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
NIM_THREADVAR NB8 LENGC_ERR_;
#include <stdio.h>
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct Token_0_tok9e79hf Token_0_tok9e79hf;
typedef struct seq_0_Ixdx2fh1_aif7a4qfr{
  NI64 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aif7a4qfr;
typedef struct HSlice_0_I6e0t4q1_aif7a4qfr{
  NI64 a_0;
  NI64 b_0;}
HSlice_0_I6e0t4q1_aif7a4qfr;
typedef NU8 ErrorCode_0_sysvq0asl;

#define Success_0_sysvq0asl ((NU8)IL64(0))
#define OverflowError_0_sysvq0asl ((NU8)IL64(1))
#define Failure_0_sysvq0asl ((NU8)IL64(2))
#define BugError_0_sysvq0asl ((NU8)IL64(3))
#define IndexError_0_sysvq0asl ((NU8)IL64(4))
#define RangeError_0_sysvq0asl ((NU8)IL64(5))
#define OverlapError_0_sysvq0asl ((NU8)IL64(6))
#define SyntaxError_0_sysvq0asl ((NU8)IL64(7))
#define OutOfMemError_0_sysvq0asl ((NU8)IL64(8))
#define DiskFullError_0_sysvq0asl ((NU8)IL64(9))
#define StackOverflow_0_sysvq0asl ((NU8)IL64(10))
#define IOError_0_sysvq0asl ((NU8)IL64(11))
#define ValueError_0_sysvq0asl ((NU8)IL64(12))
#define KeyError_0_sysvq0asl ((NU8)IL64(13))
#define EndOfStreamError_0_sysvq0asl ((NU8)IL64(14))
#define SkipError_0_sysvq0asl ((NU8)IL64(15))
#define FullError_0_sysvq0asl ((NU8)IL64(16))
#define EmptyError_0_sysvq0asl ((NU8)IL64(17))
#define BusyError_0_sysvq0asl ((NU8)IL64(18))
#define DeadResource_0_sysvq0asl ((NU8)IL64(19))
#define ResourceExhaustedError_0_sysvq0asl ((NU8)IL64(20))
#define DescriptorExhaustedError_0_sysvq0asl ((NU8)IL64(21))
#define PermissionDenied_0_sysvq0asl ((NU8)IL64(22))
#define RetryError_0_sysvq0asl ((NU8)IL64(23))
#define TimeoutError_0_sysvq0asl ((NU8)IL64(24))
#define InterruptedError_0_sysvq0asl ((NU8)IL64(25))
#define DeadlockError_0_sysvq0asl ((NU8)IL64(26))
#define LockedError_0_sysvq0asl ((NU8)IL64(27))
#define FormatMismatch_0_sysvq0asl ((NU8)IL64(28))
#define AlreadyConnected_0_sysvq0asl ((NU8)IL64(29))
#define AddressNotAvailable_0_sysvq0asl ((NU8)IL64(30))
#define AddressFamilyUnsupported_0_sysvq0asl ((NU8)IL64(31))
#define BadOperation_0_sysvq0asl ((NU8)IL64(32))
#define AbortedOperation_0_sysvq0asl ((NU8)IL64(33))
#define UnimplementedOperation_0_sysvq0asl ((NU8)IL64(34))
#define AlreadyInProgress_0_sysvq0asl ((NU8)IL64(35))
#define NameTooLong_0_sysvq0asl ((NU8)IL64(36))
#define NameExists_0_sysvq0asl ((NU8)IL64(37))
#define NameNotFound_0_sysvq0asl ((NU8)IL64(38))
#define ContentTooLong_0_sysvq0asl ((NU8)IL64(39))
#define BadDescriptor_0_sysvq0asl ((NU8)IL64(40))
#define BadExecutable_0_sysvq0asl ((NU8)IL64(41))
#define BadLink_0_sysvq0asl ((NU8)IL64(42))
#define BadProtocol_0_sysvq0asl ((NU8)IL64(43))
#define ProtocolError_0_sysvq0asl ((NU8)IL64(44))
#define ReadonlyProtection_0_sysvq0asl ((NU8)IL64(45))
#define SegFault_0_sysvq0asl ((NU8)IL64(46))
#define DiskCorruption_0_sysvq0asl ((NU8)IL64(47))
#define Disconnected_0_sysvq0asl ((NU8)IL64(48))
#define RefusedConnection_0_sysvq0asl ((NU8)IL64(49))
#define UnreachableHost_0_sysvq0asl ((NU8)IL64(50))
#define UnrecoverableState_0_sysvq0asl ((NU8)IL64(51))
#define AuthenticationRequired_0_sysvq0asl ((NU8)IL64(52))
#define RedirectError_0_sysvq0asl ((NU8)IL64(53))
#define Reserved1_0_sysvq0asl ((NU8)IL64(54))
#define Reserved2_0_sysvq0asl ((NU8)IL64(55))
#define Reserved3_0_sysvq0asl ((NU8)IL64(56))
#define Reserved4_0_sysvq0asl ((NU8)IL64(57))
#define Reserved5_0_sysvq0asl ((NU8)IL64(58))
#define Reserved6_0_sysvq0asl ((NU8)IL64(59))
#define Reserved7_0_sysvq0asl ((NU8)IL64(60))
#define Reserved8_0_sysvq0asl ((NU8)IL64(61))
#define Reserved9_0_sysvq0asl ((NU8)IL64(62))
typedef struct string_0_sysvq0asl{
  NU64 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr{
  ErrorCode_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr;
typedef struct LongString_0_sysvq0asl{
  NI64 fullLen_0;
  NI64 rc_0;
  NI64 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct seq_0_Iyai4gn_lex3r1urc1{
  NI64 len_0;
  Token_0_tok9e79hf* data_0;}
seq_0_Iyai4gn_lex3r1urc1;
typedef struct Parser_0_parq39nt2{
  seq_0_Iyai4gn_lex3r1urc1 toks_0;
  string_0_sysvq0asl file_0;
  NB8 curly_0;
  NI64 depth_0;
  NI64 maxDepth_0;}
Parser_0_parq39nt2;
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
static inline seq_0_Ixdx2fh1_aif7a4qfr newSeqUninit_0_Im3cqd9_aif7a4qfr(NI64 size_1);
static inline NI64 len_3_Ixq6taz_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_3);
static inline string_0_sysvq0asl* getQ_7_Ir6d0tw_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_4, NI64 i_2);
static inline void add_0_Ig6072n_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_5, string_0_sysvq0asl elem_1);
static inline HSlice_0_I6e0t4q1_aif7a4qfr ___1_If4noih_aif7a4qfr(NI64 a_3, NI64 b_4);
static inline NI64 memSizeInBytes_0_I7me00i_aif7a4qfr(NI64 size_3);
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1);
static inline NI64 capInBytes_0_Ih2sbn01_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_7);
NB8 resize_0_I4buliy_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* dest_1, NI64 addedElements_1);
void eQdestroy_1_Ivioh0a_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_10);
void eQdestroyQ_SX42uilder0nifjp9lau1_0_aif7a4qfr(Builder_0_nifjp9lau1* dest_0);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr readFile_0_syn1lfpjv(string_0_sysvq0asl filename_4);
static inline void nimStrDestroy(string_0_sysvq0asl s_39);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40);
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32);
extern string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI64 len_3);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_48, string_0_sysvq0asl part_0);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern void quit_0_syn1lfpjv(NI64 value_0);
extern seq_0_Iyai4gn_lex3r1urc1 tokenize_3_lex3r1urc1(string_0_sysvq0asl src_4);
extern Parser_0_parq39nt2 initParser_0_parq39nt2(seq_0_Iyai4gn_lex3r1urc1 toks_0, string_0_sysvq0asl file_0, NB8 curly_0, NI64 maxDepth_0);
extern Builder_0_nifjp9lau1 open_0_nifjp9lau1(string_0_sysvq0asl filename_0, NB8 compact_0, FileWriteMode_0_vfsc9jn7 writeMode_0);
extern void parseModule_0_parq39nt2(Parser_0_parq39nt2* ps_98, Builder_0_nifjp9lau1* b_77);
extern void close_0_nifjp9lau1(Builder_0_nifjp9lau1* b_2);
extern void eQdestroyQ_SX50arser0parq39nt2_0_parq39nt2(Parser_0_parq39nt2* dest_0);
extern void eQdestroy_1_Ie8xo6a1_lex3r1urc1(seq_0_Iyai4gn_lex3r1urc1 s_41);
extern seq_0_Ixdx2fh1_aif7a4qfr commandLineParams_0_cmdqs323n1(void);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_14, string_0_sysvq0asl b_10);
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_75, HSlice_0_I6e0t4q1_aif7a4qfr x_336);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_18, string_0_sysvq0asl b_14);
extern void* alloc_0_sysvq0asl(NI64 size_10);
extern X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_68);
extern NI64 allocatedSize_0_sysvq0asl(void* p_11);
static inline NI64 recalcCap_0_sysvq0asl(NI64 oldCap_0, NI64 addedElements_0);
extern void* realloc_0_sysvq0asl(void* p_9, NI64 size_12);
extern void dealloc_0_sysvq0asl(void* p_10);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_nifjp9lau1(void);
extern void X60Qini_0_vfsc9jn7(void);
extern void X60Qini_0_tok9e79hf(void);
extern void X60Qini_0_lex3r1urc1(void);
extern void X60Qini_0_parq39nt2(void);
extern void nimFlushStdStreams(void);
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1);
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0);
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0);
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_13, string_0_sysvq0asl b_9);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38);
extern string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_54, NI64 first_0, NI64 last_0);
static inline NI64 max_3_sysvq0asl(NI64 x_212, NI64 y_169);
LongString_0_sysvq0asl const strlit_0_I14087893985203228080_aif7a4qfr = {
  .fullLen_0 = IL64(18), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "cannot read file: "}
