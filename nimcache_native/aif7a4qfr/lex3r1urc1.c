#define NIM_INTBITS 64
/* GENERATED CODE. DO NOT EDIT. */

#ifdef __cplusplus
#  if __cplusplus >= 201103L
#    /* nullptr is more type safe (less implicit conversions than 0) */
#    define NIM_NIL nullptr
#  else
#    // both `((void*)0)` and `NULL` would cause codegen to emit
#    // error: assigning to 'Foo *' from incompatible type 'void *'
#    // but codegen could be fixed if need. See also potential caveat regarding
#    // NULL.
#    // However, `0` causes other issues, see #13798
#    define NIM_NIL 0
#  endif
#else
#  include <stdbool.h>
#  define NIM_NIL NULL
#endif

#ifdef __cplusplus
#define NB8 bool
#elif (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901)
// see #13798: to avoid conflicts for code emitting `#include <stdbool.h>`
#define NB8 _Bool
#else
typedef unsigned char NB8; // best effort
#endif

typedef unsigned char NC8;

typedef float NF32;
typedef double NF64;
#if defined(__BORLANDC__) || defined(_MSC_VER)
typedef signed char NI8;
typedef signed short int NI16;
typedef signed int NI32;
typedef __int64 NI64;
/* XXX: Float128? */
typedef unsigned char NU8;
typedef unsigned short int NU16;
typedef unsigned int NU32;
typedef unsigned __int64 NU64;
#elif defined(HAVE_STDINT_H)
#ifndef USE_NIM_NAMESPACE
#  include <stdint.h>
#endif
typedef int8_t NI8;
typedef int16_t NI16;
typedef int32_t NI32;
typedef int64_t NI64;
typedef uint8_t NU8;
typedef uint16_t NU16;
typedef uint32_t NU32;
typedef uint64_t NU64;
#elif defined(HAVE_CSTDINT)
#ifndef USE_NIM_NAMESPACE
#  include <cstdint>
#endif
typedef std::int8_t NI8;
typedef std::int16_t NI16;
typedef std::int32_t NI32;
typedef std::int64_t NI64;
typedef std::uint8_t NU8;
typedef std::uint16_t NU16;
typedef std::uint32_t NU32;
typedef std::uint64_t NU64;
#else
/* Unknown compiler/version, do our best */
#ifdef __INT8_TYPE__
typedef __INT8_TYPE__ NI8;
#else
typedef signed char NI8;
#endif
#ifdef __INT16_TYPE__
typedef __INT16_TYPE__ NI16;
#else
typedef signed short int NI16;
#endif
#ifdef __INT32_TYPE__
typedef __INT32_TYPE__ NI32;
#else
typedef signed int NI32;
#endif
#ifdef __INT64_TYPE__
typedef __INT64_TYPE__ NI64;
#else
typedef long long int NI64;
#endif
/* XXX: Float128? */
#ifdef __UINT8_TYPE__
typedef __UINT8_TYPE__ NU8;
#else
typedef unsigned char NU8;
#endif
#ifdef __UINT16_TYPE__
typedef __UINT16_TYPE__ NU16;
#else
typedef unsigned short int NU16;
#endif
#ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ NU32;
#else
typedef unsigned int NU32;
#endif
#ifdef __UINT64_TYPE__
typedef __UINT64_TYPE__ NU64;
#else
typedef unsigned long long int NU64;
#endif
#endif

#ifdef NIM_INTBITS
#  if NIM_INTBITS == 64
typedef NI64 NI;
typedef NU64 NU;
#  elif NIM_INTBITS == 32
typedef NI32 NI;
typedef NU32 NU;
#  elif NIM_INTBITS == 16
typedef NI16 NI;
typedef NU16 NU;
#  elif NIM_INTBITS == 8
typedef NI8 NI;
typedef NU8 NU;
#  else
#    error "invalid bit width for int"
#  endif
#endif

#define NIM_TRUE true
#define NIM_FALSE false

#define _GNU_SOURCE

// Include math.h to use `NAN` that should be defined in C compilers supports C99.
#include <math.h>

// Define NAN in case math.h doesn't define it.
// NAN definition copied from math.h included in the Windows SDK version 10.0.14393.0
#ifndef NAN
#  ifndef _HUGE_ENUF
#    define _HUGE_ENUF  1e+300  // _HUGE_ENUF*_HUGE_ENUF must overflow
#  endif
#  define NAN_INFINITY ((float)(_HUGE_ENUF * _HUGE_ENUF))
#  define NAN ((float)(NAN_INFINITY * 0.0F))
#endif

#ifndef INF
#  ifdef INFINITY
#    define INF INFINITY
#  elif defined(HUGE_VAL)
#    define INF  HUGE_VAL
#  elif defined(_MSC_VER)
#    include <float.h>
#    define INF (DBL_MAX+DBL_MAX)
#  else
#    define INF (1.0 / 0.0)
#  endif
#endif

#if defined(__GNUC__) || defined(_MSC_VER)
#  define IL64(x) x##LL
#else /* works only without LL */
#  define IL64(x) ((NI64)x)
#endif


/* ------------ ignore typical warnings in Nim-generated files ------------- */
#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic ignored "-Wswitch-bool"
#  pragma GCC diagnostic ignored "-Wformat"
#  pragma GCC diagnostic ignored "-Wpointer-sign"
#  if defined(__clang__)
#    pragma GCC diagnostic ignored "-Wincompatible-pointer-types-discards-qualifiers"
#  else
#    pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
#  endif
#endif



/* ------------------------------------------------------------------- */
#ifdef  __cplusplus
#  define NIM_EXTERNC extern "C"
#else
#  define NIM_EXTERNC
#endif

#if defined(WIN32) || defined(_WIN32) /* only Windows has this mess... */
#  define N_LIB_PRIVATE
#  define N_CDECL(rettype, name) rettype __cdecl name
#  define N_STDCALL(rettype, name) rettype __stdcall name
#  define N_SYSCALL(rettype, name) rettype __syscall name
#  define N_FASTCALL(rettype, name) rettype __fastcall name
#  define N_THISCALL(rettype, name) rettype __thiscall name
#  define N_SAFECALL(rettype, name) rettype __stdcall name
/* function pointers with calling convention: */
#  define N_CDECL_PTR(rettype, name) rettype (__cdecl *name)
#  define N_STDCALL_PTR(rettype, name) rettype (__stdcall *name)
#  define N_SYSCALL_PTR(rettype, name) rettype (__syscall *name)
#  define N_FASTCALL_PTR(rettype, name) rettype (__fastcall *name)
#  define N_THISCALL_PTR(rettype, name) rettype (__thiscall *name)
#  define N_SAFECALL_PTR(rettype, name) rettype (__stdcall *name)

#  ifdef __EMSCRIPTEN__
#    define N_LIB_EXPORT  NIM_EXTERNC __declspec(dllexport) __attribute__((used))
#    define N_LIB_EXPORT_VAR  __declspec(dllexport) __attribute__((used))
#  else
#    define N_LIB_EXPORT  NIM_EXTERNC __declspec(dllexport)
#    define N_LIB_EXPORT_VAR  __declspec(dllexport)
#  endif
#  define N_LIB_IMPORT  extern __declspec(dllimport)
#else
#  define N_LIB_PRIVATE __attribute__((visibility("hidden")))
#  if defined(__GNUC__)
#    define N_CDECL(rettype, name) rettype name
#    define N_STDCALL(rettype, name) rettype name
#    define N_SYSCALL(rettype, name) rettype name
#    define N_FASTCALL(rettype, name) __attribute__((fastcall)) rettype name
#    define N_SAFECALL(rettype, name) rettype name
/*   function pointers with calling convention: */
#    define N_CDECL_PTR(rettype, name) rettype (*name)
#    define N_STDCALL_PTR(rettype, name) rettype (*name)
#    define N_SYSCALL_PTR(rettype, name) rettype (*name)
#    define N_FASTCALL_PTR(rettype, name) __attribute__((fastcall)) rettype (*name)
#    define N_SAFECALL_PTR(rettype, name) rettype (*name)
#  else
#    define N_CDECL(rettype, name) rettype name
#    define N_STDCALL(rettype, name) rettype name
#    define N_SYSCALL(rettype, name) rettype name
#    define N_FASTCALL(rettype, name) rettype name
#    define N_SAFECALL(rettype, name) rettype name
/*   function pointers with calling convention: */
#    define N_CDECL_PTR(rettype, name) rettype (*name)
#    define N_STDCALL_PTR(rettype, name) rettype (*name)
#    define N_SYSCALL_PTR(rettype, name) rettype (*name)
#    define N_FASTCALL_PTR(rettype, name) rettype (*name)
#    define N_SAFECALL_PTR(rettype, name) rettype (*name)
#  endif
#  ifdef __EMSCRIPTEN__
#    define N_LIB_EXPORT NIM_EXTERNC __attribute__((visibility("default"), used))
#    define N_LIB_EXPORT_VAR  __attribute__((visibility("default"), used))
#  else
#    define N_LIB_EXPORT NIM_EXTERNC __attribute__((visibility("default")))
#    define N_LIB_EXPORT_VAR  __attribute__((visibility("default")))
#  endif
#  define N_LIB_IMPORT  extern
#endif

#if defined(__BORLANDC__) || defined(_MSC_VER) || defined(WIN32) || defined(_WIN32)
/* these compilers have a fastcall so use it: */
#  define N_NIMCALL(rettype, name) rettype __fastcall name
#  define N_NIMCALL_PTR(rettype, name) rettype (__fastcall *name)
#else
#  define N_NIMCALL(rettype, name) rettype name /* no modifier */
#  define N_NIMCALL_PTR(rettype, name) rettype (*name)
#endif

#define N_NOCONV(rettype, name) rettype name
/* specify no calling convention */
#define N_NOCONV_PTR(rettype, name) rettype (*name)

/* calling convention mess ----------------------------------------------- */
#if defined(__GNUC__) || defined(__TINYC__)
  /* these should support C99's inline */
#  define N_INLINE(rettype, name) inline rettype name
#elif defined(__BORLANDC__) || defined(_MSC_VER)
/* Borland's compiler is really STRANGE here; note that the __fastcall
   keyword cannot be before the return type, but __inline cannot be after
   the return type, so we do not handle this mess in the code generator
   but rather here. */
#  define N_INLINE(rettype, name) __inline rettype name
#else /* others are less picky: */
#  define N_INLINE(rettype, name) rettype __inline name
#endif

#define N_INLINE_PTR(rettype, name) rettype (*name)

#if defined(__GNUC__) || defined(__ICC__)
#  define N_NOINLINE __attribute__((__noinline__))
#elif defined(_MSC_VER)
#  define N_NOINLINE __declspec(noinline)
#else
#  define N_NOINLINE
#endif

#define N_NOINLINE_PTR(rettype, name) rettype (*name)

#if defined(_MSC_VER)
#  define NIM_ALIGN(x)  __declspec(align(x))
#  define NIM_ALIGNOF(x) __alignof(x)
#else
#  define NIM_ALIGN(x)  __attribute__((aligned(x)))
#  define NIM_ALIGNOF(x) __alignof__(x)
#endif

#include <stddef.h>


/*
  NIM_THREADVAR declaration based on
  https://stackoverflow.com/questions/18298280/how-to-declare-a-variable-as-thread-local-portably
*/
#if defined _WIN32
#  if defined _MSC_VER || defined __BORLANDC__
#    define NIM_THREADVAR __declspec(thread)
#  else
#    define NIM_THREADVAR __thread
#  endif
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112 && !defined __STDC_NO_THREADS__
#  define NIM_THREADVAR _Thread_local
#elif defined _WIN32 && ( \
       defined _MSC_VER || \
       defined __ICL || \
       defined __BORLANDC__ )
#  define NIM_THREADVAR __declspec(thread)
#elif defined(__TINYC__) || defined(__GENODE__)
#  define NIM_THREADVAR
/* note that ICC (linux) and Clang are covered by __GNUC__ */
#elif defined __GNUC__ || \
       defined __SUNPRO_C || \
       defined __xlC__
#  define NIM_THREADVAR __thread
#else
#  error "Cannot define NIM_THREADVAR"
#endif

/* define NIM_STATIC_ASSERT */
#if defined(__cplusplus)
#define NIM_STATIC_ASSERT(x, msg) static_assert((x), msg)
#else
#define NIM_STATIC_ASSERT(x, msg) _Static_assert((x), msg)
#endif

// Test to see if Nim and the C compiler agree on the size of a pointer.
NIM_STATIC_ASSERT(sizeof(NI) == sizeof(void*) && NIM_INTBITS == sizeof(NI)*8, "Pointer size mismatch between Nim and C/C++ backend. You probably need to setup the backend compiler for target CPU.");

N_INLINE(NB8, _Qlengc_div_sll_overflow)(long long int a, long long int b, long long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  if (a == (long long int)(((unsigned long long int)1) << (sizeof(long long int) * 8 - 1)) && b == -1) {
    *res = a;
    return NIM_TRUE;
  }
  *res = a / b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_div_sl_overflow)(long int a, long int b, long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  if (a == (long int)(((unsigned long int)1) << (sizeof(long int) * 8 - 1)) && b == -1) {
    *res = a;
    return NIM_TRUE;
  }
  *res = a / b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_div_ull_overflow)(unsigned long long int a, unsigned long long int b, unsigned long long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE; /* Overflow: division by zero */
  }
  *res = a / b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_div_ul_overflow)(unsigned long int a, unsigned long int b, unsigned long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a / b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_mod_sll_overflow)(long long int a, long long int b, long long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  if (a == (long long int)(((unsigned long long int)1) << (sizeof(long long int) * 8 - 1)) && b == -1) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a % b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_mod_sl_overflow)(long int a, long int b, long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  if (a == (long int)(((unsigned long int)1) << (sizeof(long int) * 8 - 1)) && b == -1) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a % b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_mod_ull_overflow)(unsigned long long int a, unsigned long long int b, unsigned long long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a % b;
  return NIM_FALSE;
}

N_INLINE(NB8, _Qlengc_mod_ul_overflow)(unsigned long int a, unsigned long int b, unsigned long int *res) {
  if (b == 0) {
    *res = 0;
    return NIM_TRUE;
  }
  *res = a % b;
  return NIM_FALSE;
}
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct Diagnostic_0_tok9e79hf Diagnostic_0_tok9e79hf;
typedef struct Token_0_tok9e79hf Token_0_tok9e79hf;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef NU8 TabPolicy_0_lex3r1urc1;

#define tpSpaces_0_lex3r1urc1 ((NU8)IL64(0))
#define tpTabs_0_lex3r1urc1 ((NU8)IL64(1))
#define tpBoth_0_lex3r1urc1 ((NU8)IL64(2))
typedef NU8 NewlinePolicy_0_lex3r1urc1;

#define nlAny_0_lex3r1urc1 ((NU8)IL64(0))
#define nlLf_0_lex3r1urc1 ((NU8)IL64(1))
#define nlCrlf_0_lex3r1urc1 ((NU8)IL64(2))
typedef NU8 BomPolicy_0_lex3r1urc1;

#define bomDefault_0_lex3r1urc1 ((NU8)IL64(0))
#define bomStrip_0_lex3r1urc1 ((NU8)IL64(1))
#define bomReject_0_lex3r1urc1 ((NU8)IL64(2))
typedef NU8 TabStops_0_lex3r1urc1;

#define tsHard_0_lex3r1urc1 ((NU8)IL64(0))
#define tsRound_0_lex3r1urc1 ((NU8)IL64(1))
typedef struct LexOptions_0_lex3r1urc1{
  TabPolicy_0_lex3r1urc1 tabPolicy_0;
  NI64 tabWidth_0;
  NI64 indentWidth_0;
  NB8 finalNewlineRequire_0;
  NewlinePolicy_0_lex3r1urc1 newlinePolicy_0;
  NB8 trailingWhitespaceWarn_0;
  BomPolicy_0_lex3r1urc1 bomPolicy_0;
  NB8 indentConsistency_0;
  TabStops_0_lex3r1urc1 tabStops_0;
  NB8 docComments_0;}
