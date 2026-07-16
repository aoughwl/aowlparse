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
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
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
typedef NU8 Severity_0_tok9e79hf;

#define sevHint_0_tok9e79hf ((NU8)IL64(0))
#define sevWarn_0_tok9e79hf ((NU8)IL64(1))
#define sevError_0_tok9e79hf ((NU8)IL64(2))
typedef struct string_0_sysvq0asl{
  NU64 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct Diagnostic_0_tok9e79hf{
  Severity_0_tok9e79hf severity_0;
  string_0_sysvq0asl code_0;
  string_0_sysvq0asl message_0;
  NI32 line_0;
  NI32 col_0;
  NI32 endCol_0;}
Diagnostic_0_tok9e79hf;
typedef struct seq_0_Ixdx2fh1_aif7a4qfr{
  NI64 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aif7a4qfr;
typedef struct seq_0_Ift2sne_lex3r1urc1{
  NI64 len_0;
  NI32* data_0;}
seq_0_Ift2sne_lex3r1urc1;
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
typedef struct openArray_0_Ig73pnk_osalirkw71{
  string_0_sysvq0asl* a_0;
  NI64 len_0;}
openArray_0_Ig73pnk_osalirkw71;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS66_tok9e79hf{
  string_0_sysvq0asl a[IL64(66)];}
X60Qt_0_IAarraySstring0sysvq0aslS66_tok9e79hf;
typedef struct LongString_0_sysvq0asl{
  NI64 fullLen_0;
  NI64 rc_0;
  NI64 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI64);
static inline openArray_0_Ig73pnk_osalirkw71 toOpenArray_0_Ijzd1nf_tok9e79hf(X60Qt_0_IAarraySstring0sysvq0aslS66_tok9e79hf* x_1);
void eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* dest_0);
void eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* dest_0);
extern LongString_0_sysvq0asl const strlit_0_I2210116261907819816_parq39nt2;
extern LongString_0_sysvq0asl const strlit_0_I6864681898360807206_parq39nt2;
extern LongString_0_sysvq0asl const strlit_0_I3021806080610957510_parq39nt2;
extern LongString_0_sysvq0asl const strlit_0_I9071657656589967445_parq39nt2;
extern LongString_0_sysvq0asl const strlit_0_I17987658270787974407_parq39nt2;
static inline NI64 len_6_Igv2wyu1_osalirkw71(openArray_0_Ig73pnk_osalirkw71 a_3);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_osalirkw71(openArray_0_Ig73pnk_osalirkw71 x_4, NI64 idx_1);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_14, string_0_sysvq0asl b_10);
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1);
static inline seq_0_Ixdx2fh1_aif7a4qfr newSeqUninit_0_Im3cqd9_aif7a4qfr(NI64 size_1);
static inline seq_0_Ift2sne_lex3r1urc1 newSeqUninit_0_Iggfvwp_lex3r1urc1(NI64 size_8);
static inline void nimStrDestroy(string_0_sysvq0asl s_39);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40);
extern void eQdestroy_1_Iv9ij5i1_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1 s_45);
extern void eQdestroy_1_Ivioh0a_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_10);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38);
static inline void eQwasMoved_1_I5vdnla_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_11);
static inline void eQwasMoved_1_Ix88qzs1_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1* s_46);
extern seq_0_Ixdx2fh1_aif7a4qfr eQdup_1_Imq0s4c_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr a_5);
extern seq_0_Ift2sne_lex3r1urc1 eQdup_1_Iplow11_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1 a_11);
extern void X60Qini_0_sysvq0asl(void);
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_68);
extern LongString_0_sysvq0asl const strlit_0_I14694606176902936784_has9tn57v;
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_13, string_0_sysvq0asl b_9);
static inline NI64 memSizeInBytes_0_I7me00i_aif7a4qfr(NI64 size_3);
extern void* alloc_0_sysvq0asl(NI64 size_10);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aif7a4qfr;
extern X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI64 memSizeInBytes_0_Inv7kg3_lex3r1urc1(NI64 size_14);
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1);
extern void dealloc_0_sysvq0asl(void* p_10);
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0);
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0);
LongString_0_sysvq0asl const strlit_0_I11374605019106816382_tok9e79hf = {
  .fullLen_0 = IL64(9), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "interface"}