;
LongString_0_sysvq0asl const strlit_0_I11115568359365557036_aif7a4qfr = {
  .fullLen_0 = IL64(52), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "aifparser \342\200\224 Nim source -> AIF (nifler-compatible)\012"}
;
LongString_0_sysvq0asl const strlit_0_I8347300752998099112_aif7a4qfr = {
  .fullLen_0 = IL64(50), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "usage: aifparser [--curly] p <in.nim> [out.p.aif]\012"}
;
LongString_0_sysvq0asl const strlit_0_I905830756158398464_aif7a4qfr = {
  .fullLen_0 = IL64(61), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "  --curly   experimental: also accept `{ \342\200\246 }` block bodies\012"}
;
LongString_0_sysvq0asl const strlit_0_I268139908787247502_aif7a4qfr = {
  .fullLen_0 = IL64(17), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "unknown command: "}
;
LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aif7a4qfr = {
  .fullLen_0 = IL64(19), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "leave uninitialized"}
;
LongString_0_sysvq0asl const strlit_0_I14532204288076119502_aif7a4qfr = {
  .fullLen_0 = IL64(86), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "../nimony/lib/std/system/seqimpl.nim(167, 41): i < s.len and 0 <= i [AssertionDefect]\012"}
;
NB8 X60QiniGuard_0_aif7a4qfr;
NI32 cmdCount;
NC8** cmdLine;
NC8** nimEnviron;
void parseToFile_0_aif7a4qfr(string_0_sysvq0asl inp_0, string_0_sysvq0asl outp_0, string_0_sysvq0asl fileField_0, NB8 curly_0){
  string_0_sysvq0asl src_0 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr X60QcanRaise_0 = readFile_0_syn1lfpjv(inp_0);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_0;}
  nimStrDestroy(src_0);
  string_0_sysvq0asl X60Qx_2 = nimStrDup(X60QcanRaise_0.fld_1);
  src_0 = X60Qx_2;
  if (NIM_FALSE){
    X60Qexlab_0: ;
    NI64 X60Qx_3 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2338616626601092094ull, .more_0 = (&strlit_0_I14087893985203228080_aif7a4qfr)}
    );
    NI64 X60Qx_4 = len_4_sysvq0asl(inp_0);
    NI64 X60Qx_5 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561ull, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_0 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_3 + X60Qx_4)) + X60Qx_5)));
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 2338616626601092094ull, .more_0 = (&strlit_0_I14087893985203228080_aif7a4qfr)}
    );
    add_2_sysvq0asl((&X60Qdesugar_0), inp_0);
    add_2_sysvq0asl((&X60Qdesugar_0), (string_0_sysvq0asl){
      .bytes_0 = 2561ull, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_0);
    quit_0_syn1lfpjv(IL64(1));
    nimStrDestroy(X60Qdesugar_0);}
  seq_0_Iyai4gn_lex3r1urc1 toks_0 = tokenize_3_lex3r1urc1(src_0);
  Parser_0_parq39nt2 ps_0 = initParser_0_parq39nt2(toks_0, fileField_0, curly_0, IL64(0));
  Builder_0_nifjp9lau1 b_0 = open_0_nifjp9lau1(outp_0, NIM_FALSE, IL64(0));
  parseModule_0_parq39nt2((&ps_0), (&b_0));
  close_0_nifjp9lau1((&b_0));
  eQdestroyQ_SX42uilder0nifjp9lau1_0_aif7a4qfr((&b_0));
  eQdestroyQ_SX50arser0parq39nt2_0_parq39nt2((&ps_0));
  eQdestroy_1_Ie8xo6a1_lex3r1urc1(toks_0);
  nimStrDestroy(src_0);}