LexOptions_0_lex3r1urc1;
typedef struct string_0_sysvq0asl{
  NU64 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct seq_0_I1z1mkd_lex3r1urc1{
  NI64 len_0;
  Diagnostic_0_tok9e79hf* data_0;}
seq_0_I1z1mkd_lex3r1urc1;
typedef struct Lexer_0_lex3r1urc1{
  string_0_sysvq0asl src_0;
  NI64 n_0;
  NI64 pos_0;
  NI32 line_0;
  NI32 col_0;
  NB8 atLineStart_0;
  LexOptions_0_lex3r1urc1 opts_0;
  NB8 sawSpaceInIndent_0;
  NB8 sawTabInIndent_0;
  NB8 warnedMixThisLine_0;
  NI64 errors_0;
  NI32 prevIndent_0;
  NI32 indentUnit_0;
  seq_0_I1z1mkd_lex3r1urc1 diags_0;}
Lexer_0_lex3r1urc1;
typedef struct seq_0_Iyai4gn_lex3r1urc1{
  NI64 len_0;
  Token_0_tok9e79hf* data_0;}
seq_0_Iyai4gn_lex3r1urc1;
typedef struct seq_0_Ixdx2fh1_aif7a4qfr{
  NI64 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aif7a4qfr;
typedef struct seq_0_Ift2sne_lex3r1urc1{
  NI64 len_0;
  NI32* data_0;}
seq_0_Ift2sne_lex3r1urc1;
typedef struct openArray_0_Ijk0jkw1_has9tn57v{
  NC8* a_0;
  NI64 len_0;}
openArray_0_Ijk0jkw1_has9tn57v;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[IL64(32)];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct LongString_0_sysvq0asl{
  NI64 fullLen_0;
  NI64 rc_0;
  NI64 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef NU8 TokKind_0_tok9e79hf;

#define tkEof_0_tok9e79hf ((NU8)IL64(0))
#define tkIdent_0_tok9e79hf ((NU8)IL64(1))
#define tkKeyword_0_tok9e79hf ((NU8)IL64(2))
#define tkIntLit_0_tok9e79hf ((NU8)IL64(3))
#define tkFloatLit_0_tok9e79hf ((NU8)IL64(4))
#define tkStrLit_0_tok9e79hf ((NU8)IL64(5))
#define tkRStrLit_0_tok9e79hf ((NU8)IL64(6))
#define tkTripleStrLit_0_tok9e79hf ((NU8)IL64(7))
#define tkCharLit_0_tok9e79hf ((NU8)IL64(8))
#define tkOperator_0_tok9e79hf ((NU8)IL64(9))
#define tkParLe_0_tok9e79hf ((NU8)IL64(10))
#define tkParRi_0_tok9e79hf ((NU8)IL64(11))
#define tkBracketLe_0_tok9e79hf ((NU8)IL64(12))
#define tkBracketRi_0_tok9e79hf ((NU8)IL64(13))
#define tkCurlyLe_0_tok9e79hf ((NU8)IL64(14))
#define tkCurlyRi_0_tok9e79hf ((NU8)IL64(15))
#define tkComma_0_tok9e79hf ((NU8)IL64(16))
#define tkSemicolon_0_tok9e79hf ((NU8)IL64(17))
#define tkColon_0_tok9e79hf ((NU8)IL64(18))
#define tkDot_0_tok9e79hf ((NU8)IL64(19))
#define tkComment_0_tok9e79hf ((NU8)IL64(20))
typedef struct Token_0_tok9e79hf{
  TokKind_0_tok9e79hf kind_0;
  string_0_sysvq0asl s_0;
  NI64 iVal_0;
  NF64 fVal_0;
  string_0_sysvq0asl suffix_0;
  NI32 line_0;
  NI32 col_0;
  NI32 endCol_0;
  NI32 indent_0;
  NB8 quoted_0;
  seq_0_Ixdx2fh1_aif7a4qfr parts_0;
  seq_0_Ift2sne_lex3r1urc1 partCols_0;}
Token_0_tok9e79hf;
typedef NU8 Severity_0_tok9e79hf;

#define sevHint_0_tok9e79hf ((NU8)IL64(0))
#define sevWarn_0_tok9e79hf ((NU8)IL64(1))
#define sevError_0_tok9e79hf ((NU8)IL64(2))
typedef struct Diagnostic_0_tok9e79hf{
  Severity_0_tok9e79hf severity_0;
  string_0_sysvq0asl code_0;
  string_0_sysvq0asl message_0;
  NI32 line_0;
  NI32 col_0;
  NI32 endCol_0;}
Diagnostic_0_tok9e79hf;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI64);
static inline seq_0_I1z1mkd_lex3r1urc1 newSeqUninit_0_I90m2ee1_lex3r1urc1(NI64 size_4);
static inline void inc_1_I6wjjge_lex3r1urc1(NI32* x_4);
static inline void inc_0_Iloplki_lex3r1urc1(NI32* x_5, NI32 y_1);
static inline void add_0_Ikpo3qe_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1* s_17, Diagnostic_0_tok9e79hf elem_4);
static inline seq_0_Ift2sne_lex3r1urc1 newSeqUninit_0_Iggfvwp_lex3r1urc1(NI64 size_8);
static inline void add_0_I8kd4i4_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1* s_19, NI32 elem_5);
static inline seq_0_Iyai4gn_lex3r1urc1 newSeqUninit_0_I28kyaw1_lex3r1urc1(NI64 size_10);
static inline NI64 len_3_Iefkljt1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_23);
static inline void add_0_Icvfjtn_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* s_24, Token_0_tok9e79hf elem_7);
static inline Token_0_tok9e79hf* getQ_7_Ijq9cyk1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_26, NI64 i_3);
static inline NI64 memSizeInBytes_0_Igy60gp1_lex3r1urc1(NI64 size_12);
static inline NI64 capInBytes_0_I2z6vh21_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1 s_27);
NB8 resize_0_I5waj38_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1* dest_4, NI64 addedElements_4);
static inline NI64 memSizeInBytes_0_Inv7kg3_lex3r1urc1(NI64 size_14);
static inline NI64 capInBytes_0_Iet286n_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1 s_28);
NB8 resize_0_I8l4tya_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1* dest_5, NI64 addedElements_5);
static inline NI64 memSizeInBytes_0_Imlcc9c1_lex3r1urc1(NI64 size_15);
static inline NI64 capInBytes_0_Iztvafh1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_30);
NB8 resize_0_Ijirql71_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* dest_7, NI64 addedElements_7);
void eQdestroy_1_I9g9z2g1_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1 s_39);
static inline void eQwasMoved_1_Ikj6j7q_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1* s_40);
void eQdestroy_1_Ie8xo6a1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_41);
static inline void eQwasMoved_1_I4bu01z_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* s_42);
void eQdestroy_1_Iv9ij5i1_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1 s_45);
static inline void eQwasMoved_1_Ix88qzs1_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1* s_46);
void eQdestroyQ_SX4cexer0lex3r1urc1_0_lex3r1urc1(Lexer_0_lex3r1urc1* dest_0);
void eQwasmovedQ_SX4cexer0lex3r1urc1_0_lex3r1urc1(Lexer_0_lex3r1urc1* dest_0);
Lexer_0_lex3r1urc1 eQdupQ_SX4cexer0lex3r1urc1_0_lex3r1urc1(Lexer_0_lex3r1urc1* src_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40);
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38);
static inline void nimStrDestroy(string_0_sysvq0asl s_39);
extern string_0_sysvq0asl newString_0_sysvq0asl(NI64 len_2);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_52, NI64 i_14);
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_53, NI64 i_15, NC8 c_1);
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1);
extern void eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* dest_0);
extern void eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* dest_0);
extern Token_0_tok9e79hf initToken_0_tok9e79hf(TokKind_0_tok9e79hf kind_0, NI32 line_0, NI32 col_0);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
extern string_0_sysvq0asl dollarQ_1_sysvq0asl(NI64 x_225);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI64 len_3);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_48, string_0_sysvq0asl part_0);
static inline NC8 chr_0_sysvq0asl(NI64 u_0);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_47, NC8 c_0);
static inline openArray_0_Ijk0jkw1_has9tn57v toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_65);
static inline NI64 len_6_Iroq7kd1_has9tn57v(openArray_0_Ijk0jkw1_has9tn57v a_6);
static inline NC8* getQ_10_I5nt6we_has9tn57v(openArray_0_Ijk0jkw1_has9tn57v x_14, NI64 idx_1);
extern NI64 parseBiggestFloat_0_party5a2l1(openArray_0_Ijk0jkw1_has9tn57v s_6, NF64* number_4);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_56, NI64 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_13, string_0_sysvq0asl b_9);
extern NB8 isKeyword_0_tok9e79hf(string_0_sysvq0asl s_0);
static inline seq_0_Ixdx2fh1_aif7a4qfr newSeqUninit_0_Im3cqd9_aif7a4qfr(NI64 size_1);
static inline void add_0_Ig6072n_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_5, string_0_sysvq0asl elem_1);
extern void eQdestroy_1_Ivioh0a_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_10);
static inline void eQwasMoved_1_I5vdnla_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_11);
static inline void dec_1_I2mwrey1_envto7w6l1(NI64* x_8);
extern void* alloc_0_sysvq0asl(NI64 size_10);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aif7a4qfr;
extern X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void eQdestroyQ_SX44iagnostic0tok9e79hf_0_tok9e79hf(Diagnostic_0_tok9e79hf* dest_0);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_68);
extern LongString_0_sysvq0asl const strlit_0_I14532204288076119502_aif7a4qfr;
extern NI64 allocatedSize_0_sysvq0asl(void* p_11);
static inline NI64 recalcCap_0_sysvq0asl(NI64 oldCap_0, NI64 addedElements_0);
extern void* realloc_0_sysvq0asl(void* p_9, NI64 size_12);
extern void dealloc_0_sysvq0asl(void* p_10);
extern Diagnostic_0_tok9e79hf eQdupQ_SX44iagnostic0tok9e79hf_0_tok9e79hf(Diagnostic_0_tok9e79hf* src_0);
extern Token_0_tok9e79hf eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* src_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tok9e79hf(void);
extern void X60Qini_0_party5a2l1(void);
extern void X60Qini_0_syn1lfpjv(void);
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0);
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0);
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1);
extern LongString_0_sysvq0asl const strlit_0_I14131790745264837101_sysvq0asl;
extern LongString_0_sysvq0asl const strlit_0_I11927585966806674622_sysvq0asl;
extern void prepareMutation_0_sysvq0asl(string_0_sysvq0asl* s_44);
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_37, NI64 start_0);
extern LongString_0_sysvq0asl const strlit_0_I14694606176902936784_has9tn57v;
static inline NI64 memSizeInBytes_0_I7me00i_aif7a4qfr(NI64 size_3);
static inline NI64 capInBytes_0_Ih2sbn01_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_7);
extern NB8 resize_0_I4buliy_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* dest_1, NI64 addedElements_1);
static inline NI64 max_3_sysvq0asl(NI64 x_212, NI64 y_169);
LongString_0_sysvq0asl const strlit_0_I7901555537561129428_lex3r1urc1 = {
  .fullLen_0 = IL64(16), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "0123456789ABCDEF"}
;
LongString_0_sysvq0asl const strlit_0_I6280642289327629658_lex3r1urc1 = {
  .fullLen_0 = IL64(15), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "indentation of "}
;
LongString_0_sysvq0asl const strlit_0_I10413904334500263167_lex3r1urc1 = {
  .fullLen_0 = IL64(32), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = " column(s) is not a multiple of "}
;
LongString_0_sysvq0asl const strlit_0_I1280312082867034263_lex3r1urc1 = {
  .fullLen_0 = IL64(15), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "--indent-width:"}
;
LongString_0_sysvq0asl const strlit_0_I7239112280132897979_lex3r1urc1 = {
  .fullLen_0 = IL64(12), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "indent-width"}
;
LongString_0_sysvq0asl const strlit_0_I16348626965461658915_lex3r1urc1 = {
  .fullLen_0 = IL64(24), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "the file\'s indent step ("}
;
LongString_0_sysvq0asl const strlit_0_I5579380358509126566_lex3r1urc1 = {
  .fullLen_0 = IL64(24), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = ") [--indent-consistency]"}
;
LongString_0_sysvq0asl const strlit_0_I1183140066353762900_lex3r1urc1 = {
  .fullLen_0 = IL64(18), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "indent-consistency"}
;
LongString_0_sysvq0asl const strlit_0_I4192191418491144372_lex3r1urc1 = {
  .fullLen_0 = IL64(19), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "unterminated-string"}
;
LongString_0_sysvq0asl const strlit_0_I8436252750452789659_lex3r1urc1 = {
  .fullLen_0 = IL64(27), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "unterminated string literal"}
;
LongString_0_sysvq0asl const strlit_0_I16765148769446371680_lex3r1urc1 = {
  .fullLen_0 = IL64(12), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "bom-rejected"}
;
LongString_0_sysvq0asl const strlit_0_I3289740197006093898_lex3r1urc1 = {
  .fullLen_0 = IL64(41), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "leading UTF-8 BOM rejected [--bom:reject]"}
;
LongString_0_sysvq0asl const strlit_0_I9812626919684199076_lex3r1urc1 = {
  .fullLen_0 = IL64(12), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "mixed-indent"}
;
LongString_0_sysvq0asl const strlit_0_I2041765918324268108_lex3r1urc1 = {
  .fullLen_0 = IL64(33), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "indentation mixes tabs and spaces"}
;
LongString_0_sysvq0asl const strlit_0_I1365890887990331020_lex3r1urc1 = {
  .fullLen_0 = IL64(11), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "line-ending"}
;
LongString_0_sysvq0asl const strlit_0_I15073253361476384615_lex3r1urc1 = {
  .fullLen_0 = IL64(47), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "line ends with CRLF, expected LF [--newline:lf]"}
;
LongString_0_sysvq0asl const strlit_0_I3525481182892397244_lex3r1urc1 = {
  .fullLen_0 = IL64(49), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "line ends with LF, expected CRLF [--newline:crlf]"}
;
LongString_0_sysvq0asl const strlit_0_I3814179386273276921_lex3r1urc1 = {
  .fullLen_0 = IL64(19), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "trailing-whitespace"}
;
LongString_0_sysvq0asl const strlit_0_I18387374889788949454_lex3r1urc1 = {
  .fullLen_0 = IL64(48), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "trailing whitespace [--trailing-whitespace:warn]"}
;
LongString_0_sysvq0asl const strlit_0_I2073055120360076570_lex3r1urc1 = {
  .fullLen_0 = IL64(23), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "unknown/illegal byte 0x"}
;
LongString_0_sysvq0asl const strlit_0_I14660181550455658176_lex3r1urc1 = {
  .fullLen_0 = IL64(8), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = " skipped"}
;
LongString_0_sysvq0asl const strlit_0_I13586503514632046678_lex3r1urc1 = {
  .fullLen_0 = IL64(12), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "unknown-byte"}
;
LongString_0_sysvq0asl const strlit_0_I1664332866290125980_lex3r1urc1 = {
  .fullLen_0 = IL64(21), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "missing-final-newline"}
;
LongString_0_sysvq0asl const strlit_0_I5470147542548005821_lex3r1urc1 = {
  .fullLen_0 = IL64(60), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "source does not end with a newline [--final-newline:require]"}
;
LexOptions_0_lex3r1urc1 const defaultLexOptions_0_lex3r1urc1 = {
  .tabPolicy_0 = IL64(0), .tabWidth_0 = ((NI64)IL64(8)), .indentWidth_0 = ((NI64)IL64(0)), .finalNewlineRequire_0 = NIM_FALSE, .newlinePolicy_0 = IL64(0), .trailingWhitespaceWarn_0 = NIM_FALSE, .bomPolicy_0 = IL64(0), .indentConsistency_0 = NIM_FALSE, .tabStops_0 = IL64(0), .docComments_0 = NIM_TRUE}
;
seq_0_I1z1mkd_lex3r1urc1 gLexDiags_0_lex3r1urc1;
static string_0_sysvq0asl const hex_0 = {
  .bytes_0 = 3906085646303834366ull, .more_0 = (&strlit_0_I7901555537561129428_lex3r1urc1)}
;
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 const OperatorChars_0_lex3r1urc1 = {
  .a = {
    0ull, 0ull, 0ull, 0ull, 114ull, 236ull, 0ull, 244ull, 1ull, 0ull, 0ull, 80ull, 0ull, 0ull, 0ull, 80ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull}}
;
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 const QQuoteMergeChars_0_lex3r1urc1 = {
  .a = {
    0ull, 0ull, 0ull, 0ull, 114ull, 239ull, 0ull, 240ull, 1ull, 0ull, 0ull, 120ull, 0ull, 0ull, 0ull, 120ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull}}
;
NB8 X60QiniGuard_0_lex3r1urc1;
Lexer_0_lex3r1urc1 initLexer_0_lex3r1urc1(string_0_sysvq0asl src_0, LexOptions_0_lex3r1urc1* opts_0){
  Lexer_0_lex3r1urc1 result_4;
  eQwasmovedQ_SX4cexer0lex3r1urc1_0_lex3r1urc1((&result_4));
  eQdestroyQ_SX4cexer0lex3r1urc1_0_lex3r1urc1((&result_4));
  string_0_sysvq0asl X60Qx_15 = nimStrDup(src_0);
  NI64 X60Qx_16 = len_4_sysvq0asl(src_0);
  seq_0_I1z1mkd_lex3r1urc1 X60Qx_17 = newSeqUninit_0_I90m2ee1_lex3r1urc1(IL64(0));
  result_4 = (Lexer_0_lex3r1urc1){
    .src_0 = X60Qx_15, .n_0 = X60Qx_16, .pos_0 = IL64(0), .line_0 = ((NI32)IL64(1)), .col_0 = ((NI32)IL64(0)), .atLineStart_0 = NIM_TRUE, .opts_0 = (*opts_0), .sawSpaceInIndent_0 = NIM_FALSE, .sawTabInIndent_0 = NIM_FALSE, .warnedMixThisLine_0 = NIM_FALSE, .errors_0 = IL64(0), .prevIndent_0 = ((NI32)IL64(0)), .indentUnit_0 = ((NI32)IL64(0)), .diags_0 = X60Qx_17}
  ;
  return result_4;}
string_0_sysvq0asl toHex2_0_lex3r1urc1(NU8 b_0){
  string_0_sysvq0asl result_5;
  nimStrWasMoved((&result_5));
  nimStrDestroy(result_5);
  string_0_sysvq0asl X60Qx_18 = newString_0_sysvq0asl(IL64(2));
  result_5 = X60Qx_18;
  NC8 X60Qx_19 = getQ_9_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3906085646303834366ull, .more_0 = (&strlit_0_I7901555537561129428_lex3r1urc1)}
  , ((NI64)((NU8)(b_0 >> IL64(4)))));
  putQ_9_sysvq0asl((&result_5), IL64(0), X60Qx_19);
  NC8 X60Qx_20 = getQ_9_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3906085646303834366ull, .more_0 = (&strlit_0_I7901555537561129428_lex3r1urc1)}
  , ((NI64)((NU8)(b_0 & ((NU8)IL64(15))))));
  putQ_9_sysvq0asl((&result_5), IL64(1), X60Qx_20);
  return result_5;}
NC8 cur_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_1){
  NC8 result_6;
  NC8 X60Qx_0;
  if ((*lx_1).pos_0 < (*lx_1).n_0){
    NC8 X60Qx_21 = getQ_9_sysvq0asl((*lx_1).src_0, (*lx_1).pos_0);
    X60Qx_0 = X60Qx_21;}
  else {
    X60Qx_0 = (NC8)'\000';}
  result_6 = X60Qx_0;
  return result_6;}
NC8 peek_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_2, NI64 k_0){
  NC8 result_7;
  NI64 p_0 = ((NI64)((*lx_2).pos_0 + k_0));
  NC8 X60Qx_1;
  if (p_0 < (*lx_2).n_0){
    NC8 X60Qx_22 = getQ_9_sysvq0asl((*lx_2).src_0, p_0);
    X60Qx_1 = X60Qx_22;}
  else {
    X60Qx_1 = (NC8)'\000';}
  result_7 = X60Qx_1;
  return result_7;}
void advance_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_3){
  if ((*lx_3).pos_0 < (*lx_3).n_0){
    NC8 ch_0 = getQ_9_sysvq0asl((*lx_3).src_0, (*lx_3).pos_0);
    if (ch_0 == (NC8)'\012'){
      inc_1_I6wjjge_lex3r1urc1((&(*lx_3).line_0));
      (*lx_3).col_0 = ((NI32)IL64(0));
      (*lx_3).atLineStart_0 = NIM_TRUE;
      (*lx_3).sawSpaceInIndent_0 = NIM_FALSE;
      (*lx_3).sawTabInIndent_0 = NIM_FALSE;
      (*lx_3).warnedMixThisLine_0 = NIM_FALSE;}
    else {
      NB8 X60Qx_23;
      if (ch_0 == (NC8)'\011'){
        X60Qx_23 = (!((*lx_3).opts_0.tabPolicy_0 == IL64(0)));}
      else {
        X60Qx_23 = NIM_FALSE;}
      if (X60Qx_23){
        if ((*lx_3).opts_0.tabStops_0 == IL64(1)){
          NI32 w_0 = ((NI32)(*lx_3).opts_0.tabWidth_0);
          (*lx_3).col_0 = ((NI32)(((NI32)(((NI32)((*lx_3).col_0 / w_0)) + ((NI32)IL64(1)))) * w_0));}
        else {
          inc_0_Iloplki_lex3r1urc1((&(*lx_3).col_0), ((NI32)(*lx_3).opts_0.tabWidth_0));}}
      else {
        inc_1_I6wjjge_lex3r1urc1((&(*lx_3).col_0));}}
    inc_1_Irn1g7r1_aif7a4qfr((&(*lx_3).pos_0));}}
NB8 isIdentStart_0_lex3r1urc1(NC8 c_0){
  NB8 result_8;
  NB8 X60Qx_24;
  NB8 X60Qx_25;
  if (c_0 == (NC8)'_'){
    X60Qx_25 = NIM_TRUE;}
  else {
    NB8 X60Qx_26;
    if ((NC8)'a' <= c_0){
      X60Qx_26 = (c_0 <= (NC8)'z');}
    else {
      X60Qx_26 = NIM_FALSE;}
    X60Qx_25 = X60Qx_26;}
  if (X60Qx_25){
    X60Qx_24 = NIM_TRUE;}
  else {
    NB8 X60Qx_27;
    if ((NC8)'A' <= c_0){
      X60Qx_27 = (c_0 <= (NC8)'Z');}
    else {
      X60Qx_27 = NIM_FALSE;}
    X60Qx_24 = X60Qx_27;}
  result_8 = X60Qx_24;
  return result_8;}
NB8 isIdentCont_0_lex3r1urc1(NC8 c_1){
  NB8 result_9;
  NB8 X60Qx_28;
  NB8 X60Qx_29 = isIdentStart_0_lex3r1urc1(c_1);
  if (X60Qx_29){
    X60Qx_28 = NIM_TRUE;}
  else {
    NB8 X60Qx_30;
    if ((NC8)'0' <= c_1){
      X60Qx_30 = (c_1 <= (NC8)'9');}
    else {
      X60Qx_30 = NIM_FALSE;}
    X60Qx_28 = X60Qx_30;}
  result_9 = X60Qx_28;
  return result_9;}
NB8 isDigit_0_lex3r1urc1(NC8 c_2){
  NB8 result_10;
  NB8 X60Qx_31;
  if ((NC8)'0' <= c_2){
    X60Qx_31 = (c_2 <= (NC8)'9');}
  else {
    X60Qx_31 = NIM_FALSE;}
  result_10 = X60Qx_31;
  return result_10;}
NB8 isHexDigit_0_lex3r1urc1(NC8 c_3){
  NB8 result_11;
  NB8 X60Qx_32;
  NB8 X60Qx_33;
  NB8 X60Qx_34 = isDigit_0_lex3r1urc1(c_3);
  if (X60Qx_34){
    X60Qx_33 = NIM_TRUE;}
  else {
    NB8 X60Qx_35;
    if ((NC8)'a' <= c_3){
      X60Qx_35 = (c_3 <= (NC8)'f');}
    else {
      X60Qx_35 = NIM_FALSE;}
    X60Qx_33 = X60Qx_35;}
  if (X60Qx_33){
    X60Qx_32 = NIM_TRUE;}
  else {
    NB8 X60Qx_36;
    if ((NC8)'A' <= c_3){
      X60Qx_36 = (c_3 <= (NC8)'F');}
    else {
      X60Qx_36 = NIM_FALSE;}
    X60Qx_32 = X60Qx_36;}
  result_11 = X60Qx_32;
  return result_11;}
NI64 hexVal_0_lex3r1urc1(NC8 c_4){
  NI64 result_12;
  NI64 X60Qx_2;
  NB8 X60Qx_37;
  if ((NC8)'0' <= c_4){
    X60Qx_37 = (c_4 <= (NC8)'9');}
  else {
    X60Qx_37 = NIM_FALSE;}
  if (X60Qx_37){
    X60Qx_2 = ((NI64)(((NI64)c_4) - ((NI64)(NC8)'0')));}
  else {
    NB8 X60Qx_38;
    if ((NC8)'a' <= c_4){
      X60Qx_38 = (c_4 <= (NC8)'f');}
    else {
      X60Qx_38 = NIM_FALSE;}
    if (X60Qx_38){
      X60Qx_2 = ((NI64)(((NI64)(((NI64)c_4) - ((NI64)(NC8)'a'))) + IL64(10)));}
    else {
      NB8 X60Qx_39;
      if ((NC8)'A' <= c_4){
        X60Qx_39 = (c_4 <= (NC8)'F');}
      else {
        X60Qx_39 = NIM_FALSE;}
      if (X60Qx_39){
        X60Qx_2 = ((NI64)(((NI64)(((NI64)c_4) - ((NI64)(NC8)'A'))) + IL64(10)));}
      else {
        X60Qx_2 = IL64(-1);}}}
  result_12 = X60Qx_2;
  return result_12;}