;
X60Qt_0_IAarraySstring0sysvq0aslS66_tok9e79hf const Keywords_0_tok9e79hf = {
  .a = {
    {
      .bytes_0 = 491310571780ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1684955395ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7561474ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1836278019ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 431349129732ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 118066057994757ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 500151968516ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 8390317583520195335ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 128039122854661ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 8461816698665657342ull, .more_0 = (&strlit_0_I2210116261907819816_parq39nt2)}
    , {
      .bytes_0 = 8390880615077995518ull, .more_0 = (&strlit_0_I6864681898360807206_parq39nt2)}
    , {
      .bytes_0 = 125779835184133ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7237954630903751687ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7164780006066447614ull, .more_0 = (&strlit_0_I3021806080610957510_parq39nt2)}
    , {
      .bytes_0 = 1986618371ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7300098ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1684956419ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 470121604356ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 32776920252310790ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 8749487341794059783ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1919903235ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 470021203460ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 427054949892ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 32776920251590918ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7235842ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7306093603886885127ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7018422849374153214ull, .more_0 = (&strlit_0_I11374605019106816382_tok9e79hf)}
    , {
      .bytes_0 = 7563522ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 128021943249157ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
    , {
      .bytes_0 = 1952803843ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 122537084284165ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 28269992091151622ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 121399270796549ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1685024003ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1818848771ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1953459715ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 121399204081157ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 32760384526118662ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7499522ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1953853187ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 427071533060ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1920233475ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 111546363638277ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1717924355ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 31088096227717638ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1818784515ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1919447811ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 27981971266499334ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 8386103211268076798ull, .more_0 = (&strlit_0_I17987658270787974407_parq39nt2)}
    , {
      .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 111516417618949ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 435678704644ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 113723913237765ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1918989827ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 111516299327237ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1919907843ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 110416720656645ull, .more_0 = NIM_NIL}}}
;
NB8 X60QiniGuard_0_tok9e79hf;
NB8 isKeyword_0_tok9e79hf(string_0_sysvq0asl s_0){
  NB8 result_2;
  {
    openArray_0_Ig73pnk_osalirkw71 X60Qlf_0 = toOpenArray_0_Ijzd1nf_tok9e79hf((&Keywords_0_tok9e79hf));
    NI64 X60Qlf_1 = IL64(0);
    {
      while (NIM_TRUE){
        NI64 X60Qx_3 = len_6_Igv2wyu1_osalirkw71(X60Qlf_0);
        if (X60Qlf_1 < X60Qx_3){
          {
            string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_osalirkw71(X60Qlf_0, X60Qlf_1);
            NB8 X60Qx_4 = eqQ_20_sysvq0asl((*X60Qii_2), s_0);
            if (X60Qx_4){
              return NIM_TRUE;}}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_1));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return NIM_FALSE;
  return result_2;}
Token_0_tok9e79hf initToken_0_tok9e79hf(TokKind_0_tok9e79hf kind_0, NI32 line_0, NI32 col_0){
  Token_0_tok9e79hf result_3;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_3));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_3));
  seq_0_Ixdx2fh1_aif7a4qfr X60Qx_5 = newSeqUninit_0_Im3cqd9_aif7a4qfr(IL64(0));
  seq_0_Ift2sne_lex3r1urc1 X60Qx_6 = newSeqUninit_0_Iggfvwp_lex3r1urc1(IL64(0));
  result_3 = (Token_0_tok9e79hf){
    .kind_0 = kind_0, .s_0 = (string_0_sysvq0asl){
      .bytes_0 = 0ull, .more_0 = NIM_NIL}
    , .iVal_0 = IL64(0), .fVal_0 = 0.0, .suffix_0 = (string_0_sysvq0asl){
      .bytes_0 = 0ull, .more_0 = NIM_NIL}
    , .line_0 = line_0, .col_0 = col_0, .endCol_0 = col_0, .indent_0 = ((NI32)IL64(-1)), .quoted_0 = NIM_FALSE, .parts_0 = X60Qx_5, .partCols_0 = X60Qx_6}
  ;
  return result_3;}