void usage_0_aif7a4qfr(void){
  write_0_syn1lfpjv(stderr, (string_0_sysvq0asl){
    .bytes_0 = 8318818597089141246ull, .more_0 = (&strlit_0_I11115568359365557036_aif7a4qfr)}
  );
  write_0_syn1lfpjv(stderr, (string_0_sysvq0asl){
    .bytes_0 = 2322280052553905662ull, .more_0 = (&strlit_0_I8347300752998099112_aif7a4qfr)}
  );
  write_0_syn1lfpjv(stderr, (string_0_sysvq0asl){
    .bytes_0 = 8247607338280689918ull, .more_0 = (&strlit_0_I905830756158398464_aif7a4qfr)}
  );
  quit_0_syn1lfpjv(IL64(1));}
void main_0_aif7a4qfr(void){
  seq_0_Ixdx2fh1_aif7a4qfr params_0 = newSeqUninit_0_Im3cqd9_aif7a4qfr(IL64(0));
  NB8 curly_1 = NIM_FALSE;
  seq_0_Ixdx2fh1_aif7a4qfr cli_0 = commandLineParams_0_cmdqs323n1();
  {
    NI64 X60Qlf_0 = IL64(0);
    NI64 X60Qlf_1 = len_3_Ixq6taz_aif7a4qfr(cli_0);
    NI64 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 < X60Qlf_1){
        {
          string_0_sysvq0asl* X60Qx_6 = getQ_7_Ir6d0tw_aif7a4qfr(cli_0, X60Qlf_2);
          NB8 X60Qx_7 = eqQ_20_sysvq0asl((*X60Qx_6), (string_0_sysvq0asl){
            .bytes_0 = 8749494024574676231ull, .more_0 = NIM_NIL}
          );
          if (X60Qx_7){
            curly_1 = NIM_TRUE;}
          else {
            string_0_sysvq0asl* X60Qx_8 = getQ_7_Ir6d0tw_aif7a4qfr(cli_0, X60Qlf_2);
            string_0_sysvq0asl X60Qx_9 = nimStrDup((*X60Qx_8));
            add_0_Ig6072n_aif7a4qfr((&params_0), X60Qx_9);}}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NI64 X60Qx_10 = len_3_Ixq6taz_aif7a4qfr(params_0);
  if (X60Qx_10 < IL64(2)){
    usage_0_aif7a4qfr();}
  string_0_sysvq0asl* X60Qx_11 = getQ_7_Ir6d0tw_aif7a4qfr(params_0, IL64(0));
  string_0_sysvq0asl action_0 = nimStrDup((*X60Qx_11));
  NB8 X60Qx_12;
  NB8 X60Qx_13 = eqQ_20_sysvq0asl(action_0, (string_0_sysvq0asl){
    .bytes_0 = 28673ull, .more_0 = NIM_NIL}
  );
  if ((!X60Qx_13)){
    NB8 X60Qx_14 = eqQ_20_sysvq0asl(action_0, (string_0_sysvq0asl){
      .bytes_0 = 111546514632709ull, .more_0 = NIM_NIL}
    );
    X60Qx_12 = (!X60Qx_14);}
  else {
    X60Qx_12 = NIM_FALSE;}
  if (X60Qx_12){
    NI64 X60Qx_15 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 7959953386440127998ull, .more_0 = (&strlit_0_I268139908787247502_aif7a4qfr)}
    );
    NI64 X60Qx_16 = len_4_sysvq0asl(action_0);
    NI64 X60Qx_17 = len_4_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561ull, .more_0 = NIM_NIL}
    );
    string_0_sysvq0asl X60Qdesugar_1 = newStringOfCap_0_sysvq0asl(((NI)(((NI)(X60Qx_15 + X60Qx_16)) + X60Qx_17)));
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 7959953386440127998ull, .more_0 = (&strlit_0_I268139908787247502_aif7a4qfr)}
    );
    add_2_sysvq0asl((&X60Qdesugar_1), action_0);
    add_2_sysvq0asl((&X60Qdesugar_1), (string_0_sysvq0asl){
      .bytes_0 = 2561ull, .more_0 = NIM_NIL}
    );
    write_0_syn1lfpjv(stderr, X60Qdesugar_1);
    usage_0_aif7a4qfr();
    nimStrDestroy(X60Qdesugar_1);}
  string_0_sysvq0asl* X60Qx_18 = getQ_7_Ir6d0tw_aif7a4qfr(params_0, IL64(1));
  string_0_sysvq0asl inp_1 = nimStrDup((*X60Qx_18));
  string_0_sysvq0asl outp_1 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  if (IL64(3) <= params_0.len_0){
    nimStrDestroy(outp_1);
    string_0_sysvq0asl* X60Qx_19 = getQ_7_Ir6d0tw_aif7a4qfr(params_0, IL64(2));
    string_0_sysvq0asl X60Qx_20 = nimStrDup((*X60Qx_19));
    outp_1 = X60Qx_20;
    NI64 n_0 = len_4_sysvq0asl(outp_1);
    NB8 X60Qx_1;
    if (n_0 < IL64(4)){
      X60Qx_1 = NIM_TRUE;}
    else {
      HSlice_0_I6e0t4q1_aif7a4qfr X60Qx_21 = ___1_If4noih_aif7a4qfr(((NI64)(n_0 - IL64(4))), ((NI64)(n_0 - IL64(1))));
      string_0_sysvq0asl X60Qtmp_0 = getQ_14_sysvq0asl(outp_1, X60Qx_21);
      NB8 X60Qx_22 = eqQ_20_sysvq0asl(X60Qtmp_0, (string_0_sysvq0asl){
        .bytes_0 = 439855492612ull, .more_0 = NIM_NIL}
      );
      X60Qx_1 = (!X60Qx_22);
      nimStrDestroy(X60Qtmp_0);}
    if (X60Qx_1){
      string_0_sysvq0asl X60Qlhs_1 = ampQ_0_sysvq0asl(outp_1, (string_0_sysvq0asl){
        .bytes_0 = 439855492612ull, .more_0 = NIM_NIL}
      );
      nimStrDestroy(outp_1);
      outp_1 = X60Qlhs_1;}}
  else {
    nimStrDestroy(outp_1);
    string_0_sysvq0asl X60Qx_23 = ampQ_0_sysvq0asl(inp_1, (string_0_sysvq0asl){
      .bytes_0 = 28826313736334854ull, .more_0 = NIM_NIL}
    );
    outp_1 = X60Qx_23;}
  parseToFile_0_aif7a4qfr(inp_1, outp_1, inp_1, curly_1);
  nimStrDestroy(outp_1);
  nimStrDestroy(inp_1);
  nimStrDestroy(action_0);
  eQdestroy_1_Ivioh0a_aif7a4qfr(cli_0);
  eQdestroy_1_Ivioh0a_aif7a4qfr(params_0);}
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
static inline HSlice_0_I6e0t4q1_aif7a4qfr ___1_If4noih_aif7a4qfr(NI64 a_3, NI64 b_4){
  HSlice_0_I6e0t4q1_aif7a4qfr result_3;
  result_3 = (HSlice_0_I6e0t4q1_aif7a4qfr){
    .a_0 = a_3, .b_0 = b_4}
  ;
  return result_3;}
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
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1){
  (*x_1) = ((NI64)((*x_1) + ((NI64)IL64(1))));}
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
NB8 resize_0_I4buliy_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* dest_1, NI64 addedElements_1){
  NB8 result_6;
  NI64 X60Qx_30 = capInBytes_0_Ih2sbn01_aif7a4qfr((*dest_1));
  NI64 oldCap_0 = ((NI64)(X60Qx_30 / sizeof(string_0_sysvq0asl)));
  NI64 newCap_0 = recalcCap_0_sysvq0asl(oldCap_0, addedElements_1);
  NI64 memSize_1 = memSizeInBytes_0_I7me00i_aif7a4qfr(newCap_0);
  void* X60Qx_31 = realloc_0_sysvq0asl(((void*)((void*)(*dest_1).data_0)), memSize_1);
  (*dest_1).data_0 = ((string_0_sysvq0asl*)X60Qx_31);
  if ((*dest_1).data_0 == NIM_NIL){
    (*dest_1).len_0 = IL64(0);
    oomHandler_0_sysvq0asl(memSize_1);
    result_6 = NIM_FALSE;}
  else {
    result_6 = NIM_TRUE;}
  return result_6;}