Token_0_tok9e79hf startToken_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_4, TokKind_0_tok9e79hf kind_0){
  Token_0_tok9e79hf result_13;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_13));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_13));
  Token_0_tok9e79hf X60Qx_40 = initToken_0_tok9e79hf(kind_0, (*lx_4).line_0, (*lx_4).col_0);
  result_13 = X60Qx_40;
  if ((*lx_4).atLineStart_0){
    result_13.indent_0 = (*lx_4).col_0;
    NB8 X60Qx_41;
    NB8 X60Qx_42;
    if (IL64(0) < (*lx_4).opts_0.indentWidth_0){
      X60Qx_42 = (((NI32)IL64(0)) < (*lx_4).col_0);}
    else {
      X60Qx_42 = NIM_FALSE;}
    if (X60Qx_42){
      X60Qx_41 = (!(((NI64)(((NI64)(*lx_4).col_0) % (*lx_4).opts_0.indentWidth_0)) == IL64(0)));}
    else {
      X60Qx_41 = NIM_FALSE;}
    if (X60Qx_41){
      string_0_sysvq0asl X60Qdesugar_0 = dollarQ_2_sysvq0asl((*lx_4).col_0);
      string_0_sysvq0asl X60Qdesugar_1 = dollarQ_1_sysvq0asl((*lx_4).opts_0.indentWidth_0);
      NI64 X60Qx_43 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 7022359100733155838ull, .more_0 = (&strlit_0_I6280642289327629658_lex3r1urc1)}
      );
      NI64 X60Qx_44 = len_4_sysvq0asl(X60Qdesugar_0);
      NI64 X60Qx_45 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 7957145225219219710ull, .more_0 = (&strlit_0_I10413904334500263167_lex3r1urc1)}
      );
      NI64 X60Qx_46 = len_4_sysvq0asl((string_0_sysvq0asl){
        .bytes_0 = 7954874742193597950ull, .more_0 = (&strlit_0_I1280312082867034263_lex3r1urc1)}
      );
      NI64 X60Qx_47 = len_4_sysvq0asl(X60Qdesugar_1);
      string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_43 + X60Qx_44)) + X60Qx_45)) + X60Qx_46)) + X60Qx_47)));
      add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
        .bytes_0 = 7022359100733155838ull, .more_0 = (&strlit_0_I6280642289327629658_lex3r1urc1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_0);
      add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
        .bytes_0 = 7957145225219219710ull, .more_0 = (&strlit_0_I10413904334500263167_lex3r1urc1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
        .bytes_0 = 7954874742193597950ull, .more_0 = (&strlit_0_I1280312082867034263_lex3r1urc1)}
      );
      add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_1);
      string_0_sysvq0asl X60Qtmp_0 = X60Qdesugar_2;
      nimStrWasMoved((&X60Qdesugar_2));
      add_0_Ikpo3qe_lex3r1urc1((&(*lx_4).diags_0), (Diagnostic_0_tok9e79hf){
        .severity_0 = IL64(0), .code_0 = (string_0_sysvq0asl){
          .bytes_0 = 3275364210760903166ull, .more_0 = (&strlit_0_I7239112280132897979_lex3r1urc1)}
        , .message_0 = X60Qtmp_0, .line_0 = (*lx_4).line_0, .col_0 = ((NI32)IL64(0)), .endCol_0 = (*lx_4).col_0}
      );
      if (IL64(0) == IL64(2)){
        inc_1_Irn1g7r1_aif7a4qfr((&(*lx_4).errors_0));}
      nimStrDestroy(X60Qdesugar_2);
      nimStrDestroy(X60Qdesugar_1);
      nimStrDestroy(X60Qdesugar_0);}
    if ((*lx_4).opts_0.indentConsistency_0){
      NB8 X60Qx_48;
      if ((*lx_4).indentUnit_0 == ((NI32)IL64(0))){
        X60Qx_48 = ((*lx_4).prevIndent_0 < (*lx_4).col_0);}
      else {
        X60Qx_48 = NIM_FALSE;}
      if (X60Qx_48){
        (*lx_4).indentUnit_0 = ((NI32)((*lx_4).col_0 - (*lx_4).prevIndent_0));}
      NB8 X60Qx_49;
      NB8 X60Qx_50;
      if (((NI32)IL64(0)) < (*lx_4).indentUnit_0){
        X60Qx_50 = (((NI32)IL64(0)) < (*lx_4).col_0);}
      else {
        X60Qx_50 = NIM_FALSE;}
      if (X60Qx_50){
        X60Qx_49 = (!(((NI32)((*lx_4).col_0 % (*lx_4).indentUnit_0)) == ((NI32)IL64(0))));}
      else {
        X60Qx_49 = NIM_FALSE;}
      if (X60Qx_49){
        string_0_sysvq0asl X60Qdesugar_3 = dollarQ_2_sysvq0asl((*lx_4).col_0);
        string_0_sysvq0asl X60Qdesugar_4 = dollarQ_2_sysvq0asl((*lx_4).indentUnit_0);
        NI64 X60Qx_51 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 7022359100733155838ull, .more_0 = (&strlit_0_I6280642289327629658_lex3r1urc1)}
        );
        NI64 X60Qx_52 = len_4_sysvq0asl(X60Qdesugar_3);
        NI64 X60Qx_53 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 7957145225219219710ull, .more_0 = (&strlit_0_I10413904334500263167_lex3r1urc1)}
        );
        NI64 X60Qx_54 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 7811887317977167102ull, .more_0 = (&strlit_0_I16348626965461658915_lex3r1urc1)}
        );
        NI64 X60Qx_55 = len_4_sysvq0asl(X60Qdesugar_4);
        NI64 X60Qx_56 = len_4_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 7955939889552304638ull, .more_0 = (&strlit_0_I5579380358509126566_lex3r1urc1)}
        );
        string_0_sysvq0asl X60Qdesugar_5 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(((NI)(X60Qx_51 + X60Qx_52)) + X60Qx_53)) + X60Qx_54)) + X60Qx_55)) + X60Qx_56)));
        add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
          .bytes_0 = 7022359100733155838ull, .more_0 = (&strlit_0_I6280642289327629658_lex3r1urc1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_3);
        add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
          .bytes_0 = 7957145225219219710ull, .more_0 = (&strlit_0_I10413904334500263167_lex3r1urc1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
          .bytes_0 = 7811887317977167102ull, .more_0 = (&strlit_0_I16348626965461658915_lex3r1urc1)}
        );
        add_2_sysvq0asl((&X60Qdesugar_5), X60Qdesugar_4);
        add_2_sysvq0asl((&X60Qdesugar_5), (string_0_sysvq0asl){
          .bytes_0 = 7955939889552304638ull, .more_0 = (&strlit_0_I5579380358509126566_lex3r1urc1)}
        );
        string_0_sysvq0asl X60Qtmp_1 = X60Qdesugar_5;
        nimStrWasMoved((&X60Qdesugar_5));
        add_0_Ikpo3qe_lex3r1urc1((&(*lx_4).diags_0), (Diagnostic_0_tok9e79hf){
          .severity_0 = IL64(0), .code_0 = (string_0_sysvq0asl){
            .bytes_0 = 3275364210760903166ull, .more_0 = (&strlit_0_I1183140066353762900_lex3r1urc1)}
          , .message_0 = X60Qtmp_1, .line_0 = (*lx_4).line_0, .col_0 = ((NI32)IL64(0)), .endCol_0 = (*lx_4).col_0}
        );
        if (IL64(0) == IL64(2)){
          inc_1_Irn1g7r1_aif7a4qfr((&(*lx_4).errors_0));}
        nimStrDestroy(X60Qdesugar_5);
        nimStrDestroy(X60Qdesugar_4);
        nimStrDestroy(X60Qdesugar_3);}
      (*lx_4).prevIndent_0 = (*lx_4).col_0;}}
  return result_13;}
void addUtf8_0_lex3r1urc1(string_0_sysvq0asl* s_0, NI64 cp_0){
  NI64 i_0 = cp_0;
  if (i_0 <= IL64(127)){
    NC8 X60Qx_57 = chr_0_sysvq0asl(((NI64)(i_0 & IL64(255))));
    add_1_sysvq0asl(s_0, X60Qx_57);}
  else {
    if (i_0 <= IL64(2047)){
      NC8 X60Qx_58 = chr_0_sysvq0asl(((NI64)(((NI64)(((NI64)i_0) >> ((NU64)IL64(6)))) | IL64(192))));
      add_1_sysvq0asl(s_0, X60Qx_58);
      NC8 X60Qx_59 = chr_0_sysvq0asl(((NI64)(((NI64)(i_0 & IL64(63))) | IL64(128))));
      add_1_sysvq0asl(s_0, X60Qx_59);}
    else {
      if (i_0 <= IL64(65535)){
        NC8 X60Qx_60 = chr_0_sysvq0asl(((NI64)(((NI64)(((NI64)i_0) >> ((NU64)IL64(12)))) | IL64(224))));
        add_1_sysvq0asl(s_0, X60Qx_60);
        NC8 X60Qx_61 = chr_0_sysvq0asl(((NI64)(((NI64)(((NI64)(((NI64)i_0) >> ((NU64)IL64(6)))) & IL64(63))) | IL64(128))));
        add_1_sysvq0asl(s_0, X60Qx_61);
        NC8 X60Qx_62 = chr_0_sysvq0asl(((NI64)(((NI64)(i_0 & IL64(63))) | IL64(128))));
        add_1_sysvq0asl(s_0, X60Qx_62);}
      else {
        NC8 X60Qx_63 = chr_0_sysvq0asl(((NI64)(((NI64)(((NI64)i_0) >> ((NU64)IL64(18)))) | IL64(240))));
        add_1_sysvq0asl(s_0, X60Qx_63);
        NC8 X60Qx_64 = chr_0_sysvq0asl(((NI64)(((NI64)(((NI64)(((NI64)i_0) >> ((NU64)IL64(12)))) & IL64(63))) | IL64(128))));
        add_1_sysvq0asl(s_0, X60Qx_64);
        NC8 X60Qx_65 = chr_0_sysvq0asl(((NI64)(((NI64)(((NI64)(((NI64)i_0) >> ((NU64)IL64(6)))) & IL64(63))) | IL64(128))));
        add_1_sysvq0asl(s_0, X60Qx_65);
        NC8 X60Qx_66 = chr_0_sysvq0asl(((NI64)(((NI64)(i_0 & IL64(63))) | IL64(128))));
        add_1_sysvq0asl(s_0, X60Qx_66);}}}}
void decodeEscape_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_5, string_0_sysvq0asl* s_1){
  advance_0_lex3r1urc1(lx_5);
  NC8 c_5 = cur_0_lex3r1urc1((&(*lx_5)));
  switch (c_5){
    case (NC8)'n':
    case (NC8)'N':
    {
      add_1_sysvq0asl(s_1, (NC8)'\012');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'p':
    case (NC8)'P':
    {
      add_1_sysvq0asl(s_1, (NC8)'\012');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'r':
    case (NC8)'R':
    case (NC8)'c':
    case (NC8)'C':
    {
      add_1_sysvq0asl(s_1, (NC8)'\015');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'l':
    case (NC8)'L':
    {
      add_1_sysvq0asl(s_1, (NC8)'\012');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'f':
    case (NC8)'F':
    {
      add_1_sysvq0asl(s_1, (NC8)'\014');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'e':
    case (NC8)'E':
    {
      add_1_sysvq0asl(s_1, (NC8)'\033');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'a':
    case (NC8)'A':
    {
      add_1_sysvq0asl(s_1, (NC8)'\007');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'b':
    case (NC8)'B':
    {
      add_1_sysvq0asl(s_1, (NC8)'\010');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'v':
    case (NC8)'V':
    {
      add_1_sysvq0asl(s_1, (NC8)'\013');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'t':
    case (NC8)'T':
    {
      add_1_sysvq0asl(s_1, (NC8)'\011');
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'\'':
    case (NC8)'\"':
    case (NC8)'\\':
    {
      add_1_sysvq0asl(s_1, c_5);
      advance_0_lex3r1urc1(lx_5);}
    break;
    case (NC8)'x':
    case (NC8)'X':
    {
      advance_0_lex3r1urc1(lx_5);
      NI64 xi_0 = IL64(0);
      NI64 k_1 = IL64(0);
      {
        while (NIM_TRUE){
          NB8 X60Qx_67;
          if (k_1 < IL64(2)){
            NC8 X60Qx_68 = cur_0_lex3r1urc1((&(*lx_5)));
            NB8 X60Qx_69 = isHexDigit_0_lex3r1urc1(X60Qx_68);
            X60Qx_67 = X60Qx_69;}
          else {
            X60Qx_67 = NIM_FALSE;}
          if (X60Qx_67){
            NC8 X60Qx_70 = cur_0_lex3r1urc1((&(*lx_5)));
            NI64 X60Qx_71 = hexVal_0_lex3r1urc1(X60Qx_70);
            xi_0 = ((NI64)(((NI64)(xi_0 << IL64(4))) | X60Qx_71));
            advance_0_lex3r1urc1(lx_5);
            inc_1_Irn1g7r1_aif7a4qfr((&k_1));}
          else {
            break;}}}
      whileStmtLabel_0: ;
      NC8 X60Qx_72 = chr_0_sysvq0asl(((NI64)(xi_0 & IL64(255))));
      add_1_sysvq0asl(s_1, X60Qx_72);}
    break;
    case (NC8)'u':
    case (NC8)'U':
    {
      advance_0_lex3r1urc1(lx_5);
      NI64 xi_1 = IL64(0);
      NC8 X60Qx_73 = cur_0_lex3r1urc1((&(*lx_5)));
      if (X60Qx_73 == (NC8)'{'){
        advance_0_lex3r1urc1(lx_5);
        {
          while (NIM_TRUE){
            NB8 X60Qx_74;
            NC8 X60Qx_75 = cur_0_lex3r1urc1((&(*lx_5)));
            if ((!(X60Qx_75 == (NC8)'}'))){
              X60Qx_74 = ((*lx_5).pos_0 < (*lx_5).n_0);}
            else {
              X60Qx_74 = NIM_FALSE;}
            if (X60Qx_74){
              NC8 X60Qx_76 = cur_0_lex3r1urc1((&(*lx_5)));
              NB8 X60Qx_77 = isHexDigit_0_lex3r1urc1(X60Qx_76);
              if (X60Qx_77){
                NC8 X60Qx_78 = cur_0_lex3r1urc1((&(*lx_5)));
                NI64 X60Qx_79 = hexVal_0_lex3r1urc1(X60Qx_78);
                xi_1 = ((NI64)(((NI64)(xi_1 << IL64(4))) | X60Qx_79));}
              advance_0_lex3r1urc1(lx_5);}
            else {
              break;}}}
        whileStmtLabel_1: ;
        NC8 X60Qx_80 = cur_0_lex3r1urc1((&(*lx_5)));
        if (X60Qx_80 == (NC8)'}'){
          advance_0_lex3r1urc1(lx_5);}}
      else {
        NI64 k_2 = IL64(0);
        {
          while (NIM_TRUE){
            NB8 X60Qx_81;
            if (k_2 < IL64(4)){
              NC8 X60Qx_82 = cur_0_lex3r1urc1((&(*lx_5)));
              NB8 X60Qx_83 = isHexDigit_0_lex3r1urc1(X60Qx_82);
              X60Qx_81 = X60Qx_83;}
            else {
              X60Qx_81 = NIM_FALSE;}
            if (X60Qx_81){
              NC8 X60Qx_84 = cur_0_lex3r1urc1((&(*lx_5)));
              NI64 X60Qx_85 = hexVal_0_lex3r1urc1(X60Qx_84);
              xi_1 = ((NI64)(((NI64)(xi_1 << IL64(4))) | X60Qx_85));
              advance_0_lex3r1urc1(lx_5);
              inc_1_Irn1g7r1_aif7a4qfr((&k_2));}
            else {
              break;}}}
        whileStmtLabel_2: ;}
      addUtf8_0_lex3r1urc1(s_1, xi_1);}
    break;
    case (NC8)'0' ... (NC8)'9':
    {
      NI64 xi_2 = IL64(0);
      {
        while (NIM_TRUE){
          NC8 X60Qx_86 = cur_0_lex3r1urc1((&(*lx_5)));
          NB8 X60Qx_87 = isDigit_0_lex3r1urc1(X60Qx_86);
          if (X60Qx_87){
            NC8 X60Qx_88 = cur_0_lex3r1urc1((&(*lx_5)));
            xi_2 = ((NI64)(((NI64)(xi_2 * IL64(10))) + ((NI64)(((NI64)X60Qx_88) - ((NI64)(NC8)'0')))));
            advance_0_lex3r1urc1(lx_5);}
          else {
            break;}}}
      whileStmtLabel_3: ;
      NC8 X60Qx_89 = chr_0_sysvq0asl(((NI64)(xi_2 & IL64(255))));
      add_1_sysvq0asl(s_1, X60Qx_89);}
    break;
    default:
    {
      if ((*lx_5).pos_0 < (*lx_5).n_0){
        add_1_sysvq0asl(s_1, c_5);
        advance_0_lex3r1urc1(lx_5);}}
    break;}}
Token_0_tok9e79hf lexTripleString_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_6, NB8 raw_0){
  Token_0_tok9e79hf result_14;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_14));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_14));
  Token_0_tok9e79hf X60Qx_90 = startToken_0_lex3r1urc1(lx_6, IL64(7));
  result_14 = X60Qx_90;
  advance_0_lex3r1urc1(lx_6);
  advance_0_lex3r1urc1(lx_6);
  advance_0_lex3r1urc1(lx_6);
  NB8 X60Qx_91;
  NC8 X60Qx_92 = cur_0_lex3r1urc1((&(*lx_6)));
  if (X60Qx_92 == (NC8)' '){
    X60Qx_91 = NIM_TRUE;}
  else {
    NC8 X60Qx_93 = cur_0_lex3r1urc1((&(*lx_6)));
    X60Qx_91 = (X60Qx_93 == (NC8)'\011');}
  if (X60Qx_91){
    Lexer_0_lex3r1urc1 save_0 = eQdupQ_SX4cexer0lex3r1urc1_0_lex3r1urc1((&(*lx_6)));
    {
      while (NIM_TRUE){
        NB8 X60Qx_94;
        NC8 X60Qx_95 = cur_0_lex3r1urc1((&(*lx_6)));
        if (X60Qx_95 == (NC8)' '){
          X60Qx_94 = NIM_TRUE;}
        else {
          NC8 X60Qx_96 = cur_0_lex3r1urc1((&(*lx_6)));
          X60Qx_94 = (X60Qx_96 == (NC8)'\011');}
        if (X60Qx_94){
          advance_0_lex3r1urc1(lx_6);}
        else {
          break;}}}
    whileStmtLabel_0: ;
    NB8 X60Qx_97;
    NC8 X60Qx_98 = cur_0_lex3r1urc1((&(*lx_6)));
    if (X60Qx_98 == (NC8)'\015'){
      X60Qx_97 = NIM_TRUE;}
    else {
      NC8 X60Qx_99 = cur_0_lex3r1urc1((&(*lx_6)));
      X60Qx_97 = (X60Qx_99 == (NC8)'\012');}
    if (X60Qx_97){
      }
    else {
      eQdestroyQ_SX4cexer0lex3r1urc1_0_lex3r1urc1((&(*lx_6)));
      (*lx_6) = save_0;
      eQwasmovedQ_SX4cexer0lex3r1urc1_0_lex3r1urc1((&save_0));}
    eQdestroyQ_SX4cexer0lex3r1urc1_0_lex3r1urc1((&save_0));}
  NC8 X60Qx_100 = cur_0_lex3r1urc1((&(*lx_6)));
  if (X60Qx_100 == (NC8)'\015'){
    advance_0_lex3r1urc1(lx_6);
    NC8 X60Qx_101 = cur_0_lex3r1urc1((&(*lx_6)));
    if (X60Qx_101 == (NC8)'\012'){
      advance_0_lex3r1urc1(lx_6);}}
  else {
    NC8 X60Qx_102 = cur_0_lex3r1urc1((&(*lx_6)));
    if (X60Qx_102 == (NC8)'\012'){
      advance_0_lex3r1urc1(lx_6);}}
  string_0_sysvq0asl s_5 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  {
    while ((*lx_6).pos_0 < (*lx_6).n_0){
      NB8 X60Qx_103;
      NB8 X60Qx_104;
      NB8 X60Qx_105;
      NC8 X60Qx_106 = cur_0_lex3r1urc1((&(*lx_6)));
      if (X60Qx_106 == (NC8)'\"'){
        NC8 X60Qx_107 = peek_0_lex3r1urc1((&(*lx_6)), IL64(1));
        X60Qx_105 = (X60Qx_107 == (NC8)'\"');}
      else {
        X60Qx_105 = NIM_FALSE;}
      if (X60Qx_105){
        NC8 X60Qx_108 = peek_0_lex3r1urc1((&(*lx_6)), IL64(2));
        X60Qx_104 = (X60Qx_108 == (NC8)'\"');}
      else {
        X60Qx_104 = NIM_FALSE;}
      if (X60Qx_104){
        NC8 X60Qx_109 = peek_0_lex3r1urc1((&(*lx_6)), IL64(3));
        X60Qx_103 = (!(X60Qx_109 == (NC8)'\"'));}
      else {
        X60Qx_103 = NIM_FALSE;}
      if (X60Qx_103){
        advance_0_lex3r1urc1(lx_6);
        advance_0_lex3r1urc1(lx_6);
        advance_0_lex3r1urc1(lx_6);
        goto whileStmtLabel_1;}
      else {
        NC8 X60Qx_110 = cur_0_lex3r1urc1((&(*lx_6)));
        if (X60Qx_110 == (NC8)'\015'){
          advance_0_lex3r1urc1(lx_6);
          NC8 X60Qx_111 = cur_0_lex3r1urc1((&(*lx_6)));
          if (X60Qx_111 == (NC8)'\012'){
            advance_0_lex3r1urc1(lx_6);}
          add_1_sysvq0asl((&s_5), (NC8)'\012');}
        else {
          NC8 X60Qx_112 = cur_0_lex3r1urc1((&(*lx_6)));
          if (X60Qx_112 == (NC8)'\012'){
            advance_0_lex3r1urc1(lx_6);
            add_1_sysvq0asl((&s_5), (NC8)'\012');}
          else {
            NC8 X60Qx_113 = cur_0_lex3r1urc1((&(*lx_6)));
            add_1_sysvq0asl((&s_5), X60Qx_113);
            advance_0_lex3r1urc1(lx_6);}}}}}
  whileStmtLabel_1: ;
  string_0_sysvq0asl* X60Qlhs_2 = (&result_14.s_0);
  nimStrDestroy((*X60Qlhs_2));
  (*X60Qlhs_2) = s_5;
  nimStrWasMoved((&s_5));
  nimStrDestroy(s_5);
  return result_14;
  nimStrDestroy(s_5);
  return result_14;}
Token_0_tok9e79hf lexRawString_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_7){
  Token_0_tok9e79hf result_15;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_15));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_15));
  Token_0_tok9e79hf X60Qx_114 = startToken_0_lex3r1urc1(lx_7, IL64(6));
  result_15 = X60Qx_114;
  advance_0_lex3r1urc1(lx_7);
  string_0_sysvq0asl s_6 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  {
    while (NIM_TRUE){
      NB8 X60Qx_115;
      if ((*lx_7).pos_0 < (*lx_7).n_0){
        NC8 X60Qx_116 = cur_0_lex3r1urc1((&(*lx_7)));
        X60Qx_115 = (!(X60Qx_116 == (NC8)'\012'));}
      else {
        X60Qx_115 = NIM_FALSE;}
      if (X60Qx_115){
        NC8 X60Qx_117 = cur_0_lex3r1urc1((&(*lx_7)));
        if (X60Qx_117 == (NC8)'\"'){
          NC8 X60Qx_118 = peek_0_lex3r1urc1((&(*lx_7)), IL64(1));
          if (X60Qx_118 == (NC8)'\"'){
            add_1_sysvq0asl((&s_6), (NC8)'\"');
            advance_0_lex3r1urc1(lx_7);
            advance_0_lex3r1urc1(lx_7);}
          else {
            advance_0_lex3r1urc1(lx_7);
            goto whileStmtLabel_0;}}
        else {
          NC8 X60Qx_119 = cur_0_lex3r1urc1((&(*lx_7)));
          add_1_sysvq0asl((&s_6), X60Qx_119);
          advance_0_lex3r1urc1(lx_7);}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl* X60Qlhs_3 = (&result_15.s_0);
  nimStrDestroy((*X60Qlhs_3));
  (*X60Qlhs_3) = s_6;
  nimStrWasMoved((&s_6));
  nimStrDestroy(s_6);
  return result_15;
  nimStrDestroy(s_6);
  return result_15;}
Token_0_tok9e79hf lexString_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_8){
  Token_0_tok9e79hf result_16;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_16));
  NB8 X60Qx_120;
  NC8 X60Qx_121 = peek_0_lex3r1urc1((&(*lx_8)), IL64(1));
  if (X60Qx_121 == (NC8)'\"'){
    NC8 X60Qx_122 = peek_0_lex3r1urc1((&(*lx_8)), IL64(2));
    X60Qx_120 = (X60Qx_122 == (NC8)'\"');}
  else {
    X60Qx_120 = NIM_FALSE;}
  if (X60Qx_120){
    Token_0_tok9e79hf X60Qx_123 = lexTripleString_0_lex3r1urc1(lx_8, NIM_FALSE);
    result_16 = X60Qx_123;
    return result_16;}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_16));
  Token_0_tok9e79hf X60Qx_124 = startToken_0_lex3r1urc1(lx_8, IL64(5));
  result_16 = X60Qx_124;
  advance_0_lex3r1urc1(lx_8);
  string_0_sysvq0asl s_7 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  {
    while (NIM_TRUE){
      NB8 X60Qx_125;
      NB8 X60Qx_126;
      if ((*lx_8).pos_0 < (*lx_8).n_0){
        NC8 X60Qx_127 = cur_0_lex3r1urc1((&(*lx_8)));
        X60Qx_126 = (!(X60Qx_127 == (NC8)'\"'));}
      else {
        X60Qx_126 = NIM_FALSE;}
      if (X60Qx_126){
        NC8 X60Qx_128 = cur_0_lex3r1urc1((&(*lx_8)));
        X60Qx_125 = (!(X60Qx_128 == (NC8)'\012'));}
      else {
        X60Qx_125 = NIM_FALSE;}
      if (X60Qx_125){
        NC8 X60Qx_129 = cur_0_lex3r1urc1((&(*lx_8)));
        if (X60Qx_129 == (NC8)'\\'){
          decodeEscape_0_lex3r1urc1(lx_8, (&s_7));}
        else {
          NC8 X60Qx_130 = cur_0_lex3r1urc1((&(*lx_8)));
          add_1_sysvq0asl((&s_7), X60Qx_130);
          advance_0_lex3r1urc1(lx_8);}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NC8 X60Qx_131 = cur_0_lex3r1urc1((&(*lx_8)));
  if (X60Qx_131 == (NC8)'\"'){
    advance_0_lex3r1urc1(lx_8);}
  else {
    add_0_Ikpo3qe_lex3r1urc1((&(*lx_8).diags_0), (Diagnostic_0_tok9e79hf){
      .severity_0 = IL64(2), .code_0 = (string_0_sysvq0asl){
        .bytes_0 = 7596853926514554366ull, .more_0 = (&strlit_0_I4192191418491144372_lex3r1urc1)}
      , .message_0 = (string_0_sysvq0asl){
        .bytes_0 = 7596853926514554366ull, .more_0 = (&strlit_0_I8436252750452789659_lex3r1urc1)}
      , .line_0 = result_16.line_0, .col_0 = result_16.col_0, .endCol_0 = (*lx_8).col_0}
    );
    if (IL64(2) == IL64(2)){
      inc_1_Irn1g7r1_aif7a4qfr((&(*lx_8).errors_0));}}
  string_0_sysvq0asl* X60Qlhs_4 = (&result_16.s_0);
  nimStrDestroy((*X60Qlhs_4));
  (*X60Qlhs_4) = s_7;
  nimStrWasMoved((&s_7));
  nimStrDestroy(s_7);
  return result_16;
  nimStrDestroy(s_7);
  return result_16;}
Token_0_tok9e79hf lexRawOrTriple_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_9){
  Token_0_tok9e79hf result_17;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_17));
  Token_0_tok9e79hf anchor_0 = startToken_0_lex3r1urc1(lx_9, IL64(6));
  advance_0_lex3r1urc1(lx_9);
  NB8 X60Qx_132;
  NB8 X60Qx_133;
  NC8 X60Qx_134 = cur_0_lex3r1urc1((&(*lx_9)));
  if (X60Qx_134 == (NC8)'\"'){
    NC8 X60Qx_135 = peek_0_lex3r1urc1((&(*lx_9)), IL64(1));
    X60Qx_133 = (X60Qx_135 == (NC8)'\"');}
  else {
    X60Qx_133 = NIM_FALSE;}
  if (X60Qx_133){
    NC8 X60Qx_136 = peek_0_lex3r1urc1((&(*lx_9)), IL64(2));
    X60Qx_132 = (X60Qx_136 == (NC8)'\"');}
  else {
    X60Qx_132 = NIM_FALSE;}
  if (X60Qx_132){
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_17));
    Token_0_tok9e79hf X60Qx_137 = lexTripleString_0_lex3r1urc1(lx_9, NIM_TRUE);
    result_17 = X60Qx_137;}
  else {
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_17));
    Token_0_tok9e79hf X60Qx_138 = lexRawString_0_lex3r1urc1(lx_9);
    result_17 = X60Qx_138;}
  result_17.line_0 = anchor_0.line_0;
  result_17.col_0 = anchor_0.col_0;
  result_17.indent_0 = anchor_0.indent_0;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&anchor_0));
  return result_17;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&anchor_0));
  return result_17;}