static inline openArray_0_Ig73pnk_osalirkw71 toOpenArray_0_Ijzd1nf_tok9e79hf(X60Qt_0_IAarraySstring0sysvq0aslS66_tok9e79hf* x_1){
  openArray_0_Ig73pnk_osalirkw71 result_4;
  openArray_0_Ig73pnk_osalirkw71 X60Qx_0;
  if (((NI64)(((NI64)(((NI64)((NI64)IL64(65))) - ((NI64)((NI64)IL64(0))))) + IL64(1))) == IL64(0)){
    X60Qx_0 = (openArray_0_Ig73pnk_osalirkw71){
      .a_0 = NIM_NIL, .len_0 = IL64(0)}
    ;}
  else {
    X60Qx_0 = (openArray_0_Ig73pnk_osalirkw71){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_1))), .len_0 = ((NI64)(((NI64)(((NI64)((NI64)IL64(65))) - ((NI64)((NI64)IL64(0))))) + IL64(1)))}
    ;}
  result_4 = X60Qx_0;
  return result_4;}
void eQdestroyQ_SX44iagnostic0tok9e79hf_0_tok9e79hf(Diagnostic_0_tok9e79hf* dest_0){
  nimStrDestroy((*dest_0).message_0);
  nimStrDestroy((*dest_0).code_0);}
Diagnostic_0_tok9e79hf eQdupQ_SX44iagnostic0tok9e79hf_0_tok9e79hf(Diagnostic_0_tok9e79hf* src_0){
  Diagnostic_0_tok9e79hf dest_0;
  dest_0.severity_0 = (*src_0).severity_0;
  string_0_sysvq0asl X60Qx_24 = nimStrDup((*src_0).code_0);
  dest_0.code_0 = X60Qx_24;
  string_0_sysvq0asl X60Qx_25 = nimStrDup((*src_0).message_0);
  dest_0.message_0 = X60Qx_25;
  dest_0.line_0 = (*src_0).line_0;
  dest_0.col_0 = (*src_0).col_0;
  dest_0.endCol_0 = (*src_0).endCol_0;
  return dest_0;}
void eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* dest_0){
  eQdestroy_1_Iv9ij5i1_lex3r1urc1((*dest_0).partCols_0);
  eQdestroy_1_Ivioh0a_aif7a4qfr((*dest_0).parts_0);
  nimStrDestroy((*dest_0).suffix_0);
  nimStrDestroy((*dest_0).s_0);}
void eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* dest_0){
  nimStrWasMoved((&(*dest_0).s_0));
  nimStrWasMoved((&(*dest_0).suffix_0));
  eQwasMoved_1_I5vdnla_aif7a4qfr((&(*dest_0).parts_0));
  eQwasMoved_1_Ix88qzs1_lex3r1urc1((&(*dest_0).partCols_0));}
Token_0_tok9e79hf eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* src_0){
  Token_0_tok9e79hf dest_0;
  dest_0.kind_0 = (*src_0).kind_0;
  string_0_sysvq0asl X60Qx_26 = nimStrDup((*src_0).s_0);
  dest_0.s_0 = X60Qx_26;
  dest_0.iVal_0 = (*src_0).iVal_0;
  dest_0.fVal_0 = (*src_0).fVal_0;
  string_0_sysvq0asl X60Qx_27 = nimStrDup((*src_0).suffix_0);
  dest_0.suffix_0 = X60Qx_27;
  dest_0.line_0 = (*src_0).line_0;
  dest_0.col_0 = (*src_0).col_0;
  dest_0.endCol_0 = (*src_0).endCol_0;
  dest_0.indent_0 = (*src_0).indent_0;
  dest_0.quoted_0 = (*src_0).quoted_0;
  seq_0_Ixdx2fh1_aif7a4qfr X60Qx_28 = eQdup_1_Imq0s4c_aif7a4qfr((*src_0).parts_0);
  dest_0.parts_0 = X60Qx_28;
  seq_0_Ift2sne_lex3r1urc1 X60Qx_29 = eQdup_1_Iplow11_lex3r1urc1((*src_0).partCols_0);
  dest_0.partCols_0 = X60Qx_29;
  return dest_0;}