void eQdestroy_1_Ivioh0a_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_10){
  if ((!(s_10.data_0 == NIM_NIL))){
    NI64 i_3 = IL64(0);
    {
      while (i_3 < s_10.len_0){
        nimStrDestroy(s_10.data_0[i_3]);
        inc_1_Irn1g7r1_aif7a4qfr((&i_3));}}
    whileStmtLabel_0: ;
    dealloc_0_sysvq0asl(((void*)((void*)s_10.data_0)));}}
static inline void eQwasMoved_1_I5vdnla_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_11){
  (*s_11).len_0 = IL64(0);
  (*s_11).data_0 = NIM_NIL;}
seq_0_Ixdx2fh1_aif7a4qfr eQdup_1_Imq0s4c_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr a_5){
  seq_0_Ixdx2fh1_aif7a4qfr result_7;
  seq_0_Ixdx2fh1_aif7a4qfr X60Qx_32 = newSeqUninit_0_Im3cqd9_aif7a4qfr(a_5.len_0);
  result_7 = X60Qx_32;
  NI64 i_4 = IL64(0);
  {
    while (i_4 < a_5.len_0){
      string_0_sysvq0asl X60Qx_33 = nimStrDup(a_5.data_0[i_4]);
      result_7.data_0[i_4] = X60Qx_33;
      inc_1_Irn1g7r1_aif7a4qfr((&i_4));}}
  whileStmtLabel_0: ;
  return result_7;}