Token_0_tok9e79hf lexChar_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_10){
  Token_0_tok9e79hf result_18;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_18));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_18));
  Token_0_tok9e79hf X60Qx_139 = startToken_0_lex3r1urc1(lx_10, IL64(8));
  result_18 = X60Qx_139;
  advance_0_lex3r1urc1(lx_10);
  string_0_sysvq0asl s_8 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  NC8 X60Qx_140 = cur_0_lex3r1urc1((&(*lx_10)));
  if (X60Qx_140 == (NC8)'\\'){
    decodeEscape_0_lex3r1urc1(lx_10, (&s_8));}
  else {
    NC8 X60Qx_141 = cur_0_lex3r1urc1((&(*lx_10)));
    add_1_sysvq0asl((&s_8), X60Qx_141);
    advance_0_lex3r1urc1(lx_10);}
  NC8 X60Qx_142 = cur_0_lex3r1urc1((&(*lx_10)));
  if (X60Qx_142 == (NC8)'\''){
    advance_0_lex3r1urc1(lx_10);}
  NI64 X60Qx_143 = len_4_sysvq0asl(s_8);
  if (IL64(0) < X60Qx_143){
    NC8 X60Qx_144 = getQ_9_sysvq0asl(s_8, IL64(0));
    result_18.iVal_0 = ((NI64)((NI64)X60Qx_144));}
  string_0_sysvq0asl* X60Qlhs_5 = (&result_18.s_0);
  nimStrDestroy((*X60Qlhs_5));
  (*X60Qlhs_5) = s_8;
  nimStrWasMoved((&s_8));
  nimStrDestroy(s_8);
  return result_18;
  nimStrDestroy(s_8);
  return result_18;}
NI64 decodeIntBase_0_lex3r1urc1(string_0_sysvq0asl digits_0, NI64 base_0){
  NI64 result_19;
  result_19 = IL64(0);
  switch (base_0){
    case IL64(16):
    {
      {
        openArray_0_Ijk0jkw1_has9tn57v X60Qlf_0 = toOpenArray_2_sysvq0asl((&digits_0));
        NI64 X60Qlf_1 = IL64(0);
        {
          while (NIM_TRUE){
            NI64 X60Qx_145 = len_6_Iroq7kd1_has9tn57v(X60Qlf_0);
            if (X60Qlf_1 < X60Qx_145){
              {
                NC8* X60Qii_2 = getQ_10_I5nt6we_has9tn57v(X60Qlf_0, X60Qlf_1);
                NI64 X60Qx_146 = hexVal_0_lex3r1urc1((*X60Qii_2));
                result_19 = ((NI64)(((NI64)(result_19 << IL64(4))) | ((NI64)X60Qx_146)));}
              inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_1));}
            else {
              break;}}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;}
    break;
    case IL64(8):
    {
      {
        openArray_0_Ijk0jkw1_has9tn57v X60Qlf_2 = toOpenArray_2_sysvq0asl((&digits_0));
        NI64 X60Qlf_3 = IL64(0);
        {
          while (NIM_TRUE){
            NI64 X60Qx_147 = len_6_Iroq7kd1_has9tn57v(X60Qlf_2);
            if (X60Qlf_3 < X60Qx_147){
              {
                NC8* X60Qii_5 = getQ_10_I5nt6we_has9tn57v(X60Qlf_2, X60Qlf_3);
                result_19 = ((NI64)(((NI64)(result_19 << IL64(3))) | ((NI64)((NI64)(((NI64)(*X60Qii_5)) - ((NI64)(NC8)'0'))))));}
              inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_3));}
            else {
              break;}}}
        whileStmtLabel_4: ;}
      forStmtLabel_3: ;}
    break;
    case IL64(2):
    {
      {
        openArray_0_Ijk0jkw1_has9tn57v X60Qlf_4 = toOpenArray_2_sysvq0asl((&digits_0));
        NI64 X60Qlf_5 = IL64(0);
        {
          while (NIM_TRUE){
            NI64 X60Qx_148 = len_6_Iroq7kd1_has9tn57v(X60Qlf_4);
            if (X60Qlf_5 < X60Qx_148){
              {
                NC8* X60Qii_8 = getQ_10_I5nt6we_has9tn57v(X60Qlf_4, X60Qlf_5);
                result_19 = ((NI64)(((NI64)(result_19 << IL64(1))) | ((NI64)((NI64)(((NI64)(*X60Qii_8)) - ((NI64)(NC8)'0'))))));}
              inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_5));}
            else {
              break;}}}
        whileStmtLabel_7: ;}
      forStmtLabel_6: ;}
    break;
    default:
    {
      {
        openArray_0_Ijk0jkw1_has9tn57v X60Qlf_6 = toOpenArray_2_sysvq0asl((&digits_0));
        NI64 X60Qlf_7 = IL64(0);
        {
          while (NIM_TRUE){
            NI64 X60Qx_149 = len_6_Iroq7kd1_has9tn57v(X60Qlf_6);
            if (X60Qlf_7 < X60Qx_149){
              {
                NC8* X60Qii_11 = getQ_10_I5nt6we_has9tn57v(X60Qlf_6, X60Qlf_7);
                result_19 = ((NI64)(((NI64)(result_19 * IL64(10))) + ((NI64)((NI64)(((NI64)(*X60Qii_11)) - ((NI64)(NC8)'0'))))));}
              inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_7));}
            else {
              break;}}}
        whileStmtLabel_10: ;}
      forStmtLabel_9: ;}
    break;}
  return result_19;}
NF64 parseFloatStr_0_lex3r1urc1(string_0_sysvq0asl s_2){
  NF64 result_20;
  NF64 f_0 = 0.0;
  openArray_0_Ijk0jkw1_has9tn57v X60Qx_150 = toOpenArray_2_sysvq0asl((&s_2));
  NI64 X60Qx_151 = parseBiggestFloat_0_party5a2l1(X60Qx_150, (&f_0));
  result_20 = ((NF64)f_0);
  return result_20;}
string_0_sysvq0asl canonFloatSuffix_0_lex3r1urc1(string_0_sysvq0asl s_3){
  string_0_sysvq0asl result_21;
  nimStrWasMoved((&result_21));
  string_0_sysvq0asl X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  NB8 X60Qtc_3 = nimStrAtLe_0_sysvq0asl(s_3, IL64(0), (NC8)'F');
  if (X60Qtc_3){
    NB8 X60Qtc_4 = nimStrAtLe_0_sysvq0asl(s_3, IL64(1), (NC8)'3');
    if (X60Qtc_4){
      if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
        .bytes_0 = 842221059ull, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_0;}
      else if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
        .bytes_0 = 241360258564ull, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_2;}}
    else {
      NB8 X60Qtc_5 = nimStrAtLe_0_sysvq0asl(s_3, IL64(0), (NC8)'D');
      if (X60Qtc_5){
        if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
          .bytes_0 = 17409ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_1;}}
      else {
        if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
          .bytes_0 = 17921ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
          .bytes_0 = 875972099ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_1;}}}}
  else {
    NB8 X60Qtc_6 = nimStrAtLe_0_sysvq0asl(s_3, IL64(1), (NC8)'3');
    if (X60Qtc_6){
      if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
        .bytes_0 = 842229251ull, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_0;}
      else if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
        .bytes_0 = 241360266756ull, .more_0 = NIM_NIL}
      )){
        goto X60Qsc_2;}}
    else {
      NB8 X60Qtc_7 = nimStrAtLe_0_sysvq0asl(s_3, IL64(0), (NC8)'d');
      if (X60Qtc_7){
        if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
          .bytes_0 = 25601ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_1;}}
      else {
        if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
          .bytes_0 = 26113ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_0;}
        else if (equalStrings_0_sysvq0asl(s_3, (string_0_sysvq0asl){
          .bytes_0 = 875980291ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_1;}}}}
  goto X60Qsc_9;
  X60Qsc_0: ;
  nimStrDestroy(X60Qx_3);
  X60Qx_3 = (string_0_sysvq0asl){
    .bytes_0 = 842229251ull, .more_0 = NIM_NIL}
  ;
  goto X60Qsc_8;
  X60Qsc_1: ;
  nimStrDestroy(X60Qx_3);
  X60Qx_3 = (string_0_sysvq0asl){
    .bytes_0 = 875980291ull, .more_0 = NIM_NIL}
  ;
  goto X60Qsc_8;
  X60Qsc_2: ;
  nimStrDestroy(X60Qx_3);
  X60Qx_3 = (string_0_sysvq0asl){
    .bytes_0 = 241360266756ull, .more_0 = NIM_NIL}
  ;
  goto X60Qsc_8;
  X60Qsc_9: ;
  nimStrDestroy(X60Qx_3);
  string_0_sysvq0asl X60Qx_152 = nimStrDup(s_3);
  X60Qx_3 = X60Qx_152;
  X60Qsc_8: ;
  nimStrDestroy(result_21);
  result_21 = X60Qx_3;
  nimStrWasMoved((&X60Qx_3));
  nimStrDestroy(X60Qx_3);
  return result_21;
  nimStrDestroy(X60Qx_3);
  return result_21;}
