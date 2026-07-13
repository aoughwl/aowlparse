#!/usr/bin/env bash
# Build nifparser-js/webmain.nim through the nimony-web JS backend -> nifparser.js
set -u
NIM=/home/savant/nimony
WEB=/home/savant/nimony-web
NP=/home/savant/nifparser-js
JSFFI="$WEB/tests/jsbackend"
HERE="$NP/webtest"
NC="$HERE/nc"

echo "== 1. nimony frontend + hexer: webmain.nim -> .c.nif (--bits:32) =="
rm -rf "$NC"; mkdir -p "$NC"
"$NIM/bin/nimony" c --bits:32 --define:nimNativeAlloc \
  -p:"$NIM/src/lib" -p:"$NIM/src/nimony" -p:"$NIM/src/models" \
  -p:"$NIM/src/gear2" -p:"$NP/src" -p:"$JSFFI" \
  --nimcache:"$NC" "$NP/src/webmain.nim" 2>&1 | grep -viE '^$' | tail -30
echo "   (32-bit C link failure above is expected/harmless)"

mapfile -t cnifs < <(find "$NC" -name '*.c.nif')
echo "   .c.nif modules produced: ${#cnifs[@]}"
if [ "${#cnifs[@]}" -eq 0 ]; then echo "FATAL: no .c.nif — frontend failed"; exit 1; fi

echo "== 2. nim_js: each .c.nif -> .js (counting unsupported nodes) =="
total_todo=0
for c in "${cnifs[@]}"; do
  out="$("$WEB/bin/nim_js" "$c" "${c%.c.nif}.js" 2>&1)"
  echo "$out" | grep -E 'unsupported node' && \
    total_todo=$((total_todo + $(echo "$out" | grep -oE '[0-9]+ unsupported' | grep -oE '[0-9]+')))
done
echo "   TOTAL unsupported nodes across all modules: $total_todo"

echo "== 3. bundle =="
BUNDLE="$HERE/nifparser.js"
AF="$HERE/.alloc.tmp"; FF="$HERE/.fill.tmp"; KF="$HERE/.code.tmp"
jsfiles=(); for c in "${cnifs[@]}"; do jsfiles+=("${c%.c.nif}.js"); done
awk -v AF="$AF" -v FF="$FF" -v KF="$KF" '
  /^\/\/__NIMJS_CONST_ALLOC_BEGIN__$/ { s=1; next }
  /^\/\/__NIMJS_CONST_ALLOC_END__$/   { s=0; next }
  /^\/\/__NIMJS_CONST_FILL_BEGIN__$/  { s=2; next }
  /^\/\/__NIMJS_CONST_FILL_END__$/    { s=0; next }
  /^"use strict";$/                   { next }
  { if (s==1) print > AF; else if (s==2) print > FF; else print > KF }
' "${jsfiles[@]}"
cat "$JSFFI/runtime.js" > "$BUNDLE"; echo >> "$BUNDLE"
cat "$AF" "$FF" "$KF" >> "$BUNDLE"
rm -f "$AF" "$FF" "$KF"
ls -la "$BUNDLE"; echo "   bundle bytes: $(wc -c < "$BUNDLE")"