void X60Qini_0_tok9e79hf(void){
  if (X60QiniGuard_0_tok9e79hf){
    return;}
  X60QiniGuard_0_tok9e79hf = NIM_TRUE;
  X60Qini_0_sysvq0asl();}
static inline NI64 len_6_Igv2wyu1_osalirkw71(openArray_0_Ig73pnk_osalirkw71 a_3){
  NI64 result_9;
  result_9 = a_3.len_0;
  return result_9;}
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_osalirkw71(openArray_0_Ig73pnk_osalirkw71 x_4, NI64 idx_1){
  NB8 X60Qx_11;
  if (IL64(0) <= idx_1){
    X60Qx_11 = (idx_1 < x_4.len_0);}
  else {
    X60Qx_11 = NIM_FALSE;}
  if ((!X60Qx_11)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14694606176902936784_has9tn57v)}
    );}
  string_0_sysvq0asl* result_10;
  result_10 = (&x_4.a_0[idx_1]);
  return result_10;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_14, string_0_sysvq0asl b_10){
  NB8 result_88;
  NB8 X60Qx_142 = equalStrings_0_sysvq0asl(a_14, b_10);
  result_88 = X60Qx_142;
  return result_88;}
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1){
  (*x_1) = ((NI64)((*x_1) + ((NI64)IL64(1))));}
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
static inline void nimStrDestroy(string_0_sysvq0asl s_39){
  if (((NI64)(*((NU8*)(&s_39.bytes_0)))) == ((NI64)IL64(255))){
    NB8 X60Qx_80 = arcDec_0_sysvq0asl((&(*s_39.more_0).rc_0));
    if (X60Qx_80){
      dealloc_0_sysvq0asl(((void*)s_39.more_0));}}}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40){
  string_0_sysvq0asl result_66;
  NI64 X60Qx_83 = ssLenOf_0_sysvq0asl(s_40.bytes_0);
  if (X60Qx_83 == ((NI64)IL64(255))){
    arcInc_0_sysvq0asl((&(*s_40.more_0).rc_0));}
  result_66 = (string_0_sysvq0asl){
    .bytes_0 = s_40.bytes_0, .more_0 = s_40.more_0}
  ;
  return result_66;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38){
  (*s_38).bytes_0 = ((NU64)IL64(0));}
static inline void eQwasMoved_1_I5vdnla_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_11){
  (*s_11).len_0 = IL64(0);
  (*s_11).data_0 = NIM_NIL;}
static inline void eQwasMoved_1_Ix88qzs1_lex3r1urc1(seq_0_Ift2sne_lex3r1urc1* s_46){
  (*s_46).len_0 = IL64(0);
  (*s_46).data_0 = NIM_NIL;}
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
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1){
  NB8 result_118;
  NI64 X60Qx_178 = __atomic_sub_fetch((&(*memLoc_1)), IL64(1), __ATOMIC_SEQ_CST);
  result_118 = (X60Qx_178 < IL64(0));
  return result_118;}
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0){
  NI64 result_57;
  result_57 = ((NI64)((NU64)(bytes_0 & 255ull)));
  return result_57;}
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0){
  NI64 X60Qx_177 = __atomic_add_fetch((&(*memLoc_0)), IL64(1), __ATOMIC_SEQ_CST);}