Token_0_tok9e79hf lexNumber_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_11){
  Token_0_tok9e79hf result_22;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_22));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_22));
  Token_0_tok9e79hf X60Qx_153 = startToken_0_lex3r1urc1(lx_11, IL64(3));
  result_22 = X60Qx_153;
  NI64 base_1 = IL64(10);
  string_0_sysvq0asl digits_1 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  string_0_sysvq0asl floatText_0 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  NB8 isFloat_0 = NIM_FALSE;
  NB8 X60Qx_4;
  NC8 X60Qx_154 = cur_0_lex3r1urc1((&(*lx_11)));
  if (X60Qx_154 == (NC8)'0'){
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_6 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
      .a = {
        0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 12ull, 0ull, 0ull, 1ull, 12ull, 128ull, 0ull, 1ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull}}
    ;
    NC8 X60Qx_155 = peek_0_lex3r1urc1((&(*lx_11)), IL64(1));
    NU64 X60Qdesugar_7 = ((NU)X60Qx_155);
    X60Qx_4 = (((NU8)(X60Qdesugar_6.a[((NU)(X60Qdesugar_7 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_7 & 7ull)))))) != 0ull);}
  else {
    X60Qx_4 = NIM_FALSE;}
  if (X60Qx_4){
    NC8 b_1 = peek_0_lex3r1urc1((&(*lx_11)), IL64(1));
    advance_0_lex3r1urc1(lx_11);
    advance_0_lex3r1urc1(lx_11);
    switch (b_1){
      case (NC8)'x':
      case (NC8)'X':
      {
        base_1 = IL64(16);}
      break;
      case (NC8)'o':
      {
        base_1 = IL64(8);}
      break;
      case (NC8)'c':
      case (NC8)'C':
      {
        base_1 = IL64(8);}
      break;
      case (NC8)'b':
      case (NC8)'B':
      {
        base_1 = IL64(2);}
      break;
      default:
      {
        }
      break;}
    {
      while (NIM_TRUE){
        NC8 c_10 = cur_0_lex3r1urc1((&(*lx_11)));
        if (c_10 == (NC8)'_'){
          advance_0_lex3r1urc1(lx_11);}
        else {
          NB8 X60Qx_156;
          NB8 X60Qx_157;
          NB8 X60Qx_158;
          if (base_1 == IL64(16)){
            NB8 X60Qx_159 = isHexDigit_0_lex3r1urc1(c_10);
            X60Qx_158 = X60Qx_159;}
          else {
            X60Qx_158 = NIM_FALSE;}
          if (X60Qx_158){
            X60Qx_157 = NIM_TRUE;}
          else {
            NB8 X60Qx_160;
            NB8 X60Qx_161;
            if (base_1 == IL64(8)){
              X60Qx_161 = ((NC8)'0' <= c_10);}
            else {
              X60Qx_161 = NIM_FALSE;}
            if (X60Qx_161){
              X60Qx_160 = (c_10 <= (NC8)'7');}
            else {
              X60Qx_160 = NIM_FALSE;}
            X60Qx_157 = X60Qx_160;}
          if (X60Qx_157){
            X60Qx_156 = NIM_TRUE;}
          else {
            NB8 X60Qx_162;
            if (base_1 == IL64(2)){
              NB8 X60Qx_163;
              if (c_10 == (NC8)'0'){
                X60Qx_163 = NIM_TRUE;}
              else {
                X60Qx_163 = (c_10 == (NC8)'1');}
              X60Qx_162 = X60Qx_163;}
            else {
              X60Qx_162 = NIM_FALSE;}
            X60Qx_156 = X60Qx_162;}
          if (X60Qx_156){
            add_1_sysvq0asl((&digits_1), c_10);
            advance_0_lex3r1urc1(lx_11);}
          else {
            goto whileStmtLabel_0;}}}}
    whileStmtLabel_0: ;}
  else {
    {
      while (NIM_TRUE){
        NC8 X60Qx_164 = cur_0_lex3r1urc1((&(*lx_11)));
        NB8 X60Qx_165 = isDigit_0_lex3r1urc1(X60Qx_164);
        if (X60Qx_165){
          NC8 X60Qx_166 = cur_0_lex3r1urc1((&(*lx_11)));
          add_1_sysvq0asl((&digits_1), X60Qx_166);
          NC8 X60Qx_167 = cur_0_lex3r1urc1((&(*lx_11)));
          add_1_sysvq0asl((&floatText_0), X60Qx_167);
          advance_0_lex3r1urc1(lx_11);}
        else {
          NC8 X60Qx_168 = cur_0_lex3r1urc1((&(*lx_11)));
          if (X60Qx_168 == (NC8)'_'){
            advance_0_lex3r1urc1(lx_11);}
          else {
            goto whileStmtLabel_1;}}}}
    whileStmtLabel_1: ;
    NB8 X60Qx_169;
    NC8 X60Qx_170 = cur_0_lex3r1urc1((&(*lx_11)));
    if (X60Qx_170 == (NC8)'.'){
      NC8 X60Qx_171 = peek_0_lex3r1urc1((&(*lx_11)), IL64(1));
      NB8 X60Qx_172 = isDigit_0_lex3r1urc1(X60Qx_171);
      X60Qx_169 = X60Qx_172;}
    else {
      X60Qx_169 = NIM_FALSE;}
    if (X60Qx_169){
      isFloat_0 = NIM_TRUE;
      add_1_sysvq0asl((&floatText_0), (NC8)'.');
      advance_0_lex3r1urc1(lx_11);
      {
        while (NIM_TRUE){
          NC8 X60Qx_173 = cur_0_lex3r1urc1((&(*lx_11)));
          NB8 X60Qx_174 = isDigit_0_lex3r1urc1(X60Qx_173);
          if (X60Qx_174){
            NC8 X60Qx_175 = cur_0_lex3r1urc1((&(*lx_11)));
            add_1_sysvq0asl((&floatText_0), X60Qx_175);
            advance_0_lex3r1urc1(lx_11);}
          else {
            NC8 X60Qx_176 = cur_0_lex3r1urc1((&(*lx_11)));
            if (X60Qx_176 == (NC8)'_'){
              advance_0_lex3r1urc1(lx_11);}
            else {
              goto whileStmtLabel_2;}}}}
      whileStmtLabel_2: ;}
    NB8 X60Qx_177;
    NC8 X60Qx_178 = cur_0_lex3r1urc1((&(*lx_11)));
    if (X60Qx_178 == (NC8)'e'){
      X60Qx_177 = NIM_TRUE;}
    else {
      NC8 X60Qx_179 = cur_0_lex3r1urc1((&(*lx_11)));
      X60Qx_177 = (X60Qx_179 == (NC8)'E');}
    if (X60Qx_177){
      isFloat_0 = NIM_TRUE;
      add_1_sysvq0asl((&floatText_0), (NC8)'e');
      advance_0_lex3r1urc1(lx_11);
      NB8 X60Qx_180;
      NC8 X60Qx_181 = cur_0_lex3r1urc1((&(*lx_11)));
      if (X60Qx_181 == (NC8)'+'){
        X60Qx_180 = NIM_TRUE;}
      else {
        NC8 X60Qx_182 = cur_0_lex3r1urc1((&(*lx_11)));
        X60Qx_180 = (X60Qx_182 == (NC8)'-');}
      if (X60Qx_180){
        NC8 X60Qx_183 = cur_0_lex3r1urc1((&(*lx_11)));
        add_1_sysvq0asl((&floatText_0), X60Qx_183);
        advance_0_lex3r1urc1(lx_11);}
      {
        while (NIM_TRUE){
          NC8 X60Qx_184 = cur_0_lex3r1urc1((&(*lx_11)));
          NB8 X60Qx_185 = isDigit_0_lex3r1urc1(X60Qx_184);
          if (X60Qx_185){
            NC8 X60Qx_186 = cur_0_lex3r1urc1((&(*lx_11)));
            add_1_sysvq0asl((&floatText_0), X60Qx_186);
            advance_0_lex3r1urc1(lx_11);}
          else {
            NC8 X60Qx_187 = cur_0_lex3r1urc1((&(*lx_11)));
            if (X60Qx_187 == (NC8)'_'){
              advance_0_lex3r1urc1(lx_11);}
            else {
              goto whileStmtLabel_3;}}}}
      whileStmtLabel_3: ;}}
  string_0_sysvq0asl suffix_0 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  {
    NB8 hasQQuote_0 = NIM_FALSE;
    NC8 X60Qx_188 = cur_0_lex3r1urc1((&(*lx_11)));
    if (X60Qx_188 == (NC8)'\''){
      hasQQuote_0 = NIM_TRUE;}
    else {
      X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_8 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
        .a = {
          0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 80ull, 2ull, 32ull, 0ull, 80ull, 2ull, 32ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull}}
      ;
      NC8 X60Qx_189 = cur_0_lex3r1urc1((&(*lx_11)));
      NU64 X60Qdesugar_9 = ((NU)X60Qx_189);
      if ((!(((NU8)(X60Qdesugar_8.a[((NU)(X60Qdesugar_9 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_9 & 7ull)))))) != 0ull))){
        goto suffixScan_0;}}
    if (hasQQuote_0){
      advance_0_lex3r1urc1(lx_11);}
    NC8 X60Qx_190 = cur_0_lex3r1urc1((&(*lx_11)));
    NB8 X60Qx_191 = isIdentStart_0_lex3r1urc1(X60Qx_190);
    if ((!X60Qx_191)){
      goto suffixScan_0;}
    string_0_sysvq0asl raw_1 = (string_0_sysvq0asl){
      .bytes_0 = 0ull, .more_0 = NIM_NIL}
    ;
    {
      while (NIM_TRUE){
        NC8 X60Qx_192 = cur_0_lex3r1urc1((&(*lx_11)));
        NB8 X60Qx_193 = isIdentCont_0_lex3r1urc1(X60Qx_192);
        if (X60Qx_193){
          NC8 X60Qx_194 = cur_0_lex3r1urc1((&(*lx_11)));
          add_1_sysvq0asl((&raw_1), X60Qx_194);
          advance_0_lex3r1urc1(lx_11);}
        else {
          break;}}}
    whileStmtLabel_4: ;
    nimStrDestroy(suffix_0);
    suffix_0 = raw_1;
    nimStrWasMoved((&raw_1));
    nimStrDestroy(raw_1);}
  suffixScan_0: ;
  string_0_sysvq0asl sufl_0 = suffix_0;
  nimStrWasMoved((&suffix_0));
  NB8 X60Qx_195;
  NI64 X60Qx_196 = len_4_sysvq0asl(sufl_0);
  if (IL64(0) < X60Qx_196){
    NB8 X60Qx_197;
    NB8 X60Qx_198;
    NB8 X60Qx_199;
    NC8 X60Qx_200 = getQ_9_sysvq0asl(sufl_0, IL64(0));
    if (X60Qx_200 == (NC8)'f'){
      X60Qx_199 = NIM_TRUE;}
    else {
      NC8 X60Qx_201 = getQ_9_sysvq0asl(sufl_0, IL64(0));
      X60Qx_199 = (X60Qx_201 == (NC8)'F');}
    if (X60Qx_199){
      X60Qx_198 = NIM_TRUE;}
    else {
      NC8 X60Qx_202 = getQ_9_sysvq0asl(sufl_0, IL64(0));
      X60Qx_198 = (X60Qx_202 == (NC8)'d');}
    if (X60Qx_198){
      X60Qx_197 = NIM_TRUE;}
    else {
      NC8 X60Qx_203 = getQ_9_sysvq0asl(sufl_0, IL64(0));
      X60Qx_197 = (X60Qx_203 == (NC8)'D');}
    X60Qx_195 = X60Qx_197;}
  else {
    X60Qx_195 = NIM_FALSE;}
  if (X60Qx_195){
    isFloat_0 = NIM_TRUE;
    string_0_sysvq0asl* X60Qlhs_6 = (&result_22.suffix_0);
    nimStrDestroy((*X60Qlhs_6));
    string_0_sysvq0asl X60Qx_204 = canonFloatSuffix_0_lex3r1urc1(sufl_0);
    (*X60Qlhs_6) = X60Qx_204;}
  else {
    NI64 X60Qx_205 = len_4_sysvq0asl(sufl_0);
    if (IL64(0) < X60Qx_205){
      string_0_sysvq0asl* X60Qlhs_7 = (&result_22.suffix_0);
      nimStrDestroy((*X60Qlhs_7));
      (*X60Qlhs_7) = sufl_0;
      nimStrWasMoved((&sufl_0));}}
  if (isFloat_0){
    result_22.kind_0 = IL64(4);
    NI64 X60Qx_206 = len_4_sysvq0asl(floatText_0);
    if (X60Qx_206 == IL64(0)){
      nimStrDestroy(floatText_0);
      floatText_0 = digits_1;
      nimStrWasMoved((&digits_1));}
    NF64 X60Qx_207 = parseFloatStr_0_lex3r1urc1(floatText_0);
    result_22.fVal_0 = X60Qx_207;
    string_0_sysvq0asl* X60Qlhs_8 = (&result_22.s_0);
    nimStrDestroy((*X60Qlhs_8));
    (*X60Qlhs_8) = floatText_0;
    nimStrWasMoved((&floatText_0));}
  else {
    result_22.kind_0 = IL64(3);
    NI64 X60Qx_208 = decodeIntBase_0_lex3r1urc1(digits_1, base_1);
    result_22.iVal_0 = X60Qx_208;
    string_0_sysvq0asl* X60Qlhs_9 = (&result_22.s_0);
    nimStrDestroy((*X60Qlhs_9));
    (*X60Qlhs_9) = digits_1;
    nimStrWasMoved((&digits_1));}
  nimStrDestroy(sufl_0);
  nimStrDestroy(suffix_0);
  nimStrDestroy(floatText_0);
  nimStrDestroy(digits_1);
  return result_22;
  nimStrDestroy(sufl_0);
  nimStrDestroy(suffix_0);
  nimStrDestroy(floatText_0);
  nimStrDestroy(digits_1);
  return result_22;}
Token_0_tok9e79hf lexOperator_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_12){
  Token_0_tok9e79hf result_23;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_23));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_23));
  Token_0_tok9e79hf X60Qx_209 = startToken_0_lex3r1urc1(lx_12, IL64(9));
  result_23 = X60Qx_209;
  string_0_sysvq0asl s_9 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  {
    while (NIM_TRUE){
      NB8 X60Qx_5;
      if ((*lx_12).pos_0 < (*lx_12).n_0){
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_10 = OperatorChars_0_lex3r1urc1;
        NC8 X60Qx_210 = cur_0_lex3r1urc1((&(*lx_12)));
        NU64 X60Qdesugar_11 = ((NU)X60Qx_210);
        X60Qx_5 = (((NU8)(X60Qdesugar_10.a[((NU)(X60Qdesugar_11 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_11 & 7ull)))))) != 0ull);}
      else {
        X60Qx_5 = NIM_FALSE;}
      if (X60Qx_5){
        NC8 X60Qx_211 = cur_0_lex3r1urc1((&(*lx_12)));
        add_1_sysvq0asl((&s_9), X60Qx_211);
        advance_0_lex3r1urc1(lx_12);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl* X60Qlhs_10 = (&result_23.s_0);
  nimStrDestroy((*X60Qlhs_10));
  (*X60Qlhs_10) = s_9;
  nimStrWasMoved((&s_9));
  nimStrDestroy(s_9);
  return result_23;
  nimStrDestroy(s_9);
  return result_23;}
Token_0_tok9e79hf lexIdent_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_13){
  Token_0_tok9e79hf result_24;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_24));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_24));
  Token_0_tok9e79hf X60Qx_212 = startToken_0_lex3r1urc1(lx_13, IL64(1));
  result_24 = X60Qx_212;
  string_0_sysvq0asl s_10 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  {
    while (NIM_TRUE){
      NB8 X60Qx_213;
      if ((*lx_13).pos_0 < (*lx_13).n_0){
        NC8 X60Qx_214 = cur_0_lex3r1urc1((&(*lx_13)));
        NB8 X60Qx_215 = isIdentCont_0_lex3r1urc1(X60Qx_214);
        X60Qx_213 = X60Qx_215;}
      else {
        X60Qx_213 = NIM_FALSE;}
      if (X60Qx_213){
        NC8 X60Qx_216 = cur_0_lex3r1urc1((&(*lx_13)));
        add_1_sysvq0asl((&s_10), X60Qx_216);
        advance_0_lex3r1urc1(lx_13);}
      else {
        break;}}}
  whileStmtLabel_0: ;
  string_0_sysvq0asl* X60Qlhs_11 = (&result_24.s_0);
  nimStrDestroy((*X60Qlhs_11));
  string_0_sysvq0asl X60Qx_217 = nimStrDup(s_10);
  (*X60Qlhs_11) = X60Qx_217;
  NB8 X60Qx_218 = isKeyword_0_tok9e79hf(s_10);
  if (X60Qx_218){
    result_24.kind_0 = IL64(2);}
  nimStrDestroy(s_10);
  return result_24;
  nimStrDestroy(s_10);
  return result_24;}
Token_0_tok9e79hf lexBackquotedIdent_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_14){
  Token_0_tok9e79hf result_25;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_25));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_25));
  Token_0_tok9e79hf X60Qx_219 = startToken_0_lex3r1urc1(lx_14, IL64(1));
  result_25 = X60Qx_219;
  result_25.quoted_0 = NIM_TRUE;
  advance_0_lex3r1urc1(lx_14);
  string_0_sysvq0asl s_11 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  seq_0_Ixdx2fh1_aif7a4qfr parts_0 = newSeqUninit_0_Im3cqd9_aif7a4qfr(IL64(0));
  seq_0_Ift2sne_lex3r1urc1 partCols_0 = newSeqUninit_0_Iggfvwp_lex3r1urc1(IL64(0));
  {
    while (NIM_TRUE){
      NB8 X60Qx_220;
      NB8 X60Qx_221;
      if ((*lx_14).pos_0 < (*lx_14).n_0){
        NC8 X60Qx_222 = cur_0_lex3r1urc1((&(*lx_14)));
        X60Qx_221 = (!(X60Qx_222 == (NC8)'`'));}
      else {
        X60Qx_221 = NIM_FALSE;}
      if (X60Qx_221){
        NC8 X60Qx_223 = cur_0_lex3r1urc1((&(*lx_14)));
        X60Qx_220 = (!(X60Qx_223 == (NC8)'\012'));}
      else {
        X60Qx_220 = NIM_FALSE;}
      if (X60Qx_220){
        NC8 c_11 = cur_0_lex3r1urc1((&(*lx_14)));
        NB8 X60Qx_224;
        if (c_11 == (NC8)' '){
          X60Qx_224 = NIM_TRUE;}
        else {
          X60Qx_224 = (c_11 == (NC8)'\011');}
        if (X60Qx_224){
          advance_0_lex3r1urc1(lx_14);}
        else {
          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_12 = QQuoteMergeChars_0_lex3r1urc1;
          NU64 X60Qdesugar_13 = ((NU)c_11);
          if (((NU8)(X60Qdesugar_12.a[((NU)(X60Qdesugar_13 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_13 & 7ull)))))) != 0ull){
            add_0_I8kd4i4_lex3r1urc1((&partCols_0), (*lx_14).col_0);
            string_0_sysvq0asl run_0 = (string_0_sysvq0asl){
              .bytes_0 = 0ull, .more_0 = NIM_NIL}
            ;
            {
              while (NIM_TRUE){
                NB8 X60Qx_6;
                if ((*lx_14).pos_0 < (*lx_14).n_0){
                  X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_14 = QQuoteMergeChars_0_lex3r1urc1;
                  NC8 X60Qx_225 = cur_0_lex3r1urc1((&(*lx_14)));
                  NU64 X60Qdesugar_15 = ((NU)X60Qx_225);
                  X60Qx_6 = (((NU8)(X60Qdesugar_14.a[((NU)(X60Qdesugar_15 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_15 & 7ull)))))) != 0ull);}
                else {
                  X60Qx_6 = NIM_FALSE;}
                if (X60Qx_6){
                  NC8 X60Qx_226 = cur_0_lex3r1urc1((&(*lx_14)));
                  add_1_sysvq0asl((&run_0), X60Qx_226);
                  NC8 X60Qx_227 = cur_0_lex3r1urc1((&(*lx_14)));
                  add_1_sysvq0asl((&s_11), X60Qx_227);
                  advance_0_lex3r1urc1(lx_14);}
                else {
                  break;}}}
            whileStmtLabel_1: ;
            string_0_sysvq0asl X60Qtmp_12 = run_0;
            nimStrWasMoved((&run_0));
            add_0_Ig6072n_aif7a4qfr((&parts_0), X60Qtmp_12);
            nimStrDestroy(run_0);}
          else {
            NB8 X60Qx_228;
            NB8 X60Qx_229 = isIdentStart_0_lex3r1urc1(c_11);
            if (X60Qx_229){
              X60Qx_228 = NIM_TRUE;}
            else {
              NB8 X60Qx_230 = isDigit_0_lex3r1urc1(c_11);
              X60Qx_228 = X60Qx_230;}
            if (X60Qx_228){
              add_0_I8kd4i4_lex3r1urc1((&partCols_0), (*lx_14).col_0);
              string_0_sysvq0asl word_0 = (string_0_sysvq0asl){
                .bytes_0 = 0ull, .more_0 = NIM_NIL}
              ;
              {
                while (NIM_TRUE){
                  NB8 X60Qx_231;
                  if ((*lx_14).pos_0 < (*lx_14).n_0){
                    NC8 X60Qx_232 = cur_0_lex3r1urc1((&(*lx_14)));
                    NB8 X60Qx_233 = isIdentCont_0_lex3r1urc1(X60Qx_232);
                    X60Qx_231 = X60Qx_233;}
                  else {
                    X60Qx_231 = NIM_FALSE;}
                  if (X60Qx_231){
                    NC8 X60Qx_234 = cur_0_lex3r1urc1((&(*lx_14)));
                    add_1_sysvq0asl((&word_0), X60Qx_234);
                    NC8 X60Qx_235 = cur_0_lex3r1urc1((&(*lx_14)));
                    add_1_sysvq0asl((&s_11), X60Qx_235);
                    advance_0_lex3r1urc1(lx_14);}
                  else {
                    break;}}}
              whileStmtLabel_2: ;
              string_0_sysvq0asl X60Qtmp_13 = word_0;
              nimStrWasMoved((&word_0));
              add_0_Ig6072n_aif7a4qfr((&parts_0), X60Qtmp_13);
              nimStrDestroy(word_0);}
            else {
              add_0_I8kd4i4_lex3r1urc1((&partCols_0), (*lx_14).col_0);
              string_0_sysvq0asl one_0 = (string_0_sysvq0asl){
                .bytes_0 = 0ull, .more_0 = NIM_NIL}
              ;
              add_1_sysvq0asl((&one_0), c_11);
              add_1_sysvq0asl((&s_11), c_11);
              advance_0_lex3r1urc1(lx_14);
              string_0_sysvq0asl X60Qtmp_14 = one_0;
              nimStrWasMoved((&one_0));
              add_0_Ig6072n_aif7a4qfr((&parts_0), X60Qtmp_14);
              nimStrDestroy(one_0);}}}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NC8 X60Qx_236 = cur_0_lex3r1urc1((&(*lx_14)));
  if (X60Qx_236 == (NC8)'`'){
    advance_0_lex3r1urc1(lx_14);}
  string_0_sysvq0asl* X60Qlhs_15 = (&result_25.s_0);
  nimStrDestroy((*X60Qlhs_15));
  (*X60Qlhs_15) = s_11;
  nimStrWasMoved((&s_11));
  seq_0_Ixdx2fh1_aif7a4qfr* X60Qlhs_16 = (&result_25.parts_0);
  eQdestroy_1_Ivioh0a_aif7a4qfr((*X60Qlhs_16));
  (*X60Qlhs_16) = parts_0;
  eQwasMoved_1_I5vdnla_aif7a4qfr((&parts_0));
  seq_0_Ift2sne_lex3r1urc1* X60Qlhs_17 = (&result_25.partCols_0);
  eQdestroy_1_Iv9ij5i1_lex3r1urc1((*X60Qlhs_17));
  (*X60Qlhs_17) = partCols_0;
  eQwasMoved_1_Ix88qzs1_lex3r1urc1((&partCols_0));
  eQdestroy_1_Iv9ij5i1_lex3r1urc1(partCols_0);
  eQdestroy_1_Ivioh0a_aif7a4qfr(parts_0);
  nimStrDestroy(s_11);
  return result_25;
  eQdestroy_1_Iv9ij5i1_lex3r1urc1(partCols_0);
  eQdestroy_1_Ivioh0a_aif7a4qfr(parts_0);
  nimStrDestroy(s_11);
  return result_25;}
void skipBlockComment_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_15){
  advance_0_lex3r1urc1(lx_15);
  advance_0_lex3r1urc1(lx_15);
  NI64 depth_0 = IL64(1);
  {
    while (NIM_TRUE){
      NB8 X60Qx_237;
      if ((*lx_15).pos_0 < (*lx_15).n_0){
        X60Qx_237 = (IL64(0) < depth_0);}
      else {
        X60Qx_237 = NIM_FALSE;}
      if (X60Qx_237){
        NB8 X60Qx_238;
        NC8 X60Qx_239 = cur_0_lex3r1urc1((&(*lx_15)));
        if (X60Qx_239 == (NC8)'#'){
          NC8 X60Qx_240 = peek_0_lex3r1urc1((&(*lx_15)), IL64(1));
          X60Qx_238 = (X60Qx_240 == (NC8)'[');}
        else {
          X60Qx_238 = NIM_FALSE;}
        if (X60Qx_238){
          advance_0_lex3r1urc1(lx_15);
          advance_0_lex3r1urc1(lx_15);
          inc_1_Irn1g7r1_aif7a4qfr((&depth_0));}
        else {
          NB8 X60Qx_241;
          NC8 X60Qx_242 = cur_0_lex3r1urc1((&(*lx_15)));
          if (X60Qx_242 == (NC8)']'){
            NC8 X60Qx_243 = peek_0_lex3r1urc1((&(*lx_15)), IL64(1));
            X60Qx_241 = (X60Qx_243 == (NC8)'#');}
          else {
            X60Qx_241 = NIM_FALSE;}
          if (X60Qx_241){
            advance_0_lex3r1urc1(lx_15);
            advance_0_lex3r1urc1(lx_15);
            dec_1_I2mwrey1_envto7w6l1((&depth_0));}
          else {
            advance_0_lex3r1urc1(lx_15);}}}
      else {
        break;}}}
  whileStmtLabel_0: ;}
