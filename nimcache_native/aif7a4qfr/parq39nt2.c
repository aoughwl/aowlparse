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
#include <stdio.h>
typedef struct Token_0_tok9e79hf Token_0_tok9e79hf;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct seq_0_Iyai4gn_lex3r1urc1{
  NI64 len_0;
  Token_0_tok9e79hf* data_0;}
seq_0_Iyai4gn_lex3r1urc1;
typedef struct string_0_sysvq0asl{
  NU64 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct Parser_0_parq39nt2{
  seq_0_Iyai4gn_lex3r1urc1 toks_0;
  string_0_sysvq0asl file_0;
  NB8 curly_0;
  NI64 depth_0;
  NI64 maxDepth_0;}
Parser_0_parq39nt2;
typedef struct seq_0_Iotb7mc_mat7cnfv21{
  NI64 len_0;
  NI64* data_0;}
seq_0_Iotb7mc_mat7cnfv21;
typedef struct openArray_0_Ig73pnk_osalirkw71{
  string_0_sysvq0asl* a_0;
  NI64 len_0;}
openArray_0_Ig73pnk_osalirkw71;
typedef struct openArray_0_Iu1stc01_parq39nt2{
  Token_0_tok9e79hf* a_0;
  NI64 len_0;}
openArray_0_Iu1stc01_parq39nt2;
typedef struct seq_0_Iflf8jf1_parq39nt2{
  NI64 len_0;
  NB8* data_0;}
seq_0_Iflf8jf1_parq39nt2;
typedef struct seq_0_Ixdx2fh1_aif7a4qfr{
  NI64 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aif7a4qfr;
typedef struct seq_0_Ift2sne_lex3r1urc1{
  NI64 len_0;
  NI32* data_0;}
seq_0_Ift2sne_lex3r1urc1;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS14_parq39nt2{
  string_0_sysvq0asl a[IL64(14)];}
X60Qt_0_IAarraySstring0sysvq0aslS14_parq39nt2;
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
typedef NU8 Mode_0_nifjp9lau1;

#define UsesMem_0_nifjp9lau1 ((NU8)IL64(0))
#define UsesFile_0_nifjp9lau1 ((NU8)IL64(1))
typedef NU8 FileWriteMode_0_vfsc9jn7;

#define AlwaysWrite_0_vfsc9jn7 ((NU8)IL64(0))
#define OnlyIfChanged_0_vfsc9jn7 ((NU8)IL64(1))
typedef struct Builder_0_nifjp9lau1{
  string_0_sysvq0asl buffer_0;
  Mode_0_nifjp9lau1 mode_0;
  FileWriteMode_0_vfsc9jn7 writeMode_0;
  NB8 compact_0;
  string_0_sysvq0asl filename_0;
  NI64 nesting_0;
  NI64 offs_0;}
Builder_0_nifjp9lau1;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI64);
NB8 isBinaryOp_0_parq39nt2(Token_0_tok9e79hf* t_1);
NB8 startsExpr_0_parq39nt2(Token_0_tok9e79hf* t_3);
NI64 matchClose_0_parq39nt2(Parser_0_parq39nt2* ps_8, NI64 openIdx_0);
void parsePrimaryRange_1_parq39nt2(Parser_0_parq39nt2* ps_37, Builder_0_nifjp9lau1* b_21, NI32 lo_21, NI32 hi_21, NI32 pl_21, NI32 pc_21);
void parseExprRange_1_parq39nt2(Parser_0_parq39nt2* ps_39, Builder_0_nifjp9lau1* b_23, NI32 lo_23, NI32 hi_23, NI32 pl_23, NI32 pc_23);
void parseTypeRange_1_parq39nt2(Parser_0_parq39nt2* ps_51, Builder_0_nifjp9lau1* b_34, NI32 lo_29, NI32 hi_28, NI32 pl_34, NI32 pc_34);
NI64 parseType_1_parq39nt2(Parser_0_parq39nt2* ps_52, Builder_0_nifjp9lau1* b_35, NI64 idx_2, NI32 pl_35, NI32 pc_35);
void parseTupleInline_1_parq39nt2(Parser_0_parq39nt2* ps_53, Builder_0_nifjp9lau1* b_36, NI32 lo_30, NI32 hi_29, NI32 pl_36, NI32 pc_36);
void parseProcType_1_parq39nt2(Parser_0_parq39nt2* ps_54, Builder_0_nifjp9lau1* b_37, NI32 lo_31, NI32 hi_30, NI32 pl_37, NI32 pc_37);
NI64 parsePragmas_1_parq39nt2(Parser_0_parq39nt2* ps_55, Builder_0_nifjp9lau1* b_38, NI64 braceIdx_1, NI32 pl_38, NI32 pc_38);
NI64 parseParams_1_parq39nt2(Parser_0_parq39nt2* ps_69, Builder_0_nifjp9lau1* b_51, NI64 lpIdx_1, NI32 pl_46, NI32 pc_46);
NI64 parseRoutine_1_parq39nt2(Parser_0_parq39nt2* ps_70, Builder_0_nifjp9lau1* b_52, NI64 kwIdx_4, NI32 pl_47, NI32 pc_47, string_0_sysvq0asl tag_2);
void parseCommand_1_parq39nt2(Parser_0_parq39nt2* ps_71, Builder_0_nifjp9lau1* b_53, NI32 lo_32, NI32 hi_32, NI32 pl_48, NI32 pc_48);
NI64 skipTrailingDoc_1_parq39nt2(Parser_0_parq39nt2* ps_75, NI64 i_5, NI64 refIndent_1);
NI64 findColon_0_parq39nt2(Parser_0_parq39nt2* ps_76, NI64 lo_34, NI64 hi_34);
void parseTryExpr_1_parq39nt2(Parser_0_parq39nt2* ps_82, Builder_0_nifjp9lau1* b_62, NI32 lo_35, NI32 hi_35, NI32 pl_57, NI32 pc_57);
NI64 parseTry_1_parq39nt2(Parser_0_parq39nt2* ps_83, Builder_0_nifjp9lau1* b_63, NI64 kwIdx_11, NI32 pl_58, NI32 pc_58);
NI64 parseCtrlFlowValue_0_parq39nt2(Parser_0_parq39nt2* ps_87, Builder_0_nifjp9lau1* b_67, NI64 kwIdx_15, NI32 pl_62, NI32 pc_62);
NI64 semiEnd_0_parq39nt2(Parser_0_parq39nt2* ps_93, NI64 startIdx_2, NI64 bound_0);
NI64 parsePostExprBlock_1_parq39nt2(Parser_0_parq39nt2* ps_94, Builder_0_nifjp9lau1* b_73, NI64 headLo_1, NI64 colonIdx_3, NI32 pl_68, NI32 pc_68);
NI64 parseStmt_1_parq39nt2(Parser_0_parq39nt2* ps_97, Builder_0_nifjp9lau1* b_76, NI64 startIdx_5, NI32 pl_71, NI32 pc_71, NI64 hiLimit_3);
static inline NI64 len_3_I0v1j8d_parq39nt2(seq_0_Ift2sne_lex3r1urc1 s_21);
static inline NI32* getQ_7_Ir8kccm_parq39nt2(seq_0_Ift2sne_lex3r1urc1 s_22, NI64 i_52);
static inline openArray_0_Ig73pnk_osalirkw71 toOpenArray_0_Ipj8xjx1_parq39nt2(X60Qt_0_IAarraySstring0sysvq0aslS14_parq39nt2* x_6);
static inline void add_0_I8fahwb_parq39nt2(seq_0_Iotb7mc_mat7cnfv21* s_23, NI64 elem_3);
static inline NI64 len_3_I12oavy1_parq39nt2(seq_0_Iotb7mc_mat7cnfv21 s_25);
static inline NI64* getQ_7_Ite3z0o_parq39nt2(seq_0_Iotb7mc_mat7cnfv21 s_26, NI64 i_54);
static inline openArray_0_Iu1stc01_parq39nt2 toOpenArray_1_I6ofx191_parq39nt2(seq_0_Iyai4gn_lex3r1urc1 s_29);
static inline seq_0_Iflf8jf1_parq39nt2 newSeqUninit_0_I5mozxi1_parq39nt2(NI64 size_7);
static inline void add_0_Irnc3p1_parq39nt2(seq_0_Iflf8jf1_parq39nt2* s_31, NB8 elem_5);
static inline NB8* getQ_7_Iul1no9_parq39nt2(seq_0_Iflf8jf1_parq39nt2 s_33, NI64 i_56);
NB8 resize_0_Itn1ieo1_parq39nt2(seq_0_Iotb7mc_mat7cnfv21* dest_3, NI64 addedElements_3);
static inline Token_0_tok9e79hf* rawData_0_Ilu0q8c1_parq39nt2(seq_0_Iyai4gn_lex3r1urc1 s_36);
static inline NI64 len_6_Inwgz45_parq39nt2(openArray_0_Iu1stc01_parq39nt2 a_9);
static inline Token_0_tok9e79hf* getQ_10_Iplfojn1_parq39nt2(openArray_0_Iu1stc01_parq39nt2 x_11, NI64 idx_6);
static inline NI64 memSizeInBytes_0_Ih4q01h_parq39nt2(NI64 size_11);
static inline NI64 capInBytes_0_In1m6ni_parq39nt2(seq_0_Iflf8jf1_parq39nt2 s_37);
NB8 resize_0_I2yw78g1_parq39nt2(seq_0_Iflf8jf1_parq39nt2* dest_5, NI64 addedElements_5);
void eQdestroy_1_I7a20g9_parq39nt2(seq_0_Iflf8jf1_parq39nt2 s_52);
void eQdestroyQ_SX50arser0parq39nt2_0_parq39nt2(Parser_0_parq39nt2* dest_0);
void eQwasmovedQ_SX50arser0parq39nt2_0_parq39nt2(Parser_0_parq39nt2* dest_0);
extern seq_0_Iyai4gn_lex3r1urc1 eQdup_1_Ikdu5b_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 a_9);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40);
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1);
extern string_0_sysvq0asl dollarQ_1_sysvq0asl(NI64 x_225);
extern string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226);
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI64 len_3);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_48, string_0_sysvq0asl part_0);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern void quit_0_syn1lfpjv(NI64 value_0);
static inline void nimStrDestroy(string_0_sysvq0asl s_39);
extern void eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* dest_0);
static inline NI64 len_3_Iefkljt1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_23);
extern void eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* dest_0);
static inline Token_0_tok9e79hf* getQ_7_Ijq9cyk1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_26, NI64 i_3);
extern Token_0_tok9e79hf eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf(Token_0_tok9e79hf* src_0);
extern void attachLineInfo_1_nifjp9lau1(Builder_0_nifjp9lau1* b_27, NI32 col_2, NI32 line_2, string_0_sysvq0asl file_2);
static inline void plusQeQ_0_Ihg6mz11_mat7cnfv21(NI64* x_147, NI64 y_41);
extern void addTree_0_nifjp9lau1(Builder_0_nifjp9lau1* b_31, string_0_sysvq0asl kind_0);
static inline NI64 len_3_Ixq6taz_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_3);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_4, NI64 i_2);
extern void addIdent_0_nifjp9lau1(Builder_0_nifjp9lau1* b_12, string_0_sysvq0asl s_5);
extern void endTree_0_nifjp9lau1(Builder_0_nifjp9lau1* b_32);
static inline NI64 len_6_Igv2wyu1_osalirkw71(openArray_0_Ig73pnk_osalirkw71 a_3);
static inline string_0_sysvq0asl* getQ_10_Ik9hgkq1_osalirkw71(openArray_0_Ig73pnk_osalirkw71 x_4, NI64 idx_1);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_14, string_0_sysvq0asl b_10);
static inline NB8 nimStrAtLe_0_sysvq0asl(string_0_sysvq0asl s_56, NI64 idx_2, NC8 ch_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_13, string_0_sysvq0asl b_9);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_52, NI64 i_14);
static inline void dec_1_I2mwrey1_envto7w6l1(NI64* x_8);
static inline void eQwasMoved_1_Ia0kll01_mat7cnfv21(seq_0_Iotb7mc_mat7cnfv21* s_5);
extern void eQdestroy_1_Iez2nr5_mat7cnfv21(seq_0_Iotb7mc_mat7cnfv21 s_4);
static inline seq_0_Iotb7mc_mat7cnfv21 newSeqUninit_0_I7whkjh1_mat7cnfv21(NI64 size_4);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38);
extern void addUIntLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_22, NU64 u_0);
extern void addIntLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_21, NI64 i_0);
extern void addStrLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_18, string_0_sysvq0asl s_11);
extern void addFloatLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_24, NF64 f_0, NI32 col_1, NI32 line_1, string_0_sysvq0asl file_1);
extern void addStrLit_1_nifjp9lau1(Builder_0_nifjp9lau1* b_35, string_0_sysvq0asl s_13, string_0_sysvq0asl suffix_1, NI32 col_5, NI32 line_5, string_0_sysvq0asl file_5);
extern void addCharLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_20, NC8 c_2);
extern void addEmpty_0_nifjp9lau1(Builder_0_nifjp9lau1* b_19, NI64 count_0);
static inline seq_0_Iyai4gn_lex3r1urc1 newSeqUninit_0_I28kyaw1_lex3r1urc1(NI64 size_10);
static inline void add_0_Icvfjtn_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* s_24, Token_0_tok9e79hf elem_7);
extern void eQdestroy_1_Ie8xo6a1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_41);
extern void addRaw_0_nifjp9lau1(Builder_0_nifjp9lau1* b_9, string_0_sysvq0asl s_3);
extern LongString_0_sysvq0asl const strlit_0_I2246750106930142149_nifjp9lau1;
extern LongString_0_sysvq0asl const strlit_0_I15962761803738331083_nifjp9lau1;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_68);
extern LongString_0_sysvq0asl const strlit_0_I14532204288076119502_aif7a4qfr;
static inline NI64 capInBytes_0_Ilkynur1_mat7cnfv21(seq_0_Iotb7mc_mat7cnfv21 s_10);
extern void* alloc_0_sysvq0asl(NI64 size_10);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aif7a4qfr;
extern X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI64 recalcCap_0_sysvq0asl(NI64 oldCap_0, NI64 addedElements_0);
static inline NI64 memSizeInBytes_0_Iqj0wsf_mat7cnfv21(NI64 size_5);
extern void* realloc_0_sysvq0asl(void* p_9, NI64 size_12);
extern LongString_0_sysvq0asl const strlit_0_I14694606176902936784_has9tn57v;
extern NI64 allocatedSize_0_sysvq0asl(void* p_11);
extern void dealloc_0_sysvq0asl(void* p_10);
static inline void eQwasMoved_1_I4bu01z_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* s_42);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_tok9e79hf(void);
extern void X60Qini_0_nifjp9lau1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_syn1lfpjv(void);
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0);
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0);
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1);
extern LongString_0_sysvq0asl const strlit_0_I14131790745264837101_sysvq0asl;
static inline NI64 memSizeInBytes_0_Imlcc9c1_lex3r1urc1(NI64 size_15);
static inline NI64 capInBytes_0_Iztvafh1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_30);
extern NB8 resize_0_Ijirql71_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* dest_7, NI64 addedElements_7);
static inline NI64 max_3_sysvq0asl(NI64 x_212, NI64 y_169);
LongString_0_sysvq0asl const strlit_0_I8632713663290646188_parq39nt2 = {
  .fullLen_0 = IL64(46), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "aifparser: parse nesting exceeded --max-depth:"}
;
LongString_0_sysvq0asl const strlit_0_I4431330445191187683_parq39nt2 = {
  .fullLen_0 = IL64(12), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = " (near line "}
;
LongString_0_sysvq0asl const strlit_0_I9071657656589967445_parq39nt2 = {
  .fullLen_0 = IL64(8), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "iterator"}
;
LongString_0_sysvq0asl const strlit_0_I9217337746930322866_parq39nt2 = {
  .fullLen_0 = IL64(10), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "callstrlit"}
;
LongString_0_sysvq0asl const strlit_0_I16361658452647583931_parq39nt2 = {
  .fullLen_0 = IL64(9), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "tabconstr"}
;
LongString_0_sysvq0asl const strlit_0_I3021806080610957510_parq39nt2 = {
  .fullLen_0 = IL64(8), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "distinct"}
;
LongString_0_sysvq0asl const strlit_0_I15938251790995683266_parq39nt2 = {
  .fullLen_0 = IL64(8), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "itertype"}
;
LongString_0_sysvq0asl const strlit_0_I1995551610468546737_parq39nt2 = {
  .fullLen_0 = IL64(8), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "proctype"}
;
LongString_0_sysvq0asl const strlit_0_I14656641239204103783_parq39nt2 = {
  .fullLen_0 = IL64(8), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "typevars"}
;
LongString_0_sysvq0asl const strlit_0_I16948548629793503007_parq39nt2 = {
  .fullLen_0 = IL64(12), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "importexcept"}
;
LongString_0_sysvq0asl const strlit_0_I7395289177220351871_parq39nt2 = {
  .fullLen_0 = IL64(12), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "exportexcept"}
;
LongString_0_sysvq0asl const strlit_0_I1237672436915077942_parq39nt2 = {
  .fullLen_0 = IL64(9), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "unpacktup"}
;
LongString_0_sysvq0asl const strlit_0_I13179338205702368459_parq39nt2 = {
  .fullLen_0 = IL64(10), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "unpackflat"}
;
LongString_0_sysvq0asl const strlit_0_I7731358638274129439_parq39nt2 = {
  .fullLen_0 = IL64(10), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "unpackdecl"}
;
LongString_0_sysvq0asl const strlit_0_I3199637833187763350_parq39nt2 = {
  .fullLen_0 = IL64(10), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "fromimport"}
;
LongString_0_sysvq0asl const strlit_0_I4843651051758684618_parq39nt2 = {
  .fullLen_0 = IL64(10), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "staticstmt"}
;
LongString_0_sysvq0asl const strlit_0_I17987658270787974407_parq39nt2 = {
  .fullLen_0 = IL64(8), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "template"}
;
LongString_0_sysvq0asl const strlit_0_I6864681898360807206_parq39nt2 = {
  .fullLen_0 = IL64(9), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "converter"}
;
LongString_0_sysvq0asl const strlit_0_I2210116261907819816_parq39nt2 = {
  .fullLen_0 = IL64(8), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "continue"}
;
LongString_0_sysvq0asl const strlit_0_I12712967915968306358_parq39nt2 = {
  .fullLen_0 = IL64(9), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "(.aif27)\012"}
;
LongString_0_sysvq0asl const strlit_0_I1979059236716115474_parq39nt2 = {
  .fullLen_0 = IL64(9), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "aifparser"}
;
LongString_0_sysvq0asl const strlit_0_I15261117590630161161_parq39nt2 = {
  .fullLen_0 = IL64(10), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "nim-parsed"}
;
X60Qt_0_IAarraySstring0sysvq0aslS14_parq39nt2 const BinaryKeywords_0_parq39nt2 = {
  .a = {
    {
      .bytes_0 = 1986618371ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1685024003ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1818784515ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1919447811ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1684955395ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7499522ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 1919907843ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7235842ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 121399204081157ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7563522ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 128021943249157ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 7561474ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 470021203460ull, .more_0 = NIM_NIL}}}
;
NB8 X60QiniGuard_0_parq39nt2;
Parser_0_parq39nt2 initParser_0_parq39nt2(seq_0_Iyai4gn_lex3r1urc1 toks_0, string_0_sysvq0asl file_0, NB8 curly_0, NI64 maxDepth_0){
  Parser_0_parq39nt2 result_0;
  eQwasmovedQ_SX50arser0parq39nt2_0_parq39nt2((&result_0));
  eQdestroyQ_SX50arser0parq39nt2_0_parq39nt2((&result_0));
  seq_0_Iyai4gn_lex3r1urc1 X60Qx_188 = eQdup_1_Ikdu5b_lex3r1urc1(toks_0);
  string_0_sysvq0asl X60Qx_189 = nimStrDup(file_0);
  result_0 = (Parser_0_parq39nt2){
    .toks_0 = X60Qx_188, .file_0 = X60Qx_189, .curly_0 = curly_0, .depth_0 = IL64(0), .maxDepth_0 = maxDepth_0}
  ;
  return result_0;}
void enterDepth_0_parq39nt2(Parser_0_parq39nt2* ps_0, NI32 line_0){
  inc_1_Irn1g7r1_aif7a4qfr((&(*ps_0).depth_0));
  NB8 X60Qx_190;
  if (IL64(0) < (*ps_0).maxDepth_0){
    X60Qx_190 = ((*ps_0).maxDepth_0 < (*ps_0).depth_0);}
  else {
    X60Qx_190 = NIM_FALSE;}
  if (X60Qx_190){
    string_0_sysvq0asl X60Qdesugar_0 = dollarQ_1_sysvq0asl((*ps_0).maxDepth_0);
    string_0_sysvq0asl X60Qdesugar_1 = dollarQ_2_sysvq0asl(line_0);
    NI64 X60Qx_191 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8318818597089141246ull, .more_0 = (&strlit_0_I8632713663290646188_parq39nt2)}
    );
    NI64 X60Qx_192 = len_4_sysvq0asl(X60Qdesugar_0);
    NI64 X60Qx_193 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2338038244826423550ull, .more_0 = (&strlit_0_I4431330445191187683_parq39nt2)}
    );
    NI64 X60Qx_194 = len_4_sysvq0asl(X60Qdesugar_1);
    NI64 X60Qx_195 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 665858ull, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_2 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(((NI)(((NI)(X60Qx_191 + X60Qx_192)) + X60Qx_193)) + X60Qx_194)) + X60Qx_195)));
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 8318818597089141246ull, .more_0 = (&strlit_0_I8632713663290646188_parq39nt2)}
    );
    add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_0);
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 2338038244826423550ull, .more_0 = (&strlit_0_I4431330445191187683_parq39nt2)}
    );
    add_2_sysvq0asl((&X60Qdesugar_2), X60Qdesugar_1);
    add_2_sysvq0asl((&X60Qdesugar_2), (string_0_sysvq0asl){
      .bytes_0 = 665858ull, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_2);
    quit_0_syn1lfpjv(IL64(1));
    nimStrDestroy(X60Qdesugar_2);
    nimStrDestroy(X60Qdesugar_1);
    nimStrDestroy(X60Qdesugar_0);}}
Token_0_tok9e79hf tok_0_parq39nt2(Parser_0_parq39nt2* ps_1, NI64 i_0){
  Token_0_tok9e79hf result_1;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_1));
  Token_0_tok9e79hf X60Qx_0;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_0));
  NB8 X60Qx_196;
  if (IL64(0) <= i_0){
    NI64 X60Qx_197 = len_3_Iefkljt1_lex3r1urc1((*ps_1).toks_0);
    X60Qx_196 = (i_0 < X60Qx_197);}
  else {
    X60Qx_196 = NIM_FALSE;}
  if (X60Qx_196){
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_0));
    Token_0_tok9e79hf* X60Qx_198 = getQ_7_Ijq9cyk1_lex3r1urc1((*ps_1).toks_0, i_0);
    Token_0_tok9e79hf X60QconstRefTemp_0 = (*X60Qx_198);
    Token_0_tok9e79hf X60Qx_199 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60QconstRefTemp_0));
    X60Qx_0 = X60Qx_199;}
  else {
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_0));
    NI64 X60Qx_200 = len_3_Iefkljt1_lex3r1urc1((*ps_1).toks_0);
    Token_0_tok9e79hf* X60Qx_201 = getQ_7_Ijq9cyk1_lex3r1urc1((*ps_1).toks_0, ((NI64)(X60Qx_200 - IL64(1))));
    Token_0_tok9e79hf X60QconstRefTemp_1 = (*X60Qx_201);
    Token_0_tok9e79hf X60Qx_202 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60QconstRefTemp_1));
    X60Qx_0 = X60Qx_202;}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_1));
  result_1 = X60Qx_0;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_0));
  return result_1;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_0));
  return result_1;}
NB8 isOpenBracket_0_parq39nt2(TokKind_0_tok9e79hf k_0){
  NB8 result_2;
  NB8 X60Qx_203;
  NB8 X60Qx_204;
  if (k_0 == IL64(10)){
    X60Qx_204 = NIM_TRUE;}
  else {
    X60Qx_204 = (k_0 == IL64(12));}
  if (X60Qx_204){
    X60Qx_203 = NIM_TRUE;}
  else {
    X60Qx_203 = (k_0 == IL64(14));}
  result_2 = X60Qx_203;
  return result_2;}
NB8 isCloseBracket_0_parq39nt2(TokKind_0_tok9e79hf k_1){
  NB8 result_3;
  NB8 X60Qx_205;
  NB8 X60Qx_206;
  if (k_1 == IL64(11)){
    X60Qx_206 = NIM_TRUE;}
  else {
    X60Qx_206 = (k_1 == IL64(13));}
  if (X60Qx_206){
    X60Qx_205 = NIM_TRUE;}
  else {
    X60Qx_205 = (k_1 == IL64(15));}
  result_3 = X60Qx_205;
  return result_3;}
void emitInfo_0_parq39nt2(Parser_0_parq39nt2* ps_2, Builder_0_nifjp9lau1* b_0, NI32 nl_0, NI32 nc_0, NI32 pl_0, NI32 pc_0, NB8 root_0){
  if (root_0){
    attachLineInfo_1_nifjp9lau1(b_0, nc_0, nl_0, (*ps_2).file_0);}
  else {
    attachLineInfo_1_nifjp9lau1(b_0, ((NI32)(nc_0 - pc_0)), ((NI32)(nl_0 - pl_0)), (string_0_sysvq0asl){
      .bytes_0 = 0ull, .more_0 = NIM_NIL}
    );}}
NB8 opIsInfix_0_parq39nt2(Parser_0_parq39nt2* ps_3, NI64 i_1, NI64 lo_0){
  NB8 result_4;
  if (i_1 <= lo_0){
    return NIM_FALSE;}
  Token_0_tok9e79hf t_4 = tok_0_parq39nt2((&(*ps_3)), i_1);
  Token_0_tok9e79hf prev_1 = tok_0_parq39nt2((&(*ps_3)), ((NI64)(i_1 - IL64(1))));
  Token_0_tok9e79hf nxt_0 = tok_0_parq39nt2((&(*ps_3)), ((NI64)(i_1 + IL64(1))));
  NB8 X60Qx_207;
  if ((!(t_4.line_0 == prev_1.line_0))){
    X60Qx_207 = NIM_TRUE;}
  else {
    X60Qx_207 = (prev_1.endCol_0 < t_4.col_0);}
  NB8 leadSpace_0 = X60Qx_207;
  NB8 X60Qx_208;
  if ((!(nxt_0.line_0 == t_4.line_0))){
    X60Qx_208 = NIM_TRUE;}
  else {
    X60Qx_208 = (t_4.endCol_0 < nxt_0.col_0);}
  NB8 trailSpace_0 = X60Qx_208;
  NB8 X60Qx_209;
  if (leadSpace_0){
    X60Qx_209 = (!trailSpace_0);}
  else {
    X60Qx_209 = NIM_FALSE;}
  if (X60Qx_209){
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_0));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_1));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_4));
    return NIM_FALSE;}
  result_4 = NIM_TRUE;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_1));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_4));
  return result_4;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_1));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_4));
  return result_4;}
NB8 startsArg_0_parq39nt2(Parser_0_parq39nt2* ps_4, NI64 i_2, NI64 hi_0){
  NB8 result_5;
  Token_0_tok9e79hf t_5 = tok_0_parq39nt2((&(*ps_4)), i_2);
  if (t_5.kind_0 == IL64(9)){
    if (hi_0 <= ((NI64)(i_2 + IL64(1)))){
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_5));
      return NIM_FALSE;}
    Token_0_tok9e79hf prev_2 = tok_0_parq39nt2((&(*ps_4)), ((NI64)(i_2 - IL64(1))));
    NB8 X60Qx_210;
    if ((!(t_5.line_0 == prev_2.line_0))){
      X60Qx_210 = NIM_TRUE;}
    else {
      X60Qx_210 = (prev_2.endCol_0 < t_5.col_0);}
    NB8 leadSpace_1 = X60Qx_210;
    Token_0_tok9e79hf nxt_1 = tok_0_parq39nt2((&(*ps_4)), ((NI64)(i_2 + IL64(1))));
    NB8 X60Qx_211;
    NB8 X60Qx_212;
    if (leadSpace_1){
      X60Qx_212 = (nxt_1.line_0 == t_5.line_0);}
    else {
      X60Qx_212 = NIM_FALSE;}
    if (X60Qx_212){
      X60Qx_211 = (nxt_1.col_0 == t_5.endCol_0);}
    else {
      X60Qx_211 = NIM_FALSE;}
    result_5 = X60Qx_211;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_1));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_2));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_5));
    return result_5;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_1));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_2));}
  NB8 X60Qx_213;
  NB8 X60Qx_214 = startsExpr_0_parq39nt2((&t_5));
  if (X60Qx_214){
    NB8 X60Qx_215 = isBinaryOp_0_parq39nt2((&t_5));
    X60Qx_213 = (!X60Qx_215);}
  else {
    X60Qx_213 = NIM_FALSE;}
  result_5 = X60Qx_213;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_5));
  return result_5;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_5));
  return result_5;}
NI64 cmdCalleeEnd_0_parq39nt2(Parser_0_parq39nt2* ps_5, NI64 lo_1, NI64 hi_1){
  NI64 result_6;
  NI64 i_7 = lo_1;
  NI32 endCol_0;
  Token_0_tok9e79hf X60Qtmp_0 = tok_0_parq39nt2((&(*ps_5)), i_7);
  NB8 X60Qx_216 = isOpenBracket_0_parq39nt2(X60Qtmp_0.kind_0);
  if (X60Qx_216){
    NI64 c_0 = matchClose_0_parq39nt2((&(*ps_5)), i_7);
    Token_0_tok9e79hf X60Qtmp_1 = tok_0_parq39nt2((&(*ps_5)), c_0);
    endCol_0 = X60Qtmp_1.endCol_0;
    i_7 = ((NI64)(c_0 + IL64(1)));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_1));}
  else {
    Token_0_tok9e79hf X60Qtmp_2 = tok_0_parq39nt2((&(*ps_5)), i_7);
    endCol_0 = X60Qtmp_2.endCol_0;
    inc_1_Irn1g7r1_aif7a4qfr((&i_7));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_2));}
  {
    while (i_7 < hi_1){
      Token_0_tok9e79hf t_6 = tok_0_parq39nt2((&(*ps_5)), i_7);
      NB8 X60Qx_217;
      if (t_6.kind_0 == IL64(19)){
        X60Qx_217 = (((NI64)(i_7 + IL64(1))) < hi_1);}
      else {
        X60Qx_217 = NIM_FALSE;}
      if (X60Qx_217){
        Token_0_tok9e79hf nm_0 = tok_0_parq39nt2((&(*ps_5)), ((NI64)(i_7 + IL64(1))));
        endCol_0 = nm_0.endCol_0;
        plusQeQ_0_Ihg6mz11_mat7cnfv21((&i_7), IL64(2));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nm_0));}
      else {
        NB8 X60Qx_62;
        NB8 X60Qx_63;
        NB8 X60Qx_218 = isOpenBracket_0_parq39nt2(t_6.kind_0);
        if (X60Qx_218){
          Token_0_tok9e79hf X60Qtmp_3 = tok_0_parq39nt2((&(*ps_5)), ((NI64)(i_7 - IL64(1))));
          X60Qx_63 = (t_6.line_0 == X60Qtmp_3.line_0);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_3));}
        else {
          X60Qx_63 = NIM_FALSE;}
        if (X60Qx_63){
          X60Qx_62 = (t_6.col_0 == endCol_0);}
        else {
          X60Qx_62 = NIM_FALSE;}
        if (X60Qx_62){
          NI64 c_1 = matchClose_0_parq39nt2((&(*ps_5)), i_7);
          Token_0_tok9e79hf X60Qtmp_4 = tok_0_parq39nt2((&(*ps_5)), c_1);
          endCol_0 = X60Qtmp_4.endCol_0;
          i_7 = ((NI64)(c_1 + IL64(1)));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_4));}
        else {
          NB8 X60Qx_64;
          NB8 X60Qx_65;
          NB8 X60Qx_219;
          NB8 X60Qx_220;
          if (t_6.kind_0 == IL64(5)){
            X60Qx_220 = NIM_TRUE;}
          else {
            X60Qx_220 = (t_6.kind_0 == IL64(6));}
          if (X60Qx_220){
            X60Qx_219 = NIM_TRUE;}
          else {
            X60Qx_219 = (t_6.kind_0 == IL64(7));}
          if (X60Qx_219){
            Token_0_tok9e79hf X60Qtmp_5 = tok_0_parq39nt2((&(*ps_5)), ((NI64)(i_7 - IL64(1))));
            X60Qx_65 = (t_6.line_0 == X60Qtmp_5.line_0);
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_5));}
          else {
            X60Qx_65 = NIM_FALSE;}
          if (X60Qx_65){
            X60Qx_64 = (t_6.col_0 == endCol_0);}
          else {
            X60Qx_64 = NIM_FALSE;}
          if (X60Qx_64){
            endCol_0 = t_6.col_0;
            inc_1_Irn1g7r1_aif7a4qfr((&i_7));}
          else {
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_6));
            goto whileStmtLabel_0;}}}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_6));}}
  whileStmtLabel_0: ;
  result_6 = i_7;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_0));
  return result_6;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_0));
  return result_6;}
void emitName_0_parq39nt2(Parser_0_parq39nt2* ps_6, Builder_0_nifjp9lau1* b_1, Token_0_tok9e79hf* t_0, NI32 pl_1, NI32 pc_1){
  if ((*t_0).quoted_0){
    addTree_0_nifjp9lau1(b_1, (string_0_sysvq0asl){
      .bytes_0 = 28259048431644934ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_6)), b_1, (*t_0).line_0, (*t_0).col_0, pl_1, pc_1, NIM_FALSE);
    {
      NI64 X60Qlf_0 = IL64(0);
      NI64 X60Qlf_1 = len_3_Ixq6taz_aif7a4qfr((*t_0).parts_0);
      NI64 X60Qlf_2 = X60Qlf_0;
      {
        while (X60Qlf_2 < X60Qlf_1){
          {
            string_0_sysvq0asl* X60Qx_221 = getQ_7_Ir6d0tw_aif7a4qfr((*t_0).parts_0, X60Qlf_2);
            addIdent_0_nifjp9lau1(b_1, (*X60Qx_221));
            NI32 X60Qx_1;
            NI64 X60Qx_222 = len_3_I0v1j8d_parq39nt2((*t_0).partCols_0);
            if (X60Qlf_2 < X60Qx_222){
              NI32* X60Qx_223 = getQ_7_Ir8kccm_parq39nt2((*t_0).partCols_0, X60Qlf_2);
              X60Qx_1 = (*X60Qx_223);}
            else {
              X60Qx_1 = (*t_0).col_0;}
            NI32 X60Qii_2 = X60Qx_1;
            emitInfo_0_parq39nt2((&(*ps_6)), b_1, (*t_0).line_0, X60Qii_2, (*t_0).line_0, (*t_0).col_0, NIM_FALSE);}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_2));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;
    endTree_0_nifjp9lau1(b_1);}
  else {
    addIdent_0_nifjp9lau1(b_1, (*t_0).s_0);
    emitInfo_0_parq39nt2((&(*ps_6)), b_1, (*t_0).line_0, (*t_0).col_0, pl_1, pc_1, NIM_FALSE);}}
NB8 isBinaryOp_0_parq39nt2(Token_0_tok9e79hf* t_1){
  NB8 result_7;
  if ((*t_1).kind_0 == IL64(2)){
    {
      openArray_0_Ig73pnk_osalirkw71 X60Qlf_3 = toOpenArray_0_Ipj8xjx1_parq39nt2((&BinaryKeywords_0_parq39nt2));
      NI64 X60Qlf_4 = IL64(0);
      {
        while (NIM_TRUE){
          NI64 X60Qx_224 = len_6_Igv2wyu1_osalirkw71(X60Qlf_3);
          if (X60Qlf_4 < X60Qx_224){
            {
              string_0_sysvq0asl* X60Qii_2 = getQ_10_Ik9hgkq1_osalirkw71(X60Qlf_3, X60Qlf_4);
              NB8 X60Qx_225 = eqQ_20_sysvq0asl((*X60Qii_2), (*t_1).s_0);
              if (X60Qx_225){
                return NIM_TRUE;}}
            inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_4));}
          else {
            break;}}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;
    return NIM_FALSE;}
  else {
    if ((*t_1).kind_0 == IL64(9)){
      NB8 X60Qx_226;
      NB8 X60Qx_227 = eqQ_20_sysvq0asl((*t_1).s_0, (string_0_sysvq0asl){
        .bytes_0 = 15617ull, .more_0 = NIM_NIL}
      );
      if ((!X60Qx_227)){
        NB8 X60Qx_228 = eqQ_20_sysvq0asl((*t_1).s_0, (string_0_sysvq0asl){
          .bytes_0 = 11777ull, .more_0 = NIM_NIL}
        );
        X60Qx_226 = (!X60Qx_228);}
      else {
        X60Qx_226 = NIM_FALSE;}
      result_7 = X60Qx_226;
      return result_7;}
    else {
      return NIM_FALSE;}}
  return result_7;}
NI64 precedenceOf_0_parq39nt2(Token_0_tok9e79hf* t_2){
  NI64 result_8;
  if ((*t_2).kind_0 == IL64(2)){
    string_0_sysvq0asl X60Qtc_0 = (*t_2).s_0;
    NB8 X60Qtc_4 = nimStrAtLe_0_sysvq0asl(X60Qtc_0, IL64(0), (NC8)'m');
    if (X60Qtc_4){
      NB8 X60Qtc_5 = nimStrAtLe_0_sysvq0asl(X60Qtc_0, IL64(0), (NC8)'d');
      if (X60Qtc_5){
        if (equalStrings_0_sysvq0asl(X60Qtc_0, (string_0_sysvq0asl){
          .bytes_0 = 1986618371ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_1;}
        else if (equalStrings_0_sysvq0asl(X60Qtc_0, (string_0_sysvq0asl){
          .bytes_0 = 1684955395ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_2;}}
      else {
        if (equalStrings_0_sysvq0asl(X60Qtc_0, (string_0_sysvq0asl){
          .bytes_0 = 1685024003ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_1;}}}
    else {
      NB8 X60Qtc_6 = nimStrAtLe_0_sysvq0asl(X60Qtc_0, IL64(1), (NC8)'h');
      if (X60Qtc_6){
        if (equalStrings_0_sysvq0asl(X60Qtc_0, (string_0_sysvq0asl){
          .bytes_0 = 1818784515ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_1;}
        else if (equalStrings_0_sysvq0asl(X60Qtc_0, (string_0_sysvq0asl){
          .bytes_0 = 1919447811ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_1;}}
      else {
        if (equalStrings_0_sysvq0asl(X60Qtc_0, (string_0_sysvq0asl){
          .bytes_0 = 7499522ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_3;}
        else if (equalStrings_0_sysvq0asl(X60Qtc_0, (string_0_sysvq0asl){
          .bytes_0 = 1919907843ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_3;}}}
    goto X60Qsc_8;
    X60Qsc_1: ;
    return IL64(9);
    goto X60Qsc_7;
    X60Qsc_2: ;
    return IL64(4);
    goto X60Qsc_7;
    X60Qsc_3: ;
    return IL64(3);
    goto X60Qsc_7;
    X60Qsc_8: ;
    return IL64(5);
    X60Qsc_7: ;}
  NB8 X60Qx_229 = eqQ_20_sysvq0asl((*t_2).s_0, (string_0_sysvq0asl){
    .bytes_0 = 3026434ull, .more_0 = NIM_NIL}
  );
  if (X60Qx_229){
    return IL64(6);}
  NI64 X60Qx_230 = len_4_sysvq0asl((*t_2).s_0);
  if (X60Qx_230 == IL64(0)){
    return IL64(2);}
  NB8 X60Qx_231;
  NB8 X60Qx_232;
  NI64 X60Qx_233 = len_4_sysvq0asl((*t_2).s_0);
  if (IL64(1) < X60Qx_233){
    NI64 X60Qx_234 = len_4_sysvq0asl((*t_2).s_0);
    NC8 X60Qx_235 = getQ_9_sysvq0asl((*t_2).s_0, ((NI64)(X60Qx_234 - IL64(1))));
    X60Qx_232 = (X60Qx_235 == (NC8)'>');}
  else {
    X60Qx_232 = NIM_FALSE;}
  if (X60Qx_232){
    NB8 X60Qx_236;
    NB8 X60Qx_237;
    NI64 X60Qx_238 = len_4_sysvq0asl((*t_2).s_0);
    NC8 X60Qx_239 = getQ_9_sysvq0asl((*t_2).s_0, ((NI64)(X60Qx_238 - IL64(2))));
    if (X60Qx_239 == (NC8)'-'){
      X60Qx_237 = NIM_TRUE;}
    else {
      NI64 X60Qx_240 = len_4_sysvq0asl((*t_2).s_0);
      NC8 X60Qx_241 = getQ_9_sysvq0asl((*t_2).s_0, ((NI64)(X60Qx_240 - IL64(2))));
      X60Qx_237 = (X60Qx_241 == (NC8)'~');}
    if (X60Qx_237){
      X60Qx_236 = NIM_TRUE;}
    else {
      NI64 X60Qx_242 = len_4_sysvq0asl((*t_2).s_0);
      NC8 X60Qx_243 = getQ_9_sysvq0asl((*t_2).s_0, ((NI64)(X60Qx_242 - IL64(2))));
      X60Qx_236 = (X60Qx_243 == (NC8)'=');}
    X60Qx_231 = X60Qx_236;}
  else {
    X60Qx_231 = NIM_FALSE;}
  if (X60Qx_231){
    return IL64(0);}
  NC8 c_2 = getQ_9_sysvq0asl((*t_2).s_0, IL64(0));
  NI64 X60Qx_244 = len_4_sysvq0asl((*t_2).s_0);
  NC8 X60Qx_245 = getQ_9_sysvq0asl((*t_2).s_0, ((NI64)(X60Qx_244 - IL64(1))));
  NB8 asgn_0 = (X60Qx_245 == (NC8)'=');
  switch (c_2){
    case (NC8)'$':
    case (NC8)'^':
    {
      NI64 X60Qx_2;
      if (asgn_0){
        X60Qx_2 = IL64(1);}
      else {
        X60Qx_2 = IL64(10);}
      return X60Qx_2;}
    break;
    case (NC8)'*':
    case (NC8)'/':
    case (NC8)'%':
    case (NC8)'\\':
    {
      NI64 X60Qx_3;
      if (asgn_0){
        X60Qx_3 = IL64(1);}
      else {
        X60Qx_3 = IL64(9);}
      return X60Qx_3;}
    break;
    case (NC8)'~':
    {
      return IL64(8);}
    break;
    case (NC8)'+':
    case (NC8)'-':
    case (NC8)'|':
    {
      NI64 X60Qx_4;
      if (asgn_0){
        X60Qx_4 = IL64(1);}
      else {
        X60Qx_4 = IL64(8);}
      return X60Qx_4;}
    break;
    case (NC8)'&':
    {
      NI64 X60Qx_5;
      if (asgn_0){
        X60Qx_5 = IL64(1);}
      else {
        X60Qx_5 = IL64(7);}
      return X60Qx_5;}
    break;
    case (NC8)'=':
    case (NC8)'<':
    case (NC8)'>':
    case (NC8)'!':
    {
      return IL64(5);}
    break;
    case (NC8)'.':
    {
      NI64 X60Qx_6;
      if (asgn_0){
        X60Qx_6 = IL64(1);}
      else {
        X60Qx_6 = IL64(6);}
      return X60Qx_6;}
    break;
    case (NC8)'\?':
    {
      return IL64(2);}
    break;
    default:
    {
      NI64 X60Qx_7;
      if (asgn_0){
        X60Qx_7 = IL64(1);}
      else {
        X60Qx_7 = IL64(2);}
      return X60Qx_7;}
    break;}
  return result_8;}
NB8 startsExpr_0_parq39nt2(Token_0_tok9e79hf* t_3){
  NB8 result_9;
  NB8 X60Qx_8;
  switch ((*t_3).kind_0){
    case IL64(1):
    case IL64(2):
    case IL64(3):
    case IL64(4):
    case IL64(5):
    case IL64(6):
    case IL64(7):
    case IL64(8):
    case IL64(10):
    case IL64(12):
    case IL64(14):
    case IL64(9):
    {
      X60Qx_8 = NIM_TRUE;}
    break;
    default:
    {
      X60Qx_8 = NIM_FALSE;}
    break;}
  result_9 = X60Qx_8;
  return result_9;}
NB8 continuesLine_0_parq39nt2(Token_0_tok9e79hf* prev_0){
  NB8 result_10;
  NB8 X60Qx_9;
  switch ((*prev_0).kind_0){
    case IL64(16):
    case IL64(9):
    case IL64(19):
    {
      X60Qx_9 = NIM_TRUE;}
    break;
    case IL64(2):
    {
      NB8 X60Qx_246 = isBinaryOp_0_parq39nt2((&(*prev_0)));
      X60Qx_9 = X60Qx_246;}
    break;
    default:
    {
      X60Qx_9 = NIM_FALSE;}
    break;}
  result_10 = X60Qx_9;
  return result_10;}
NI64 lineEnd_0_parq39nt2(Parser_0_parq39nt2* ps_7, NI64 startIdx_0){
  NI64 result_11;
  NI64 i_11 = startIdx_0;
  NI64 depth_0 = IL64(0);
  {
    while (NIM_TRUE){
      Token_0_tok9e79hf X60Qtmp_6 = tok_0_parq39nt2((&(*ps_7)), i_11);
      if ((!(X60Qtmp_6.kind_0 == IL64(0)))){
        Token_0_tok9e79hf t_7 = tok_0_parq39nt2((&(*ps_7)), i_11);
        NB8 X60Qx_247;
        if (depth_0 == IL64(0)){
          X60Qx_247 = (startIdx_0 < i_11);}
        else {
          X60Qx_247 = NIM_FALSE;}
        if (X60Qx_247){
          Token_0_tok9e79hf prev_3 = tok_0_parq39nt2((&(*ps_7)), ((NI64)(i_11 - IL64(1))));
          NB8 X60Qx_248;
          if ((!(t_7.line_0 == prev_3.line_0))){
            NB8 X60Qx_249 = continuesLine_0_parq39nt2((&prev_3));
            X60Qx_248 = (!X60Qx_249);}
          else {
            X60Qx_248 = NIM_FALSE;}
          if (X60Qx_248){
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_3));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_7));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_6));
            goto whileStmtLabel_0;}
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_3));}
        NB8 X60Qx_250 = isOpenBracket_0_parq39nt2(t_7.kind_0);
        if (X60Qx_250){
          inc_1_Irn1g7r1_aif7a4qfr((&depth_0));}
        else {
          NB8 X60Qx_251 = isCloseBracket_0_parq39nt2(t_7.kind_0);
          if (X60Qx_251){
            if (IL64(0) < depth_0){
              dec_1_I2mwrey1_envto7w6l1((&depth_0));}}}
        inc_1_Irn1g7r1_aif7a4qfr((&i_11));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_7));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_6));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_6));}}
  whileStmtLabel_0: ;
  result_11 = i_11;
  return result_11;}
NI64 matchClose_0_parq39nt2(Parser_0_parq39nt2* ps_8, NI64 openIdx_0){
  NI64 result_12;
  NI64 depth_1 = IL64(0);
  NI64 i_12 = openIdx_0;
  {
    while (NIM_TRUE){
      Token_0_tok9e79hf X60Qtmp_7 = tok_0_parq39nt2((&(*ps_8)), i_12);
      if ((!(X60Qtmp_7.kind_0 == IL64(0)))){
        Token_0_tok9e79hf X60Qtmp_8 = tok_0_parq39nt2((&(*ps_8)), i_12);
        TokKind_0_tok9e79hf k_4 = X60Qtmp_8.kind_0;
        NB8 X60Qx_252 = isOpenBracket_0_parq39nt2(k_4);
        if (X60Qx_252){
          inc_1_Irn1g7r1_aif7a4qfr((&depth_1));}
        else {
          NB8 X60Qx_253 = isCloseBracket_0_parq39nt2(k_4);
          if (X60Qx_253){
            dec_1_I2mwrey1_envto7w6l1((&depth_1));
            if (depth_1 == IL64(0)){
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_8));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_7));
              return i_12;}}}
        inc_1_Irn1g7r1_aif7a4qfr((&i_12));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_8));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_7));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_7));}}
  whileStmtLabel_0: ;
  result_12 = i_12;
  return result_12;}
NI32 lineIndentOf_0_parq39nt2(Parser_0_parq39nt2* ps_9, NI64 idx_0){
  NI32 result_13;
  NI64 i_13 = idx_0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_66;
      if (IL64(0) < i_13){
        Token_0_tok9e79hf X60Qtmp_9 = tok_0_parq39nt2((&(*ps_9)), i_13);
        X60Qx_66 = (X60Qtmp_9.indent_0 < ((NI32)IL64(0)));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_9));}
      else {
        X60Qx_66 = NIM_FALSE;}
      if (X60Qx_66){
        dec_1_I2mwrey1_envto7w6l1((&i_13));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI32 X60Qx_10;
  Token_0_tok9e79hf X60Qtmp_10 = tok_0_parq39nt2((&(*ps_9)), i_13);
  if (((NI32)IL64(0)) <= X60Qtmp_10.indent_0){
    Token_0_tok9e79hf X60Qtmp_11 = tok_0_parq39nt2((&(*ps_9)), i_13);
    X60Qx_10 = X60Qtmp_11.indent_0;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_11));}
  else {
    Token_0_tok9e79hf X60Qtmp_12 = tok_0_parq39nt2((&(*ps_9)), idx_0);
    X60Qx_10 = X60Qtmp_12.col_0;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_12));}
  result_13 = X60Qx_10;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_10));
  return result_13;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_10));
  return result_13;}
NI64 matchOpen_0_parq39nt2(Parser_0_parq39nt2* ps_10, NI64 closeIdx_0){
  NI64 result_14;
  NI64 depth_2 = IL64(0);
  NI64 i_14 = closeIdx_0;
  {
    while (IL64(0) <= i_14){
      Token_0_tok9e79hf X60Qtmp_13 = tok_0_parq39nt2((&(*ps_10)), i_14);
      TokKind_0_tok9e79hf k_5 = X60Qtmp_13.kind_0;
      NB8 X60Qx_254 = isCloseBracket_0_parq39nt2(k_5);
      if (X60Qx_254){
        inc_1_Irn1g7r1_aif7a4qfr((&depth_2));}
      else {
        NB8 X60Qx_255 = isOpenBracket_0_parq39nt2(k_5);
        if (X60Qx_255){
          dec_1_I2mwrey1_envto7w6l1((&depth_2));
          if (depth_2 == IL64(0)){
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_13));
            return i_14;}}}
      dec_1_I2mwrey1_envto7w6l1((&i_14));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_13));}}
  whileStmtLabel_0: ;
  result_14 = closeIdx_0;
  return result_14;}
NI64 findSplit_0_parq39nt2(Parser_0_parq39nt2* ps_11, NI64 lo_2, NI64 hi_2){
  NI64 result_15;
  NI64 depth_3 = IL64(0);
  NI64 bestPrec_0 = IL64(1000);
  result_15 = IL64(-1);
  NI64 i_15 = lo_2;
  {
    while (i_15 < hi_2){
      Token_0_tok9e79hf t_8 = tok_0_parq39nt2((&(*ps_11)), i_15);
      NB8 X60Qx_256 = isOpenBracket_0_parq39nt2(t_8.kind_0);
      if (X60Qx_256){
        inc_1_Irn1g7r1_aif7a4qfr((&depth_3));}
      else {
        NB8 X60Qx_257 = isCloseBracket_0_parq39nt2(t_8.kind_0);
        if (X60Qx_257){
          if (IL64(0) < depth_3){
            dec_1_I2mwrey1_envto7w6l1((&depth_3));}}
        else {
          NB8 X60Qx_258;
          NB8 X60Qx_259;
          NB8 X60Qx_260;
          if (depth_3 == IL64(0)){
            X60Qx_260 = (lo_2 < i_15);}
          else {
            X60Qx_260 = NIM_FALSE;}
          if (X60Qx_260){
            NB8 X60Qx_261 = isBinaryOp_0_parq39nt2((&t_8));
            X60Qx_259 = X60Qx_261;}
          else {
            X60Qx_259 = NIM_FALSE;}
          if (X60Qx_259){
            NB8 X60Qx_262 = opIsInfix_0_parq39nt2((&(*ps_11)), i_15, lo_2);
            X60Qx_258 = X60Qx_262;}
          else {
            X60Qx_258 = NIM_FALSE;}
          if (X60Qx_258){
            NI64 p_0 = precedenceOf_0_parq39nt2((&t_8));
            if (p_0 <= bestPrec_0){
              bestPrec_0 = p_0;
              result_15 = i_15;}}}}
      inc_1_Irn1g7r1_aif7a4qfr((&i_15));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_8));}}
  whileStmtLabel_0: ;
  return result_15;}
NI64 findAssign_0_parq39nt2(Parser_0_parq39nt2* ps_12, NI64 lo_3, NI64 hi_3){
  NI64 result_16;
  NI64 depth_4 = IL64(0);
  result_16 = IL64(-1);
  NI64 i_16 = lo_3;
  {
    while (i_16 < hi_3){
      Token_0_tok9e79hf t_9 = tok_0_parq39nt2((&(*ps_12)), i_16);
      NB8 X60Qx_263 = isOpenBracket_0_parq39nt2(t_9.kind_0);
      if (X60Qx_263){
        inc_1_Irn1g7r1_aif7a4qfr((&depth_4));}
      else {
        NB8 X60Qx_264 = isCloseBracket_0_parq39nt2(t_9.kind_0);
        if (X60Qx_264){
          if (IL64(0) < depth_4){
            dec_1_I2mwrey1_envto7w6l1((&depth_4));}}
        else {
          NB8 X60Qx_265;
          NB8 X60Qx_266;
          if (depth_4 == IL64(0)){
            X60Qx_266 = (t_9.kind_0 == IL64(9));}
          else {
            X60Qx_266 = NIM_FALSE;}
          if (X60Qx_266){
            NB8 X60Qx_267 = eqQ_20_sysvq0asl(t_9.s_0, (string_0_sysvq0asl){
              .bytes_0 = 15617ull, .more_0 = NIM_NIL}
            );
            X60Qx_265 = X60Qx_267;}
          else {
            X60Qx_265 = NIM_FALSE;}
          if (X60Qx_265){
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_9));
            return i_16;}}}
      inc_1_Irn1g7r1_aif7a4qfr((&i_16));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_9));}}
  whileStmtLabel_0: ;
  return result_16;}
seq_0_Iotb7mc_mat7cnfv21 splitArgs_0_parq39nt2(Parser_0_parq39nt2* ps_13, NI64 lo_4, NI64 hi_4){
  seq_0_Iotb7mc_mat7cnfv21 result_17;
  eQwasMoved_1_Ia0kll01_mat7cnfv21((&result_17));
  eQdestroy_1_Iez2nr5_mat7cnfv21(result_17);
  seq_0_Iotb7mc_mat7cnfv21 X60Qx_268 = newSeqUninit_0_I7whkjh1_mat7cnfv21(IL64(0));
  result_17 = X60Qx_268;
  if (hi_4 <= lo_4){
    return result_17;}
  add_0_I8fahwb_parq39nt2((&result_17), lo_4);
  NI64 depth_5 = IL64(0);
  NI64 i_17 = lo_4;
  {
    while (i_17 < hi_4){
      Token_0_tok9e79hf t_10 = tok_0_parq39nt2((&(*ps_13)), i_17);
      NB8 X60Qx_269 = isOpenBracket_0_parq39nt2(t_10.kind_0);
      if (X60Qx_269){
        inc_1_Irn1g7r1_aif7a4qfr((&depth_5));}
      else {
        NB8 X60Qx_270 = isCloseBracket_0_parq39nt2(t_10.kind_0);
        if (X60Qx_270){
          if (IL64(0) < depth_5){
            dec_1_I2mwrey1_envto7w6l1((&depth_5));}}
        else {
          NB8 X60Qx_271;
          if (depth_5 == IL64(0)){
            X60Qx_271 = (t_10.kind_0 == IL64(16));}
          else {
            X60Qx_271 = NIM_FALSE;}
          if (X60Qx_271){
            if (((NI64)(i_17 + IL64(1))) < hi_4){
              add_0_I8fahwb_parq39nt2((&result_17), ((NI64)(i_17 + IL64(1))));}}}}
      inc_1_Irn1g7r1_aif7a4qfr((&i_17));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_10));}}
  whileStmtLabel_0: ;
  return result_17;}
NI64 depth0Colon_0_parq39nt2(Parser_0_parq39nt2* ps_26, NI64 lo_10, NI64 hi_10){
  NI64 result_18;
  NI64 depth_6 = IL64(0);
  result_18 = IL64(-1);
  NI64 i_18 = lo_10;
  {
    while (i_18 < hi_10){
      Token_0_tok9e79hf t_11 = tok_0_parq39nt2((&(*ps_26)), i_18);
      NB8 X60Qx_272 = isOpenBracket_0_parq39nt2(t_11.kind_0);
      if (X60Qx_272){
        inc_1_Irn1g7r1_aif7a4qfr((&depth_6));}
      else {
        NB8 X60Qx_273 = isCloseBracket_0_parq39nt2(t_11.kind_0);
        if (X60Qx_273){
          if (IL64(0) < depth_6){
            dec_1_I2mwrey1_envto7w6l1((&depth_6));}}
        else {
          NB8 X60Qx_274;
          if (depth_6 == IL64(0)){
            X60Qx_274 = (t_11.kind_0 == IL64(18));}
          else {
            X60Qx_274 = NIM_FALSE;}
          if (X60Qx_274){
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_11));
            return i_18;}}}
      inc_1_Irn1g7r1_aif7a4qfr((&i_18));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_11));}}
  whileStmtLabel_0: ;
  return result_18;}
NI64 findPostfix_0_parq39nt2(Parser_0_parq39nt2* ps_27, NI64 lo_11, NI64 hi_11, NI64* kind_0){
  NI64 result_19;
  NI64 depth_7 = IL64(0);
  result_19 = IL64(-1);
  (*kind_0) = IL64(0);
  NI64 i_19 = lo_11;
  {
    while (i_19 < hi_11){
      Token_0_tok9e79hf t_12 = tok_0_parq39nt2((&(*ps_27)), i_19);
      NB8 X60Qx_275;
      if (depth_7 == IL64(0)){
        X60Qx_275 = (lo_11 < i_19);}
      else {
        X60Qx_275 = NIM_FALSE;}
      if (X60Qx_275){
        switch (t_12.kind_0){
          case IL64(19):
          {
            result_19 = i_19;
            (*kind_0) = ((NI64)IL64(1));}
          break;
          case IL64(12):
          {
            result_19 = i_19;
            (*kind_0) = ((NI64)IL64(2));}
          break;
          case IL64(14):
          {
            result_19 = i_19;
            (*kind_0) = ((NI64)IL64(3));}
          break;
          case IL64(10):
          {
            result_19 = i_19;
            (*kind_0) = ((NI64)IL64(4));}
          break;
          default:
          {
            }
          break;}}
      NB8 X60Qx_276 = isOpenBracket_0_parq39nt2(t_12.kind_0);
      if (X60Qx_276){
        inc_1_Irn1g7r1_aif7a4qfr((&depth_7));}
      else {
        NB8 X60Qx_277 = isCloseBracket_0_parq39nt2(t_12.kind_0);
        if (X60Qx_277){
          if (IL64(0) < depth_7){
            dec_1_I2mwrey1_envto7w6l1((&depth_7));}}}
      inc_1_Irn1g7r1_aif7a4qfr((&i_19));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_12));}}
  whileStmtLabel_0: ;
  return result_19;}
Token_0_tok9e79hf calleeAnchor_0_parq39nt2(Parser_0_parq39nt2* ps_28, NI64 lo_12, NI64 hi_12){
  Token_0_tok9e79hf result_20;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_20));
  NI64 pk_0 = IL64(0);
  NI64 k_6 = findPostfix_0_parq39nt2((&(*ps_28)), lo_12, hi_12, (&pk_0));
  Token_0_tok9e79hf X60Qx_11;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_11));
  if (IL64(0) <= k_6){
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_11));
    Token_0_tok9e79hf X60Qx_278 = tok_0_parq39nt2((&(*ps_28)), k_6);
    X60Qx_11 = X60Qx_278;}
  else {
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_11));
    Token_0_tok9e79hf X60Qx_279 = tok_0_parq39nt2((&(*ps_28)), lo_12);
    X60Qx_11 = X60Qx_279;}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&result_20));
  result_20 = X60Qx_11;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_11));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_11));
  return result_20;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_11));
  return result_20;}
void parseArg_0_parq39nt2(Parser_0_parq39nt2* ps_29, Builder_0_nifjp9lau1* b_13, NI32 lo_13, NI32 hi_13, NI32 pl_13, NI32 pc_13){
  Token_0_tok9e79hf head_0 = tok_0_parq39nt2((&(*ps_29)), ((NI64)lo_13));
  NB8 X60Qx_280;
  if (head_0.kind_0 == IL64(2)){
    NB8 X60Qx_281;
    NB8 X60Qx_282;
    NB8 X60Qx_283;
    NB8 X60Qx_284;
    NB8 X60Qx_285 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
      .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
    );
    if (X60Qx_285){
      X60Qx_284 = NIM_TRUE;}
    else {
      NB8 X60Qx_286 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
        .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
      );
      X60Qx_284 = X60Qx_286;}
    if (X60Qx_284){
      X60Qx_283 = NIM_TRUE;}
    else {
      NB8 X60Qx_287 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
        .bytes_0 = 427071533060ull, .more_0 = NIM_NIL}
      );
      X60Qx_283 = X60Qx_287;}
    if (X60Qx_283){
      X60Qx_282 = NIM_TRUE;}
    else {
      NB8 X60Qx_288 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
        .bytes_0 = 427054949892ull, .more_0 = NIM_NIL}
      );
      X60Qx_282 = X60Qx_288;}
    if (X60Qx_282){
      X60Qx_281 = NIM_TRUE;}
    else {
      NB8 X60Qx_289 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
        .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
      );
      X60Qx_281 = X60Qx_289;}
    X60Qx_280 = X60Qx_281;}
  else {
    X60Qx_280 = NIM_FALSE;}
  NB8 guardKw_0 = X60Qx_280;
  if ((!guardKw_0)){
    NI64 ci_0 = depth0Colon_0_parq39nt2((&(*ps_29)), ((NI64)lo_13), ((NI64)hi_13));
    if (IL64(0) <= ci_0){
      Token_0_tok9e79hf op_0 = tok_0_parq39nt2((&(*ps_29)), ci_0);
      addTree_0_nifjp9lau1(b_13, (string_0_sysvq0asl){
        .bytes_0 = 7760642ull, .more_0 = NIM_NIL}
      );
      emitInfo_0_parq39nt2((&(*ps_29)), b_13, op_0.line_0, op_0.col_0, pl_13, pc_13, NIM_FALSE);
      parseExprRange_1_parq39nt2(ps_29, b_13, lo_13, ((NI32)ci_0), op_0.line_0, op_0.col_0);
      parseExprRange_1_parq39nt2(ps_29, b_13, ((NI32)(((NI32)ci_0) + ((NI32)IL64(1)))), hi_13, op_0.line_0, op_0.col_0);
      endTree_0_nifjp9lau1(b_13);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&op_0));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_0));
      return;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&op_0));}
    NI64 ei_0 = findAssign_0_parq39nt2((&(*ps_29)), ((NI64)lo_13), ((NI64)hi_13));
    if (IL64(0) <= ei_0){
      Token_0_tok9e79hf op_1 = tok_0_parq39nt2((&(*ps_29)), ei_0);
      addTree_0_nifjp9lau1(b_13, (string_0_sysvq0asl){
        .bytes_0 = 7763458ull, .more_0 = NIM_NIL}
      );
      emitInfo_0_parq39nt2((&(*ps_29)), b_13, op_1.line_0, op_1.col_0, pl_13, pc_13, NIM_FALSE);
      parseExprRange_1_parq39nt2(ps_29, b_13, lo_13, ((NI32)ei_0), op_1.line_0, op_1.col_0);
      parseExprRange_1_parq39nt2(ps_29, b_13, ((NI32)(((NI32)ei_0) + ((NI32)IL64(1)))), hi_13, op_1.line_0, op_1.col_0);
      endTree_0_nifjp9lau1(b_13);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&op_1));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_0));
      return;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&op_1));}}
  NB8 X60Qx_290;
  NB8 X60Qx_291;
  if (head_0.kind_0 == IL64(2)){
    X60Qx_291 = (((NI64)(((NI64)lo_13) + IL64(1))) < ((NI64)hi_13));}
  else {
    X60Qx_291 = NIM_FALSE;}
  if (X60Qx_291){
    NB8 X60Qx_292;
    NB8 X60Qx_293;
    NB8 X60Qx_294;
    NB8 X60Qx_295 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
      .bytes_0 = 1717924355ull, .more_0 = NIM_NIL}
    );
    if (X60Qx_295){
      X60Qx_294 = NIM_TRUE;}
    else {
      NB8 X60Qx_296 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
        .bytes_0 = 1920233475ull, .more_0 = NIM_NIL}
      );
      X60Qx_294 = X60Qx_296;}
    if (X60Qx_294){
      X60Qx_293 = NIM_TRUE;}
    else {
      NB8 X60Qx_297 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
        .bytes_0 = 1918989827ull, .more_0 = NIM_NIL}
      );
      X60Qx_293 = X60Qx_297;}
    if (X60Qx_293){
      X60Qx_292 = NIM_TRUE;}
    else {
      NB8 X60Qx_298 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
        .bytes_0 = 1953853187ull, .more_0 = NIM_NIL}
      );
      X60Qx_292 = X60Qx_298;}
    X60Qx_290 = X60Qx_292;}
  else {
    X60Qx_290 = NIM_FALSE;}
  if (X60Qx_290){
    parseTypeRange_1_parq39nt2(ps_29, b_13, lo_13, hi_13, pl_13, pc_13);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_0));
    return;}
  NB8 X60Qx_67;
  NB8 X60Qx_299;
  NB8 X60Qx_300;
  if (head_0.kind_0 == IL64(2)){
    NB8 X60Qx_301 = eqQ_20_sysvq0asl(head_0.s_0, (string_0_sysvq0asl){
      .bytes_0 = 111516417618949ull, .more_0 = NIM_NIL}
    );
    X60Qx_300 = X60Qx_301;}
  else {
    X60Qx_300 = NIM_FALSE;}
  if (X60Qx_300){
    X60Qx_299 = (((NI64)(((NI64)lo_13) + IL64(1))) < ((NI64)hi_13));}
  else {
    X60Qx_299 = NIM_FALSE;}
  if (X60Qx_299){
    Token_0_tok9e79hf X60Qtmp_14 = tok_0_parq39nt2((&(*ps_29)), ((NI64)(((NI64)lo_13) + IL64(1))));
    X60Qx_67 = (X60Qtmp_14.kind_0 == IL64(12));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_14));}
  else {
    X60Qx_67 = NIM_FALSE;}
  if (X60Qx_67){
    parseTypeRange_1_parq39nt2(ps_29, b_13, lo_13, hi_13, pl_13, pc_13);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_0));
    return;}
  parseExprRange_1_parq39nt2(ps_29, b_13, lo_13, hi_13, pl_13, pc_13);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_0));}
void parseArgList_0_parq39nt2(Parser_0_parq39nt2* ps_30, Builder_0_nifjp9lau1* b_14, NI32 lo_14, NI32 hi_14, NI32 pl_14, NI32 pc_14){
  seq_0_Iotb7mc_mat7cnfv21 starts_0 = splitArgs_0_parq39nt2((&(*ps_30)), ((NI64)lo_14), ((NI64)hi_14));
  {
    NI64 X60Qlf_5 = IL64(0);
    NI64 X60Qlf_6 = len_3_I12oavy1_parq39nt2(starts_0);
    NI64 X60Qlf_7 = X60Qlf_5;
    {
      while (X60Qlf_7 < X60Qlf_6){
        {
          NI64* X60Qx_302 = getQ_7_Ite3z0o_parq39nt2(starts_0, X60Qlf_7);
          NI64 X60Qii_2 = (*X60Qx_302);
          NI64 X60Qx_12;
          NI64 X60Qx_303 = len_3_I12oavy1_parq39nt2(starts_0);
          if (((NI64)(X60Qlf_7 + IL64(1))) < X60Qx_303){
            NI64* X60Qx_304 = getQ_7_Ite3z0o_parq39nt2(starts_0, ((NI64)(X60Qlf_7 + IL64(1))));
            X60Qx_12 = ((NI64)((*X60Qx_304) - IL64(1)));}
          else {
            X60Qx_12 = ((NI64)hi_14);}
          NI64 X60Qii_3 = X60Qx_12;
          if (X60Qii_2 < X60Qii_3){
            parseArg_0_parq39nt2(ps_30, b_14, ((NI32)X60Qii_2), ((NI32)X60Qii_3), pl_14, pc_14);}}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_7));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  eQdestroy_1_Iez2nr5_mat7cnfv21(starts_0);}
void parseBareResultBody_0_parq39nt2(Parser_0_parq39nt2* ps_31, Builder_0_nifjp9lau1* b_15, NI32 lo_15, NI32 hi_15, NI32 pl_15, NI32 pc_15){
  Token_0_tok9e79hf head_1 = tok_0_parq39nt2((&(*ps_31)), ((NI64)lo_15));
  NI64 ce_0 = cmdCalleeEnd_0_parq39nt2((&(*ps_31)), ((NI64)lo_15), ((NI64)hi_15));
  NB8 X60Qx_305;
  NB8 X60Qx_306;
  if (head_1.kind_0 == IL64(1)){
    X60Qx_306 = (ce_0 < ((NI64)hi_15));}
  else {
    X60Qx_306 = NIM_FALSE;}
  if (X60Qx_306){
    NB8 X60Qx_307 = startsArg_0_parq39nt2((&(*ps_31)), ce_0, ((NI64)hi_15));
    X60Qx_305 = X60Qx_307;}
  else {
    X60Qx_305 = NIM_FALSE;}
  if (X60Qx_305){
    parseCommand_1_parq39nt2(ps_31, b_15, lo_15, hi_15, pl_15, pc_15);}
  else {
    parseExprRange_1_parq39nt2(ps_31, b_15, lo_15, hi_15, pl_15, pc_15);}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_1));}
void parseIfExpr_0_parq39nt2(Parser_0_parq39nt2* ps_32, Builder_0_nifjp9lau1* b_16, NI32 lo_16, NI32 hi_16, NI32 pl_16, NI32 pc_16, NB8 bare_0, string_0_sysvq0asl tag_1){
  Token_0_tok9e79hf ifTok_0 = tok_0_parq39nt2((&(*ps_32)), ((NI64)lo_16));
  addTree_0_nifjp9lau1(b_16, tag_1);
  emitInfo_0_parq39nt2((&(*ps_32)), b_16, ifTok_0.line_0, ifTok_0.col_0, pl_16, pc_16, NIM_FALSE);
  NI64 i_21 = ((NI64)lo_16);
  {
    while (i_21 < ((NI64)hi_16)){
      Token_0_tok9e79hf kw_0 = tok_0_parq39nt2((&(*ps_32)), i_21);
      NB8 X60Qx_308;
      if (kw_0.kind_0 == IL64(2)){
        NB8 X60Qx_309 = eqQ_20_sysvq0asl(kw_0.s_0, (string_0_sysvq0asl){
          .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
        );
        X60Qx_308 = X60Qx_309;}
      else {
        X60Qx_308 = NIM_FALSE;}
      NB8 isElse_0 = X60Qx_308;
      NI64 depth_8 = IL64(0);
      NI64 colon_0 = IL64(-1);
      NI64 nxt_2 = ((NI64)hi_16);
      NI64 j_0 = ((NI64)(i_21 + IL64(1)));
      {
        while (j_0 < ((NI64)hi_16)){
          Token_0_tok9e79hf t_13 = tok_0_parq39nt2((&(*ps_32)), j_0);
          NB8 X60Qx_310 = isOpenBracket_0_parq39nt2(t_13.kind_0);
          if (X60Qx_310){
            inc_1_Irn1g7r1_aif7a4qfr((&depth_8));}
          else {
            NB8 X60Qx_311 = isCloseBracket_0_parq39nt2(t_13.kind_0);
            if (X60Qx_311){
              if (IL64(0) < depth_8){
                dec_1_I2mwrey1_envto7w6l1((&depth_8));}}
            else {
              NB8 X60Qx_312;
              NB8 X60Qx_313;
              if (depth_8 == IL64(0)){
                X60Qx_313 = (t_13.kind_0 == IL64(18));}
              else {
                X60Qx_313 = NIM_FALSE;}
              if (X60Qx_313){
                X60Qx_312 = (colon_0 < IL64(0));}
              else {
                X60Qx_312 = NIM_FALSE;}
              if (X60Qx_312){
                colon_0 = j_0;}
              else {
                NB8 X60Qx_314;
                NB8 X60Qx_315;
                if (depth_8 == IL64(0)){
                  X60Qx_315 = (t_13.kind_0 == IL64(2));}
                else {
                  X60Qx_315 = NIM_FALSE;}
                if (X60Qx_315){
                  NB8 X60Qx_316;
                  NB8 X60Qx_317 = eqQ_20_sysvq0asl(t_13.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
                  );
                  if (X60Qx_317){
                    X60Qx_316 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_318 = eqQ_20_sysvq0asl(t_13.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_316 = X60Qx_318;}
                  X60Qx_314 = X60Qx_316;}
                else {
                  X60Qx_314 = NIM_FALSE;}
                if (X60Qx_314){
                  nxt_2 = j_0;
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_13));
                  goto whileStmtLabel_1;}}}}
          inc_1_Irn1g7r1_aif7a4qfr((&j_0));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_13));}}
      whileStmtLabel_1: ;
      NI64 bodyLo_0 = ((NI64)(colon_0 + IL64(1)));
      if (isElse_0){
        addTree_0_nifjp9lau1(b_16, (string_0_sysvq0asl){
          .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_32)), b_16, kw_0.line_0, kw_0.col_0, ifTok_0.line_0, ifTok_0.col_0, NIM_FALSE);
        Token_0_tok9e79hf bt_0 = tok_0_parq39nt2((&(*ps_32)), bodyLo_0);
        if (bare_0){
          parseBareResultBody_0_parq39nt2(ps_32, b_16, ((NI32)bodyLo_0), ((NI32)nxt_2), kw_0.line_0, kw_0.col_0);}
        else {
          addTree_0_nifjp9lau1(b_16, (string_0_sysvq0asl){
            .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_32)), b_16, bt_0.line_0, bt_0.col_0, kw_0.line_0, kw_0.col_0, NIM_FALSE);
          parseExprRange_1_parq39nt2(ps_32, b_16, ((NI32)bodyLo_0), ((NI32)nxt_2), bt_0.line_0, bt_0.col_0);
          endTree_0_nifjp9lau1(b_16);}
        endTree_0_nifjp9lau1(b_16);
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&bt_0));}
      else {
        Token_0_tok9e79hf ct_0 = tok_0_parq39nt2((&(*ps_32)), ((NI64)(i_21 + IL64(1))));
        addTree_0_nifjp9lau1(b_16, (string_0_sysvq0asl){
          .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_32)), b_16, ct_0.line_0, ct_0.col_0, ifTok_0.line_0, ifTok_0.col_0, NIM_FALSE);
        parseExprRange_1_parq39nt2(ps_32, b_16, ((NI32)((NI64)(i_21 + IL64(1)))), ((NI32)colon_0), ct_0.line_0, ct_0.col_0);
        Token_0_tok9e79hf bt_1 = tok_0_parq39nt2((&(*ps_32)), bodyLo_0);
        if (bare_0){
          parseBareResultBody_0_parq39nt2(ps_32, b_16, ((NI32)bodyLo_0), ((NI32)nxt_2), ct_0.line_0, ct_0.col_0);}
        else {
          addTree_0_nifjp9lau1(b_16, (string_0_sysvq0asl){
            .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_32)), b_16, bt_1.line_0, bt_1.col_0, ct_0.line_0, ct_0.col_0, NIM_FALSE);
          parseExprRange_1_parq39nt2(ps_32, b_16, ((NI32)bodyLo_0), ((NI32)nxt_2), bt_1.line_0, bt_1.col_0);
          endTree_0_nifjp9lau1(b_16);}
        endTree_0_nifjp9lau1(b_16);
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&bt_1));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&ct_0));}
      i_21 = nxt_2;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_0));}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_16);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&ifTok_0));}
void parseCaseExpr_1_parq39nt2(Parser_0_parq39nt2* ps_33, Builder_0_nifjp9lau1* b_17, NI32 lo_17, NI32 hi_17, NI32 pl_17, NI32 pc_17){
  Token_0_tok9e79hf kw_1 = tok_0_parq39nt2((&(*ps_33)), ((NI64)lo_17));
  addTree_0_nifjp9lau1(b_17, (string_0_sysvq0asl){
    .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_33)), b_17, kw_1.line_0, kw_1.col_0, pl_17, pc_17, NIM_FALSE);
  NI64 depth_9 = IL64(0);
  NI64 firstOf_0 = ((NI64)hi_17);
  NI64 j_1 = ((NI64)(((NI64)lo_17) + IL64(1)));
  {
    while (j_1 < ((NI64)hi_17)){
      Token_0_tok9e79hf t_14 = tok_0_parq39nt2((&(*ps_33)), j_1);
      NB8 X60Qx_319 = isOpenBracket_0_parq39nt2(t_14.kind_0);
      if (X60Qx_319){
        inc_1_Irn1g7r1_aif7a4qfr((&depth_9));}
      else {
        NB8 X60Qx_320 = isCloseBracket_0_parq39nt2(t_14.kind_0);
        if (X60Qx_320){
          if (IL64(0) < depth_9){
            dec_1_I2mwrey1_envto7w6l1((&depth_9));}}
        else {
          NB8 X60Qx_321;
          NB8 X60Qx_322;
          if (depth_9 == IL64(0)){
            X60Qx_322 = (t_14.kind_0 == IL64(2));}
          else {
            X60Qx_322 = NIM_FALSE;}
          if (X60Qx_322){
            NB8 X60Qx_323 = eqQ_20_sysvq0asl(t_14.s_0, (string_0_sysvq0asl){
              .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
            );
            X60Qx_321 = X60Qx_323;}
          else {
            X60Qx_321 = NIM_FALSE;}
          if (X60Qx_321){
            firstOf_0 = j_1;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_14));
            goto whileStmtLabel_0;}}}
      inc_1_Irn1g7r1_aif7a4qfr((&j_1));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_14));}}
  whileStmtLabel_0: ;
  NI64 selHi_0 = firstOf_0;
  NB8 X60Qx_68;
  if (((NI64)lo_17) < ((NI64)(selHi_0 - IL64(1)))){
    Token_0_tok9e79hf X60Qtmp_15 = tok_0_parq39nt2((&(*ps_33)), ((NI64)(selHi_0 - IL64(1))));
    X60Qx_68 = (X60Qtmp_15.kind_0 == IL64(18));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_15));}
  else {
    X60Qx_68 = NIM_FALSE;}
  if (X60Qx_68){
    dec_1_I2mwrey1_envto7w6l1((&selHi_0));}
  parseExprRange_1_parq39nt2(ps_33, b_17, ((NI32)(((NI32)lo_17) + ((NI32)IL64(1)))), ((NI32)selHi_0), kw_1.line_0, kw_1.col_0);
  NI64 i_22 = firstOf_0;
  {
    while (i_22 < ((NI64)hi_17)){
      Token_0_tok9e79hf br_0 = tok_0_parq39nt2((&(*ps_33)), i_22);
      NB8 X60Qx_324;
      if (br_0.kind_0 == IL64(2)){
        NB8 X60Qx_325 = eqQ_20_sysvq0asl(br_0.s_0, (string_0_sysvq0asl){
          .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
        );
        X60Qx_324 = X60Qx_325;}
      else {
        X60Qx_324 = NIM_FALSE;}
      NB8 isOf_0 = X60Qx_324;
      NB8 X60Qx_326;
      if (br_0.kind_0 == IL64(2)){
        NB8 X60Qx_327 = eqQ_20_sysvq0asl(br_0.s_0, (string_0_sysvq0asl){
          .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
        );
        X60Qx_326 = X60Qx_327;}
      else {
        X60Qx_326 = NIM_FALSE;}
      NB8 isElse_1 = X60Qx_326;
      NI64 d_0 = IL64(0);
      NI64 colon_1 = IL64(-1);
      NI64 nxt_3 = ((NI64)hi_17);
      NI64 k_7 = ((NI64)(i_22 + IL64(1)));
      {
        while (k_7 < ((NI64)hi_17)){
          Token_0_tok9e79hf t_15 = tok_0_parq39nt2((&(*ps_33)), k_7);
          NB8 X60Qx_328 = isOpenBracket_0_parq39nt2(t_15.kind_0);
          if (X60Qx_328){
            inc_1_Irn1g7r1_aif7a4qfr((&d_0));}
          else {
            NB8 X60Qx_329 = isCloseBracket_0_parq39nt2(t_15.kind_0);
            if (X60Qx_329){
              if (IL64(0) < d_0){
                dec_1_I2mwrey1_envto7w6l1((&d_0));}}
            else {
              NB8 X60Qx_330;
              NB8 X60Qx_331;
              if (d_0 == IL64(0)){
                X60Qx_331 = (t_15.kind_0 == IL64(18));}
              else {
                X60Qx_331 = NIM_FALSE;}
              if (X60Qx_331){
                X60Qx_330 = (colon_1 < IL64(0));}
              else {
                X60Qx_330 = NIM_FALSE;}
              if (X60Qx_330){
                colon_1 = k_7;}
              else {
                NB8 X60Qx_332;
                NB8 X60Qx_333;
                if (d_0 == IL64(0)){
                  X60Qx_333 = (t_15.kind_0 == IL64(2));}
                else {
                  X60Qx_333 = NIM_FALSE;}
                if (X60Qx_333){
                  NB8 X60Qx_334;
                  NB8 X60Qx_335;
                  NB8 X60Qx_336 = eqQ_20_sysvq0asl(t_15.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
                  );
                  if (X60Qx_336){
                    X60Qx_335 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_337 = eqQ_20_sysvq0asl(t_15.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_335 = X60Qx_337;}
                  if (X60Qx_335){
                    X60Qx_334 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_338 = eqQ_20_sysvq0asl(t_15.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_334 = X60Qx_338;}
                  X60Qx_332 = X60Qx_334;}
                else {
                  X60Qx_332 = NIM_FALSE;}
                if (X60Qx_332){
                  nxt_3 = k_7;
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_15));
                  goto whileStmtLabel_2;}}}}
          inc_1_Irn1g7r1_aif7a4qfr((&k_7));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_15));}}
      whileStmtLabel_2: ;
      NI64 bodyLo_1 = ((NI64)(colon_1 + IL64(1)));
      if (isOf_0){
        addTree_0_nifjp9lau1(b_17, (string_0_sysvq0asl){
          .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_33)), b_17, br_0.line_0, br_0.col_0, kw_1.line_0, kw_1.col_0, NIM_FALSE);
        addTree_0_nifjp9lau1(b_17, (string_0_sysvq0asl){
          .bytes_0 = 32481117229642246ull, .more_0 = NIM_NIL}
        );
        seq_0_Iotb7mc_mat7cnfv21 starts_1 = splitArgs_0_parq39nt2((&(*ps_33)), ((NI64)(i_22 + IL64(1))), colon_1);
        {
          NI64 X60Qlf_8 = IL64(0);
          NI64 X60Qlf_9 = len_3_I12oavy1_parq39nt2(starts_1);
          NI64 X60Qlf_10 = X60Qlf_8;
          {
            while (X60Qlf_10 < X60Qlf_9){
              {
                NI64* X60Qx_339 = getQ_7_Ite3z0o_parq39nt2(starts_1, X60Qlf_10);
                NI64 X60Qii_5 = (*X60Qx_339);
                NI64 X60Qx_13;
                NI64 X60Qx_340 = len_3_I12oavy1_parq39nt2(starts_1);
                if (((NI64)(X60Qlf_10 + IL64(1))) < X60Qx_340){
                  NI64* X60Qx_341 = getQ_7_Ite3z0o_parq39nt2(starts_1, ((NI64)(X60Qlf_10 + IL64(1))));
                  X60Qx_13 = ((NI64)((*X60Qx_341) - IL64(1)));}
                else {
                  X60Qx_13 = colon_1;}
                NI64 X60Qii_6 = X60Qx_13;
                if (X60Qii_5 < X60Qii_6){
                  parseExprRange_1_parq39nt2(ps_33, b_17, ((NI32)X60Qii_5), ((NI32)X60Qii_6), br_0.line_0, br_0.col_0);}}
              inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_10));}}
          whileStmtLabel_4: ;}
        forStmtLabel_3: ;
        endTree_0_nifjp9lau1(b_17);
        parseBareResultBody_0_parq39nt2(ps_33, b_17, ((NI32)bodyLo_1), ((NI32)nxt_3), br_0.line_0, br_0.col_0);
        endTree_0_nifjp9lau1(b_17);
        eQdestroy_1_Iez2nr5_mat7cnfv21(starts_1);}
      else {
        if (isElse_1){
          addTree_0_nifjp9lau1(b_17, (string_0_sysvq0asl){
            .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_33)), b_17, br_0.line_0, br_0.col_0, kw_1.line_0, kw_1.col_0, NIM_FALSE);
          parseBareResultBody_0_parq39nt2(ps_33, b_17, ((NI32)bodyLo_1), ((NI32)nxt_3), br_0.line_0, br_0.col_0);
          endTree_0_nifjp9lau1(b_17);}
        else {
          addTree_0_nifjp9lau1(b_17, (string_0_sysvq0asl){
            .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
          );
          Token_0_tok9e79hf ct_1 = tok_0_parq39nt2((&(*ps_33)), ((NI64)(i_22 + IL64(1))));
          emitInfo_0_parq39nt2((&(*ps_33)), b_17, ct_1.line_0, ct_1.col_0, kw_1.line_0, kw_1.col_0, NIM_FALSE);
          parseExprRange_1_parq39nt2(ps_33, b_17, ((NI32)((NI64)(i_22 + IL64(1)))), ((NI32)colon_1), ct_1.line_0, ct_1.col_0);
          parseBareResultBody_0_parq39nt2(ps_33, b_17, ((NI32)bodyLo_1), ((NI32)nxt_3), ct_1.line_0, ct_1.col_0);
          endTree_0_nifjp9lau1(b_17);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&ct_1));}}
      i_22 = nxt_3;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&br_0));}}
  whileStmtLabel_1: ;
  endTree_0_nifjp9lau1(b_17);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_1));}
void parseCastExpr_0_parq39nt2(Parser_0_parq39nt2* ps_34, Builder_0_nifjp9lau1* b_18, NI32 lo_18, NI32 hi_18, NI32 pl_18, NI32 pc_18){
  Token_0_tok9e79hf castTok_0 = tok_0_parq39nt2((&(*ps_34)), ((NI64)lo_18));
  addTree_0_nifjp9lau1(b_18, (string_0_sysvq0asl){
    .bytes_0 = 500151968516ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_34)), b_18, castTok_0.line_0, castTok_0.col_0, pl_18, pc_18, NIM_FALSE);
  NI64 lb_0 = ((NI64)(((NI64)lo_18) + IL64(1)));
  NI64 rb_0 = matchClose_0_parq39nt2((&(*ps_34)), lb_0);
  NI64 X60Qx_342 = parseType_1_parq39nt2(ps_34, b_18, ((NI64)(lb_0 + IL64(1))), castTok_0.line_0, castTok_0.col_0);
  NI64 lp_0 = ((NI64)(rb_0 + IL64(1)));
  NI64 rp_0 = matchClose_0_parq39nt2((&(*ps_34)), lp_0);
  parseExprRange_1_parq39nt2(ps_34, b_18, ((NI32)((NI64)(lp_0 + IL64(1)))), ((NI32)rp_0), castTok_0.line_0, castTok_0.col_0);
  endTree_0_nifjp9lau1(b_18);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&castTok_0));}
void parseCmdKw_0_parq39nt2(Parser_0_parq39nt2* ps_35, Builder_0_nifjp9lau1* b_19, NI32 lo_19, NI32 hi_19, NI32 pl_19, NI32 pc_19){
  Token_0_tok9e79hf kw_2 = tok_0_parq39nt2((&(*ps_35)), ((NI64)lo_19));
  Token_0_tok9e79hf arg0_0 = tok_0_parq39nt2((&(*ps_35)), ((NI64)(((NI64)lo_19) + IL64(1))));
  addTree_0_nifjp9lau1(b_19, (string_0_sysvq0asl){
    .bytes_0 = 1684890371ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_35)), b_19, arg0_0.line_0, arg0_0.col_0, pl_19, pc_19, NIM_FALSE);
  addIdent_0_nifjp9lau1(b_19, kw_2.s_0);
  emitInfo_0_parq39nt2((&(*ps_35)), b_19, kw_2.line_0, kw_2.col_0, arg0_0.line_0, arg0_0.col_0, NIM_FALSE);
  parseArgList_0_parq39nt2(ps_35, b_19, ((NI32)(lo_19 + ((NI32)IL64(1)))), hi_19, arg0_0.line_0, arg0_0.col_0);
  endTree_0_nifjp9lau1(b_19);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&arg0_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_2));}
void parsePrimaryRangeImpl_0_parq39nt2(Parser_0_parq39nt2* ps_36, Builder_0_nifjp9lau1* b_20, NI32 lo_20, NI32 hi_20, NI32 pl_20, NI32 pc_20){
  Token_0_tok9e79hf t_16 = tok_0_parq39nt2((&(*ps_36)), ((NI64)lo_20));
  NB8 X60Qx_343;
  NB8 X60Qx_344;
  if (t_16.kind_0 == IL64(9)){
    NB8 X60Qx_345 = eqQ_20_sysvq0asl(t_16.s_0, (string_0_sysvq0asl){
      .bytes_0 = 11521ull, .more_0 = NIM_NIL}
    );
    X60Qx_344 = X60Qx_345;}
  else {
    X60Qx_344 = NIM_FALSE;}
  if (X60Qx_344){
    X60Qx_343 = (((NI64)(((NI64)lo_20) + IL64(2))) == ((NI64)hi_20));}
  else {
    X60Qx_343 = NIM_FALSE;}
  if (X60Qx_343){
    Token_0_tok9e79hf n_0 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)lo_20) + IL64(1))));
    NB8 X60Qx_346;
    NB8 X60Qx_347;
    NB8 X60Qx_348;
    if (n_0.kind_0 == IL64(3)){
      X60Qx_348 = NIM_TRUE;}
    else {
      X60Qx_348 = (n_0.kind_0 == IL64(4));}
    if (X60Qx_348){
      X60Qx_347 = (n_0.line_0 == t_16.line_0);}
    else {
      X60Qx_347 = NIM_FALSE;}
    if (X60Qx_347){
      X60Qx_346 = (n_0.col_0 == ((NI32)(t_16.col_0 + ((NI32)IL64(1)))));}
    else {
      X60Qx_346 = NIM_FALSE;}
    if (X60Qx_346){
      string_0_sysvq0asl suf_0 = n_0.suffix_0;
      nimStrWasMoved((&n_0.suffix_0));
      if (n_0.kind_0 == IL64(3)){
        NI64 v_0 = ((NI64)-n_0.iVal_0);
        NI64 X60Qx_349 = len_4_sysvq0asl(suf_0);
        if (IL64(0) < X60Qx_349){
          addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
            .bytes_0 = 1718973187ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
          NC8 X60Qx_350 = getQ_9_sysvq0asl(suf_0, IL64(0));
          if (X60Qx_350 == (NC8)'u'){
            addUIntLit_0_nifjp9lau1(b_20, ((NU64)v_0));}
          else {
            addIntLit_0_nifjp9lau1(b_20, v_0);}
          addStrLit_0_nifjp9lau1(b_20, suf_0);
          endTree_0_nifjp9lau1(b_20);}
        else {
          NB8 X60Qx_351;
          if (((NI64)IL64(2147483647)) < v_0){
            X60Qx_351 = NIM_TRUE;}
          else {
            X60Qx_351 = (v_0 < ((NI64)IL64(-2147483648)));}
          if (X60Qx_351){
            addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
              .bytes_0 = 1718973187ull, .more_0 = NIM_NIL}
            );
            emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
            addIntLit_0_nifjp9lau1(b_20, v_0);
            addStrLit_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
              .bytes_0 = 875981059ull, .more_0 = NIM_NIL}
            );
            endTree_0_nifjp9lau1(b_20);}
          else {
            addIntLit_0_nifjp9lau1(b_20, v_0);
            emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);}}}
      else {
        NI64 X60Qx_352 = len_4_sysvq0asl(suf_0);
        if (IL64(0) < X60Qx_352){
          addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
            .bytes_0 = 1718973187ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
          addFloatLit_0_nifjp9lau1(b_20, ((NF64)-n_0.fVal_0), ((NI32)IL64(0)), ((NI32)IL64(0)), (string_0_sysvq0asl){
            .bytes_0 = 0ull, .more_0 = NIM_NIL}
          );
          addStrLit_0_nifjp9lau1(b_20, suf_0);
          endTree_0_nifjp9lau1(b_20);}
        else {
          addFloatLit_0_nifjp9lau1(b_20, ((NF64)-n_0.fVal_0), ((NI32)(t_16.col_0 - pc_20)), ((NI32)(t_16.line_0 - pl_20)), (string_0_sysvq0asl){
            .bytes_0 = 0ull, .more_0 = NIM_NIL}
          );}}
      nimStrDestroy(suf_0);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&n_0));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
      return;
      nimStrDestroy(suf_0);}
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&n_0));}
  NB8 X60Qx_353;
  NB8 X60Qx_354;
  if (t_16.kind_0 == IL64(1)){
    X60Qx_354 = NIM_TRUE;}
  else {
    X60Qx_354 = (t_16.kind_0 == IL64(2));}
  if (X60Qx_354){
    X60Qx_353 = (((NI64)lo_20) < ((NI64)(((NI64)hi_20) - IL64(1))));}
  else {
    X60Qx_353 = NIM_FALSE;}
  if (X60Qx_353){
    Token_0_tok9e79hf s_11 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)hi_20) - IL64(1))));
    Token_0_tok9e79hf prev_4 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)hi_20) - IL64(2))));
    NB8 X60Qx_355;
    NB8 X60Qx_356;
    NB8 X60Qx_357;
    NB8 X60Qx_358;
    NB8 X60Qx_359;
    if (s_11.kind_0 == IL64(5)){
      X60Qx_359 = NIM_TRUE;}
    else {
      X60Qx_359 = (s_11.kind_0 == IL64(6));}
    if (X60Qx_359){
      X60Qx_358 = NIM_TRUE;}
    else {
      X60Qx_358 = (s_11.kind_0 == IL64(7));}
    if (X60Qx_358){
      X60Qx_357 = (s_11.line_0 == prev_4.line_0);}
    else {
      X60Qx_357 = NIM_FALSE;}
    if (X60Qx_357){
      X60Qx_356 = (s_11.col_0 == prev_4.endCol_0);}
    else {
      X60Qx_356 = NIM_FALSE;}
    if (X60Qx_356){
      NB8 X60Qx_360;
      if (prev_4.kind_0 == IL64(1)){
        X60Qx_360 = NIM_TRUE;}
      else {
        X60Qx_360 = (prev_4.kind_0 == IL64(2));}
      X60Qx_355 = X60Qx_360;}
    else {
      X60Qx_355 = NIM_FALSE;}
    if (X60Qx_355){
      NB8 X60Qx_69;
      if (((NI64)(((NI64)hi_20) - IL64(2))) == ((NI64)lo_20)){
        X60Qx_69 = NIM_TRUE;}
      else {
        Token_0_tok9e79hf X60Qtmp_16 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)hi_20) - IL64(3))));
        X60Qx_69 = (X60Qtmp_16.kind_0 == IL64(19));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_16));}
      NB8 dotAccess_0 = X60Qx_69;
      if (dotAccess_0){
        addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
          .bytes_0 = 8247343727134204926ull, .more_0 = (&strlit_0_I9217337746930322866_parq39nt2)}
        );
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, s_11.line_0, s_11.col_0, pl_20, pc_20, NIM_FALSE);
        parseExprRange_1_parq39nt2(ps_36, b_20, lo_20, ((NI32)((NI64)(((NI64)hi_20) - IL64(1)))), s_11.line_0, s_11.col_0);
        addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
          .bytes_0 = 1718973187ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, s_11.line_0, s_11.col_0, s_11.line_0, s_11.col_0, NIM_FALSE);
        addStrLit_0_nifjp9lau1(b_20, s_11.s_0);
        addStrLit_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
          .bytes_0 = 20993ull, .more_0 = NIM_NIL}
        );
        endTree_0_nifjp9lau1(b_20);
        endTree_0_nifjp9lau1(b_20);
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_4));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&s_11));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
        return;}}
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_4));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&s_11));}
  if (t_16.kind_0 == IL64(9)){
    addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
      .bytes_0 = 33892885714857990ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
    addIdent_0_nifjp9lau1(b_20, t_16.s_0);
    emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, t_16.line_0, t_16.col_0, NIM_FALSE);
    if (((NI64)(((NI64)lo_20) + IL64(1))) < ((NI64)hi_20)){
      parseExprRange_1_parq39nt2(ps_36, b_20, ((NI32)(lo_20 + ((NI32)IL64(1)))), hi_20, t_16.line_0, t_16.col_0);}
    endTree_0_nifjp9lau1(b_20);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
    return;}
  if (t_16.kind_0 == IL64(2)){
    string_0_sysvq0asl X60Qtc_9 = t_16.s_0;
    NB8 X60Qtc_18 = nimStrAtLe_0_sysvq0asl(X60Qtc_9, IL64(0), (NC8)'i');
    if (X60Qtc_18){
      NB8 X60Qtc_19 = nimStrAtLe_0_sysvq0asl(X60Qtc_9, IL64(0), (NC8)'c');
      if (X60Qtc_19){
        if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
          .bytes_0 = 500151968516ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_12;}
        else if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
          .bytes_0 = 491310571780ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_17;}}
      else {
        NB8 X60Qtc_20 = nimStrAtLe_0_sysvq0asl(X60Qtc_9, IL64(0), (NC8)'f');
        if (X60Qtc_20){
          if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
            .bytes_0 = 427054949892ull, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_16;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
            .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_13;}
          else if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
            .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
          )){
            goto X60Qsc_16;}}}}
    else {
      NB8 X60Qtc_21 = nimStrAtLe_0_sysvq0asl(X60Qtc_9, IL64(0), (NC8)'n');
      if (X60Qtc_21){
        if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
          .bytes_0 = 1818848771ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_10;}
        else if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
          .bytes_0 = 1953459715ull, .more_0 = NIM_NIL}
        )){
          goto X60Qsc_11;}}
      else {
        NB8 X60Qtc_22 = nimStrAtLe_0_sysvq0asl(X60Qtc_9, IL64(0), (NC8)'t');
        if (X60Qtc_22){
          if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
            .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_15;}
          else if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
            .bytes_0 = 427071533060ull, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_16;}}
        else {
          if (equalStrings_0_sysvq0asl(X60Qtc_9, (string_0_sysvq0asl){
            .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
          )){
            goto X60Qsc_14;}}}}
    goto X60Qsc_24;
    X60Qsc_10: ;
    addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
      .bytes_0 = 1818848771ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
    endTree_0_nifjp9lau1(b_20);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
    return;
    goto X60Qsc_23;
    X60Qsc_11: ;
    addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
      .bytes_0 = 33892885714857990ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
    addIdent_0_nifjp9lau1(b_20, t_16.s_0);
    emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, t_16.line_0, t_16.col_0, NIM_FALSE);
    if (((NI64)(((NI64)lo_20) + IL64(1))) < ((NI64)hi_20)){
      parseExprRange_1_parq39nt2(ps_36, b_20, ((NI32)(lo_20 + ((NI32)IL64(1)))), hi_20, t_16.line_0, t_16.col_0);}
    endTree_0_nifjp9lau1(b_20);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
    return;
    goto X60Qsc_23;
    X60Qsc_12: ;
    NB8 X60Qx_70;
    if (((NI64)(((NI64)lo_20) + IL64(1))) < ((NI64)hi_20)){
      Token_0_tok9e79hf X60Qtmp_17 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)lo_20) + IL64(1))));
      X60Qx_70 = (X60Qtmp_17.kind_0 == IL64(12));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_17));}
    else {
      X60Qx_70 = NIM_FALSE;}
    if (X60Qx_70){
      NI64 rb_1 = matchClose_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)lo_20) + IL64(1))));
      NI64 castEnd_0 = rb_1;
      NB8 X60Qx_71;
      if (((NI64)(rb_1 + IL64(1))) < ((NI64)hi_20)){
        Token_0_tok9e79hf X60Qtmp_18 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(rb_1 + IL64(1))));
        X60Qx_71 = (X60Qtmp_18.kind_0 == IL64(10));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_18));}
      else {
        X60Qx_71 = NIM_FALSE;}
      if (X60Qx_71){
        NI64 X60Qx_361 = matchClose_0_parq39nt2((&(*ps_36)), ((NI64)(rb_1 + IL64(1))));
        castEnd_0 = X60Qx_361;}
      if (((NI64)hi_20) <= ((NI64)(castEnd_0 + IL64(1)))){
        parseCastExpr_0_parq39nt2(ps_36, b_20, lo_20, hi_20, pl_20, pc_20);
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
        return;}}
    goto X60Qsc_23;
    X60Qsc_13: ;
    parseIfExpr_0_parq39nt2(ps_36, b_20, lo_20, hi_20, pl_20, pc_20, NIM_FALSE, (string_0_sysvq0asl){
      .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
    );
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
    return;
    goto X60Qsc_23;
    X60Qsc_14: ;
    parseIfExpr_0_parq39nt2(ps_36, b_20, lo_20, hi_20, pl_20, pc_20, NIM_FALSE, (string_0_sysvq0asl){
      .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
    );
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
    return;
    goto X60Qsc_23;
    X60Qsc_15: ;
    NI64 X60Qx_362 = parseTry_1_parq39nt2(ps_36, b_20, ((NI64)lo_20), pl_20, pc_20);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
    return;
    goto X60Qsc_23;
    X60Qsc_16: ;
    NI64 X60Qx_363 = parseRoutine_1_parq39nt2(ps_36, b_20, ((NI64)lo_20), pl_20, pc_20, t_16.s_0);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
    return;
    goto X60Qsc_23;
    X60Qsc_17: ;
    Token_0_tok9e79hf nxt_4 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)lo_20) + IL64(1))));
    NB8 X60Qx_364;
    NB8 X60Qx_365;
    if (nxt_4.kind_0 == IL64(10)){
      X60Qx_365 = (nxt_4.line_0 == t_16.line_0);}
    else {
      X60Qx_365 = NIM_FALSE;}
    if (X60Qx_365){
      NI64 X60Qx_366 = len_4_sysvq0asl(t_16.s_0);
      X60Qx_364 = (nxt_4.col_0 == ((NI32)(t_16.col_0 + ((NI32)X60Qx_366))));}
    else {
      X60Qx_364 = NIM_FALSE;}
    NB8 adjacentCall_0 = X60Qx_364;
    NB8 X60Qx_367;
    if (((NI64)(((NI64)lo_20) + IL64(1))) < ((NI64)hi_20)){
      X60Qx_367 = (!adjacentCall_0);}
    else {
      X60Qx_367 = NIM_FALSE;}
    if (X60Qx_367){
      parseCmdKw_0_parq39nt2(ps_36, b_20, lo_20, hi_20, pl_20, pc_20);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_4));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
      return;}
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_4));
    goto X60Qsc_23;
    X60Qsc_24: ;
    X60Qsc_23: ;}
  NI64 pkind_0 = IL64(0);
  NI64 k_8 = findPostfix_0_parq39nt2((&(*ps_36)), ((NI64)lo_20), ((NI64)hi_20), (&pkind_0));
  if (IL64(0) <= k_8){
    Token_0_tok9e79hf opTok_0 = tok_0_parq39nt2((&(*ps_36)), k_8);
    switch (pkind_0){
      case ((NI64)IL64(1)):
      {
        addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
          .bytes_0 = 1953457155ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, opTok_0.line_0, opTok_0.col_0, pl_20, pc_20, NIM_FALSE);
        parsePrimaryRange_1_parq39nt2(ps_36, b_20, lo_20, ((NI32)k_8), opTok_0.line_0, opTok_0.col_0);
        Token_0_tok9e79hf r_0 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(k_8 + IL64(1))));
        emitName_0_parq39nt2((&(*ps_36)), b_20, (&r_0), opTok_0.line_0, opTok_0.col_0);
        endTree_0_nifjp9lau1(b_20);
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&r_0));}
      break;
      case ((NI64)IL64(2)):
      {
        NI64 rp_1 = matchClose_0_parq39nt2((&(*ps_36)), k_8);
        addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
          .bytes_0 = 7627010ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, opTok_0.line_0, opTok_0.col_0, pl_20, pc_20, NIM_FALSE);
        parsePrimaryRange_1_parq39nt2(ps_36, b_20, lo_20, ((NI32)k_8), opTok_0.line_0, opTok_0.col_0);
        parseArgList_0_parq39nt2(ps_36, b_20, ((NI32)((NI64)(k_8 + IL64(1)))), ((NI32)rp_1), opTok_0.line_0, opTok_0.col_0);
        endTree_0_nifjp9lau1(b_20);}
      break;
      case ((NI64)IL64(3)):
      {
        NI64 rp_2 = matchClose_0_parq39nt2((&(*ps_36)), k_8);
        addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
          .bytes_0 = 8386117487824298759ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, opTok_0.line_0, opTok_0.col_0, pl_20, pc_20, NIM_FALSE);
        parsePrimaryRange_1_parq39nt2(ps_36, b_20, lo_20, ((NI32)k_8), opTok_0.line_0, opTok_0.col_0);
        parseArgList_0_parq39nt2(ps_36, b_20, ((NI32)((NI64)(k_8 + IL64(1)))), ((NI32)rp_2), opTok_0.line_0, opTok_0.col_0);
        endTree_0_nifjp9lau1(b_20);}
      break;
      default:
      {
        NI64 rp_3 = matchClose_0_parq39nt2((&(*ps_36)), k_8);
        seq_0_Iotb7mc_mat7cnfv21 starts_2 = splitArgs_0_parq39nt2((&(*ps_36)), ((NI64)(k_8 + IL64(1))), rp_3);
        NB8 isObj_0 = NIM_FALSE;
        if (IL64(0) < starts_2.len_0){
          NI64 X60Qx_14;
          if (IL64(1) < starts_2.len_0){
            NI64* X60Qx_368 = getQ_7_Ite3z0o_parq39nt2(starts_2, IL64(1));
            X60Qx_14 = ((NI64)((*X60Qx_368) - IL64(1)));}
          else {
            X60Qx_14 = rp_3;}
          NI64 a0Hi_0 = X60Qx_14;
          NB8 X60Qx_72;
          NI64* X60Qx_369 = getQ_7_Ite3z0o_parq39nt2(starts_2, IL64(0));
          Token_0_tok9e79hf X60Qtmp_19 = tok_0_parq39nt2((&(*ps_36)), (*X60Qx_369));
          if (X60Qtmp_19.kind_0 == IL64(1)){
            NI64* X60Qx_370 = getQ_7_Ite3z0o_parq39nt2(starts_2, IL64(0));
            NI64 X60Qx_371 = depth0Colon_0_parq39nt2((&(*ps_36)), (*X60Qx_370), a0Hi_0);
            X60Qx_72 = (IL64(0) <= X60Qx_371);}
          else {
            X60Qx_72 = NIM_FALSE;}
          isObj_0 = X60Qx_72;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_19));}
        string_0_sysvq0asl X60Qx_15;
        nimStrWasMoved((&X60Qx_15));
        if (isObj_0){
          nimStrDestroy(X60Qx_15);
          X60Qx_15 = (string_0_sysvq0asl){
            .bytes_0 = 8247343735774605063ull, .more_0 = NIM_NIL}
          ;}
        else {
          nimStrDestroy(X60Qx_15);
          X60Qx_15 = (string_0_sysvq0asl){
            .bytes_0 = 465674789636ull, .more_0 = NIM_NIL}
          ;}
        addTree_0_nifjp9lau1(b_20, X60Qx_15);
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, opTok_0.line_0, opTok_0.col_0, pl_20, pc_20, NIM_FALSE);
        parsePrimaryRange_1_parq39nt2(ps_36, b_20, lo_20, ((NI32)k_8), opTok_0.line_0, opTok_0.col_0);
        parseArgList_0_parq39nt2(ps_36, b_20, ((NI32)((NI64)(k_8 + IL64(1)))), ((NI32)rp_3), opTok_0.line_0, opTok_0.col_0);
        endTree_0_nifjp9lau1(b_20);
        nimStrDestroy(X60Qx_15);
        eQdestroy_1_Iez2nr5_mat7cnfv21(starts_2);}
      break;}
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&opTok_0));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));
    return;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&opTok_0));}
  switch (t_16.kind_0){
    case IL64(3):
    {
      string_0_sysvq0asl suf_1 = t_16.suffix_0;
      nimStrWasMoved((&t_16.suffix_0));
      NI64 X60Qx_372 = len_4_sysvq0asl(suf_1);
      if (X60Qx_372 == IL64(0)){
        NB8 X60Qx_373;
        if (((NI64)IL64(2147483647)) < t_16.iVal_0){
          X60Qx_373 = NIM_TRUE;}
        else {
          X60Qx_373 = (t_16.iVal_0 < ((NI64)IL64(-2147483648)));}
        if (X60Qx_373){
          addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
            .bytes_0 = 1718973187ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
          addIntLit_0_nifjp9lau1(b_20, t_16.iVal_0);
          addStrLit_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
            .bytes_0 = 875981059ull, .more_0 = NIM_NIL}
          );
          endTree_0_nifjp9lau1(b_20);}
        else {
          addIntLit_0_nifjp9lau1(b_20, t_16.iVal_0);
          emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);}}
      else {
        NB8 X60Qx_374 = eqQ_20_sysvq0asl(suf_1, (string_0_sysvq0asl){
          .bytes_0 = 29953ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_374){
          addUIntLit_0_nifjp9lau1(b_20, ((NU64)t_16.iVal_0));
          emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);}
        else {
          addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
            .bytes_0 = 1718973187ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
          NC8 X60Qx_375 = getQ_9_sysvq0asl(suf_1, IL64(0));
          if (X60Qx_375 == (NC8)'u'){
            addUIntLit_0_nifjp9lau1(b_20, ((NU64)t_16.iVal_0));}
          else {
            addIntLit_0_nifjp9lau1(b_20, t_16.iVal_0);}
          addStrLit_0_nifjp9lau1(b_20, suf_1);
          endTree_0_nifjp9lau1(b_20);}}
      nimStrDestroy(suf_1);}
    break;
    case IL64(4):
    {
      NI64 X60Qx_376 = len_4_sysvq0asl(t_16.suffix_0);
      if (X60Qx_376 == IL64(0)){
        addFloatLit_0_nifjp9lau1(b_20, t_16.fVal_0, ((NI32)(t_16.col_0 - pc_20)), ((NI32)(t_16.line_0 - pl_20)), (string_0_sysvq0asl){
          .bytes_0 = 0ull, .more_0 = NIM_NIL}
        );}
      else {
        addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
          .bytes_0 = 1718973187ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
        addFloatLit_0_nifjp9lau1(b_20, t_16.fVal_0, ((NI32)IL64(0)), ((NI32)IL64(0)), (string_0_sysvq0asl){
          .bytes_0 = 0ull, .more_0 = NIM_NIL}
        );
        addStrLit_0_nifjp9lau1(b_20, t_16.suffix_0);
        endTree_0_nifjp9lau1(b_20);}}
    break;
    case IL64(5):
    {
      addStrLit_0_nifjp9lau1(b_20, t_16.s_0);
      emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);}
    break;
    case IL64(6):
    {
      addStrLit_1_nifjp9lau1(b_20, t_16.s_0, (string_0_sysvq0asl){
        .bytes_0 = 20993ull, .more_0 = NIM_NIL}
      , ((NI32)(t_16.col_0 - pc_20)), ((NI32)(t_16.line_0 - pl_20)), (string_0_sysvq0asl){
        .bytes_0 = 0ull, .more_0 = NIM_NIL}
      );}
    break;
    case IL64(7):
    {
      addStrLit_1_nifjp9lau1(b_20, t_16.s_0, (string_0_sysvq0asl){
        .bytes_0 = 21505ull, .more_0 = NIM_NIL}
      , ((NI32)(t_16.col_0 - pc_20)), ((NI32)(t_16.line_0 - pl_20)), (string_0_sysvq0asl){
        .bytes_0 = 0ull, .more_0 = NIM_NIL}
      );}
    break;
    case IL64(8):
    {
      addCharLit_0_nifjp9lau1(b_20, ((NC8)t_16.iVal_0));
      emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);}
    break;
    case IL64(10):
    {
      NI64 rpIdx_0 = matchClose_0_parq39nt2((&(*ps_36)), ((NI64)lo_20));
      seq_0_Iotb7mc_mat7cnfv21 semis_0 = newSeqUninit_0_I7whkjh1_mat7cnfv21(IL64(0));
      {
        NI64 d_1 = IL64(0);
        NI64 k_9 = ((NI64)(((NI64)lo_20) + IL64(1)));
        {
          while (k_9 < rpIdx_0){
            Token_0_tok9e79hf kk_0 = tok_0_parq39nt2((&(*ps_36)), k_9);
            NB8 X60Qx_377 = isOpenBracket_0_parq39nt2(kk_0.kind_0);
            if (X60Qx_377){
              inc_1_Irn1g7r1_aif7a4qfr((&d_1));}
            else {
              NB8 X60Qx_378 = isCloseBracket_0_parq39nt2(kk_0.kind_0);
              if (X60Qx_378){
                if (IL64(0) < d_1){
                  dec_1_I2mwrey1_envto7w6l1((&d_1));}}
              else {
                NB8 X60Qx_379;
                NB8 X60Qx_380;
                if (d_1 == IL64(0)){
                  X60Qx_380 = (kk_0.kind_0 == IL64(2));}
                else {
                  X60Qx_380 = NIM_FALSE;}
                if (X60Qx_380){
                  NB8 X60Qx_381;
                  NB8 X60Qx_382;
                  NB8 X60Qx_383;
                  NB8 X60Qx_384;
                  NB8 X60Qx_385;
                  NB8 X60Qx_386;
                  NB8 X60Qx_387 = eqQ_20_sysvq0asl(kk_0.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
                  );
                  if (X60Qx_387){
                    X60Qx_386 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_388 = eqQ_20_sysvq0asl(kk_0.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_386 = X60Qx_388;}
                  if (X60Qx_386){
                    X60Qx_385 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_389 = eqQ_20_sysvq0asl(kk_0.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_385 = X60Qx_389;}
                  if (X60Qx_385){
                    X60Qx_384 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_390 = eqQ_20_sysvq0asl(kk_0.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_384 = X60Qx_390;}
                  if (X60Qx_384){
                    X60Qx_383 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_391 = eqQ_20_sysvq0asl(kk_0.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_383 = X60Qx_391;}
                  if (X60Qx_383){
                    X60Qx_382 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_392 = eqQ_20_sysvq0asl(kk_0.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 111516299327237ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_382 = X60Qx_392;}
                  if (X60Qx_382){
                    X60Qx_381 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_393 = eqQ_20_sysvq0asl(kk_0.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 1919903235ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_381 = X60Qx_393;}
                  X60Qx_379 = X60Qx_381;}
                else {
                  X60Qx_379 = NIM_FALSE;}
                if (X60Qx_379){
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kk_0));
                  goto whileStmtLabel_1;}
                else {
                  NB8 X60Qx_394;
                  if (d_1 == IL64(0)){
                    X60Qx_394 = (kk_0.kind_0 == IL64(17));}
                  else {
                    X60Qx_394 = NIM_FALSE;}
                  if (X60Qx_394){
                    add_0_I8fahwb_parq39nt2((&semis_0), k_9);}}}}
            inc_1_Irn1g7r1_aif7a4qfr((&k_9));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kk_0));}}
        whileStmtLabel_1: ;}
      X60Qlab_0: ;
      Token_0_tok9e79hf inner_0 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)lo_20) + IL64(1))));
      NB8 X60Qx_395;
      if (inner_0.kind_0 == IL64(2)){
        NB8 X60Qx_396;
        NB8 X60Qx_397;
        NB8 X60Qx_398;
        NB8 X60Qx_399;
        NB8 X60Qx_400;
        NB8 X60Qx_401;
        NB8 X60Qx_402 = eqQ_20_sysvq0asl(inner_0.s_0, (string_0_sysvq0asl){
          .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_402){
          X60Qx_401 = NIM_TRUE;}
        else {
          NB8 X60Qx_403 = eqQ_20_sysvq0asl(inner_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
          );
          X60Qx_401 = X60Qx_403;}
        if (X60Qx_401){
          X60Qx_400 = NIM_TRUE;}
        else {
          NB8 X60Qx_404 = eqQ_20_sysvq0asl(inner_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
          );
          X60Qx_400 = X60Qx_404;}
        if (X60Qx_400){
          X60Qx_399 = NIM_TRUE;}
        else {
          NB8 X60Qx_405 = eqQ_20_sysvq0asl(inner_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
          );
          X60Qx_399 = X60Qx_405;}
        if (X60Qx_399){
          X60Qx_398 = NIM_TRUE;}
        else {
          NB8 X60Qx_406 = eqQ_20_sysvq0asl(inner_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
          );
          X60Qx_398 = X60Qx_406;}
        if (X60Qx_398){
          X60Qx_397 = NIM_TRUE;}
        else {
          NB8 X60Qx_407 = eqQ_20_sysvq0asl(inner_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 111516299327237ull, .more_0 = NIM_NIL}
          );
          X60Qx_397 = X60Qx_407;}
        if (X60Qx_397){
          X60Qx_396 = NIM_TRUE;}
        else {
          NB8 X60Qx_408 = eqQ_20_sysvq0asl(inner_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 1919903235ull, .more_0 = NIM_NIL}
          );
          X60Qx_396 = X60Qx_408;}
        X60Qx_395 = X60Qx_396;}
      else {
        X60Qx_395 = NIM_FALSE;}
      NB8 ctrl_0 = X60Qx_395;
      NB8 X60Qx_409;
      if (IL64(0) < semis_0.len_0){
        X60Qx_409 = NIM_TRUE;}
      else {
        X60Qx_409 = ctrl_0;}
      if (X60Qx_409){
        addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
          .bytes_0 = 491513210116ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, pl_20, pc_20, pl_20, pc_20, NIM_FALSE);
        addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
          .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
        );
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
        NI64 segLo_0 = ((NI64)(((NI64)lo_20) + IL64(1)));
        {
          NI64 X60Qlf_11 = IL64(0);
          NI64 X60Qlf_12 = len_3_I12oavy1_parq39nt2(semis_0);
          NI64 X60Qlf_13 = X60Qlf_11;
          {
            while (X60Qlf_13 < X60Qlf_12){
              {
                NI64* X60Qx_410 = getQ_7_Ite3z0o_parq39nt2(semis_0, X60Qlf_13);
                NI64 X60Qx_411 = parseStmt_1_parq39nt2(ps_36, b_20, segLo_0, t_16.line_0, t_16.col_0, (*X60Qx_410));
                NI64* X60Qx_412 = getQ_7_Ite3z0o_parq39nt2(semis_0, X60Qlf_13);
                segLo_0 = ((NI64)((*X60Qx_412) + IL64(1)));}
              inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_13));}}
          whileStmtLabel_3: ;}
        forStmtLabel_2: ;
        endTree_0_nifjp9lau1(b_20);
        Token_0_tok9e79hf rt_0 = tok_0_parq39nt2((&(*ps_36)), segLo_0);
        NB8 X60Qx_413;
        if (rt_0.kind_0 == IL64(2)){
          NB8 X60Qx_414 = eqQ_20_sysvq0asl(rt_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
          );
          X60Qx_413 = X60Qx_414;}
        else {
          X60Qx_413 = NIM_FALSE;}
        if (X60Qx_413){
          parseTryExpr_1_parq39nt2(ps_36, b_20, ((NI32)segLo_0), ((NI32)rpIdx_0), t_16.line_0, t_16.col_0);}
        else {
          NB8 X60Qx_415;
          if (rt_0.kind_0 == IL64(2)){
            NB8 X60Qx_416 = eqQ_20_sysvq0asl(rt_0.s_0, (string_0_sysvq0asl){
              .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
            );
            X60Qx_415 = X60Qx_416;}
          else {
            X60Qx_415 = NIM_FALSE;}
          if (X60Qx_415){
            parseIfExpr_0_parq39nt2(ps_36, b_20, ((NI32)segLo_0), ((NI32)rpIdx_0), t_16.line_0, t_16.col_0, NIM_TRUE, (string_0_sysvq0asl){
              .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
            );}
          else {
            NB8 X60Qx_417;
            if (rt_0.kind_0 == IL64(2)){
              NB8 X60Qx_418 = eqQ_20_sysvq0asl(rt_0.s_0, (string_0_sysvq0asl){
                .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
              );
              X60Qx_417 = X60Qx_418;}
            else {
              X60Qx_417 = NIM_FALSE;}
            if (X60Qx_417){
              parseIfExpr_0_parq39nt2(ps_36, b_20, ((NI32)segLo_0), ((NI32)rpIdx_0), t_16.line_0, t_16.col_0, NIM_TRUE, (string_0_sysvq0asl){
                .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
              );}
            else {
              NB8 X60Qx_419;
              if (rt_0.kind_0 == IL64(2)){
                NB8 X60Qx_420 = eqQ_20_sysvq0asl(rt_0.s_0, (string_0_sysvq0asl){
                  .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
                );
                X60Qx_419 = X60Qx_420;}
              else {
                X60Qx_419 = NIM_FALSE;}
              if (X60Qx_419){
                parseCaseExpr_1_parq39nt2(ps_36, b_20, ((NI32)segLo_0), ((NI32)rpIdx_0), t_16.line_0, t_16.col_0);}
              else {
                NB8 X60Qx_421;
                if (rt_0.kind_0 == IL64(2)){
                  NB8 X60Qx_422 = eqQ_20_sysvq0asl(rt_0.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
                  );
                  X60Qx_421 = X60Qx_422;}
                else {
                  X60Qx_421 = NIM_FALSE;}
                if (X60Qx_421){
                  NI64 bcolon_0 = findColon_0_parq39nt2((&(*ps_36)), segLo_0, rpIdx_0);
                  addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
                    .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
                  );
                  emitInfo_0_parq39nt2((&(*ps_36)), b_20, rt_0.line_0, rt_0.col_0, t_16.line_0, t_16.col_0, NIM_FALSE);
                  NB8 X60Qx_73;
                  if (((NI64)(segLo_0 + IL64(1))) < bcolon_0){
                    Token_0_tok9e79hf X60Qtmp_20 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(segLo_0 + IL64(1))));
                    X60Qx_73 = (X60Qtmp_20.kind_0 == IL64(1));
                    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_20));}
                  else {
                    X60Qx_73 = NIM_FALSE;}
                  if (X60Qx_73){
                    Token_0_tok9e79hf X60Qtmp_21 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(segLo_0 + IL64(1))));
                    emitName_0_parq39nt2((&(*ps_36)), b_20, (&X60Qtmp_21), rt_0.line_0, rt_0.col_0);
                    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_21));}
                  else {
                    addEmpty_0_nifjp9lau1(b_20, IL64(1));}
                  Token_0_tok9e79hf first_0 = tok_0_parq39nt2((&(*ps_36)), ((NI64)(bcolon_0 + IL64(1))));
                  addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
                    .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
                  );
                  emitInfo_0_parq39nt2((&(*ps_36)), b_20, first_0.line_0, first_0.col_0, rt_0.line_0, rt_0.col_0, NIM_FALSE);
                  NI64 sj_0 = ((NI64)(bcolon_0 + IL64(1)));
                  {
                    while (NIM_TRUE){
                      NB8 X60Qx_74;
                      if (sj_0 < rpIdx_0){
                        Token_0_tok9e79hf X60Qtmp_22 = tok_0_parq39nt2((&(*ps_36)), sj_0);
                        X60Qx_74 = (!(X60Qtmp_22.kind_0 == IL64(0)));
                        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_22));}
                      else {
                        X60Qx_74 = NIM_FALSE;}
                      if (X60Qx_74){
                        NI64 X60Qx_423 = parseStmt_1_parq39nt2(ps_36, b_20, sj_0, first_0.line_0, first_0.col_0, rpIdx_0);
                        sj_0 = X60Qx_423;
                        NB8 X60Qx_75;
                        if (sj_0 < rpIdx_0){
                          Token_0_tok9e79hf X60Qtmp_23 = tok_0_parq39nt2((&(*ps_36)), sj_0);
                          X60Qx_75 = (X60Qtmp_23.kind_0 == IL64(17));
                          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_23));}
                        else {
                          X60Qx_75 = NIM_FALSE;}
                        if (X60Qx_75){
                          inc_1_Irn1g7r1_aif7a4qfr((&sj_0));}}
                      else {
                        break;}}}
                  whileStmtLabel_4: ;
                  endTree_0_nifjp9lau1(b_20);
                  endTree_0_nifjp9lau1(b_20);
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_0));}
                else {
                  parseExprRange_1_parq39nt2(ps_36, b_20, ((NI32)segLo_0), ((NI32)rpIdx_0), t_16.line_0, t_16.col_0);}}}}}
        endTree_0_nifjp9lau1(b_20);
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&rt_0));}
      else {
        seq_0_Iotb7mc_mat7cnfv21 starts_3 = splitArgs_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)lo_20) + IL64(1))), rpIdx_0);
        string_0_sysvq0asl X60Qx_16;
        nimStrWasMoved((&X60Qx_16));
        if (IL64(1) < starts_3.len_0){
          nimStrDestroy(X60Qx_16);
          X60Qx_16 = (string_0_sysvq0asl){
            .bytes_0 = 1886745603ull, .more_0 = NIM_NIL}
          ;}
        else {
          nimStrDestroy(X60Qx_16);
          X60Qx_16 = (string_0_sysvq0asl){
            .bytes_0 = 1918988291ull, .more_0 = NIM_NIL}
          ;}
        string_0_sysvq0asl tag_9 = X60Qx_16;
        nimStrWasMoved((&X60Qx_16));
        addTree_0_nifjp9lau1(b_20, tag_9);
        emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
        parseArgList_0_parq39nt2(ps_36, b_20, ((NI32)((NI64)(((NI64)lo_20) + IL64(1)))), ((NI32)rpIdx_0), t_16.line_0, t_16.col_0);
        endTree_0_nifjp9lau1(b_20);
        nimStrDestroy(tag_9);
        nimStrDestroy(X60Qx_16);
        eQdestroy_1_Iez2nr5_mat7cnfv21(starts_3);}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&inner_0));
      eQdestroy_1_Iez2nr5_mat7cnfv21(semis_0);}
    break;
    case IL64(12):
    {
      NI64 rpIdx_1 = matchClose_0_parq39nt2((&(*ps_36)), ((NI64)lo_20));
      addTree_0_nifjp9lau1(b_20, (string_0_sysvq0asl){
        .bytes_0 = 8387227955628237319ull, .more_0 = NIM_NIL}
      );
      emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
      parseArgList_0_parq39nt2(ps_36, b_20, ((NI32)((NI64)(((NI64)lo_20) + IL64(1)))), ((NI32)rpIdx_1), t_16.line_0, t_16.col_0);
      endTree_0_nifjp9lau1(b_20);}
    break;
    case IL64(14):
    {
      NI64 rpIdx_2 = matchClose_0_parq39nt2((&(*ps_36)), ((NI64)lo_20));
      NI64 X60Qx_424 = depth0Colon_0_parq39nt2((&(*ps_36)), ((NI64)(((NI64)lo_20) + IL64(1))), rpIdx_2);
      NB8 isTab_0 = (IL64(0) <= X60Qx_424);
      string_0_sysvq0asl X60Qx_17;
      nimStrWasMoved((&X60Qx_17));
      if (isTab_0){
        nimStrDestroy(X60Qx_17);
        X60Qx_17 = (string_0_sysvq0asl){
          .bytes_0 = 8317708034442884350ull, .more_0 = (&strlit_0_I16361658452647583931_parq39nt2)}
        ;}
      else {
        nimStrDestroy(X60Qx_17);
        X60Qx_17 = (string_0_sysvq0asl){
          .bytes_0 = 133506683724549ull, .more_0 = NIM_NIL}
        ;}
      addTree_0_nifjp9lau1(b_20, X60Qx_17);
      emitInfo_0_parq39nt2((&(*ps_36)), b_20, t_16.line_0, t_16.col_0, pl_20, pc_20, NIM_FALSE);
      parseArgList_0_parq39nt2(ps_36, b_20, ((NI32)((NI64)(((NI64)lo_20) + IL64(1)))), ((NI32)rpIdx_2), t_16.line_0, t_16.col_0);
      endTree_0_nifjp9lau1(b_20);
      nimStrDestroy(X60Qx_17);}
    break;
    case IL64(1):
    case IL64(2):
    {
      emitName_0_parq39nt2((&(*ps_36)), b_20, (&t_16), pl_20, pc_20);}
    break;
    default:
    {
      addEmpty_0_nifjp9lau1(b_20, IL64(1));}
    break;}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_16));}
void parsePrimaryRange_1_parq39nt2(Parser_0_parq39nt2* ps_37, Builder_0_nifjp9lau1* b_21, NI32 lo_21, NI32 hi_21, NI32 pl_21, NI32 pc_21){
  Token_0_tok9e79hf X60Qtmp_24 = tok_0_parq39nt2((&(*ps_37)), ((NI64)lo_21));
  enterDepth_0_parq39nt2(ps_37, X60Qtmp_24.line_0);
  parsePrimaryRangeImpl_0_parq39nt2(ps_37, b_21, lo_21, hi_21, pl_21, pc_21);
  dec_1_I2mwrey1_envto7w6l1((&(*ps_37).depth_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_24));}
void parseExprRangeImpl_0_parq39nt2(Parser_0_parq39nt2* ps_38, Builder_0_nifjp9lau1* b_22, NI32 lo_22, NI32 hi_22, NI32 pl_22, NI32 pc_22){
  Token_0_tok9e79hf head_2 = tok_0_parq39nt2((&(*ps_38)), ((NI64)lo_22));
  NB8 X60Qx_425;
  if (head_2.kind_0 == IL64(2)){
    NB8 X60Qx_426;
    NB8 X60Qx_427;
    NB8 X60Qx_428;
    NB8 X60Qx_429;
    NB8 X60Qx_430;
    NB8 X60Qx_431 = eqQ_20_sysvq0asl(head_2.s_0, (string_0_sysvq0asl){
      .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
    );
    if (X60Qx_431){
      X60Qx_430 = NIM_TRUE;}
    else {
      NB8 X60Qx_432 = eqQ_20_sysvq0asl(head_2.s_0, (string_0_sysvq0asl){
        .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
      );
      X60Qx_430 = X60Qx_432;}
    if (X60Qx_430){
      X60Qx_429 = NIM_TRUE;}
    else {
      NB8 X60Qx_433 = eqQ_20_sysvq0asl(head_2.s_0, (string_0_sysvq0asl){
        .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
      );
      X60Qx_429 = X60Qx_433;}
    if (X60Qx_429){
      X60Qx_428 = NIM_TRUE;}
    else {
      NB8 X60Qx_434 = eqQ_20_sysvq0asl(head_2.s_0, (string_0_sysvq0asl){
        .bytes_0 = 427071533060ull, .more_0 = NIM_NIL}
      );
      X60Qx_428 = X60Qx_434;}
    if (X60Qx_428){
      X60Qx_427 = NIM_TRUE;}
    else {
      NB8 X60Qx_435 = eqQ_20_sysvq0asl(head_2.s_0, (string_0_sysvq0asl){
        .bytes_0 = 427054949892ull, .more_0 = NIM_NIL}
      );
      X60Qx_427 = X60Qx_435;}
    if (X60Qx_427){
      X60Qx_426 = NIM_TRUE;}
    else {
      NB8 X60Qx_436 = eqQ_20_sysvq0asl(head_2.s_0, (string_0_sysvq0asl){
        .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
      );
      X60Qx_426 = X60Qx_436;}
    X60Qx_425 = X60Qx_426;}
  else {
    X60Qx_425 = NIM_FALSE;}
  if (X60Qx_425){
    parsePrimaryRange_1_parq39nt2(ps_38, b_22, lo_22, hi_22, pl_22, pc_22);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_2));
    return;}
  {
    NI64 ce_1 = cmdCalleeEnd_0_parq39nt2((&(*ps_38)), ((NI64)lo_22), ((NI64)hi_22));
    NB8 X60Qx_437;
    NB8 X60Qx_438;
    if (head_2.kind_0 == IL64(1)){
      X60Qx_438 = (ce_1 < ((NI64)hi_22));}
    else {
      X60Qx_438 = NIM_FALSE;}
    if (X60Qx_438){
      NB8 X60Qx_439 = startsArg_0_parq39nt2((&(*ps_38)), ce_1, ((NI64)hi_22));
      X60Qx_437 = X60Qx_439;}
    else {
      X60Qx_437 = NIM_FALSE;}
    if (X60Qx_437){
      Token_0_tok9e79hf arg0_1 = tok_0_parq39nt2((&(*ps_38)), ce_1);
      addTree_0_nifjp9lau1(b_22, (string_0_sysvq0asl){
        .bytes_0 = 1684890371ull, .more_0 = NIM_NIL}
      );
      emitInfo_0_parq39nt2((&(*ps_38)), b_22, arg0_1.line_0, arg0_1.col_0, pl_22, pc_22, NIM_FALSE);
      parseExprRange_1_parq39nt2(ps_38, b_22, lo_22, ((NI32)ce_1), arg0_1.line_0, arg0_1.col_0);
      parseArgList_0_parq39nt2(ps_38, b_22, ((NI32)ce_1), hi_22, arg0_1.line_0, arg0_1.col_0);
      endTree_0_nifjp9lau1(b_22);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&arg0_1));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_2));
      return;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&arg0_1));}}
  cmdLead_0: ;
  NI64 split_0 = findSplit_0_parq39nt2((&(*ps_38)), ((NI64)lo_22), ((NI64)hi_22));
  if (split_0 < IL64(0)){
    parsePrimaryRange_1_parq39nt2(ps_38, b_22, lo_22, hi_22, pl_22, pc_22);}
  else {
    Token_0_tok9e79hf op_2 = tok_0_parq39nt2((&(*ps_38)), split_0);
    addTree_0_nifjp9lau1(b_22, (string_0_sysvq0asl){
      .bytes_0 = 132394085411077ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_38)), b_22, op_2.line_0, op_2.col_0, pl_22, pc_22, NIM_FALSE);
    addIdent_0_nifjp9lau1(b_22, op_2.s_0);
    emitInfo_0_parq39nt2((&(*ps_38)), b_22, op_2.line_0, op_2.col_0, op_2.line_0, op_2.col_0, NIM_FALSE);
    parseExprRange_1_parq39nt2(ps_38, b_22, lo_22, ((NI32)split_0), op_2.line_0, op_2.col_0);
    parseExprRange_1_parq39nt2(ps_38, b_22, ((NI32)(((NI32)split_0) + ((NI32)IL64(1)))), hi_22, op_2.line_0, op_2.col_0);
    endTree_0_nifjp9lau1(b_22);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&op_2));}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_2));}
void parseExprRange_1_parq39nt2(Parser_0_parq39nt2* ps_39, Builder_0_nifjp9lau1* b_23, NI32 lo_23, NI32 hi_23, NI32 pl_23, NI32 pc_23){
  Token_0_tok9e79hf X60Qtmp_25 = tok_0_parq39nt2((&(*ps_39)), ((NI64)lo_23));
  enterDepth_0_parq39nt2(ps_39, X60Qtmp_25.line_0);
  parseExprRangeImpl_0_parq39nt2(ps_39, b_23, lo_23, hi_23, pl_23, pc_23);
  dec_1_I2mwrey1_envto7w6l1((&(*ps_39).depth_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_25));}
NB8 isPrefixTypeKw_0_parq39nt2(string_0_sysvq0asl s_0){
  NB8 result_21;
  NB8 X60Qx_440;
  NB8 X60Qx_441;
  NB8 X60Qx_442;
  NB8 X60Qx_443;
  NB8 X60Qx_444 = eqQ_20_sysvq0asl(s_0, (string_0_sysvq0asl){
    .bytes_0 = 1717924355ull, .more_0 = NIM_NIL}
  );
  if (X60Qx_444){
    X60Qx_443 = NIM_TRUE;}
  else {
    NB8 X60Qx_445 = eqQ_20_sysvq0asl(s_0, (string_0_sysvq0asl){
      .bytes_0 = 1920233475ull, .more_0 = NIM_NIL}
    );
    X60Qx_443 = X60Qx_445;}
  if (X60Qx_443){
    X60Qx_442 = NIM_TRUE;}
  else {
    NB8 X60Qx_446 = eqQ_20_sysvq0asl(s_0, (string_0_sysvq0asl){
      .bytes_0 = 1918989827ull, .more_0 = NIM_NIL}
    );
    X60Qx_442 = X60Qx_446;}
  if (X60Qx_442){
    X60Qx_441 = NIM_TRUE;}
  else {
    NB8 X60Qx_447 = eqQ_20_sysvq0asl(s_0, (string_0_sysvq0asl){
      .bytes_0 = 1953853187ull, .more_0 = NIM_NIL}
    );
    X60Qx_441 = X60Qx_447;}
  if (X60Qx_441){
    X60Qx_440 = NIM_TRUE;}
  else {
    NB8 X60Qx_448 = eqQ_20_sysvq0asl(s_0, (string_0_sysvq0asl){
      .bytes_0 = 7164780006066447614ull, .more_0 = (&strlit_0_I3021806080610957510_parq39nt2)}
    );
    X60Qx_440 = X60Qx_448;}
  result_21 = X60Qx_440;
  return result_21;}
string_0_sysvq0asl prefixTypeTag_0_parq39nt2(string_0_sysvq0asl s_1){
  string_0_sysvq0asl result_22;
  nimStrWasMoved((&result_22));
  string_0_sysvq0asl X60Qx_18;
  nimStrWasMoved((&X60Qx_18));
  NB8 X60Qx_449 = eqQ_20_sysvq0asl(s_1, (string_0_sysvq0asl){
    .bytes_0 = 1918989827ull, .more_0 = NIM_NIL}
  );
  if (X60Qx_449){
    nimStrDestroy(X60Qx_18);
    X60Qx_18 = (string_0_sysvq0asl){
      .bytes_0 = 1953852675ull, .more_0 = NIM_NIL}
    ;}
  else {
    nimStrDestroy(X60Qx_18);
    string_0_sysvq0asl X60Qx_450 = nimStrDup(s_1);
    X60Qx_18 = X60Qx_450;}
  nimStrDestroy(result_22);
  result_22 = X60Qx_18;
  nimStrWasMoved((&X60Qx_18));
  nimStrDestroy(X60Qx_18);
  return result_22;
  nimStrDestroy(X60Qx_18);
  return result_22;}
NI64 typeExprEnd_0_parq39nt2(Parser_0_parq39nt2* ps_49, NI64 lo_27){
  NI64 result_23;
  NB8 X60Qx_76;
  Token_0_tok9e79hf X60Qtmp_26 = tok_0_parq39nt2((&(*ps_49)), lo_27);
  if (X60Qtmp_26.kind_0 == IL64(2)){
    NB8 X60Qx_77;
    Token_0_tok9e79hf X60Qtmp_27 = tok_0_parq39nt2((&(*ps_49)), lo_27);
    NB8 X60Qx_451 = eqQ_20_sysvq0asl(X60Qtmp_27.s_0, (string_0_sysvq0asl){
      .bytes_0 = 427071533060ull, .more_0 = NIM_NIL}
    );
    if (X60Qx_451){
      X60Qx_77 = NIM_TRUE;}
    else {
      Token_0_tok9e79hf X60Qtmp_28 = tok_0_parq39nt2((&(*ps_49)), lo_27);
      NB8 X60Qx_452 = eqQ_20_sysvq0asl(X60Qtmp_28.s_0, (string_0_sysvq0asl){
        .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
      );
      X60Qx_77 = X60Qx_452;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_28));}
    X60Qx_76 = X60Qx_77;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_27));}
  else {
    X60Qx_76 = NIM_FALSE;}
  NB8 procType_0 = X60Qx_76;
  NB8 retPending_0 = NIM_FALSE;
  NI64 depth_10 = IL64(0);
  NI64 i_23 = lo_27;
  Token_0_tok9e79hf X60Qtmp_29 = tok_0_parq39nt2((&(*ps_49)), lo_27);
  NI32 startLine_0 = X60Qtmp_29.line_0;
  {
    while (NIM_TRUE){
      Token_0_tok9e79hf X60Qtmp_30 = tok_0_parq39nt2((&(*ps_49)), i_23);
      if ((!(X60Qtmp_30.kind_0 == IL64(0)))){
        Token_0_tok9e79hf t_17 = tok_0_parq39nt2((&(*ps_49)), i_23);
        NB8 X60Qx_453;
        if (depth_10 == IL64(0)){
          X60Qx_453 = (t_17.kind_0 == IL64(14));}
        else {
          X60Qx_453 = NIM_FALSE;}
        if (X60Qx_453){
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_17));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_30));
          goto whileStmtLabel_0;}
        else {
          NB8 X60Qx_454 = isOpenBracket_0_parq39nt2(t_17.kind_0);
          if (X60Qx_454){
            inc_1_Irn1g7r1_aif7a4qfr((&depth_10));}
          else {
            NB8 X60Qx_455 = isCloseBracket_0_parq39nt2(t_17.kind_0);
            if (X60Qx_455){
              if (depth_10 == IL64(0)){
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_17));
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_30));
                goto whileStmtLabel_0;}
              dec_1_I2mwrey1_envto7w6l1((&depth_10));
              NB8 X60Qx_456;
              NB8 X60Qx_457;
              if (depth_10 == IL64(0)){
                X60Qx_457 = procType_0;}
              else {
                X60Qx_457 = NIM_FALSE;}
              if (X60Qx_457){
                X60Qx_456 = (t_17.kind_0 == IL64(11));}
              else {
                X60Qx_456 = NIM_FALSE;}
              if (X60Qx_456){
                retPending_0 = NIM_TRUE;}}
            else {
              if (depth_10 == IL64(0)){
                NB8 X60Qx_458;
                if (t_17.kind_0 == IL64(18)){
                  X60Qx_458 = retPending_0;}
                else {
                  X60Qx_458 = NIM_FALSE;}
                if (X60Qx_458){
                  retPending_0 = NIM_FALSE;}
                else {
                  NB8 X60Qx_459;
                  NB8 X60Qx_460;
                  if (t_17.kind_0 == IL64(16)){
                    X60Qx_460 = NIM_TRUE;}
                  else {
                    X60Qx_460 = (t_17.kind_0 == IL64(17));}
                  if (X60Qx_460){
                    X60Qx_459 = NIM_TRUE;}
                  else {
                    X60Qx_459 = (t_17.kind_0 == IL64(18));}
                  if (X60Qx_459){
                    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_17));
                    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_30));
                    goto whileStmtLabel_0;}
                  else {
                    NB8 X60Qx_461;
                    if (t_17.kind_0 == IL64(9)){
                      NB8 X60Qx_462 = eqQ_20_sysvq0asl(t_17.s_0, (string_0_sysvq0asl){
                        .bytes_0 = 15617ull, .more_0 = NIM_NIL}
                      );
                      X60Qx_461 = X60Qx_462;}
                    else {
                      X60Qx_461 = NIM_FALSE;}
                    if (X60Qx_461){
                      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_17));
                      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_30));
                      goto whileStmtLabel_0;}
                    else {
                      NB8 X60Qx_463;
                      if ((!(t_17.line_0 == startLine_0))){
                        X60Qx_463 = (((NI32)IL64(0)) <= t_17.indent_0);}
                      else {
                        X60Qx_463 = NIM_FALSE;}
                      if (X60Qx_463){
                        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_17));
                        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_30));
                        goto whileStmtLabel_0;}}}}}}}}
        inc_1_Irn1g7r1_aif7a4qfr((&i_23));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_17));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_30));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_30));}}
  whileStmtLabel_0: ;
  result_23 = i_23;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_29));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_26));
  return result_23;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_29));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_26));
  return result_23;}
void parseTypeRangeImpl_0_parq39nt2(Parser_0_parq39nt2* ps_50, Builder_0_nifjp9lau1* b_33, NI32 lo_28, NI32 hi_27, NI32 pl_33, NI32 pc_33){
  if (hi_27 <= lo_28){
    addEmpty_0_nifjp9lau1(b_33, IL64(1));
    return;}
  Token_0_tok9e79hf first_1 = tok_0_parq39nt2((&(*ps_50)), ((NI64)lo_28));
  NB8 X60Qx_464;
  if (first_1.kind_0 == IL64(2)){
    NB8 X60Qx_465 = isPrefixTypeKw_0_parq39nt2(first_1.s_0);
    X60Qx_464 = X60Qx_465;}
  else {
    X60Qx_464 = NIM_FALSE;}
  if (X60Qx_464){
    string_0_sysvq0asl X60Qtmp_31 = prefixTypeTag_0_parq39nt2(first_1.s_0);
    addTree_0_nifjp9lau1(b_33, X60Qtmp_31);
    emitInfo_0_parq39nt2((&(*ps_50)), b_33, first_1.line_0, first_1.col_0, pl_33, pc_33, NIM_FALSE);
    parseTypeRange_1_parq39nt2(ps_50, b_33, ((NI32)(lo_28 + ((NI32)IL64(1)))), hi_27, first_1.line_0, first_1.col_0);
    endTree_0_nifjp9lau1(b_33);
    nimStrDestroy(X60Qtmp_31);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_1));
    return;
    nimStrDestroy(X60Qtmp_31);}
  NB8 X60Qx_466;
  if (first_1.kind_0 == IL64(2)){
    NB8 X60Qx_467;
    NB8 X60Qx_468 = eqQ_20_sysvq0asl(first_1.s_0, (string_0_sysvq0asl){
      .bytes_0 = 427071533060ull, .more_0 = NIM_NIL}
    );
    if (X60Qx_468){
      X60Qx_467 = NIM_TRUE;}
    else {
      NB8 X60Qx_469 = eqQ_20_sysvq0asl(first_1.s_0, (string_0_sysvq0asl){
        .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
      );
      X60Qx_467 = X60Qx_469;}
    X60Qx_466 = X60Qx_467;}
  else {
    X60Qx_466 = NIM_FALSE;}
  if (X60Qx_466){
    parseProcType_1_parq39nt2(ps_50, b_33, lo_28, hi_27, pl_33, pc_33);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_1));
    return;}
  NB8 X60Qx_470;
  if (first_1.kind_0 == IL64(2)){
    NB8 X60Qx_471 = eqQ_20_sysvq0asl(first_1.s_0, (string_0_sysvq0asl){
      .bytes_0 = 111516417618949ull, .more_0 = NIM_NIL}
    );
    X60Qx_470 = X60Qx_471;}
  else {
    X60Qx_470 = NIM_FALSE;}
  if (X60Qx_470){
    parseTupleInline_1_parq39nt2(ps_50, b_33, lo_28, hi_27, pl_33, pc_33);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_1));
    return;}
  NB8 X60Qx_472;
  if (first_1.kind_0 == IL64(10)){
    NI64 X60Qx_473 = matchClose_0_parq39nt2((&(*ps_50)), ((NI64)lo_28));
    X60Qx_472 = (X60Qx_473 == ((NI64)(((NI64)hi_27) - IL64(1))));}
  else {
    X60Qx_472 = NIM_FALSE;}
  if (X60Qx_472){
    NI64 rb_2 = ((NI64)(((NI64)hi_27) - IL64(1)));
    addTree_0_nifjp9lau1(b_33, (string_0_sysvq0asl){
      .bytes_0 = 1886745603ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_50)), b_33, first_1.line_0, first_1.col_0, pl_33, pc_33, NIM_FALSE);
    seq_0_Iotb7mc_mat7cnfv21 elems_0 = splitArgs_0_parq39nt2((&(*ps_50)), ((NI64)(((NI64)lo_28) + IL64(1))), rb_2);
    {
      NI64 X60Qlf_14 = IL64(0);
      NI64 X60Qlf_15 = len_3_I12oavy1_parq39nt2(elems_0);
      NI64 X60Qlf_16 = X60Qlf_14;
      {
        while (X60Qlf_16 < X60Qlf_15){
          {
            {
              NI64* X60Qx_474 = getQ_7_Ite3z0o_parq39nt2(elems_0, X60Qlf_16);
              NI64 X60Qii_3 = (*X60Qx_474);
              NI64 X60Qx_19;
              NI64 X60Qx_475 = len_3_I12oavy1_parq39nt2(elems_0);
              if (((NI64)(X60Qlf_16 + IL64(1))) < X60Qx_475){
                NI64* X60Qx_476 = getQ_7_Ite3z0o_parq39nt2(elems_0, ((NI64)(X60Qlf_16 + IL64(1))));
                X60Qx_19 = ((NI64)((*X60Qx_476) - IL64(1)));}
              else {
                X60Qx_19 = rb_2;}
              NI64 X60Qii_4 = X60Qx_19;
              if (X60Qii_4 <= X60Qii_3){
                goto continueLabel_2;}
              NI64 X60Qii_5 = depth0Colon_0_parq39nt2((&(*ps_50)), X60Qii_3, X60Qii_4);
              if (IL64(0) <= X60Qii_5){
                Token_0_tok9e79hf X60Qii_6 = tok_0_parq39nt2((&(*ps_50)), X60Qii_3);
                addTree_0_nifjp9lau1(b_33, (string_0_sysvq0asl){
                  .bytes_0 = 7760642ull, .more_0 = NIM_NIL}
                );
                emitInfo_0_parq39nt2((&(*ps_50)), b_33, X60Qii_6.line_0, X60Qii_6.col_0, first_1.line_0, first_1.col_0, NIM_FALSE);
                addIdent_0_nifjp9lau1(b_33, X60Qii_6.s_0);
                emitInfo_0_parq39nt2((&(*ps_50)), b_33, X60Qii_6.line_0, X60Qii_6.col_0, X60Qii_6.line_0, X60Qii_6.col_0, NIM_FALSE);
                parseTypeRange_1_parq39nt2(ps_50, b_33, ((NI32)((NI64)(X60Qii_5 + IL64(1)))), ((NI32)X60Qii_4), X60Qii_6.line_0, X60Qii_6.col_0);
                endTree_0_nifjp9lau1(b_33);
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_6));}
              else {
                parseTypeRange_1_parq39nt2(ps_50, b_33, ((NI32)X60Qii_3), ((NI32)X60Qii_4), first_1.line_0, first_1.col_0);}}
            continueLabel_2: ;}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_16));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;
    endTree_0_nifjp9lau1(b_33);
    eQdestroy_1_Iez2nr5_mat7cnfv21(elems_0);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_1));
    return;
    eQdestroy_1_Iez2nr5_mat7cnfv21(elems_0);}
  NI64 sp_0 = findSplit_0_parq39nt2((&(*ps_50)), ((NI64)lo_28), ((NI64)hi_27));
  if (IL64(0) <= sp_0){
    Token_0_tok9e79hf op_3 = tok_0_parq39nt2((&(*ps_50)), sp_0);
    addTree_0_nifjp9lau1(b_33, (string_0_sysvq0asl){
      .bytes_0 = 132394085411077ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_50)), b_33, op_3.line_0, op_3.col_0, pl_33, pc_33, NIM_FALSE);
    addIdent_0_nifjp9lau1(b_33, op_3.s_0);
    emitInfo_0_parq39nt2((&(*ps_50)), b_33, op_3.line_0, op_3.col_0, op_3.line_0, op_3.col_0, NIM_FALSE);
    parseTypeRange_1_parq39nt2(ps_50, b_33, lo_28, ((NI32)sp_0), op_3.line_0, op_3.col_0);
    parseTypeRange_1_parq39nt2(ps_50, b_33, ((NI32)(((NI32)sp_0) + ((NI32)IL64(1)))), hi_27, op_3.line_0, op_3.col_0);
    endTree_0_nifjp9lau1(b_33);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&op_3));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_1));
    return;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&op_3));}
  {
    NI64 ce_2 = cmdCalleeEnd_0_parq39nt2((&(*ps_50)), ((NI64)lo_28), ((NI64)hi_27));
    NB8 X60Qx_78;
    NB8 X60Qx_79;
    Token_0_tok9e79hf X60Qtmp_32 = tok_0_parq39nt2((&(*ps_50)), ((NI64)lo_28));
    if (X60Qtmp_32.kind_0 == IL64(1)){
      X60Qx_79 = (ce_2 < ((NI64)hi_27));}
    else {
      X60Qx_79 = NIM_FALSE;}
    if (X60Qx_79){
      NB8 X60Qx_477 = startsArg_0_parq39nt2((&(*ps_50)), ce_2, ((NI64)hi_27));
      X60Qx_78 = X60Qx_477;}
    else {
      X60Qx_78 = NIM_FALSE;}
    if (X60Qx_78){
      Token_0_tok9e79hf arg0_2 = tok_0_parq39nt2((&(*ps_50)), ce_2);
      addTree_0_nifjp9lau1(b_33, (string_0_sysvq0asl){
        .bytes_0 = 1684890371ull, .more_0 = NIM_NIL}
      );
      emitInfo_0_parq39nt2((&(*ps_50)), b_33, arg0_2.line_0, arg0_2.col_0, pl_33, pc_33, NIM_FALSE);
      parseTypeRange_1_parq39nt2(ps_50, b_33, lo_28, ((NI32)ce_2), arg0_2.line_0, arg0_2.col_0);
      seq_0_Iotb7mc_mat7cnfv21 starts_4 = splitArgs_0_parq39nt2((&(*ps_50)), ce_2, ((NI64)hi_27));
      {
        NI64 X60Qlf_17 = IL64(0);
        NI64 X60Qlf_18 = len_3_I12oavy1_parq39nt2(starts_4);
        NI64 X60Qlf_19 = X60Qlf_17;
        {
          while (X60Qlf_19 < X60Qlf_18){
            {
              NI64* X60Qx_478 = getQ_7_Ite3z0o_parq39nt2(starts_4, X60Qlf_19);
              NI64 X60Qii_10 = (*X60Qx_478);
              NI64 X60Qx_20;
              NI64 X60Qx_479 = len_3_I12oavy1_parq39nt2(starts_4);
              if (((NI64)(X60Qlf_19 + IL64(1))) < X60Qx_479){
                NI64* X60Qx_480 = getQ_7_Ite3z0o_parq39nt2(starts_4, ((NI64)(X60Qlf_19 + IL64(1))));
                X60Qx_20 = ((NI64)((*X60Qx_480) - IL64(1)));}
              else {
                X60Qx_20 = ((NI64)hi_27);}
              NI64 X60Qii_11 = X60Qx_20;
              if (X60Qii_10 < X60Qii_11){
                parseTypeRange_1_parq39nt2(ps_50, b_33, ((NI32)X60Qii_10), ((NI32)X60Qii_11), arg0_2.line_0, arg0_2.col_0);}}
            inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_19));}}
        whileStmtLabel_9: ;}
      forStmtLabel_8: ;
      endTree_0_nifjp9lau1(b_33);
      eQdestroy_1_Iez2nr5_mat7cnfv21(starts_4);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&arg0_2));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_32));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_1));
      return;
      eQdestroy_1_Iez2nr5_mat7cnfv21(starts_4);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&arg0_2));}
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_32));}
  X60Qlab_7: ;
  Token_0_tok9e79hf X60Qtmp_33 = tok_0_parq39nt2((&(*ps_50)), ((NI64)(((NI64)hi_27) - IL64(1))));
  if (X60Qtmp_33.kind_0 == IL64(13)){
    NI64 depth_11 = IL64(0);
    NI64 k_10 = ((NI64)(((NI64)hi_27) - IL64(1)));
    {
      while (((NI64)lo_28) <= k_10){
        Token_0_tok9e79hf X60Qtmp_34 = tok_0_parq39nt2((&(*ps_50)), k_10);
        TokKind_0_tok9e79hf kk_1 = X60Qtmp_34.kind_0;
        NB8 X60Qx_481 = isCloseBracket_0_parq39nt2(kk_1);
        if (X60Qx_481){
          inc_1_Irn1g7r1_aif7a4qfr((&depth_11));}
        else {
          NB8 X60Qx_482 = isOpenBracket_0_parq39nt2(kk_1);
          if (X60Qx_482){
            dec_1_I2mwrey1_envto7w6l1((&depth_11));
            if (depth_11 == IL64(0)){
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_34));
              goto whileStmtLabel_12;}}}
        dec_1_I2mwrey1_envto7w6l1((&k_10));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_34));}}
    whileStmtLabel_12: ;
    NB8 X60Qx_80;
    if (((NI64)lo_28) < k_10){
      Token_0_tok9e79hf X60Qtmp_35 = tok_0_parq39nt2((&(*ps_50)), k_10);
      X60Qx_80 = (X60Qtmp_35.kind_0 == IL64(12));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_35));}
    else {
      X60Qx_80 = NIM_FALSE;}
    if (X60Qx_80){
      Token_0_tok9e79hf lb_1 = tok_0_parq39nt2((&(*ps_50)), k_10);
      addTree_0_nifjp9lau1(b_33, (string_0_sysvq0asl){
        .bytes_0 = 7627010ull, .more_0 = NIM_NIL}
      );
      emitInfo_0_parq39nt2((&(*ps_50)), b_33, lb_1.line_0, lb_1.col_0, pl_33, pc_33, NIM_FALSE);
      parseTypeRange_1_parq39nt2(ps_50, b_33, lo_28, ((NI32)k_10), lb_1.line_0, lb_1.col_0);
      seq_0_Iotb7mc_mat7cnfv21 starts_5 = splitArgs_0_parq39nt2((&(*ps_50)), ((NI64)(k_10 + IL64(1))), ((NI64)(((NI64)hi_27) - IL64(1))));
      {
        NI64 X60Qlf_20 = IL64(0);
        NI64 X60Qlf_21 = len_3_I12oavy1_parq39nt2(starts_5);
        NI64 X60Qlf_22 = X60Qlf_20;
        {
          while (X60Qlf_22 < X60Qlf_21){
            {
              NI64* X60Qx_483 = getQ_7_Ite3z0o_parq39nt2(starts_5, X60Qlf_22);
              NI64 X60Qii_15 = (*X60Qx_483);
              NI64 X60Qx_21;
              NI64 X60Qx_484 = len_3_I12oavy1_parq39nt2(starts_5);
              if (((NI64)(X60Qlf_22 + IL64(1))) < X60Qx_484){
                NI64* X60Qx_485 = getQ_7_Ite3z0o_parq39nt2(starts_5, ((NI64)(X60Qlf_22 + IL64(1))));
                X60Qx_21 = ((NI64)((*X60Qx_485) - IL64(1)));}
              else {
                X60Qx_21 = ((NI64)(((NI64)hi_27) - IL64(1)));}
              NI64 X60Qii_16 = X60Qx_21;
              if (X60Qii_15 < X60Qii_16){
                parseTypeRange_1_parq39nt2(ps_50, b_33, ((NI32)X60Qii_15), ((NI32)X60Qii_16), lb_1.line_0, lb_1.col_0);}}
            inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_22));}}
        whileStmtLabel_14: ;}
      forStmtLabel_13: ;
      endTree_0_nifjp9lau1(b_33);
      eQdestroy_1_Iez2nr5_mat7cnfv21(starts_5);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lb_1));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_33));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_1));
      return;
      eQdestroy_1_Iez2nr5_mat7cnfv21(starts_5);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lb_1));}}
  {
    NI64 depth_12 = IL64(0);
    NI64 d_2 = IL64(-1);
    NI64 i_24 = ((NI64)lo_28);
    {
      while (i_24 < ((NI64)hi_27)){
        Token_0_tok9e79hf t_18 = tok_0_parq39nt2((&(*ps_50)), i_24);
        NB8 X60Qx_486 = isOpenBracket_0_parq39nt2(t_18.kind_0);
        if (X60Qx_486){
          inc_1_Irn1g7r1_aif7a4qfr((&depth_12));}
        else {
          NB8 X60Qx_487 = isCloseBracket_0_parq39nt2(t_18.kind_0);
          if (X60Qx_487){
            if (IL64(0) < depth_12){
              dec_1_I2mwrey1_envto7w6l1((&depth_12));}}
          else {
            NB8 X60Qx_488;
            NB8 X60Qx_489;
            if (depth_12 == IL64(0)){
              X60Qx_489 = (t_18.kind_0 == IL64(19));}
            else {
              X60Qx_489 = NIM_FALSE;}
            if (X60Qx_489){
              X60Qx_488 = (((NI64)lo_28) < i_24);}
            else {
              X60Qx_488 = NIM_FALSE;}
            if (X60Qx_488){
              d_2 = i_24;}}}
        inc_1_Irn1g7r1_aif7a4qfr((&i_24));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_18));}}
    whileStmtLabel_17: ;
    if (((NI64)lo_28) < d_2){
      Token_0_tok9e79hf dt_0 = tok_0_parq39nt2((&(*ps_50)), d_2);
      addTree_0_nifjp9lau1(b_33, (string_0_sysvq0asl){
        .bytes_0 = 1953457155ull, .more_0 = NIM_NIL}
      );
      emitInfo_0_parq39nt2((&(*ps_50)), b_33, dt_0.line_0, dt_0.col_0, pl_33, pc_33, NIM_FALSE);
      parseTypeRange_1_parq39nt2(ps_50, b_33, lo_28, ((NI32)d_2), dt_0.line_0, dt_0.col_0);
      parseTypeRange_1_parq39nt2(ps_50, b_33, ((NI32)(((NI32)d_2) + ((NI32)IL64(1)))), hi_27, dt_0.line_0, dt_0.col_0);
      endTree_0_nifjp9lau1(b_33);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&dt_0));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_33));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_1));
      return;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&dt_0));}}
  dotCase_0: ;
  Token_0_tok9e79hf t_19 = tok_0_parq39nt2((&(*ps_50)), ((NI64)lo_28));
  NB8 X60Qx_490;
  if (((NI64)hi_27) <= ((NI64)(((NI64)lo_28) + IL64(1)))){
    NB8 X60Qx_491;
    if (t_19.kind_0 == IL64(1)){
      X60Qx_491 = NIM_TRUE;}
    else {
      X60Qx_491 = (t_19.kind_0 == IL64(2));}
    X60Qx_490 = X60Qx_491;}
  else {
    X60Qx_490 = NIM_FALSE;}
  if (X60Qx_490){
    emitName_0_parq39nt2((&(*ps_50)), b_33, (&t_19), pl_33, pc_33);}
  else {
    parseExprRange_1_parq39nt2(ps_50, b_33, lo_28, hi_27, pl_33, pc_33);}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_19));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_33));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_1));}
void parseTypeRange_1_parq39nt2(Parser_0_parq39nt2* ps_51, Builder_0_nifjp9lau1* b_34, NI32 lo_29, NI32 hi_28, NI32 pl_34, NI32 pc_34){
  Token_0_tok9e79hf X60Qtmp_36 = tok_0_parq39nt2((&(*ps_51)), ((NI64)lo_29));
  enterDepth_0_parq39nt2(ps_51, X60Qtmp_36.line_0);
  parseTypeRangeImpl_0_parq39nt2(ps_51, b_34, lo_29, hi_28, pl_34, pc_34);
  dec_1_I2mwrey1_envto7w6l1((&(*ps_51).depth_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_36));}
NI64 parseType_1_parq39nt2(Parser_0_parq39nt2* ps_52, Builder_0_nifjp9lau1* b_35, NI64 idx_2, NI32 pl_35, NI32 pc_35){
  NI64 result_24;
  NI64 hi_37 = typeExprEnd_0_parq39nt2(ps_52, idx_2);
  parseTypeRange_1_parq39nt2(ps_52, b_35, ((NI32)idx_2), ((NI32)hi_37), pl_35, pc_35);
  result_24 = hi_37;
  return result_24;}
void parseTupleInline_1_parq39nt2(Parser_0_parq39nt2* ps_53, Builder_0_nifjp9lau1* b_36, NI32 lo_30, NI32 hi_29, NI32 pl_36, NI32 pc_36){
  Token_0_tok9e79hf kw_3 = tok_0_parq39nt2((&(*ps_53)), ((NI64)lo_30));
  addTree_0_nifjp9lau1(b_36, (string_0_sysvq0asl){
    .bytes_0 = 111516417618949ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_53)), b_36, kw_3.line_0, kw_3.col_0, pl_36, pc_36, NIM_FALSE);
  NI64 lb_2 = ((NI64)(((NI64)lo_30) + IL64(1)));
  {
    while (NIM_TRUE){
      NB8 X60Qx_81;
      if (lb_2 < ((NI64)hi_29)){
        Token_0_tok9e79hf X60Qtmp_37 = tok_0_parq39nt2((&(*ps_53)), lb_2);
        X60Qx_81 = (!(X60Qtmp_37.kind_0 == IL64(12)));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_37));}
      else {
        X60Qx_81 = NIM_FALSE;}
      if (X60Qx_81){
        inc_1_Irn1g7r1_aif7a4qfr((&lb_2));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  if (lb_2 < ((NI64)hi_29)){
    NI64 rb_3 = matchClose_0_parq39nt2((&(*ps_53)), lb_2);
    NI64 i_25 = ((NI64)(lb_2 + IL64(1)));
    {
      while (i_25 < rb_3){
        seq_0_Iyai4gn_lex3r1urc1 names_0 = newSeqUninit_0_I28kyaw1_lex3r1urc1(IL64(0));
        {
          while (NIM_TRUE){
            NB8 X60Qx_82;
            if (i_25 < rb_3){
              NB8 X60Qx_83;
              Token_0_tok9e79hf X60Qtmp_38 = tok_0_parq39nt2((&(*ps_53)), i_25);
              if (X60Qtmp_38.kind_0 == IL64(1)){
                X60Qx_83 = NIM_TRUE;}
              else {
                Token_0_tok9e79hf X60Qtmp_39 = tok_0_parq39nt2((&(*ps_53)), i_25);
                X60Qx_83 = (X60Qtmp_39.kind_0 == IL64(2));
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_39));}
              X60Qx_82 = X60Qx_83;
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_38));}
            else {
              X60Qx_82 = NIM_FALSE;}
            if (X60Qx_82){
              Token_0_tok9e79hf X60Qx_492 = tok_0_parq39nt2((&(*ps_53)), i_25);
              add_0_Icvfjtn_lex3r1urc1((&names_0), X60Qx_492);
              inc_1_Irn1g7r1_aif7a4qfr((&i_25));
              NB8 X60Qx_84;
              if (i_25 < rb_3){
                Token_0_tok9e79hf X60Qtmp_40 = tok_0_parq39nt2((&(*ps_53)), i_25);
                X60Qx_84 = (X60Qtmp_40.kind_0 == IL64(16));
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_40));}
              else {
                X60Qx_84 = NIM_FALSE;}
              if (X60Qx_84){
                inc_1_Irn1g7r1_aif7a4qfr((&i_25));}
              else {
                goto whileStmtLabel_2;}}
            else {
              break;}}}
        whileStmtLabel_2: ;
        NI64 tLo_0 = IL64(-1);
        NI64 tHi_0 = rb_3;
        NB8 X60Qx_85;
        if (i_25 < rb_3){
          Token_0_tok9e79hf X60Qtmp_41 = tok_0_parq39nt2((&(*ps_53)), i_25);
          X60Qx_85 = (X60Qtmp_41.kind_0 == IL64(18));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_41));}
        else {
          X60Qx_85 = NIM_FALSE;}
        if (X60Qx_85){
          tLo_0 = ((NI64)(i_25 + IL64(1)));
          NI64 d_3 = IL64(0);
          NI64 k_11 = tLo_0;
          {
            while (k_11 < rb_3){
              Token_0_tok9e79hf kk_2 = tok_0_parq39nt2((&(*ps_53)), k_11);
              NB8 X60Qx_493 = isOpenBracket_0_parq39nt2(kk_2.kind_0);
              if (X60Qx_493){
                inc_1_Irn1g7r1_aif7a4qfr((&d_3));}
              else {
                NB8 X60Qx_494 = isCloseBracket_0_parq39nt2(kk_2.kind_0);
                if (X60Qx_494){
                  if (IL64(0) < d_3){
                    dec_1_I2mwrey1_envto7w6l1((&d_3));}}
                else {
                  NB8 X60Qx_495;
                  if (d_3 == IL64(0)){
                    NB8 X60Qx_496;
                    if (kk_2.kind_0 == IL64(16)){
                      X60Qx_496 = NIM_TRUE;}
                    else {
                      X60Qx_496 = (kk_2.kind_0 == IL64(17));}
                    X60Qx_495 = X60Qx_496;}
                  else {
                    X60Qx_495 = NIM_FALSE;}
                  if (X60Qx_495){
                    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kk_2));
                    goto whileStmtLabel_3;}}}
              inc_1_Irn1g7r1_aif7a4qfr((&k_11));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kk_2));}}
          whileStmtLabel_3: ;
          tHi_0 = k_11;
          i_25 = k_11;}
        NB8 X60Qx_86;
        if (i_25 < rb_3){
          NB8 X60Qx_87;
          Token_0_tok9e79hf X60Qtmp_42 = tok_0_parq39nt2((&(*ps_53)), i_25);
          if (X60Qtmp_42.kind_0 == IL64(16)){
            X60Qx_87 = NIM_TRUE;}
          else {
            Token_0_tok9e79hf X60Qtmp_43 = tok_0_parq39nt2((&(*ps_53)), i_25);
            X60Qx_87 = (X60Qtmp_43.kind_0 == IL64(17));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_43));}
          X60Qx_86 = X60Qx_87;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_42));}
        else {
          X60Qx_86 = NIM_FALSE;}
        if (X60Qx_86){
          inc_1_Irn1g7r1_aif7a4qfr((&i_25));}
        {
          openArray_0_Iu1stc01_parq39nt2 X60Qlf_23 = toOpenArray_1_I6ofx191_parq39nt2(names_0);
          NI64 X60Qlf_24 = IL64(0);
          {
            while (NIM_TRUE){
              NI64 X60Qx_497 = len_6_Inwgz45_parq39nt2(X60Qlf_23);
              if (X60Qlf_24 < X60Qx_497){
                {
                  Token_0_tok9e79hf* X60Qii_6 = getQ_10_Iplfojn1_parq39nt2(X60Qlf_23, X60Qlf_24);
                  addTree_0_nifjp9lau1(b_36, (string_0_sysvq0asl){
                    .bytes_0 = 7760642ull, .more_0 = NIM_NIL}
                  );
                  emitInfo_0_parq39nt2((&(*ps_53)), b_36, (*X60Qii_6).line_0, (*X60Qii_6).col_0, pl_36, pc_36, NIM_FALSE);
                  addIdent_0_nifjp9lau1(b_36, (*X60Qii_6).s_0);
                  emitInfo_0_parq39nt2((&(*ps_53)), b_36, (*X60Qii_6).line_0, (*X60Qii_6).col_0, (*X60Qii_6).line_0, (*X60Qii_6).col_0, NIM_FALSE);
                  if (IL64(0) <= tLo_0){
                    parseTypeRange_1_parq39nt2(ps_53, b_36, ((NI32)tLo_0), ((NI32)tHi_0), (*X60Qii_6).line_0, (*X60Qii_6).col_0);}
                  else {
                    addEmpty_0_nifjp9lau1(b_36, IL64(1));}
                  endTree_0_nifjp9lau1(b_36);}
                inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_24));}
              else {
                break;}}}
          whileStmtLabel_5: ;}
        forStmtLabel_4: ;
        NI64 X60Qx_498 = len_3_Iefkljt1_lex3r1urc1(names_0);
        if (X60Qx_498 == IL64(0)){
          inc_1_Irn1g7r1_aif7a4qfr((&i_25));}
        eQdestroy_1_Ie8xo6a1_lex3r1urc1(names_0);}}
    whileStmtLabel_1: ;}
  endTree_0_nifjp9lau1(b_36);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_3));}
void parseProcType_1_parq39nt2(Parser_0_parq39nt2* ps_54, Builder_0_nifjp9lau1* b_37, NI32 lo_31, NI32 hi_30, NI32 pl_37, NI32 pc_37){
  Token_0_tok9e79hf kw_4 = tok_0_parq39nt2((&(*ps_54)), ((NI64)lo_31));
  string_0_sysvq0asl X60Qx_22;
  nimStrWasMoved((&X60Qx_22));
  NB8 X60Qx_499 = eqQ_20_sysvq0asl(kw_4.s_0, (string_0_sysvq0asl){
    .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
  );
  if (X60Qx_499){
    nimStrDestroy(X60Qx_22);
    X60Qx_22 = (string_0_sysvq0asl){
      .bytes_0 = 8104637039107140094ull, .more_0 = (&strlit_0_I15938251790995683266_parq39nt2)}
    ;}
  else {
    nimStrDestroy(X60Qx_22);
    X60Qx_22 = (string_0_sysvq0asl){
      .bytes_0 = 8104636974850273534ull, .more_0 = (&strlit_0_I1995551610468546737_parq39nt2)}
    ;}
  string_0_sysvq0asl tag_10 = X60Qx_22;
  nimStrWasMoved((&X60Qx_22));
  NI64 lp_1 = ((NI64)(((NI64)lo_31) + IL64(1)));
  {
    while (NIM_TRUE){
      NB8 X60Qx_88;
      if (lp_1 < ((NI64)hi_30)){
        Token_0_tok9e79hf X60Qtmp_44 = tok_0_parq39nt2((&(*ps_54)), lp_1);
        X60Qx_88 = (!(X60Qtmp_44.kind_0 == IL64(10)));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_44));}
      else {
        X60Qx_88 = NIM_FALSE;}
      if (X60Qx_88){
        inc_1_Irn1g7r1_aif7a4qfr((&lp_1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  addTree_0_nifjp9lau1(b_37, tag_10);
  if (lp_1 < ((NI64)hi_30)){
    Token_0_tok9e79hf lpTok_0 = tok_0_parq39nt2((&(*ps_54)), lp_1);
    emitInfo_0_parq39nt2((&(*ps_54)), b_37, lpTok_0.line_0, lpTok_0.col_0, pl_37, pc_37, NIM_FALSE);
    addEmpty_0_nifjp9lau1(b_37, IL64(4));
    NI64 i_26 = parseParams_1_parq39nt2(ps_54, b_37, lp_1, lpTok_0.line_0, lpTok_0.col_0);
    Token_0_tok9e79hf X60Qtmp_45 = tok_0_parq39nt2((&(*ps_54)), i_26);
    if (X60Qtmp_45.kind_0 == IL64(14)){
      NI64 X60Qx_500 = parsePragmas_1_parq39nt2(ps_54, b_37, i_26, lpTok_0.line_0, lpTok_0.col_0);
      i_26 = X60Qx_500;}
    else {
      addEmpty_0_nifjp9lau1(b_37, IL64(1));}
    addEmpty_0_nifjp9lau1(b_37, IL64(2));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_45));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lpTok_0));}
  else {
    emitInfo_0_parq39nt2((&(*ps_54)), b_37, kw_4.line_0, kw_4.col_0, pl_37, pc_37, NIM_FALSE);
    addEmpty_0_nifjp9lau1(b_37, IL64(8));}
  endTree_0_nifjp9lau1(b_37);
  nimStrDestroy(tag_10);
  nimStrDestroy(X60Qx_22);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_4));}
NI64 parsePragmas_1_parq39nt2(Parser_0_parq39nt2* ps_55, Builder_0_nifjp9lau1* b_38, NI64 braceIdx_1, NI32 pl_38, NI32 pc_38){
  NI64 result_25;
  Token_0_tok9e79hf brace_0 = tok_0_parq39nt2((&(*ps_55)), braceIdx_1);
  NI64 rb_4 = matchClose_0_parq39nt2((&(*ps_55)), braceIdx_1);
  addTree_0_nifjp9lau1(b_38, (string_0_sysvq0asl){
    .bytes_0 = 8314046677886595079ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_55)), b_38, brace_0.line_0, brace_0.col_0, pl_38, pc_38, NIM_FALSE);
  NI64 lo_37 = ((NI64)(braceIdx_1 + IL64(1)));
  NB8 X60Qx_89;
  if (lo_37 < rb_4){
    Token_0_tok9e79hf X60Qtmp_46 = tok_0_parq39nt2((&(*ps_55)), lo_37);
    X60Qx_89 = (X60Qtmp_46.kind_0 == IL64(19));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_46));}
  else {
    X60Qx_89 = NIM_FALSE;}
  if (X60Qx_89){
    inc_1_Irn1g7r1_aif7a4qfr((&lo_37));}
  NI64 hi_38 = rb_4;
  NB8 X60Qx_90;
  if (lo_37 <= ((NI64)(hi_38 - IL64(1)))){
    Token_0_tok9e79hf X60Qtmp_47 = tok_0_parq39nt2((&(*ps_55)), ((NI64)(hi_38 - IL64(1))));
    X60Qx_90 = (X60Qtmp_47.kind_0 == IL64(19));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_47));}
  else {
    X60Qx_90 = NIM_FALSE;}
  if (X60Qx_90){
    dec_1_I2mwrey1_envto7w6l1((&hi_38));}
  NB8 X60Qx_91;
  if (((NI64)(lo_37 + IL64(1))) < hi_38){
    NB8 X60Qx_92;
    Token_0_tok9e79hf X60Qtmp_48 = tok_0_parq39nt2((&(*ps_55)), lo_37);
    if (X60Qtmp_48.kind_0 == IL64(1)){
      X60Qx_92 = NIM_TRUE;}
    else {
      Token_0_tok9e79hf X60Qtmp_49 = tok_0_parq39nt2((&(*ps_55)), lo_37);
      X60Qx_92 = (X60Qtmp_49.kind_0 == IL64(2));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_49));}
    X60Qx_91 = X60Qx_92;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_48));}
  else {
    X60Qx_91 = NIM_FALSE;}
  if (X60Qx_91){
    Token_0_tok9e79hf nxt_5 = tok_0_parq39nt2((&(*ps_55)), ((NI64)(lo_37 + IL64(1))));
    NB8 X60Qx_501;
    NB8 X60Qx_502;
    NB8 X60Qx_503;
    NB8 X60Qx_504;
    if (nxt_5.kind_0 == IL64(1)){
      X60Qx_504 = NIM_TRUE;}
    else {
      X60Qx_504 = (nxt_5.kind_0 == IL64(2));}
    if (X60Qx_504){
      X60Qx_503 = NIM_TRUE;}
    else {
      X60Qx_503 = (nxt_5.kind_0 == IL64(5));}
    if (X60Qx_503){
      X60Qx_502 = NIM_TRUE;}
    else {
      X60Qx_502 = (nxt_5.kind_0 == IL64(3));}
    if (X60Qx_502){
      X60Qx_501 = NIM_TRUE;}
    else {
      X60Qx_501 = (nxt_5.kind_0 == IL64(4));}
    if (X60Qx_501){
      Token_0_tok9e79hf X60Qtmp_50 = tok_0_parq39nt2((&(*ps_55)), lo_37);
      emitName_0_parq39nt2((&(*ps_55)), b_38, (&X60Qtmp_50), brace_0.line_0, brace_0.col_0);
      inc_1_Irn1g7r1_aif7a4qfr((&lo_37));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_50));}
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_5));}
  seq_0_Iotb7mc_mat7cnfv21 starts_6 = splitArgs_0_parq39nt2((&(*ps_55)), lo_37, hi_38);
  {
    NI64 X60Qlf_25 = IL64(0);
    NI64 X60Qlf_26 = len_3_I12oavy1_parq39nt2(starts_6);
    NI64 X60Qlf_27 = X60Qlf_25;
    {
      while (X60Qlf_27 < X60Qlf_26){
        {
          NI64* X60Qx_505 = getQ_7_Ite3z0o_parq39nt2(starts_6, X60Qlf_27);
          NI64 X60Qii_2 = (*X60Qx_505);
          NI64 X60Qx_23;
          NI64 X60Qx_506 = len_3_I12oavy1_parq39nt2(starts_6);
          if (((NI64)(X60Qlf_27 + IL64(1))) < X60Qx_506){
            NI64* X60Qx_507 = getQ_7_Ite3z0o_parq39nt2(starts_6, ((NI64)(X60Qlf_27 + IL64(1))));
            X60Qx_23 = ((NI64)((*X60Qx_507) - IL64(1)));}
          else {
            X60Qx_23 = hi_38;}
          NI64 X60Qii_3 = X60Qx_23;
          if (X60Qii_2 < X60Qii_3){
            parseArg_0_parq39nt2(ps_55, b_38, ((NI32)X60Qii_2), ((NI32)X60Qii_3), brace_0.line_0, brace_0.col_0);}}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_27));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_38);
  result_25 = ((NI64)(rb_4 + IL64(1)));
  eQdestroy_1_Iez2nr5_mat7cnfv21(starts_6);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&brace_0));
  return result_25;
  eQdestroy_1_Iez2nr5_mat7cnfv21(starts_6);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&brace_0));
  return result_25;}
void emitTypevarGroup_0_parq39nt2(Parser_0_parq39nt2* ps_56, Builder_0_nifjp9lau1* b_39, NI64 gLo_0, NI64 gHi_0, NI32 tvL_0, NI32 tvC_0){
  NI64 ci_1 = gLo_0;
  seq_0_Iyai4gn_lex3r1urc1 names_1 = newSeqUninit_0_I28kyaw1_lex3r1urc1(IL64(0));
  {
    while (NIM_TRUE){
      NB8 X60Qx_93;
      if (ci_1 < gHi_0){
        NB8 X60Qx_94;
        Token_0_tok9e79hf X60Qtmp_51 = tok_0_parq39nt2((&(*ps_56)), ci_1);
        if (X60Qtmp_51.kind_0 == IL64(1)){
          X60Qx_94 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_52 = tok_0_parq39nt2((&(*ps_56)), ci_1);
          X60Qx_94 = (X60Qtmp_52.kind_0 == IL64(2));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_52));}
        X60Qx_93 = X60Qx_94;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_51));}
      else {
        X60Qx_93 = NIM_FALSE;}
      if (X60Qx_93){
        Token_0_tok9e79hf X60Qx_508 = tok_0_parq39nt2((&(*ps_56)), ci_1);
        add_0_Icvfjtn_lex3r1urc1((&names_1), X60Qx_508);
        inc_1_Irn1g7r1_aif7a4qfr((&ci_1));
        NB8 X60Qx_95;
        if (ci_1 < gHi_0){
          Token_0_tok9e79hf X60Qtmp_53 = tok_0_parq39nt2((&(*ps_56)), ci_1);
          X60Qx_95 = (X60Qtmp_53.kind_0 == IL64(16));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_53));}
        else {
          X60Qx_95 = NIM_FALSE;}
        if (X60Qx_95){
          inc_1_Irn1g7r1_aif7a4qfr((&ci_1));}
        else {
          goto whileStmtLabel_0;}}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI64 cLo_0 = IL64(-1);
  NI64 cHi_0 = gHi_0;
  NB8 X60Qx_96;
  if (ci_1 < gHi_0){
    Token_0_tok9e79hf X60Qtmp_54 = tok_0_parq39nt2((&(*ps_56)), ci_1);
    X60Qx_96 = (X60Qtmp_54.kind_0 == IL64(18));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_54));}
  else {
    X60Qx_96 = NIM_FALSE;}
  if (X60Qx_96){
    cLo_0 = ((NI64)(ci_1 + IL64(1)));}
  {
    openArray_0_Iu1stc01_parq39nt2 X60Qlf_28 = toOpenArray_1_I6ofx191_parq39nt2(names_1);
    NI64 X60Qlf_29 = IL64(0);
    {
      while (NIM_TRUE){
        NI64 X60Qx_509 = len_6_Inwgz45_parq39nt2(X60Qlf_28);
        if (X60Qlf_29 < X60Qx_509){
          {
            Token_0_tok9e79hf* X60Qii_3 = getQ_10_Iplfojn1_parq39nt2(X60Qlf_28, X60Qlf_29);
            addTree_0_nifjp9lau1(b_39, (string_0_sysvq0asl){
              .bytes_0 = 8241998971115500551ull, .more_0 = NIM_NIL}
            );
            emitInfo_0_parq39nt2((&(*ps_56)), b_39, (*X60Qii_3).line_0, (*X60Qii_3).col_0, tvL_0, tvC_0, NIM_FALSE);
            emitName_0_parq39nt2((&(*ps_56)), b_39, (&(*X60Qii_3)), (*X60Qii_3).line_0, (*X60Qii_3).col_0);
            addEmpty_0_nifjp9lau1(b_39, IL64(1));
            addEmpty_0_nifjp9lau1(b_39, IL64(1));
            if (IL64(0) <= cLo_0){
              parseTypeRange_1_parq39nt2(ps_56, b_39, ((NI32)cLo_0), ((NI32)cHi_0), (*X60Qii_3).line_0, (*X60Qii_3).col_0);}
            else {
              addEmpty_0_nifjp9lau1(b_39, IL64(1));}
            addEmpty_0_nifjp9lau1(b_39, IL64(1));
            endTree_0_nifjp9lau1(b_39);}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_29));}
        else {
          break;}}}
    whileStmtLabel_2: ;}
  forStmtLabel_1: ;
  eQdestroy_1_Ie8xo6a1_lex3r1urc1(names_1);}
NI64 parseGenerics_1_parq39nt2(Parser_0_parq39nt2* ps_57, Builder_0_nifjp9lau1* b_40, NI64 lbIdx_1, NI32 pl_39, NI32 pc_39){
  NI64 result_26;
  Token_0_tok9e79hf lb_3 = tok_0_parq39nt2((&(*ps_57)), lbIdx_1);
  NI64 rb_5 = matchClose_0_parq39nt2((&(*ps_57)), lbIdx_1);
  addTree_0_nifjp9lau1(b_40, (string_0_sysvq0asl){
    .bytes_0 = 8241998971115500798ull, .more_0 = (&strlit_0_I14656641239204103783_parq39nt2)}
  );
  emitInfo_0_parq39nt2((&(*ps_57)), b_40, lb_3.line_0, lb_3.col_0, pl_39, pc_39, NIM_FALSE);
  NI64 gstart_0 = ((NI64)(lbIdx_1 + IL64(1)));
  NI64 i_27 = ((NI64)(lbIdx_1 + IL64(1)));
  NI64 depth_13 = IL64(0);
  NB8 seenColon_0 = NIM_FALSE;
  {
    while (i_27 < rb_5){
      Token_0_tok9e79hf X60Qtmp_55 = tok_0_parq39nt2((&(*ps_57)), i_27);
      TokKind_0_tok9e79hf k_12 = X60Qtmp_55.kind_0;
      NB8 X60Qx_510 = isOpenBracket_0_parq39nt2(k_12);
      if (X60Qx_510){
        inc_1_Irn1g7r1_aif7a4qfr((&depth_13));}
      else {
        NB8 X60Qx_511 = isCloseBracket_0_parq39nt2(k_12);
        if (X60Qx_511){
          if (IL64(0) < depth_13){
            dec_1_I2mwrey1_envto7w6l1((&depth_13));}}
        else {
          NB8 X60Qx_512;
          if (depth_13 == IL64(0)){
            NB8 X60Qx_513;
            if (k_12 == IL64(17)){
              X60Qx_513 = NIM_TRUE;}
            else {
              NB8 X60Qx_514;
              if (k_12 == IL64(16)){
                X60Qx_514 = seenColon_0;}
              else {
                X60Qx_514 = NIM_FALSE;}
              X60Qx_513 = X60Qx_514;}
            X60Qx_512 = X60Qx_513;}
          else {
            X60Qx_512 = NIM_FALSE;}
          if (X60Qx_512){
            emitTypevarGroup_0_parq39nt2(ps_57, b_40, gstart_0, i_27, lb_3.line_0, lb_3.col_0);
            gstart_0 = ((NI64)(i_27 + IL64(1)));
            seenColon_0 = NIM_FALSE;}
          else {
            NB8 X60Qx_515;
            if (depth_13 == IL64(0)){
              X60Qx_515 = (k_12 == IL64(18));}
            else {
              X60Qx_515 = NIM_FALSE;}
            if (X60Qx_515){
              seenColon_0 = NIM_TRUE;}}}}
      inc_1_Irn1g7r1_aif7a4qfr((&i_27));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_55));}}
  whileStmtLabel_0: ;
  if (gstart_0 < rb_5){
    emitTypevarGroup_0_parq39nt2(ps_57, b_40, gstart_0, rb_5, lb_3.line_0, lb_3.col_0);}
  endTree_0_nifjp9lau1(b_40);
  result_26 = ((NI64)(rb_5 + IL64(1)));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lb_3));
  return result_26;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lb_3));
  return result_26;}
void splitFieldName_0_parq39nt2(Parser_0_parq39nt2* ps_58, NI64* i_4, NI64 hi_31, Token_0_tok9e79hf* nameTok_0, NB8* hasExport_0, NI64* pragLo_0, NI64* pragHi_0){
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&(*nameTok_0)));
  Token_0_tok9e79hf X60Qx_516 = tok_0_parq39nt2((&(*ps_58)), (*i_4));
  (*nameTok_0) = X60Qx_516;
  (*hasExport_0) = NIM_FALSE;
  (*pragLo_0) = IL64(-1);
  (*pragHi_0) = IL64(-1);
  inc_1_Irn1g7r1_aif7a4qfr(i_4);
  NB8 X60Qx_97;
  NB8 X60Qx_98;
  if ((*i_4) < hi_31){
    Token_0_tok9e79hf X60Qtmp_56 = tok_0_parq39nt2((&(*ps_58)), (*i_4));
    X60Qx_98 = (X60Qtmp_56.kind_0 == IL64(9));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_56));}
  else {
    X60Qx_98 = NIM_FALSE;}
  if (X60Qx_98){
    Token_0_tok9e79hf X60Qtmp_57 = tok_0_parq39nt2((&(*ps_58)), (*i_4));
    NB8 X60Qx_517 = eqQ_20_sysvq0asl(X60Qtmp_57.s_0, (string_0_sysvq0asl){
      .bytes_0 = 10753ull, .more_0 = NIM_NIL}
    );
    X60Qx_97 = X60Qx_517;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_57));}
  else {
    X60Qx_97 = NIM_FALSE;}
  if (X60Qx_97){
    (*hasExport_0) = NIM_TRUE;
    inc_1_Irn1g7r1_aif7a4qfr(i_4);}
  NB8 X60Qx_99;
  if ((*i_4) < hi_31){
    Token_0_tok9e79hf X60Qtmp_58 = tok_0_parq39nt2((&(*ps_58)), (*i_4));
    X60Qx_99 = (X60Qtmp_58.kind_0 == IL64(14));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_58));}
  else {
    X60Qx_99 = NIM_FALSE;}
  if (X60Qx_99){
    NI64 rb_6 = matchClose_0_parq39nt2((&(*ps_58)), (*i_4));
    (*pragLo_0) = (*i_4);
    (*pragHi_0) = rb_6;
    (*i_4) = ((NI64)(rb_6 + IL64(1)));}}
void emitPragmaSlot_0_parq39nt2(Parser_0_parq39nt2* ps_59, Builder_0_nifjp9lau1* b_41, NI64 pragLo_1, NI64 pragHi_1, NI32 pl_40, NI32 pc_40){
  if (IL64(0) <= pragLo_1){
    NI64 X60Qx_518 = parsePragmas_1_parq39nt2(ps_59, b_41, pragLo_1, pl_40, pc_40);}
  else {
    addEmpty_0_nifjp9lau1(b_41, IL64(1));}}
void emitFieldLine_0_parq39nt2(Parser_0_parq39nt2* ps_60, Builder_0_nifjp9lau1* b_42, NI64 fi_0, NI64 lineHi_0, NI32 kl_0, NI32 kc_0){
  NB8 X60Qx_100;
  Token_0_tok9e79hf X60Qtmp_59 = tok_0_parq39nt2((&(*ps_60)), fi_0);
  if (X60Qtmp_59.kind_0 == IL64(2)){
    NB8 X60Qx_101;
    Token_0_tok9e79hf X60Qtmp_60 = tok_0_parq39nt2((&(*ps_60)), fi_0);
    NB8 X60Qx_519 = eqQ_20_sysvq0asl(X60Qtmp_60.s_0, (string_0_sysvq0asl){
      .bytes_0 = 1818848771ull, .more_0 = NIM_NIL}
    );
    if (X60Qx_519){
      X60Qx_101 = NIM_TRUE;}
    else {
      Token_0_tok9e79hf X60Qtmp_61 = tok_0_parq39nt2((&(*ps_60)), fi_0);
      NB8 X60Qx_520 = eqQ_20_sysvq0asl(X60Qtmp_61.s_0, (string_0_sysvq0asl){
        .bytes_0 = 7237954630903751687ull, .more_0 = NIM_NIL}
      );
      X60Qx_101 = X60Qx_520;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_61));}
    X60Qx_100 = X60Qx_101;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_60));}
  else {
    X60Qx_100 = NIM_FALSE;}
  if (X60Qx_100){
    addTree_0_nifjp9lau1(b_42, (string_0_sysvq0asl){
      .bytes_0 = 1818848771ull, .more_0 = NIM_NIL}
    );
    Token_0_tok9e79hf X60Qtmp_62 = tok_0_parq39nt2((&(*ps_60)), fi_0);
    Token_0_tok9e79hf X60Qtmp_63 = tok_0_parq39nt2((&(*ps_60)), fi_0);
    emitInfo_0_parq39nt2((&(*ps_60)), b_42, X60Qtmp_62.line_0, X60Qtmp_63.col_0, kl_0, kc_0, NIM_FALSE);
    endTree_0_nifjp9lau1(b_42);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_63));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_62));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_59));
    return;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_63));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_62));}
  NI64 j_2 = fi_0;
  seq_0_Iyai4gn_lex3r1urc1 names_2 = newSeqUninit_0_I28kyaw1_lex3r1urc1(IL64(0));
  seq_0_Iflf8jf1_parq39nt2 exports_0 = newSeqUninit_0_I5mozxi1_parq39nt2(IL64(0));
  NI64 firstPragLo_0 = IL64(-1);
  NI64 firstPragHi_0 = IL64(-1);
  {
    while (NIM_TRUE){
      NB8 X60Qx_102;
      if (j_2 < lineHi_0){
        Token_0_tok9e79hf X60Qtmp_64 = tok_0_parq39nt2((&(*ps_60)), j_2);
        X60Qx_102 = (X60Qtmp_64.kind_0 == IL64(1));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_64));}
      else {
        X60Qx_102 = NIM_FALSE;}
      if (X60Qx_102){
        Token_0_tok9e79hf nm_4 = tok_0_parq39nt2((&(*ps_60)), j_2);
        NB8 ex_0 = NIM_FALSE;
        NI64 pl2_0 = IL64(-1);
        NI64 ph2_0 = IL64(-1);
        splitFieldName_0_parq39nt2(ps_60, (&j_2), lineHi_0, (&nm_4), (&ex_0), (&pl2_0), (&ph2_0));
        Token_0_tok9e79hf X60Qtmp_65 = nm_4;
        eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&nm_4));
        add_0_Icvfjtn_lex3r1urc1((&names_2), X60Qtmp_65);
        add_0_Irnc3p1_parq39nt2((&exports_0), ex_0);
        NB8 X60Qx_521;
        if (IL64(0) <= pl2_0){
          X60Qx_521 = (firstPragLo_0 < IL64(0));}
        else {
          X60Qx_521 = NIM_FALSE;}
        if (X60Qx_521){
          firstPragLo_0 = pl2_0;
          firstPragHi_0 = ph2_0;}
        NB8 X60Qx_103;
        if (j_2 < lineHi_0){
          Token_0_tok9e79hf X60Qtmp_66 = tok_0_parq39nt2((&(*ps_60)), j_2);
          X60Qx_103 = (X60Qtmp_66.kind_0 == IL64(16));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_66));}
        else {
          X60Qx_103 = NIM_FALSE;}
        if (X60Qx_103){
          inc_1_Irn1g7r1_aif7a4qfr((&j_2));}
        else {
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nm_4));
          goto whileStmtLabel_0;}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nm_4));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  NI64 tLo_1 = IL64(-1);
  NI64 tHi_1 = lineHi_0;
  NI64 vLo_0 = IL64(-1);
  NB8 X60Qx_104;
  if (j_2 < lineHi_0){
    Token_0_tok9e79hf X60Qtmp_67 = tok_0_parq39nt2((&(*ps_60)), j_2);
    X60Qx_104 = (X60Qtmp_67.kind_0 == IL64(18));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_67));}
  else {
    X60Qx_104 = NIM_FALSE;}
  if (X60Qx_104){
    inc_1_Irn1g7r1_aif7a4qfr((&j_2));
    tLo_1 = j_2;
    NI64 X60Qx_522 = typeExprEnd_0_parq39nt2(ps_60, j_2);
    tHi_1 = X60Qx_522;
    j_2 = tHi_1;
    NB8 X60Qx_105;
    if (j_2 < lineHi_0){
      Token_0_tok9e79hf X60Qtmp_68 = tok_0_parq39nt2((&(*ps_60)), j_2);
      X60Qx_105 = (X60Qtmp_68.kind_0 == IL64(14));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_68));}
    else {
      X60Qx_105 = NIM_FALSE;}
    if (X60Qx_105){
      NI64 X60Qx_523 = matchClose_0_parq39nt2((&(*ps_60)), j_2);
      j_2 = ((NI64)(X60Qx_523 + IL64(1)));
      tHi_1 = j_2;}}
  NB8 X60Qx_106;
  NB8 X60Qx_107;
  if (j_2 < lineHi_0){
    Token_0_tok9e79hf X60Qtmp_69 = tok_0_parq39nt2((&(*ps_60)), j_2);
    X60Qx_107 = (X60Qtmp_69.kind_0 == IL64(9));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_69));}
  else {
    X60Qx_107 = NIM_FALSE;}
  if (X60Qx_107){
    Token_0_tok9e79hf X60Qtmp_70 = tok_0_parq39nt2((&(*ps_60)), j_2);
    NB8 X60Qx_524 = eqQ_20_sysvq0asl(X60Qtmp_70.s_0, (string_0_sysvq0asl){
      .bytes_0 = 15617ull, .more_0 = NIM_NIL}
    );
    X60Qx_106 = X60Qx_524;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_70));}
  else {
    X60Qx_106 = NIM_FALSE;}
  if (X60Qx_106){
    vLo_0 = ((NI64)(j_2 + IL64(1)));}
  {
    NI64 X60Qlf_30 = IL64(0);
    NI64 X60Qlf_31 = len_3_Iefkljt1_lex3r1urc1(names_2);
    NI64 X60Qlf_32 = X60Qlf_30;
    {
      while (X60Qlf_32 < X60Qlf_31){
        {
          Token_0_tok9e79hf* X60Qx_525 = getQ_7_Ijq9cyk1_lex3r1urc1(names_2, X60Qlf_32);
          Token_0_tok9e79hf X60QconstRefTemp_0 = (*X60Qx_525);
          Token_0_tok9e79hf X60Qii_3 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60QconstRefTemp_0));
          NI32 X60Qx_24;
          if (IL64(0) <= firstPragLo_0){
            Token_0_tok9e79hf X60Qtmp_71 = tok_0_parq39nt2((&(*ps_60)), firstPragLo_0);
            X60Qx_24 = X60Qtmp_71.col_0;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_71));}
          else {
            NB8* X60Qx_526 = getQ_7_Iul1no9_parq39nt2(exports_0, X60Qlf_32);
            if ((*X60Qx_526)){
              X60Qx_24 = X60Qii_3.endCol_0;}
            else {
              X60Qx_24 = X60Qii_3.col_0;}}
          NI32 X60Qii_4 = X60Qx_24;
          addTree_0_nifjp9lau1(b_42, (string_0_sysvq0asl){
            .bytes_0 = 1684825603ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_60)), b_42, X60Qii_3.line_0, X60Qii_4, kl_0, kc_0, NIM_FALSE);
          emitName_0_parq39nt2((&(*ps_60)), b_42, (&X60Qii_3), X60Qii_3.line_0, X60Qii_4);
          NB8* X60Qx_527 = getQ_7_Iul1no9_parq39nt2(exports_0, X60Qlf_32);
          if ((*X60Qx_527)){
            addRaw_0_nifjp9lau1(b_42, (string_0_sysvq0asl){
              .bytes_0 = 7872514ull, .more_0 = NIM_NIL}
            );}
          else {
            addEmpty_0_nifjp9lau1(b_42, IL64(1));}
          emitPragmaSlot_0_parq39nt2(ps_60, b_42, firstPragLo_0, firstPragHi_0, X60Qii_3.line_0, X60Qii_4);
          if (IL64(0) <= tLo_1){
            parseTypeRange_1_parq39nt2(ps_60, b_42, ((NI32)tLo_1), ((NI32)tHi_1), X60Qii_3.line_0, X60Qii_4);}
          else {
            addEmpty_0_nifjp9lau1(b_42, IL64(1));}
          if (IL64(0) <= vLo_0){
            parseExprRange_1_parq39nt2(ps_60, b_42, ((NI32)vLo_0), ((NI32)lineHi_0), X60Qii_3.line_0, X60Qii_4);}
          else {
            addEmpty_0_nifjp9lau1(b_42, IL64(1));}
          endTree_0_nifjp9lau1(b_42);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_3));}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_32));}}
    whileStmtLabel_2: ;}
  forStmtLabel_1: ;
  eQdestroy_1_I7a20g9_parq39nt2(exports_0);
  eQdestroy_1_Ie8xo6a1_lex3r1urc1(names_2);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_59));}
NI64 emitFieldBody_0_parq39nt2(Parser_0_parq39nt2* ps_61, Builder_0_nifjp9lau1* b_43, NI64 colonIdx_1, NI64 defIndent_2, NI32 kl_1, NI32 kc_1){
  NI64 result_27;
  NI64 bodyStart_0 = ((NI64)(colonIdx_1 + IL64(1)));
  Token_0_tok9e79hf first_2 = tok_0_parq39nt2((&(*ps_61)), bodyStart_0);
  if (first_2.indent_0 < ((NI32)IL64(0))){
    NI64 hi_39 = lineEnd_0_parq39nt2((&(*ps_61)), bodyStart_0);
    emitFieldLine_0_parq39nt2(ps_61, b_43, bodyStart_0, hi_39, kl_1, kc_1);
    result_27 = hi_39;}
  else {
    addTree_0_nifjp9lau1(b_43, (string_0_sysvq0asl){
      .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_61)), b_43, first_2.line_0, first_2.col_0, kl_1, kc_1, NIM_FALSE);
    NI64 i_29 = bodyStart_0;
    {
      while (NIM_TRUE){
        NB8 X60Qx_108;
        Token_0_tok9e79hf X60Qtmp_72 = tok_0_parq39nt2((&(*ps_61)), i_29);
        if ((!(X60Qtmp_72.kind_0 == IL64(0)))){
          Token_0_tok9e79hf X60Qtmp_73 = tok_0_parq39nt2((&(*ps_61)), i_29);
          X60Qx_108 = (((NI32)defIndent_2) < X60Qtmp_73.indent_0);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_73));}
        else {
          X60Qx_108 = NIM_FALSE;}
        if (X60Qx_108){
          {
            Token_0_tok9e79hf X60Qtmp_74 = tok_0_parq39nt2((&(*ps_61)), i_29);
            if (X60Qtmp_74.kind_0 == IL64(20)){
              inc_1_Irn1g7r1_aif7a4qfr((&i_29));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_74));
              goto continueLabel_1;}
            NI64 lh_0 = lineEnd_0_parq39nt2((&(*ps_61)), i_29);
            emitFieldLine_0_parq39nt2(ps_61, b_43, i_29, lh_0, first_2.line_0, first_2.col_0);
            i_29 = lh_0;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_74));}
          continueLabel_1: ;}
        else {
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_72));
          break;}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_72));}}
    whileStmtLabel_0: ;
    endTree_0_nifjp9lau1(b_43);
    result_27 = i_29;}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_2));
  return result_27;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_2));
  return result_27;}
NI64 parseObjectCase_0_parq39nt2(Parser_0_parq39nt2* ps_62, Builder_0_nifjp9lau1* b_44, NI64 caseIdx_0, NI64 defIndent_3, NI32 kl_2, NI32 kc_2){
  NI64 result_28;
  Token_0_tok9e79hf kw_5 = tok_0_parq39nt2((&(*ps_62)), caseIdx_0);
  addTree_0_nifjp9lau1(b_44, (string_0_sysvq0asl){
    .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_62)), b_44, kw_5.line_0, kw_5.col_0, kl_2, kc_2, NIM_FALSE);
  NI64 caseHi_0 = lineEnd_0_parq39nt2((&(*ps_62)), caseIdx_0);
  emitFieldLine_0_parq39nt2(ps_62, b_44, ((NI64)(caseIdx_0 + IL64(1))), caseHi_0, kw_5.line_0, kw_5.col_0);
  NI64 i_30 = caseHi_0;
  NI32 refIndent_3 = kw_5.col_0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_109;
      NB8 X60Qx_110;
      NB8 X60Qx_111;
      Token_0_tok9e79hf X60Qtmp_75 = tok_0_parq39nt2((&(*ps_62)), i_30);
      if ((!(X60Qtmp_75.kind_0 == IL64(0)))){
        Token_0_tok9e79hf X60Qtmp_76 = tok_0_parq39nt2((&(*ps_62)), i_30);
        X60Qx_111 = (((NI32)refIndent_3) <= X60Qtmp_76.indent_0);
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_76));}
      else {
        X60Qx_111 = NIM_FALSE;}
      if (X60Qx_111){
        Token_0_tok9e79hf X60Qtmp_77 = tok_0_parq39nt2((&(*ps_62)), i_30);
        X60Qx_110 = (X60Qtmp_77.kind_0 == IL64(2));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_77));}
      else {
        X60Qx_110 = NIM_FALSE;}
      if (X60Qx_110){
        NB8 X60Qx_112;
        NB8 X60Qx_113;
        Token_0_tok9e79hf X60Qtmp_78 = tok_0_parq39nt2((&(*ps_62)), i_30);
        NB8 X60Qx_528 = eqQ_20_sysvq0asl(X60Qtmp_78.s_0, (string_0_sysvq0asl){
          .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_528){
          X60Qx_113 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_79 = tok_0_parq39nt2((&(*ps_62)), i_30);
          NB8 X60Qx_529 = eqQ_20_sysvq0asl(X60Qtmp_79.s_0, (string_0_sysvq0asl){
            .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
          );
          X60Qx_113 = X60Qx_529;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_79));}
        if (X60Qx_113){
          X60Qx_112 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_80 = tok_0_parq39nt2((&(*ps_62)), i_30);
          NB8 X60Qx_530 = eqQ_20_sysvq0asl(X60Qtmp_80.s_0, (string_0_sysvq0asl){
            .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
          );
          X60Qx_112 = X60Qx_530;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_80));}
        X60Qx_109 = X60Qx_112;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_78));}
      else {
        X60Qx_109 = NIM_FALSE;}
      if (X60Qx_109){
        Token_0_tok9e79hf br_1 = tok_0_parq39nt2((&(*ps_62)), i_30);
        NI64 bhi_0 = lineEnd_0_parq39nt2((&(*ps_62)), i_30);
        NI64 bcolon_1 = findColon_0_parq39nt2((&(*ps_62)), i_30, bhi_0);
        NB8 X60Qx_531 = eqQ_20_sysvq0asl(br_1.s_0, (string_0_sysvq0asl){
          .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_531){
          addTree_0_nifjp9lau1(b_44, (string_0_sysvq0asl){
            .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_62)), b_44, br_1.line_0, br_1.col_0, kw_5.line_0, kw_5.col_0, NIM_FALSE);
          addTree_0_nifjp9lau1(b_44, (string_0_sysvq0asl){
            .bytes_0 = 32481117229642246ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_62)), b_44, br_1.line_0, br_1.col_0, br_1.line_0, br_1.col_0, NIM_FALSE);
          NI64 X60Qx_25;
          if (IL64(0) <= bcolon_1){
            X60Qx_25 = bcolon_1;}
          else {
            X60Qx_25 = bhi_0;}
          seq_0_Iotb7mc_mat7cnfv21 vals_0 = splitArgs_0_parq39nt2((&(*ps_62)), ((NI64)(i_30 + IL64(1))), X60Qx_25);
          {
            NI64 X60Qlf_33 = IL64(0);
            NI64 X60Qlf_34 = len_3_I12oavy1_parq39nt2(vals_0);
            NI64 X60Qlf_35 = X60Qlf_33;
            {
              while (X60Qlf_35 < X60Qlf_34){
                {
                  NI64* X60Qx_532 = getQ_7_Ite3z0o_parq39nt2(vals_0, X60Qlf_35);
                  NI64 X60Qii_3 = (*X60Qx_532);
                  NI64 X60Qx_26;
                  NI64 X60Qx_533 = len_3_I12oavy1_parq39nt2(vals_0);
                  if (((NI64)(X60Qlf_35 + IL64(1))) < X60Qx_533){
                    NI64* X60Qx_534 = getQ_7_Ite3z0o_parq39nt2(vals_0, ((NI64)(X60Qlf_35 + IL64(1))));
                    X60Qx_26 = ((NI64)((*X60Qx_534) - IL64(1)));}
                  else {
                    NI64 X60Qx_27;
                    if (IL64(0) <= bcolon_1){
                      X60Qx_27 = bcolon_1;}
                    else {
                      X60Qx_27 = bhi_0;}
                    X60Qx_26 = X60Qx_27;}
                  NI64 X60Qii_4 = X60Qx_26;
                  if (X60Qii_3 < X60Qii_4){
                    parseExprRange_1_parq39nt2(ps_62, b_44, ((NI32)X60Qii_3), ((NI32)X60Qii_4), br_1.line_0, br_1.col_0);}}
                inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_35));}}
            whileStmtLabel_2: ;}
          forStmtLabel_1: ;
          endTree_0_nifjp9lau1(b_44);
          NI64 X60Qx_535 = emitFieldBody_0_parq39nt2(ps_62, b_44, bcolon_1, ((NI64)refIndent_3), br_1.line_0, br_1.col_0);
          i_30 = X60Qx_535;
          endTree_0_nifjp9lau1(b_44);
          eQdestroy_1_Iez2nr5_mat7cnfv21(vals_0);}
        else {
          string_0_sysvq0asl X60Qx_28;
          nimStrWasMoved((&X60Qx_28));
          NB8 X60Qx_536 = eqQ_20_sysvq0asl(br_1.s_0, (string_0_sysvq0asl){
            .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
          );
          if (X60Qx_536){
            nimStrDestroy(X60Qx_28);
            X60Qx_28 = (string_0_sysvq0asl){
              .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
            ;}
          else {
            nimStrDestroy(X60Qx_28);
            X60Qx_28 = (string_0_sysvq0asl){
              .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
            ;}
          addTree_0_nifjp9lau1(b_44, X60Qx_28);
          emitInfo_0_parq39nt2((&(*ps_62)), b_44, br_1.line_0, br_1.col_0, kw_5.line_0, kw_5.col_0, NIM_FALSE);
          NI64 X60Qx_537 = emitFieldBody_0_parq39nt2(ps_62, b_44, bcolon_1, ((NI64)refIndent_3), br_1.line_0, br_1.col_0);
          i_30 = X60Qx_537;
          endTree_0_nifjp9lau1(b_44);
          nimStrDestroy(X60Qx_28);}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&br_1));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_75));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_75));}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_44);
  result_28 = i_30;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_5));
  return result_28;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_5));
  return result_28;}
NI64 parseObjectWhen_0_parq39nt2(Parser_0_parq39nt2* ps_63, Builder_0_nifjp9lau1* b_45, NI64 whenIdx_0, NI64 defIndent_4, NI32 kl_3, NI32 kc_3){
  NI64 result_29;
  Token_0_tok9e79hf kw_6 = tok_0_parq39nt2((&(*ps_63)), whenIdx_0);
  addTree_0_nifjp9lau1(b_45, (string_0_sysvq0asl){
    .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_63)), b_45, kw_6.line_0, kw_6.col_0, kl_3, kc_3, NIM_FALSE);
  NI64 i_31 = whenIdx_0;
  NI32 refIndent_4 = kw_6.col_0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_114;
      NB8 X60Qx_115;
      Token_0_tok9e79hf X60Qtmp_81 = tok_0_parq39nt2((&(*ps_63)), i_31);
      if (X60Qtmp_81.kind_0 == IL64(2)){
        Token_0_tok9e79hf X60Qtmp_82 = tok_0_parq39nt2((&(*ps_63)), i_31);
        X60Qx_115 = (((NI32)refIndent_4) <= X60Qtmp_82.indent_0);
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_82));}
      else {
        X60Qx_115 = NIM_FALSE;}
      if (X60Qx_115){
        NB8 X60Qx_116;
        NB8 X60Qx_117;
        Token_0_tok9e79hf X60Qtmp_83 = tok_0_parq39nt2((&(*ps_63)), i_31);
        NB8 X60Qx_538 = eqQ_20_sysvq0asl(X60Qtmp_83.s_0, (string_0_sysvq0asl){
          .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_538){
          X60Qx_117 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_84 = tok_0_parq39nt2((&(*ps_63)), i_31);
          NB8 X60Qx_539 = eqQ_20_sysvq0asl(X60Qtmp_84.s_0, (string_0_sysvq0asl){
            .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
          );
          X60Qx_117 = X60Qx_539;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_84));}
        if (X60Qx_117){
          X60Qx_116 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_85 = tok_0_parq39nt2((&(*ps_63)), i_31);
          NB8 X60Qx_540 = eqQ_20_sysvq0asl(X60Qtmp_85.s_0, (string_0_sysvq0asl){
            .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
          );
          X60Qx_116 = X60Qx_540;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_85));}
        X60Qx_114 = X60Qx_116;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_83));}
      else {
        X60Qx_114 = NIM_FALSE;}
      if (X60Qx_114){
        Token_0_tok9e79hf br_2 = tok_0_parq39nt2((&(*ps_63)), i_31);
        NI64 bhi_1 = lineEnd_0_parq39nt2((&(*ps_63)), i_31);
        NI64 bcolon_2 = findColon_0_parq39nt2((&(*ps_63)), i_31, bhi_1);
        NB8 X60Qx_541 = eqQ_20_sysvq0asl(br_2.s_0, (string_0_sysvq0asl){
          .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_541){
          addTree_0_nifjp9lau1(b_45, (string_0_sysvq0asl){
            .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_63)), b_45, br_2.line_0, br_2.col_0, kw_6.line_0, kw_6.col_0, NIM_FALSE);
          NI64 X60Qx_542 = emitFieldBody_0_parq39nt2(ps_63, b_45, bcolon_2, ((NI64)refIndent_4), br_2.line_0, br_2.col_0);
          i_31 = X60Qx_542;
          endTree_0_nifjp9lau1(b_45);}
        else {
          Token_0_tok9e79hf ct_2 = tok_0_parq39nt2((&(*ps_63)), ((NI64)(i_31 + IL64(1))));
          addTree_0_nifjp9lau1(b_45, (string_0_sysvq0asl){
            .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_63)), b_45, ct_2.line_0, ct_2.col_0, kw_6.line_0, kw_6.col_0, NIM_FALSE);
          if (((NI64)(i_31 + IL64(1))) < bcolon_2){
            parseExprRange_1_parq39nt2(ps_63, b_45, ((NI32)((NI64)(i_31 + IL64(1)))), ((NI32)bcolon_2), ct_2.line_0, ct_2.col_0);}
          else {
            addEmpty_0_nifjp9lau1(b_45, IL64(1));}
          NI64 X60Qx_543 = emitFieldBody_0_parq39nt2(ps_63, b_45, bcolon_2, ((NI64)refIndent_4), ct_2.line_0, ct_2.col_0);
          i_31 = X60Qx_543;
          endTree_0_nifjp9lau1(b_45);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&ct_2));}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&br_2));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_81));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_81));}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_45);
  result_29 = i_31;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_6));
  return result_29;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_6));
  return result_29;}
NI64 parseObject_1_parq39nt2(Parser_0_parq39nt2* ps_64, Builder_0_nifjp9lau1* b_46, NI64 objIdx_1, NI64 defIndent_5, NI32 pl_41, NI32 pc_41){
  NI64 result_30;
  Token_0_tok9e79hf kw_7 = tok_0_parq39nt2((&(*ps_64)), objIdx_1);
  addTree_0_nifjp9lau1(b_46, (string_0_sysvq0asl){
    .bytes_0 = 32760384526118662ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_64)), b_46, kw_7.line_0, kw_7.col_0, pl_41, pc_41, NIM_FALSE);
  NI64 objLineEnd_0 = lineEnd_0_parq39nt2((&(*ps_64)), objIdx_1);
  NI64 i_32 = ((NI64)(objIdx_1 + IL64(1)));
  NB8 X60Qx_118;
  NB8 X60Qx_119;
  if (i_32 < objLineEnd_0){
    Token_0_tok9e79hf X60Qtmp_86 = tok_0_parq39nt2((&(*ps_64)), i_32);
    X60Qx_119 = (X60Qtmp_86.kind_0 == IL64(2));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_86));}
  else {
    X60Qx_119 = NIM_FALSE;}
  if (X60Qx_119){
    Token_0_tok9e79hf X60Qtmp_87 = tok_0_parq39nt2((&(*ps_64)), i_32);
    NB8 X60Qx_544 = eqQ_20_sysvq0asl(X60Qtmp_87.s_0, (string_0_sysvq0asl){
      .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
    );
    X60Qx_118 = X60Qx_544;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_87));}
  else {
    X60Qx_118 = NIM_FALSE;}
  if (X60Qx_118){
    inc_1_Irn1g7r1_aif7a4qfr((&i_32));
    if (i_32 < objLineEnd_0){
      Token_0_tok9e79hf pt_0 = tok_0_parq39nt2((&(*ps_64)), i_32);
      addIdent_0_nifjp9lau1(b_46, pt_0.s_0);
      emitInfo_0_parq39nt2((&(*ps_64)), b_46, pt_0.line_0, pt_0.col_0, kw_7.line_0, kw_7.col_0, NIM_FALSE);
      inc_1_Irn1g7r1_aif7a4qfr((&i_32));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&pt_0));}}
  else {
    addEmpty_0_nifjp9lau1(b_46, IL64(1));}
  NI64 fi_1 = objLineEnd_0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_120;
      Token_0_tok9e79hf X60Qtmp_88 = tok_0_parq39nt2((&(*ps_64)), fi_1);
      if ((!(X60Qtmp_88.kind_0 == IL64(0)))){
        Token_0_tok9e79hf X60Qtmp_89 = tok_0_parq39nt2((&(*ps_64)), fi_1);
        X60Qx_120 = (((NI32)defIndent_5) < X60Qtmp_89.indent_0);
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_89));}
      else {
        X60Qx_120 = NIM_FALSE;}
      if (X60Qx_120){
        {
          Token_0_tok9e79hf X60Qtmp_90 = tok_0_parq39nt2((&(*ps_64)), fi_1);
          if (X60Qtmp_90.kind_0 == IL64(20)){
            inc_1_Irn1g7r1_aif7a4qfr((&fi_1));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_90));
            goto continueLabel_1;}
          NB8 X60Qx_121;
          Token_0_tok9e79hf X60Qtmp_91 = tok_0_parq39nt2((&(*ps_64)), fi_1);
          if (X60Qtmp_91.kind_0 == IL64(2)){
            Token_0_tok9e79hf X60Qtmp_92 = tok_0_parq39nt2((&(*ps_64)), fi_1);
            NB8 X60Qx_545 = eqQ_20_sysvq0asl(X60Qtmp_92.s_0, (string_0_sysvq0asl){
              .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
            );
            X60Qx_121 = X60Qx_545;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_92));}
          else {
            X60Qx_121 = NIM_FALSE;}
          if (X60Qx_121){
            NI64 X60Qx_546 = parseObjectCase_0_parq39nt2(ps_64, b_46, fi_1, defIndent_5, kw_7.line_0, kw_7.col_0);
            fi_1 = X60Qx_546;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_91));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_90));
            goto continueLabel_1;}
          NB8 X60Qx_122;
          Token_0_tok9e79hf X60Qtmp_93 = tok_0_parq39nt2((&(*ps_64)), fi_1);
          if (X60Qtmp_93.kind_0 == IL64(2)){
            Token_0_tok9e79hf X60Qtmp_94 = tok_0_parq39nt2((&(*ps_64)), fi_1);
            NB8 X60Qx_547 = eqQ_20_sysvq0asl(X60Qtmp_94.s_0, (string_0_sysvq0asl){
              .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
            );
            X60Qx_122 = X60Qx_547;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_94));}
          else {
            X60Qx_122 = NIM_FALSE;}
          if (X60Qx_122){
            NI64 X60Qx_548 = parseObjectWhen_0_parq39nt2(ps_64, b_46, fi_1, defIndent_5, kw_7.line_0, kw_7.col_0);
            fi_1 = X60Qx_548;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_93));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_91));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_90));
            goto continueLabel_1;}
          NI64 lineHi_1 = lineEnd_0_parq39nt2((&(*ps_64)), fi_1);
          emitFieldLine_0_parq39nt2(ps_64, b_46, fi_1, lineHi_1, kw_7.line_0, kw_7.col_0);
          fi_1 = lineHi_1;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_93));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_91));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_90));}
        continueLabel_1: ;}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_88));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_88));}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_46);
  result_30 = fi_1;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_7));
  return result_30;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_7));
  return result_30;}
NI64 parseEnum_1_parq39nt2(Parser_0_parq39nt2* ps_65, Builder_0_nifjp9lau1* b_47, NI64 enumIdx_1, NI64 defIndent_6, NI32 pl_42, NI32 pc_42){
  NI64 result_31;
  Token_0_tok9e79hf kw_8 = tok_0_parq39nt2((&(*ps_65)), enumIdx_1);
  addTree_0_nifjp9lau1(b_47, (string_0_sysvq0asl){
    .bytes_0 = 470121604356ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_65)), b_47, kw_8.line_0, kw_8.col_0, pl_42, pc_42, NIM_FALSE);
  addEmpty_0_nifjp9lau1(b_47, IL64(1));
  NI64 lo_38 = lineEnd_0_parq39nt2((&(*ps_65)), enumIdx_1);
  NI64 startLo_0 = ((NI64)(enumIdx_1 + IL64(1)));
  if (startLo_0 < lo_38){
    lo_38 = startLo_0;}
  NI64 hi_40 = lo_38;
  {
    while (NIM_TRUE){
      NB8 X60Qx_123;
      Token_0_tok9e79hf X60Qtmp_95 = tok_0_parq39nt2((&(*ps_65)), hi_40);
      if ((!(X60Qtmp_95.kind_0 == IL64(0)))){
        NB8 X60Qx_124;
        Token_0_tok9e79hf X60Qtmp_96 = tok_0_parq39nt2((&(*ps_65)), hi_40);
        if (((NI32)defIndent_6) < X60Qtmp_96.indent_0){
          X60Qx_124 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_97 = tok_0_parq39nt2((&(*ps_65)), hi_40);
          X60Qx_124 = (X60Qtmp_97.indent_0 < ((NI32)IL64(0)));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_97));}
        X60Qx_123 = X60Qx_124;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_96));}
      else {
        X60Qx_123 = NIM_FALSE;}
      if (X60Qx_123){
        inc_1_Irn1g7r1_aif7a4qfr((&hi_40));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_95));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_95));}}
  whileStmtLabel_0: ;
  seq_0_Iotb7mc_mat7cnfv21 iLos_0 = newSeqUninit_0_I7whkjh1_mat7cnfv21(IL64(0));
  seq_0_Iotb7mc_mat7cnfv21 iHis_0 = newSeqUninit_0_I7whkjh1_mat7cnfv21(IL64(0));
  if (lo_38 < hi_40){
    NI64 curLo_0 = lo_38;
    NI64 d_4 = IL64(0);
    NI64 k_13 = lo_38;
    {
      while (k_13 < hi_40){
        Token_0_tok9e79hf t_20 = tok_0_parq39nt2((&(*ps_65)), k_13);
        NB8 X60Qx_549 = isOpenBracket_0_parq39nt2(t_20.kind_0);
        if (X60Qx_549){
          inc_1_Irn1g7r1_aif7a4qfr((&d_4));}
        else {
          NB8 X60Qx_550 = isCloseBracket_0_parq39nt2(t_20.kind_0);
          if (X60Qx_550){
            if (IL64(0) < d_4){
              dec_1_I2mwrey1_envto7w6l1((&d_4));}}
          else {
            NB8 X60Qx_551;
            if (d_4 == IL64(0)){
              X60Qx_551 = (t_20.kind_0 == IL64(16));}
            else {
              X60Qx_551 = NIM_FALSE;}
            if (X60Qx_551){
              add_0_I8fahwb_parq39nt2((&iLos_0), curLo_0);
              add_0_I8fahwb_parq39nt2((&iHis_0), k_13);
              curLo_0 = ((NI64)(k_13 + IL64(1)));}
            else {
              NB8 X60Qx_125;
              NB8 X60Qx_552;
              NB8 X60Qx_553;
              if (d_4 == IL64(0)){
                X60Qx_553 = (curLo_0 < k_13);}
              else {
                X60Qx_553 = NIM_FALSE;}
              if (X60Qx_553){
                X60Qx_552 = (((NI32)IL64(0)) <= t_20.indent_0);}
              else {
                X60Qx_552 = NIM_FALSE;}
              if (X60Qx_552){
                Token_0_tok9e79hf X60Qtmp_98 = tok_0_parq39nt2((&(*ps_65)), ((NI64)(k_13 - IL64(1))));
                X60Qx_125 = (!(X60Qtmp_98.kind_0 == IL64(16)));
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_98));}
              else {
                X60Qx_125 = NIM_FALSE;}
              if (X60Qx_125){
                add_0_I8fahwb_parq39nt2((&iLos_0), curLo_0);
                add_0_I8fahwb_parq39nt2((&iHis_0), k_13);
                curLo_0 = k_13;}}}}
        inc_1_Irn1g7r1_aif7a4qfr((&k_13));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_20));}}
    whileStmtLabel_1: ;
    if (curLo_0 < hi_40){
      add_0_I8fahwb_parq39nt2((&iLos_0), curLo_0);
      add_0_I8fahwb_parq39nt2((&iHis_0), hi_40);}}
  {
    NI64 X60Qlf_36 = IL64(0);
    NI64 X60Qlf_37 = len_3_I12oavy1_parq39nt2(iLos_0);
    NI64 X60Qlf_38 = X60Qlf_36;
    {
      while (X60Qlf_38 < X60Qlf_37){
        {
          {
            NI64* X60Qx_554 = getQ_7_Ite3z0o_parq39nt2(iLos_0, X60Qlf_38);
            NI64 X60Qii_5 = (*X60Qx_554);
            NI64* X60Qx_555 = getQ_7_Ite3z0o_parq39nt2(iHis_0, X60Qlf_38);
            NI64 X60Qii_6 = (*X60Qx_555);
            if (X60Qii_6 <= X60Qii_5){
              goto continueLabel_4;}
            NI64 X60Qii_7 = X60Qii_5;
            Token_0_tok9e79hf X60Qii_8 = tok_0_parq39nt2((&(*ps_65)), X60Qii_7);
            if ((!(X60Qii_8.kind_0 == IL64(1)))){
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_8));
              goto continueLabel_4;}
            inc_1_Irn1g7r1_aif7a4qfr((&X60Qii_7));
            NI64 X60Qii_9 = IL64(-1);
            NI64 X60Qii_10 = IL64(-1);
            NB8 X60Qx_126;
            if (X60Qii_7 < X60Qii_6){
              Token_0_tok9e79hf X60Qtmp_99 = tok_0_parq39nt2((&(*ps_65)), X60Qii_7);
              X60Qx_126 = (X60Qtmp_99.kind_0 == IL64(14));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_99));}
            else {
              X60Qx_126 = NIM_FALSE;}
            if (X60Qx_126){
              X60Qii_9 = X60Qii_7;
              NI64 X60Qx_556 = matchClose_0_parq39nt2((&(*ps_65)), X60Qii_7);
              X60Qii_10 = X60Qx_556;
              X60Qii_7 = ((NI64)(X60Qii_10 + IL64(1)));}
            NI64 X60Qii_11 = IL64(-1);
            NB8 X60Qx_127;
            NB8 X60Qx_128;
            if (X60Qii_7 < X60Qii_6){
              Token_0_tok9e79hf X60Qtmp_100 = tok_0_parq39nt2((&(*ps_65)), X60Qii_7);
              X60Qx_128 = (X60Qtmp_100.kind_0 == IL64(9));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_100));}
            else {
              X60Qx_128 = NIM_FALSE;}
            if (X60Qx_128){
              Token_0_tok9e79hf X60Qtmp_101 = tok_0_parq39nt2((&(*ps_65)), X60Qii_7);
              NB8 X60Qx_557 = eqQ_20_sysvq0asl(X60Qtmp_101.s_0, (string_0_sysvq0asl){
                .bytes_0 = 15617ull, .more_0 = NIM_NIL}
              );
              X60Qx_127 = X60Qx_557;
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_101));}
            else {
              X60Qx_127 = NIM_FALSE;}
            if (X60Qx_127){
              X60Qii_11 = ((NI64)(X60Qii_7 + IL64(1)));}
            Token_0_tok9e79hf X60Qx_29;
            eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_29));
            if (IL64(0) <= X60Qii_11){
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_29));
              Token_0_tok9e79hf X60Qx_558 = tok_0_parq39nt2((&(*ps_65)), X60Qii_11);
              X60Qx_29 = X60Qx_558;}
            else {
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_29));
              Token_0_tok9e79hf X60Qx_559 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_8));
              X60Qx_29 = X60Qx_559;}
            Token_0_tok9e79hf X60Qii_12 = X60Qx_29;
            eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_29));
            addTree_0_nifjp9lau1(b_47, (string_0_sysvq0asl){
              .bytes_0 = 431315379460ull, .more_0 = NIM_NIL}
            );
            emitInfo_0_parq39nt2((&(*ps_65)), b_47, X60Qii_12.line_0, X60Qii_12.col_0, kw_8.line_0, kw_8.col_0, NIM_FALSE);
            emitName_0_parq39nt2((&(*ps_65)), b_47, (&X60Qii_8), X60Qii_12.line_0, X60Qii_12.col_0);
            addEmpty_0_nifjp9lau1(b_47, IL64(1));
            emitPragmaSlot_0_parq39nt2(ps_65, b_47, X60Qii_9, X60Qii_10, X60Qii_12.line_0, X60Qii_12.col_0);
            addEmpty_0_nifjp9lau1(b_47, IL64(1));
            if (IL64(0) <= X60Qii_11){
              parseExprRange_1_parq39nt2(ps_65, b_47, ((NI32)X60Qii_11), ((NI32)X60Qii_6), X60Qii_12.line_0, X60Qii_12.col_0);}
            else {
              addEmpty_0_nifjp9lau1(b_47, IL64(1));}
            endTree_0_nifjp9lau1(b_47);
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_12));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_29));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_8));}
          continueLabel_4: ;}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_38));}}
    whileStmtLabel_3: ;}
  forStmtLabel_2: ;
  endTree_0_nifjp9lau1(b_47);
  result_31 = hi_40;
  eQdestroy_1_Iez2nr5_mat7cnfv21(iHis_0);
  eQdestroy_1_Iez2nr5_mat7cnfv21(iLos_0);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_8));
  return result_31;
  eQdestroy_1_Iez2nr5_mat7cnfv21(iHis_0);
  eQdestroy_1_Iez2nr5_mat7cnfv21(iLos_0);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_8));
  return result_31;}
NI64 parseConcept_0_parq39nt2(Parser_0_parq39nt2* ps_66, Builder_0_nifjp9lau1* b_48, NI64 conceptIdx_0, NI64 defIndent_7, NI32 pl_43, NI32 pc_43){
  NI64 result_32;
  Token_0_tok9e79hf kw_9 = tok_0_parq39nt2((&(*ps_66)), conceptIdx_0);
  addTree_0_nifjp9lau1(b_48, (string_0_sysvq0asl){
    .bytes_0 = 8390317583520195335ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_66)), b_48, kw_9.line_0, kw_9.col_0, pl_43, pc_43, NIM_FALSE);
  NI64 hi_41 = lineEnd_0_parq39nt2((&(*ps_66)), conceptIdx_0);
  addTree_0_nifjp9lau1(b_48, (string_0_sysvq0asl){
    .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
  );
  Token_0_tok9e79hf pfirst_0 = tok_0_parq39nt2((&(*ps_66)), ((NI64)(conceptIdx_0 + IL64(1))));
  emitInfo_0_parq39nt2((&(*ps_66)), b_48, pfirst_0.line_0, pfirst_0.col_0, kw_9.line_0, kw_9.col_0, NIM_FALSE);
  NI64 pi_0 = ((NI64)(conceptIdx_0 + IL64(1)));
  {
    while (NIM_TRUE){
      NB8 X60Qx_129;
      if (pi_0 < hi_41){
        Token_0_tok9e79hf X60Qtmp_102 = tok_0_parq39nt2((&(*ps_66)), pi_0);
        X60Qx_129 = (!(X60Qtmp_102.kind_0 == IL64(0)));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_102));}
      else {
        X60Qx_129 = NIM_FALSE;}
      if (X60Qx_129){
        NI64 X60Qx_560 = parseStmt_1_parq39nt2(ps_66, b_48, pi_0, pfirst_0.line_0, pfirst_0.col_0, hi_41);
        pi_0 = X60Qx_560;}
      else {
        break;}}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_48);
  addEmpty_0_nifjp9lau1(b_48, IL64(1));
  addEmpty_0_nifjp9lau1(b_48, IL64(1));
  Token_0_tok9e79hf bodyFirst_0 = tok_0_parq39nt2((&(*ps_66)), hi_41);
  NB8 X60Qx_561;
  if ((!(bodyFirst_0.kind_0 == IL64(0)))){
    X60Qx_561 = (((NI32)defIndent_7) < bodyFirst_0.indent_0);}
  else {
    X60Qx_561 = NIM_FALSE;}
  if (X60Qx_561){
    addTree_0_nifjp9lau1(b_48, (string_0_sysvq0asl){
      .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_66)), b_48, bodyFirst_0.line_0, bodyFirst_0.col_0, kw_9.line_0, kw_9.col_0, NIM_FALSE);
    NI64 i_33 = hi_41;
    NI32 bodyRef_0 = ((NI32)(bodyFirst_0.indent_0 - ((NI32)IL64(1))));
    {
      while (NIM_TRUE){
        NB8 X60Qx_130;
        Token_0_tok9e79hf X60Qtmp_103 = tok_0_parq39nt2((&(*ps_66)), i_33);
        if ((!(X60Qtmp_103.kind_0 == IL64(0)))){
          Token_0_tok9e79hf X60Qtmp_104 = tok_0_parq39nt2((&(*ps_66)), i_33);
          X60Qx_130 = (bodyRef_0 < X60Qtmp_104.indent_0);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_104));}
        else {
          X60Qx_130 = NIM_FALSE;}
        if (X60Qx_130){
          NI64 X60Qx_562 = parseStmt_1_parq39nt2(ps_66, b_48, i_33, bodyFirst_0.line_0, bodyFirst_0.col_0, IL64(-1));
          i_33 = X60Qx_562;}
        else {
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_103));
          break;}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_103));}}
    whileStmtLabel_1: ;
    endTree_0_nifjp9lau1(b_48);
    result_32 = i_33;}
  else {
    addEmpty_0_nifjp9lau1(b_48, IL64(1));
    result_32 = hi_41;}
  endTree_0_nifjp9lau1(b_48);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&bodyFirst_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&pfirst_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_9));
  return result_32;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&bodyFirst_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&pfirst_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_9));
  return result_32;}
NI64 parseTypeDef_1_parq39nt2(Parser_0_parq39nt2* ps_67, Builder_0_nifjp9lau1* b_49, NI64 nameIdx_1, NI64 typeKwCol_1, NI32 pl_44, NI32 pc_44){
  NI64 result_33;
  NI64 i_34 = nameIdx_1;
  Token_0_tok9e79hf nameTok_2 = tok_0_parq39nt2((&(*ps_67)), nameIdx_1);
  NB8 hasExport_1 = NIM_FALSE;
  NI64 pragLo_3 = IL64(-1);
  NI64 pragHi_3 = IL64(-1);
  NI64 X60Qx_563 = len_3_Iefkljt1_lex3r1urc1((*ps_67).toks_0);
  splitFieldName_0_parq39nt2(ps_67, (&i_34), X60Qx_563, (&nameTok_2), (&hasExport_1), (&pragLo_3), (&pragHi_3));
  NI64 genIdx_0 = IL64(-1);
  NB8 X60Qx_131;
  NI64 X60Qx_564 = len_3_Iefkljt1_lex3r1urc1((*ps_67).toks_0);
  if (i_34 < X60Qx_564){
    Token_0_tok9e79hf X60Qtmp_105 = tok_0_parq39nt2((&(*ps_67)), i_34);
    X60Qx_131 = (X60Qtmp_105.kind_0 == IL64(12));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_105));}
  else {
    X60Qx_131 = NIM_FALSE;}
  if (X60Qx_131){
    genIdx_0 = i_34;
    NI64 X60Qx_565 = matchClose_0_parq39nt2((&(*ps_67)), i_34);
    i_34 = ((NI64)(X60Qx_565 + IL64(1)));}
  NI64 eqIdx_0 = IL64(-1);
  {
    NI64 k_14 = i_34;
    NI64 le_0 = lineEnd_0_parq39nt2((&(*ps_67)), nameIdx_1);
    {
      while (k_14 < le_0){
        NB8 X60Qx_132;
        Token_0_tok9e79hf X60Qtmp_106 = tok_0_parq39nt2((&(*ps_67)), k_14);
        if (X60Qtmp_106.kind_0 == IL64(9)){
          Token_0_tok9e79hf X60Qtmp_107 = tok_0_parq39nt2((&(*ps_67)), k_14);
          NB8 X60Qx_566 = eqQ_20_sysvq0asl(X60Qtmp_107.s_0, (string_0_sysvq0asl){
            .bytes_0 = 15617ull, .more_0 = NIM_NIL}
          );
          X60Qx_132 = X60Qx_566;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_107));}
        else {
          X60Qx_132 = NIM_FALSE;}
        if (X60Qx_132){
          eqIdx_0 = k_14;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_106));
          goto whileStmtLabel_1;}
        inc_1_Irn1g7r1_aif7a4qfr((&k_14));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_106));}}
    whileStmtLabel_1: ;}
  X60Qlab_0: ;
  Token_0_tok9e79hf X60Qx_30;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_30));
  if (IL64(0) <= eqIdx_0){
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_30));
    Token_0_tok9e79hf X60Qx_567 = tok_0_parq39nt2((&(*ps_67)), eqIdx_0);
    X60Qx_30 = X60Qx_567;}
  else {
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_30));
    Token_0_tok9e79hf X60Qx_568 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&nameTok_2));
    X60Qx_30 = X60Qx_568;}
  Token_0_tok9e79hf eqTok_0 = X60Qx_30;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_30));
  addTree_0_nifjp9lau1(b_49, (string_0_sysvq0asl){
    .bytes_0 = 435678704644ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_67)), b_49, eqTok_0.line_0, eqTok_0.col_0, pl_44, pc_44, NIM_FALSE);
  emitName_0_parq39nt2((&(*ps_67)), b_49, (&nameTok_2), eqTok_0.line_0, eqTok_0.col_0);
  if (hasExport_1){
    addRaw_0_nifjp9lau1(b_49, (string_0_sysvq0asl){
      .bytes_0 = 7872514ull, .more_0 = NIM_NIL}
    );}
  else {
    addEmpty_0_nifjp9lau1(b_49, IL64(1));}
  if (IL64(0) <= genIdx_0){
    NI64 X60Qx_569 = parseGenerics_1_parq39nt2(ps_67, b_49, genIdx_0, eqTok_0.line_0, eqTok_0.col_0);}
  else {
    addEmpty_0_nifjp9lau1(b_49, IL64(1));}
  emitPragmaSlot_0_parq39nt2(ps_67, b_49, pragLo_3, pragHi_3, eqTok_0.line_0, eqTok_0.col_0);
  NI64 X60Qx_31;
  if (((NI32)IL64(0)) <= nameTok_2.indent_0){
    X60Qx_31 = ((NI64)nameTok_2.indent_0);}
  else {
    X60Qx_31 = typeKwCol_1;}
  NI64 defIndent_8 = X60Qx_31;
  NI64 resultIdx_0 = lineEnd_0_parq39nt2((&(*ps_67)), nameIdx_1);
  if (IL64(0) <= eqIdx_0){
    NI64 rhsIdx_0 = ((NI64)(eqIdx_0 + IL64(1)));
    Token_0_tok9e79hf r_1 = tok_0_parq39nt2((&(*ps_67)), rhsIdx_0);
    NB8 X60Qx_570;
    if (r_1.kind_0 == IL64(2)){
      NB8 X60Qx_571 = eqQ_20_sysvq0asl(r_1.s_0, (string_0_sysvq0asl){
        .bytes_0 = 32760384526118662ull, .more_0 = NIM_NIL}
      );
      X60Qx_570 = X60Qx_571;}
    else {
      X60Qx_570 = NIM_FALSE;}
    if (X60Qx_570){
      NI64 X60Qx_572 = parseObject_1_parq39nt2(ps_67, b_49, rhsIdx_0, defIndent_8, eqTok_0.line_0, eqTok_0.col_0);
      resultIdx_0 = X60Qx_572;}
    else {
      NB8 X60Qx_573;
      if (r_1.kind_0 == IL64(2)){
        NB8 X60Qx_574 = eqQ_20_sysvq0asl(r_1.s_0, (string_0_sysvq0asl){
          .bytes_0 = 470121604356ull, .more_0 = NIM_NIL}
        );
        X60Qx_573 = X60Qx_574;}
      else {
        X60Qx_573 = NIM_FALSE;}
      if (X60Qx_573){
        NI64 X60Qx_575 = parseEnum_1_parq39nt2(ps_67, b_49, rhsIdx_0, defIndent_8, eqTok_0.line_0, eqTok_0.col_0);
        resultIdx_0 = X60Qx_575;}
      else {
        NB8 X60Qx_576;
        if (r_1.kind_0 == IL64(2)){
          NB8 X60Qx_577 = eqQ_20_sysvq0asl(r_1.s_0, (string_0_sysvq0asl){
            .bytes_0 = 8390317583520195335ull, .more_0 = NIM_NIL}
          );
          X60Qx_576 = X60Qx_577;}
        else {
          X60Qx_576 = NIM_FALSE;}
        if (X60Qx_576){
          NI64 X60Qx_578 = parseConcept_0_parq39nt2(ps_67, b_49, rhsIdx_0, defIndent_8, eqTok_0.line_0, eqTok_0.col_0);
          resultIdx_0 = X60Qx_578;}
        else {
          NB8 X60Qx_133;
          NB8 X60Qx_134;
          NB8 X60Qx_579;
          if (r_1.kind_0 == IL64(2)){
            NB8 X60Qx_580;
            NB8 X60Qx_581 = eqQ_20_sysvq0asl(r_1.s_0, (string_0_sysvq0asl){
              .bytes_0 = 1717924355ull, .more_0 = NIM_NIL}
            );
            if (X60Qx_581){
              X60Qx_580 = NIM_TRUE;}
            else {
              NB8 X60Qx_582 = eqQ_20_sysvq0asl(r_1.s_0, (string_0_sysvq0asl){
                .bytes_0 = 1920233475ull, .more_0 = NIM_NIL}
              );
              X60Qx_580 = X60Qx_582;}
            X60Qx_579 = X60Qx_580;}
          else {
            X60Qx_579 = NIM_FALSE;}
          if (X60Qx_579){
            Token_0_tok9e79hf X60Qtmp_108 = tok_0_parq39nt2((&(*ps_67)), ((NI64)(rhsIdx_0 + IL64(1))));
            X60Qx_134 = (X60Qtmp_108.kind_0 == IL64(2));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_108));}
          else {
            X60Qx_134 = NIM_FALSE;}
          if (X60Qx_134){
            Token_0_tok9e79hf X60Qtmp_109 = tok_0_parq39nt2((&(*ps_67)), ((NI64)(rhsIdx_0 + IL64(1))));
            NB8 X60Qx_583 = eqQ_20_sysvq0asl(X60Qtmp_109.s_0, (string_0_sysvq0asl){
              .bytes_0 = 32760384526118662ull, .more_0 = NIM_NIL}
            );
            X60Qx_133 = X60Qx_583;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_109));}
          else {
            X60Qx_133 = NIM_FALSE;}
          if (X60Qx_133){
            addTree_0_nifjp9lau1(b_49, r_1.s_0);
            emitInfo_0_parq39nt2((&(*ps_67)), b_49, r_1.line_0, r_1.col_0, eqTok_0.line_0, eqTok_0.col_0, NIM_FALSE);
            NI64 X60Qx_584 = parseObject_1_parq39nt2(ps_67, b_49, ((NI64)(rhsIdx_0 + IL64(1))), defIndent_8, r_1.line_0, r_1.col_0);
            resultIdx_0 = X60Qx_584;
            endTree_0_nifjp9lau1(b_49);}
          else {
            NI64 hi_42 = lineEnd_0_parq39nt2((&(*ps_67)), rhsIdx_0);
            parseTypeRange_1_parq39nt2(ps_67, b_49, ((NI32)rhsIdx_0), ((NI32)hi_42), eqTok_0.line_0, eqTok_0.col_0);
            resultIdx_0 = hi_42;}}}}
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&r_1));}
  else {
    addEmpty_0_nifjp9lau1(b_49, IL64(1));}
  endTree_0_nifjp9lau1(b_49);
  result_33 = resultIdx_0;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&eqTok_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_30));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nameTok_2));
  return result_33;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&eqTok_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_30));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nameTok_2));
  return result_33;}
NI64 parseTypeSection_1_parq39nt2(Parser_0_parq39nt2* ps_68, Builder_0_nifjp9lau1* b_50, NI64 kwIdx_3, NI32 pl_45, NI32 pc_45){
  NI64 result_34;
  Token_0_tok9e79hf kw_10 = tok_0_parq39nt2((&(*ps_68)), kwIdx_3);
  NI64 typeKwCol_2 = ((NI64)kw_10.col_0);
  NI64 i_35 = ((NI64)(kwIdx_3 + IL64(1)));
  NB8 X60Qx_135;
  Token_0_tok9e79hf X60Qtmp_110 = tok_0_parq39nt2((&(*ps_68)), i_35);
  if ((!(X60Qtmp_110.kind_0 == IL64(0)))){
    Token_0_tok9e79hf X60Qtmp_111 = tok_0_parq39nt2((&(*ps_68)), i_35);
    X60Qx_135 = (X60Qtmp_111.line_0 == kw_10.line_0);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_111));}
  else {
    X60Qx_135 = NIM_FALSE;}
  if (X60Qx_135){
    NI64 X60Qx_585 = parseTypeDef_1_parq39nt2(ps_68, b_50, i_35, typeKwCol_2, pl_45, pc_45);
    result_34 = X60Qx_585;}
  else {
    NI64 j_4 = i_35;
    {
      while (NIM_TRUE){
        NB8 X60Qx_136;
        Token_0_tok9e79hf X60Qtmp_112 = tok_0_parq39nt2((&(*ps_68)), j_4);
        if ((!(X60Qtmp_112.kind_0 == IL64(0)))){
          Token_0_tok9e79hf X60Qtmp_113 = tok_0_parq39nt2((&(*ps_68)), j_4);
          X60Qx_136 = (((NI32)typeKwCol_2) < X60Qtmp_113.indent_0);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_113));}
        else {
          X60Qx_136 = NIM_FALSE;}
        if (X60Qx_136){
          {
            Token_0_tok9e79hf X60Qtmp_114 = tok_0_parq39nt2((&(*ps_68)), j_4);
            if (X60Qtmp_114.kind_0 == IL64(20)){
              inc_1_Irn1g7r1_aif7a4qfr((&j_4));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_114));
              goto continueLabel_1;}
            NI64 X60Qx_586 = parseTypeDef_1_parq39nt2(ps_68, b_50, j_4, typeKwCol_2, pl_45, pc_45);
            j_4 = X60Qx_586;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_114));}
          continueLabel_1: ;}
        else {
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_112));
          break;}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_112));}}
    whileStmtLabel_0: ;
    result_34 = j_4;}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_110));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_10));
  return result_34;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_110));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_10));
  return result_34;}
NI64 parseParams_1_parq39nt2(Parser_0_parq39nt2* ps_69, Builder_0_nifjp9lau1* b_51, NI64 lpIdx_1, NI32 pl_46, NI32 pc_46){
  NI64 result_35;
  Token_0_tok9e79hf lp_2 = tok_0_parq39nt2((&(*ps_69)), lpIdx_1);
  NI64 rpIdx_3 = matchClose_0_parq39nt2((&(*ps_69)), lpIdx_1);
  addTree_0_nifjp9lau1(b_51, (string_0_sysvq0asl){
    .bytes_0 = 32489887619969030ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_69)), b_51, lp_2.line_0, lp_2.col_0, pl_46, pc_46, NIM_FALSE);
  NI64 i_36 = ((NI64)(lpIdx_1 + IL64(1)));
  {
    while (i_36 < rpIdx_3){
      seq_0_Iyai4gn_lex3r1urc1 names_3 = newSeqUninit_0_I28kyaw1_lex3r1urc1(IL64(0));
      seq_0_Iflf8jf1_parq39nt2 exports_1 = newSeqUninit_0_I5mozxi1_parq39nt2(IL64(0));
      NI64 firstPragLo_1 = IL64(-1);
      NI64 firstPragHi_1 = IL64(-1);
      {
        while (NIM_TRUE){
          NB8 X60Qx_137;
          if (i_36 < rpIdx_3){
            NB8 X60Qx_138;
            Token_0_tok9e79hf X60Qtmp_115 = tok_0_parq39nt2((&(*ps_69)), i_36);
            if (X60Qtmp_115.kind_0 == IL64(1)){
              X60Qx_138 = NIM_TRUE;}
            else {
              Token_0_tok9e79hf X60Qtmp_116 = tok_0_parq39nt2((&(*ps_69)), i_36);
              X60Qx_138 = (X60Qtmp_116.kind_0 == IL64(2));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_116));}
            X60Qx_137 = X60Qx_138;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_115));}
          else {
            X60Qx_137 = NIM_FALSE;}
          if (X60Qx_137){
            Token_0_tok9e79hf nm_6 = tok_0_parq39nt2((&(*ps_69)), i_36);
            NB8 ex_1 = NIM_FALSE;
            NI64 pl2_1 = IL64(-1);
            NI64 ph2_1 = IL64(-1);
            splitFieldName_0_parq39nt2(ps_69, (&i_36), rpIdx_3, (&nm_6), (&ex_1), (&pl2_1), (&ph2_1));
            Token_0_tok9e79hf X60Qtmp_117 = nm_6;
            eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&nm_6));
            add_0_Icvfjtn_lex3r1urc1((&names_3), X60Qtmp_117);
            add_0_Irnc3p1_parq39nt2((&exports_1), ex_1);
            NB8 X60Qx_587;
            if (IL64(0) <= pl2_1){
              X60Qx_587 = (firstPragLo_1 < IL64(0));}
            else {
              X60Qx_587 = NIM_FALSE;}
            if (X60Qx_587){
              firstPragLo_1 = pl2_1;
              firstPragHi_1 = ph2_1;}
            NB8 X60Qx_139;
            if (i_36 < rpIdx_3){
              Token_0_tok9e79hf X60Qtmp_118 = tok_0_parq39nt2((&(*ps_69)), i_36);
              X60Qx_139 = (X60Qtmp_118.kind_0 == IL64(16));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_118));}
            else {
              X60Qx_139 = NIM_FALSE;}
            if (X60Qx_139){
              inc_1_Irn1g7r1_aif7a4qfr((&i_36));}
            else {
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nm_6));
              goto whileStmtLabel_1;}
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nm_6));}
          else {
            break;}}}
      whileStmtLabel_1: ;
      NI64 tLo_2 = IL64(-1);
      NI64 tHi_2 = rpIdx_3;
      NI64 vLo_3 = IL64(-1);
      NB8 X60Qx_140;
      if (i_36 < rpIdx_3){
        Token_0_tok9e79hf X60Qtmp_119 = tok_0_parq39nt2((&(*ps_69)), i_36);
        X60Qx_140 = (X60Qtmp_119.kind_0 == IL64(18));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_119));}
      else {
        X60Qx_140 = NIM_FALSE;}
      if (X60Qx_140){
        inc_1_Irn1g7r1_aif7a4qfr((&i_36));
        tLo_2 = i_36;
        NI64 X60Qx_588 = typeExprEnd_0_parq39nt2(ps_69, i_36);
        tHi_2 = X60Qx_588;
        i_36 = tHi_2;
        NB8 X60Qx_141;
        if (i_36 < rpIdx_3){
          Token_0_tok9e79hf X60Qtmp_120 = tok_0_parq39nt2((&(*ps_69)), i_36);
          X60Qx_141 = (X60Qtmp_120.kind_0 == IL64(14));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_120));}
        else {
          X60Qx_141 = NIM_FALSE;}
        if (X60Qx_141){
          NI64 X60Qx_589 = matchClose_0_parq39nt2((&(*ps_69)), i_36);
          i_36 = ((NI64)(X60Qx_589 + IL64(1)));
          tHi_2 = i_36;}}
      NB8 X60Qx_142;
      NB8 X60Qx_143;
      if (i_36 < rpIdx_3){
        Token_0_tok9e79hf X60Qtmp_121 = tok_0_parq39nt2((&(*ps_69)), i_36);
        X60Qx_143 = (X60Qtmp_121.kind_0 == IL64(9));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_121));}
      else {
        X60Qx_143 = NIM_FALSE;}
      if (X60Qx_143){
        Token_0_tok9e79hf X60Qtmp_122 = tok_0_parq39nt2((&(*ps_69)), i_36);
        NB8 X60Qx_590 = eqQ_20_sysvq0asl(X60Qtmp_122.s_0, (string_0_sysvq0asl){
          .bytes_0 = 15617ull, .more_0 = NIM_NIL}
        );
        X60Qx_142 = X60Qx_590;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_122));}
      else {
        X60Qx_142 = NIM_FALSE;}
      if (X60Qx_142){
        inc_1_Irn1g7r1_aif7a4qfr((&i_36));
        vLo_3 = i_36;
        NI64 vd_0 = IL64(0);
        {
          while (i_36 < rpIdx_3){
            Token_0_tok9e79hf X60Qtmp_123 = tok_0_parq39nt2((&(*ps_69)), i_36);
            TokKind_0_tok9e79hf k_15 = X60Qtmp_123.kind_0;
            NB8 X60Qx_591 = isOpenBracket_0_parq39nt2(k_15);
            if (X60Qx_591){
              inc_1_Irn1g7r1_aif7a4qfr((&vd_0));}
            else {
              NB8 X60Qx_592 = isCloseBracket_0_parq39nt2(k_15);
              if (X60Qx_592){
                if (IL64(0) < vd_0){
                  dec_1_I2mwrey1_envto7w6l1((&vd_0));}}
              else {
                NB8 X60Qx_593;
                if (vd_0 == IL64(0)){
                  NB8 X60Qx_594;
                  if (k_15 == IL64(16)){
                    X60Qx_594 = NIM_TRUE;}
                  else {
                    X60Qx_594 = (k_15 == IL64(17));}
                  X60Qx_593 = X60Qx_594;}
                else {
                  X60Qx_593 = NIM_FALSE;}
                if (X60Qx_593){
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_123));
                  goto whileStmtLabel_2;}}}
            inc_1_Irn1g7r1_aif7a4qfr((&i_36));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_123));}}
        whileStmtLabel_2: ;}
      NI64 vHi_1 = i_36;
      {
        NI64 X60Qlf_39 = IL64(0);
        NI64 X60Qlf_40 = len_3_Iefkljt1_lex3r1urc1(names_3);
        NI64 X60Qlf_41 = X60Qlf_39;
        {
          while (X60Qlf_41 < X60Qlf_40){
            {
              Token_0_tok9e79hf* X60Qx_595 = getQ_7_Ijq9cyk1_lex3r1urc1(names_3, X60Qlf_41);
              Token_0_tok9e79hf X60QconstRefTemp_0 = (*X60Qx_595);
              Token_0_tok9e79hf X60Qii_5 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60QconstRefTemp_0));
              addTree_0_nifjp9lau1(b_51, (string_0_sysvq0asl){
                .bytes_0 = 120265298243589ull, .more_0 = NIM_NIL}
              );
              emitInfo_0_parq39nt2((&(*ps_69)), b_51, X60Qii_5.line_0, X60Qii_5.col_0, lp_2.line_0, lp_2.col_0, NIM_FALSE);
              emitName_0_parq39nt2((&(*ps_69)), b_51, (&X60Qii_5), X60Qii_5.line_0, X60Qii_5.col_0);
              NB8* X60Qx_596 = getQ_7_Iul1no9_parq39nt2(exports_1, X60Qlf_41);
              if ((*X60Qx_596)){
                addRaw_0_nifjp9lau1(b_51, (string_0_sysvq0asl){
                  .bytes_0 = 7872514ull, .more_0 = NIM_NIL}
                );}
              else {
                addEmpty_0_nifjp9lau1(b_51, IL64(1));}
              emitPragmaSlot_0_parq39nt2(ps_69, b_51, firstPragLo_1, firstPragHi_1, X60Qii_5.line_0, X60Qii_5.col_0);
              if (IL64(0) <= tLo_2){
                parseTypeRange_1_parq39nt2(ps_69, b_51, ((NI32)tLo_2), ((NI32)tHi_2), X60Qii_5.line_0, X60Qii_5.col_0);}
              else {
                addEmpty_0_nifjp9lau1(b_51, IL64(1));}
              if (IL64(0) <= vLo_3){
                parseExprRange_1_parq39nt2(ps_69, b_51, ((NI32)vLo_3), ((NI32)vHi_1), X60Qii_5.line_0, X60Qii_5.col_0);}
              else {
                addEmpty_0_nifjp9lau1(b_51, IL64(1));}
              endTree_0_nifjp9lau1(b_51);
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_5));}
            inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_41));}}
        whileStmtLabel_4: ;}
      forStmtLabel_3: ;
      NB8 X60Qx_144;
      if (i_36 < rpIdx_3){
        NB8 X60Qx_145;
        Token_0_tok9e79hf X60Qtmp_124 = tok_0_parq39nt2((&(*ps_69)), i_36);
        if (X60Qtmp_124.kind_0 == IL64(16)){
          X60Qx_145 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_125 = tok_0_parq39nt2((&(*ps_69)), i_36);
          X60Qx_145 = (X60Qtmp_125.kind_0 == IL64(17));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_125));}
        X60Qx_144 = X60Qx_145;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_124));}
      else {
        X60Qx_144 = NIM_FALSE;}
      if (X60Qx_144){
        inc_1_Irn1g7r1_aif7a4qfr((&i_36));}
      eQdestroy_1_I7a20g9_parq39nt2(exports_1);
      eQdestroy_1_Ie8xo6a1_lex3r1urc1(names_3);}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_51);
  NI64 j_5 = ((NI64)(rpIdx_3 + IL64(1)));
  NB8 X60Qx_146;
  Token_0_tok9e79hf X60Qtmp_126 = tok_0_parq39nt2((&(*ps_69)), j_5);
  if (X60Qtmp_126.kind_0 == IL64(18)){
    X60Qx_146 = NIM_TRUE;}
  else {
    NB8 X60Qx_147;
    Token_0_tok9e79hf X60Qtmp_127 = tok_0_parq39nt2((&(*ps_69)), j_5);
    if (X60Qtmp_127.kind_0 == IL64(9)){
      Token_0_tok9e79hf X60Qtmp_128 = tok_0_parq39nt2((&(*ps_69)), j_5);
      NB8 X60Qx_597 = eqQ_20_sysvq0asl(X60Qtmp_128.s_0, (string_0_sysvq0asl){
        .bytes_0 = 4074754ull, .more_0 = NIM_NIL}
      );
      X60Qx_147 = X60Qx_597;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_128));}
    else {
      X60Qx_147 = NIM_FALSE;}
    X60Qx_146 = X60Qx_147;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_127));}
  if (X60Qx_146){
    inc_1_Irn1g7r1_aif7a4qfr((&j_5));
    NI64 X60Qx_598 = parseType_1_parq39nt2(ps_69, b_51, j_5, lp_2.line_0, lp_2.col_0);
    j_5 = X60Qx_598;}
  else {
    addEmpty_0_nifjp9lau1(b_51, IL64(1));}
  result_35 = j_5;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_126));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lp_2));
  return result_35;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_126));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lp_2));
  return result_35;}
NI64 parseRoutine_1_parq39nt2(Parser_0_parq39nt2* ps_70, Builder_0_nifjp9lau1* b_52, NI64 kwIdx_4, NI32 pl_47, NI32 pc_47, string_0_sysvq0asl tag_2){
  NI64 result_36;
  Token_0_tok9e79hf kw_11 = tok_0_parq39nt2((&(*ps_70)), kwIdx_4);
  addTree_0_nifjp9lau1(b_52, tag_2);
  NI64 i_37 = ((NI64)(kwIdx_4 + IL64(1)));
  Token_0_tok9e79hf name_0 = tok_0_parq39nt2((&(*ps_70)), i_37);
  NB8 X60Qx_599;
  NB8 X60Qx_600;
  NB8 X60Qx_601;
  if (name_0.kind_0 == IL64(10)){
    X60Qx_601 = NIM_TRUE;}
  else {
    X60Qx_601 = (name_0.kind_0 == IL64(12));}
  if (X60Qx_601){
    X60Qx_600 = NIM_TRUE;}
  else {
    X60Qx_600 = (name_0.kind_0 == IL64(14));}
  if (X60Qx_600){
    X60Qx_599 = NIM_TRUE;}
  else {
    NB8 X60Qx_602;
    if (name_0.kind_0 == IL64(9)){
      NB8 X60Qx_603 = eqQ_20_sysvq0asl(name_0.s_0, (string_0_sysvq0asl){
        .bytes_0 = 15617ull, .more_0 = NIM_NIL}
      );
      X60Qx_602 = X60Qx_603;}
    else {
      X60Qx_602 = NIM_FALSE;}
    X60Qx_599 = X60Qx_602;}
  NB8 anon_0 = X60Qx_599;
  Token_0_tok9e79hf X60Qx_32;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_32));
  if (anon_0){
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_32));
    Token_0_tok9e79hf X60Qx_604 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&name_0));
    X60Qx_32 = X60Qx_604;}
  else {
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_32));
    Token_0_tok9e79hf X60Qx_605 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_11));
    X60Qx_32 = X60Qx_605;}
  Token_0_tok9e79hf aTok_0 = X60Qx_32;
  eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_32));
  if (anon_0){
    addEmpty_0_nifjp9lau1(b_52, IL64(1));
    emitInfo_0_parq39nt2((&(*ps_70)), b_52, aTok_0.line_0, aTok_0.col_0, pl_47, pc_47, NIM_FALSE);}
  else {
    emitInfo_0_parq39nt2((&(*ps_70)), b_52, aTok_0.line_0, aTok_0.col_0, pl_47, pc_47, NIM_FALSE);
    emitName_0_parq39nt2((&(*ps_70)), b_52, (&name_0), aTok_0.line_0, aTok_0.col_0);
    inc_1_Irn1g7r1_aif7a4qfr((&i_37));}
  NB8 X60Qx_148;
  Token_0_tok9e79hf X60Qtmp_129 = tok_0_parq39nt2((&(*ps_70)), i_37);
  if (X60Qtmp_129.kind_0 == IL64(9)){
    Token_0_tok9e79hf X60Qtmp_130 = tok_0_parq39nt2((&(*ps_70)), i_37);
    NB8 X60Qx_606 = eqQ_20_sysvq0asl(X60Qtmp_130.s_0, (string_0_sysvq0asl){
      .bytes_0 = 10753ull, .more_0 = NIM_NIL}
    );
    X60Qx_148 = X60Qx_606;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_130));}
  else {
    X60Qx_148 = NIM_FALSE;}
  if (X60Qx_148){
    inc_1_Irn1g7r1_aif7a4qfr((&i_37));
    addRaw_0_nifjp9lau1(b_52, (string_0_sysvq0asl){
      .bytes_0 = 7872514ull, .more_0 = NIM_NIL}
    );}
  else {
    addEmpty_0_nifjp9lau1(b_52, IL64(1));}
  addEmpty_0_nifjp9lau1(b_52, IL64(1));
  Token_0_tok9e79hf X60Qtmp_131 = tok_0_parq39nt2((&(*ps_70)), i_37);
  if (X60Qtmp_131.kind_0 == IL64(12)){
    NI64 X60Qx_607 = parseGenerics_1_parq39nt2(ps_70, b_52, i_37, aTok_0.line_0, aTok_0.col_0);
    i_37 = X60Qx_607;}
  else {
    addEmpty_0_nifjp9lau1(b_52, IL64(1));}
  Token_0_tok9e79hf X60Qtmp_132 = tok_0_parq39nt2((&(*ps_70)), i_37);
  if (X60Qtmp_132.kind_0 == IL64(10)){
    NI64 X60Qx_608 = parseParams_1_parq39nt2(ps_70, b_52, i_37, aTok_0.line_0, aTok_0.col_0);
    i_37 = X60Qx_608;}
  else {
    Token_0_tok9e79hf at_0 = tok_0_parq39nt2((&(*ps_70)), i_37);
    addTree_0_nifjp9lau1(b_52, (string_0_sysvq0asl){
      .bytes_0 = 32489887619969030ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_70)), b_52, at_0.line_0, at_0.col_0, aTok_0.line_0, aTok_0.col_0, NIM_FALSE);
    endTree_0_nifjp9lau1(b_52);
    Token_0_tok9e79hf X60Qtmp_133 = tok_0_parq39nt2((&(*ps_70)), i_37);
    if (X60Qtmp_133.kind_0 == IL64(18)){
      inc_1_Irn1g7r1_aif7a4qfr((&i_37));
      NI64 X60Qx_609 = parseType_1_parq39nt2(ps_70, b_52, i_37, at_0.line_0, at_0.col_0);
      i_37 = X60Qx_609;}
    else {
      addEmpty_0_nifjp9lau1(b_52, IL64(1));}
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_133));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&at_0));}
  NB8 X60Qx_149;
  Token_0_tok9e79hf X60Qtmp_134 = tok_0_parq39nt2((&(*ps_70)), i_37);
  if (X60Qtmp_134.kind_0 == IL64(14)){
    NB8 X60Qx_150;
    if ((!(*ps_70).curly_0)){
      X60Qx_150 = NIM_TRUE;}
    else {
      Token_0_tok9e79hf X60Qtmp_135 = tok_0_parq39nt2((&(*ps_70)), ((NI64)(i_37 + IL64(1))));
      X60Qx_150 = (X60Qtmp_135.kind_0 == IL64(19));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_135));}
    X60Qx_149 = X60Qx_150;}
  else {
    X60Qx_149 = NIM_FALSE;}
  if (X60Qx_149){
    NI64 X60Qx_610 = parsePragmas_1_parq39nt2(ps_70, b_52, i_37, aTok_0.line_0, aTok_0.col_0);
    i_37 = X60Qx_610;}
  else {
    addEmpty_0_nifjp9lau1(b_52, IL64(1));}
  addEmpty_0_nifjp9lau1(b_52, IL64(1));
  NB8 X60Qx_151;
  NB8 X60Qx_152;
  if ((*ps_70).curly_0){
    Token_0_tok9e79hf X60Qtmp_136 = tok_0_parq39nt2((&(*ps_70)), i_37);
    X60Qx_152 = (X60Qtmp_136.kind_0 == IL64(14));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_136));}
  else {
    X60Qx_152 = NIM_FALSE;}
  if (X60Qx_152){
    Token_0_tok9e79hf X60Qtmp_137 = tok_0_parq39nt2((&(*ps_70)), ((NI64)(i_37 + IL64(1))));
    X60Qx_151 = (!(X60Qtmp_137.kind_0 == IL64(19)));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_137));}
  else {
    X60Qx_151 = NIM_FALSE;}
  if (X60Qx_151){
    NI64 rb_7 = matchClose_0_parq39nt2((&(*ps_70)), i_37);
    Token_0_tok9e79hf first_3 = tok_0_parq39nt2((&(*ps_70)), ((NI64)(i_37 + IL64(1))));
    addTree_0_nifjp9lau1(b_52, (string_0_sysvq0asl){
      .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_70)), b_52, first_3.line_0, first_3.col_0, aTok_0.line_0, aTok_0.col_0, NIM_FALSE);
    NI64 j_6 = ((NI64)(i_37 + IL64(1)));
    {
      while (NIM_TRUE){
        NB8 X60Qx_153;
        if (j_6 < rb_7){
          Token_0_tok9e79hf X60Qtmp_138 = tok_0_parq39nt2((&(*ps_70)), j_6);
          X60Qx_153 = (!(X60Qtmp_138.kind_0 == IL64(0)));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_138));}
        else {
          X60Qx_153 = NIM_FALSE;}
        if (X60Qx_153){
          {
            Token_0_tok9e79hf X60Qtmp_139 = tok_0_parq39nt2((&(*ps_70)), j_6);
            if (X60Qtmp_139.kind_0 == IL64(20)){
              inc_1_Irn1g7r1_aif7a4qfr((&j_6));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_139));
              goto continueLabel_1;}
            NI64 X60Qx_611 = parseStmt_1_parq39nt2(ps_70, b_52, j_6, first_3.line_0, first_3.col_0, rb_7);
            j_6 = X60Qx_611;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_139));}
          continueLabel_1: ;}
        else {
          break;}}}
    whileStmtLabel_0: ;
    endTree_0_nifjp9lau1(b_52);
    i_37 = ((NI64)(rb_7 + IL64(1)));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_3));}
  else {
    NB8 X60Qx_154;
    Token_0_tok9e79hf X60Qtmp_140 = tok_0_parq39nt2((&(*ps_70)), i_37);
    if (X60Qtmp_140.kind_0 == IL64(9)){
      Token_0_tok9e79hf X60Qtmp_141 = tok_0_parq39nt2((&(*ps_70)), i_37);
      NB8 X60Qx_612 = eqQ_20_sysvq0asl(X60Qtmp_141.s_0, (string_0_sysvq0asl){
        .bytes_0 = 15617ull, .more_0 = NIM_NIL}
      );
      X60Qx_154 = X60Qx_612;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_141));}
    else {
      X60Qx_154 = NIM_FALSE;}
    if (X60Qx_154){
      inc_1_Irn1g7r1_aif7a4qfr((&i_37));
      NI32 refIndent_5 = kw_11.col_0;
      Token_0_tok9e79hf first_4 = tok_0_parq39nt2((&(*ps_70)), i_37);
      if (first_4.kind_0 == IL64(0)){
        addEmpty_0_nifjp9lau1(b_52, IL64(1));}
      else {
        if (first_4.indent_0 < ((NI32)IL64(0))){
          addTree_0_nifjp9lau1(b_52, (string_0_sysvq0asl){
            .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_70)), b_52, first_4.line_0, first_4.col_0, aTok_0.line_0, aTok_0.col_0, NIM_FALSE);
          NI64 hi_43 = lineEnd_0_parq39nt2((&(*ps_70)), i_37);
          {
            while (NIM_TRUE){
              NB8 X60Qx_155;
              if (i_37 < hi_43){
                Token_0_tok9e79hf X60Qtmp_142 = tok_0_parq39nt2((&(*ps_70)), i_37);
                X60Qx_155 = (!(X60Qtmp_142.kind_0 == IL64(0)));
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_142));}
              else {
                X60Qx_155 = NIM_FALSE;}
              if (X60Qx_155){
                NI64 X60Qx_613 = parseStmt_1_parq39nt2(ps_70, b_52, i_37, first_4.line_0, first_4.col_0, IL64(-1));
                i_37 = X60Qx_613;}
              else {
                break;}}}
          whileStmtLabel_2: ;
          endTree_0_nifjp9lau1(b_52);}
        else {
          if (refIndent_5 < first_4.indent_0){
            addTree_0_nifjp9lau1(b_52, (string_0_sysvq0asl){
              .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
            );
            emitInfo_0_parq39nt2((&(*ps_70)), b_52, first_4.line_0, first_4.col_0, aTok_0.line_0, aTok_0.col_0, NIM_FALSE);
            {
              while (NIM_TRUE){
                NB8 X60Qx_156;
                Token_0_tok9e79hf X60Qtmp_143 = tok_0_parq39nt2((&(*ps_70)), i_37);
                if ((!(X60Qtmp_143.kind_0 == IL64(0)))){
                  Token_0_tok9e79hf X60Qtmp_144 = tok_0_parq39nt2((&(*ps_70)), i_37);
                  X60Qx_156 = (refIndent_5 < X60Qtmp_144.indent_0);
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_144));}
                else {
                  X60Qx_156 = NIM_FALSE;}
                if (X60Qx_156){
                  NI64 X60Qx_614 = parseStmt_1_parq39nt2(ps_70, b_52, i_37, first_4.line_0, first_4.col_0, IL64(-1));
                  i_37 = X60Qx_614;
                  NI64 X60Qx_615 = skipTrailingDoc_1_parq39nt2((&(*ps_70)), i_37, ((NI64)first_4.indent_0));
                  i_37 = X60Qx_615;}
                else {
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_143));
                  break;}
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_143));}}
            whileStmtLabel_3: ;
            endTree_0_nifjp9lau1(b_52);}
          else {
            addEmpty_0_nifjp9lau1(b_52, IL64(1));}}}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_4));}
    else {
      addEmpty_0_nifjp9lau1(b_52, IL64(1));}
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_140));}
  endTree_0_nifjp9lau1(b_52);
  result_36 = i_37;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_134));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_132));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_131));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_129));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&aTok_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_32));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&name_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_11));
  return result_36;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_134));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_132));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_131));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_129));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&aTok_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_32));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&name_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_11));
  return result_36;}
void parseCommand_1_parq39nt2(Parser_0_parq39nt2* ps_71, Builder_0_nifjp9lau1* b_53, NI32 lo_32, NI32 hi_32, NI32 pl_48, NI32 pc_48){
  NI64 ce_3 = cmdCalleeEnd_0_parq39nt2((&(*ps_71)), ((NI64)lo_32), ((NI64)hi_32));
  Token_0_tok9e79hf anchor_0 = calleeAnchor_0_parq39nt2((&(*ps_71)), ((NI64)lo_32), ce_3);
  addTree_0_nifjp9lau1(b_53, (string_0_sysvq0asl){
    .bytes_0 = 1684890371ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_71)), b_53, anchor_0.line_0, anchor_0.col_0, pl_48, pc_48, NIM_FALSE);
  parseExprRange_1_parq39nt2(ps_71, b_53, lo_32, ((NI32)ce_3), anchor_0.line_0, anchor_0.col_0);
  parseArgList_0_parq39nt2(ps_71, b_53, ((NI32)ce_3), hi_32, anchor_0.line_0, anchor_0.col_0);
  endTree_0_nifjp9lau1(b_53);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&anchor_0));}
NI64 parseExprStmt_0_parq39nt2(Parser_0_parq39nt2* ps_72, Builder_0_nifjp9lau1* b_54, NI32 lo_33, NI32 hi_33, NI32 pl_49, NI32 pc_49){
  NI64 result_37;
  result_37 = ((NI64)hi_33);
  Token_0_tok9e79hf head_3 = tok_0_parq39nt2((&(*ps_72)), ((NI64)lo_33));
  NI64 ce_4 = cmdCalleeEnd_0_parq39nt2((&(*ps_72)), ((NI64)lo_33), ((NI64)hi_33));
  NB8 X60Qx_616;
  if (head_3.kind_0 == IL64(1)){
    X60Qx_616 = NIM_TRUE;}
  else {
    NB8 X60Qx_617;
    if (head_3.kind_0 == IL64(2)){
      NB8 X60Qx_618 = eqQ_20_sysvq0asl(head_3.s_0, (string_0_sysvq0asl){
        .bytes_0 = 491310571780ull, .more_0 = NIM_NIL}
      );
      X60Qx_617 = X60Qx_618;}
    else {
      X60Qx_617 = NIM_FALSE;}
    X60Qx_616 = X60Qx_617;}
  NB8 calleeOk_0 = X60Qx_616;
  NB8 X60Qx_619;
  NB8 X60Qx_620;
  if (calleeOk_0){
    X60Qx_620 = (ce_4 < ((NI64)hi_33));}
  else {
    X60Qx_620 = NIM_FALSE;}
  if (X60Qx_620){
    NB8 X60Qx_621 = startsArg_0_parq39nt2((&(*ps_72)), ce_4, ((NI64)hi_33));
    X60Qx_619 = X60Qx_621;}
  else {
    X60Qx_619 = NIM_FALSE;}
  NB8 isCmd_0 = X60Qx_619;
  if (isCmd_0){
    parseCommand_1_parq39nt2(ps_72, b_54, lo_33, hi_33, pl_49, pc_49);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_3));
    return result_37;}
  NI64 eqi_0 = findAssign_0_parq39nt2((&(*ps_72)), ((NI64)lo_33), ((NI64)hi_33));
  if (IL64(0) <= eqi_0){
    Token_0_tok9e79hf op_4 = tok_0_parq39nt2((&(*ps_72)), eqi_0);
    addTree_0_nifjp9lau1(b_54, (string_0_sysvq0asl){
      .bytes_0 = 474182017284ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_72)), b_54, op_4.line_0, op_4.col_0, pl_49, pc_49, NIM_FALSE);
    parseExprRange_1_parq39nt2(ps_72, b_54, lo_33, ((NI32)eqi_0), op_4.line_0, op_4.col_0);
    Token_0_tok9e79hf rt_1 = tok_0_parq39nt2((&(*ps_72)), ((NI64)(eqi_0 + IL64(1))));
    NB8 X60Qx_622;
    if (rt_1.kind_0 == IL64(2)){
      NB8 X60Qx_623;
      NB8 X60Qx_624;
      NB8 X60Qx_625;
      NB8 X60Qx_626;
      NB8 X60Qx_627 = eqQ_20_sysvq0asl(rt_1.s_0, (string_0_sysvq0asl){
        .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
      );
      if (X60Qx_627){
        X60Qx_626 = NIM_TRUE;}
      else {
        NB8 X60Qx_628 = eqQ_20_sysvq0asl(rt_1.s_0, (string_0_sysvq0asl){
          .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
        );
        X60Qx_626 = X60Qx_628;}
      if (X60Qx_626){
        X60Qx_625 = NIM_TRUE;}
      else {
        NB8 X60Qx_629 = eqQ_20_sysvq0asl(rt_1.s_0, (string_0_sysvq0asl){
          .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
        );
        X60Qx_625 = X60Qx_629;}
      if (X60Qx_625){
        X60Qx_624 = NIM_TRUE;}
      else {
        NB8 X60Qx_630 = eqQ_20_sysvq0asl(rt_1.s_0, (string_0_sysvq0asl){
          .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
        );
        X60Qx_624 = X60Qx_630;}
      if (X60Qx_624){
        X60Qx_623 = NIM_TRUE;}
      else {
        NB8 X60Qx_631 = eqQ_20_sysvq0asl(rt_1.s_0, (string_0_sysvq0asl){
          .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
        );
        X60Qx_623 = X60Qx_631;}
      X60Qx_622 = X60Qx_623;}
    else {
      X60Qx_622 = NIM_FALSE;}
    if (X60Qx_622){
      NI64 X60Qx_632 = parseCtrlFlowValue_0_parq39nt2(ps_72, b_54, ((NI64)(eqi_0 + IL64(1))), op_4.line_0, op_4.col_0);
      result_37 = X60Qx_632;}
    else {
      parseExprRange_1_parq39nt2(ps_72, b_54, ((NI32)(((NI32)eqi_0) + ((NI32)IL64(1)))), hi_33, op_4.line_0, op_4.col_0);}
    endTree_0_nifjp9lau1(b_54);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&rt_1));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&op_4));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_3));
    return result_37;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&rt_1));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&op_4));}
  parseExprRange_1_parq39nt2(ps_72, b_54, lo_33, hi_33, pl_49, pc_49);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_3));
  return result_37;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_3));
  return result_37;}
NI64 parseReturnLike_0_parq39nt2(Parser_0_parq39nt2* ps_73, Builder_0_nifjp9lau1* b_55, NI64 kwIdx_5, NI32 pl_50, NI32 pc_50, string_0_sysvq0asl tag_3){
  NI64 result_38;
  Token_0_tok9e79hf kw_12 = tok_0_parq39nt2((&(*ps_73)), kwIdx_5);
  NI64 X60Qx_633 = lineEnd_0_parq39nt2((&(*ps_73)), kwIdx_5);
  NI64 hi_44 = semiEnd_0_parq39nt2((&(*ps_73)), kwIdx_5, X60Qx_633);
  addTree_0_nifjp9lau1(b_55, tag_3);
  emitInfo_0_parq39nt2((&(*ps_73)), b_55, kw_12.line_0, kw_12.col_0, pl_50, pc_50, NIM_FALSE);
  NB8 X60Qx_157;
  if (((NI64)(kwIdx_5 + IL64(1))) < hi_44){
    Token_0_tok9e79hf X60Qtmp_145 = tok_0_parq39nt2((&(*ps_73)), ((NI64)(kwIdx_5 + IL64(1))));
    NB8 X60Qx_634 = startsExpr_0_parq39nt2((&X60Qtmp_145));
    X60Qx_157 = X60Qx_634;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_145));}
  else {
    X60Qx_157 = NIM_FALSE;}
  if (X60Qx_157){
    parseExprRange_1_parq39nt2(ps_73, b_55, ((NI32)(((NI32)kwIdx_5) + ((NI32)IL64(1)))), ((NI32)hi_44), kw_12.line_0, kw_12.col_0);}
  else {
    addEmpty_0_nifjp9lau1(b_55, IL64(1));}
  endTree_0_nifjp9lau1(b_55);
  result_38 = hi_44;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_12));
  return result_38;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_12));
  return result_38;}
NI64 parseImportLike_0_parq39nt2(Parser_0_parq39nt2* ps_74, Builder_0_nifjp9lau1* b_56, NI64 kwIdx_6, NI32 pl_51, NI32 pc_51, string_0_sysvq0asl tag_4){
  NI64 result_39;
  Token_0_tok9e79hf kw_13 = tok_0_parq39nt2((&(*ps_74)), kwIdx_6);
  NI64 X60Qx_635 = lineEnd_0_parq39nt2((&(*ps_74)), kwIdx_6);
  NI64 hi_45 = semiEnd_0_parq39nt2((&(*ps_74)), kwIdx_6, X60Qx_635);
  NB8 X60Qx_636;
  NB8 X60Qx_637 = eqQ_20_sysvq0asl(tag_4, (string_0_sysvq0asl){
    .bytes_0 = 32776920251590918ull, .more_0 = NIM_NIL}
  );
  if (X60Qx_637){
    X60Qx_636 = NIM_TRUE;}
  else {
    NB8 X60Qx_638 = eqQ_20_sysvq0asl(tag_4, (string_0_sysvq0asl){
      .bytes_0 = 32776920252310790ull, .more_0 = NIM_NIL}
    );
    X60Qx_636 = X60Qx_638;}
  if (X60Qx_636){
    NI64 d_5 = IL64(0);
    NI64 exceptIdx_0 = IL64(-1);
    NI64 j_7 = ((NI64)(kwIdx_6 + IL64(1)));
    {
      while (j_7 < hi_45){
        Token_0_tok9e79hf t_21 = tok_0_parq39nt2((&(*ps_74)), j_7);
        NB8 X60Qx_639 = isOpenBracket_0_parq39nt2(t_21.kind_0);
        if (X60Qx_639){
          inc_1_Irn1g7r1_aif7a4qfr((&d_5));}
        else {
          NB8 X60Qx_640 = isCloseBracket_0_parq39nt2(t_21.kind_0);
          if (X60Qx_640){
            if (IL64(0) < d_5){
              dec_1_I2mwrey1_envto7w6l1((&d_5));}}
          else {
            NB8 X60Qx_641;
            NB8 X60Qx_642;
            if (d_5 == IL64(0)){
              X60Qx_642 = (t_21.kind_0 == IL64(2));}
            else {
              X60Qx_642 = NIM_FALSE;}
            if (X60Qx_642){
              NB8 X60Qx_643 = eqQ_20_sysvq0asl(t_21.s_0, (string_0_sysvq0asl){
                .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
              );
              X60Qx_641 = X60Qx_643;}
            else {
              X60Qx_641 = NIM_FALSE;}
            if (X60Qx_641){
              exceptIdx_0 = j_7;
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_21));
              goto whileStmtLabel_0;}}}
        inc_1_Irn1g7r1_aif7a4qfr((&j_7));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_21));}}
    whileStmtLabel_0: ;
    if (IL64(0) <= exceptIdx_0){
      string_0_sysvq0asl X60Qx_33;
      nimStrWasMoved((&X60Qx_33));
      NB8 X60Qx_644 = eqQ_20_sysvq0asl(tag_4, (string_0_sysvq0asl){
        .bytes_0 = 32776920251590918ull, .more_0 = NIM_NIL}
      );
      if (X60Qx_644){
        nimStrDestroy(X60Qx_33);
        X60Qx_33 = (string_0_sysvq0asl){
          .bytes_0 = 7310593918082312702ull, .more_0 = (&strlit_0_I16948548629793503007_parq39nt2)}
        ;}
      else {
        nimStrDestroy(X60Qx_33);
        X60Qx_33 = (string_0_sysvq0asl){
          .bytes_0 = 7310593918083032574ull, .more_0 = (&strlit_0_I7395289177220351871_parq39nt2)}
        ;}
      addTree_0_nifjp9lau1(b_56, X60Qx_33);
      emitInfo_0_parq39nt2((&(*ps_74)), b_56, kw_13.line_0, kw_13.col_0, pl_51, pc_51, NIM_FALSE);
      if (((NI64)(kwIdx_6 + IL64(1))) < exceptIdx_0){
        parseExprRange_1_parq39nt2(ps_74, b_56, ((NI32)((NI64)(kwIdx_6 + IL64(1)))), ((NI32)exceptIdx_0), kw_13.line_0, kw_13.col_0);}
      seq_0_Iotb7mc_mat7cnfv21 estarts_0 = splitArgs_0_parq39nt2((&(*ps_74)), ((NI64)(exceptIdx_0 + IL64(1))), hi_45);
      {
        NI64 X60Qlf_42 = IL64(0);
        NI64 X60Qlf_43 = len_3_I12oavy1_parq39nt2(estarts_0);
        NI64 X60Qlf_44 = X60Qlf_42;
        {
          while (X60Qlf_44 < X60Qlf_43){
            {
              NI64* X60Qx_645 = getQ_7_Ite3z0o_parq39nt2(estarts_0, X60Qlf_44);
              NI64 X60Qii_3 = (*X60Qx_645);
              NI64 X60Qx_34;
              NI64 X60Qx_646 = len_3_I12oavy1_parq39nt2(estarts_0);
              if (((NI64)(X60Qlf_44 + IL64(1))) < X60Qx_646){
                NI64* X60Qx_647 = getQ_7_Ite3z0o_parq39nt2(estarts_0, ((NI64)(X60Qlf_44 + IL64(1))));
                X60Qx_34 = ((NI64)((*X60Qx_647) - IL64(1)));}
              else {
                X60Qx_34 = hi_45;}
              NI64 X60Qii_4 = X60Qx_34;
              if (X60Qii_3 < X60Qii_4){
                parseExprRange_1_parq39nt2(ps_74, b_56, ((NI32)X60Qii_3), ((NI32)X60Qii_4), kw_13.line_0, kw_13.col_0);}}
            inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_44));}}
        whileStmtLabel_2: ;}
      forStmtLabel_1: ;
      endTree_0_nifjp9lau1(b_56);
      eQdestroy_1_Iez2nr5_mat7cnfv21(estarts_0);
      nimStrDestroy(X60Qx_33);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_13));
      return hi_45;
      eQdestroy_1_Iez2nr5_mat7cnfv21(estarts_0);
      nimStrDestroy(X60Qx_33);}}
  addTree_0_nifjp9lau1(b_56, tag_4);
  emitInfo_0_parq39nt2((&(*ps_74)), b_56, kw_13.line_0, kw_13.col_0, pl_51, pc_51, NIM_FALSE);
  seq_0_Iotb7mc_mat7cnfv21 starts_7 = splitArgs_0_parq39nt2((&(*ps_74)), ((NI64)(kwIdx_6 + IL64(1))), hi_45);
  {
    NI64 X60Qlf_45 = IL64(0);
    NI64 X60Qlf_46 = len_3_I12oavy1_parq39nt2(starts_7);
    NI64 X60Qlf_47 = X60Qlf_45;
    {
      while (X60Qlf_47 < X60Qlf_46){
        {
          NI64* X60Qx_648 = getQ_7_Ite3z0o_parq39nt2(starts_7, X60Qlf_47);
          NI64 X60Qii_7 = (*X60Qx_648);
          NI64 X60Qx_35;
          NI64 X60Qx_649 = len_3_I12oavy1_parq39nt2(starts_7);
          if (((NI64)(X60Qlf_47 + IL64(1))) < X60Qx_649){
            NI64* X60Qx_650 = getQ_7_Ite3z0o_parq39nt2(starts_7, ((NI64)(X60Qlf_47 + IL64(1))));
            X60Qx_35 = ((NI64)((*X60Qx_650) - IL64(1)));}
          else {
            X60Qx_35 = hi_45;}
          NI64 X60Qii_8 = X60Qx_35;
          if (X60Qii_7 < X60Qii_8){
            parseExprRange_1_parq39nt2(ps_74, b_56, ((NI32)X60Qii_7), ((NI32)X60Qii_8), kw_13.line_0, kw_13.col_0);}}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_47));}}
    whileStmtLabel_6: ;}
  forStmtLabel_5: ;
  endTree_0_nifjp9lau1(b_56);
  result_39 = hi_45;
  eQdestroy_1_Iez2nr5_mat7cnfv21(starts_7);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_13));
  return result_39;
  eQdestroy_1_Iez2nr5_mat7cnfv21(starts_7);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_13));
  return result_39;}
NB8 isOperandEnd_0_parq39nt2(TokKind_0_tok9e79hf k_2){
  NB8 result_40;
  NB8 X60Qx_651;
  NB8 X60Qx_652;
  NB8 X60Qx_653;
  NB8 X60Qx_654;
  NB8 X60Qx_655;
  NB8 X60Qx_656;
  NB8 X60Qx_657;
  NB8 X60Qx_658;
  NB8 X60Qx_659;
  if (k_2 == IL64(1)){
    X60Qx_659 = NIM_TRUE;}
  else {
    X60Qx_659 = (k_2 == IL64(11));}
  if (X60Qx_659){
    X60Qx_658 = NIM_TRUE;}
  else {
    X60Qx_658 = (k_2 == IL64(13));}
  if (X60Qx_658){
    X60Qx_657 = NIM_TRUE;}
  else {
    X60Qx_657 = (k_2 == IL64(15));}
  if (X60Qx_657){
    X60Qx_656 = NIM_TRUE;}
  else {
    X60Qx_656 = (k_2 == IL64(5));}
  if (X60Qx_656){
    X60Qx_655 = NIM_TRUE;}
  else {
    X60Qx_655 = (k_2 == IL64(6));}
  if (X60Qx_655){
    X60Qx_654 = NIM_TRUE;}
  else {
    X60Qx_654 = (k_2 == IL64(7));}
  if (X60Qx_654){
    X60Qx_653 = NIM_TRUE;}
  else {
    X60Qx_653 = (k_2 == IL64(3));}
  if (X60Qx_653){
    X60Qx_652 = NIM_TRUE;}
  else {
    X60Qx_652 = (k_2 == IL64(4));}
  if (X60Qx_652){
    X60Qx_651 = NIM_TRUE;}
  else {
    X60Qx_651 = (k_2 == IL64(8));}
  result_40 = X60Qx_651;
  return result_40;}
NI64 skipTrailingDoc_1_parq39nt2(Parser_0_parq39nt2* ps_75, NI64 i_5, NI64 refIndent_1){
  NI64 result_41;
  result_41 = i_5;
  {
    while (NIM_TRUE){
      NB8 X60Qx_158;
      Token_0_tok9e79hf X60Qtmp_146 = tok_0_parq39nt2((&(*ps_75)), result_41);
      if (X60Qtmp_146.kind_0 == IL64(20)){
        Token_0_tok9e79hf X60Qtmp_147 = tok_0_parq39nt2((&(*ps_75)), result_41);
        X60Qx_158 = (refIndent_1 < ((NI64)X60Qtmp_147.indent_0));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_147));}
      else {
        X60Qx_158 = NIM_FALSE;}
      if (X60Qx_158){
        inc_1_Irn1g7r1_aif7a4qfr((&result_41));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_146));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_146));}}
  whileStmtLabel_0: ;
  return result_41;}
NI64 findColon_0_parq39nt2(Parser_0_parq39nt2* ps_76, NI64 lo_34, NI64 hi_34){
  NI64 result_42;
  NI64 depth_14 = IL64(0);
  NI64 i_38 = lo_34;
  NI64 brace_1 = IL64(-1);
  {
    while (i_38 < hi_34){
      Token_0_tok9e79hf t_22 = tok_0_parq39nt2((&(*ps_76)), i_38);
      NB8 X60Qx_660;
      if (depth_14 == IL64(0)){
        X60Qx_660 = (t_22.kind_0 == IL64(18));}
      else {
        X60Qx_660 = NIM_FALSE;}
      if (X60Qx_660){
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_22));
        return i_38;}
      NB8 X60Qx_159;
      NB8 X60Qx_160;
      NB8 X60Qx_661;
      NB8 X60Qx_662;
      NB8 X60Qx_663;
      if (depth_14 == IL64(0)){
        X60Qx_663 = (*ps_76).curly_0;}
      else {
        X60Qx_663 = NIM_FALSE;}
      if (X60Qx_663){
        X60Qx_662 = (brace_1 < IL64(0));}
      else {
        X60Qx_662 = NIM_FALSE;}
      if (X60Qx_662){
        X60Qx_661 = (t_22.kind_0 == IL64(14));}
      else {
        X60Qx_661 = NIM_FALSE;}
      if (X60Qx_661){
        Token_0_tok9e79hf X60Qtmp_148 = tok_0_parq39nt2((&(*ps_76)), ((NI64)(i_38 + IL64(1))));
        X60Qx_160 = (!(X60Qtmp_148.kind_0 == IL64(19)));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_148));}
      else {
        X60Qx_160 = NIM_FALSE;}
      if (X60Qx_160){
        X60Qx_159 = (lo_34 < i_38);}
      else {
        X60Qx_159 = NIM_FALSE;}
      if (X60Qx_159){
        Token_0_tok9e79hf prev_5 = tok_0_parq39nt2((&(*ps_76)), ((NI64)(i_38 - IL64(1))));
        NB8 X60Qx_664;
        NB8 X60Qx_665 = isOperandEnd_0_parq39nt2(prev_5.kind_0);
        if (X60Qx_665){
          X60Qx_664 = NIM_TRUE;}
        else {
          NB8 X60Qx_666;
          if (prev_5.kind_0 == IL64(2)){
            NB8 X60Qx_667;
            NB8 X60Qx_668;
            NB8 X60Qx_669;
            NB8 X60Qx_670;
            NB8 X60Qx_671 = eqQ_20_sysvq0asl(prev_5.s_0, (string_0_sysvq0asl){
              .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
            );
            if (X60Qx_671){
              X60Qx_670 = NIM_TRUE;}
            else {
              NB8 X60Qx_672 = eqQ_20_sysvq0asl(prev_5.s_0, (string_0_sysvq0asl){
                .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
              );
              X60Qx_670 = X60Qx_672;}
            if (X60Qx_670){
              X60Qx_669 = NIM_TRUE;}
            else {
              NB8 X60Qx_673 = eqQ_20_sysvq0asl(prev_5.s_0, (string_0_sysvq0asl){
                .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
              );
              X60Qx_669 = X60Qx_673;}
            if (X60Qx_669){
              X60Qx_668 = NIM_TRUE;}
            else {
              NB8 X60Qx_674 = eqQ_20_sysvq0asl(prev_5.s_0, (string_0_sysvq0asl){
                .bytes_0 = 8749487341794059783ull, .more_0 = NIM_NIL}
              );
              X60Qx_668 = X60Qx_674;}
            if (X60Qx_668){
              X60Qx_667 = NIM_TRUE;}
            else {
              NB8 X60Qx_675 = eqQ_20_sysvq0asl(prev_5.s_0, (string_0_sysvq0asl){
                .bytes_0 = 125779835184133ull, .more_0 = NIM_NIL}
              );
              X60Qx_667 = X60Qx_675;}
            X60Qx_666 = X60Qx_667;}
          else {
            X60Qx_666 = NIM_FALSE;}
          X60Qx_664 = X60Qx_666;}
        if (X60Qx_664){
          brace_1 = i_38;}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&prev_5));}
      NB8 X60Qx_676 = isOpenBracket_0_parq39nt2(t_22.kind_0);
      if (X60Qx_676){
        inc_1_Irn1g7r1_aif7a4qfr((&depth_14));}
      else {
        NB8 X60Qx_677 = isCloseBracket_0_parq39nt2(t_22.kind_0);
        if (X60Qx_677){
          if (IL64(0) < depth_14){
            dec_1_I2mwrey1_envto7w6l1((&depth_14));}}}
      inc_1_Irn1g7r1_aif7a4qfr((&i_38));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_22));}}
  whileStmtLabel_0: ;
  result_42 = brace_1;
  return result_42;}
NI64 emitBody_0_parq39nt2(Parser_0_parq39nt2* ps_77, Builder_0_nifjp9lau1* b_57, NI64 colonIdx_2, NI32 refIndent_2, NI32 pl_52, NI32 pc_52){
  NI64 result_43;
  if (colonIdx_2 < IL64(0)){
    addTree_0_nifjp9lau1(b_57, (string_0_sysvq0asl){
      .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
    );
    addEmpty_0_nifjp9lau1(b_57, IL64(1));
    endTree_0_nifjp9lau1(b_57);
    return colonIdx_2;}
  Token_0_tok9e79hf X60Qtmp_149 = tok_0_parq39nt2((&(*ps_77)), colonIdx_2);
  if (X60Qtmp_149.kind_0 == IL64(14)){
    NI64 rb_8 = matchClose_0_parq39nt2((&(*ps_77)), colonIdx_2);
    Token_0_tok9e79hf first_5 = tok_0_parq39nt2((&(*ps_77)), ((NI64)(colonIdx_2 + IL64(1))));
    addTree_0_nifjp9lau1(b_57, (string_0_sysvq0asl){
      .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_77)), b_57, first_5.line_0, first_5.col_0, pl_52, pc_52, NIM_FALSE);
    NI64 j_8 = ((NI64)(colonIdx_2 + IL64(1)));
    {
      while (NIM_TRUE){
        NB8 X60Qx_161;
        if (j_8 < rb_8){
          Token_0_tok9e79hf X60Qtmp_150 = tok_0_parq39nt2((&(*ps_77)), j_8);
          X60Qx_161 = (!(X60Qtmp_150.kind_0 == IL64(0)));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_150));}
        else {
          X60Qx_161 = NIM_FALSE;}
        if (X60Qx_161){
          {
            Token_0_tok9e79hf X60Qtmp_151 = tok_0_parq39nt2((&(*ps_77)), j_8);
            if (X60Qtmp_151.kind_0 == IL64(20)){
              inc_1_Irn1g7r1_aif7a4qfr((&j_8));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_151));
              goto continueLabel_1;}
            NI64 X60Qx_678 = parseStmt_1_parq39nt2(ps_77, b_57, j_8, first_5.line_0, first_5.col_0, rb_8);
            j_8 = X60Qx_678;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_151));}
          continueLabel_1: ;}
        else {
          break;}}}
    whileStmtLabel_0: ;
    endTree_0_nifjp9lau1(b_57);
    result_43 = ((NI64)(rb_8 + IL64(1)));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_5));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_149));
    return result_43;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_5));}
  NI64 bodyStart_1 = ((NI64)(colonIdx_2 + IL64(1)));
  Token_0_tok9e79hf first_6 = tok_0_parq39nt2((&(*ps_77)), bodyStart_1);
  addTree_0_nifjp9lau1(b_57, (string_0_sysvq0asl){
    .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_77)), b_57, first_6.line_0, first_6.col_0, pl_52, pc_52, NIM_FALSE);
  NI64 i_39 = bodyStart_1;
  if (first_6.kind_0 == IL64(0)){
    }
  else {
    if (first_6.indent_0 < ((NI32)IL64(0))){
      NI64 hi_46 = lineEnd_0_parq39nt2((&(*ps_77)), bodyStart_1);
      {
        NI64 d_6 = IL64(0);
        NI64 k_16 = bodyStart_1;
        {
          while (k_16 < hi_46){
            Token_0_tok9e79hf kk_3 = tok_0_parq39nt2((&(*ps_77)), k_16);
            NB8 X60Qx_679 = isOpenBracket_0_parq39nt2(kk_3.kind_0);
            if (X60Qx_679){
              inc_1_Irn1g7r1_aif7a4qfr((&d_6));}
            else {
              NB8 X60Qx_680 = isCloseBracket_0_parq39nt2(kk_3.kind_0);
              if (X60Qx_680){
                if (IL64(0) < d_6){
                  dec_1_I2mwrey1_envto7w6l1((&d_6));}}
              else {
                NB8 X60Qx_681;
                NB8 X60Qx_682;
                if (d_6 == IL64(0)){
                  X60Qx_682 = (kk_3.kind_0 == IL64(2));}
                else {
                  X60Qx_682 = NIM_FALSE;}
                if (X60Qx_682){
                  NB8 X60Qx_683;
                  NB8 X60Qx_684;
                  NB8 X60Qx_685;
                  NB8 X60Qx_686;
                  NB8 X60Qx_687 = eqQ_20_sysvq0asl(kk_3.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
                  );
                  if (X60Qx_687){
                    X60Qx_686 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_688 = eqQ_20_sysvq0asl(kk_3.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_686 = X60Qx_688;}
                  if (X60Qx_686){
                    X60Qx_685 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_689 = eqQ_20_sysvq0asl(kk_3.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_685 = X60Qx_689;}
                  if (X60Qx_685){
                    X60Qx_684 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_690 = eqQ_20_sysvq0asl(kk_3.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_684 = X60Qx_690;}
                  if (X60Qx_684){
                    X60Qx_683 = NIM_TRUE;}
                  else {
                    NB8 X60Qx_691 = eqQ_20_sysvq0asl(kk_3.s_0, (string_0_sysvq0asl){
                      .bytes_0 = 8749487341794059783ull, .more_0 = NIM_NIL}
                    );
                    X60Qx_683 = X60Qx_691;}
                  X60Qx_681 = X60Qx_683;}
                else {
                  X60Qx_681 = NIM_FALSE;}
                if (X60Qx_681){
                  hi_46 = k_16;
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kk_3));
                  goto whileStmtLabel_3;}}}
            inc_1_Irn1g7r1_aif7a4qfr((&k_16));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kk_3));}}
        whileStmtLabel_3: ;}
      X60Qlab_2: ;
      {
        while (NIM_TRUE){
          NB8 X60Qx_162;
          if (i_39 < hi_46){
            Token_0_tok9e79hf X60Qtmp_152 = tok_0_parq39nt2((&(*ps_77)), i_39);
            X60Qx_162 = (!(X60Qtmp_152.kind_0 == IL64(0)));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_152));}
          else {
            X60Qx_162 = NIM_FALSE;}
          if (X60Qx_162){
            NI64 X60Qx_692 = parseStmt_1_parq39nt2(ps_77, b_57, i_39, first_6.line_0, first_6.col_0, hi_46);
            i_39 = X60Qx_692;}
          else {
            break;}}}
      whileStmtLabel_4: ;}
    else {
      NI32 bodyRef_1 = ((NI32)(first_6.indent_0 - ((NI32)IL64(1))));
      {
        while (NIM_TRUE){
          NB8 X60Qx_163;
          Token_0_tok9e79hf X60Qtmp_153 = tok_0_parq39nt2((&(*ps_77)), i_39);
          if ((!(X60Qtmp_153.kind_0 == IL64(0)))){
            Token_0_tok9e79hf X60Qtmp_154 = tok_0_parq39nt2((&(*ps_77)), i_39);
            X60Qx_163 = (bodyRef_1 < X60Qtmp_154.indent_0);
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_154));}
          else {
            X60Qx_163 = NIM_FALSE;}
          if (X60Qx_163){
            NI64 stmtHi_0 = IL64(-1);
            {
              NI64 d_7 = IL64(0);
              NI64 k_17 = i_39;
              NB8 sawCf_0 = NIM_FALSE;
              NI64 lend_0 = lineEnd_0_parq39nt2((&(*ps_77)), i_39);
              {
                while (k_17 < lend_0){
                  Token_0_tok9e79hf kk_4 = tok_0_parq39nt2((&(*ps_77)), k_17);
                  NB8 X60Qx_693 = isOpenBracket_0_parq39nt2(kk_4.kind_0);
                  if (X60Qx_693){
                    inc_1_Irn1g7r1_aif7a4qfr((&d_7));}
                  else {
                    NB8 X60Qx_694 = isCloseBracket_0_parq39nt2(kk_4.kind_0);
                    if (X60Qx_694){
                      if (IL64(0) < d_7){
                        dec_1_I2mwrey1_envto7w6l1((&d_7));}}
                    else {
                      NB8 X60Qx_695;
                      NB8 X60Qx_696;
                      if (d_7 == IL64(0)){
                        X60Qx_696 = (kk_4.kind_0 == IL64(2));}
                      else {
                        X60Qx_696 = NIM_FALSE;}
                      if (X60Qx_696){
                        NB8 X60Qx_697;
                        NB8 X60Qx_698;
                        NB8 X60Qx_699;
                        NB8 X60Qx_700 = eqQ_20_sysvq0asl(kk_4.s_0, (string_0_sysvq0asl){
                          .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
                        );
                        if (X60Qx_700){
                          X60Qx_699 = NIM_TRUE;}
                        else {
                          NB8 X60Qx_701 = eqQ_20_sysvq0asl(kk_4.s_0, (string_0_sysvq0asl){
                            .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
                          );
                          X60Qx_699 = X60Qx_701;}
                        if (X60Qx_699){
                          X60Qx_698 = NIM_TRUE;}
                        else {
                          NB8 X60Qx_702 = eqQ_20_sysvq0asl(kk_4.s_0, (string_0_sysvq0asl){
                            .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
                          );
                          X60Qx_698 = X60Qx_702;}
                        if (X60Qx_698){
                          X60Qx_697 = NIM_TRUE;}
                        else {
                          NB8 X60Qx_703 = eqQ_20_sysvq0asl(kk_4.s_0, (string_0_sysvq0asl){
                            .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
                          );
                          X60Qx_697 = X60Qx_703;}
                        X60Qx_695 = X60Qx_697;}
                      else {
                        X60Qx_695 = NIM_FALSE;}
                      if (X60Qx_695){
                        sawCf_0 = NIM_TRUE;}
                      else {
                        NB8 X60Qx_704;
                        NB8 X60Qx_705;
                        NB8 X60Qx_706;
                        NB8 X60Qx_707;
                        NB8 X60Qx_708;
                        if (d_7 == IL64(0)){
                          X60Qx_708 = (i_39 < k_17);}
                        else {
                          X60Qx_708 = NIM_FALSE;}
                        if (X60Qx_708){
                          X60Qx_707 = (!sawCf_0);}
                        else {
                          X60Qx_707 = NIM_FALSE;}
                        if (X60Qx_707){
                          X60Qx_706 = (kk_4.kind_0 == IL64(2));}
                        else {
                          X60Qx_706 = NIM_FALSE;}
                        if (X60Qx_706){
                          X60Qx_705 = (kk_4.indent_0 < ((NI32)IL64(0)));}
                        else {
                          X60Qx_705 = NIM_FALSE;}
                        if (X60Qx_705){
                          NB8 X60Qx_709;
                          NB8 X60Qx_710;
                          NB8 X60Qx_711;
                          NB8 X60Qx_712;
                          NB8 X60Qx_713 = eqQ_20_sysvq0asl(kk_4.s_0, (string_0_sysvq0asl){
                            .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
                          );
                          if (X60Qx_713){
                            X60Qx_712 = NIM_TRUE;}
                          else {
                            NB8 X60Qx_714 = eqQ_20_sysvq0asl(kk_4.s_0, (string_0_sysvq0asl){
                              .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
                            );
                            X60Qx_712 = X60Qx_714;}
                          if (X60Qx_712){
                            X60Qx_711 = NIM_TRUE;}
                          else {
                            NB8 X60Qx_715 = eqQ_20_sysvq0asl(kk_4.s_0, (string_0_sysvq0asl){
                              .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
                            );
                            X60Qx_711 = X60Qx_715;}
                          if (X60Qx_711){
                            X60Qx_710 = NIM_TRUE;}
                          else {
                            NB8 X60Qx_716 = eqQ_20_sysvq0asl(kk_4.s_0, (string_0_sysvq0asl){
                              .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
                            );
                            X60Qx_710 = X60Qx_716;}
                          if (X60Qx_710){
                            X60Qx_709 = NIM_TRUE;}
                          else {
                            NB8 X60Qx_717 = eqQ_20_sysvq0asl(kk_4.s_0, (string_0_sysvq0asl){
                              .bytes_0 = 8749487341794059783ull, .more_0 = NIM_NIL}
                            );
                            X60Qx_709 = X60Qx_717;}
                          X60Qx_704 = X60Qx_709;}
                        else {
                          X60Qx_704 = NIM_FALSE;}
                        if (X60Qx_704){
                          stmtHi_0 = k_17;
                          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kk_4));
                          goto whileStmtLabel_7;}}}}
                  inc_1_Irn1g7r1_aif7a4qfr((&k_17));
                  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kk_4));}}
              whileStmtLabel_7: ;}
            X60Qlab_6: ;
            NI64 X60Qx_718 = parseStmt_1_parq39nt2(ps_77, b_57, i_39, first_6.line_0, first_6.col_0, ((NI64)((NI32)stmtHi_0)));
            i_39 = X60Qx_718;
            NI64 X60Qx_719 = skipTrailingDoc_1_parq39nt2((&(*ps_77)), i_39, ((NI64)first_6.indent_0));
            i_39 = X60Qx_719;}
          else {
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_153));
            break;}
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_153));}}
      whileStmtLabel_5: ;}}
  endTree_0_nifjp9lau1(b_57);
  result_43 = i_39;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_6));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_149));
  return result_43;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_6));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_149));
  return result_43;}
NI64 parseIfLike_0_parq39nt2(Parser_0_parq39nt2* ps_78, Builder_0_nifjp9lau1* b_58, NI64 kwIdx_7, NI32 pl_53, NI32 pc_53, string_0_sysvq0asl tag_5){
  NI64 result_44;
  Token_0_tok9e79hf kw_14 = tok_0_parq39nt2((&(*ps_78)), kwIdx_7);
  NI32 refIndent_6 = kw_14.col_0;
  NI32 lineIndent_0 = lineIndentOf_0_parq39nt2((&(*ps_78)), kwIdx_7);
  NI64 X60Qx_720 = lineEnd_0_parq39nt2((&(*ps_78)), kwIdx_7);
  NI64 firstColon_0 = findColon_0_parq39nt2((&(*ps_78)), kwIdx_7, X60Qx_720);
  NI32 X60Qx_36;
  NB8 X60Qx_164;
  if (IL64(0) <= firstColon_0){
    Token_0_tok9e79hf X60Qtmp_155 = tok_0_parq39nt2((&(*ps_78)), ((NI64)(firstColon_0 + IL64(1))));
    X60Qx_164 = (((NI32)IL64(0)) <= X60Qtmp_155.indent_0);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_155));}
  else {
    X60Qx_164 = NIM_FALSE;}
  if (X60Qx_164){
    Token_0_tok9e79hf X60Qtmp_156 = tok_0_parq39nt2((&(*ps_78)), ((NI64)(firstColon_0 + IL64(1))));
    X60Qx_36 = X60Qtmp_156.indent_0;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_156));}
  else {
    X60Qx_36 = ((NI32)IL64(100000));}
  NI32 bodyIndent_0 = X60Qx_36;
  addTree_0_nifjp9lau1(b_58, tag_5);
  emitInfo_0_parq39nt2((&(*ps_78)), b_58, kw_14.line_0, kw_14.col_0, pl_53, pc_53, NIM_FALSE);
  NI64 i_40 = kwIdx_7;
  {
    while (NIM_TRUE){
      {
        Token_0_tok9e79hf branch_0 = tok_0_parq39nt2((&(*ps_78)), i_40);
        NB8 X60Qx_721;
        if (branch_0.kind_0 == IL64(2)){
          NB8 X60Qx_722;
          NB8 X60Qx_723 = eqQ_20_sysvq0asl(branch_0.s_0, tag_5);
          if (X60Qx_723){
            X60Qx_722 = NIM_TRUE;}
          else {
            NB8 X60Qx_724 = eqQ_20_sysvq0asl(branch_0.s_0, (string_0_sysvq0asl){
              .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
            );
            X60Qx_722 = X60Qx_724;}
          X60Qx_721 = X60Qx_722;}
        else {
          X60Qx_721 = NIM_FALSE;}
        NB8 isElif_0 = X60Qx_721;
        if (isElif_0){
          NI64 hi_47 = lineEnd_0_parq39nt2((&(*ps_78)), i_40);
          NI64 colon_3 = findColon_0_parq39nt2((&(*ps_78)), i_40, hi_47);
          Token_0_tok9e79hf condTok_0 = tok_0_parq39nt2((&(*ps_78)), ((NI64)(i_40 + IL64(1))));
          addTree_0_nifjp9lau1(b_58, (string_0_sysvq0asl){
            .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_78)), b_58, condTok_0.line_0, condTok_0.col_0, kw_14.line_0, kw_14.col_0, NIM_FALSE);
          parseExprRange_1_parq39nt2(ps_78, b_58, ((NI32)((NI64)(i_40 + IL64(1)))), ((NI32)colon_3), condTok_0.line_0, condTok_0.col_0);
          NI64 X60Qx_725 = emitBody_0_parq39nt2(ps_78, b_58, colon_3, refIndent_6, condTok_0.line_0, condTok_0.col_0);
          i_40 = X60Qx_725;
          endTree_0_nifjp9lau1(b_58);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&condTok_0));}
        else {
          NB8 X60Qx_726;
          if (branch_0.kind_0 == IL64(2)){
            NB8 X60Qx_727 = eqQ_20_sysvq0asl(branch_0.s_0, (string_0_sysvq0asl){
              .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
            );
            X60Qx_726 = X60Qx_727;}
          else {
            X60Qx_726 = NIM_FALSE;}
          if (X60Qx_726){
            NI64 hi_48 = lineEnd_0_parq39nt2((&(*ps_78)), i_40);
            NI64 colon_4 = findColon_0_parq39nt2((&(*ps_78)), i_40, hi_48);
            addTree_0_nifjp9lau1(b_58, (string_0_sysvq0asl){
              .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
            );
            emitInfo_0_parq39nt2((&(*ps_78)), b_58, branch_0.line_0, branch_0.col_0, kw_14.line_0, kw_14.col_0, NIM_FALSE);
            NI64 X60Qx_728 = emitBody_0_parq39nt2(ps_78, b_58, colon_4, refIndent_6, branch_0.line_0, branch_0.col_0);
            i_40 = X60Qx_728;
            endTree_0_nifjp9lau1(b_58);
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&branch_0));
            goto whileStmtLabel_0;}
          else {
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&branch_0));
            goto whileStmtLabel_0;}}
        Token_0_tok9e79hf nxt_6 = tok_0_parq39nt2((&(*ps_78)), i_40);
        NB8 X60Qx_729;
        NB8 X60Qx_730;
        if (nxt_6.kind_0 == IL64(2)){
          NB8 X60Qx_731;
          NB8 X60Qx_732 = eqQ_20_sysvq0asl(nxt_6.s_0, (string_0_sysvq0asl){
            .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
          );
          if (X60Qx_732){
            X60Qx_731 = NIM_TRUE;}
          else {
            NB8 X60Qx_733 = eqQ_20_sysvq0asl(nxt_6.s_0, (string_0_sysvq0asl){
              .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
            );
            X60Qx_731 = X60Qx_733;}
          X60Qx_730 = X60Qx_731;}
        else {
          X60Qx_730 = NIM_FALSE;}
        if (X60Qx_730){
          NB8 X60Qx_734;
          if (nxt_6.indent_0 < ((NI32)IL64(0))){
            X60Qx_734 = NIM_TRUE;}
          else {
            NB8 X60Qx_735;
            if (lineIndent_0 <= nxt_6.indent_0){
              X60Qx_735 = (nxt_6.indent_0 < bodyIndent_0);}
            else {
              X60Qx_735 = NIM_FALSE;}
            X60Qx_734 = X60Qx_735;}
          X60Qx_729 = X60Qx_734;}
        else {
          X60Qx_729 = NIM_FALSE;}
        if (X60Qx_729){
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_6));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&branch_0));
          goto continueLabel_1;}
        else {
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_6));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&branch_0));
          goto whileStmtLabel_0;}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&nxt_6));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&branch_0));}
      continueLabel_1: ;}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_58);
  result_44 = i_40;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_14));
  return result_44;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_14));
  return result_44;}
NI64 parseWhile_0_parq39nt2(Parser_0_parq39nt2* ps_79, Builder_0_nifjp9lau1* b_59, NI64 kwIdx_8, NI32 pl_54, NI32 pc_54){
  NI64 result_45;
  Token_0_tok9e79hf kw_15 = tok_0_parq39nt2((&(*ps_79)), kwIdx_8);
  NI32 refIndent_7 = kw_15.col_0;
  NI64 hi_49 = lineEnd_0_parq39nt2((&(*ps_79)), kwIdx_8);
  NI64 colon_5 = findColon_0_parq39nt2((&(*ps_79)), kwIdx_8, hi_49);
  addTree_0_nifjp9lau1(b_59, (string_0_sysvq0asl){
    .bytes_0 = 111516299327237ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_79)), b_59, kw_15.line_0, kw_15.col_0, pl_54, pc_54, NIM_FALSE);
  parseExprRange_1_parq39nt2(ps_79, b_59, ((NI32)((NI64)(kwIdx_8 + IL64(1)))), ((NI32)colon_5), kw_15.line_0, kw_15.col_0);
  NI64 X60Qx_736 = emitBody_0_parq39nt2(ps_79, b_59, colon_5, refIndent_7, kw_15.line_0, kw_15.col_0);
  result_45 = X60Qx_736;
  endTree_0_nifjp9lau1(b_59);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_15));
  return result_45;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_15));
  return result_45;}
NI64 parseCase_0_parq39nt2(Parser_0_parq39nt2* ps_80, Builder_0_nifjp9lau1* b_60, NI64 kwIdx_9, NI32 pl_55, NI32 pc_55){
  NI64 result_46;
  Token_0_tok9e79hf kw_16 = tok_0_parq39nt2((&(*ps_80)), kwIdx_9);
  NI32 refIndent_8 = kw_16.col_0;
  NI64 selHi_1 = lineEnd_0_parq39nt2((&(*ps_80)), kwIdx_9);
  addTree_0_nifjp9lau1(b_60, (string_0_sysvq0asl){
    .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_80)), b_60, kw_16.line_0, kw_16.col_0, pl_55, pc_55, NIM_FALSE);
  NI64 selColon_0 = findColon_0_parq39nt2((&(*ps_80)), kwIdx_9, selHi_1);
  NI64 X60Qx_37;
  if (IL64(0) <= selColon_0){
    X60Qx_37 = selColon_0;}
  else {
    X60Qx_37 = selHi_1;}
  NI64 selEnd_0 = X60Qx_37;
  parseExprRange_1_parq39nt2(ps_80, b_60, ((NI32)((NI64)(kwIdx_9 + IL64(1)))), ((NI32)selEnd_0), kw_16.line_0, kw_16.col_0);
  NI64 i_41 = selHi_1;
  Token_0_tok9e79hf X60Qtmp_157 = tok_0_parq39nt2((&(*ps_80)), selHi_1);
  NI32 ofIndent_0 = X60Qtmp_157.indent_0;
  {
    while (NIM_TRUE){
      NB8 X60Qx_165;
      NB8 X60Qx_166;
      Token_0_tok9e79hf X60Qtmp_158 = tok_0_parq39nt2((&(*ps_80)), i_41);
      if (X60Qtmp_158.kind_0 == IL64(2)){
        NB8 X60Qx_167;
        Token_0_tok9e79hf X60Qtmp_159 = tok_0_parq39nt2((&(*ps_80)), i_41);
        if (X60Qtmp_159.indent_0 == ofIndent_0){
          X60Qx_167 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_160 = tok_0_parq39nt2((&(*ps_80)), i_41);
          X60Qx_167 = (X60Qtmp_160.indent_0 < ((NI32)IL64(0)));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_160));}
        X60Qx_166 = X60Qx_167;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_159));}
      else {
        X60Qx_166 = NIM_FALSE;}
      if (X60Qx_166){
        NB8 X60Qx_168;
        NB8 X60Qx_169;
        Token_0_tok9e79hf X60Qtmp_161 = tok_0_parq39nt2((&(*ps_80)), i_41);
        NB8 X60Qx_737 = eqQ_20_sysvq0asl(X60Qtmp_161.s_0, (string_0_sysvq0asl){
          .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_737){
          X60Qx_169 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_162 = tok_0_parq39nt2((&(*ps_80)), i_41);
          NB8 X60Qx_738 = eqQ_20_sysvq0asl(X60Qtmp_162.s_0, (string_0_sysvq0asl){
            .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
          );
          X60Qx_169 = X60Qx_738;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_162));}
        if (X60Qx_169){
          X60Qx_168 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_163 = tok_0_parq39nt2((&(*ps_80)), i_41);
          NB8 X60Qx_739 = eqQ_20_sysvq0asl(X60Qtmp_163.s_0, (string_0_sysvq0asl){
            .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
          );
          X60Qx_168 = X60Qx_739;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_163));}
        X60Qx_165 = X60Qx_168;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_161));}
      else {
        X60Qx_165 = NIM_FALSE;}
      if (X60Qx_165){
        Token_0_tok9e79hf br_3 = tok_0_parq39nt2((&(*ps_80)), i_41);
        NI64 bhi_2 = lineEnd_0_parq39nt2((&(*ps_80)), i_41);
        NI64 bcolon_3 = findColon_0_parq39nt2((&(*ps_80)), i_41, bhi_2);
        NB8 X60Qx_740 = eqQ_20_sysvq0asl(br_3.s_0, (string_0_sysvq0asl){
          .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_740){
          addTree_0_nifjp9lau1(b_60, (string_0_sysvq0asl){
            .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_80)), b_60, br_3.line_0, br_3.col_0, kw_16.line_0, kw_16.col_0, NIM_FALSE);
          addTree_0_nifjp9lau1(b_60, (string_0_sysvq0asl){
            .bytes_0 = 32481117229642246ull, .more_0 = NIM_NIL}
          );
          seq_0_Iotb7mc_mat7cnfv21 starts_8 = splitArgs_0_parq39nt2((&(*ps_80)), ((NI64)(i_41 + IL64(1))), bcolon_3);
          {
            NI64 X60Qlf_48 = IL64(0);
            NI64 X60Qlf_49 = len_3_I12oavy1_parq39nt2(starts_8);
            NI64 X60Qlf_50 = X60Qlf_48;
            {
              while (X60Qlf_50 < X60Qlf_49){
                {
                  NI64* X60Qx_741 = getQ_7_Ite3z0o_parq39nt2(starts_8, X60Qlf_50);
                  NI64 X60Qii_3 = (*X60Qx_741);
                  NI64 X60Qx_38;
                  NI64 X60Qx_742 = len_3_I12oavy1_parq39nt2(starts_8);
                  if (((NI64)(X60Qlf_50 + IL64(1))) < X60Qx_742){
                    NI64* X60Qx_743 = getQ_7_Ite3z0o_parq39nt2(starts_8, ((NI64)(X60Qlf_50 + IL64(1))));
                    X60Qx_38 = ((NI64)((*X60Qx_743) - IL64(1)));}
                  else {
                    X60Qx_38 = bcolon_3;}
                  NI64 X60Qii_4 = X60Qx_38;
                  if (X60Qii_3 < X60Qii_4){
                    parseExprRange_1_parq39nt2(ps_80, b_60, ((NI32)X60Qii_3), ((NI32)X60Qii_4), br_3.line_0, br_3.col_0);}}
                inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_50));}}
            whileStmtLabel_2: ;}
          forStmtLabel_1: ;
          endTree_0_nifjp9lau1(b_60);
          NI64 X60Qx_744 = emitBody_0_parq39nt2(ps_80, b_60, bcolon_3, refIndent_8, br_3.line_0, br_3.col_0);
          i_41 = X60Qx_744;
          endTree_0_nifjp9lau1(b_60);
          eQdestroy_1_Iez2nr5_mat7cnfv21(starts_8);}
        else {
          addTree_0_nifjp9lau1(b_60, (string_0_sysvq0asl){
            .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_80)), b_60, br_3.line_0, br_3.col_0, kw_16.line_0, kw_16.col_0, NIM_FALSE);
          NI64 X60Qx_745 = emitBody_0_parq39nt2(ps_80, b_60, bcolon_3, refIndent_8, br_3.line_0, br_3.col_0);
          i_41 = X60Qx_745;
          endTree_0_nifjp9lau1(b_60);}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&br_3));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_158));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_158));}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_60);
  result_46 = i_41;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_157));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_16));
  return result_46;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_157));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_16));
  return result_46;}
NI64 parseFor_0_parq39nt2(Parser_0_parq39nt2* ps_81, Builder_0_nifjp9lau1* b_61, NI64 kwIdx_10, NI32 pl_56, NI32 pc_56){
  NI64 result_47;
  Token_0_tok9e79hf kw_17 = tok_0_parq39nt2((&(*ps_81)), kwIdx_10);
  NI32 refIndent_9 = kw_17.col_0;
  NI64 hi_50 = lineEnd_0_parq39nt2((&(*ps_81)), kwIdx_10);
  NI64 colon_6 = findColon_0_parq39nt2((&(*ps_81)), kwIdx_10, hi_50);
  NI64 inIdx_0 = IL64(-1);
  {
    NI64 depth_15 = IL64(0);
    NI64 j_9 = ((NI64)(kwIdx_10 + IL64(1)));
    {
      while (j_9 < colon_6){
        Token_0_tok9e79hf t_23 = tok_0_parq39nt2((&(*ps_81)), j_9);
        NB8 X60Qx_746 = isOpenBracket_0_parq39nt2(t_23.kind_0);
        if (X60Qx_746){
          inc_1_Irn1g7r1_aif7a4qfr((&depth_15));}
        else {
          NB8 X60Qx_747 = isCloseBracket_0_parq39nt2(t_23.kind_0);
          if (X60Qx_747){
            if (IL64(0) < depth_15){
              dec_1_I2mwrey1_envto7w6l1((&depth_15));}}
          else {
            NB8 X60Qx_748;
            NB8 X60Qx_749;
            if (depth_15 == IL64(0)){
              X60Qx_749 = (t_23.kind_0 == IL64(2));}
            else {
              X60Qx_749 = NIM_FALSE;}
            if (X60Qx_749){
              NB8 X60Qx_750 = eqQ_20_sysvq0asl(t_23.s_0, (string_0_sysvq0asl){
                .bytes_0 = 7235842ull, .more_0 = NIM_NIL}
              );
              X60Qx_748 = X60Qx_750;}
            else {
              X60Qx_748 = NIM_FALSE;}
            if (X60Qx_748){
              inIdx_0 = j_9;
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_23));
              goto findIn_0;}}}
        inc_1_Irn1g7r1_aif7a4qfr((&j_9));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_23));}}
    whileStmtLabel_0: ;}
  findIn_0: ;
  Token_0_tok9e79hf firstVar_0 = tok_0_parq39nt2((&(*ps_81)), ((NI64)(kwIdx_10 + IL64(1))));
  addTree_0_nifjp9lau1(b_61, (string_0_sysvq0asl){
    .bytes_0 = 1919903235ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_81)), b_61, firstVar_0.line_0, firstVar_0.col_0, pl_56, pc_56, NIM_FALSE);
  parseExprRange_1_parq39nt2(ps_81, b_61, ((NI32)((NI64)(inIdx_0 + IL64(1)))), ((NI32)colon_6), firstVar_0.line_0, firstVar_0.col_0);
  if (firstVar_0.kind_0 == IL64(10)){
    NI64 rp_4 = matchClose_0_parq39nt2((&(*ps_81)), ((NI64)(kwIdx_10 + IL64(1))));
    addTree_0_nifjp9lau1(b_61, (string_0_sysvq0asl){
      .bytes_0 = 8388908001056945662ull, .more_0 = (&strlit_0_I1237672436915077942_parq39nt2)}
    );
    seq_0_Iotb7mc_mat7cnfv21 starts_9 = splitArgs_0_parq39nt2((&(*ps_81)), ((NI64)(kwIdx_10 + IL64(2))), rp_4);
    {
      NI64 X60Qlf_51 = IL64(0);
      NI64 X60Qlf_52 = len_3_I12oavy1_parq39nt2(starts_9);
      NI64 X60Qlf_53 = X60Qlf_51;
      {
        while (X60Qlf_53 < X60Qlf_52){
          {
            NI64* X60Qx_751 = getQ_7_Ite3z0o_parq39nt2(starts_9, X60Qlf_53);
            Token_0_tok9e79hf X60Qii_3 = tok_0_parq39nt2((&(*ps_81)), (*X60Qx_751));
            addTree_0_nifjp9lau1(b_61, (string_0_sysvq0asl){
              .bytes_0 = 1952803843ull, .more_0 = NIM_NIL}
            );
            emitName_0_parq39nt2((&(*ps_81)), b_61, (&X60Qii_3), firstVar_0.line_0, firstVar_0.col_0);
            addEmpty_0_nifjp9lau1(b_61, IL64(4));
            endTree_0_nifjp9lau1(b_61);
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_3));}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_53));}}
      whileStmtLabel_2: ;}
    forStmtLabel_1: ;
    endTree_0_nifjp9lau1(b_61);
    eQdestroy_1_Iez2nr5_mat7cnfv21(starts_9);}
  else {
    addTree_0_nifjp9lau1(b_61, (string_0_sysvq0asl){
      .bytes_0 = 7380101684525954558ull, .more_0 = (&strlit_0_I13179338205702368459_parq39nt2)}
    );
    seq_0_Iotb7mc_mat7cnfv21 starts_10 = splitArgs_0_parq39nt2((&(*ps_81)), ((NI64)(kwIdx_10 + IL64(1))), inIdx_0);
    {
      NI64 X60Qlf_54 = IL64(0);
      NI64 X60Qlf_55 = len_3_I12oavy1_parq39nt2(starts_10);
      NI64 X60Qlf_56 = X60Qlf_54;
      {
        while (X60Qlf_56 < X60Qlf_55){
          {
            NI64* X60Qx_752 = getQ_7_Ite3z0o_parq39nt2(starts_10, X60Qlf_56);
            Token_0_tok9e79hf X60Qii_6 = tok_0_parq39nt2((&(*ps_81)), (*X60Qx_752));
            if (X60Qii_6.kind_0 == IL64(10)){
              NI64* X60Qx_753 = getQ_7_Ite3z0o_parq39nt2(starts_10, X60Qlf_56);
              NI64 X60Qii_7 = matchClose_0_parq39nt2((&(*ps_81)), (*X60Qx_753));
              addTree_0_nifjp9lau1(b_61, (string_0_sysvq0asl){
                .bytes_0 = 8388908001056945662ull, .more_0 = (&strlit_0_I1237672436915077942_parq39nt2)}
              );
              NI64* X60Qx_754 = getQ_7_Ite3z0o_parq39nt2(starts_10, X60Qlf_56);
              seq_0_Iotb7mc_mat7cnfv21 X60Qii_8 = splitArgs_0_parq39nt2((&(*ps_81)), ((NI64)((*X60Qx_754) + IL64(1))), X60Qii_7);
              {
                NI64 X60Qlf_57 = IL64(0);
                NI64 X60Qlf_58 = len_3_I12oavy1_parq39nt2(X60Qii_8);
                NI64 X60Qlf_59 = X60Qlf_57;
                {
                  while (X60Qlf_59 < X60Qlf_58){
                    {
                      NI64* X60Qx_755 = getQ_7_Ite3z0o_parq39nt2(X60Qii_8, X60Qlf_59);
                      Token_0_tok9e79hf X60Qii_11 = tok_0_parq39nt2((&(*ps_81)), (*X60Qx_755));
                      addTree_0_nifjp9lau1(b_61, (string_0_sysvq0asl){
                        .bytes_0 = 1952803843ull, .more_0 = NIM_NIL}
                      );
                      emitName_0_parq39nt2((&(*ps_81)), b_61, (&X60Qii_11), firstVar_0.line_0, firstVar_0.col_0);
                      addEmpty_0_nifjp9lau1(b_61, IL64(4));
                      endTree_0_nifjp9lau1(b_61);
                      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_11));}
                    inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_59));}}
                whileStmtLabel_10: ;}
              forStmtLabel_9: ;
              endTree_0_nifjp9lau1(b_61);
              eQdestroy_1_Iez2nr5_mat7cnfv21(X60Qii_8);}
            else {
              addTree_0_nifjp9lau1(b_61, (string_0_sysvq0asl){
                .bytes_0 = 1952803843ull, .more_0 = NIM_NIL}
              );
              emitName_0_parq39nt2((&(*ps_81)), b_61, (&X60Qii_6), firstVar_0.line_0, firstVar_0.col_0);
              addEmpty_0_nifjp9lau1(b_61, IL64(1));
              addEmpty_0_nifjp9lau1(b_61, IL64(1));
              addEmpty_0_nifjp9lau1(b_61, IL64(2));
              endTree_0_nifjp9lau1(b_61);}
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_6));}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_56));}}
      whileStmtLabel_5: ;}
    forStmtLabel_4: ;
    endTree_0_nifjp9lau1(b_61);
    eQdestroy_1_Iez2nr5_mat7cnfv21(starts_10);}
  NI64 X60Qx_756 = emitBody_0_parq39nt2(ps_81, b_61, colon_6, refIndent_9, firstVar_0.line_0, firstVar_0.col_0);
  result_47 = X60Qx_756;
  endTree_0_nifjp9lau1(b_61);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&firstVar_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_17));
  return result_47;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&firstVar_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_17));
  return result_47;}
void parseTryExpr_1_parq39nt2(Parser_0_parq39nt2* ps_82, Builder_0_nifjp9lau1* b_62, NI32 lo_35, NI32 hi_35, NI32 pl_57, NI32 pc_57){
  Token_0_tok9e79hf kw_18 = tok_0_parq39nt2((&(*ps_82)), ((NI64)lo_35));
  addTree_0_nifjp9lau1(b_62, (string_0_sysvq0asl){
    .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_82)), b_62, kw_18.line_0, kw_18.col_0, pl_57, pc_57, NIM_FALSE);
  seq_0_Iotb7mc_mat7cnfv21 branches_0 = newSeqUninit_0_I7whkjh1_mat7cnfv21(IL64(0));
  {
    NI64 d_8 = IL64(0);
    NI64 i_42 = ((NI64)(((NI64)lo_35) + IL64(1)));
    {
      while (i_42 < ((NI64)hi_35)){
        Token_0_tok9e79hf t_24 = tok_0_parq39nt2((&(*ps_82)), i_42);
        NB8 X60Qx_757 = isOpenBracket_0_parq39nt2(t_24.kind_0);
        if (X60Qx_757){
          inc_1_Irn1g7r1_aif7a4qfr((&d_8));}
        else {
          NB8 X60Qx_758 = isCloseBracket_0_parq39nt2(t_24.kind_0);
          if (X60Qx_758){
            if (IL64(0) < d_8){
              dec_1_I2mwrey1_envto7w6l1((&d_8));}}
          else {
            NB8 X60Qx_759;
            NB8 X60Qx_760;
            if (d_8 == IL64(0)){
              X60Qx_760 = (t_24.kind_0 == IL64(2));}
            else {
              X60Qx_760 = NIM_FALSE;}
            if (X60Qx_760){
              NB8 X60Qx_761;
              NB8 X60Qx_762 = eqQ_20_sysvq0asl(t_24.s_0, (string_0_sysvq0asl){
                .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
              );
              if (X60Qx_762){
                X60Qx_761 = NIM_TRUE;}
              else {
                NB8 X60Qx_763 = eqQ_20_sysvq0asl(t_24.s_0, (string_0_sysvq0asl){
                  .bytes_0 = 8749487341794059783ull, .more_0 = NIM_NIL}
                );
                X60Qx_761 = X60Qx_763;}
              X60Qx_759 = X60Qx_761;}
            else {
              X60Qx_759 = NIM_FALSE;}
            if (X60Qx_759){
              add_0_I8fahwb_parq39nt2((&branches_0), i_42);}}}
        inc_1_Irn1g7r1_aif7a4qfr((&i_42));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_24));}}
    whileStmtLabel_1: ;}
  X60Qlab_0: ;
  NI64 X60Qx_39;
  if (IL64(0) < branches_0.len_0){
    NI64* X60Qx_764 = getQ_7_Ite3z0o_parq39nt2(branches_0, IL64(0));
    X60Qx_39 = (*X60Qx_764);}
  else {
    X60Qx_39 = ((NI64)hi_35);}
  NI64 firstBranch_0 = X60Qx_39;
  NI64 colon_7 = findColon_0_parq39nt2((&(*ps_82)), ((NI64)lo_35), firstBranch_0);
  NB8 X60Qx_765;
  if (IL64(0) <= colon_7){
    X60Qx_765 = (((NI64)(colon_7 + IL64(1))) < firstBranch_0);}
  else {
    X60Qx_765 = NIM_FALSE;}
  if (X60Qx_765){
    parseExprRange_1_parq39nt2(ps_82, b_62, ((NI32)((NI64)(colon_7 + IL64(1)))), ((NI32)firstBranch_0), kw_18.line_0, kw_18.col_0);}
  else {
    addEmpty_0_nifjp9lau1(b_62, IL64(1));}
  {
    NI64 X60Qlf_60 = IL64(0);
    NI64 X60Qlf_61 = len_3_I12oavy1_parq39nt2(branches_0);
    NI64 X60Qlf_62 = X60Qlf_60;
    {
      while (X60Qlf_62 < X60Qlf_61){
        {
          NI64* X60Qx_766 = getQ_7_Ite3z0o_parq39nt2(branches_0, X60Qlf_62);
          NI64 X60Qii_4 = (*X60Qx_766);
          Token_0_tok9e79hf X60Qii_5 = tok_0_parq39nt2((&(*ps_82)), X60Qii_4);
          NI64 X60Qx_40;
          NI64 X60Qx_767 = len_3_I12oavy1_parq39nt2(branches_0);
          if (((NI64)(X60Qlf_62 + IL64(1))) < X60Qx_767){
            NI64* X60Qx_768 = getQ_7_Ite3z0o_parq39nt2(branches_0, ((NI64)(X60Qlf_62 + IL64(1))));
            X60Qx_40 = (*X60Qx_768);}
          else {
            X60Qx_40 = ((NI64)hi_35);}
          NI64 X60Qii_6 = X60Qx_40;
          NI64 X60Qii_7 = findColon_0_parq39nt2((&(*ps_82)), X60Qii_4, X60Qii_6);
          NB8 X60Qx_769 = eqQ_20_sysvq0asl(X60Qii_5.s_0, (string_0_sysvq0asl){
            .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
          );
          if (X60Qx_769){
            addTree_0_nifjp9lau1(b_62, (string_0_sysvq0asl){
              .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
            );
            emitInfo_0_parq39nt2((&(*ps_82)), b_62, X60Qii_5.line_0, X60Qii_5.col_0, kw_18.line_0, kw_18.col_0, NIM_FALSE);
            if (((NI64)(X60Qii_4 + IL64(1))) < X60Qii_7){
              parseExprRange_1_parq39nt2(ps_82, b_62, ((NI32)((NI64)(X60Qii_4 + IL64(1)))), ((NI32)X60Qii_7), X60Qii_5.line_0, X60Qii_5.col_0);}
            else {
              addEmpty_0_nifjp9lau1(b_62, IL64(1));}
            NB8 X60Qx_770;
            if (IL64(0) <= X60Qii_7){
              X60Qx_770 = (((NI64)(X60Qii_7 + IL64(1))) < X60Qii_6);}
            else {
              X60Qx_770 = NIM_FALSE;}
            if (X60Qx_770){
              parseExprRange_1_parq39nt2(ps_82, b_62, ((NI32)((NI64)(X60Qii_7 + IL64(1)))), ((NI32)X60Qii_6), X60Qii_5.line_0, X60Qii_5.col_0);}
            else {
              addEmpty_0_nifjp9lau1(b_62, IL64(1));}
            endTree_0_nifjp9lau1(b_62);}
          else {
            addTree_0_nifjp9lau1(b_62, (string_0_sysvq0asl){
              .bytes_0 = 1852401155ull, .more_0 = NIM_NIL}
            );
            emitInfo_0_parq39nt2((&(*ps_82)), b_62, X60Qii_5.line_0, X60Qii_5.col_0, kw_18.line_0, kw_18.col_0, NIM_FALSE);
            NB8 X60Qx_771;
            if (IL64(0) <= X60Qii_7){
              X60Qx_771 = (((NI64)(X60Qii_7 + IL64(1))) < X60Qii_6);}
            else {
              X60Qx_771 = NIM_FALSE;}
            if (X60Qx_771){
              parseExprRange_1_parq39nt2(ps_82, b_62, ((NI32)((NI64)(X60Qii_7 + IL64(1)))), ((NI32)X60Qii_6), X60Qii_5.line_0, X60Qii_5.col_0);}
            else {
              addEmpty_0_nifjp9lau1(b_62, IL64(1));}
            endTree_0_nifjp9lau1(b_62);}
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_5));}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_62));}}
    whileStmtLabel_3: ;}
  forStmtLabel_2: ;
  endTree_0_nifjp9lau1(b_62);
  eQdestroy_1_Iez2nr5_mat7cnfv21(branches_0);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_18));}
NI64 parseTry_1_parq39nt2(Parser_0_parq39nt2* ps_83, Builder_0_nifjp9lau1* b_63, NI64 kwIdx_11, NI32 pl_58, NI32 pc_58){
  NI64 result_48;
  Token_0_tok9e79hf kw_19 = tok_0_parq39nt2((&(*ps_83)), kwIdx_11);
  NI32 refIndent_10 = kw_19.col_0;
  NI32 lineIndent_1 = lineIndentOf_0_parq39nt2((&(*ps_83)), kwIdx_11);
  addTree_0_nifjp9lau1(b_63, (string_0_sysvq0asl){
    .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_83)), b_63, kw_19.line_0, kw_19.col_0, pl_58, pc_58, NIM_FALSE);
  NI64 hi_51 = lineEnd_0_parq39nt2((&(*ps_83)), kwIdx_11);
  NI64 colon_8 = findColon_0_parq39nt2((&(*ps_83)), kwIdx_11, hi_51);
  NI32 X60Qx_41;
  NB8 X60Qx_170;
  if (IL64(0) <= colon_8){
    Token_0_tok9e79hf X60Qtmp_164 = tok_0_parq39nt2((&(*ps_83)), ((NI64)(colon_8 + IL64(1))));
    X60Qx_170 = (((NI32)IL64(0)) <= X60Qtmp_164.indent_0);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_164));}
  else {
    X60Qx_170 = NIM_FALSE;}
  if (X60Qx_170){
    Token_0_tok9e79hf X60Qtmp_165 = tok_0_parq39nt2((&(*ps_83)), ((NI64)(colon_8 + IL64(1))));
    X60Qx_41 = X60Qtmp_165.indent_0;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_165));}
  else {
    X60Qx_41 = ((NI32)IL64(100000));}
  NI32 bodyIndent_1 = X60Qx_41;
  NI64 i_43 = emitBody_0_parq39nt2(ps_83, b_63, colon_8, refIndent_10, kw_19.line_0, kw_19.col_0);
  {
    while (NIM_TRUE){
      NB8 X60Qx_171;
      NB8 X60Qx_172;
      Token_0_tok9e79hf X60Qtmp_166 = tok_0_parq39nt2((&(*ps_83)), i_43);
      if (X60Qtmp_166.kind_0 == IL64(2)){
        NB8 X60Qx_173;
        Token_0_tok9e79hf X60Qtmp_167 = tok_0_parq39nt2((&(*ps_83)), i_43);
        if (X60Qtmp_167.indent_0 < ((NI32)IL64(0))){
          X60Qx_173 = NIM_TRUE;}
        else {
          NB8 X60Qx_174;
          Token_0_tok9e79hf X60Qtmp_168 = tok_0_parq39nt2((&(*ps_83)), i_43);
          if (lineIndent_1 <= X60Qtmp_168.indent_0){
            Token_0_tok9e79hf X60Qtmp_169 = tok_0_parq39nt2((&(*ps_83)), i_43);
            X60Qx_174 = (X60Qtmp_169.indent_0 < bodyIndent_1);
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_169));}
          else {
            X60Qx_174 = NIM_FALSE;}
          X60Qx_173 = X60Qx_174;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_168));}
        X60Qx_172 = X60Qx_173;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_167));}
      else {
        X60Qx_172 = NIM_FALSE;}
      if (X60Qx_172){
        NB8 X60Qx_175;
        Token_0_tok9e79hf X60Qtmp_170 = tok_0_parq39nt2((&(*ps_83)), i_43);
        NB8 X60Qx_772 = eqQ_20_sysvq0asl(X60Qtmp_170.s_0, (string_0_sysvq0asl){
          .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_772){
          X60Qx_175 = NIM_TRUE;}
        else {
          Token_0_tok9e79hf X60Qtmp_171 = tok_0_parq39nt2((&(*ps_83)), i_43);
          NB8 X60Qx_773 = eqQ_20_sysvq0asl(X60Qtmp_171.s_0, (string_0_sysvq0asl){
            .bytes_0 = 8749487341794059783ull, .more_0 = NIM_NIL}
          );
          X60Qx_175 = X60Qx_773;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_171));}
        X60Qx_171 = X60Qx_175;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_170));}
      else {
        X60Qx_171 = NIM_FALSE;}
      if (X60Qx_171){
        Token_0_tok9e79hf br_5 = tok_0_parq39nt2((&(*ps_83)), i_43);
        NI64 bhi_3 = lineEnd_0_parq39nt2((&(*ps_83)), i_43);
        NI64 bcolon_5 = findColon_0_parq39nt2((&(*ps_83)), i_43, bhi_3);
        NB8 X60Qx_774 = eqQ_20_sysvq0asl(br_5.s_0, (string_0_sysvq0asl){
          .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_774){
          addTree_0_nifjp9lau1(b_63, (string_0_sysvq0asl){
            .bytes_0 = 32774678061278470ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_83)), b_63, br_5.line_0, br_5.col_0, kw_19.line_0, kw_19.col_0, NIM_FALSE);
          if (((NI64)(i_43 + IL64(1))) < bcolon_5){
            seq_0_Iotb7mc_mat7cnfv21 ecStarts_0 = splitArgs_0_parq39nt2((&(*ps_83)), ((NI64)(i_43 + IL64(1))), bcolon_5);
            {
              NI64 X60Qlf_63 = IL64(0);
              NI64 X60Qlf_64 = len_3_I12oavy1_parq39nt2(ecStarts_0);
              NI64 X60Qlf_65 = X60Qlf_63;
              {
                while (X60Qlf_65 < X60Qlf_64){
                  {
                    NI64* X60Qx_775 = getQ_7_Ite3z0o_parq39nt2(ecStarts_0, X60Qlf_65);
                    NI64 X60Qii_3 = (*X60Qx_775);
                    NI64 X60Qx_42;
                    NI64 X60Qx_776 = len_3_I12oavy1_parq39nt2(ecStarts_0);
                    if (((NI64)(X60Qlf_65 + IL64(1))) < X60Qx_776){
                      NI64* X60Qx_777 = getQ_7_Ite3z0o_parq39nt2(ecStarts_0, ((NI64)(X60Qlf_65 + IL64(1))));
                      X60Qx_42 = ((NI64)((*X60Qx_777) - IL64(1)));}
                    else {
                      X60Qx_42 = bcolon_5;}
                    NI64 X60Qii_4 = X60Qx_42;
                    if (X60Qii_3 < X60Qii_4){
                      parseExprRange_1_parq39nt2(ps_83, b_63, ((NI32)X60Qii_3), ((NI32)X60Qii_4), br_5.line_0, br_5.col_0);}}
                  inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_65));}}
              whileStmtLabel_2: ;}
            forStmtLabel_1: ;
            eQdestroy_1_Iez2nr5_mat7cnfv21(ecStarts_0);}
          else {
            addEmpty_0_nifjp9lau1(b_63, IL64(1));}
          NI64 X60Qx_778 = emitBody_0_parq39nt2(ps_83, b_63, bcolon_5, refIndent_10, br_5.line_0, br_5.col_0);
          i_43 = X60Qx_778;
          endTree_0_nifjp9lau1(b_63);}
        else {
          addTree_0_nifjp9lau1(b_63, (string_0_sysvq0asl){
            .bytes_0 = 1852401155ull, .more_0 = NIM_NIL}
          );
          emitInfo_0_parq39nt2((&(*ps_83)), b_63, br_5.line_0, br_5.col_0, kw_19.line_0, kw_19.col_0, NIM_FALSE);
          NI64 X60Qx_779 = emitBody_0_parq39nt2(ps_83, b_63, bcolon_5, refIndent_10, br_5.line_0, br_5.col_0);
          i_43 = X60Qx_779;
          endTree_0_nifjp9lau1(b_63);}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&br_5));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_166));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_166));}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_63);
  result_48 = i_43;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_19));
  return result_48;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_19));
  return result_48;}
NI64 parseBlock_0_parq39nt2(Parser_0_parq39nt2* ps_84, Builder_0_nifjp9lau1* b_64, NI64 kwIdx_12, NI32 pl_59, NI32 pc_59){
  NI64 result_49;
  Token_0_tok9e79hf kw_20 = tok_0_parq39nt2((&(*ps_84)), kwIdx_12);
  NI32 refIndent_11 = kw_20.col_0;
  addTree_0_nifjp9lau1(b_64, (string_0_sysvq0asl){
    .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_84)), b_64, kw_20.line_0, kw_20.col_0, pl_59, pc_59, NIM_FALSE);
  NI64 hi_52 = lineEnd_0_parq39nt2((&(*ps_84)), kwIdx_12);
  NI64 colon_9 = findColon_0_parq39nt2((&(*ps_84)), kwIdx_12, hi_52);
  NB8 X60Qx_176;
  if (((NI64)(kwIdx_12 + IL64(1))) < colon_9){
    Token_0_tok9e79hf X60Qtmp_172 = tok_0_parq39nt2((&(*ps_84)), ((NI64)(kwIdx_12 + IL64(1))));
    X60Qx_176 = (X60Qtmp_172.kind_0 == IL64(1));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_172));}
  else {
    X60Qx_176 = NIM_FALSE;}
  if (X60Qx_176){
    Token_0_tok9e79hf lbl_0 = tok_0_parq39nt2((&(*ps_84)), ((NI64)(kwIdx_12 + IL64(1))));
    emitName_0_parq39nt2((&(*ps_84)), b_64, (&lbl_0), kw_20.line_0, kw_20.col_0);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lbl_0));}
  else {
    addEmpty_0_nifjp9lau1(b_64, IL64(1));}
  NI64 X60Qx_780 = emitBody_0_parq39nt2(ps_84, b_64, colon_9, refIndent_11, kw_20.line_0, kw_20.col_0);
  result_49 = X60Qx_780;
  endTree_0_nifjp9lau1(b_64);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_20));
  return result_49;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_20));
  return result_49;}
NI64 parseBreakLike_0_parq39nt2(Parser_0_parq39nt2* ps_85, Builder_0_nifjp9lau1* b_65, NI64 kwIdx_13, NI32 pl_60, NI32 pc_60, string_0_sysvq0asl tag_6){
  NI64 result_50;
  Token_0_tok9e79hf kw_21 = tok_0_parq39nt2((&(*ps_85)), kwIdx_13);
  NI64 hi_53 = lineEnd_0_parq39nt2((&(*ps_85)), kwIdx_13);
  addTree_0_nifjp9lau1(b_65, tag_6);
  emitInfo_0_parq39nt2((&(*ps_85)), b_65, kw_21.line_0, kw_21.col_0, pl_60, pc_60, NIM_FALSE);
  NB8 X60Qx_177;
  if (((NI64)(kwIdx_13 + IL64(1))) < hi_53){
    Token_0_tok9e79hf X60Qtmp_173 = tok_0_parq39nt2((&(*ps_85)), ((NI64)(kwIdx_13 + IL64(1))));
    X60Qx_177 = (X60Qtmp_173.kind_0 == IL64(1));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_173));}
  else {
    X60Qx_177 = NIM_FALSE;}
  if (X60Qx_177){
    Token_0_tok9e79hf lbl_1 = tok_0_parq39nt2((&(*ps_85)), ((NI64)(kwIdx_13 + IL64(1))));
    emitName_0_parq39nt2((&(*ps_85)), b_65, (&lbl_1), kw_21.line_0, kw_21.col_0);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lbl_1));}
  else {
    addEmpty_0_nifjp9lau1(b_65, IL64(1));}
  endTree_0_nifjp9lau1(b_65);
  result_50 = hi_53;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_21));
  return result_50;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_21));
  return result_50;}
NI64 parseDefer_0_parq39nt2(Parser_0_parq39nt2* ps_86, Builder_0_nifjp9lau1* b_66, NI64 kwIdx_14, NI32 pl_61, NI32 pc_61){
  NI64 result_51;
  Token_0_tok9e79hf kw_22 = tok_0_parq39nt2((&(*ps_86)), kwIdx_14);
  NI32 refIndent_12 = kw_22.col_0;
  addTree_0_nifjp9lau1(b_66, (string_0_sysvq0asl){
    .bytes_0 = 125779835184133ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_86)), b_66, kw_22.line_0, kw_22.col_0, pl_61, pc_61, NIM_FALSE);
  NI64 hi_54 = lineEnd_0_parq39nt2((&(*ps_86)), kwIdx_14);
  NI64 colon_10 = findColon_0_parq39nt2((&(*ps_86)), kwIdx_14, hi_54);
  NI64 X60Qx_781 = emitBody_0_parq39nt2(ps_86, b_66, colon_10, refIndent_12, kw_22.line_0, kw_22.col_0);
  result_51 = X60Qx_781;
  endTree_0_nifjp9lau1(b_66);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_22));
  return result_51;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_22));
  return result_51;}
NI64 parseCtrlFlowValue_0_parq39nt2(Parser_0_parq39nt2* ps_87, Builder_0_nifjp9lau1* b_67, NI64 kwIdx_15, NI32 pl_62, NI32 pc_62){
  NI64 result_52;
  Token_0_tok9e79hf X60Qtmp_174 = tok_0_parq39nt2((&(*ps_87)), kwIdx_15);
  string_0_sysvq0asl s_16 = nimStrDup(X60Qtmp_174.s_0);
  NB8 X60Qx_782 = eqQ_20_sysvq0asl(s_16, (string_0_sysvq0asl){
    .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
  );
  if (X60Qx_782){
    NI64 X60Qx_783 = parseTry_1_parq39nt2(ps_87, b_67, kwIdx_15, pl_62, pc_62);
    result_52 = X60Qx_783;}
  else {
    NB8 X60Qx_784 = eqQ_20_sysvq0asl(s_16, (string_0_sysvq0asl){
      .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
    );
    if (X60Qx_784){
      NI64 X60Qx_785 = parseIfLike_0_parq39nt2(ps_87, b_67, kwIdx_15, pl_62, pc_62, (string_0_sysvq0asl){
        .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
      );
      result_52 = X60Qx_785;}
    else {
      NB8 X60Qx_786 = eqQ_20_sysvq0asl(s_16, (string_0_sysvq0asl){
        .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
      );
      if (X60Qx_786){
        NI64 X60Qx_787 = parseIfLike_0_parq39nt2(ps_87, b_67, kwIdx_15, pl_62, pc_62, (string_0_sysvq0asl){
          .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
        );
        result_52 = X60Qx_787;}
      else {
        NB8 X60Qx_788 = eqQ_20_sysvq0asl(s_16, (string_0_sysvq0asl){
          .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_788){
          NI64 X60Qx_789 = parseCase_0_parq39nt2(ps_87, b_67, kwIdx_15, pl_62, pc_62);
          result_52 = X60Qx_789;}
        else {
          NB8 X60Qx_790 = eqQ_20_sysvq0asl(s_16, (string_0_sysvq0asl){
            .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
          );
          if (X60Qx_790){
            NI64 X60Qx_791 = parseBlock_0_parq39nt2(ps_87, b_67, kwIdx_15, pl_62, pc_62);
            result_52 = X60Qx_791;}
          else {
            result_52 = kwIdx_15;}}}}}
  nimStrDestroy(s_16);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_174));
  return result_52;
  nimStrDestroy(s_16);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_174));
  return result_52;}
NI64 parseSectionDef_0_parq39nt2(Parser_0_parq39nt2* ps_88, Builder_0_nifjp9lau1* b_68, NI64 lo_36, NI64 hi_36, string_0_sysvq0asl tag_7, NI32 pl_63, NI32 pc_63){
  NI64 result_53;
  result_53 = hi_36;
  Token_0_tok9e79hf X60Qtmp_175 = tok_0_parq39nt2((&(*ps_88)), lo_36);
  if (X60Qtmp_175.kind_0 == IL64(10)){
    Token_0_tok9e79hf lp_3 = tok_0_parq39nt2((&(*ps_88)), lo_36);
    NI64 rp_6 = matchClose_0_parq39nt2((&(*ps_88)), lo_36);
    NI64 assign_0 = findAssign_0_parq39nt2((&(*ps_88)), ((NI64)(rp_6 + IL64(1))), hi_36);
    addTree_0_nifjp9lau1(b_68, (string_0_sysvq0asl){
      .bytes_0 = 7235986496450098686ull, .more_0 = (&strlit_0_I7731358638274129439_parq39nt2)}
    );
    emitInfo_0_parq39nt2((&(*ps_88)), b_68, lp_3.line_0, lp_3.col_0, pl_63, pc_63, NIM_FALSE);
    NB8 X60Qx_792;
    if (IL64(0) <= assign_0){
      X60Qx_792 = (((NI64)(assign_0 + IL64(1))) < hi_36);}
    else {
      X60Qx_792 = NIM_FALSE;}
    if (X60Qx_792){
      Token_0_tok9e79hf vt_0 = tok_0_parq39nt2((&(*ps_88)), ((NI64)(assign_0 + IL64(1))));
      NB8 X60Qx_793;
      if (vt_0.kind_0 == IL64(2)){
        NB8 X60Qx_794;
        NB8 X60Qx_795;
        NB8 X60Qx_796;
        NB8 X60Qx_797;
        NB8 X60Qx_798 = eqQ_20_sysvq0asl(vt_0.s_0, (string_0_sysvq0asl){
          .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
        );
        if (X60Qx_798){
          X60Qx_797 = NIM_TRUE;}
        else {
          NB8 X60Qx_799 = eqQ_20_sysvq0asl(vt_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
          );
          X60Qx_797 = X60Qx_799;}
        if (X60Qx_797){
          X60Qx_796 = NIM_TRUE;}
        else {
          NB8 X60Qx_800 = eqQ_20_sysvq0asl(vt_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
          );
          X60Qx_796 = X60Qx_800;}
        if (X60Qx_796){
          X60Qx_795 = NIM_TRUE;}
        else {
          NB8 X60Qx_801 = eqQ_20_sysvq0asl(vt_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
          );
          X60Qx_795 = X60Qx_801;}
        if (X60Qx_795){
          X60Qx_794 = NIM_TRUE;}
        else {
          NB8 X60Qx_802 = eqQ_20_sysvq0asl(vt_0.s_0, (string_0_sysvq0asl){
            .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
          );
          X60Qx_794 = X60Qx_802;}
        X60Qx_793 = X60Qx_794;}
      else {
        X60Qx_793 = NIM_FALSE;}
      if (X60Qx_793){
        NI64 X60Qx_803 = parseCtrlFlowValue_0_parq39nt2(ps_88, b_68, ((NI64)(assign_0 + IL64(1))), lp_3.line_0, lp_3.col_0);
        result_53 = X60Qx_803;}
      else {
        parseExprRange_1_parq39nt2(ps_88, b_68, ((NI32)((NI64)(assign_0 + IL64(1)))), ((NI32)hi_36), lp_3.line_0, lp_3.col_0);}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&vt_0));}
    else {
      addEmpty_0_nifjp9lau1(b_68, IL64(1));}
    addTree_0_nifjp9lau1(b_68, (string_0_sysvq0asl){
      .bytes_0 = 8388908001056945662ull, .more_0 = (&strlit_0_I1237672436915077942_parq39nt2)}
    );
    seq_0_Iotb7mc_mat7cnfv21 starts_11 = splitArgs_0_parq39nt2((&(*ps_88)), ((NI64)(lo_36 + IL64(1))), rp_6);
    {
      NI64 X60Qlf_66 = IL64(0);
      NI64 X60Qlf_67 = len_3_I12oavy1_parq39nt2(starts_11);
      NI64 X60Qlf_68 = X60Qlf_66;
      {
        while (X60Qlf_68 < X60Qlf_67){
          {
            NI64* X60Qx_804 = getQ_7_Ite3z0o_parq39nt2(starts_11, X60Qlf_68);
            Token_0_tok9e79hf X60Qii_2 = tok_0_parq39nt2((&(*ps_88)), (*X60Qx_804));
            addTree_0_nifjp9lau1(b_68, tag_7);
            emitName_0_parq39nt2((&(*ps_88)), b_68, (&X60Qii_2), lp_3.line_0, lp_3.col_0);
            addEmpty_0_nifjp9lau1(b_68, IL64(1));
            addEmpty_0_nifjp9lau1(b_68, IL64(1));
            addEmpty_0_nifjp9lau1(b_68, IL64(2));
            endTree_0_nifjp9lau1(b_68);
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_2));}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_68));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;
    endTree_0_nifjp9lau1(b_68);
    endTree_0_nifjp9lau1(b_68);
    eQdestroy_1_Iez2nr5_mat7cnfv21(starts_11);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lp_3));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_175));
    return result_53;
    eQdestroy_1_Iez2nr5_mat7cnfv21(starts_11);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lp_3));}
  NI64 colon_11 = findColon_0_parq39nt2((&(*ps_88)), lo_36, hi_36);
  NI64 assign_1 = findAssign_0_parq39nt2((&(*ps_88)), lo_36, hi_36);
  NB8 X60Qx_805;
  if (IL64(0) <= assign_1){
    X60Qx_805 = (assign_1 < colon_11);}
  else {
    X60Qx_805 = NIM_FALSE;}
  if (X60Qx_805){
    colon_11 = IL64(-1);}
  NI64 X60Qx_43;
  if (IL64(0) <= colon_11){
    X60Qx_43 = colon_11;}
  else {
    if (IL64(0) <= assign_1){
      X60Qx_43 = assign_1;}
    else {
      X60Qx_43 = hi_36;}}
  NI64 boundary_0 = X60Qx_43;
  NI64 pragLo_4 = IL64(-1);
  NI64 pragHi_4 = IL64(-1);
  {
    NI64 d_9 = IL64(0);
    NI64 k_18 = lo_36;
    {
      while (k_18 < boundary_0){
        Token_0_tok9e79hf X60Qtmp_176 = tok_0_parq39nt2((&(*ps_88)), k_18);
        TokKind_0_tok9e79hf kk_5 = X60Qtmp_176.kind_0;
        NB8 X60Qx_806;
        if (kk_5 == IL64(14)){
          X60Qx_806 = (d_9 == IL64(0));}
        else {
          X60Qx_806 = NIM_FALSE;}
        if (X60Qx_806){
          pragLo_4 = k_18;
          NI64 X60Qx_807 = matchClose_0_parq39nt2((&(*ps_88)), k_18);
          pragHi_4 = X60Qx_807;
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_176));
          goto whileStmtLabel_4;}
        NB8 X60Qx_808 = isOpenBracket_0_parq39nt2(kk_5);
        if (X60Qx_808){
          inc_1_Irn1g7r1_aif7a4qfr((&d_9));}
        else {
          NB8 X60Qx_809 = isCloseBracket_0_parq39nt2(kk_5);
          if (X60Qx_809){
            if (IL64(0) < d_9){
              dec_1_I2mwrey1_envto7w6l1((&d_9));}}}
        inc_1_Irn1g7r1_aif7a4qfr((&k_18));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_176));}}
    whileStmtLabel_4: ;}
  X60Qlab_3: ;
  NI64 X60Qx_44;
  if (IL64(0) <= pragLo_4){
    X60Qx_44 = pragLo_4;}
  else {
    if (IL64(0) <= colon_11){
      X60Qx_44 = colon_11;}
    else {
      if (IL64(0) <= assign_1){
        X60Qx_44 = assign_1;}
      else {
        X60Qx_44 = hi_36;}}}
  NI64 nameEnd_0 = X60Qx_44;
  NI64 X60Qx_45;
  if (IL64(0) <= colon_11){
    X60Qx_45 = ((NI64)(colon_11 + IL64(1)));}
  else {
    X60Qx_45 = IL64(-1);}
  NI64 typeLo_0 = X60Qx_45;
  NI64 X60Qx_46;
  if (IL64(0) <= colon_11){
    NI64 X60Qx_47;
    if (IL64(0) <= assign_1){
      X60Qx_47 = assign_1;}
    else {
      X60Qx_47 = hi_36;}
    X60Qx_46 = X60Qx_47;}
  else {
    X60Qx_46 = IL64(-1);}
  NI64 typeHi_0 = X60Qx_46;
  NI64 X60Qx_48;
  if (IL64(0) <= assign_1){
    X60Qx_48 = ((NI64)(assign_1 + IL64(1)));}
  else {
    X60Qx_48 = IL64(-1);}
  NI64 valLo_0 = X60Qx_48;
  seq_0_Iotb7mc_mat7cnfv21 nameStarts_0 = splitArgs_0_parq39nt2((&(*ps_88)), lo_36, nameEnd_0);
  {
    NI64 X60Qlf_69 = IL64(0);
    NI64 X60Qlf_70 = len_3_I12oavy1_parq39nt2(nameStarts_0);
    NI64 X60Qlf_71 = X60Qlf_69;
    {
      while (X60Qlf_71 < X60Qlf_70){
        {
          NI64* X60Qx_810 = getQ_7_Ite3z0o_parq39nt2(nameStarts_0, X60Qlf_71);
          Token_0_tok9e79hf X60Qii_7 = tok_0_parq39nt2((&(*ps_88)), (*X60Qx_810));
          NB8 X60Qx_178;
          NB8 X60Qx_179;
          NI64* X60Qx_811 = getQ_7_Ite3z0o_parq39nt2(nameStarts_0, X60Qlf_71);
          if (((NI64)((*X60Qx_811) + IL64(1))) < nameEnd_0){
            NI64* X60Qx_812 = getQ_7_Ite3z0o_parq39nt2(nameStarts_0, X60Qlf_71);
            Token_0_tok9e79hf X60Qtmp_177 = tok_0_parq39nt2((&(*ps_88)), ((NI64)((*X60Qx_812) + IL64(1))));
            X60Qx_179 = (X60Qtmp_177.kind_0 == IL64(9));
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_177));}
          else {
            X60Qx_179 = NIM_FALSE;}
          if (X60Qx_179){
            NI64* X60Qx_813 = getQ_7_Ite3z0o_parq39nt2(nameStarts_0, X60Qlf_71);
            Token_0_tok9e79hf X60Qtmp_178 = tok_0_parq39nt2((&(*ps_88)), ((NI64)((*X60Qx_813) + IL64(1))));
            NB8 X60Qx_814 = eqQ_20_sysvq0asl(X60Qtmp_178.s_0, (string_0_sysvq0asl){
              .bytes_0 = 10753ull, .more_0 = NIM_NIL}
            );
            X60Qx_178 = X60Qx_814;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_178));}
          else {
            X60Qx_178 = NIM_FALSE;}
          NB8 X60Qii_8 = X60Qx_178;
          Token_0_tok9e79hf X60Qx_49;
          eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_49));
          if (IL64(0) <= pragLo_4){
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_49));
            Token_0_tok9e79hf X60Qx_815 = tok_0_parq39nt2((&(*ps_88)), pragLo_4);
            X60Qx_49 = X60Qx_815;}
          else {
            if (X60Qii_8){
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_49));
              NI64* X60Qx_816 = getQ_7_Ite3z0o_parq39nt2(nameStarts_0, X60Qlf_71);
              Token_0_tok9e79hf X60Qx_817 = tok_0_parq39nt2((&(*ps_88)), ((NI64)((*X60Qx_816) + IL64(1))));
              X60Qx_49 = X60Qx_817;}
            else {
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_49));
              Token_0_tok9e79hf X60Qx_818 = eQdupQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_7));
              X60Qx_49 = X60Qx_818;}}
          Token_0_tok9e79hf X60Qii_9 = X60Qx_49;
          eQwasmovedQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_49));
          addTree_0_nifjp9lau1(b_68, tag_7);
          emitInfo_0_parq39nt2((&(*ps_88)), b_68, X60Qii_9.line_0, X60Qii_9.col_0, pl_63, pc_63, NIM_FALSE);
          emitName_0_parq39nt2((&(*ps_88)), b_68, (&X60Qii_7), X60Qii_9.line_0, X60Qii_9.col_0);
          if (X60Qii_8){
            addRaw_0_nifjp9lau1(b_68, (string_0_sysvq0asl){
              .bytes_0 = 7872514ull, .more_0 = NIM_NIL}
            );}
          else {
            addEmpty_0_nifjp9lau1(b_68, IL64(1));}
          if (IL64(0) <= pragLo_4){
            NI64 X60Qx_819 = parsePragmas_1_parq39nt2(ps_88, b_68, pragLo_4, X60Qii_9.line_0, X60Qii_9.col_0);}
          else {
            addEmpty_0_nifjp9lau1(b_68, IL64(1));}
          NB8 X60Qx_820;
          if (IL64(0) <= typeLo_0){
            X60Qx_820 = (typeLo_0 < typeHi_0);}
          else {
            X60Qx_820 = NIM_FALSE;}
          if (X60Qx_820){
            parseTypeRange_1_parq39nt2(ps_88, b_68, ((NI32)typeLo_0), ((NI32)typeHi_0), X60Qii_9.line_0, X60Qii_9.col_0);}
          else {
            addEmpty_0_nifjp9lau1(b_68, IL64(1));}
          NB8 X60Qx_821;
          if (IL64(0) <= valLo_0){
            X60Qx_821 = (valLo_0 < hi_36);}
          else {
            X60Qx_821 = NIM_FALSE;}
          if (X60Qx_821){
            Token_0_tok9e79hf X60Qii_10 = tok_0_parq39nt2((&(*ps_88)), valLo_0);
            NB8 X60Qx_822;
            NB8 X60Qx_823;
            NI64 X60Qx_824 = len_3_I12oavy1_parq39nt2(nameStarts_0);
            if (X60Qx_824 == IL64(1)){
              X60Qx_823 = (X60Qii_10.kind_0 == IL64(2));}
            else {
              X60Qx_823 = NIM_FALSE;}
            if (X60Qx_823){
              NB8 X60Qx_825;
              NB8 X60Qx_826;
              NB8 X60Qx_827;
              NB8 X60Qx_828;
              NB8 X60Qx_829 = eqQ_20_sysvq0asl(X60Qii_10.s_0, (string_0_sysvq0asl){
                .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
              );
              if (X60Qx_829){
                X60Qx_828 = NIM_TRUE;}
              else {
                NB8 X60Qx_830 = eqQ_20_sysvq0asl(X60Qii_10.s_0, (string_0_sysvq0asl){
                  .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
                );
                X60Qx_828 = X60Qx_830;}
              if (X60Qx_828){
                X60Qx_827 = NIM_TRUE;}
              else {
                NB8 X60Qx_831 = eqQ_20_sysvq0asl(X60Qii_10.s_0, (string_0_sysvq0asl){
                  .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
                );
                X60Qx_827 = X60Qx_831;}
              if (X60Qx_827){
                X60Qx_826 = NIM_TRUE;}
              else {
                NB8 X60Qx_832 = eqQ_20_sysvq0asl(X60Qii_10.s_0, (string_0_sysvq0asl){
                  .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
                );
                X60Qx_826 = X60Qx_832;}
              if (X60Qx_826){
                X60Qx_825 = NIM_TRUE;}
              else {
                NB8 X60Qx_833 = eqQ_20_sysvq0asl(X60Qii_10.s_0, (string_0_sysvq0asl){
                  .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
                );
                X60Qx_825 = X60Qx_833;}
              X60Qx_822 = X60Qx_825;}
            else {
              X60Qx_822 = NIM_FALSE;}
            if (X60Qx_822){
              NI64 X60Qx_834 = parseCtrlFlowValue_0_parq39nt2(ps_88, b_68, valLo_0, X60Qii_9.line_0, X60Qii_9.col_0);
              result_53 = X60Qx_834;}
            else {
              NB8 X60Qx_835;
              NB8 X60Qx_836;
              NI64 X60Qx_837 = len_3_I12oavy1_parq39nt2(nameStarts_0);
              if (X60Qx_837 == IL64(1)){
                X60Qx_836 = (X60Qii_10.kind_0 == IL64(1));}
              else {
                X60Qx_836 = NIM_FALSE;}
              if (X60Qx_836){
                NI64 X60Qx_838 = depth0Colon_0_parq39nt2((&(*ps_88)), valLo_0, hi_36);
                X60Qx_835 = (valLo_0 < X60Qx_838);}
              else {
                X60Qx_835 = NIM_FALSE;}
              if (X60Qx_835){
                NI64 X60Qx_839 = depth0Colon_0_parq39nt2((&(*ps_88)), valLo_0, hi_36);
                NI64 X60Qx_840 = parsePostExprBlock_1_parq39nt2(ps_88, b_68, valLo_0, X60Qx_839, X60Qii_9.line_0, X60Qii_9.col_0);
                result_53 = X60Qx_840;}
              else {
                parseExprRange_1_parq39nt2(ps_88, b_68, ((NI32)valLo_0), ((NI32)hi_36), X60Qii_9.line_0, X60Qii_9.col_0);}}
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_10));}
          else {
            addEmpty_0_nifjp9lau1(b_68, IL64(1));}
          endTree_0_nifjp9lau1(b_68);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_9));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qx_49));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qii_7));}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_71));}}
    whileStmtLabel_6: ;}
  forStmtLabel_5: ;
  eQdestroy_1_Iez2nr5_mat7cnfv21(nameStarts_0);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_175));
  return result_53;
  eQdestroy_1_Iez2nr5_mat7cnfv21(nameStarts_0);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_175));
  return result_53;}
NI64 parseSection_0_parq39nt2(Parser_0_parq39nt2* ps_89, Builder_0_nifjp9lau1* b_69, NI64 kwIdx_16, NI32 pl_64, NI32 pc_64, string_0_sysvq0asl tag_8){
  NI64 result_54;
  Token_0_tok9e79hf kw_23 = tok_0_parq39nt2((&(*ps_89)), kwIdx_16);
  Token_0_tok9e79hf next_0 = tok_0_parq39nt2((&(*ps_89)), ((NI64)(kwIdx_16 + IL64(1))));
  if (next_0.kind_0 == IL64(0)){
    result_54 = ((NI64)(kwIdx_16 + IL64(1)));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&next_0));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_23));
    return result_54;}
  if (((NI32)IL64(0)) <= next_0.indent_0){
    NI32 refIndent_13 = kw_23.col_0;
    NI32 memberIndent_0 = next_0.indent_0;
    NI64 i_44 = ((NI64)(kwIdx_16 + IL64(1)));
    {
      while (NIM_TRUE){
        NB8 X60Qx_180;
        Token_0_tok9e79hf X60Qtmp_179 = tok_0_parq39nt2((&(*ps_89)), i_44);
        if ((!(X60Qtmp_179.kind_0 == IL64(0)))){
          Token_0_tok9e79hf X60Qtmp_180 = tok_0_parq39nt2((&(*ps_89)), i_44);
          X60Qx_180 = (refIndent_13 < X60Qtmp_180.indent_0);
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_180));}
        else {
          X60Qx_180 = NIM_FALSE;}
        if (X60Qx_180){
          {
            Token_0_tok9e79hf X60Qtmp_181 = tok_0_parq39nt2((&(*ps_89)), i_44);
            if (X60Qtmp_181.kind_0 == IL64(20)){
              Token_0_tok9e79hf X60Qtmp_182 = tok_0_parq39nt2((&(*ps_89)), i_44);
              if (X60Qtmp_182.indent_0 == memberIndent_0){
                Token_0_tok9e79hf ct_3 = tok_0_parq39nt2((&(*ps_89)), i_44);
                addTree_0_nifjp9lau1(b_69, (string_0_sysvq0asl){
                  .bytes_0 = 8389754676499669767ull, .more_0 = NIM_NIL}
                );
                emitInfo_0_parq39nt2((&(*ps_89)), b_69, ct_3.line_0, ct_3.col_0, pl_64, pc_64, NIM_FALSE);
                endTree_0_nifjp9lau1(b_69);
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&ct_3));}
              inc_1_Irn1g7r1_aif7a4qfr((&i_44));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_182));
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_181));
              goto continueLabel_1;
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_182));}
            NI64 dhi_0 = lineEnd_0_parq39nt2((&(*ps_89)), i_44);
            NI64 consumed_0 = parseSectionDef_0_parq39nt2(ps_89, b_69, i_44, dhi_0, tag_8, pl_64, pc_64);
            NI64 X60Qx_50;
            if (dhi_0 < consumed_0){
              X60Qx_50 = consumed_0;}
            else {
              X60Qx_50 = dhi_0;}
            i_44 = X60Qx_50;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_181));}
          continueLabel_1: ;}
        else {
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_179));
          break;}
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_179));}}
    whileStmtLabel_0: ;
    result_54 = i_44;}
  else {
    NI64 X60Qx_841 = lineEnd_0_parq39nt2((&(*ps_89)), kwIdx_16);
    NI64 hi_55 = semiEnd_0_parq39nt2((&(*ps_89)), kwIdx_16, X60Qx_841);
    NI64 X60Qx_842 = parseSectionDef_0_parq39nt2(ps_89, b_69, ((NI64)(kwIdx_16 + IL64(1))), hi_55, tag_8, pl_64, pc_64);
    result_54 = X60Qx_842;}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&next_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_23));
  return result_54;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&next_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_23));
  return result_54;}
NI64 parsePragmaStmt_0_parq39nt2(Parser_0_parq39nt2* ps_90, Builder_0_nifjp9lau1* b_70, NI64 braceIdx_2, NI32 pl_65, NI32 pc_65){
  NI64 result_55;
  Token_0_tok9e79hf brace_2 = tok_0_parq39nt2((&(*ps_90)), braceIdx_2);
  NI64 rb_9 = matchClose_0_parq39nt2((&(*ps_90)), braceIdx_2);
  Token_0_tok9e79hf X60Qtmp_183 = tok_0_parq39nt2((&(*ps_90)), ((NI64)(rb_9 + IL64(1))));
  if (X60Qtmp_183.kind_0 == IL64(18)){
    addTree_0_nifjp9lau1(b_70, (string_0_sysvq0asl){
      .bytes_0 = 8674334648076234759ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_90)), b_70, brace_2.line_0, brace_2.col_0, pl_65, pc_65, NIM_FALSE);
    NI64 X60Qx_843 = parsePragmas_1_parq39nt2(ps_90, b_70, braceIdx_2, brace_2.line_0, brace_2.col_0);
    NI64 X60Qx_844 = emitBody_0_parq39nt2(ps_90, b_70, ((NI64)(rb_9 + IL64(1))), brace_2.col_0, brace_2.line_0, brace_2.col_0);
    result_55 = X60Qx_844;
    endTree_0_nifjp9lau1(b_70);}
  else {
    NI64 X60Qx_845 = parsePragmas_1_parq39nt2(ps_90, b_70, braceIdx_2, pl_65, pc_65);
    result_55 = X60Qx_845;}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_183));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&brace_2));
  return result_55;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_183));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&brace_2));
  return result_55;}
NI64 parseFromImport_0_parq39nt2(Parser_0_parq39nt2* ps_91, Builder_0_nifjp9lau1* b_71, NI64 kwIdx_17, NI32 pl_66, NI32 pc_66){
  NI64 result_56;
  Token_0_tok9e79hf kw_24 = tok_0_parq39nt2((&(*ps_91)), kwIdx_17);
  NI64 X60Qx_846 = lineEnd_0_parq39nt2((&(*ps_91)), kwIdx_17);
  NI64 hi_56 = semiEnd_0_parq39nt2((&(*ps_91)), kwIdx_17, X60Qx_846);
  NI64 impIdx_0 = IL64(-1);
  NI64 d_10 = IL64(0);
  NI64 i_45 = ((NI64)(kwIdx_17 + IL64(1)));
  {
    while (i_45 < hi_56){
      Token_0_tok9e79hf t_25 = tok_0_parq39nt2((&(*ps_91)), i_45);
      NB8 X60Qx_847 = isOpenBracket_0_parq39nt2(t_25.kind_0);
      if (X60Qx_847){
        inc_1_Irn1g7r1_aif7a4qfr((&d_10));}
      else {
        NB8 X60Qx_848 = isCloseBracket_0_parq39nt2(t_25.kind_0);
        if (X60Qx_848){
          if (IL64(0) < d_10){
            dec_1_I2mwrey1_envto7w6l1((&d_10));}}
        else {
          NB8 X60Qx_849;
          NB8 X60Qx_850;
          if (d_10 == IL64(0)){
            X60Qx_850 = (t_25.kind_0 == IL64(2));}
          else {
            X60Qx_850 = NIM_FALSE;}
          if (X60Qx_850){
            NB8 X60Qx_851 = eqQ_20_sysvq0asl(t_25.s_0, (string_0_sysvq0asl){
              .bytes_0 = 32776920251590918ull, .more_0 = NIM_NIL}
            );
            X60Qx_849 = X60Qx_851;}
          else {
            X60Qx_849 = NIM_FALSE;}
          if (X60Qx_849){
            impIdx_0 = i_45;
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_25));
            goto whileStmtLabel_0;}}}
      inc_1_Irn1g7r1_aif7a4qfr((&i_45));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_25));}}
  whileStmtLabel_0: ;
  addTree_0_nifjp9lau1(b_71, (string_0_sysvq0asl){
    .bytes_0 = 8101247223451510526ull, .more_0 = (&strlit_0_I3199637833187763350_parq39nt2)}
  );
  emitInfo_0_parq39nt2((&(*ps_91)), b_71, kw_24.line_0, kw_24.col_0, pl_66, pc_66, NIM_FALSE);
  NI64 X60Qx_51;
  if (IL64(0) <= impIdx_0){
    X60Qx_51 = impIdx_0;}
  else {
    X60Qx_51 = hi_56;}
  NI64 modHi_0 = X60Qx_51;
  if (((NI64)(kwIdx_17 + IL64(1))) < modHi_0){
    parseExprRange_1_parq39nt2(ps_91, b_71, ((NI32)((NI64)(kwIdx_17 + IL64(1)))), ((NI32)modHi_0), kw_24.line_0, kw_24.col_0);}
  else {
    addEmpty_0_nifjp9lau1(b_71, IL64(1));}
  if (IL64(0) <= impIdx_0){
    seq_0_Iotb7mc_mat7cnfv21 starts_12 = splitArgs_0_parq39nt2((&(*ps_91)), ((NI64)(impIdx_0 + IL64(1))), hi_56);
    {
      NI64 X60Qlf_72 = IL64(0);
      NI64 X60Qlf_73 = len_3_I12oavy1_parq39nt2(starts_12);
      NI64 X60Qlf_74 = X60Qlf_72;
      {
        while (X60Qlf_74 < X60Qlf_73){
          {
            NI64* X60Qx_852 = getQ_7_Ite3z0o_parq39nt2(starts_12, X60Qlf_74);
            NI64 X60Qii_3 = (*X60Qx_852);
            NI64 X60Qx_52;
            NI64 X60Qx_853 = len_3_I12oavy1_parq39nt2(starts_12);
            if (((NI64)(X60Qlf_74 + IL64(1))) < X60Qx_853){
              NI64* X60Qx_854 = getQ_7_Ite3z0o_parq39nt2(starts_12, ((NI64)(X60Qlf_74 + IL64(1))));
              X60Qx_52 = ((NI64)((*X60Qx_854) - IL64(1)));}
            else {
              X60Qx_52 = hi_56;}
            NI64 X60Qii_4 = X60Qx_52;
            if (X60Qii_3 < X60Qii_4){
              parseExprRange_1_parq39nt2(ps_91, b_71, ((NI32)X60Qii_3), ((NI32)X60Qii_4), kw_24.line_0, kw_24.col_0);}}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_74));}}
      whileStmtLabel_2: ;}
    forStmtLabel_1: ;
    eQdestroy_1_Iez2nr5_mat7cnfv21(starts_12);}
  endTree_0_nifjp9lau1(b_71);
  result_56 = hi_56;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_24));
  return result_56;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_24));
  return result_56;}
NI64 parseStatic_0_parq39nt2(Parser_0_parq39nt2* ps_92, Builder_0_nifjp9lau1* b_72, NI64 kwIdx_18, NI32 pl_67, NI32 pc_67){
  NI64 result_57;
  Token_0_tok9e79hf kw_25 = tok_0_parq39nt2((&(*ps_92)), kwIdx_18);
  addTree_0_nifjp9lau1(b_72, (string_0_sysvq0asl){
    .bytes_0 = 8314605285628212222ull, .more_0 = (&strlit_0_I4843651051758684618_parq39nt2)}
  );
  emitInfo_0_parq39nt2((&(*ps_92)), b_72, kw_25.line_0, kw_25.col_0, pl_67, pc_67, NIM_FALSE);
  NI64 hi_57 = lineEnd_0_parq39nt2((&(*ps_92)), kwIdx_18);
  NI64 colon_12 = findColon_0_parq39nt2((&(*ps_92)), kwIdx_18, hi_57);
  NI64 X60Qx_855 = emitBody_0_parq39nt2(ps_92, b_72, colon_12, kw_25.col_0, kw_25.line_0, kw_25.col_0);
  result_57 = X60Qx_855;
  endTree_0_nifjp9lau1(b_72);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_25));
  return result_57;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&kw_25));
  return result_57;}
NI64 semiEnd_0_parq39nt2(Parser_0_parq39nt2* ps_93, NI64 startIdx_2, NI64 bound_0){
  NI64 result_58;
  NI64 d_11 = IL64(0);
  NI64 i_46 = startIdx_2;
  {
    while (i_46 < bound_0){
      Token_0_tok9e79hf t_26 = tok_0_parq39nt2((&(*ps_93)), i_46);
      NB8 X60Qx_856 = isOpenBracket_0_parq39nt2(t_26.kind_0);
      if (X60Qx_856){
        inc_1_Irn1g7r1_aif7a4qfr((&d_11));}
      else {
        NB8 X60Qx_857 = isCloseBracket_0_parq39nt2(t_26.kind_0);
        if (X60Qx_857){
          if (IL64(0) < d_11){
            dec_1_I2mwrey1_envto7w6l1((&d_11));}}
        else {
          NB8 X60Qx_858;
          if (d_11 == IL64(0)){
            X60Qx_858 = (t_26.kind_0 == IL64(17));}
          else {
            X60Qx_858 = NIM_FALSE;}
          if (X60Qx_858){
            eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_26));
            return i_46;}}}
      inc_1_Irn1g7r1_aif7a4qfr((&i_46));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_26));}}
  whileStmtLabel_0: ;
  result_58 = bound_0;
  return result_58;}
NI64 parsePostExprBlock_1_parq39nt2(Parser_0_parq39nt2* ps_94, Builder_0_nifjp9lau1* b_73, NI64 headLo_1, NI64 colonIdx_3, NI32 pl_68, NI32 pc_68){
  NI64 result_59;
  Token_0_tok9e79hf head_4 = tok_0_parq39nt2((&(*ps_94)), headLo_1);
  NI32 refIndent_14 = head_4.col_0;
  {
    NI64 d_12 = IL64(0);
    NI64 doIdx_0 = IL64(-1);
    NI64 k_19 = headLo_1;
    {
      while (k_19 < colonIdx_3){
        Token_0_tok9e79hf t_27 = tok_0_parq39nt2((&(*ps_94)), k_19);
        NB8 X60Qx_859 = isOpenBracket_0_parq39nt2(t_27.kind_0);
        if (X60Qx_859){
          inc_1_Irn1g7r1_aif7a4qfr((&d_12));}
        else {
          NB8 X60Qx_860 = isCloseBracket_0_parq39nt2(t_27.kind_0);
          if (X60Qx_860){
            if (IL64(0) < d_12){
              dec_1_I2mwrey1_envto7w6l1((&d_12));}}
          else {
            NB8 X60Qx_861;
            NB8 X60Qx_862;
            if (d_12 == IL64(0)){
              X60Qx_862 = (t_27.kind_0 == IL64(2));}
            else {
              X60Qx_862 = NIM_FALSE;}
            if (X60Qx_862){
              NB8 X60Qx_863 = eqQ_20_sysvq0asl(t_27.s_0, (string_0_sysvq0asl){
                .bytes_0 = 7300098ull, .more_0 = NIM_NIL}
              );
              X60Qx_861 = X60Qx_863;}
            else {
              X60Qx_861 = NIM_FALSE;}
            if (X60Qx_861){
              doIdx_0 = k_19;
              eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_27));
              goto whileStmtLabel_0;}}}
        inc_1_Irn1g7r1_aif7a4qfr((&k_19));
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_27));}}
    whileStmtLabel_0: ;
    NB8 X60Qx_181;
    if (headLo_1 < doIdx_0){
      Token_0_tok9e79hf X60Qtmp_184 = tok_0_parq39nt2((&(*ps_94)), ((NI64)(doIdx_0 + IL64(1))));
      X60Qx_181 = (X60Qtmp_184.kind_0 == IL64(10));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_184));}
    else {
      X60Qx_181 = NIM_FALSE;}
    if (X60Qx_181){
      Token_0_tok9e79hf dk_0 = tok_0_parq39nt2((&(*ps_94)), doIdx_0);
      addTree_0_nifjp9lau1(b_73, (string_0_sysvq0asl){
        .bytes_0 = 465674789636ull, .more_0 = NIM_NIL}
      );
      emitInfo_0_parq39nt2((&(*ps_94)), b_73, head_4.line_0, head_4.col_0, pl_68, pc_68, NIM_FALSE);
      Token_0_tok9e79hf X60Qtmp_185 = tok_0_parq39nt2((&(*ps_94)), ((NI64)(doIdx_0 - IL64(1))));
      if (X60Qtmp_185.kind_0 == IL64(11)){
        NI64 rparen_0 = ((NI64)(doIdx_0 - IL64(1)));
        NI64 lparen_0 = matchOpen_0_parq39nt2((&(*ps_94)), rparen_0);
        parseExprRange_1_parq39nt2(ps_94, b_73, ((NI32)headLo_1), ((NI32)lparen_0), head_4.line_0, head_4.col_0);
        parseArgList_0_parq39nt2(ps_94, b_73, ((NI32)((NI64)(lparen_0 + IL64(1)))), ((NI32)rparen_0), head_4.line_0, head_4.col_0);}
      else {
        parseExprRange_1_parq39nt2(ps_94, b_73, ((NI32)headLo_1), ((NI32)doIdx_0), head_4.line_0, head_4.col_0);}
      addTree_0_nifjp9lau1(b_73, (string_0_sysvq0asl){
        .bytes_0 = 7300098ull, .more_0 = NIM_NIL}
      );
      emitInfo_0_parq39nt2((&(*ps_94)), b_73, dk_0.line_0, dk_0.col_0, head_4.line_0, head_4.col_0, NIM_FALSE);
      NI64 X60Qx_864 = parseParams_1_parq39nt2(ps_94, b_73, ((NI64)(doIdx_0 + IL64(1))), dk_0.line_0, dk_0.col_0);
      NI64 X60Qx_865 = emitBody_0_parq39nt2(ps_94, b_73, colonIdx_3, refIndent_14, dk_0.line_0, dk_0.col_0);
      result_59 = X60Qx_865;
      endTree_0_nifjp9lau1(b_73);
      endTree_0_nifjp9lau1(b_73);
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_185));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&dk_0));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_4));
      return result_59;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_185));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&dk_0));}}
  doBlock_0: ;
  NI64 ce_5 = cmdCalleeEnd_0_parq39nt2((&(*ps_94)), headLo_1, colonIdx_3);
  NB8 X60Qx_866;
  NB8 X60Qx_867;
  if (head_4.kind_0 == IL64(1)){
    X60Qx_867 = (ce_5 < colonIdx_3);}
  else {
    X60Qx_867 = NIM_FALSE;}
  if (X60Qx_867){
    NB8 X60Qx_868 = startsArg_0_parq39nt2((&(*ps_94)), ce_5, colonIdx_3);
    X60Qx_866 = X60Qx_868;}
  else {
    X60Qx_866 = NIM_FALSE;}
  if (X60Qx_866){
    Token_0_tok9e79hf anchor_2 = calleeAnchor_0_parq39nt2((&(*ps_94)), headLo_1, ce_5);
    addTree_0_nifjp9lau1(b_73, (string_0_sysvq0asl){
      .bytes_0 = 1684890371ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_94)), b_73, anchor_2.line_0, anchor_2.col_0, pl_68, pc_68, NIM_FALSE);
    parseExprRange_1_parq39nt2(ps_94, b_73, ((NI32)headLo_1), ((NI32)ce_5), anchor_2.line_0, anchor_2.col_0);
    parseArgList_0_parq39nt2(ps_94, b_73, ((NI32)ce_5), ((NI32)colonIdx_3), anchor_2.line_0, anchor_2.col_0);
    NI64 X60Qx_869 = emitBody_0_parq39nt2(ps_94, b_73, colonIdx_3, refIndent_14, anchor_2.line_0, anchor_2.col_0);
    result_59 = X60Qx_869;
    endTree_0_nifjp9lau1(b_73);
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&anchor_2));}
  else {
    addTree_0_nifjp9lau1(b_73, (string_0_sysvq0asl){
      .bytes_0 = 465674789636ull, .more_0 = NIM_NIL}
    );
    NB8 X60Qx_182;
    if (headLo_1 <= ((NI64)(colonIdx_3 - IL64(1)))){
      Token_0_tok9e79hf X60Qtmp_186 = tok_0_parq39nt2((&(*ps_94)), ((NI64)(colonIdx_3 - IL64(1))));
      X60Qx_182 = (X60Qtmp_186.kind_0 == IL64(11));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_186));}
    else {
      X60Qx_182 = NIM_FALSE;}
    if (X60Qx_182){
      NI64 rparen_1 = ((NI64)(colonIdx_3 - IL64(1)));
      NI64 lparen_1 = matchOpen_0_parq39nt2((&(*ps_94)), rparen_1);
      Token_0_tok9e79hf lp_4 = tok_0_parq39nt2((&(*ps_94)), lparen_1);
      emitInfo_0_parq39nt2((&(*ps_94)), b_73, lp_4.line_0, lp_4.col_0, pl_68, pc_68, NIM_FALSE);
      parseExprRange_1_parq39nt2(ps_94, b_73, ((NI32)headLo_1), ((NI32)lparen_1), lp_4.line_0, lp_4.col_0);
      parseArgList_0_parq39nt2(ps_94, b_73, ((NI32)((NI64)(lparen_1 + IL64(1)))), ((NI32)rparen_1), lp_4.line_0, lp_4.col_0);
      NI64 X60Qx_870 = emitBody_0_parq39nt2(ps_94, b_73, colonIdx_3, refIndent_14, lp_4.line_0, lp_4.col_0);
      result_59 = X60Qx_870;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&lp_4));}
    else {
      Token_0_tok9e79hf anchor_3 = calleeAnchor_0_parq39nt2((&(*ps_94)), headLo_1, colonIdx_3);
      emitInfo_0_parq39nt2((&(*ps_94)), b_73, anchor_3.line_0, anchor_3.col_0, pl_68, pc_68, NIM_FALSE);
      parseExprRange_1_parq39nt2(ps_94, b_73, ((NI32)headLo_1), ((NI32)colonIdx_3), anchor_3.line_0, anchor_3.col_0);
      NI64 X60Qx_871 = emitBody_0_parq39nt2(ps_94, b_73, colonIdx_3, refIndent_14, anchor_3.line_0, anchor_3.col_0);
      result_59 = X60Qx_871;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&anchor_3));}
    endTree_0_nifjp9lau1(b_73);}
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_4));
  return result_59;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&head_4));
  return result_59;}
NI64 parseOneStmt_0_parq39nt2(Parser_0_parq39nt2* ps_95, Builder_0_nifjp9lau1* b_74, NI64 startIdx_3, NI32 pl_69, NI32 pc_69, NI64 hiLimit_1){
  NI64 result_60;
  Token_0_tok9e79hf t_28 = tok_0_parq39nt2((&(*ps_95)), startIdx_3);
  if (t_28.kind_0 == IL64(20)){
    addTree_0_nifjp9lau1(b_74, (string_0_sysvq0asl){
      .bytes_0 = 8389754676499669767ull, .more_0 = NIM_NIL}
    );
    emitInfo_0_parq39nt2((&(*ps_95)), b_74, t_28.line_0, t_28.col_0, pl_69, pc_69, NIM_FALSE);
    endTree_0_nifjp9lau1(b_74);
    result_60 = ((NI64)(startIdx_3 + IL64(1)));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;}
  NB8 X60Qx_183;
  if (t_28.kind_0 == IL64(14)){
    Token_0_tok9e79hf X60Qtmp_187 = tok_0_parq39nt2((&(*ps_95)), ((NI64)(startIdx_3 + IL64(1))));
    X60Qx_183 = (X60Qtmp_187.kind_0 == IL64(19));
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_187));}
  else {
    X60Qx_183 = NIM_FALSE;}
  if (X60Qx_183){
    NI64 X60Qx_872 = parsePragmaStmt_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_872;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;}
  if (t_28.kind_0 == IL64(2)){
    string_0_sysvq0asl X60Qtc_25 = t_28.s_0;
    NB8 X60Qtc_58 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(1), (NC8)'i');
    if (X60Qtc_58){
      NB8 X60Qtc_59 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(2), (NC8)'n');
      if (X60Qtc_59){
        NB8 X60Qtc_60 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(0), (NC8)'r');
        if (X60Qtc_60){
          NB8 X60Qtc_61 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(0), (NC8)'d');
          if (X60Qtc_61){
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 431349129732ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_41;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 125779835184133ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_53;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 122537084284165ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_31;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 111546363638277ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_35;}}}
        else {
          NB8 X60Qtc_62 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(2), (NC8)'e');
          if (X60Qtc_62){
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 110416720656645ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_36;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_45;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 8386103211268076798ull, .more_0 = (&strlit_0_I17987658270787974407_parq39nt2)}
            )){
              goto X60Qsc_32;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 111516299327237ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_46;}}}}
      else {
        NB8 X60Qtc_63 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(0), (NC8)'l');
        if (X60Qtc_63){
          NB8 X60Qtc_64 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(0), (NC8)'d');
          if (X60Qtc_64){
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 7237954630903751687ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_34;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_47;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_44;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 1952803843ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_55;}}}
        else {
          NB8 X60Qtc_65 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(0), (NC8)'m');
          if (X60Qtc_65){
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 28269992091151622ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_28;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 121399270796549ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_40;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 31088096227717638ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_33;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 1918989827ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_54;}}}}}
    else {
      NB8 X60Qtc_66 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(2), (NC8)'n');
      if (X60Qtc_66){
        NB8 X60Qtc_67 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(0), (NC8)'c');
        if (X60Qtc_67){
          NB8 X60Qtc_68 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(3), (NC8)'s');
          if (X60Qtc_68){
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 118066057994757ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_51;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 128039122854661ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_56;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 8390880615077995518ull, .more_0 = (&strlit_0_I6864681898360807206_parq39nt2)}
            )){
              goto X60Qsc_29;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 8461816698665657342ull, .more_0 = (&strlit_0_I2210116261907819816_parq39nt2)}
            )){
              goto X60Qsc_52;}}}
        else {
          NB8 X60Qtc_69 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(2), (NC8)'c');
          if (X60Qtc_69){
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 7306093603886885127ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_38;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 27981971266499334ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_43;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 427054949892ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_27;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
            )){
              goto X60Qsc_30;}}}}
      else {
        NB8 X60Qtc_70 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(0), (NC8)'f');
        if (X60Qtc_70){
          NB8 X60Qtc_71 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(0), (NC8)'e');
          if (X60Qtc_71){
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 32776920252310790ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_39;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 118074815308293ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_50;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 470021203460ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_42;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 1919903235ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_48;}}}
        else {
          NB8 X60Qtc_72 = nimStrAtLe_0_sysvq0asl(X60Qtc_25, IL64(0), (NC8)'p');
          if (X60Qtc_72){
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 427071533060ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_26;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 32776920251590918ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_37;}}
          else {
            if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 2037543939ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_49;}
            else if (equalStrings_0_sysvq0asl(X60Qtc_25, (string_0_sysvq0asl){
              .bytes_0 = 435678704644ull, .more_0 = NIM_NIL}
            )){
              goto X60Qsc_57;}}}}}
    goto X60Qsc_74;
    X60Qsc_26: ;
    NI64 X60Qx_873 = parseRoutine_1_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 427071533060ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_873;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_27: ;
    NI64 X60Qx_874 = parseRoutine_1_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 427054949892ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_874;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_28: ;
    NI64 X60Qx_875 = parseRoutine_1_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 28269992091151622ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_875;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_29: ;
    NI64 X60Qx_876 = parseRoutine_1_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 8390880615077995518ull, .more_0 = (&strlit_0_I6864681898360807206_parq39nt2)}
    );
    result_60 = X60Qx_876;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_30: ;
    NI64 X60Qx_877 = parseRoutine_1_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
    );
    result_60 = X60Qx_877;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_31: ;
    NI64 X60Qx_878 = parseRoutine_1_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 122537084284165ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_878;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_32: ;
    NI64 X60Qx_879 = parseRoutine_1_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 8386103211268076798ull, .more_0 = (&strlit_0_I17987658270787974407_parq39nt2)}
    );
    result_60 = X60Qx_879;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_33: ;
    NI64 X60Qx_880 = parseReturnLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 1952805379ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_880;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_34: ;
    NI64 X60Qx_881 = parseReturnLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 7237954630903751687ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_881;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_35: ;
    NI64 X60Qx_882 = parseReturnLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 111546363638277ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_882;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_36: ;
    NI64 X60Qx_883 = parseReturnLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 1684830467ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_883;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_37: ;
    NI64 X60Qx_884 = parseImportLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 32776920251590918ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_884;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_38: ;
    NI64 X60Qx_885 = parseImportLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 7306093603886885127ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_885;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_39: ;
    NI64 X60Qx_886 = parseImportLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 32776920252310790ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_886;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_40: ;
    NI64 X60Qx_887 = parseImportLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 121399270796549ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_887;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_41: ;
    NI64 X60Qx_888 = parseImportLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 431349129732ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_888;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_42: ;
    NI64 X60Qx_889 = parseFromImport_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_889;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_43: ;
    NI64 X60Qx_890 = parseStatic_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_890;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_44: ;
    NI64 X60Qx_891 = parseIfLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_891;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_45: ;
    NI64 X60Qx_892 = parseIfLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_892;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_46: ;
    NI64 X60Qx_893 = parseWhile_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_893;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_47: ;
    NI64 X60Qx_894 = parseCase_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_894;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_48: ;
    NI64 X60Qx_895 = parseFor_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_895;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_49: ;
    NI64 X60Qx_896 = parseTry_1_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_896;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_50: ;
    NI64 X60Qx_897 = parseBlock_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_897;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_51: ;
    NI64 X60Qx_898 = parseBreakLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 118066057994757ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_898;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_52: ;
    NI64 X60Qx_899 = parseBreakLike_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 8461816698665657342ull, .more_0 = (&strlit_0_I2210116261907819816_parq39nt2)}
    );
    result_60 = X60Qx_899;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_53: ;
    NI64 X60Qx_900 = parseDefer_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_900;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_54: ;
    NI64 X60Qx_901 = parseSection_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 1918989827ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_901;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_55: ;
    NI64 X60Qx_902 = parseSection_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 1952803843ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_902;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_56: ;
    NI64 X60Qx_903 = parseSection_0_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69, (string_0_sysvq0asl){
      .bytes_0 = 128039122854661ull, .more_0 = NIM_NIL}
    );
    result_60 = X60Qx_903;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_57: ;
    NI64 X60Qx_904 = parseTypeSection_1_parq39nt2(ps_95, b_74, startIdx_3, pl_69, pc_69);
    result_60 = X60Qx_904;
    eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
    return result_60;
    goto X60Qsc_73;
    X60Qsc_74: ;
    X60Qsc_73: ;}
  if (hiLimit_1 < IL64(0)){
    NI64 lineHi_2 = lineEnd_0_parq39nt2((&(*ps_95)), startIdx_3);
    NI64 pcolon_0 = depth0Colon_0_parq39nt2((&(*ps_95)), startIdx_3, lineHi_2);
    NB8 X60Qx_905;
    if (startIdx_3 < pcolon_0){
      NI64 X60Qx_906 = findAssign_0_parq39nt2((&(*ps_95)), startIdx_3, pcolon_0);
      X60Qx_905 = (X60Qx_906 < IL64(0));}
    else {
      X60Qx_905 = NIM_FALSE;}
    if (X60Qx_905){
      NB8 cf_0 = NIM_FALSE;
      NI64 d_13 = IL64(0);
      NI64 k_20 = startIdx_3;
      {
        while (k_20 < pcolon_0){
          Token_0_tok9e79hf t_29 = tok_0_parq39nt2((&(*ps_95)), k_20);
          NB8 X60Qx_907 = isOpenBracket_0_parq39nt2(t_29.kind_0);
          if (X60Qx_907){
            inc_1_Irn1g7r1_aif7a4qfr((&d_13));}
          else {
            NB8 X60Qx_908 = isCloseBracket_0_parq39nt2(t_29.kind_0);
            if (X60Qx_908){
              if (IL64(0) < d_13){
                dec_1_I2mwrey1_envto7w6l1((&d_13));}}
            else {
              NB8 X60Qx_909;
              NB8 X60Qx_910;
              if (d_13 == IL64(0)){
                X60Qx_910 = (t_29.kind_0 == IL64(2));}
              else {
                X60Qx_910 = NIM_FALSE;}
              if (X60Qx_910){
                NB8 X60Qx_911;
                NB8 X60Qx_912;
                NB8 X60Qx_913;
                NB8 X60Qx_914;
                NB8 X60Qx_915;
                NB8 X60Qx_916;
                NB8 X60Qx_917;
                NB8 X60Qx_918;
                NB8 X60Qx_919 = eqQ_20_sysvq0asl(t_29.s_0, (string_0_sysvq0asl){
                  .bytes_0 = 6711554ull, .more_0 = NIM_NIL}
                );
                if (X60Qx_919){
                  X60Qx_918 = NIM_TRUE;}
                else {
                  NB8 X60Qx_920 = eqQ_20_sysvq0asl(t_29.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 474147747588ull, .more_0 = NIM_NIL}
                  );
                  X60Qx_918 = X60Qx_920;}
                if (X60Qx_918){
                  X60Qx_917 = NIM_TRUE;}
                else {
                  NB8 X60Qx_921 = eqQ_20_sysvq0asl(t_29.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 435727459076ull, .more_0 = NIM_NIL}
                  );
                  X60Qx_917 = X60Qx_921;}
                if (X60Qx_917){
                  X60Qx_916 = NIM_TRUE;}
                else {
                  NB8 X60Qx_922 = eqQ_20_sysvq0asl(t_29.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 439855375620ull, .more_0 = NIM_NIL}
                  );
                  X60Qx_916 = X60Qx_922;}
                if (X60Qx_916){
                  X60Qx_915 = NIM_TRUE;}
                else {
                  NB8 X60Qx_923 = eqQ_20_sysvq0asl(t_29.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 435728180484ull, .more_0 = NIM_NIL}
                  );
                  X60Qx_915 = X60Qx_923;}
                if (X60Qx_915){
                  X60Qx_914 = NIM_TRUE;}
                else {
                  NB8 X60Qx_924 = eqQ_20_sysvq0asl(t_29.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 6713090ull, .more_0 = NIM_NIL}
                  );
                  X60Qx_914 = X60Qx_924;}
                if (X60Qx_914){
                  X60Qx_913 = NIM_TRUE;}
                else {
                  NB8 X60Qx_925 = eqQ_20_sysvq0asl(t_29.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 427071533060ull, .more_0 = NIM_NIL}
                  );
                  X60Qx_913 = X60Qx_925;}
                if (X60Qx_913){
                  X60Qx_912 = NIM_TRUE;}
                else {
                  NB8 X60Qx_926 = eqQ_20_sysvq0asl(t_29.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 427054949892ull, .more_0 = NIM_NIL}
                  );
                  X60Qx_912 = X60Qx_926;}
                if (X60Qx_912){
                  X60Qx_911 = NIM_TRUE;}
                else {
                  NB8 X60Qx_927 = eqQ_20_sysvq0asl(t_29.s_0, (string_0_sysvq0asl){
                    .bytes_0 = 8031151179464731134ull, .more_0 = (&strlit_0_I9071657656589967445_parq39nt2)}
                  );
                  X60Qx_911 = X60Qx_927;}
                X60Qx_909 = X60Qx_911;}
              else {
                X60Qx_909 = NIM_FALSE;}
              if (X60Qx_909){
                cf_0 = NIM_TRUE;
                eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_29));
                goto whileStmtLabel_0;}}}
          inc_1_Irn1g7r1_aif7a4qfr((&k_20));
          eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_29));}}
      whileStmtLabel_0: ;
      if ((!cf_0)){
        NI64 X60Qx_928 = parsePostExprBlock_1_parq39nt2(ps_95, b_74, startIdx_3, pcolon_0, pl_69, pc_69);
        result_60 = X60Qx_928;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
        return result_60;}}
    NI64 eol_0 = ((NI64)(lineHi_2 - IL64(1)));
    NB8 X60Qx_184;
    NB8 X60Qx_185;
    NB8 X60Qx_186;
    if (startIdx_3 < eol_0){
      Token_0_tok9e79hf X60Qtmp_188 = tok_0_parq39nt2((&(*ps_95)), eol_0);
      X60Qx_186 = (X60Qtmp_188.kind_0 == IL64(18));
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_188));}
    else {
      X60Qx_186 = NIM_FALSE;}
    if (X60Qx_186){
      X60Qx_185 = (pcolon_0 < eol_0);}
    else {
      X60Qx_185 = NIM_FALSE;}
    if (X60Qx_185){
      NI64 X60Qx_929 = findAssign_0_parq39nt2((&(*ps_95)), startIdx_3, eol_0);
      X60Qx_184 = (X60Qx_929 < IL64(0));}
    else {
      X60Qx_184 = NIM_FALSE;}
    if (X60Qx_184){
      NI64 X60Qx_930 = parsePostExprBlock_1_parq39nt2(ps_95, b_74, startIdx_3, eol_0, pl_69, pc_69);
      result_60 = X60Qx_930;
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
      return result_60;}}
  NI64 bound_1 = lineEnd_0_parq39nt2((&(*ps_95)), startIdx_3);
  NB8 X60Qx_931;
  if (IL64(0) <= hiLimit_1){
    X60Qx_931 = (hiLimit_1 < bound_1);}
  else {
    X60Qx_931 = NIM_FALSE;}
  if (X60Qx_931){
    bound_1 = hiLimit_1;}
  NI64 hi_58 = semiEnd_0_parq39nt2((&(*ps_95)), startIdx_3, bound_1);
  NI64 consumed_1 = parseExprStmt_0_parq39nt2(ps_95, b_74, ((NI32)startIdx_3), ((NI32)hi_58), pl_69, pc_69);
  NI64 X60Qx_53;
  if (hi_58 < consumed_1){
    X60Qx_53 = consumed_1;}
  else {
    X60Qx_53 = hi_58;}
  result_60 = X60Qx_53;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
  return result_60;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_28));
  return result_60;}
NI64 parseStmtImpl_0_parq39nt2(Parser_0_parq39nt2* ps_96, Builder_0_nifjp9lau1* b_75, NI64 startIdx_4, NI32 pl_70, NI32 pc_70, NI64 hiLimit_2){
  NI64 result_61;
  NI64 i_47 = parseOneStmt_0_parq39nt2(ps_96, b_75, startIdx_4, pl_70, pc_70, hiLimit_2);
  NI64 bound_2 = lineEnd_0_parq39nt2((&(*ps_96)), startIdx_4);
  NB8 X60Qx_932;
  if (IL64(0) <= hiLimit_2){
    X60Qx_932 = (hiLimit_2 < bound_2);}
  else {
    X60Qx_932 = NIM_FALSE;}
  if (X60Qx_932){
    bound_2 = hiLimit_2;}
  {
    while (NIM_TRUE){
      NB8 X60Qx_187;
      Token_0_tok9e79hf X60Qtmp_189 = tok_0_parq39nt2((&(*ps_96)), i_47);
      if (X60Qtmp_189.kind_0 == IL64(17)){
        X60Qx_187 = (((NI64)(i_47 + IL64(1))) < bound_2);}
      else {
        X60Qx_187 = NIM_FALSE;}
      if (X60Qx_187){
        NI64 X60Qx_933 = parseOneStmt_0_parq39nt2(ps_96, b_75, ((NI64)(i_47 + IL64(1))), pl_70, pc_70, hiLimit_2);
        i_47 = X60Qx_933;}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_189));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_189));}}
  whileStmtLabel_0: ;
  result_61 = i_47;
  return result_61;}
NI64 parseStmt_1_parq39nt2(Parser_0_parq39nt2* ps_97, Builder_0_nifjp9lau1* b_76, NI64 startIdx_5, NI32 pl_71, NI32 pc_71, NI64 hiLimit_3){
  NI64 result_62;
  Token_0_tok9e79hf X60Qtmp_190 = tok_0_parq39nt2((&(*ps_97)), startIdx_5);
  enterDepth_0_parq39nt2(ps_97, X60Qtmp_190.line_0);
  NI64 X60Qx_934 = parseStmtImpl_0_parq39nt2(ps_97, b_76, startIdx_5, pl_71, pc_71, hiLimit_3);
  result_62 = X60Qx_934;
  dec_1_I2mwrey1_envto7w6l1((&(*ps_97).depth_0));
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_190));
  return result_62;
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_190));
  return result_62;}
void parseModule_0_parq39nt2(Parser_0_parq39nt2* ps_98, Builder_0_nifjp9lau1* b_77){
  addRaw_0_nifjp9lau1(b_77, (string_0_sysvq0asl){
    .bytes_0 = 3977354023709583614ull, .more_0 = (&strlit_0_I12712967915968306358_parq39nt2)}
  );
  addRaw_0_nifjp9lau1(b_77, (string_0_sysvq0asl){
    .bytes_0 = 8026661817934555390ull, .more_0 = (&strlit_0_I2246750106930142149_nifjp9lau1)}
  );
  addStrLit_0_nifjp9lau1(b_77, (string_0_sysvq0asl){
    .bytes_0 = 8318818597089141246ull, .more_0 = (&strlit_0_I1979059236716115474_parq39nt2)}
  );
  addRaw_0_nifjp9lau1(b_77, (string_0_sysvq0asl){
    .bytes_0 = 665858ull, .more_0 = NIM_NIL}
  );
  addRaw_0_nifjp9lau1(b_77, (string_0_sysvq0asl){
    .bytes_0 = 7308323400595679486ull, .more_0 = (&strlit_0_I15962761803738331083_nifjp9lau1)}
  );
  addStrLit_0_nifjp9lau1(b_77, (string_0_sysvq0asl){
    .bytes_0 = 8241992133476183806ull, .more_0 = (&strlit_0_I15261117590630161161_parq39nt2)}
  );
  addRaw_0_nifjp9lau1(b_77, (string_0_sysvq0asl){
    .bytes_0 = 665858ull, .more_0 = NIM_NIL}
  );
  Token_0_tok9e79hf first_7 = tok_0_parq39nt2((&(*ps_98)), IL64(0));
  NI32 X60Qx_54;
  if (first_7.kind_0 == IL64(0)){
    X60Qx_54 = ((NI32)IL64(1));}
  else {
    X60Qx_54 = first_7.line_0;}
  NI32 sl_0 = X60Qx_54;
  NI32 X60Qx_55;
  if (first_7.kind_0 == IL64(0)){
    X60Qx_55 = ((NI32)IL64(0));}
  else {
    X60Qx_55 = first_7.col_0;}
  NI32 sc_0 = X60Qx_55;
  addTree_0_nifjp9lau1(b_77, (string_0_sysvq0asl){
    .bytes_0 = 126943889748741ull, .more_0 = NIM_NIL}
  );
  emitInfo_0_parq39nt2((&(*ps_98)), b_77, sl_0, sc_0, ((NI32)IL64(0)), ((NI32)IL64(0)), NIM_TRUE);
  NI64 i_48 = IL64(0);
  {
    while (NIM_TRUE){
      Token_0_tok9e79hf X60Qtmp_191 = tok_0_parq39nt2((&(*ps_98)), i_48);
      if ((!(X60Qtmp_191.kind_0 == IL64(0)))){
        Token_0_tok9e79hf t_30 = tok_0_parq39nt2((&(*ps_98)), i_48);
        NB8 X60Qx_935;
        if (t_30.kind_0 == IL64(2)){
          NB8 X60Qx_936 = eqQ_20_sysvq0asl(t_30.s_0, (string_0_sysvq0asl){
            .bytes_0 = 435678704644ull, .more_0 = NIM_NIL}
          );
          X60Qx_935 = X60Qx_936;}
        else {
          X60Qx_935 = NIM_FALSE;}
        if (X60Qx_935){
          NI64 X60Qx_937 = parseTypeSection_1_parq39nt2(ps_98, b_77, i_48, sl_0, sc_0);
          i_48 = X60Qx_937;}
        else {
          NI64 X60Qx_938 = parseStmt_1_parq39nt2(ps_98, b_77, i_48, sl_0, sc_0, IL64(-1));
          i_48 = X60Qx_938;}
        NI64 X60Qx_939 = skipTrailingDoc_1_parq39nt2((&(*ps_98)), i_48, IL64(0));
        i_48 = X60Qx_939;
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&t_30));}
      else {
        eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_191));
        break;}
      eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&X60Qtmp_191));}}
  whileStmtLabel_0: ;
  endTree_0_nifjp9lau1(b_77);
  eQdestroyQ_SX54oken0tok9e79hf_0_tok9e79hf((&first_7));}
static inline NI64 len_3_I0v1j8d_parq39nt2(seq_0_Ift2sne_lex3r1urc1 s_21){
  NI64 result_67;
  result_67 = s_21.len_0;
  return result_67;}
static inline NI32* getQ_7_Ir8kccm_parq39nt2(seq_0_Ift2sne_lex3r1urc1 s_22, NI64 i_52){
  NB8 X60Qx_942;
  if (i_52 < s_22.len_0){
    X60Qx_942 = (IL64(0) <= i_52);}
  else {
    X60Qx_942 = NIM_FALSE;}
  if ((!X60Qx_942)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14532204288076119502_aif7a4qfr)}
    );}
  NI32* result_68;
  result_68 = (&s_22.data_0[i_52]);
  return result_68;}
static inline openArray_0_Ig73pnk_osalirkw71 toOpenArray_0_Ipj8xjx1_parq39nt2(X60Qt_0_IAarraySstring0sysvq0aslS14_parq39nt2* x_6){
  openArray_0_Ig73pnk_osalirkw71 result_69;
  openArray_0_Ig73pnk_osalirkw71 X60Qx_56;
  if (((NI64)(((NI64)(((NI64)((NI64)IL64(13))) - ((NI64)((NI64)IL64(0))))) + IL64(1))) == IL64(0)){
    X60Qx_56 = (openArray_0_Ig73pnk_osalirkw71){
      .a_0 = NIM_NIL, .len_0 = IL64(0)}
    ;}
  else {
    X60Qx_56 = (openArray_0_Ig73pnk_osalirkw71){
      .a_0 = ((string_0_sysvq0asl*)(&(*x_6))), .len_0 = ((NI64)(((NI64)(((NI64)((NI64)IL64(13))) - ((NI64)((NI64)IL64(0))))) + IL64(1)))}
    ;}
  result_69 = X60Qx_56;
  return result_69;}
static inline void add_0_I8fahwb_parq39nt2(seq_0_Iotb7mc_mat7cnfv21* s_23, NI64 elem_3){
  NI64 L_0 = (*s_23).len_0;
  NI64 X60Qx_945 = capInBytes_0_Ilkynur1_mat7cnfv21((*s_23));
  if (X60Qx_945 < ((NI64)(((NI64)(L_0 * sizeof(NI64))) + sizeof(NI64)))){
    NB8 X60Qx_946 = resize_0_Itn1ieo1_parq39nt2(s_23, IL64(1));
    if ((!X60Qx_946)){
      return;}}
  inc_1_Irn1g7r1_aif7a4qfr((&(*s_23).len_0));
  (*s_23).data_0[L_0] = elem_3;}
static inline NI64 len_3_I12oavy1_parq39nt2(seq_0_Iotb7mc_mat7cnfv21 s_25){
  NI64 result_71;
  result_71 = s_25.len_0;
  return result_71;}
static inline NI64* getQ_7_Ite3z0o_parq39nt2(seq_0_Iotb7mc_mat7cnfv21 s_26, NI64 i_54){
  NB8 X60Qx_947;
  if (i_54 < s_26.len_0){
    X60Qx_947 = (IL64(0) <= i_54);}
  else {
    X60Qx_947 = NIM_FALSE;}
  if ((!X60Qx_947)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14532204288076119502_aif7a4qfr)}
    );}
  NI64* result_72;
  result_72 = (&s_26.data_0[i_54]);
  return result_72;}
static inline openArray_0_Iu1stc01_parq39nt2 toOpenArray_1_I6ofx191_parq39nt2(seq_0_Iyai4gn_lex3r1urc1 s_29){
  openArray_0_Iu1stc01_parq39nt2 result_74;
  Token_0_tok9e79hf* X60Qx_952 = rawData_0_Ilu0q8c1_parq39nt2(s_29);
  result_74 = (openArray_0_Iu1stc01_parq39nt2){
    .a_0 = X60Qx_952, .len_0 = s_29.len_0}
  ;
  return result_74;}
static inline seq_0_Iflf8jf1_parq39nt2 newSeqUninit_0_I5mozxi1_parq39nt2(NI64 size_7){
  seq_0_Iflf8jf1_parq39nt2 result_75;
  if (size_7 == IL64(0)){
    result_75 = (seq_0_Iflf8jf1_parq39nt2){
      .len_0 = size_7, .data_0 = NIM_NIL}
    ;}
  else {
    NI64 memSize_2 = memSizeInBytes_0_Ih4q01h_parq39nt2(size_7);
    void* X60Qx_953 = alloc_0_sysvq0asl(memSize_2);
    result_75 = (seq_0_Iflf8jf1_parq39nt2){
      .len_0 = size_7, .data_0 = ((NB8*)X60Qx_953)}
    ;
    if ((!(result_75.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_954 = (string_0_sysvq0asl){
        .bytes_0 = 8439857260806892798ull, .more_0 = (&strlit_0_I15750996627617194403_aif7a4qfr)}
      ;}
    else {
      result_75.len_0 = IL64(0);
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_75;}
static inline void add_0_Irnc3p1_parq39nt2(seq_0_Iflf8jf1_parq39nt2* s_31, NB8 elem_5){
  NI64 L_2 = (*s_31).len_0;
  NI64 X60Qx_955 = capInBytes_0_In1m6ni_parq39nt2((*s_31));
  if (X60Qx_955 < ((NI64)(((NI64)(L_2 * sizeof(NB8))) + sizeof(NB8)))){
    NB8 X60Qx_956 = resize_0_I2yw78g1_parq39nt2(s_31, IL64(1));
    if ((!X60Qx_956)){
      return;}}
  inc_1_Irn1g7r1_aif7a4qfr((&(*s_31).len_0));
  (*s_31).data_0[L_2] = elem_5;}
static inline NB8* getQ_7_Iul1no9_parq39nt2(seq_0_Iflf8jf1_parq39nt2 s_33, NI64 i_56){
  NB8 X60Qx_957;
  if (i_56 < s_33.len_0){
    X60Qx_957 = (IL64(0) <= i_56);}
  else {
    X60Qx_957 = NIM_FALSE;}
  if ((!X60Qx_957)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14532204288076119502_aif7a4qfr)}
    );}
  NB8* result_76;
  result_76 = (&s_33.data_0[i_56]);
  return result_76;}
NB8 resize_0_Itn1ieo1_parq39nt2(seq_0_Iotb7mc_mat7cnfv21* dest_3, NI64 addedElements_3){
  NB8 result_81;
  NI64 X60Qx_960 = capInBytes_0_Ilkynur1_mat7cnfv21((*dest_3));
  NI64 oldCap_0 = ((NI64)(X60Qx_960 / sizeof(NI64)));
  NI64 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_3);
  NI64 memSize_3 = memSizeInBytes_0_Iqj0wsf_mat7cnfv21(newCap_0);
  void* X60Qx_961 = realloc_0_sysvq0asl(((void*)((void*)(*dest_3).data_0)), memSize_3);
  (*dest_3).data_0 = ((NI64*)X60Qx_961);
  if ((*dest_3).data_0 == NIM_NIL){
    (*dest_3).len_0 = IL64(0);
    oomHandler_0_sysvq0asl(memSize_3);
    result_81 = NIM_FALSE;}
  else {
    result_81 = NIM_TRUE;}
  return result_81;}
static inline Token_0_tok9e79hf* rawData_0_Ilu0q8c1_parq39nt2(seq_0_Iyai4gn_lex3r1urc1 s_36){
  Token_0_tok9e79hf* result_85;
  result_85 = s_36.data_0;
  return result_85;}
static inline NI64 len_6_Inwgz45_parq39nt2(openArray_0_Iu1stc01_parq39nt2 a_9){
  NI64 result_86;
  result_86 = a_9.len_0;
  return result_86;}
static inline Token_0_tok9e79hf* getQ_10_Iplfojn1_parq39nt2(openArray_0_Iu1stc01_parq39nt2 x_11, NI64 idx_6){
  NB8 X60Qx_965;
  if (IL64(0) <= idx_6){
    X60Qx_965 = (idx_6 < x_11.len_0);}
  else {
    X60Qx_965 = NIM_FALSE;}
  if ((!X60Qx_965)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14694606176902936784_has9tn57v)}
    );}
  Token_0_tok9e79hf* result_87;
  result_87 = (&x_11.a_0[idx_6]);
  return result_87;}
static inline NI64 memSizeInBytes_0_Ih4q01h_parq39nt2(NI64 size_11){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI64 result_88;
  NI64 X60QconstRefTemp_0;
  if (__builtin_smulll_overflow(size_11, sizeof(NB8), (long long int*)(&X60QconstRefTemp_0))){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_88 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_88 = ((NI64)IL64(9223372036854775807));}
  return result_88;}
static inline NI64 capInBytes_0_In1m6ni_parq39nt2(seq_0_Iflf8jf1_parq39nt2 s_37){
  NI64 result_89;
  NI64 X60Qx_59;
  if ((!(s_37.data_0 == NIM_NIL))){
    NI64 X60Qx_966 = allocatedSize_0_sysvq0asl(((void*)((void*)s_37.data_0)));
    X60Qx_59 = X60Qx_966;}
  else {
    X60Qx_59 = IL64(0);}
  result_89 = X60Qx_59;
  return result_89;}
NB8 resize_0_I2yw78g1_parq39nt2(seq_0_Iflf8jf1_parq39nt2* dest_5, NI64 addedElements_5){
  NB8 result_90;
  NI64 X60Qx_967 = capInBytes_0_In1m6ni_parq39nt2((*dest_5));
  NI64 oldCap_2 = ((NI64)(X60Qx_967 / sizeof(NB8)));
  NI64 newCap_2 = recalcCap_0_sysvq0asl(oldCap_2, addedElements_5);
  NI64 memSize_5 = memSizeInBytes_0_Ih4q01h_parq39nt2(newCap_2);
  void* X60Qx_968 = realloc_0_sysvq0asl(((void*)((void*)(*dest_5).data_0)), memSize_5);
  (*dest_5).data_0 = ((NB8*)X60Qx_968);
  if ((*dest_5).data_0 == NIM_NIL){
    (*dest_5).len_0 = IL64(0);
    oomHandler_0_sysvq0asl(memSize_5);
    result_90 = NIM_FALSE;}
  else {
    result_90 = NIM_TRUE;}
  return result_90;}
void eQdestroy_1_I7a20g9_parq39nt2(seq_0_Iflf8jf1_parq39nt2 s_52){
  if ((!(s_52.data_0 == NIM_NIL))){
    NI64 i_65 = IL64(0);
    {
      while (i_65 < s_52.len_0){
        inc_1_Irn1g7r1_aif7a4qfr((&i_65));}}
    whileStmtLabel_0: ;
    dealloc_0_sysvq0asl(((void*)((void*)s_52.data_0)));}}
void eQdestroyQ_SX50arser0parq39nt2_0_parq39nt2(Parser_0_parq39nt2* dest_0){
  nimStrDestroy((*dest_0).file_0);
  eQdestroy_1_Ie8xo6a1_lex3r1urc1((*dest_0).toks_0);}
void eQwasmovedQ_SX50arser0parq39nt2_0_parq39nt2(Parser_0_parq39nt2* dest_0){
  eQwasMoved_1_I4bu01z_lex3r1urc1((&(*dest_0).toks_0));
  nimStrWasMoved((&(*dest_0).file_0));}
void X60Qini_0_parq39nt2(void){
  if (X60QiniGuard_0_parq39nt2){
    return;}
  X60QiniGuard_0_parq39nt2 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_tok9e79hf();
  X60Qini_0_nifjp9lau1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_syn1lfpjv();}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40){
  string_0_sysvq0asl result_66;
  NI64 X60Qx_83 = ssLenOf_0_sysvq0asl(s_40.bytes_0);
  if (X60Qx_83 == ((NI64)IL64(255))){
    arcInc_0_sysvq0asl((&(*s_40.more_0).rc_0));}
  result_66 = (string_0_sysvq0asl){
    .bytes_0 = s_40.bytes_0, .more_0 = s_40.more_0}
  ;
  return result_66;}
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1){
  (*x_1) = ((NI64)((*x_1) + ((NI64)IL64(1))));}
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32){
  NI64 result_60;
  result_60 = ((NI64)(*((NU8*)(&s_32.bytes_0))));
  if (((NI64)IL64(14)) < result_60){
    result_60 = (*s_32.more_0).fullLen_0;}
  return result_60;}
static inline void nimStrDestroy(string_0_sysvq0asl s_39){
  if (((NI64)(*((NU8*)(&s_39.bytes_0)))) == ((NI64)IL64(255))){
    NB8 X60Qx_80 = arcDec_0_sysvq0asl((&(*s_39.more_0).rc_0));
    if (X60Qx_80){
      dealloc_0_sysvq0asl(((void*)s_39.more_0));}}}
static inline NI64 len_3_Iefkljt1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_23){
  NI64 result_33;
  result_33 = s_23.len_0;
  return result_33;}
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
static inline void plusQeQ_0_Ihg6mz11_mat7cnfv21(NI64* x_147, NI64 y_41){
  (*x_147) = ((NI64)((*x_147) + y_41));}
static inline NI64 len_3_Ixq6taz_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_3){
  NI64 result_1;
  result_1 = s_3.len_0;
  return result_1;}
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_4, NI64 i_2){
  NB8 X60Qx_26;
  if (i_2 < s_4.len_0){
    X60Qx_26 = (IL64(0) <= i_2);}
  else {
    X60Qx_26 = NIM_FALSE;}
  if ((!X60Qx_26)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14532204288076119502_aif7a4qfr)}
    );}
  string_0_sysvq0asl* result_2;
  result_2 = (&s_4.data_0[i_2]);
  return result_2;}
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
static inline void dec_1_I2mwrey1_envto7w6l1(NI64* x_8){
  (*x_8) = ((NI64)((*x_8) - ((NI64)IL64(1))));}
static inline void eQwasMoved_1_Ia0kll01_mat7cnfv21(seq_0_Iotb7mc_mat7cnfv21* s_5){
  (*s_5).len_0 = IL64(0);
  (*s_5).data_0 = NIM_NIL;}
static inline seq_0_Iotb7mc_mat7cnfv21 newSeqUninit_0_I7whkjh1_mat7cnfv21(NI64 size_4){
  seq_0_Iotb7mc_mat7cnfv21 result_81;
  if (size_4 == IL64(0)){
    result_81 = (seq_0_Iotb7mc_mat7cnfv21){
      .len_0 = size_4, .data_0 = NIM_NIL}
    ;}
  else {
    NI64 memSize_2 = memSizeInBytes_0_Iqj0wsf_mat7cnfv21(size_4);
    void* X60Qx_73 = alloc_0_sysvq0asl(memSize_2);
    result_81 = (seq_0_Iotb7mc_mat7cnfv21){
      .len_0 = size_4, .data_0 = ((NI64*)X60Qx_73)}
    ;
    if ((!(result_81.data_0 == NIM_NIL))){
      string_0_sysvq0asl X60Qx_74 = (string_0_sysvq0asl){
        .bytes_0 = 8439857260806892798ull, .more_0 = (&strlit_0_I15750996627617194403_aif7a4qfr)}
      ;}
    else {
      result_81.len_0 = IL64(0);
      oomHandler_0_sysvq0asl(memSize_2);}}
  return result_81;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38){
  (*s_38).bytes_0 = ((NU64)IL64(0));}
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
static inline NI64 capInBytes_0_Ilkynur1_mat7cnfv21(seq_0_Iotb7mc_mat7cnfv21 s_10){
  NI64 result_82;
  NI64 X60Qx_1;
  if ((!(s_10.data_0 == NIM_NIL))){
    NI64 X60Qx_75 = allocatedSize_0_sysvq0asl(((void*)((void*)s_10.data_0)));
    X60Qx_1 = X60Qx_75;}
  else {
    X60Qx_1 = IL64(0);}
  result_82 = X60Qx_1;
  return result_82;}
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
static inline NI64 memSizeInBytes_0_Iqj0wsf_mat7cnfv21(NI64 size_5){
  NB8 LENGC_OVF_ = NIM_FALSE;
  NI64 result_83;
  NI64 X60QconstRefTemp_0;
  if (__builtin_smulll_overflow(size_5, sizeof(NI64), (long long int*)(&X60QconstRefTemp_0))){
    LENGC_OVF_ = LENGC_OVF_ || NIM_TRUE;}
  result_83 = X60QconstRefTemp_0;
  if (LENGC_OVF_){
    result_83 = ((NI64)IL64(9223372036854775807));}
  return result_83;}
static inline void eQwasMoved_1_I4bu01z_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1* s_42){
  (*s_42).len_0 = IL64(0);
  (*s_42).data_0 = NIM_NIL;}
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
static inline NI64 max_3_sysvq0asl(NI64 x_212, NI64 y_169){
  NI64 result_13;
  NI64 X60Qx_9;
  if (y_169 <= x_212){
    X60Qx_9 = x_212;}
  else {
    X60Qx_9 = y_169;}
  result_13 = X60Qx_9;
  return result_13;}