void eQdestroyQ_SX42uilder0nifjp9lau1_0_aif7a4qfr(Builder_0_nifjp9lau1* dest_0){
  nimStrDestroy((*dest_0).filename_0);
  nimStrDestroy((*dest_0).buffer_0);}
void X60Qini_0_aif7a4qfr(void){
  if (X60QiniGuard_0_aif7a4qfr){
    return;}
  X60QiniGuard_0_aif7a4qfr = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_nifjp9lau1();
  X60Qini_0_vfsc9jn7();
  X60Qini_0_tok9e79hf();
  X60Qini_0_lex3r1urc1();
  X60Qini_0_parq39nt2();
  main_0_aif7a4qfr();}
NI32 main(NI32 X60Qargc_0_aif7a4qfr, char** X60Qargv_0_aif7a4qfr, char** X60Qenvp_0_aif7a4qfr){
  cmdCount = X60Qargc_0_aif7a4qfr;
  cmdLine = ((NC8**)X60Qargv_0_aif7a4qfr);
  nimEnviron = ((NC8**)X60Qenvp_0_aif7a4qfr);
  X60Qini_0_aif7a4qfr();
  nimFlushStdStreams();
  return IL64(0);}
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
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32){
  NI64 result_60;
  result_60 = ((NI64)(*((NU8*)(&s_32.bytes_0))));
  if (((NI64)IL64(14)) < result_60){
    result_60 = (*s_32.more_0).fullLen_0;}
  return result_60;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_14, string_0_sysvq0asl b_10){
  NB8 result_88;
  NB8 X60Qx_142 = equalStrings_0_sysvq0asl(a_14, b_10);
  result_88 = X60Qx_142;
  return result_88;}
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_75, HSlice_0_I6e0t4q1_aif7a4qfr x_336){
  string_0_sysvq0asl result_186;
  nimStrWasMoved((&result_186));
  nimStrDestroy(result_186);
  string_0_sysvq0asl X60Qx_296 = substr_0_sysvq0asl(s_75, x_336.a_0, x_336.b_0);
  result_186 = X60Qx_296;
  return result_186;}
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38){
  (*s_38).bytes_0 = ((NU64)IL64(0));}
static inline NI64 max_3_sysvq0asl(NI64 x_212, NI64 y_169){
  NI64 result_13;
  NI64 X60Qx_9;
  if (y_169 <= x_212){
    X60Qx_9 = x_212;}
  else {
    X60Qx_9 = y_169;}
  result_13 = X60Qx_9;
  return result_13;}