void skipDocBlockComment_0_lex3r1urc1(Lexer_0_lex3r1urc1* lx_16){
  advance_0_lex3r1urc1(lx_16);
  advance_0_lex3r1urc1(lx_16);
  advance_0_lex3r1urc1(lx_16);
  NI64 depth_1 = IL64(1);
  {
    while (NIM_TRUE){
      NB8 X60Qx_244;
      if ((*lx_16).pos_0 < (*lx_16).n_0){
        X60Qx_244 = (IL64(0) < depth_1);}
      else {
        X60Qx_244 = NIM_FALSE;}
      if (X60Qx_244){
        NB8 X60Qx_245;
        NB8 X60Qx_246;
        NC8 X60Qx_247 = cur_0_lex3r1urc1((&(*lx_16)));
        if (X60Qx_247 == (NC8)'#'){
          NC8 X60Qx_248 = peek_0_lex3r1urc1((&(*lx_16)), IL64(1));
          X60Qx_246 = (X60Qx_248 == (NC8)'#');}
        else {
          X60Qx_246 = NIM_FALSE;}
        if (X60Qx_246){
          NC8 X60Qx_249 = peek_0_lex3r1urc1((&(*lx_16)), IL64(2));
          X60Qx_245 = (X60Qx_249 == (NC8)'[');}
        else {
          X60Qx_245 = NIM_FALSE;}
        if (X60Qx_245){
          advance_0_lex3r1urc1(lx_16);
          advance_0_lex3r1urc1(lx_16);
          advance_0_lex3r1urc1(lx_16);
          inc_1_Irn1g7r1_aif7a4qfr((&depth_1));}
        else {
          NB8 X60Qx_250;
          NB8 X60Qx_251;
          NC8 X60Qx_252 = cur_0_lex3r1urc1((&(*lx_16)));
          if (X60Qx_252 == (NC8)']'){
            NC8 X60Qx_253 = peek_0_lex3r1urc1((&(*lx_16)), IL64(1));
            X60Qx_251 = (X60Qx_253 == (NC8)'#');}
          else {
            X60Qx_251 = NIM_FALSE;}
          if (X60Qx_251){
            NC8 X60Qx_254 = peek_0_lex3r1urc1((&(*lx_16)), IL64(2));
            X60Qx_250 = (X60Qx_254 == (NC8)'#');}
          else {
            X60Qx_250 = NIM_FALSE;}
          if (X60Qx_250){
            advance_0_lex3r1urc1(lx_16);
            advance_0_lex3r1urc1(lx_16);
            advance_0_lex3r1urc1(lx_16);
            dec_1_I2mwrey1_envto7w6l1((&depth_1));}
          else {
            advance_0_lex3r1urc1(lx_16);}}}
      else {
        break;}}}
  whileStmtLabel_0: ;}
seq_0_Iyai4gn_lex3r1urc1 tokenize_1_lex3r1urc1(string_0_sysvq0asl src_2, LexOptions_0_lex3r1urc1* opts_1, NI64* errors_0){
  seq_0_Iyai4gn_lex3r1urc1 result_26;
  eQwasMoved_1_I4bu01z_lex3r1urc1((&result_26));
  Lexer_0_lex3r1urc1 lx_17 = initLexer_0_lex3r1urc1(src_2, (&(*opts_1)));
  eQdestroy_1_Ie8xo6a1_lex3r1urc1(result_26);
  seq_0_Iyai4gn_lex3r1urc1 X60Qx_255 = newSeqUninit_0_I28kyaw1_lex3r1urc1(IL64(0));
  result_26 = X60Qx_255;
  NB8 X60Qx_256;
  NB8 X60Qx_257;
  NB8 X60Qx_258;
  NB8 X60Qx_259;
  if ((!(lx_17.opts_0.bomPolicy_0 == IL64(0)))){
    X60Qx_259 = (IL64(3) <= lx_17.n_0);}
  else {
    X60Qx_259 = NIM_FALSE;}
  if (X60Qx_259){
    NC8 X60Qx_260 = getQ_9_sysvq0asl(src_2, IL64(0));
    X60Qx_258 = (X60Qx_260 == (NC8)'\357');}
  else {
    X60Qx_258 = NIM_FALSE;}
  if (X60Qx_258){
    NC8 X60Qx_261 = getQ_9_sysvq0asl(src_2, IL64(1));
    X60Qx_257 = (X60Qx_261 == (NC8)'\273');}
  else {
    X60Qx_257 = NIM_FALSE;}
  if (X60Qx_257){
    NC8 X60Qx_262 = getQ_9_sysvq0asl(src_2, IL64(2));
    X60Qx_256 = (X60Qx_262 == (NC8)'\277');}
  else {
    X60Qx_256 = NIM_FALSE;}
  if (X60Qx_256){
    if (lx_17.opts_0.bomPolicy_0 == IL64(2)){
      add_0_Ikpo3qe_lex3r1urc1((&lx_17.diags_0), (Diagnostic_0_tok9e79hf){
        .severity_0 = IL64(2), .code_0 = (string_0_sysvq0asl){
          .bytes_0 = 7666659480103248638ull, .more_0 = (&strlit_0_I16765148769446371680_lex3r1urc1)}
        , .message_0 = (string_0_sysvq0asl){
          .bytes_0 = 7453010313196432638ull, .more_0 = (&strlit_0_I3289740197006093898_lex3r1urc1)}
        , .line_0 = ((NI32)IL64(1)), .col_0 = ((NI32)IL64(0)), .endCol_0 = ((NI32)IL64(0))}
      );
      if (IL64(2) == IL64(2)){
        inc_1_Irn1g7r1_aif7a4qfr((&lx_17.errors_0));}}
    lx_17.pos_0 = IL64(3);}
  {
    while (lx_17.pos_0 < lx_17.n_0){
      NI64 before_0 = len_3_Iefkljt1_lex3r1urc1(result_26);
      NC8 c_12 = cur_0_lex3r1urc1((&lx_17));
      NB8 X60Qx_263;
      NB8 X60Qx_264;
      if (c_12 == (NC8)' '){
        X60Qx_264 = NIM_TRUE;}
      else {
        X60Qx_264 = (c_12 == (NC8)'\011');}
      if (X60Qx_264){
        X60Qx_263 = NIM_TRUE;}
      else {
        X60Qx_263 = (c_12 == (NC8)'\015');}
      if (X60Qx_263){
        NB8 X60Qx_265;
        NB8 X60Qx_266;
        if (lx_17.atLineStart_0){
          X60Qx_266 = (lx_17.opts_0.tabPolicy_0 == IL64(2));}
        else {
          X60Qx_266 = NIM_FALSE;}
        if (X60Qx_266){
          X60Qx_265 = (!(c_12 == (NC8)'\015'));}
        else {
          X60Qx_265 = NIM_FALSE;}
        if (X60Qx_265){
          if (c_12 == (NC8)' '){
            lx_17.sawSpaceInIndent_0 = NIM_TRUE;}
          else {
            if (c_12 == (NC8)'\011'){
              lx_17.sawTabInIndent_0 = NIM_TRUE;}}
          NB8 X60Qx_267;
          NB8 X60Qx_268;
          if (lx_17.sawSpaceInIndent_0){
            X60Qx_268 = lx_17.sawTabInIndent_0;}
          else {
            X60Qx_268 = NIM_FALSE;}
          if (X60Qx_268){
            X60Qx_267 = (!lx_17.warnedMixThisLine_0);}
          else {
            X60Qx_267 = NIM_FALSE;}
          if (X60Qx_267){
            add_0_Ikpo3qe_lex3r1urc1((&lx_17.diags_0), (Diagnostic_0_tok9e79hf){
              .severity_0 = IL64(1), .code_0 = (string_0_sysvq0asl){
                .bytes_0 = 7578824134909062654ull, .more_0 = (&strlit_0_I9812626919684199076_lex3r1urc1)}
              , .message_0 = (string_0_sysvq0asl){
                .bytes_0 = 7022359100733155838ull, .more_0 = (&strlit_0_I2041765918324268108_lex3r1urc1)}
              , .line_0 = lx_17.line_0, .col_0 = ((NI32)IL64(0)), .endCol_0 = lx_17.col_0}
            );
            if (IL64(1) == IL64(2)){
              inc_1_Irn1g7r1_aif7a4qfr((&lx_17.errors_0));}
            lx_17.warnedMixThisLine_0 = NIM_TRUE;}}
        advance_0_lex3r1urc1((&lx_17));}
      else {
        if (c_12 == (NC8)'\012'){
          NB8 X60Qx_269;
          if ((!(lx_17.opts_0.newlinePolicy_0 == IL64(0)))){
            X60Qx_269 = NIM_TRUE;}
          else {
            X60Qx_269 = lx_17.opts_0.trailingWhitespaceWarn_0;}
          if (X60Qx_269){
            NB8 X60Qx_270;
            if (IL64(0) < lx_17.pos_0){
              NC8 X60Qx_271 = getQ_9_sysvq0asl(lx_17.src_0, ((NI64)(lx_17.pos_0 - IL64(1))));
              X60Qx_270 = (X60Qx_271 == (NC8)'\015');}
            else {
              X60Qx_270 = NIM_FALSE;}
            NB8 isCrlf_0 = X60Qx_270;
            NB8 X60Qx_272;
            if (lx_17.opts_0.newlinePolicy_0 == IL64(1)){
              X60Qx_272 = isCrlf_0;}
            else {
              X60Qx_272 = NIM_FALSE;}
            if (X60Qx_272){
              add_0_Ikpo3qe_lex3r1urc1((&lx_17.diags_0), (Diagnostic_0_tok9e79hf){
                .severity_0 = IL64(1), .code_0 = (string_0_sysvq0asl){
                  .bytes_0 = 7954814230487198974ull, .more_0 = (&strlit_0_I1365890887990331020_lex3r1urc1)}
                , .message_0 = (string_0_sysvq0asl){
                  .bytes_0 = 7954799936836037886ull, .more_0 = (&strlit_0_I15073253361476384615_lex3r1urc1)}
                , .line_0 = lx_17.line_0, .col_0 = lx_17.col_0, .endCol_0 = lx_17.col_0}
              );
              if (IL64(1) == IL64(2)){
                inc_1_Irn1g7r1_aif7a4qfr((&lx_17.errors_0));}}
            else {
              NB8 X60Qx_273;
              if (lx_17.opts_0.newlinePolicy_0 == IL64(2)){
                X60Qx_273 = (!isCrlf_0);}
              else {
                X60Qx_273 = NIM_FALSE;}
              if (X60Qx_273){
                add_0_Ikpo3qe_lex3r1urc1((&lx_17.diags_0), (Diagnostic_0_tok9e79hf){
                  .severity_0 = IL64(1), .code_0 = (string_0_sysvq0asl){
                    .bytes_0 = 7954814230487198974ull, .more_0 = (&strlit_0_I1365890887990331020_lex3r1urc1)}
                  , .message_0 = (string_0_sysvq0asl){
                    .bytes_0 = 7954799936836037886ull, .more_0 = (&strlit_0_I3525481182892397244_lex3r1urc1)}
                  , .line_0 = lx_17.line_0, .col_0 = lx_17.col_0, .endCol_0 = lx_17.col_0}
                );
                if (IL64(1) == IL64(2)){
                  inc_1_Irn1g7r1_aif7a4qfr((&lx_17.errors_0));}}}
            if (lx_17.opts_0.trailingWhitespaceWarn_0){
              NI64 j_0 = ((NI64)(lx_17.pos_0 - IL64(1)));
              NB8 X60Qx_274;
              if (IL64(0) <= j_0){
                NC8 X60Qx_275 = getQ_9_sysvq0asl(lx_17.src_0, j_0);
                X60Qx_274 = (X60Qx_275 == (NC8)'\015');}
              else {
                X60Qx_274 = NIM_FALSE;}
              if (X60Qx_274){
                dec_1_I2mwrey1_envto7w6l1((&j_0));}
              NB8 X60Qx_276;
              if (IL64(0) <= j_0){
                NB8 X60Qx_277;
                NC8 X60Qx_278 = getQ_9_sysvq0asl(lx_17.src_0, j_0);
                if (X60Qx_278 == (NC8)' '){
                  X60Qx_277 = NIM_TRUE;}
                else {
                  NC8 X60Qx_279 = getQ_9_sysvq0asl(lx_17.src_0, j_0);
                  X60Qx_277 = (X60Qx_279 == (NC8)'\011');}
                X60Qx_276 = X60Qx_277;}
              else {
                X60Qx_276 = NIM_FALSE;}
              if (X60Qx_276){
                add_0_Ikpo3qe_lex3r1urc1((&lx_17.diags_0), (Diagnostic_0_tok9e79hf){
                  .severity_0 = IL64(1), .code_0 = (string_0_sysvq0asl){
                    .bytes_0 = 7956009416588948734ull, .more_0 = (&strlit_0_I3814179386273276921_lex3r1urc1)}
                  , .message_0 = (string_0_sysvq0asl){
                    .bytes_0 = 7956009416588948734ull, .more_0 = (&strlit_0_I18387374889788949454_lex3r1urc1)}
                  , .line_0 = lx_17.line_0, .col_0 = lx_17.col_0, .endCol_0 = lx_17.col_0}
                );
                if (IL64(1) == IL64(2)){
                  inc_1_Irn1g7r1_aif7a4qfr((&lx_17.errors_0));}}}}
          advance_0_lex3r1urc1((&lx_17));}
        else {
          if (c_12 == (NC8)'#'){
            NC8 X60Qx_280 = peek_0_lex3r1urc1((&lx_17), IL64(1));
            if (X60Qx_280 == (NC8)'['){
              skipBlockComment_0_lex3r1urc1((&lx_17));}
            else {
              NB8 X60Qx_281;
              NC8 X60Qx_282 = peek_0_lex3r1urc1((&lx_17), IL64(1));
              if (X60Qx_282 == (NC8)'#'){
                NC8 X60Qx_283 = peek_0_lex3r1urc1((&lx_17), IL64(2));
                X60Qx_281 = (X60Qx_283 == (NC8)'[');}
              else {
                X60Qx_281 = NIM_FALSE;}
              if (X60Qx_281){
                NB8 standalone_0 = lx_17.atLineStart_0;
                Token_0_tok9e79hf t_0 = startToken_0_lex3r1urc1((&lx_17), IL64(20));
                skipDocBlockComment_0_lex3r1urc1((&lx_17));
                lx_17.atLineStart_0 = NIM_FALSE;
                NB8 X60Qx_284;
                if (standalone_0){
                  X60Qx_284 = lx_17.opts_0.docComments_0;}
                else {
                  X60Qx_284 = NIM_FALSE;}
                if (X60Qx_284){
                  Token_0_tok9e79hf X60Qtmp_18 = t_0;
                  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_0));
                  add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_18);}
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_0));}
              else {
                NC8 X60Qx_285 = peek_0_lex3r1urc1((&lx_17), IL64(1));
                if (X60Qx_285 == (NC8)'#'){
                  NB8 standalone_1 = lx_17.atLineStart_0;
                  Token_0_tok9e79hf t_1 = startToken_0_lex3r1urc1((&lx_17), IL64(20));
                  {
                    while (NIM_TRUE){
                      {
                        while (NIM_TRUE){
                          NB8 X60Qx_286;
                          if (lx_17.pos_0 < lx_17.n_0){
                            NC8 X60Qx_287 = cur_0_lex3r1urc1((&lx_17));
                            X60Qx_286 = (!(X60Qx_287 == (NC8)'\012'));}
                          else {
                            X60Qx_286 = NIM_FALSE;}
                          if (X60Qx_286){
                            advance_0_lex3r1urc1((&lx_17));}
                          else {
                            break;}}}
                      whileStmtLabel_2: ;
                      NC8 X60Qx_288 = cur_0_lex3r1urc1((&lx_17));
                      if ((!(X60Qx_288 == (NC8)'\012'))){
                        goto whileStmtLabel_1;}
                      NI64 k_3 = IL64(1);
                      {
                        while (NIM_TRUE){
                          NB8 X60Qx_289;
                          NC8 X60Qx_290 = peek_0_lex3r1urc1((&lx_17), k_3);
                          if (X60Qx_290 == (NC8)' '){
                            X60Qx_289 = NIM_TRUE;}
                          else {
                            NC8 X60Qx_291 = peek_0_lex3r1urc1((&lx_17), k_3);
                            X60Qx_289 = (X60Qx_291 == (NC8)'\011');}
                          if (X60Qx_289){
                            inc_1_Irn1g7r1_aif7a4qfr((&k_3));}
                          else {
                            break;}}}
                      whileStmtLabel_3: ;
                      NB8 X60Qx_292;
                      NC8 X60Qx_293 = peek_0_lex3r1urc1((&lx_17), k_3);
                      if (X60Qx_293 == (NC8)'#'){
                        NC8 X60Qx_294 = peek_0_lex3r1urc1((&lx_17), ((NI64)(k_3 + IL64(1))));
                        X60Qx_292 = (X60Qx_294 == (NC8)'#');}
                      else {
                        X60Qx_292 = NIM_FALSE;}
                      if (X60Qx_292){
                        {
                          while (IL64(0) < k_3){
                            advance_0_lex3r1urc1((&lx_17));
                            dec_1_I2mwrey1_envto7w6l1((&k_3));}}
                        whileStmtLabel_4: ;}
                      else {
                        goto whileStmtLabel_1;}}}
                  whileStmtLabel_1: ;
                  lx_17.atLineStart_0 = NIM_FALSE;
                  NB8 X60Qx_295;
                  if (standalone_1){
                    X60Qx_295 = lx_17.opts_0.docComments_0;}
                  else {
                    X60Qx_295 = NIM_FALSE;}
                  if (X60Qx_295){
                    Token_0_tok9e79hf X60Qtmp_19 = t_1;
                    eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_1));
                    add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_19);}
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_1));}
                else {
                  {
                    while (NIM_TRUE){
                      NB8 X60Qx_296;
                      if (lx_17.pos_0 < lx_17.n_0){
                        NC8 X60Qx_297 = cur_0_lex3r1urc1((&lx_17));
                        X60Qx_296 = (!(X60Qx_297 == (NC8)'\012'));}
                      else {
                        X60Qx_296 = NIM_FALSE;}
                      if (X60Qx_296){
                        advance_0_lex3r1urc1((&lx_17));}
                      else {
                        break;}}}
                  whileStmtLabel_5: ;}}}}
          else {
            if (c_12 == (NC8)'\"'){
              Token_0_tok9e79hf t_2 = lexString_0_lex3r1urc1((&lx_17));
              lx_17.atLineStart_0 = NIM_FALSE;
              Token_0_tok9e79hf X60Qtmp_20 = t_2;
              eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_2));
              add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_20);
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_2));}
            else {
              NB8 X60Qx_298;
              NB8 X60Qx_299;
              if (c_12 == (NC8)'r'){
                X60Qx_299 = NIM_TRUE;}
              else {
                X60Qx_299 = (c_12 == (NC8)'R');}
              if (X60Qx_299){
                NC8 X60Qx_300 = peek_0_lex3r1urc1((&lx_17), IL64(1));
                X60Qx_298 = (X60Qx_300 == (NC8)'\"');}
              else {
                X60Qx_298 = NIM_FALSE;}
              if (X60Qx_298){
                Token_0_tok9e79hf t_3 = lexRawOrTriple_0_lex3r1urc1((&lx_17));
                lx_17.atLineStart_0 = NIM_FALSE;
                Token_0_tok9e79hf X60Qtmp_21 = t_3;
                eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_3));
                add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_21);
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_3));}
              else {
                if (c_12 == (NC8)'\''){
                  Token_0_tok9e79hf t_4 = lexChar_0_lex3r1urc1((&lx_17));
                  lx_17.atLineStart_0 = NIM_FALSE;
                  Token_0_tok9e79hf X60Qtmp_22 = t_4;
                  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_4));
                  add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_22);
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_4));}
                else {
                  if (c_12 == (NC8)'`'){
                    Token_0_tok9e79hf t_5 = lexBackquotedIdent_0_lex3r1urc1((&lx_17));
                    lx_17.atLineStart_0 = NIM_FALSE;
                    Token_0_tok9e79hf X60Qtmp_23 = t_5;
                    eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_5));
                    add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_23);
                    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_5));}
                  else {
                    NB8 X60Qx_301 = isDigit_0_lex3r1urc1(c_12);
                    if (X60Qx_301){
                      Token_0_tok9e79hf t_6 = lexNumber_0_lex3r1urc1((&lx_17));
                      lx_17.atLineStart_0 = NIM_FALSE;
                      Token_0_tok9e79hf X60Qtmp_24 = t_6;
                      eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_6));
                      add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_24);
                      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_6));}
                    else {
                      NB8 X60Qx_302 = isIdentStart_0_lex3r1urc1(c_12);
                      if (X60Qx_302){
                        Token_0_tok9e79hf t_7 = lexIdent_0_lex3r1urc1((&lx_17));
                        lx_17.atLineStart_0 = NIM_FALSE;
                        Token_0_tok9e79hf X60Qtmp_25 = t_7;
                        eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_7));
                        add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_25);
                        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_7));}
                      else {
                        if (c_12 == (NC8)'('){
                          Token_0_tok9e79hf t_8 = startToken_0_lex3r1urc1((&lx_17), IL64(10));
                          lx_17.atLineStart_0 = NIM_FALSE;
                          advance_0_lex3r1urc1((&lx_17));
                          Token_0_tok9e79hf X60Qtmp_26 = t_8;
                          eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_8));
                          add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_26);
                          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_8));}
                        else {
                          if (c_12 == (NC8)')'){
                            Token_0_tok9e79hf t_9 = startToken_0_lex3r1urc1((&lx_17), IL64(11));
                            lx_17.atLineStart_0 = NIM_FALSE;
                            advance_0_lex3r1urc1((&lx_17));
                            Token_0_tok9e79hf X60Qtmp_27 = t_9;
                            eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_9));
                            add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_27);
                            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_9));}
                          else {
                            if (c_12 == (NC8)'['){
                              Token_0_tok9e79hf t_10 = startToken_0_lex3r1urc1((&lx_17), IL64(12));
                              lx_17.atLineStart_0 = NIM_FALSE;
                              advance_0_lex3r1urc1((&lx_17));
                              Token_0_tok9e79hf X60Qtmp_28 = t_10;
                              eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_10));
                              add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_28);
                              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_10));}
                            else {
                              if (c_12 == (NC8)']'){
                                Token_0_tok9e79hf t_11 = startToken_0_lex3r1urc1((&lx_17), IL64(13));
                                lx_17.atLineStart_0 = NIM_FALSE;
                                advance_0_lex3r1urc1((&lx_17));
                                Token_0_tok9e79hf X60Qtmp_29 = t_11;
                                eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_11));
                                add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_29);
                                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_11));}
                              else {
                                if (c_12 == (NC8)'{'){
                                  Token_0_tok9e79hf t_12 = startToken_0_lex3r1urc1((&lx_17), IL64(14));
                                  lx_17.atLineStart_0 = NIM_FALSE;
                                  advance_0_lex3r1urc1((&lx_17));
                                  Token_0_tok9e79hf X60Qtmp_30 = t_12;
                                  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_12));
                                  add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_30);
                                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_12));}
                                else {
                                  if (c_12 == (NC8)'}'){
                                    Token_0_tok9e79hf t_13 = startToken_0_lex3r1urc1((&lx_17), IL64(15));
                                    lx_17.atLineStart_0 = NIM_FALSE;
                                    advance_0_lex3r1urc1((&lx_17));
                                    Token_0_tok9e79hf X60Qtmp_31 = t_13;
                                    eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_13));
                                    add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_31);
                                    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_13));}
                                  else {
                                    if (c_12 == (NC8)','){
                                      Token_0_tok9e79hf t_14 = startToken_0_lex3r1urc1((&lx_17), IL64(16));
                                      lx_17.atLineStart_0 = NIM_FALSE;
                                      advance_0_lex3r1urc1((&lx_17));
                                      Token_0_tok9e79hf X60Qtmp_32 = t_14;
                                      eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_14));
                                      add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_32);
                                      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_14));}
                                    else {
                                      if (c_12 == (NC8)';'){
                                        Token_0_tok9e79hf t_15 = startToken_0_lex3r1urc1((&lx_17), IL64(17));
                                        lx_17.atLineStart_0 = NIM_FALSE;
                                        advance_0_lex3r1urc1((&lx_17));
                                        Token_0_tok9e79hf X60Qtmp_33 = t_15;
                                        eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_15));
                                        add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_33);
                                        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_15));}
                                      else {
                                        NB8 X60Qx_7;
                                        if (c_12 == (NC8)':'){
                                          X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_16 = OperatorChars_0_lex3r1urc1;
                                          NC8 X60Qx_303 = peek_0_lex3r1urc1((&lx_17), IL64(1));
                                          NU64 X60Qdesugar_17 = ((NU)X60Qx_303);
                                          X60Qx_7 = (!(((NU8)(X60Qdesugar_16.a[((NU)(X60Qdesugar_17 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_17 & 7ull)))))) != 0ull));}
                                        else {
                                          X60Qx_7 = NIM_FALSE;}
                                        if (X60Qx_7){
                                          Token_0_tok9e79hf t_16 = startToken_0_lex3r1urc1((&lx_17), IL64(18));
                                          lx_17.atLineStart_0 = NIM_FALSE;
                                          advance_0_lex3r1urc1((&lx_17));
                                          Token_0_tok9e79hf X60Qtmp_34 = t_16;
                                          eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
                                          add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_34);
                                          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));}
                                        else {
                                          NB8 X60Qx_8;
                                          NB8 X60Qx_9;
                                          if (c_12 == (NC8)'.'){
                                            X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_18 = OperatorChars_0_lex3r1urc1;
                                            NC8 X60Qx_304 = peek_0_lex3r1urc1((&lx_17), IL64(1));
                                            NU64 X60Qdesugar_19 = ((NU)X60Qx_304);
                                            X60Qx_9 = (!(((NU8)(X60Qdesugar_18.a[((NU)(X60Qdesugar_19 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_19 & 7ull)))))) != 0ull));}
                                          else {
                                            X60Qx_9 = NIM_FALSE;}
                                          if (X60Qx_9){
                                            NC8 X60Qx_305 = peek_0_lex3r1urc1((&lx_17), IL64(1));
                                            NB8 X60Qx_306 = isDigit_0_lex3r1urc1(X60Qx_305);
                                            X60Qx_8 = (!X60Qx_306);}
                                          else {
                                            X60Qx_8 = NIM_FALSE;}
                                          if (X60Qx_8){
                                            Token_0_tok9e79hf t_17 = startToken_0_lex3r1urc1((&lx_17), IL64(19));
                                            lx_17.atLineStart_0 = NIM_FALSE;
                                            advance_0_lex3r1urc1((&lx_17));
                                            Token_0_tok9e79hf X60Qtmp_35 = t_17;
                                            eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_17));
                                            add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_35);
                                            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_17));}
                                          else {
                                            NB8 X60Qx_10;
                                            NB8 X60Qx_307;
                                            if (c_12 == (NC8)'*'){
                                              NC8 X60Qx_308 = peek_0_lex3r1urc1((&lx_17), IL64(1));
                                              X60Qx_307 = (X60Qx_308 == (NC8)':');}
                                            else {
                                              X60Qx_307 = NIM_FALSE;}
                                            if (X60Qx_307){
                                              X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_20 = OperatorChars_0_lex3r1urc1;
                                              NC8 X60Qx_309 = peek_0_lex3r1urc1((&lx_17), IL64(2));
                                              NU64 X60Qdesugar_21 = ((NU)X60Qx_309);
                                              X60Qx_10 = (!(((NU8)(X60Qdesugar_20.a[((NU)(X60Qdesugar_21 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_21 & 7ull)))))) != 0ull));}
                                            else {
                                              X60Qx_10 = NIM_FALSE;}
                                            if (X60Qx_10){
                                              Token_0_tok9e79hf t_18 = startToken_0_lex3r1urc1((&lx_17), IL64(9));
                                              string_0_sysvq0asl* X60Qlhs_36 = (&t_18.s_0);
                                              nimStrDestroy((*X60Qlhs_36));
                                              (*X60Qlhs_36) = (string_0_sysvq0asl){
                                                .bytes_0 = 10753ull, .more_0 = NIM_NIL}
                                              ;
                                              advance_0_lex3r1urc1((&lx_17));
                                              lx_17.atLineStart_0 = NIM_FALSE;
                                              Token_0_tok9e79hf X60Qtmp_37 = t_18;
                                              eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_18));
                                              add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_37);
                                              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_18));}
                                            else {
                                              X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_22 = OperatorChars_0_lex3r1urc1;
                                              NU64 X60Qdesugar_23 = ((NU)c_12);
                                              if (((NU8)(X60Qdesugar_22.a[((NU)(X60Qdesugar_23 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_23 & 7ull)))))) != 0ull){
                                                Token_0_tok9e79hf t_19 = lexOperator_0_lex3r1urc1((&lx_17));
                                                lx_17.atLineStart_0 = NIM_FALSE;
                                                Token_0_tok9e79hf X60Qtmp_38 = t_19;
                                                eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_19));
                                                add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_38);
                                                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_19));}
                                              else {
                                                string_0_sysvq0asl X60Qdesugar_24 = toHex2_0_lex3r1urc1(((NU8)c_12));
                                                NI64 X60Qx_310 = len_4_sysvq0asl((string_0_sysvq0asl){
                                                  .bytes_0 = 7959953386440127998ull, .more_0 = (&strlit_0_I2073055120360076570_lex3r1urc1)}
                                                );
                                                NI64 X60Qx_311 = len_4_sysvq0asl(X60Qdesugar_24);
                                                NI64 X60Qx_312 = len_4_sysvq0asl((string_0_sysvq0asl){
                                                  .bytes_0 = 7309465793298899198ull, .more_0 = (&strlit_0_I14660181550455658176_lex3r1urc1)}
                                                );
                                                string_0_sysvq0asl X60Qdesugar_25 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_310 + X60Qx_311)) + X60Qx_312)));
                                                add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
                                                  .bytes_0 = 7959953386440127998ull, .more_0 = (&strlit_0_I2073055120360076570_lex3r1urc1)}
                                                );
                                                add_2_sysvq0asl((&X60Qdesugar_25), X60Qdesugar_24);
                                                add_2_sysvq0asl((&X60Qdesugar_25), (string_0_sysvq0asl){
                                                  .bytes_0 = 7309465793298899198ull, .more_0 = (&strlit_0_I14660181550455658176_lex3r1urc1)}
                                                );
                                                string_0_sysvq0asl X60Qtmp_39 = X60Qdesugar_25;
                                                nimStrWasMoved((&X60Qdesugar_25));
                                                add_0_Ikpo3qe_lex3r1urc1((&lx_17.diags_0), (Diagnostic_0_tok9e79hf){
                                                  .severity_0 = IL64(2), .code_0 = (string_0_sysvq0asl){
                                                    .bytes_0 = 7959953386440127998ull, .more_0 = (&strlit_0_I13586503514632046678_lex3r1urc1)}
                                                  , .message_0 = X60Qtmp_39, .line_0 = lx_17.line_0, .col_0 = lx_17.col_0, .endCol_0 = lx_17.col_0}
                                                );
                                                if (IL64(2) == IL64(2)){
                                                  inc_1_Irn1g7r1_aif7a4qfr((&lx_17.errors_0));}
                                                advance_0_lex3r1urc1((&lx_17));
                                                nimStrDestroy(X60Qdesugar_25);
                                                nimStrDestroy(X60Qdesugar_24);}}}}}}}}}}}}}}}}}}}}}
      if (before_0 < result_26.len_0){
        NI64 X60Qx_313 = len_3_Iefkljt1_lex3r1urc1(result_26);
        Token_0_tok9e79hf* X60Qx_314 = getQ_7_Ijq9cyk1_lex3r1urc1(result_26, ((NI64)(X60Qx_313 - IL64(1))));
        (*X60Qx_314).endCol_0 = lx_17.col_0;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_315;
  NB8 X60Qx_316;
  if (lx_17.opts_0.finalNewlineRequire_0){
    X60Qx_316 = (IL64(0) < lx_17.n_0);}
  else {
    X60Qx_316 = NIM_FALSE;}
  if (X60Qx_316){
    NC8 X60Qx_317 = getQ_9_sysvq0asl(src_2, ((NI64)(lx_17.n_0 - IL64(1))));
    X60Qx_315 = (!(X60Qx_317 == (NC8)'\012'));}
  else {
    X60Qx_315 = NIM_FALSE;}
  if (X60Qx_315){
    add_0_Ikpo3qe_lex3r1urc1((&lx_17.diags_0), (Diagnostic_0_tok9e79hf){
      .severity_0 = IL64(1), .code_0 = (string_0_sysvq0asl){
        .bytes_0 = 7453010377923194366ull, .more_0 = (&strlit_0_I1664332866290125980_lex3r1urc1)}
      , .message_0 = (string_0_sysvq0asl){
        .bytes_0 = 2334381325109130238ull, .more_0 = (&strlit_0_I5470147542548005821_lex3r1urc1)}
      , .line_0 = lx_17.line_0, .col_0 = lx_17.col_0, .endCol_0 = lx_17.col_0}
    );
    if (IL64(1) == IL64(2)){
      inc_1_Irn1g7r1_aif7a4qfr((&lx_17.errors_0));}}
  Token_0_tok9e79hf eof_0 = initToken_0_tok9e79hf(IL64(0), lx_17.line_0, lx_17.col_0);
  eof_0.indent_0 = ((NI32)IL64(0));
  Token_0_tok9e79hf X60Qtmp_40 = eof_0;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&eof_0));
  add_0_Icvfjtn_lex3r1urc1((&result_26), X60Qtmp_40);
  (*errors_0) = lx_17.errors_0;
  eQdestroy_1_I9g9z2g1_lex3r1urc1(gLexDiags_0_lex3r1urc1);
  gLexDiags_0_lex3r1urc1 = lx_17.diags_0;
  eQwasMoved_1_Ikj6j7q_lex3r1urc1((&lx_17.diags_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&eof_0));
  eQdestroyQ_SX4cexer0lex3r1urc1_0_lex3r1urc1((&lx_17));
  return result_26;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&eof_0));
  eQdestroyQ_SX4cexer0lex3r1urc1_0_lex3r1urc1((&lx_17));
  return result_26;}
seq_0_Iyai4gn_lex3r1urc1 tokenize_3_lex3r1urc1(string_0_sysvq0asl src_4){
  seq_0_Iyai4gn_lex3r1urc1 result_28;
  eQwasMoved_1_I4bu01z_lex3r1urc1((&result_28));
  NI64 errs_1 = IL64(0);
  eQdestroy_1_Ie8xo6a1_lex3r1urc1(result_28);
  seq_0_Iyai4gn_lex3r1urc1 X60Qx_319 = tokenize_1_lex3r1urc1(src_4, (&defaultLexOptions_0_lex3r1urc1), (&errs_1));
  result_28 = X60Qx_319;
  return result_28;}
static inline seq_0_I1z1mkd_lex3r1urc1 newSeqUninit_0_I90m2ee1_lex3r1urc1(NI64 size_4){
  seq_0_I1z1mkd_lex3r1urc1 result_29;
  if (size_4 == IL64(0)){
    result_29 = (seq_0_I1z1mkd_lex3r1urc1){
      .len_0 = size_4, .data_0 = NIM_NIL}
    ;}
  else {
    NI64 memSize_0 = memSizeInBytes_0_Igy60gp1_lex3r1urc1(size_4);
    void* X60Qx_320 = alloc_0_sysvq0asl(memSize_0);
    result_29 = (seq_0_I1z1mkd_lex3r1urc1){
      .len_0 = size_4, .data_0 = ((Diagnostic_0_tok9e79hf*)X60Qx_320)}
    ;
    if ((!(result_29.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_321 = (string_0_sysvq0asl){
        .bytes_0 = 8439857260806892798ull, .more_0 = (&strlit_0_I15750996627617194403_aif7a4qfr)}
      ;}
    else {
      result_29.len_0 = IL64(0);
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_29;}
static inline void inc_1_I6wjjge_lex3r1urc1(NI32* x_4){
  (*x_4) = ((NI32)((*x_4) + ((NI32)IL64(1))));}
static inline void inc_0_Iloplki_lex3r1urc1(NI32* x_5, NI32 y_1){
  (*x_5) = ((NI32)((*x_5) + y_1));}
static inline void add_0_Ikpo3qe_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1* s_17, Diagnostic_0_tok9e79hf elem_4){
  NI64 L_0 = (*s_17).len_0;
  NI64 X60Qx_322 = capInBytes_0_I2z6vh21_lex3r1urc1((*s_17));
  if (X60Qx_322 < ((NI64)(((NI64)(L_0 * sizeof(Diagnostic_0_tok9e79hf))) + sizeof(Diagnostic_0_tok9e79hf)))){
    NB8 X60Qx_323 = resize_0_I5waj38_lex3r1urc1(s_17, IL64(1));
    if ((!X60Qx_323)){
      eQdestroyQ_SX44iagnostic0tok9e79hf_0_tok9e79hf((&elem_4));
      return;}}
  inc_1_Irn1g7r1_aif7a4qfr((&(*s_17).len_0));
  (*s_17).data_0[L_0] = elem_4;}
static inline seq_0_Ift2sne_lex3r1urc1 newSeqUninit_0_Iggfvwp_lex3r1urc1(NI64 size_8){
  seq_0_Ift2sne_lex3r1urc1 result_31;
  if (size_8 == IL64(0)){
    result_31 = (seq_0_Ift2sne_lex3r1urc1){
      .len_0 = size_8, .data_0 = NIM_NIL}
    ;}
  else {
    NI64 memSize_2 = memSizeInBytes_0_Inv7kg3_lex3r1urc1(size_8);
    void* X60Qx_326 = alloc_0_sysvq0asl(memSize_2);
    result_31 = (seq_0_Ift2sne_lex3r1urc1){
      .len_0 = size_8, .data_0 = ((NI32*)X60Qx_326)}
    ;
    if ((!(result_31.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_327 = (string_0_sysvq0asl){
        .bytes_0 = 8439857260806892798ull, .more_0 = (&strlit_0_I15750996627617194403_aif7a4qfr)}
      ;}
    else {
      result_31.len_0 = IL64(0);
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_31;}
static inline void add_0_I8kd4i4_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1* s_19, NI32 elem_5){
  NI64 L_1 = (*s_19).len_0;
  NI64 X60Qx_328 = capInBytes_0_Iet286n_lex3r1urc1((*s_19));
  if (X60Qx_328 < ((NI64)(((NI64)(L_1 * sizeof(NI32))) + sizeof(NI32)))){
    NB8 X60Qx_329 = resize_0_I8l4tya_lex3r1urc1(s_19, IL64(1));
    if ((!X60Qx_329)){
      return;}}
  inc_1_Irn1g7r1_aif7a4qfr((&(*s_19).len_0));
  (*s_19).data_0[L_1] = elem_5;}
static inline seq_0_Iyai4gn_lex3r1urc1 newSeqUninit_0_I28kyaw1_lex3r1urc1(NI64 size_10){
  seq_0_Iyai4gn_lex3r1urc1 result_32;
  if (size_10 == IL64(0)){
    result_32 = (seq_0_Iyai4gn_lex3r1urc1){
      .len_0 = size_10, .data_0 = NIM_NIL}
    ;}
  else {
    NI64 memSize_3 = memSizeInBytes_0_Imlcc9c1_lex3r1urc1(size_10);
    void* X60Qx_332 = alloc_0_sysvq0asl(memSize_3);
    result_32 = (seq_0_Iyai4gn_lex3r1urc1){
      .len_0 = size_10, .data_0 = ((Token_0_tok9e79hf*)X60Qx_332)}
    ;
    if ((!(result_32.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_333 = (string_0_sysvq0asl){
        .bytes_0 = 8439857260806892798ull, .more_0 = (&strlit_0_I15750996627617194403_aif7a4qfr)}
      ;}
    else {
      result_32.len_0 = IL64(0);
      oomHandler_0_sysvq0asl(memSize_3);}}
  return result_32;}
static inline NI64 len_3_Iefkljt1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_23){
  NI64 result_33;
  result_33 = s_23.len_0;
  return result_33;}
static inline void add_0_Icvfjtn_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* s_24, Token_0_tok9e79hf elem_7){
  NI64 L_3 = (*s_24).len_0;
  NI64 X60Qx_334 = capInBytes_0_Iztvafh1_lex3r1urc1((*s_24));
  if (X60Qx_334 < ((NI64)(((NI64)(L_3 * sizeof(Token_0_tok9e79hf))) + sizeof(Token_0_tok9e79hf)))){
    NB8 X60Qx_335 = resize_0_Ijirql71_lex3r1urc1(s_24, IL64(1));
    if ((!X60Qx_335)){
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&elem_7));
      return;}}
  inc_1_Irn1g7r1_aif7a4qfr((&(*s_24).len_0));
  (*s_24).data_0[L_3] = elem_7;}
static inline Token_0_tok9e79hf* getQ_7_Ijq9cyk1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_26, NI64 i_3){
  NB8 X60Qx_336;
  if (i_3 < s_26.len_0){
    X60Qx_336 = (IL64(0) <= i_3);}
  else {
    X60Qx_336 = NIM_FALSE;}
  if ((!X60Qx_336)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14532204288076119502_aif7a4qfr)}
    );}
  Token_0_tok9e79hf* result_34;
  result_34 = (&s_26.data_0[i_3]);
  return result_34;}
static inline NI64 memSizeInBytes_0_Igy60gp1_lex3r1urc1(NI64 size_12){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI64 result_35;
  NI64 X60QconstRefTemp_0;
  if (__builtin_smulll_overflow(size_12, sizeof(Diagnostic_0_tok9e79hf), (long long int*)(&X60QconstRefTemp_0))){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_35 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_35 = ((NI64)IL64(9223372036854775807));}
  return result_35;}
static inline NI64 capInBytes_0_I2z6vh21_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1 s_27){
  NI64 result_36;
  NI64 X60Qx_11;
  if ((!(s_27.data_0 == NIM_NIL))){
    NI64 X60Qx_337 = allocatedSize_0_sysvq0asl(((void*)((void*)s_27.data_0)));
    X60Qx_11 = X60Qx_337;}
  else {
    X60Qx_11 = IL64(0);}
  result_36 = X60Qx_11;
  return result_36;}
NB8 resize_0_I5waj38_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1* dest_4, NI64 addedElements_4){
  NB8 result_37;
  NI64 X60Qx_338 = capInBytes_0_I2z6vh21_lex3r1urc1((*dest_4));
  NI64 oldCap_0 = ((NI64)(X60Qx_338 / sizeof(Diagnostic_0_tok9e79hf)));
  NI64 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_4);
  NI64 memSize_4 = memSizeInBytes_0_Igy60gp1_lex3r1urc1(newCap_0);
  void* X60Qx_339 = realloc_0_sysvq0asl(((void*)((void*)(*dest_4).data_0)), memSize_4);
  (*dest_4).data_0 = ((Diagnostic_0_tok9e79hf*)X60Qx_339);
  if ((*dest_4).data_0 == NIM_NIL){
    (*dest_4).len_0 = IL64(0);
    oomHandler_0_sysvq0asl(memSize_4);
    result_37 = NIM_FALSE;}
  else {
    result_37 = NIM_TRUE;}
  return result_37;}
static inline NI64 memSizeInBytes_0_Inv7kg3_lex3r1urc1(NI64 size_14){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI64 result_41;
  NI64 X60QconstRefTemp_0;
  if (__builtin_smulll_overflow(size_14, sizeof(NI32), (long long int*)(&X60QconstRefTemp_0))){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_41 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_41 = ((NI64)IL64(9223372036854775807));}
  return result_41;}
static inline NI64 capInBytes_0_Iet286n_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1 s_28){
  NI64 result_42;
  NI64 X60Qx_12;
  if ((!(s_28.data_0 == NIM_NIL))){
    NI64 X60Qx_341 = allocatedSize_0_sysvq0asl(((void*)((void*)s_28.data_0)));
    X60Qx_12 = X60Qx_341;}
  else {
    X60Qx_12 = IL64(0);}
  result_42 = X60Qx_12;
  return result_42;}
NB8 resize_0_I8l4tya_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1* dest_5, NI64 addedElements_5){
  NB8 result_43;
  NI64 X60Qx_342 = capInBytes_0_Iet286n_lex3r1urc1((*dest_5));
  NI64 oldCap_1 = ((NI64)(X60Qx_342 / sizeof(NI32)));
  NI64 newCap_1 = recalcCap_0_sysvq0asl(oldCap_1, addedElements_5);
  NI64 memSize_5 = memSizeInBytes_0_Inv7kg3_lex3r1urc1(newCap_1);
  void* X60Qx_343 = realloc_0_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_5);
  (*dest_5).data_0 = ((NI32*)X60Qx_343);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = IL64(0);
    oomHandler_0_sysvq0asl(memSize_5);
    result_43 = NIM_FALSE;}
  else {
    result_43 = NIM_TRUE;}
  return result_43;}
static inline NI64 memSizeInBytes_0_Imlcc9c1_lex3r1urc1(NI64 size_15){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI64 result_46;
  NI64 X60QconstRefTemp_0;
  if (__builtin_smulll_overflow(size_15, sizeof(Token_0_tok9e79hf), (long long int*)(&X60QconstRefTemp_0))){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_46 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_46 = ((NI64)IL64(9223372036854775807));}
  return result_46;}
static inline NI64 capInBytes_0_Iztvafh1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_30){
  NI64 result_47;
  NI64 X60Qx_14;
  if ((!(s_30.data_0 == NIM_NIL))){
    NI64 X60Qx_347 = allocatedSize_0_sysvq0asl(((void*)((void*)s_30.data_0)));
    X60Qx_14 = X60Qx_347;}
  else {
    X60Qx_14 = IL64(0);}
  result_47 = X60Qx_14;
  return result_47;}
NB8 resize_0_Ijirql71_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* dest_7, NI64 addedElements_7){
  NB8 result_48;
  NI64 X60Qx_348 = capInBytes_0_Iztvafh1_lex3r1urc1((*dest_7));
  NI64 oldCap_3 = ((NI64)(X60Qx_348 / sizeof(Token_0_tok9e79hf)));
  NI64 newCap_3 = recalcCap_0_sysvq0asl(oldCap_3, addedElements_7);
  NI64 memSize_7 = memSizeInBytes_0_Imlcc9c1_lex3r1urc1(newCap_3);
  void* X60Qx_349 = realloc_0_sysvq0asl(((void*)((void*)(*dest_7).data_0)), memSize_7);
  (*dest_7).data_0 = ((Token_0_tok9e79hf*)X60Qx_349);
  if ((*dest_7).data_0 == NIM_NIL){
    (*dest_7).len_0 = IL64(0);
    oomHandler_0_sysvq0asl(memSize_7);
    result_48 = NIM_FALSE;}
  else {
    result_48 = NIM_TRUE;}
  return result_48;}
void eQdestroy_1_I9g9z2g1_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1 s_39){
  if ((!(s_39.data_0 == NIM_NIL))){
    NI64 i_4 = IL64(0);
    {
      while (i_4 < s_39.len_0){
        eQdestroyQ_SX44iagnostic0tok9e79hf_0_tok9e79hf((&s_39.data_0[i_4]));
        inc_1_Irn1g7r1_aif7a4qfr((&i_4));}}
    whileStmtLabel_0: ;
    dealloc_0_sysvq0asl(((void*)((void*)s_39.data_0)));}}
static inline void eQwasMoved_1_Ikj6j7q_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1* s_40){
  (*s_40).len_0 = IL64(0);
  (*s_40).data_0 = NIM_NIL;}
seq_0_I1z1mkd_lex3r1urc1 eQdup_1_I7pydea_lex3r1urc1(seq_0_I1z1mkd_lex3r1urc1 a_8){
  seq_0_I1z1mkd_lex3r1urc1 result_49;
  seq_0_I1z1mkd_lex3r1urc1 X60Qx_350 = newSeqUninit_0_I90m2ee1_lex3r1urc1(a_8.len_0);
  result_49 = X60Qx_350;
  NI64 i_5 = IL64(0);
  {
    while (i_5 < a_8.len_0){
      Diagnostic_0_tok9e79hf X60Qx_351 = eQdupQ_SX44iagnostic0tok9e79hf_0_tok9e79hf((&a_8.data_0[i_5]));
      result_49.data_0[i_5] = X60Qx_351;
      inc_1_Irn1g7r1_aif7a4qfr((&i_5));}}
  whileStmtLabel_0: ;
  return result_49;}
void eQdestroy_1_Ie8xo6a1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_41){
  if ((!(s_41.data_0 == NIM_NIL))){
    NI64 i_8 = IL64(0);
    {
      while (i_8 < s_41.len_0){
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&s_41.data_0[i_8]));
        inc_1_Irn1g7r1_aif7a4qfr((&i_8));}}
    whileStmtLabel_0: ;
    dealloc_0_sysvq0asl(((void*)((void*)s_41.data_0)));}}
static inline void eQwasMoved_1_I4bu01z_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* s_42){
  (*s_42).len_0 = IL64(0);
  (*s_42).data_0 = NIM_NIL;}
seq_0_Iyai4gn_lex3r1urc1 eQdup_1_Ikdu5b_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 a_9){
  seq_0_Iyai4gn_lex3r1urc1 result_50;
  seq_0_Iyai4gn_lex3r1urc1 X60Qx_356 = newSeqUninit_0_I28kyaw1_lex3r1urc1(a_9.len_0);
  result_50 = X60Qx_356;
  NI64 i_9 = IL64(0);
  {
    while (i_9 < a_9.len_0){
      Token_0_tok9e79hf X60Qx_357 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&a_9.data_0[i_9]));
      result_50.data_0[i_9] = X60Qx_357;
      inc_1_Irn1g7r1_aif7a4qfr((&i_9));}}
  whileStmtLabel_0: ;
  return result_50;}
void eQdestroy_1_Iv9ij5i1_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1 s_45){
  if ((!(s_45.data_0 == NIM_NIL))){
    NI64 i_16 = IL64(0);
    {
      while (i_16 < s_45.len_0){
        inc_1_Irn1g7r1_aif7a4qfr((&i_16));}}
    whileStmtLabel_0: ;
    dealloc_0_sysvq0asl(((void*)((void*)s_45.data_0)));}}
static inline void eQwasMoved_1_Ix88qzs1_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1* s_46){
  (*s_46).len_0 = IL64(0);
  (*s_46).data_0 = NIM_NIL;}
seq_0_Ift2sne_lex3r1urc1 eQdup_1_Iplow11_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1 a_11){
  seq_0_Ift2sne_lex3r1urc1 result_52;
  seq_0_Ift2sne_lex3r1urc1 X60Qx_368 = newSeqUninit_0_Iggfvwp_lex3r1urc1(a_11.len_0);
  result_52 = X60Qx_368;
  NI64 i_17 = IL64(0);
  {
    while (i_17 < a_11.len_0){
      result_52.data_0[i_17] = a_11.data_0[i_17];
      inc_1_Irn1g7r1_aif7a4qfr((&i_17));}}
  whileStmtLabel_0: ;
  return result_52;}
void eQdestroyQ_SX4cexer0lex3r1urc1_0_lex3r1urc1(Lexer_0_lex3r1urc1* dest_0){
  eQdestroy_1_I9g9z2g1_lex3r1urc1((*dest_0).diags_0);
  nimStrDestroy((*dest_0).src_0);}
void eQwasmovedQ_SX4cexer0lex3r1urc1_0_lex3r1urc1(Lexer_0_lex3r1urc1* dest_0){
  nimStrWasMoved((&(*dest_0).src_0));
  eQwasMoved_1_Ikj6j7q_lex3r1urc1((&(*dest_0).diags_0));}
Lexer_0_lex3r1urc1 eQdupQ_SX4cexer0lex3r1urc1_0_lex3r1urc1(Lexer_0_lex3r1urc1* src_0){
  Lexer_0_lex3r1urc1 dest_0;
  string_0_sysvq0asl X60Qx_372 = nimStrDup((*src_0).src_0);
  dest_0.src_0 = X60Qx_372;
  dest_0.n_0 = (*src_0).n_0;
  dest_0.pos_0 = (*src_0).pos_0;
  dest_0.line_0 = (*src_0).line_0;
  dest_0.col_0 = (*src_0).col_0;
  dest_0.atLineStart_0 = (*src_0).atLineStart_0;
  dest_0.opts_0 = (*src_0).opts_0;
  dest_0.sawSpaceInIndent_0 = (*src_0).sawSpaceInIndent_0;
  dest_0.sawTabInIndent_0 = (*src_0).sawTabInIndent_0;
  dest_0.warnedMixThisLine_0 = (*src_0).warnedMixThisLine_0;
  dest_0.errors_0 = (*src_0).errors_0;
  dest_0.prevIndent_0 = (*src_0).prevIndent_0;
  dest_0.indentUnit_0 = (*src_0).indentUnit_0;
  seq_0_I1z1mkd_lex3r1urc1 X60Qx_373 = eQdup_1_I7pydea_lex3r1urc1((*src_0).diags_0);
  dest_0.diags_0 = X60Qx_373;
  return dest_0;}
void X60Qini_0_lex3r1urc1(void){
  if (X60QiniGuard_0_lex3r1urc1){
    return;}
  X60QiniGuard_0_lex3r1urc1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tok9e79hf();
  X60Qini_0_party5a2l1();
  X60Qini_0_syn1lfpjv();
  gLexDiags_0_lex3r1urc1 = newSeqUninit_0_I90m2ee1_lex3r1urc1(IL64(0));}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40){
  string_0_sysvq0asl result_66;
  NI64 X60Qx_83 = ssLenOf_0_sysvq0asl(s_40.bytes_0);
  if (X60Qx_83 == ((NI64)IL64(255))){
    arcInc_0_sysvq0asl((&(*s_40.more_0).rc_0));}
  result_66 = (string_0_sysvq0asl){
    .bytes_0 = s_40.bytes_0, .more_0 = s_40.more_0}
  ;
  return result_66;}
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32){
  NI64 result_60;
  result_60 = ((NI64)(*((NU8*)(&s_32.bytes_0))));
  if (((NI64)IL64(14)) < result_60){
    result_60 = (*s_32.more_0).fullLen_0;}
  return result_60;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38){
  (*s_38).bytes_0 = ((NU64)IL64(0));}
static inline void nimStrDestroy(string_0_sysvq0asl s_39){
  if (((NI64)(*((NU8*)(&s_39.bytes_0)))) == ((NI64)IL64(255))){
    NB8 X60Qx_80 = arcDec_0_sysvq0asl((&(*s_39.more_0).rc_0));
    if (X60Qx_80){
      dealloc_0_sysvq0asl(((void*)s_39.more_0));}}}
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_52, NI64 i_14){
  NB8 X60Qx_116;
  NI64 X60Qx_117 = len_4_sysvq0asl(s_52);
  if (i_14 < X60Qx_117){
    X60Qx_116 = (IL64(0) <= i_14);}
  else {
    X60Qx_116 = NIM_FALSE;}
  if ((!X60Qx_116)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14131790745264837101_sysvq0asl)}
    );}
  NC8 result_74;
  NC8 X60Qx_21;
  if (((NI64)IL64(14)) < ((NI64)(*((NU8*)(&s_52.bytes_0))))){
    X60Qx_21 = (*s_52.more_0).data_0[i_14];}
  else {
    X60Qx_21 = ((NC8*)((NU64)(((NU64)(&s_52.bytes_0)) + 1ull)))[i_14];}
  result_74 = X60Qx_21;
  return result_74;}
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_53, NI64 i_15, NC8 c_1){
  NB8 X60Qx_118;
  NI64 X60Qx_119 = len_4_sysvq0asl((*s_53));
  if (i_15 < X60Qx_119){
    X60Qx_118 = (IL64(0) <= i_15);}
  else {
    X60Qx_118 = NIM_FALSE;}
  if ((!X60Qx_118)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I11927585966806674622_sysvq0asl)}
    );}
  prepareMutation_0_sysvq0asl(s_53);
  if (((NI64)IL64(14)) < ((NI64)(*((NU8*)(&(*s_53).bytes_0))))){
    (*(*s_53).more_0).data_0[i_15] = c_1;
    if (i_15 < ((NI64)IL64(7))){
      ((NC8*)((NU64)(((NU64)(&(*s_53).bytes_0)) + 1ull)))[i_15] = c_1;}}
  else {
    ((NC8*)((NU64)(((NU64)(&(*s_53).bytes_0)) + 1ull)))[i_15] = c_1;}}
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1){
  (*x_1) = ((NI64)((*x_1) + ((NI64)IL64(1))));}
static inline NC8 chr_0_sysvq0asl(NI64 u_0){
  NC8 result_130;
  result_130 = ((NC8)((NI64)u_0));
  return result_130;}
static inline openArray_0_Ijk0jkw1_has9tn57v toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_65){
  openArray_0_Ijk0jkw1_has9tn57v result_108;
  NC8* X60Qx_175 = readRawData_0_sysvq0asl((&(*s_65)), IL64(0));
  NI64 X60Qx_176 = len_4_sysvq0asl((*s_65));
  result_108 = (openArray_0_Ijk0jkw1_has9tn57v){
    .a_0 = X60Qx_175, .len_0 = X60Qx_176}
  ;
  return result_108;}
static inline NI64 len_6_Iroq7kd1_has9tn57v(openArray_0_Ijk0jkw1_has9tn57v a_6){
  NI64 result_18;
  result_18 = a_6.len_0;
  return result_18;}
static inline NC8* getQ_10_I5nt6we_has9tn57v(openArray_0_Ijk0jkw1_has9tn57v x_14, NI64 idx_1){
  NB8 X60Qx_19;
  if (IL64(0) <= idx_1){
    X60Qx_19 = (idx_1 < x_14.len_0);}
  else {
    X60Qx_19 = NIM_FALSE;}
  if ((!X60Qx_19)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14694606176902936784_has9tn57v)}
    );}
  NC8* result_19;
  result_19 = (&x_14.a_0[idx_1]);
  return result_19;}
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_56, NI64 idx_2, NC8 ch_0){
  NB8 result_89;
  NB8 X60Qx_143;
  NI64 X60Qx_144 = len_4_sysvq0asl(s_56);
  if (idx_2 < X60Qx_144){
    NC8 X60Qx_145 = getQ_9_sysvq0asl(s_56, idx_2);
    X60Qx_143 = (X60Qx_145 <= ch_0);}
  else {
    X60Qx_143 = NIM_FALSE;}
  result_89 = X60Qx_143;
  return result_89;}
static inline seq_0_Ixdx2fh1_aif7a4qfr newSeqUninit_0_Im3cqd9_aif7a4qfr(NI64 size_1){
  seq_0_Ixdx2fh1_aif7a4qfr result_0;
  if (size_1 == IL64(0)){
    result_0 = (seq_0_Ixdx2fh1_aif7a4qfr){
      .len_0 = size_1, .data_0 = NIM_NIL}
    ;}
  else {
    NI64 memSize_0 = memSizeInBytes_0_I7me00i_aif7a4qfr(size_1);
    void* X60Qx_24 = alloc_0_sysvq0asl(memSize_0);
    result_0 = (seq_0_Ixdx2fh1_aif7a4qfr){
      .len_0 = size_1, .data_0 = ((string_0_sysvq0asl*)X60Qx_24)}
    ;
    if ((!(result_0.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_25 = (string_0_sysvq0asl){
        .bytes_0 = 8439857260806892798ull, .more_0 = (&strlit_0_I15750996627617194403_aif7a4qfr)}
      ;}
    else {
      result_0.len_0 = IL64(0);
      oomHandler_0_sysvq0asl(memSize_0);}}
  return result_0;}
static inline void add_0_Ig6072n_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_5, string_0_sysvq0asl elem_1){
  NI64 L_0 = (*s_5).len_0;
  NI64 X60Qx_27 = capInBytes_0_Ih2sbn01_aif7a4qfr((*s_5));
  if (X60Qx_27 < ((NI64)(((NI64)(L_0 * sizeof(string_0_sysvq0asl))) + sizeof(string_0_sysvq0asl)))){
    NB8 X60Qx_28 = resize_0_I4buliy_aif7a4qfr(s_5, IL64(1));
    if ((!X60Qx_28)){
      nimStrDestroy(elem_1);
      return;}}
  inc_1_Irn1g7r1_aif7a4qfr((&(*s_5).len_0));
  (*s_5).data_0[L_0] = elem_1;}
static inline void eQwasMoved_1_I5vdnla_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_11){
  (*s_11).len_0 = IL64(0);
  (*s_11).data_0 = NIM_NIL;}
static inline void dec_1_I2mwrey1_envto7w6l1(NI64* x_8){
  (*x_8) = ((NI64)((*x_8) - ((NI64)IL64(1))));}
static inline NI64 recalcCap_0_sysvq0asl(NI64 oldCap_0, NI64 addedElements_0){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI64 result_47;
  NI64 X60QconstRefTemp_0;
  if (__builtin_saddll_overflow(oldCap_0, addedElements_0, (long long int*)(&X60QconstRefTemp_0))){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  NI64 requiredLen_0 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_47 = ((NI64)IL64(9223372036854775807));}
  else {
    NI64 X60QconstRefTemp_1;
    if (__builtin_saddll_overflow(oldCap_0, ((NI64)(((NI64)oldCap_0) >> ((NU64)IL64(1)))), (long long int*)(&X60QconstRefTemp_1))){
      LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
    result_47 = X60QconstRefTemp_1;
    if (LENGC_OVF_){
      result_47 = requiredLen_0;}
    else {
      NI64 X60Qx_78 = max_3_sysvq0asl(result_47, requiredLen_0);
      result_47 = X60Qx_78;}}
  return result_47;}
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0){
  NI64 result_57;
  result_57 = ((NI64)((NU64)(bytes_0 & 255ull)));
  return result_57;}
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0){
  NI64 X60Qx_177 = __atomic_add_fetch((&(*memLoc_0)), IL64(1), __ATOMIC_SEQ_CST);}
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1){
  NB8 result_118;
  NI64 X60Qx_178 = __atomic_sub_fetch((&(*memLoc_1)), IL64(1), __ATOMIC_SEQ_CST);
  result_118 = (X60Qx_178 < IL64(0));
  return result_118;}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_37, NI64 start_0){
  NC8* result_65;
  if (((NI64)IL64(14)) < ((NI64)(*((NU8*)(&(*s_37).bytes_0))))){
    result_65 = ((NC8*)((NU64)(((NU64)(&(*(*s_37).more_0).data_0[IL64(0)])) + ((NU64)start_0))));}
  else {
    result_65 = ((NC8*)((NU64)(((NU64)((NC8*)((NU64)(((NU64)(&(*s_37).bytes_0)) + 1ull)))) + ((NU64)start_0))));}
  return result_65;}
static inline NI64 memSizeInBytes_0_I7me00i_aif7a4qfr(NI64 size_3){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI64 result_4;
  NI64 X60QconstRefTemp_0;
  if (__builtin_smulll_overflow(size_3, sizeof(string_0_sysvq0asl), (long long int*)(&X60QconstRefTemp_0))){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_4 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_4 = ((NI64)IL64(9223372036854775807));}
  return result_4;}
static inline NI64 capInBytes_0_Ih2sbn01_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_7){
  NI64 result_5;
  NI64 X60Qx_0;
  if ((!(s_7.data_0 == NIM_NIL))){
    NI64 X60Qx_29 = allocatedSize_0_sysvq0asl(((void*)((void*)s_7.data_0)));
    X60Qx_0 = X60Qx_29;}
  else {
    X60Qx_0 = IL64(0);}
  result_5 = X60Qx_0;
  return result_5;}
static inline NI64 max_3_sysvq0asl(NI64 x_212, NI64 y_169){
  NI64 result_13;
  NI64 X60Qx_9;
  if (y_169 <= x_212){
    X60Qx_9 = x_212;}
  else {
    X60Qx_9 = y_169;}
  result_13 = X60Qx_9;
  return result_13;}
