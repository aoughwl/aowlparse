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
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dlfcn.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct Rtti_0_sysvq0asl Rtti_0_sysvq0asl;
typedef struct CoroutineBase_0_sysvq0asl CoroutineBase_0_sysvq0asl;
typedef struct Continuation_0_sysvq0asl Continuation_0_sysvq0asl;
typedef struct Exception_0_sysvq0asl Exception_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl{
  NI64 fullLen_0;
  NI64 rc_0;
  NI64 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl{
  NU64 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct RootObj_0_sysvq0asl{
  Rtti_0_sysvq0asl* vt_00;}
RootObj_0_sysvq0asl;
typedef struct mi_stat_count_t{
  NI64 total_0;
  NI64 peak_0;
  NI64 current_0;}
mi_stat_count_t;
typedef struct mi_stats_t{
  int version_0;
  mi_stat_count_t pages_0;
  mi_stat_count_t reserved_0;
  mi_stat_count_t committed_0;
  mi_stat_count_t reset_0;
  mi_stat_count_t purged_0;
  mi_stat_count_t pageQ_committed_0;
  mi_stat_count_t pagesQ_abandoned_0;
  mi_stat_count_t threads_0;
  mi_stat_count_t mallocQ_normal_0;
  mi_stat_count_t mallocQ_huge_0;
  mi_stat_count_t mallocQ_requested_0;}
mi_stats_t;
typedef struct Rtti_0_sysvq0asl{
  NI64 dl_0;
  NU32* dy_0;
  void* mt_0[];}
Rtti_0_sysvq0asl;
typedef struct Single_0_sysvq0asl{
  NU32 bits_0;}
Single_0_sysvq0asl;
typedef struct FloatingDecimal32_0_sysvq0asl{
  NU32 digits_0;
  NI64 exponent_0;}
FloatingDecimal32_0_sysvq0asl;
typedef struct Double_0_sysvq0asl{
  NU64 bits_0;}
Double_0_sysvq0asl;
typedef struct uint64x2_0_sysvq0asl{
  NU64 hi_0;
  NU64 lo_0;}
uint64x2_0_sysvq0asl;
typedef struct MulCmp_0_sysvq0asl{
  NU64 mul_0;
  NU64 cmp_0;}
MulCmp_0_sysvq0asl;
typedef struct FloatingDecimal64_0_sysvq0asl{
  NU64 significand_0;
  NI64 exponent_0;}
FloatingDecimal64_0_sysvq0asl;
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
typedef N_NIMCALL_PTR(Continuation_0_sysvq0asl,  X60Qt_0_IAptrSX43oroutineX42ase0sysvq0aslZSX43ontinuation0R22AnimcallZAfalseZAR61_sysvq0asl)(CoroutineBase_0_sysvq0asl*);
typedef struct Continuation_0_sysvq0asl{
  X60Qt_0_IAptrSX43oroutineX42ase0sysvq0aslZSX43ontinuation0R22AnimcallZAfalseZAR61_sysvq0asl fn_0;
  CoroutineBase_0_sysvq0asl* env_0;}
Continuation_0_sysvq0asl;
typedef struct CoroutineBase_0_sysvq0asl{
  RootObj_0_sysvq0asl Q;
  Continuation_0_sysvq0asl caller_0;
  CoroutineBase_0_sysvq0asl* callee_0;}
CoroutineBase_0_sysvq0asl;
typedef NU8 TypeOfMode_0_sysvq0asl;

#define typeOfProc_0_sysvq0asl ((NU8)IL64(0))
#define typeOfIter_0_sysvq0asl ((NU8)IL64(1))
typedef struct Exception_0_sysvq0asl{
  RootObj_0_sysvq0asl Q;
  string_0_sysvq0asl msg_0;}
Exception_0_sysvq0asl;
typedef struct openArray_0_Ijk0jkw1_has9tn57v{
  NC8* a_0;
  NI64 len_0;}
openArray_0_Ijk0jkw1_has9tn57v;
typedef struct HSlice_0_I6e0t4q1_aif7a4qfr{
  NI64 a_0;
  NI64 b_0;}
HSlice_0_I6e0t4q1_aif7a4qfr;
typedef struct HSlice_0_Ii5kgy01_sysvq0asl{
  NI64 a_0;
  NI64 b_0;}
HSlice_0_Ii5kgy01_sysvq0asl;
typedef struct X60Qt_0_IArefSX52ootX4fbj0sysvq0asl_sysvq0asl{
  NI r_00;
  RootObj_0_sysvq0asl d_00;}
X60Qt_0_IArefSX52ootX4fbj0sysvq0asl_sysvq0asl;
typedef struct X60Qt_0_IAarraySstring0sysvq0aslS10_sysvq0asl{
  string_0_sysvq0asl a[IL64(10)];}
X60Qt_0_IAarraySstring0sysvq0aslS10_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISEAnimcallZAfalseZAR11_sysvq0asl)(void);
typedef struct X60Qt_0_IAarrayAuS8ZS256_sysvq0asl{
  NU8 a[IL64(256)];}
X60Qt_0_IAarrayAuS8ZS256_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI64);
typedef struct X60Qt_0_IAarrayAiS8ZS100_sysvq0asl{
  NI8 a[IL64(100)];}
X60Qt_0_IAarrayAiS8ZS100_sysvq0asl;
typedef struct X60Qt_0_IAarrayAcS8ZS200_sysvq0asl{
  NC8 a[IL64(200)];}
X60Qt_0_IAarrayAcS8ZS200_sysvq0asl;
typedef struct X60Qt_0_IAarrayAuS64ZS77_sysvq0asl{
  NU64 a[IL64(77)];}
X60Qt_0_IAarrayAuS64ZS77_sysvq0asl;
typedef struct X60Qt_0_IAarraySuint64x20sysvq0aslS619_sysvq0asl{
  uint64x2_0_sysvq0asl a[IL64(619)];}
X60Qt_0_IAarraySuint64x20sysvq0aslS619_sysvq0asl;
typedef struct X60Qt_0_IAarraySX4dulX43mp0sysvq0aslS25_sysvq0asl{
  MulCmp_0_sysvq0asl a[IL64(25)];}
X60Qt_0_IAarraySX4dulX43mp0sysvq0aslS25_sysvq0asl;
typedef struct X60Qt_0_IAarrayAcS8ZS16_sysvq0asl{
  NC8 a[IL64(16)];}
X60Qt_0_IAarrayAcS8ZS16_sysvq0asl;
typedef struct X60Qt_0_IAarrayAcS8ZS65_sysvq0asl{
  NC8 a[IL64(65)];}
X60Qt_0_IAarrayAcS8ZS65_sysvq0asl;
typedef N_NIMCALL_PTR(Continuation_0_sysvq0asl,  X60Qt_0_ISX43ontinuation0sysvq0aslSR0AnimcallZAfalseZAR37_sysvq0asl)(Continuation_0_sysvq0asl);
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAptrSX43oroutineX42ase0sysvq0aslZSEAnimcallZAfalseZAR44_sysvq0asl)(CoroutineBase_0_sysvq0asl*);
typedef struct X60Qt_0_IArefSX45xception0sysvq0asl_sysvq0asl{
  NI r_00;
  Exception_0_sysvq0asl d_00;}
X60Qt_0_IArefSX45xception0sysvq0asl_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISX45xception0sysvq0aslSEAnimcallZAfalseZAR33_sysvq0asl)(Exception_0_sysvq0asl*);
N_CDECL(void*, mi_malloc)(size_t size_7);
N_CDECL(void*, mi_realloc)(void* pt_0, size_t size_9);
N_CDECL(void, mi_free)(void* p_7);
N_CDECL(size_t, mi_usable_size)(void* p_8);
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38);
static inline void nimStrDestroy(string_0_sysvq0asl s_39);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40);
void add_1_sysvq0asl(string_0_sysvq0asl* s_47, NC8 c_0);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_52, NI64 i_14);
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_53, NI64 i_15, NC8 c_1);
string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_54, NI64 first_0, NI64 last_0);
string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_18, string_0_sysvq0asl b_14);
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0);
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1);
static inline NB8 arcIsUnique_0_sysvq0asl(NI64* memLoc_2);
void panic_0_sysvq0asl(string_0_sysvq0asl s_68);
static inline NI64 nimIcheckB(NI64 i_19, NI64 b_19);
void raiseIndexError3_0_Ice8haj1_sysvq0asl(NI64 i_65, NI64 a_45, NI64 b_34);
void raiseIndexError3_0_Ils6gq61_sysvq0asl(NU64 i_66, NU64 a_46, NU64 b_35);
static inline void putQ_10_If2353w_sysvq0asl(openArray_0_Ijk0jkw1_has9tn57v x_358, NI64 i_67, NC8 elem_12);
static inline void dec_0_Idgnuqw1_sysvq0asl(NU64* x_362, NU64 y_210);
static inline void plusQeQ_0_Iar0t5x_sysvq0asl(NU64* x_364, NU64 y_212);
static inline void dec_1_Ifi4w3m1_sysvq0asl(NU64* x_365);
static inline X60Qt_0_IAarrayAcS8ZS16_sysvq0asl default_23_Imn3jdi_sysvq0asl(void);
static inline X60Qt_0_IAarrayAcS8ZS65_sysvq0asl default_23_Iu3awv61_sysvq0asl(void);
static inline openArray_0_Ijk0jkw1_has9tn57v toOpenArray_0_I9ym4m81_sysvq0asl(X60Qt_0_IAarrayAcS8ZS65_sysvq0asl* x_368);
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1);
static inline void inc_0_Ineawm41_party5a2l1(NU64* x_8, NU64 y_2);
static inline void dec_0_Iw9ew8i1_ospaexnw61(NI64* x_7, NI64 y_3);
static inline void inc_0_Iwdk9lf_party5a2l1(NI64* x_10, NI64 y_3);
static inline void dec_1_I2mwrey1_envto7w6l1(NI64* x_8);
static inline NC8* getQ_10_I5nt6we_has9tn57v(openArray_0_Ijk0jkw1_has9tn57v x_14, NI64 idx_1);
extern LongString_0_sysvq0asl const strlit_0_I14872370265633446329_str7j0ifg;
extern LongString_0_sysvq0asl const strlit_0_I14694606176902936784_has9tn57v;
LongString_0_sysvq0asl const strlit_0_I14131790745264837101_sysvq0asl = {
  .fullLen_0 = IL64(90), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "../nimony/lib/std/system/stringimpl.nim(403, 37): i < len(s) and 0 <= i [AssertionDefect]\012"}
;
LongString_0_sysvq0asl const strlit_0_I11927585966806674622_sysvq0asl = {
  .fullLen_0 = IL64(90), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "../nimony/lib/std/system/stringimpl.nim(407, 45): i < len(s) and 0 <= i [AssertionDefect]\012"}
;
LongString_0_sysvq0asl const strlit_0_I15539159382304113184_sysvq0asl = {
  .fullLen_0 = IL64(27), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "invalid object conversion: "}
;
LongString_0_sysvq0asl const strlit_0_I14281474217946372742_sysvq0asl = {
  .fullLen_0 = IL64(35), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "cannot dispatch; dispatcher is nil\012"}
;
LongString_0_sysvq0asl const strlit_0_I16690852185662743073_sysvq0asl = {
  .fullLen_0 = IL64(16), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "could not load: "}
;
LongString_0_sysvq0asl const strlit_0_I10604297744791418982_sysvq0asl = {
  .fullLen_0 = IL64(18), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "could not import: "}
;
LongString_0_sysvq0asl const strlit_0_I11614695157650328859_sysvq0asl = {
  .fullLen_0 = IL64(21), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "index out of bounds: "}
;
X60Qt_0_IAarraySstring0sysvq0aslS10_sysvq0asl const NegTen_0_sysvq0asl = {
  .a = {
    {
      .bytes_0 = 3157250ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3222786ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3288322ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3353858ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3419394ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3484930ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3550466ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3616002ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3681538ull, .more_0 = NIM_NIL}
    , {
      .bytes_0 = 3747074ull, .more_0 = NIM_NIL}}}
;
X60Qt_0_ISEAnimcallZAfalseZAR11_sysvq0asl gExitFlush_0_sysvq0asl;
__thread NI64 missingBytes_0_sysvq0asl;
X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
X60Qt_0_IAarrayAiS8ZS100_sysvq0asl const trailingZeros100_0_sysvq0asl = {
  .a = {
    ((NI8)IL64(2)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(1)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(1)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(1)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(1)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(1)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(1)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(1)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(1)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(1)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0)), ((NI8)IL64(0))}}
;
X60Qt_0_IAarrayAcS8ZS200_sysvq0asl const digits100_0_sysvq0asl = {
  .a = {
    (NC8)'0', (NC8)'0', (NC8)'0', (NC8)'1', (NC8)'0', (NC8)'2', (NC8)'0', (NC8)'3', (NC8)'0', (NC8)'4', (NC8)'0', (NC8)'5', (NC8)'0', (NC8)'6', (NC8)'0', (NC8)'7', (NC8)'0', (NC8)'8', (NC8)'0', (NC8)'9', (NC8)'1', (NC8)'0', (NC8)'1', (NC8)'1', (NC8)'1', (NC8)'2', (NC8)'1', (NC8)'3', (NC8)'1', (NC8)'4', (NC8)'1', (NC8)'5', (NC8)'1', (NC8)'6', (NC8)'1', (NC8)'7', (NC8)'1', (NC8)'8', (NC8)'1', (NC8)'9', (NC8)'2', (NC8)'0', (NC8)'2', (NC8)'1', (NC8)'2', (NC8)'2', (NC8)'2', (NC8)'3', (NC8)'2', (NC8)'4', (NC8)'2', (NC8)'5', (NC8)'2', (NC8)'6', (NC8)'2', (NC8)'7', (NC8)'2', (NC8)'8', (NC8)'2', (NC8)'9', (NC8)'3', (NC8)'0', (NC8)'3', (NC8)'1', (NC8)'3', (NC8)'2', (NC8)'3', (NC8)'3', (NC8)'3', (NC8)'4', (NC8)'3', (NC8)'5', (NC8)'3', (NC8)'6', (NC8)'3', (NC8)'7', (NC8)'3', (NC8)'8', (NC8)'3', (NC8)'9', (NC8)'4', (NC8)'0', (NC8)'4', (NC8)'1', (NC8)'4', (NC8)'2', (NC8)'4', (NC8)'3', (NC8)'4', (NC8)'4', (NC8)'4', (NC8)'5', (NC8)'4', (NC8)'6', (NC8)'4', (NC8)'7', (NC8)'4', (NC8)'8', (NC8)'4', (NC8)'9', (NC8)'5', (NC8)'0', (NC8)'5', (NC8)'1', (NC8)'5', (NC8)'2', (NC8)'5', (NC8)'3', (NC8)'5', (NC8)'4', (NC8)'5', (NC8)'5', (NC8)'5', (NC8)'6', (NC8)'5', (NC8)'7', (NC8)'5', (NC8)'8', (NC8)'5', (NC8)'9', (NC8)'6', (NC8)'0', (NC8)'6', (NC8)'1', (NC8)'6', (NC8)'2', (NC8)'6', (NC8)'3', (NC8)'6', (NC8)'4', (NC8)'6', (NC8)'5', (NC8)'6', (NC8)'6', (NC8)'6', (NC8)'7', (NC8)'6', (NC8)'8', (NC8)'6', (NC8)'9', (NC8)'7', (NC8)'0', (NC8)'7', (NC8)'1', (NC8)'7', (NC8)'2', (NC8)'7', (NC8)'3', (NC8)'7', (NC8)'4', (NC8)'7', (NC8)'5', (NC8)'7', (NC8)'6', (NC8)'7', (NC8)'7', (NC8)'7', (NC8)'8', (NC8)'7', (NC8)'9', (NC8)'8', (NC8)'0', (NC8)'8', (NC8)'1', (NC8)'8', (NC8)'2', (NC8)'8', (NC8)'3', (NC8)'8', (NC8)'4', (NC8)'8', (NC8)'5', (NC8)'8', (NC8)'6', (NC8)'8', (NC8)'7', (NC8)'8', (NC8)'8', (NC8)'8', (NC8)'9', (NC8)'9', (NC8)'0', (NC8)'9', (NC8)'1', (NC8)'9', (NC8)'2', (NC8)'9', (NC8)'3', (NC8)'9', (NC8)'4', (NC8)'9', (NC8)'5', (NC8)'9', (NC8)'6', (NC8)'9', (NC8)'7', (NC8)'9', (NC8)'8', (NC8)'9', (NC8)'9'}}
;
static NI64 const kMin_0 = ((NI64)IL64(-292));
static NI64 const kMax_0 = ((NI64)IL64(326));
static X60Qt_0_IAarraySuint64x20sysvq0aslS619_sysvq0asl const pow10_3 = {
  .a = {
    {
      .hi_0 = ((NU64)18408377700990114895ull), .lo_0 = ((NU64)2731688931043774331ull)}
    , {
      .hi_0 = ((NU64)11505236063118821809ull), .lo_0 = ((NU64)8624834609543440813ull)}
    , {
      .hi_0 = ((NU64)14381545078898527261ull), .lo_0 = ((NU64)15392729280356688920ull)}
    , {
      .hi_0 = ((NU64)17976931348623159077ull), .lo_0 = ((NU64)5405853545163697438ull)}
    , {
      .hi_0 = ((NU64)11235582092889474423ull), .lo_0 = ((NU64)5684501474941004851ull)}
    , {
      .hi_0 = ((NU64)14044477616111843029ull), .lo_0 = ((NU64)2493940825248868160ull)}
    , {
      .hi_0 = ((NU64)17555597020139803786ull), .lo_0 = ((NU64)7729112049988473104ull)}
    , {
      .hi_0 = ((NU64)10972248137587377366ull), .lo_0 = ((NU64)9442381049670183594ull)}
    , {
      .hi_0 = ((NU64)13715310171984221708ull), .lo_0 = ((NU64)2579604275232953684ull)}
    , {
      .hi_0 = ((NU64)17144137714980277135ull), .lo_0 = ((NU64)3224505344041192105ull)}
    , {
      .hi_0 = ((NU64)10715086071862673209ull), .lo_0 = ((NU64)8932844867666826922ull)}
    , {
      .hi_0 = ((NU64)13393857589828341511ull), .lo_0 = ((NU64)15777742103010921556ull)}
    , {
      .hi_0 = ((NU64)16742321987285426889ull), .lo_0 = ((NU64)15110491610336264041ull)}
    , {
      .hi_0 = ((NU64)10463951242053391806ull), .lo_0 = ((NU64)2526528228819083170ull)}
    , {
      .hi_0 = ((NU64)13079939052566739757ull), .lo_0 = ((NU64)12381532322878629771ull)}
    , {
      .hi_0 = ((NU64)16349923815708424697ull), .lo_0 = ((NU64)1641857348316123501ull)}
    , {
      .hi_0 = ((NU64)10218702384817765435ull), .lo_0 = ((NU64)12555375888766046948ull)}
    , {
      .hi_0 = ((NU64)12773377981022206794ull), .lo_0 = ((NU64)11082533842530170781ull)}
    , {
      .hi_0 = ((NU64)15966722476277758493ull), .lo_0 = ((NU64)4629795266307937668ull)}
    , {
      .hi_0 = ((NU64)9979201547673599058ull), .lo_0 = ((NU64)5199465050656154995ull)}
    , {
      .hi_0 = ((NU64)12474001934591998822ull), .lo_0 = ((NU64)15722703350174969552ull)}
    , {
      .hi_0 = ((NU64)15592502418239998528ull), .lo_0 = ((NU64)10430007150863936131ull)}
    , {
      .hi_0 = ((NU64)9745314011399999080ull), .lo_0 = ((NU64)6518754469289960082ull)}
    , {
      .hi_0 = ((NU64)12181642514249998850ull), .lo_0 = ((NU64)8148443086612450103ull)}
    , {
      .hi_0 = ((NU64)15227053142812498563ull), .lo_0 = ((NU64)962181821410786820ull)}
    , {
      .hi_0 = ((NU64)9516908214257811601ull), .lo_0 = ((NU64)16742264702877599427ull)}
    , {
      .hi_0 = ((NU64)11896135267822264502ull), .lo_0 = ((NU64)7092772823314835571ull)}
    , {
      .hi_0 = ((NU64)14870169084777830627ull), .lo_0 = ((NU64)18089338065998320272ull)}
    , {
      .hi_0 = ((NU64)9293855677986144142ull), .lo_0 = ((NU64)8999993282035256218ull)}
    , {
      .hi_0 = ((NU64)11617319597482680178ull), .lo_0 = ((NU64)2026619565689294465ull)}
    , {
      .hi_0 = ((NU64)14521649496853350222ull), .lo_0 = ((NU64)11756646493966393889ull)}
    , {
      .hi_0 = ((NU64)18152061871066687778ull), .lo_0 = ((NU64)5472436080603216553ull)}
    , {
      .hi_0 = ((NU64)11345038669416679861ull), .lo_0 = ((NU64)8031958568804398250ull)}
    , {
      .hi_0 = ((NU64)14181298336770849826ull), .lo_0 = ((NU64)14651634229432885716ull)}
    , {
      .hi_0 = ((NU64)17726622920963562283ull), .lo_0 = ((NU64)9091170749936331337ull)}
    , {
      .hi_0 = ((NU64)11079139325602226427ull), .lo_0 = ((NU64)3376138709496513134ull)}
    , {
      .hi_0 = ((NU64)13848924157002783033ull), .lo_0 = ((NU64)18055231442152805129ull)}
    , {
      .hi_0 = ((NU64)17311155196253478792ull), .lo_0 = ((NU64)8733981247408842699ull)}
    , {
      .hi_0 = ((NU64)10819471997658424245ull), .lo_0 = ((NU64)5458738279630526687ull)}
    , {
      .hi_0 = ((NU64)13524339997073030306ull), .lo_0 = ((NU64)11435108867965546263ull)}
    , {
      .hi_0 = ((NU64)16905424996341287883ull), .lo_0 = ((NU64)5070514048102157021ull)}
    , {
      .hi_0 = ((NU64)10565890622713304927ull), .lo_0 = ((NU64)863228270850154186ull)}
    , {
      .hi_0 = ((NU64)13207363278391631158ull), .lo_0 = ((NU64)14914093393844856444ull)}
    , {
      .hi_0 = ((NU64)16509204097989538948ull), .lo_0 = ((NU64)9419244705451294747ull)}
    , {
      .hi_0 = ((NU64)10318252561243461842ull), .lo_0 = ((NU64)15110399977761835025ull)}
    , {
      .hi_0 = ((NU64)12897815701554327303ull), .lo_0 = ((NU64)9664627935347517974ull)}
    , {
      .hi_0 = ((NU64)16122269626942909129ull), .lo_0 = ((NU64)7469098900757009563ull)}
    , {
      .hi_0 = ((NU64)10076418516839318205ull), .lo_0 = ((NU64)16197401859041600737ull)}
    , {
      .hi_0 = ((NU64)12595523146049147757ull), .lo_0 = ((NU64)6411694268519837209ull)}
    , {
      .hi_0 = ((NU64)15744403932561434696ull), .lo_0 = ((NU64)12626303854077184415ull)}
    , {
      .hi_0 = ((NU64)9840252457850896685ull), .lo_0 = ((NU64)7891439908798240260ull)}
    , {
      .hi_0 = ((NU64)12300315572313620856ull), .lo_0 = ((NU64)14475985904425188228ull)}
    , {
      .hi_0 = ((NU64)15375394465392026070ull), .lo_0 = ((NU64)18094982380531485285ull)}
    , {
      .hi_0 = ((NU64)9609621540870016294ull), .lo_0 = ((NU64)6697677969404790400ull)}
    , {
      .hi_0 = ((NU64)12012026926087520367ull), .lo_0 = ((NU64)17595469498610763807ull)}
    , {
      .hi_0 = ((NU64)15015033657609400459ull), .lo_0 = ((NU64)17382650854836066855ull)}
    , {
      .hi_0 = ((NU64)9384396036005875287ull), .lo_0 = ((NU64)8558313775058847833ull)}
    , {
      .hi_0 = ((NU64)11730495045007344109ull), .lo_0 = ((NU64)6086206200396171887ull)}
    , {
      .hi_0 = ((NU64)14663118806259180136ull), .lo_0 = ((NU64)12219443768922602762ull)}
    , {
      .hi_0 = ((NU64)18328898507823975170ull), .lo_0 = ((NU64)15274304711153253453ull)}
    , {
      .hi_0 = ((NU64)11455561567389984481ull), .lo_0 = ((NU64)14158126462898171312ull)}
    , {
      .hi_0 = ((NU64)14319451959237480602ull), .lo_0 = ((NU64)3862600023340550428ull)}
    , {
      .hi_0 = ((NU64)17899314949046850752ull), .lo_0 = ((NU64)14051622066030463843ull)}
    , {
      .hi_0 = ((NU64)11187071843154281720ull), .lo_0 = ((NU64)8782263791269039902ull)}
    , {
      .hi_0 = ((NU64)13983839803942852150ull), .lo_0 = ((NU64)10977829739086299877ull)}
    , {
      .hi_0 = ((NU64)17479799754928565188ull), .lo_0 = ((NU64)4498915137003099038ull)}
    , {
      .hi_0 = ((NU64)10924874846830353242ull), .lo_0 = ((NU64)12035193997481712707ull)}
    , {
      .hi_0 = ((NU64)13656093558537941553ull), .lo_0 = ((NU64)5820620459997365076ull)}
    , {
      .hi_0 = ((NU64)17070116948172426941ull), .lo_0 = ((NU64)11887461593424094249ull)}
    , {
      .hi_0 = ((NU64)10668823092607766838ull), .lo_0 = ((NU64)9735506505103752858ull)}
    , {
      .hi_0 = ((NU64)13336028865759708548ull), .lo_0 = ((NU64)2946011094524915264ull)}
    , {
      .hi_0 = ((NU64)16670036082199635685ull), .lo_0 = ((NU64)3682513868156144080ull)}
    , {
      .hi_0 = ((NU64)10418772551374772303ull), .lo_0 = ((NU64)4607414176811284002ull)}
    , {
      .hi_0 = ((NU64)13023465689218465379ull), .lo_0 = ((NU64)1147581702586717098ull)}
    , {
      .hi_0 = ((NU64)16279332111523081723ull), .lo_0 = ((NU64)15269535183515560085ull)}
    , {
      .hi_0 = ((NU64)10174582569701926077ull), .lo_0 = ((NU64)7237616480483531101ull)}
    , {
      .hi_0 = ((NU64)12718228212127407596ull), .lo_0 = ((NU64)13658706619031801780ull)}
    , {
      .hi_0 = ((NU64)15897785265159259495ull), .lo_0 = ((NU64)17073383273789752225ull)}
    , {
      .hi_0 = ((NU64)9936115790724537184ull), .lo_0 = ((NU64)17588393573759676997ull)}
    , {
      .hi_0 = ((NU64)12420144738405671481ull), .lo_0 = ((NU64)3538747893490044630ull)}
    , {
      .hi_0 = ((NU64)15525180923007089351ull), .lo_0 = ((NU64)9035120885289943692ull)}
    , {
      .hi_0 = ((NU64)9703238076879430844ull), .lo_0 = ((NU64)12564479580947296664ull)}
    , {
      .hi_0 = ((NU64)12129047596099288555ull), .lo_0 = ((NU64)15705599476184120829ull)}
    , {
      .hi_0 = ((NU64)15161309495124110694ull), .lo_0 = ((NU64)15020313326802763132ull)}
    , {
      .hi_0 = ((NU64)9475818434452569184ull), .lo_0 = ((NU64)4776009810824339054ull)}
    , {
      .hi_0 = ((NU64)11844773043065711480ull), .lo_0 = ((NU64)5970012263530423817ull)}
    , {
      .hi_0 = ((NU64)14805966303832139350ull), .lo_0 = ((NU64)7462515329413029772ull)}
    , {
      .hi_0 = ((NU64)9253728939895087094ull), .lo_0 = ((NU64)52386062455755703ull)}
    , {
      .hi_0 = ((NU64)11567161174868858867ull), .lo_0 = ((NU64)9288854614924470437ull)}
    , {
      .hi_0 = ((NU64)14458951468586073584ull), .lo_0 = ((NU64)6999382250228200142ull)}
    , {
      .hi_0 = ((NU64)18073689335732591980ull), .lo_0 = ((NU64)8749227812785250178ull)}
    , {
      .hi_0 = ((NU64)11296055834832869987ull), .lo_0 = ((NU64)14691639419845557169ull)}
    , {
      .hi_0 = ((NU64)14120069793541087484ull), .lo_0 = ((NU64)13752863256379558557ull)}
    , {
      .hi_0 = ((NU64)17650087241926359355ull), .lo_0 = ((NU64)17191079070474448197ull)}
    , {
      .hi_0 = ((NU64)11031304526203974597ull), .lo_0 = ((NU64)8438581409832836171ull)}
    , {
      .hi_0 = ((NU64)13789130657754968246ull), .lo_0 = ((NU64)15159912780718433118ull)}
    , {
      .hi_0 = ((NU64)17236413322193710308ull), .lo_0 = ((NU64)9726518939043265589ull)}
    , {
      .hi_0 = ((NU64)10772758326371068942ull), .lo_0 = ((NU64)15302446373756816801ull)}
    , {
      .hi_0 = ((NU64)13465947907963836178ull), .lo_0 = ((NU64)9904685930341245194ull)}
    , {
      .hi_0 = ((NU64)16832434884954795223ull), .lo_0 = ((NU64)3157485376071780684ull)}
    , {
      .hi_0 = ((NU64)10520271803096747014ull), .lo_0 = ((NU64)8890957387685944784ull)}
    , {
      .hi_0 = ((NU64)13150339753870933768ull), .lo_0 = ((NU64)1890324697752655171ull)}
    , {
      .hi_0 = ((NU64)16437924692338667210ull), .lo_0 = ((NU64)2362905872190818964ull)}
    , {
      .hi_0 = ((NU64)10273702932711667006ull), .lo_0 = ((NU64)6088502188546649757ull)}
    , {
      .hi_0 = ((NU64)12842128665889583757ull), .lo_0 = ((NU64)16833999772538088004ull)}
    , {
      .hi_0 = ((NU64)16052660832361979697ull), .lo_0 = ((NU64)7207441660390446293ull)}
    , {
      .hi_0 = ((NU64)10032913020226237310ull), .lo_0 = ((NU64)16033866083812498693ull)}
    , {
      .hi_0 = ((NU64)12541141275282796638ull), .lo_0 = ((NU64)10818960567910847558ull)}
    , {
      .hi_0 = ((NU64)15676426594103495798ull), .lo_0 = ((NU64)4300328673033783640ull)}
    , {
      .hi_0 = ((NU64)9797766621314684873ull), .lo_0 = ((NU64)16522763475928278487ull)}
    , {
      .hi_0 = ((NU64)12247208276643356092ull), .lo_0 = ((NU64)6818396289628184397ull)}
    , {
      .hi_0 = ((NU64)15309010345804195115ull), .lo_0 = ((NU64)8522995362035230496ull)}
    , {
      .hi_0 = ((NU64)9568131466127621947ull), .lo_0 = ((NU64)3021029092058325108ull)}
    , {
      .hi_0 = ((NU64)11960164332659527433ull), .lo_0 = ((NU64)17611344420355070097ull)}
    , {
      .hi_0 = ((NU64)14950205415824409292ull), .lo_0 = ((NU64)8179122470161673909ull)}
    , {
      .hi_0 = ((NU64)9343878384890255807ull), .lo_0 = ((NU64)14335323580705822001ull)}
    , {
      .hi_0 = ((NU64)11679847981112819759ull), .lo_0 = ((NU64)13307468457454889597ull)}
    , {
      .hi_0 = ((NU64)14599809976391024699ull), .lo_0 = ((NU64)12022649553391224093ull)}
    , {
      .hi_0 = ((NU64)18249762470488780874ull), .lo_0 = ((NU64)10416625923311642212ull)}
    , {
      .hi_0 = ((NU64)11406101544055488046ull), .lo_0 = ((NU64)11122077220497164287ull)}
    , {
      .hi_0 = ((NU64)14257626930069360058ull), .lo_0 = ((NU64)4679224488766679550ull)}
    , {
      .hi_0 = ((NU64)17822033662586700072ull), .lo_0 = ((NU64)15072402647813125245ull)}
    , {
      .hi_0 = ((NU64)11138771039116687545ull), .lo_0 = ((NU64)9420251654883203279ull)}
    , {
      .hi_0 = ((NU64)13923463798895859431ull), .lo_0 = ((NU64)16387000587031392002ull)}
    , {
      .hi_0 = ((NU64)17404329748619824289ull), .lo_0 = ((NU64)15872064715361852098ull)}
    , {
      .hi_0 = ((NU64)10877706092887390181ull), .lo_0 = ((NU64)3002511419460075706ull)}
    , {
      .hi_0 = ((NU64)13597132616109237726ull), .lo_0 = ((NU64)8364825292752482536ull)}
    , {
      .hi_0 = ((NU64)16996415770136547158ull), .lo_0 = ((NU64)1232659579085827362ull)}
    , {
      .hi_0 = ((NU64)10622759856335341973ull), .lo_0 = ((NU64)14605470292210805813ull)}
    , {
      .hi_0 = ((NU64)13278449820419177467ull), .lo_0 = ((NU64)4421779809981343555ull)}
    , {
      .hi_0 = ((NU64)16598062275523971834ull), .lo_0 = ((NU64)915538744049291539ull)}
    , {
      .hi_0 = ((NU64)10373788922202482396ull), .lo_0 = ((NU64)5183897733458195116ull)}
    , {
      .hi_0 = ((NU64)12967236152753102995ull), .lo_0 = ((NU64)6479872166822743895ull)}
    , {
      .hi_0 = ((NU64)16209045190941378744ull), .lo_0 = ((NU64)3488154190101041965ull)}
    , {
      .hi_0 = ((NU64)10130653244338361715ull), .lo_0 = ((NU64)2180096368813151228ull)}
    , {
      .hi_0 = ((NU64)12663316555422952143ull), .lo_0 = ((NU64)16560178516298602747ull)}
    , {
      .hi_0 = ((NU64)15829145694278690179ull), .lo_0 = ((NU64)16088537126945865530ull)}
    , {
      .hi_0 = ((NU64)9893216058924181362ull), .lo_0 = ((NU64)7749492695127472004ull)}
    , {
      .hi_0 = ((NU64)12366520073655226703ull), .lo_0 = ((NU64)463493832054564197ull)}
    , {
      .hi_0 = ((NU64)15458150092069033378ull), .lo_0 = ((NU64)14414425345350368958ull)}
    , {
      .hi_0 = ((NU64)9661343807543145861ull), .lo_0 = ((NU64)13620701859271368503ull)}
    , {
      .hi_0 = ((NU64)12076679759428932327ull), .lo_0 = ((NU64)3190819268807046917ull)}
    , {
      .hi_0 = ((NU64)15095849699286165408ull), .lo_0 = ((NU64)17823582141290972358ull)}
    , {
      .hi_0 = ((NU64)9434906062053853380ull), .lo_0 = ((NU64)11139738838306857724ull)}
    , {
      .hi_0 = ((NU64)11793632577567316725ull), .lo_0 = ((NU64)13924673547883572155ull)}
    , {
      .hi_0 = ((NU64)14742040721959145907ull), .lo_0 = ((NU64)3570783879572301481ull)}
    , {
      .hi_0 = ((NU64)18427550902448932383ull), .lo_0 = ((NU64)18298537904747540563ull)}
    , {
      .hi_0 = ((NU64)11517219314030582739ull), .lo_0 = ((NU64)18354115218108294708ull)}
    , {
      .hi_0 = ((NU64)14396524142538228424ull), .lo_0 = ((NU64)18330958004207980481ull)}
    , {
      .hi_0 = ((NU64)17995655178172785531ull), .lo_0 = ((NU64)4466953431550423985ull)}
    , {
      .hi_0 = ((NU64)11247284486357990957ull), .lo_0 = ((NU64)486002885505321039ull)}
    , {
      .hi_0 = ((NU64)14059105607947488696ull), .lo_0 = ((NU64)5219189625309039203ull)}
    , {
      .hi_0 = ((NU64)17573882009934360870ull), .lo_0 = ((NU64)6523987031636299003ull)}
    , {
      .hi_0 = ((NU64)10983676256208975543ull), .lo_0 = ((NU64)17912549950054850589ull)}
    , {
      .hi_0 = ((NU64)13729595320261219429ull), .lo_0 = ((NU64)17779001419141175332ull)}
    , {
      .hi_0 = ((NU64)17161994150326524287ull), .lo_0 = ((NU64)8388693718644305453ull)}
    , {
      .hi_0 = ((NU64)10726246343954077679ull), .lo_0 = ((NU64)12160462601793772765ull)}
    , {
      .hi_0 = ((NU64)13407807929942597099ull), .lo_0 = ((NU64)10588892233814828052ull)}
    , {
      .hi_0 = ((NU64)16759759912428246374ull), .lo_0 = ((NU64)8624429273841147160ull)}
    , {
      .hi_0 = ((NU64)10474849945267653984ull), .lo_0 = ((NU64)778582277723329071ull)}
    , {
      .hi_0 = ((NU64)13093562431584567480ull), .lo_0 = ((NU64)973227847154161339ull)}
    , {
      .hi_0 = ((NU64)16366953039480709350ull), .lo_0 = ((NU64)1216534808942701674ull)}
    , {
      .hi_0 = ((NU64)10229345649675443343ull), .lo_0 = ((NU64)14595392310871352258ull)}
    , {
      .hi_0 = ((NU64)12786682062094304179ull), .lo_0 = ((NU64)13632554370161802419ull)}
    , {
      .hi_0 = ((NU64)15983352577617880224ull), .lo_0 = ((NU64)12429006944274865119ull)}
    , {
      .hi_0 = ((NU64)9989595361011175140ull), .lo_0 = ((NU64)7768129340171790700ull)}
    , {
      .hi_0 = ((NU64)12486994201263968925ull), .lo_0 = ((NU64)9710161675214738375ull)}
    , {
      .hi_0 = ((NU64)15608742751579961156ull), .lo_0 = ((NU64)16749388112445810872ull)}
    , {
      .hi_0 = ((NU64)9755464219737475723ull), .lo_0 = ((NU64)1244995533423855987ull)}
    , {
      .hi_0 = ((NU64)12194330274671844653ull), .lo_0 = ((NU64)15391302472061983696ull)}
    , {
      .hi_0 = ((NU64)15242912843339805817ull), .lo_0 = ((NU64)5404070034795315908ull)}
    , {
      .hi_0 = ((NU64)9526820527087378635ull), .lo_0 = ((NU64)14906758817815542203ull)}
    , {
      .hi_0 = ((NU64)11908525658859223294ull), .lo_0 = ((NU64)14021762503842039849ull)}
    , {
      .hi_0 = ((NU64)14885657073574029118ull), .lo_0 = ((NU64)8303831092947774003ull)}
    , {
      .hi_0 = ((NU64)9303535670983768199ull), .lo_0 = ((NU64)578208414664970848ull)}
    , {
      .hi_0 = ((NU64)11629419588729710248ull), .lo_0 = ((NU64)14557818573613377272ull)}
    , {
      .hi_0 = ((NU64)14536774485912137810ull), .lo_0 = ((NU64)18197273217016721590ull)}
    , {
      .hi_0 = ((NU64)18170968107390172263ull), .lo_0 = ((NU64)13523219484416126179ull)}
    , {
      .hi_0 = ((NU64)11356855067118857664ull), .lo_0 = ((NU64)15369541205401160718ull)}
    , {
      .hi_0 = ((NU64)14196068833898572081ull), .lo_0 = ((NU64)765182433041899282ull)}
    , {
      .hi_0 = ((NU64)17745086042373215101ull), .lo_0 = ((NU64)5568164059729762006ull)}
    , {
      .hi_0 = ((NU64)11090678776483259438ull), .lo_0 = ((NU64)5785945546544795206ull)}
    , {
      .hi_0 = ((NU64)13863348470604074297ull), .lo_0 = ((NU64)16455803970035769815ull)}
    , {
      .hi_0 = ((NU64)17329185588255092872ull), .lo_0 = ((NU64)6734696907262548557ull)}
    , {
      .hi_0 = ((NU64)10830740992659433045ull), .lo_0 = ((NU64)4209185567039092848ull)}
    , {
      .hi_0 = ((NU64)13538426240824291306ull), .lo_0 = ((NU64)9873167977226253964ull)}
    , {
      .hi_0 = ((NU64)16923032801030364133ull), .lo_0 = ((NU64)3118087934678041647ull)}
    , {
      .hi_0 = ((NU64)10576895500643977583ull), .lo_0 = ((NU64)4254647968387469982ull)}
    , {
      .hi_0 = ((NU64)13221119375804971979ull), .lo_0 = ((NU64)706623942056949573ull)}
    , {
      .hi_0 = ((NU64)16526399219756214973ull), .lo_0 = ((NU64)14718337982853350678ull)}
    , {
      .hi_0 = ((NU64)10328999512347634358ull), .lo_0 = ((NU64)11504804248497038126ull)}
    , {
      .hi_0 = ((NU64)12911249390434542948ull), .lo_0 = ((NU64)5157633273766521850ull)}
    , {
      .hi_0 = ((NU64)16139061738043178685ull), .lo_0 = ((NU64)6447041592208152312ull)}
    , {
      .hi_0 = ((NU64)10086913586276986678ull), .lo_0 = ((NU64)6335244004343789147ull)}
    , {
      .hi_0 = ((NU64)12608641982846233347ull), .lo_0 = ((NU64)17142427042284512242ull)}
    , {
      .hi_0 = ((NU64)15760802478557791684ull), .lo_0 = ((NU64)16816347784428252398ull)}
    , {
      .hi_0 = ((NU64)9850501549098619803ull), .lo_0 = ((NU64)1286845328412881941ull)}
    , {
      .hi_0 = ((NU64)12313126936373274753ull), .lo_0 = ((NU64)15443614715798266138ull)}
    , {
      .hi_0 = ((NU64)15391408670466593442ull), .lo_0 = ((NU64)5469460339465668960ull)}
    , {
      .hi_0 = ((NU64)9619630419041620901ull), .lo_0 = ((NU64)8030098730593431004ull)}
    , {
      .hi_0 = ((NU64)12024538023802026126ull), .lo_0 = ((NU64)14649309431669176659ull)}
    , {
      .hi_0 = ((NU64)15030672529752532658ull), .lo_0 = ((NU64)9088264752731695016ull)}
    , {
      .hi_0 = ((NU64)9394170331095332911ull), .lo_0 = ((NU64)10291851488884697289ull)}
    , {
      .hi_0 = ((NU64)11742712913869166139ull), .lo_0 = ((NU64)8253128342678483707ull)}
    , {
      .hi_0 = ((NU64)14678391142336457674ull), .lo_0 = ((NU64)5704724409920716730ull)}
    , {
      .hi_0 = ((NU64)18347988927920572092ull), .lo_0 = ((NU64)16354277549255671721ull)}
    , {
      .hi_0 = ((NU64)11467493079950357558ull), .lo_0 = ((NU64)998051431430019018ull)}
    , {
      .hi_0 = ((NU64)14334366349937946947ull), .lo_0 = ((NU64)10470936326142299580ull)}
    , {
      .hi_0 = ((NU64)17917957937422433684ull), .lo_0 = ((NU64)8476984389250486571ull)}
    , {
      .hi_0 = ((NU64)11198723710889021052ull), .lo_0 = ((NU64)14521487280136329915ull)}
    , {
      .hi_0 = ((NU64)13998404638611276315ull), .lo_0 = ((NU64)18151859100170412393ull)}
    , {
      .hi_0 = ((NU64)17498005798264095394ull), .lo_0 = ((NU64)18078137856785627588ull)}
    , {
      .hi_0 = ((NU64)10936253623915059621ull), .lo_0 = ((NU64)15910522178918405147ull)}
    , {
      .hi_0 = ((NU64)13670317029893824527ull), .lo_0 = ((NU64)6053094668365842721ull)}
    , {
      .hi_0 = ((NU64)17087896287367280659ull), .lo_0 = ((NU64)2954682317029915497ull)}
    , {
      .hi_0 = ((NU64)10679935179604550411ull), .lo_0 = ((NU64)17987577512639554850ull)}
    , {
      .hi_0 = ((NU64)13349918974505688014ull), .lo_0 = ((NU64)17872785872372055658ull)}
    , {
      .hi_0 = ((NU64)16687398718132110018ull), .lo_0 = ((NU64)13117610303610293765ull)}
    , {
      .hi_0 = ((NU64)10429624198832568761ull), .lo_0 = ((NU64)12810192458183821507ull)}
    , {
      .hi_0 = ((NU64)13037030248540710952ull), .lo_0 = ((NU64)2177682517447613172ull)}
    , {
      .hi_0 = ((NU64)16296287810675888690ull), .lo_0 = ((NU64)2722103146809516465ull)}
    , {
      .hi_0 = ((NU64)10185179881672430431ull), .lo_0 = ((NU64)6313000485183335695ull)}
    , {
      .hi_0 = ((NU64)12731474852090538039ull), .lo_0 = ((NU64)3279564588051781714ull)}
    , {
      .hi_0 = ((NU64)15914343565113172548ull), .lo_0 = ((NU64)17934513790346890854ull)}
    , {
      .hi_0 = ((NU64)9946464728195732843ull), .lo_0 = ((NU64)1985699082112030976ull)}
    , {
      .hi_0 = ((NU64)12433080910244666053ull), .lo_0 = ((NU64)16317181907922202432ull)}
    , {
      .hi_0 = ((NU64)15541351137805832567ull), .lo_0 = ((NU64)6561419329620589328ull)}
    , {
      .hi_0 = ((NU64)9713344461128645354ull), .lo_0 = ((NU64)11018416108653950186ull)}
    , {
      .hi_0 = ((NU64)12141680576410806693ull), .lo_0 = ((NU64)4549648098962661925ull)}
    , {
      .hi_0 = ((NU64)15177100720513508366ull), .lo_0 = ((NU64)10298746142130715310ull)}
    , {
      .hi_0 = ((NU64)9485687950320942729ull), .lo_0 = ((NU64)1825030320404309165ull)}
    , {
      .hi_0 = ((NU64)11857109937901178411ull), .lo_0 = ((NU64)6892973918932774360ull)}
    , {
      .hi_0 = ((NU64)14821387422376473014ull), .lo_0 = ((NU64)4004531380238580046ull)}
    , {
      .hi_0 = ((NU64)9263367138985295633ull), .lo_0 = ((NU64)16337890167931276241ull)}
    , {
      .hi_0 = ((NU64)11579208923731619542ull), .lo_0 = ((NU64)6587304654631931589ull)}
    , {
      .hi_0 = ((NU64)14474011154664524427ull), .lo_0 = ((NU64)17457502855144690294ull)}
    , {
      .hi_0 = ((NU64)18092513943330655534ull), .lo_0 = ((NU64)17210192550503474963ull)}
    , {
      .hi_0 = ((NU64)11307821214581659709ull), .lo_0 = ((NU64)6144684325637283948ull)}
    , {
      .hi_0 = ((NU64)14134776518227074636ull), .lo_0 = ((NU64)12292541425473992839ull)}
    , {
      .hi_0 = ((NU64)17668470647783843295ull), .lo_0 = ((NU64)15365676781842491049ull)}
    , {
      .hi_0 = ((NU64)11042794154864902059ull), .lo_0 = ((NU64)16521077016292638762ull)}
    , {
      .hi_0 = ((NU64)13803492693581127574ull), .lo_0 = ((NU64)16039660251938410548ull)}
    , {
      .hi_0 = ((NU64)17254365866976409468ull), .lo_0 = ((NU64)10826203278068237377ull)}
    , {
      .hi_0 = ((NU64)10783978666860255917ull), .lo_0 = ((NU64)15989749085647424169ull)}
    , {
      .hi_0 = ((NU64)13479973333575319897ull), .lo_0 = ((NU64)6152128301777116499ull)}
    , {
      .hi_0 = ((NU64)16849966666969149871ull), .lo_0 = ((NU64)12301846395648783527ull)}
    , {
      .hi_0 = ((NU64)10531229166855718669ull), .lo_0 = ((NU64)14606183024921571561ull)}
    , {
      .hi_0 = ((NU64)13164036458569648337ull), .lo_0 = ((NU64)4422670725869800739ull)}
    , {
      .hi_0 = ((NU64)16455045573212060421ull), .lo_0 = ((NU64)10140024425764638827ull)}
    , {
      .hi_0 = ((NU64)10284403483257537763ull), .lo_0 = ((NU64)8643358275316593219ull)}
    , {
      .hi_0 = ((NU64)12855504354071922204ull), .lo_0 = ((NU64)6192511825718353620ull)}
    , {
      .hi_0 = ((NU64)16069380442589902755ull), .lo_0 = ((NU64)7740639782147942025ull)}
    , {
      .hi_0 = ((NU64)10043362776618689222ull), .lo_0 = ((NU64)2532056854628769814ull)}
    , {
      .hi_0 = ((NU64)12554203470773361527ull), .lo_0 = ((NU64)12388443105140738075ull)}
    , {
      .hi_0 = ((NU64)15692754338466701909ull), .lo_0 = ((NU64)10873867862998534690ull)}
    , {
      .hi_0 = ((NU64)9807971461541688693ull), .lo_0 = ((NU64)9102010423587778133ull)}
    , {
      .hi_0 = ((NU64)12259964326927110866ull), .lo_0 = ((NU64)15989199047912110570ull)}
    , {
      .hi_0 = ((NU64)15324955408658888583ull), .lo_0 = ((NU64)10763126773035362405ull)}
    , {
      .hi_0 = ((NU64)9578097130411805364ull), .lo_0 = ((NU64)13644483260788183359ull)}
    , {
      .hi_0 = ((NU64)11972621413014756705ull), .lo_0 = ((NU64)17055604075985229199ull)}
    , {
      .hi_0 = ((NU64)14965776766268445882ull), .lo_0 = ((NU64)7484447039699372787ull)}
    , {
      .hi_0 = ((NU64)9353610478917778676ull), .lo_0 = ((NU64)9289465418239495896ull)}
    , {
      .hi_0 = ((NU64)11692013098647223345ull), .lo_0 = ((NU64)11611831772799369870ull)}
    , {
      .hi_0 = ((NU64)14615016373309029182ull), .lo_0 = ((NU64)679731660717048625ull)}
    , {
      .hi_0 = ((NU64)18268770466636286477ull), .lo_0 = ((NU64)10073036612751086589ull)}
    , {
      .hi_0 = ((NU64)11417981541647679048ull), .lo_0 = ((NU64)8601490892183123070ull)}
    , {
      .hi_0 = ((NU64)14272476927059598810ull), .lo_0 = ((NU64)10751863615228903838ull)}
    , {
      .hi_0 = ((NU64)17840596158824498513ull), .lo_0 = ((NU64)4216457482181353989ull)}
    , {
      .hi_0 = ((NU64)11150372599265311570ull), .lo_0 = ((NU64)14164500972431816003ull)}
    , {
      .hi_0 = ((NU64)13937965749081639463ull), .lo_0 = ((NU64)8482254178684994196ull)}
    , {
      .hi_0 = ((NU64)17422457186352049329ull), .lo_0 = ((NU64)5991131704928854841ull)}
    , {
      .hi_0 = ((NU64)10889035741470030830ull), .lo_0 = ((NU64)15273672361649004036ull)}
    , {
      .hi_0 = ((NU64)13611294676837538538ull), .lo_0 = ((NU64)9868718415206479237ull)}
    , {
      .hi_0 = ((NU64)17014118346046923173ull), .lo_0 = ((NU64)3112525982153323238ull)}
    , {
      .hi_0 = ((NU64)10633823966279326983ull), .lo_0 = ((NU64)4251171748059520976ull)}
    , {
      .hi_0 = ((NU64)13292279957849158729ull), .lo_0 = ((NU64)702278666647013315ull)}
    , {
      .hi_0 = ((NU64)16615349947311448411ull), .lo_0 = ((NU64)5489534351736154548ull)}
    , {
      .hi_0 = ((NU64)10384593717069655257ull), .lo_0 = ((NU64)1125115960621402641ull)}
    , {
      .hi_0 = ((NU64)12980742146337069071ull), .lo_0 = ((NU64)6018080969204141205ull)}
    , {
      .hi_0 = ((NU64)16225927682921336339ull), .lo_0 = ((NU64)2910915193077788602ull)}
    , {
      .hi_0 = ((NU64)10141204801825835211ull), .lo_0 = ((NU64)17960223060169475540ull)}
    , {
      .hi_0 = ((NU64)12676506002282294014ull), .lo_0 = ((NU64)17838592806784456521ull)}
    , {
      .hi_0 = ((NU64)15845632502852867518ull), .lo_0 = ((NU64)13074868971625794844ull)}
    , {
      .hi_0 = ((NU64)9903520314283042199ull), .lo_0 = ((NU64)3560107088838733873ull)}
    , {
      .hi_0 = ((NU64)12379400392853802748ull), .lo_0 = ((NU64)18285191916330581054ull)}
    , {
      .hi_0 = ((NU64)15474250491067253436ull), .lo_0 = ((NU64)4409745821703674701ull)}
    , {
      .hi_0 = ((NU64)9671406556917033397ull), .lo_0 = ((NU64)11979463175419572496ull)}
    , {
      .hi_0 = ((NU64)12089258196146291747ull), .lo_0 = ((NU64)1139270913992301908ull)}
    , {
      .hi_0 = ((NU64)15111572745182864683ull), .lo_0 = ((NU64)15259146697772541097ull)}
    , {
      .hi_0 = ((NU64)9444732965739290427ull), .lo_0 = ((NU64)7231123676894144234ull)}
    , {
      .hi_0 = ((NU64)11805916207174113034ull), .lo_0 = ((NU64)4427218577690292388ull)}
    , {
      .hi_0 = ((NU64)14757395258967641292ull), .lo_0 = ((NU64)14757395258967641293ull)}
    , {
      .hi_0 = ((NU64)9223372036854775808ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)11529215046068469760ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)14411518807585587200ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)18014398509481984000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)11258999068426240000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)14073748835532800000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)17592186044416000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)10995116277760000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)13743895347200000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)17179869184000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)10737418240000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)13421772800000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)16777216000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)10485760000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)13107200000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)16384000000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)10240000000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)12800000000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)16000000000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)10000000000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)12500000000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)15625000000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)9765625000000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)12207031250000000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)15258789062500000000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)9536743164062500000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)11920928955078125000ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)14901161193847656250ull), .lo_0 = ((NU64)0ull)}
    , {
      .hi_0 = ((NU64)9313225746154785156ull), .lo_0 = ((NU64)4611686018427387904ull)}
    , {
      .hi_0 = ((NU64)11641532182693481445ull), .lo_0 = ((NU64)5764607523034234880ull)}
    , {
      .hi_0 = ((NU64)14551915228366851806ull), .lo_0 = ((NU64)11817445422220181504ull)}
    , {
      .hi_0 = ((NU64)18189894035458564758ull), .lo_0 = ((NU64)5548434740920451072ull)}
    , {
      .hi_0 = ((NU64)11368683772161602973ull), .lo_0 = ((NU64)17302829768357445632ull)}
    , {
      .hi_0 = ((NU64)14210854715202003717ull), .lo_0 = ((NU64)7793479155164643328ull)}
    , {
      .hi_0 = ((NU64)17763568394002504646ull), .lo_0 = ((NU64)14353534962383192064ull)}
    , {
      .hi_0 = ((NU64)11102230246251565404ull), .lo_0 = ((NU64)4359273333062107136ull)}
    , {
      .hi_0 = ((NU64)13877787807814456755ull), .lo_0 = ((NU64)5449091666327633920ull)}
    , {
      .hi_0 = ((NU64)17347234759768070944ull), .lo_0 = ((NU64)2199678564482154496ull)}
    , {
      .hi_0 = ((NU64)10842021724855044340ull), .lo_0 = ((NU64)1374799102801346560ull)}
    , {
      .hi_0 = ((NU64)13552527156068805425ull), .lo_0 = ((NU64)1718498878501683200ull)}
    , {
      .hi_0 = ((NU64)16940658945086006781ull), .lo_0 = ((NU64)6759809616554491904ull)}
    , {
      .hi_0 = ((NU64)10587911840678754238ull), .lo_0 = ((NU64)6530724019560251392ull)}
    , {
      .hi_0 = ((NU64)13234889800848442797ull), .lo_0 = ((NU64)17386777061305090048ull)}
    , {
      .hi_0 = ((NU64)16543612251060553497ull), .lo_0 = ((NU64)7898413271349198848ull)}
    , {
      .hi_0 = ((NU64)10339757656912845935ull), .lo_0 = ((NU64)16465723340661719040ull)}
    , {
      .hi_0 = ((NU64)12924697071141057419ull), .lo_0 = ((NU64)15970468157399760896ull)}
    , {
      .hi_0 = ((NU64)16155871338926321774ull), .lo_0 = ((NU64)15351399178322313216ull)}
    , {
      .hi_0 = ((NU64)10097419586828951109ull), .lo_0 = ((NU64)4982938468024057856ull)}
    , {
      .hi_0 = ((NU64)12621774483536188886ull), .lo_0 = ((NU64)10840359103457460224ull)}
    , {
      .hi_0 = ((NU64)15777218104420236108ull), .lo_0 = ((NU64)4327076842467049472ull)}
    , {
      .hi_0 = ((NU64)9860761315262647567ull), .lo_0 = ((NU64)11927795063396681728ull)}
    , {
      .hi_0 = ((NU64)12325951644078309459ull), .lo_0 = ((NU64)10298057810818464256ull)}
    , {
      .hi_0 = ((NU64)15407439555097886824ull), .lo_0 = ((NU64)8260886245095692416ull)}
    , {
      .hi_0 = ((NU64)9629649721936179265ull), .lo_0 = ((NU64)5163053903184807760ull)}
    , {
      .hi_0 = ((NU64)12037062152420224081ull), .lo_0 = ((NU64)11065503397408397604ull)}
    , {
      .hi_0 = ((NU64)15046327690525280101ull), .lo_0 = ((NU64)18443565265187884909ull)}
    , {
      .hi_0 = ((NU64)9403954806578300063ull), .lo_0 = ((NU64)13833071299956122020ull)}
    , {
      .hi_0 = ((NU64)11754943508222875079ull), .lo_0 = ((NU64)12679653106517764621ull)}
    , {
      .hi_0 = ((NU64)14693679385278593849ull), .lo_0 = ((NU64)11237880364719817872ull)}
    , {
      .hi_0 = ((NU64)18367099231598242312ull), .lo_0 = ((NU64)212292400617608628ull)}
    , {
      .hi_0 = ((NU64)11479437019748901445ull), .lo_0 = ((NU64)132682750386005392ull)}
    , {
      .hi_0 = ((NU64)14349296274686126806ull), .lo_0 = ((NU64)4777539456409894645ull)}
    , {
      .hi_0 = ((NU64)17936620343357658507ull), .lo_0 = ((NU64)15195296357367144114ull)}
    , {
      .hi_0 = ((NU64)11210387714598536567ull), .lo_0 = ((NU64)7191217214140771119ull)}
    , {
      .hi_0 = ((NU64)14012984643248170709ull), .lo_0 = ((NU64)4377335499248575995ull)}
    , {
      .hi_0 = ((NU64)17516230804060213386ull), .lo_0 = ((NU64)10083355392488107898ull)}
    , {
      .hi_0 = ((NU64)10947644252537633366ull), .lo_0 = ((NU64)10913783138732455340ull)}
    , {
      .hi_0 = ((NU64)13684555315672041708ull), .lo_0 = ((NU64)4418856886560793367ull)}
    , {
      .hi_0 = ((NU64)17105694144590052135ull), .lo_0 = ((NU64)5523571108200991709ull)}
    , {
      .hi_0 = ((NU64)10691058840368782584ull), .lo_0 = ((NU64)10369760970266701674ull)}
    , {
      .hi_0 = ((NU64)13363823550460978230ull), .lo_0 = ((NU64)12962201212833377092ull)}
    , {
      .hi_0 = ((NU64)16704779438076222788ull), .lo_0 = ((NU64)6979379479186945558ull)}
    , {
      .hi_0 = ((NU64)10440487148797639242ull), .lo_0 = ((NU64)13585484211346616781ull)}
    , {
      .hi_0 = ((NU64)13050608935997049053ull), .lo_0 = ((NU64)7758483227328495169ull)}
    , {
      .hi_0 = ((NU64)16313261169996311316ull), .lo_0 = ((NU64)14309790052588006865ull)}
    , {
      .hi_0 = ((NU64)10195788231247694572ull), .lo_0 = ((NU64)18166990819722280098ull)}
    , {
      .hi_0 = ((NU64)12744735289059618216ull), .lo_0 = ((NU64)4261994450943298507ull)}
    , {
      .hi_0 = ((NU64)15930919111324522770ull), .lo_0 = ((NU64)5327493063679123134ull)}
    , {
      .hi_0 = ((NU64)9956824444577826731ull), .lo_0 = ((NU64)7941369183226839863ull)}
    , {
      .hi_0 = ((NU64)12446030555722283414ull), .lo_0 = ((NU64)5315025460606161924ull)}
    , {
      .hi_0 = ((NU64)15557538194652854267ull), .lo_0 = ((NU64)15867153862612478214ull)}
    , {
      .hi_0 = ((NU64)9723461371658033917ull), .lo_0 = ((NU64)7611128154919104931ull)}
    , {
      .hi_0 = ((NU64)12154326714572542396ull), .lo_0 = ((NU64)14125596212076269068ull)}
    , {
      .hi_0 = ((NU64)15192908393215677995ull), .lo_0 = ((NU64)17656995265095336336ull)}
    , {
      .hi_0 = ((NU64)9495567745759798747ull), .lo_0 = ((NU64)8729779031470891258ull)}
    , {
      .hi_0 = ((NU64)11869459682199748434ull), .lo_0 = ((NU64)6300537770911226168ull)}
    , {
      .hi_0 = ((NU64)14836824602749685542ull), .lo_0 = ((NU64)17099044250493808518ull)}
    , {
      .hi_0 = ((NU64)9273015376718553464ull), .lo_0 = ((NU64)6075216638131242420ull)}
    , {
      .hi_0 = ((NU64)11591269220898191830ull), .lo_0 = ((NU64)7594020797664053025ull)}
    , {
      .hi_0 = ((NU64)14489086526122739788ull), .lo_0 = ((NU64)269153960225290473ull)}
    , {
      .hi_0 = ((NU64)18111358157653424735ull), .lo_0 = ((NU64)336442450281613091ull)}
    , {
      .hi_0 = ((NU64)11319598848533390459ull), .lo_0 = ((NU64)7127805559067090038ull)}
    , {
      .hi_0 = ((NU64)14149498560666738074ull), .lo_0 = ((NU64)4298070930406474644ull)}
    , {
      .hi_0 = ((NU64)17686873200833422592ull), .lo_0 = ((NU64)14595960699862869113ull)}
    , {
      .hi_0 = ((NU64)11054295750520889120ull), .lo_0 = ((NU64)9122475437414293195ull)}
    , {
      .hi_0 = ((NU64)13817869688151111400ull), .lo_0 = ((NU64)11403094296767866494ull)}
    , {
      .hi_0 = ((NU64)17272337110188889250ull), .lo_0 = ((NU64)14253867870959833118ull)}
    , {
      .hi_0 = ((NU64)10795210693868055781ull), .lo_0 = ((NU64)13520353437777283602ull)}
    , {
      .hi_0 = ((NU64)13494013367335069727ull), .lo_0 = ((NU64)3065383741939440791ull)}
    , {
      .hi_0 = ((NU64)16867516709168837158ull), .lo_0 = ((NU64)17666787732706464701ull)}
    , {
      .hi_0 = ((NU64)10542197943230523224ull), .lo_0 = ((NU64)6430056314514152534ull)}
    , {
      .hi_0 = ((NU64)13177747429038154030ull), .lo_0 = ((NU64)8037570393142690668ull)}
    , {
      .hi_0 = ((NU64)16472184286297692538ull), .lo_0 = ((NU64)823590954573587527ull)}
    , {
      .hi_0 = ((NU64)10295115178936057836ull), .lo_0 = ((NU64)5126430365035880108ull)}
    , {
      .hi_0 = ((NU64)12868893973670072295ull), .lo_0 = ((NU64)6408037956294850135ull)}
    , {
      .hi_0 = ((NU64)16086117467087590369ull), .lo_0 = ((NU64)3398361426941174765ull)}
    , {
      .hi_0 = ((NU64)10053823416929743980ull), .lo_0 = ((NU64)13653190937906703988ull)}
    , {
      .hi_0 = ((NU64)12567279271162179975ull), .lo_0 = ((NU64)17066488672383379985ull)}
    , {
      .hi_0 = ((NU64)15709099088952724969ull), .lo_0 = ((NU64)16721424822051837077ull)}
    , {
      .hi_0 = ((NU64)9818186930595453106ull), .lo_0 = ((NU64)3533361486141316317ull)}
    , {
      .hi_0 = ((NU64)12272733663244316382ull), .lo_0 = ((NU64)13640073894531421205ull)}
    , {
      .hi_0 = ((NU64)15340917079055395478ull), .lo_0 = ((NU64)7826720331309500698ull)}
    , {
      .hi_0 = ((NU64)9588073174409622174ull), .lo_0 = ((NU64)280014188641050032ull)}
    , {
      .hi_0 = ((NU64)11985091468012027717ull), .lo_0 = ((NU64)9573389772656088348ull)}
    , {
      .hi_0 = ((NU64)14981364335015034646ull), .lo_0 = ((NU64)16578423234247498339ull)}
    , {
      .hi_0 = ((NU64)9363352709384396654ull), .lo_0 = ((NU64)5749828502977298558ull)}
    , {
      .hi_0 = ((NU64)11704190886730495817ull), .lo_0 = ((NU64)16410657665576399005ull)}
    , {
      .hi_0 = ((NU64)14630238608413119772ull), .lo_0 = ((NU64)6678264026688335045ull)}
    , {
      .hi_0 = ((NU64)18287798260516399715ull), .lo_0 = ((NU64)8347830033360418806ull)}
    , {
      .hi_0 = ((NU64)11429873912822749822ull), .lo_0 = ((NU64)2911550761636567802ull)}
    , {
      .hi_0 = ((NU64)14287342391028437277ull), .lo_0 = ((NU64)12862810488900485560ull)}
    , {
      .hi_0 = ((NU64)17859177988785546597ull), .lo_0 = ((NU64)2243455055843443238ull)}
    , {
      .hi_0 = ((NU64)11161986242990966623ull), .lo_0 = ((NU64)3708002419115845976ull)}
    , {
      .hi_0 = ((NU64)13952482803738708279ull), .lo_0 = ((NU64)23317005467419566ull)}
    , {
      .hi_0 = ((NU64)17440603504673385348ull), .lo_0 = ((NU64)13864204312116438170ull)}
    , {
      .hi_0 = ((NU64)10900377190420865842ull), .lo_0 = ((NU64)17888499731927549664ull)}
    , {
      .hi_0 = ((NU64)13625471488026082303ull), .lo_0 = ((NU64)13137252628054661272ull)}
    , {
      .hi_0 = ((NU64)17031839360032602879ull), .lo_0 = ((NU64)11809879766640938686ull)}
    , {
      .hi_0 = ((NU64)10644899600020376799ull), .lo_0 = ((NU64)14298703881791668535ull)}
    , {
      .hi_0 = ((NU64)13306124500025470999ull), .lo_0 = ((NU64)13261693833812197764ull)}
    , {
      .hi_0 = ((NU64)16632655625031838749ull), .lo_0 = ((NU64)11965431273837859301ull)}
    , {
      .hi_0 = ((NU64)10395409765644899218ull), .lo_0 = ((NU64)9784237555362356015ull)}
    , {
      .hi_0 = ((NU64)12994262207056124023ull), .lo_0 = ((NU64)3006924907348169211ull)}
    , {
      .hi_0 = ((NU64)16242827758820155028ull), .lo_0 = ((NU64)17593714189467375226ull)}
    , {
      .hi_0 = ((NU64)10151767349262596893ull), .lo_0 = ((NU64)1772699331562333708ull)}
    , {
      .hi_0 = ((NU64)12689709186578246116ull), .lo_0 = ((NU64)6827560182880305039ull)}
    , {
      .hi_0 = ((NU64)15862136483222807645ull), .lo_0 = ((NU64)8534450228600381299ull)}
    , {
      .hi_0 = ((NU64)9913835302014254778ull), .lo_0 = ((NU64)7639874402088932264ull)}
    , {
      .hi_0 = ((NU64)12392294127517818473ull), .lo_0 = ((NU64)326470965756389522ull)}
    , {
      .hi_0 = ((NU64)15490367659397273091ull), .lo_0 = ((NU64)5019774725622874806ull)}
    , {
      .hi_0 = ((NU64)9681479787123295682ull), .lo_0 = ((NU64)831516194300602802ull)}
    , {
      .hi_0 = ((NU64)12101849733904119602ull), .lo_0 = ((NU64)10262767279730529310ull)}
    , {
      .hi_0 = ((NU64)15127312167380149503ull), .lo_0 = ((NU64)3605087062808385830ull)}
    , {
      .hi_0 = ((NU64)9454570104612593439ull), .lo_0 = ((NU64)9170708441896323000ull)}
    , {
      .hi_0 = ((NU64)11818212630765741799ull), .lo_0 = ((NU64)6851699533943015846ull)}
    , {
      .hi_0 = ((NU64)14772765788457177249ull), .lo_0 = ((NU64)3952938399001381903ull)}
    , {
      .hi_0 = ((NU64)9232978617785735780ull), .lo_0 = ((NU64)13999801545444333449ull)}
    , {
      .hi_0 = ((NU64)11541223272232169725ull), .lo_0 = ((NU64)17499751931805416812ull)}
    , {
      .hi_0 = ((NU64)14426529090290212157ull), .lo_0 = ((NU64)8039631859474607303ull)}
    , {
      .hi_0 = ((NU64)18033161362862765196ull), .lo_0 = ((NU64)14661225842770647033ull)}
    , {
      .hi_0 = ((NU64)11270725851789228247ull), .lo_0 = ((NU64)18386638188586430203ull)}
    , {
      .hi_0 = ((NU64)14088407314736535309ull), .lo_0 = ((NU64)18371611717305649850ull)}
    , {
      .hi_0 = ((NU64)17610509143420669137ull), .lo_0 = ((NU64)9129456591349898601ull)}
    , {
      .hi_0 = ((NU64)11006568214637918210ull), .lo_0 = ((NU64)17235125415662156385ull)}
    , {
      .hi_0 = ((NU64)13758210268297397763ull), .lo_0 = ((NU64)12320534732722919674ull)}
    , {
      .hi_0 = ((NU64)17197762835371747204ull), .lo_0 = ((NU64)10788982397476261688ull)}
    , {
      .hi_0 = ((NU64)10748601772107342002ull), .lo_0 = ((NU64)15966486035277439363ull)}
    , {
      .hi_0 = ((NU64)13435752215134177503ull), .lo_0 = ((NU64)10734735507242023396ull)}
    , {
      .hi_0 = ((NU64)16794690268917721879ull), .lo_0 = ((NU64)8806733365625141341ull)}
    , {
      .hi_0 = ((NU64)10496681418073576174ull), .lo_0 = ((NU64)12421737381156795194ull)}
    , {
      .hi_0 = ((NU64)13120851772591970218ull), .lo_0 = ((NU64)6303799689591218185ull)}
    , {
      .hi_0 = ((NU64)16401064715739962772ull), .lo_0 = ((NU64)17103121648843798539ull)}
    , {
      .hi_0 = ((NU64)10250665447337476733ull), .lo_0 = ((NU64)1466078993672598279ull)}
    , {
      .hi_0 = ((NU64)12813331809171845916ull), .lo_0 = ((NU64)6444284760518135752ull)}
    , {
      .hi_0 = ((NU64)16016664761464807395ull), .lo_0 = ((NU64)8055355950647669691ull)}
    , {
      .hi_0 = ((NU64)10010415475915504622ull), .lo_0 = ((NU64)2728754459941099604ull)}
    , {
      .hi_0 = ((NU64)12513019344894380777ull), .lo_0 = ((NU64)12634315111781150314ull)}
    , {
      .hi_0 = ((NU64)15641274181117975972ull), .lo_0 = ((NU64)1957835834444274180ull)}
    , {
      .hi_0 = ((NU64)9775796363198734982ull), .lo_0 = ((NU64)10447019433382447170ull)}
    , {
      .hi_0 = ((NU64)12219745453998418728ull), .lo_0 = ((NU64)3835402254873283155ull)}
    , {
      .hi_0 = ((NU64)15274681817498023410ull), .lo_0 = ((NU64)4794252818591603944ull)}
    , {
      .hi_0 = ((NU64)9546676135936264631ull), .lo_0 = ((NU64)7608094030047140369ull)}
    , {
      .hi_0 = ((NU64)11933345169920330789ull), .lo_0 = ((NU64)4898431519131537557ull)}
    , {
      .hi_0 = ((NU64)14916681462400413486ull), .lo_0 = ((NU64)10734725417341809851ull)}
    , {
      .hi_0 = ((NU64)9322925914000258429ull), .lo_0 = ((NU64)2097517367411243253ull)}
    , {
      .hi_0 = ((NU64)11653657392500323036ull), .lo_0 = ((NU64)7233582727691441970ull)}
    , {
      .hi_0 = ((NU64)14567071740625403795ull), .lo_0 = ((NU64)9041978409614302462ull)}
    , {
      .hi_0 = ((NU64)18208839675781754744ull), .lo_0 = ((NU64)6690786993590490174ull)}
    , {
      .hi_0 = ((NU64)11380524797363596715ull), .lo_0 = ((NU64)4181741870994056359ull)}
    , {
      .hi_0 = ((NU64)14225655996704495894ull), .lo_0 = ((NU64)615491320315182544ull)}
    , {
      .hi_0 = ((NU64)17782069995880619867ull), .lo_0 = ((NU64)9992736187248753989ull)}
    , {
      .hi_0 = ((NU64)11113793747425387417ull), .lo_0 = ((NU64)3939617107816777291ull)}
    , {
      .hi_0 = ((NU64)13892242184281734271ull), .lo_0 = ((NU64)9536207403198359517ull)}
    , {
      .hi_0 = ((NU64)17365302730352167839ull), .lo_0 = ((NU64)7308573235570561493ull)}
    , {
      .hi_0 = ((NU64)10853314206470104899ull), .lo_0 = ((NU64)11485387299872682789ull)}
    , {
      .hi_0 = ((NU64)13566642758087631124ull), .lo_0 = ((NU64)9745048106413465582ull)}
    , {
      .hi_0 = ((NU64)16958303447609538905ull), .lo_0 = ((NU64)12181310133016831978ull)}
    , {
      .hi_0 = ((NU64)10598939654755961816ull), .lo_0 = ((NU64)695789805494438130ull)}
    , {
      .hi_0 = ((NU64)13248674568444952270ull), .lo_0 = ((NU64)869737256868047663ull)}
    , {
      .hi_0 = ((NU64)16560843210556190337ull), .lo_0 = ((NU64)10310543607939835386ull)}
    , {
      .hi_0 = ((NU64)10350527006597618960ull), .lo_0 = ((NU64)17973304801030866876ull)}
    , {
      .hi_0 = ((NU64)12938158758247023701ull), .lo_0 = ((NU64)4019886927579031980ull)}
    , {
      .hi_0 = ((NU64)16172698447808779626ull), .lo_0 = ((NU64)9636544677901177879ull)}
    , {
      .hi_0 = ((NU64)10107936529880487266ull), .lo_0 = ((NU64)10634526442115624078ull)}
    , {
      .hi_0 = ((NU64)12634920662350609083ull), .lo_0 = ((NU64)4069786015789754290ull)}
    , {
      .hi_0 = ((NU64)15793650827938261354ull), .lo_0 = ((NU64)475546501309804958ull)}
    , {
      .hi_0 = ((NU64)9871031767461413346ull), .lo_0 = ((NU64)4908902581746016003ull)}
    , {
      .hi_0 = ((NU64)12338789709326766682ull), .lo_0 = ((NU64)15359500264037295811ull)}
    , {
      .hi_0 = ((NU64)15423487136658458353ull), .lo_0 = ((NU64)9976003293191843956ull)}
    , {
      .hi_0 = ((NU64)9639679460411536470ull), .lo_0 = ((NU64)17764217104313372233ull)}
    , {
      .hi_0 = ((NU64)12049599325514420588ull), .lo_0 = ((NU64)12981899343536939483ull)}
    , {
      .hi_0 = ((NU64)15061999156893025735ull), .lo_0 = ((NU64)16227374179421174354ull)}
    , {
      .hi_0 = ((NU64)9413749473058141084ull), .lo_0 = ((NU64)17059637889779315827ull)}
    , {
      .hi_0 = ((NU64)11767186841322676356ull), .lo_0 = ((NU64)2877803288514593168ull)}
    , {
      .hi_0 = ((NU64)14708983551653345445ull), .lo_0 = ((NU64)3597254110643241460ull)}
    , {
      .hi_0 = ((NU64)18386229439566681806ull), .lo_0 = ((NU64)9108253656731439729ull)}
    , {
      .hi_0 = ((NU64)11491393399729176129ull), .lo_0 = ((NU64)1080972517029761926ull)}
    , {
      .hi_0 = ((NU64)14364241749661470161ull), .lo_0 = ((NU64)5962901664714590312ull)}
    , {
      .hi_0 = ((NU64)17955302187076837701ull), .lo_0 = ((NU64)12065313099320625794ull)}
    , {
      .hi_0 = ((NU64)11222063866923023563ull), .lo_0 = ((NU64)9846663696289085073ull)}
    , {
      .hi_0 = ((NU64)14027579833653779454ull), .lo_0 = ((NU64)7696643601933968437ull)}
    , {
      .hi_0 = ((NU64)17534474792067224318ull), .lo_0 = ((NU64)397432465562684739ull)}
    , {
      .hi_0 = ((NU64)10959046745042015198ull), .lo_0 = ((NU64)14083453346258841674ull)}
    , {
      .hi_0 = ((NU64)13698808431302518998ull), .lo_0 = ((NU64)8380944645968776284ull)}
    , {
      .hi_0 = ((NU64)17123510539128148748ull), .lo_0 = ((NU64)1252808770606194547ull)}
    , {
      .hi_0 = ((NU64)10702194086955092967ull), .lo_0 = ((NU64)10006377518483647400ull)}
    , {
      .hi_0 = ((NU64)13377742608693866209ull), .lo_0 = ((NU64)7896285879677171346ull)}
    , {
      .hi_0 = ((NU64)16722178260867332761ull), .lo_0 = ((NU64)14482043368023852087ull)}
    , {
      .hi_0 = ((NU64)10451361413042082976ull), .lo_0 = ((NU64)2133748077373825698ull)}
    , {
      .hi_0 = ((NU64)13064201766302603720ull), .lo_0 = ((NU64)2667185096717282123ull)}
    , {
      .hi_0 = ((NU64)16330252207878254650ull), .lo_0 = ((NU64)3333981370896602653ull)}
    , {
      .hi_0 = ((NU64)10206407629923909156ull), .lo_0 = ((NU64)6695424375237764562ull)}
    , {
      .hi_0 = ((NU64)12758009537404886445ull), .lo_0 = ((NU64)8369280469047205703ull)}
    , {
      .hi_0 = ((NU64)15947511921756108056ull), .lo_0 = ((NU64)15073286604736395033ull)}
    , {
      .hi_0 = ((NU64)9967194951097567535ull), .lo_0 = ((NU64)9420804127960246895ull)}
    , {
      .hi_0 = ((NU64)12458993688871959419ull), .lo_0 = ((NU64)7164319141522920715ull)}
    , {
      .hi_0 = ((NU64)15573742111089949274ull), .lo_0 = ((NU64)4343712908476262990ull)}
    , {
      .hi_0 = ((NU64)9733588819431218296ull), .lo_0 = ((NU64)7326506586225052273ull)}
    , {
      .hi_0 = ((NU64)12166986024289022870ull), .lo_0 = ((NU64)9158133232781315341ull)}
    , {
      .hi_0 = ((NU64)15208732530361278588ull), .lo_0 = ((NU64)2224294504121868368ull)}
    , {
      .hi_0 = ((NU64)9505457831475799117ull), .lo_0 = ((NU64)10613556101930943538ull)}
    , {
      .hi_0 = ((NU64)11881822289344748896ull), .lo_0 = ((NU64)17878631145841067327ull)}
    , {
      .hi_0 = ((NU64)14852277861680936121ull), .lo_0 = ((NU64)3901544858591782542ull)}
    , {
      .hi_0 = ((NU64)9282673663550585075ull), .lo_0 = ((NU64)13967680582688333849ull)}
    , {
      .hi_0 = ((NU64)11603342079438231344ull), .lo_0 = ((NU64)12847914709933029407ull)}
    , {
      .hi_0 = ((NU64)14504177599297789180ull), .lo_0 = ((NU64)16059893387416286759ull)}
    , {
      .hi_0 = ((NU64)18130221999122236476ull), .lo_0 = ((NU64)1628122660560806833ull)}
    , {
      .hi_0 = ((NU64)11331388749451397797ull), .lo_0 = ((NU64)10240948699705280078ull)}
    , {
      .hi_0 = ((NU64)14164235936814247246ull), .lo_0 = ((NU64)17412871893058988002ull)}
    , {
      .hi_0 = ((NU64)17705294921017809058ull), .lo_0 = ((NU64)12542717829468959195ull)}
    , {
      .hi_0 = ((NU64)11065809325636130661ull), .lo_0 = ((NU64)12450884661845487401ull)}
    , {
      .hi_0 = ((NU64)13832261657045163327ull), .lo_0 = ((NU64)1728547772024695539ull)}
    , {
      .hi_0 = ((NU64)17290327071306454158ull), .lo_0 = ((NU64)15995742770313033136ull)}
    , {
      .hi_0 = ((NU64)10806454419566533849ull), .lo_0 = ((NU64)5385653213018257806ull)}
    , {
      .hi_0 = ((NU64)13508068024458167311ull), .lo_0 = ((NU64)11343752534700210161ull)}
    , {
      .hi_0 = ((NU64)16885085030572709139ull), .lo_0 = ((NU64)9568004649947874797ull)}
    , {
      .hi_0 = ((NU64)10553178144107943212ull), .lo_0 = ((NU64)3674159897003727796ull)}
    , {
      .hi_0 = ((NU64)13191472680134929015ull), .lo_0 = ((NU64)4592699871254659745ull)}
    , {
      .hi_0 = ((NU64)16489340850168661269ull), .lo_0 = ((NU64)1129188820640936778ull)}
    , {
      .hi_0 = ((NU64)10305838031355413293ull), .lo_0 = ((NU64)3011586022114279438ull)}
    , {
      .hi_0 = ((NU64)12882297539194266616ull), .lo_0 = ((NU64)8376168546070237202ull)}
    , {
      .hi_0 = ((NU64)16102871923992833270ull), .lo_0 = ((NU64)10470210682587796502ull)}
    , {
      .hi_0 = ((NU64)10064294952495520794ull), .lo_0 = ((NU64)1932195658189984910ull)}
    , {
      .hi_0 = ((NU64)12580368690619400992ull), .lo_0 = ((NU64)11638616609592256945ull)}
    , {
      .hi_0 = ((NU64)15725460863274251240ull), .lo_0 = ((NU64)14548270761990321182ull)}
    , {
      .hi_0 = ((NU64)9828413039546407025ull), .lo_0 = ((NU64)9092669226243950738ull)}
    , {
      .hi_0 = ((NU64)12285516299433008781ull), .lo_0 = ((NU64)15977522551232326327ull)}
    , {
      .hi_0 = ((NU64)15356895374291260977ull), .lo_0 = ((NU64)6136845133758244197ull)}
    , {
      .hi_0 = ((NU64)9598059608932038110ull), .lo_0 = ((NU64)15364743254667372383ull)}
    , {
      .hi_0 = ((NU64)11997574511165047638ull), .lo_0 = ((NU64)9982557031479439671ull)}
    , {
      .hi_0 = ((NU64)14996968138956309548ull), .lo_0 = ((NU64)3254824252494523781ull)}
    , {
      .hi_0 = ((NU64)9373105086847693467ull), .lo_0 = ((NU64)11257637194663853171ull)}
    , {
      .hi_0 = ((NU64)11716381358559616834ull), .lo_0 = ((NU64)9460360474902428559ull)}
    , {
      .hi_0 = ((NU64)14645476698199521043ull), .lo_0 = ((NU64)2602078556773259891ull)}
    , {
      .hi_0 = ((NU64)18306845872749401303ull), .lo_0 = ((NU64)17087656251248738576ull)}
    , {
      .hi_0 = ((NU64)11441778670468375814ull), .lo_0 = ((NU64)17597314184671543466ull)}
    , {
      .hi_0 = ((NU64)14302223338085469768ull), .lo_0 = ((NU64)12773270693984653525ull)}
    , {
      .hi_0 = ((NU64)17877779172606837210ull), .lo_0 = ((NU64)15966588367480816906ull)}
    , {
      .hi_0 = ((NU64)11173611982879273256ull), .lo_0 = ((NU64)14590803748102898470ull)}
    , {
      .hi_0 = ((NU64)13967014978599091570ull), .lo_0 = ((NU64)18238504685128623088ull)}
    , {
      .hi_0 = ((NU64)17458768723248864463ull), .lo_0 = ((NU64)13574758819556003052ull)}
    , {
      .hi_0 = ((NU64)10911730452030540289ull), .lo_0 = ((NU64)15401753289863583763ull)}
    , {
      .hi_0 = ((NU64)13639663065038175362ull), .lo_0 = ((NU64)5417133557047315992ull)}
    , {
      .hi_0 = ((NU64)17049578831297719202ull), .lo_0 = ((NU64)15994788983163920798ull)}
    , {
      .hi_0 = ((NU64)10655986769561074501ull), .lo_0 = ((NU64)14608429132904838403ull)}
    , {
      .hi_0 = ((NU64)13319983461951343127ull), .lo_0 = ((NU64)4425478360848884291ull)}
    , {
      .hi_0 = ((NU64)16649979327439178909ull), .lo_0 = ((NU64)920161932633717460ull)}
    , {
      .hi_0 = ((NU64)10406237079649486818ull), .lo_0 = ((NU64)2880944217109767365ull)}
    , {
      .hi_0 = ((NU64)13007796349561858522ull), .lo_0 = ((NU64)12824552308241985014ull)}
    , {
      .hi_0 = ((NU64)16259745436952323153ull), .lo_0 = ((NU64)6807318348447705459ull)}
    , {
      .hi_0 = ((NU64)10162340898095201970ull), .lo_0 = ((NU64)15783789013848285672ull)}
    , {
      .hi_0 = ((NU64)12702926122619002463ull), .lo_0 = ((NU64)10506364230455581282ull)}
    , {
      .hi_0 = ((NU64)15878657653273753079ull), .lo_0 = ((NU64)8521269269642088699ull)}
    , {
      .hi_0 = ((NU64)9924161033296095674ull), .lo_0 = ((NU64)12243322321167387293ull)}
    , {
      .hi_0 = ((NU64)12405201291620119593ull), .lo_0 = ((NU64)6080780864604458308ull)}
    , {
      .hi_0 = ((NU64)15506501614525149491ull), .lo_0 = ((NU64)12212662099182960789ull)}
    , {
      .hi_0 = ((NU64)9691563509078218432ull), .lo_0 = ((NU64)5327070802775656541ull)}
    , {
      .hi_0 = ((NU64)12114454386347773040ull), .lo_0 = ((NU64)6658838503469570676ull)}
    , {
      .hi_0 = ((NU64)15143067982934716300ull), .lo_0 = ((NU64)8323548129336963345ull)}
    , {
      .hi_0 = ((NU64)9464417489334197687ull), .lo_0 = ((NU64)14425589617690377899ull)}
    , {
      .hi_0 = ((NU64)11830521861667747109ull), .lo_0 = ((NU64)13420301003685584469ull)}
    , {
      .hi_0 = ((NU64)14788152327084683887ull), .lo_0 = ((NU64)2940318199324816875ull)}
    , {
      .hi_0 = ((NU64)9242595204427927429ull), .lo_0 = ((NU64)8755227902219092403ull)}
    , {
      .hi_0 = ((NU64)11553244005534909286ull), .lo_0 = ((NU64)15555720896201253407ull)}
    , {
      .hi_0 = ((NU64)14441555006918636608ull), .lo_0 = ((NU64)10221279083396790951ull)}
    , {
      .hi_0 = ((NU64)18051943758648295760ull), .lo_0 = ((NU64)12776598854245988689ull)}
    , {
      .hi_0 = ((NU64)11282464849155184850ull), .lo_0 = ((NU64)7985374283903742931ull)}
    , {
      .hi_0 = ((NU64)14103081061443981063ull), .lo_0 = ((NU64)758345818024902856ull)}
    , {
      .hi_0 = ((NU64)17628851326804976328ull), .lo_0 = ((NU64)14782990327813292282ull)}
    , {
      .hi_0 = ((NU64)11018032079253110205ull), .lo_0 = ((NU64)9239368954883307676ull)}
    , {
      .hi_0 = ((NU64)13772540099066387756ull), .lo_0 = ((NU64)16160897212031522499ull)}
    , {
      .hi_0 = ((NU64)17215675123832984696ull), .lo_0 = ((NU64)1754377441329851508ull)}
    , {
      .hi_0 = ((NU64)10759796952395615435ull), .lo_0 = ((NU64)1096485900831157192ull)}
    , {
      .hi_0 = ((NU64)13449746190494519293ull), .lo_0 = ((NU64)15205665431321110202ull)}
    , {
      .hi_0 = ((NU64)16812182738118149117ull), .lo_0 = ((NU64)5172023733869224041ull)}
    , {
      .hi_0 = ((NU64)10507614211323843198ull), .lo_0 = ((NU64)5538357842881958977ull)}
    , {
      .hi_0 = ((NU64)13134517764154803997ull), .lo_0 = ((NU64)16146319340457224530ull)}
    , {
      .hi_0 = ((NU64)16418147205193504997ull), .lo_0 = ((NU64)6347841120289366950ull)}
    , {
      .hi_0 = ((NU64)10261342003245940623ull), .lo_0 = ((NU64)6273243709394548296ull)}
    , {
      .hi_0 = ((NU64)12826677504057425779ull), .lo_0 = ((NU64)3229868618315797466ull)}
    , {
      .hi_0 = ((NU64)16033346880071782223ull), .lo_0 = ((NU64)17872393828176910545ull)}
    , {
      .hi_0 = ((NU64)10020841800044863889ull), .lo_0 = ((NU64)18087775170251650946ull)}
    , {
      .hi_0 = ((NU64)12526052250056079862ull), .lo_0 = ((NU64)8774660907532399971ull)}
    , {
      .hi_0 = ((NU64)15657565312570099828ull), .lo_0 = ((NU64)1744954097560724156ull)}
    , {
      .hi_0 = ((NU64)9785978320356312392ull), .lo_0 = ((NU64)10313968347830228405ull)}
    , {
      .hi_0 = ((NU64)12232472900445390490ull), .lo_0 = ((NU64)12892460434787785506ull)}
    , {
      .hi_0 = ((NU64)15290591125556738113ull), .lo_0 = ((NU64)6892203506629956075ull)}
    , {
      .hi_0 = ((NU64)9556619453472961320ull), .lo_0 = ((NU64)15836842237712192307ull)}
    , {
      .hi_0 = ((NU64)11945774316841201651ull), .lo_0 = ((NU64)1349308723430688768ull)}
    , {
      .hi_0 = ((NU64)14932217896051502063ull), .lo_0 = ((NU64)15521693959570524672ull)}
    , {
      .hi_0 = ((NU64)9332636185032188789ull), .lo_0 = ((NU64)16618587752372659776ull)}
    , {
      .hi_0 = ((NU64)11665795231290235987ull), .lo_0 = ((NU64)6938176635183661008ull)}
    , {
      .hi_0 = ((NU64)14582244039112794984ull), .lo_0 = ((NU64)4061034775552188356ull)}
    , {
      .hi_0 = ((NU64)18227805048890993730ull), .lo_0 = ((NU64)5076293469440235445ull)}
    , {
      .hi_0 = ((NU64)11392378155556871081ull), .lo_0 = ((NU64)7784369436827535057ull)}
    , {
      .hi_0 = ((NU64)14240472694446088851ull), .lo_0 = ((NU64)14342147814461806725ull)}
    , {
      .hi_0 = ((NU64)17800590868057611064ull), .lo_0 = ((NU64)13315998749649870503ull)}}}
;
static X60Qt_0_IAarraySX4dulX43mp0sysvq0aslS25_sysvq0asl const mod5_0 = {
  .a = {
    {
      .mul_0 = ((NU64)1ull), .cmp_0 = ((NU64)18446744073709551615ull)}
    , {
      .mul_0 = ((NU64)14757395258967641293ull), .cmp_0 = ((NU64)3689348814741910323ull)}
    , {
      .mul_0 = ((NU64)10330176681277348905ull), .cmp_0 = ((NU64)737869762948382064ull)}
    , {
      .mul_0 = ((NU64)2066035336255469781ull), .cmp_0 = ((NU64)147573952589676412ull)}
    , {
      .mul_0 = ((NU64)15170602326218735249ull), .cmp_0 = ((NU64)29514790517935282ull)}
    , {
      .mul_0 = ((NU64)6723469279985657373ull), .cmp_0 = ((NU64)5902958103587056ull)}
    , {
      .mul_0 = ((NU64)8723391485480952121ull), .cmp_0 = ((NU64)1180591620717411ull)}
    , {
      .mul_0 = ((NU64)16502073556063831717ull), .cmp_0 = ((NU64)236118324143482ull)}
    , {
      .mul_0 = ((NU64)14368461155438497313ull), .cmp_0 = ((NU64)47223664828696ull)}
    , {
      .mul_0 = ((NU64)10252389860571520109ull), .cmp_0 = ((NU64)9444732965739ull)}
    , {
      .mul_0 = ((NU64)5739826786856214345ull), .cmp_0 = ((NU64)1888946593147ull)}
    , {
      .mul_0 = ((NU64)1147965357371242869ull), .cmp_0 = ((NU64)377789318629ull)}
    , {
      .mul_0 = ((NU64)3918941886216158897ull), .cmp_0 = ((NU64)75557863725ull)}
    , {
      .mul_0 = ((NU64)11851834821468962749ull), .cmp_0 = ((NU64)15111572745ull)}
    , {
      .mul_0 = ((NU64)6059715779035702873ull), .cmp_0 = ((NU64)3022314549ull)}
    , {
      .mul_0 = ((NU64)8590640785290961221ull), .cmp_0 = ((NU64)604462909ull)}
    , {
      .mul_0 = ((NU64)16475523416025833537ull), .cmp_0 = ((NU64)120892581ull)}
    , {
      .mul_0 = ((NU64)14363151127430897677ull), .cmp_0 = ((NU64)24178516ull)}
    , {
      .mul_0 = ((NU64)13940676669711910505ull), .cmp_0 = ((NU64)4835703ull)}
    , {
      .mul_0 = ((NU64)2788135333942382101ull), .cmp_0 = ((NU64)967140ull)}
    , {
      .mul_0 = ((NU64)15315022325756117713ull), .cmp_0 = ((NU64)193428ull)}
    , {
      .mul_0 = ((NU64)10441702094635044189ull), .cmp_0 = ((NU64)38685ull)}
    , {
      .mul_0 = ((NU64)5777689233668919161ull), .cmp_0 = ((NU64)7737ull)}
    , {
      .mul_0 = ((NU64)15912933105701425125ull), .cmp_0 = ((NU64)1547ull)}
    , {
      .mul_0 = ((NU64)3182586621140285025ull), .cmp_0 = ((NU64)309ull)}}}
;
static NI64 const P_0 = ((NI64)IL64(53));
static NI64 const kappa_0 = ((NI64)IL64(2));
static NU32 const bigDivisor_0 = ((NU32)1000ull);
static NU32 const smallDivisor_0 = ((NU32)100ull);
static NI64 const minFixedDecimalPoint_1 = ((NI64)IL64(-6));
static NI64 const maxFixedDecimalPoint_1 = ((NI64)IL64(17));
__thread X60Qt_0_IArefSX45xception0sysvq0asl_sysvq0asl* exc_0_sysvq0asl;
NB8 X60QiniGuard_0_sysvq0asl;
static inline NI64 min_3_sysvq0asl(NI64 x_205, NI64 y_162){
  NI64 result_6;
  NI64 X60Qx_3;
  if (x_205 <= y_162){
    X60Qx_3 = x_205;}
  else {
    X60Qx_3 = y_162;}
  result_6 = X60Qx_3;
  return result_6;}
static inline NI64 max_3_sysvq0asl(NI64 x_212, NI64 y_169){
  NI64 result_13;
  NI64 X60Qx_9;
  if (y_169 <= x_212){
    X60Qx_9 = x_212;}
  else {
    X60Qx_9 = y_169;}
  result_13 = X60Qx_9;
  return result_13;}
string_0_sysvq0asl dollarQ_0_sysvq0asl(NU64 x_224){
  string_0_sysvq0asl result_19;
  nimStrWasMoved((&result_19));
  nimStrDestroy(result_19);
  result_19 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  if (x_224 < ((NU64)IL64(10))){
    nimStrDestroy(result_19);
    NI64 X60Qx_52 = nimIcheckB(((NI64)x_224), IL64(9));
    string_0_sysvq0asl X60Qx_53 = substr_0_sysvq0asl(NegTen_0_sysvq0asl.a[X60Qx_52], IL64(1), IL64(1));
    result_19 = X60Qx_53;}
  else {
    NU64 y_200 = x_224;
    {
      while (NIM_TRUE){
        add_1_sysvq0asl((&result_19), ((NC8)((NU64)(((NU64)(y_200 % 10ull)) + ((NU64)(NC8)'0')))));
        y_200 = ((NU64)(y_200 / 10ull));
        if (y_200 == 0ull){
          goto whileStmtLabel_0;}}}
    whileStmtLabel_0: ;
    NI64 X60Qx_54 = len_4_sysvq0asl(result_19);
    NI64 last_3 = ((NI64)(X60Qx_54 - IL64(1)));
    NI64 i_25 = IL64(0);
    NI64 X60Qx_55 = len_4_sysvq0asl(result_19);
    NI64 b_26 = ((NI64)(X60Qx_55 / IL64(2)));
    {
      while (i_25 < b_26){
        NC8 ch_1 = getQ_9_sysvq0asl(result_19, i_25);
        NC8 X60Qx_56 = getQ_9_sysvq0asl(result_19, ((NI64)(last_3 - i_25)));
        putQ_9_sysvq0asl((&result_19), i_25, X60Qx_56);
        putQ_9_sysvq0asl((&result_19), ((NI64)(last_3 - i_25)), ch_1);
        inc_1_Irn1g7r1_aif7a4qfr((&i_25));}}
    whileStmtLabel_1: ;}
  return result_19;}
string_0_sysvq0asl dollarQ_1_sysvq0asl(NI64 x_225){
  string_0_sysvq0asl result_20;
  nimStrWasMoved((&result_20));
  if (x_225 < IL64(0)){
    if (IL64(-10) < x_225){
      nimStrDestroy(result_20);
      NI64 X60Qx_57 = nimIcheckB(((NI64)((NI64)-x_225)), IL64(9));
      string_0_sysvq0asl X60Qx_58 = nimStrDup(NegTen_0_sysvq0asl.a[X60Qx_57]);
      result_20 = X60Qx_58;}
    else {
      if (x_225 == ((NI64)(IL64(-9223372036854775807) - IL64(1)))){
        nimStrDestroy(result_20);
        string_0_sysvq0asl X60Qtmp_0 = dollarQ_0_sysvq0asl(((NU64)x_225));
        string_0_sysvq0asl X60Qx_59 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 11521ull, .more_0 = NIM_NIL}
        , X60Qtmp_0);
        result_20 = X60Qx_59;
        nimStrDestroy(X60Qtmp_0);}
      else {
        nimStrDestroy(result_20);
        string_0_sysvq0asl X60Qtmp_1 = dollarQ_1_sysvq0asl(((NI64)(IL64(0) - x_225)));
        string_0_sysvq0asl X60Qx_60 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
          .bytes_0 = 11521ull, .more_0 = NIM_NIL}
        , X60Qtmp_1);
        result_20 = X60Qx_60;
        nimStrDestroy(X60Qtmp_1);}}}
  else {
    if (x_225 < IL64(10)){
      nimStrDestroy(result_20);
      result_20 = (string_0_sysvq0asl){
        .bytes_0 = 0ull, .more_0 = NIM_NIL}
      ;
      add_1_sysvq0asl((&result_20), ((NC8)((NI64)(x_225 + ((NI64)(NC8)'0')))));}
    else {
      nimStrDestroy(result_20);
      string_0_sysvq0asl X60Qx_61 = dollarQ_0_sysvq0asl(((NU64)x_225));
      result_20 = X60Qx_61;}}
  return result_20;}
string_0_sysvq0asl dollarQ_2_sysvq0asl(NI32 x_226){
  string_0_sysvq0asl result_21;
  nimStrWasMoved((&result_21));
  nimStrDestroy(result_21);
  string_0_sysvq0asl X60Qx_62 = dollarQ_1_sysvq0asl(((NI64)x_226));
  result_21 = X60Qx_62;
  return result_21;}
N_NIMCALL(void, nimNoopFlush_0_sysvq0asl)(void){
  }
void nimFlushStdStreams(void){
  gExitFlush_0_sysvq0asl();}
void cExit_0_sysvq0asl(NI64 code_1){
  gExitFlush_0_sysvq0asl();
  exit(((NI32)code_1));}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI64 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline NI64 cmpMem_0_sysvq0asl(void* a_5, void* b_6, NI64 size_5){
  NI64 result_29;
  int X60Qx_72 = memcmp(a_5, b_6, ((size_t)size_5));
  result_29 = ((NI64)X60Qx_72);
  return result_29;}
static inline void zeroMem_0_sysvq0asl(void* dest_6, NI64 size_6){
  memset(dest_6, ((int)IL64(0)), ((size_t)size_6));}
void* alloc_0_sysvq0asl(NI64 size_10){
  void* result_30;
  void* X60Qx_73 = mi_malloc(((size_t)size_10));
  result_30 = X60Qx_73;
  return result_30;}
void* realloc_0_sysvq0asl(void* p_9, NI64 size_12){
  void* result_32;
  void* X60Qx_75 = mi_realloc(p_9, ((size_t)size_12));
  result_32 = X60Qx_75;
  return result_32;}
void dealloc_0_sysvq0asl(void* p_10){
  mi_free(p_10);}
NI64 allocatedSize_0_sysvq0asl(void* p_11){
  NI64 result_33;
  size_t X60Qx_76 = mi_usable_size(p_11);
  result_33 = ((NI64)X60Qx_76);
  return result_33;}
N_NIMCALL(void, continueAfterOutOfMem_0_sysvq0asl)(NI64 size_14){
  if (missingBytes_0_sysvq0asl < ((NI64)(((NI64)IL64(9223372036854775807)) - size_14))){
    missingBytes_0_sysvq0asl = ((NI64)(missingBytes_0_sysvq0asl + size_14));}
  else {
    missingBytes_0_sysvq0asl = ((NI64)IL64(9223372036854775807));}}
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
static inline NC8* rawData_1_sysvq0asl(string_0_sysvq0asl* s_31){
  NC8* result_58;
  if (((NI64)IL64(14)) < ((NI64)(*((NU8*)(&(*s_31).bytes_0))))){
    result_58 = ((NC8*)(&(*(*s_31).more_0).data_0[IL64(0)]));}
  else {
    result_58 = ((NC8*)((NU64)(((NU64)(&(*s_31).bytes_0)) + 1ull)));}
  return result_58;}
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32){
  NI64 result_60;
  result_60 = ((NI64)(*((NU8*)(&s_32.bytes_0))));
  if (((NI64)IL64(14)) < result_60){
    result_60 = (*s_32.more_0).fullLen_0;}
  return result_60;}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_37, NI64 start_0){
  NC8* result_65;
  if (((NI64)IL64(14)) < ((NI64)(*((NU8*)(&(*s_37).bytes_0))))){
    result_65 = ((NC8*)((NU64)(((NU64)(&(*(*s_37).more_0).data_0[IL64(0)])) + ((NU64)start_0))));}
  else {
    result_65 = ((NC8*)((NU64)(((NU64)((NC8*)((NU64)(((NU64)(&(*s_37).bytes_0)) + 1ull)))) + ((NU64)start_0))));}
  return result_65;}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38){
  (*s_38).bytes_0 = ((NU64)IL64(0));}
static inline void nimStrDestroy(string_0_sysvq0asl s_39){
  if (((NI64)(*((NU8*)(&s_39.bytes_0)))) == ((NI64)IL64(255))){
    NB8 X60Qx_80 = arcDec_0_sysvq0asl((&(*s_39.more_0).rc_0));
    if (X60Qx_80){
      dealloc_0_sysvq0asl(((void*)s_39.more_0));}}}
void nimStrCopy(string_0_sysvq0asl* dest_9, string_0_sysvq0asl src_6){
  NI64 ssrc_0 = ((NI64)(*((NU8*)(&src_6.bytes_0))));
  if (ssrc_0 <= ((NI64)IL64(14))){
    NI64 sdest_0 = ((NI64)(*((NU8*)(&(*dest_9).bytes_0))));
    if (sdest_0 == ((NI64)IL64(255))){
      NB8 X60Qx_81 = arcDec_0_sysvq0asl((&(*(*dest_9).more_0).rc_0));
      if (X60Qx_81){
        dealloc_0_sysvq0asl(((void*)(*dest_9).more_0));}}
    copyMem_0_sysvq0asl(((void*)(&(*dest_9).bytes_0)), ((void*)(&src_6.bytes_0)), sizeof(string_0_sysvq0asl));}
  else {
    if ((&(*dest_9)) == (&src_6)){
      return;}
    NI64 sdest_1 = ((NI64)(*((NU8*)(&(*dest_9).bytes_0))));
    if (sdest_1 == ((NI64)IL64(255))){
      NB8 X60Qx_82 = arcDec_0_sysvq0asl((&(*(*dest_9).more_0).rc_0));
      if (X60Qx_82){
        dealloc_0_sysvq0asl(((void*)(*dest_9).more_0));}}
    if (ssrc_0 == ((NI64)IL64(255))){
      arcInc_0_sysvq0asl((&(*src_6.more_0).rc_0));}
    copyMem_0_sysvq0asl(((void*)(&(*dest_9).bytes_0)), ((void*)(&src_6.bytes_0)), sizeof(string_0_sysvq0asl));}}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40){
  string_0_sysvq0asl result_66;
  NI64 X60Qx_83 = ssLenOf_0_sysvq0asl(s_40.bytes_0);
  if (X60Qx_83 == ((NI64)IL64(255))){
    arcInc_0_sysvq0asl((&(*s_40.more_0).rc_0));}
  result_66 = (string_0_sysvq0asl){
    .bytes_0 = s_40.bytes_0, .more_0 = s_40.more_0}
  ;
  return result_66;}
static inline NI64 len_5_sysvq0asl(NC8* a_10){
  NI64 result_67;
  NI64 X60Qx_14;
  if (((void*)a_10) == NIM_NIL){
    X60Qx_14 = IL64(0);}
  else {
    size_t X60Qx_84 = strlen(a_10);
    X60Qx_14 = ((NI64)X60Qx_84);}
  result_67 = X60Qx_14;
  return result_67;}
static inline NI64 ssResize_0_sysvq0asl(NI64 old_0){
  NI64 result_68;
  NI64 X60Qx_15;
  if (old_0 <= IL64(0)){
    X60Qx_15 = IL64(4);}
  else {
    if (old_0 <= IL64(32767)){
      X60Qx_15 = ((NI64)(old_0 * IL64(2)));}
    else {
      X60Qx_15 = ((NI64)(((NI64)(old_0 / IL64(2))) + old_0));}}
  result_68 = X60Qx_15;
  return result_68;}
void ensureUniqueLong_0_sysvq0asl(string_0_sysvq0asl* s_41, NI64 oldLen_0, NI64 newLen_5){
  NI64 sl_2 = ((NI64)(*((NU8*)(&(*s_41).bytes_0))));
  NB8 isHeap_0 = (sl_2 == ((NI64)IL64(255)));
  NI64 X60Qx_16;
  if (isHeap_0){
    X60Qx_16 = (*(*s_41).more_0).capImpl_0;}
  else {
    X60Qx_16 = IL64(0);}
  NI64 cap_1 = X60Qx_16;
  NB8 X60Qx_85;
  NB8 X60Qx_86;
  if (isHeap_0){
    NB8 X60Qx_87 = arcIsUnique_0_sysvq0asl((&(*(*s_41).more_0).rc_0));
    X60Qx_86 = X60Qx_87;}
  else {
    X60Qx_86 = NIM_FALSE;}
  if (X60Qx_86){
    X60Qx_85 = (newLen_5 <= cap_1);}
  else {
    X60Qx_85 = NIM_FALSE;}
  if (X60Qx_85){
    (*(*s_41).more_0).fullLen_0 = newLen_5;
    NI64 X60Qx_88 = min_3_sysvq0asl(oldLen_0, ((NI64)IL64(7)));
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&(*s_41).bytes_0)) + 1ull)))), ((void*)(&(*(*s_41).more_0).data_0[IL64(0)])), X60Qx_88);}
  else {
    NI64 X60Qx_17;
    if (cap_1 < newLen_5){
      NI64 X60Qx_89 = ssResize_0_sysvq0asl(cap_1);
      NI64 X60Qx_90 = max_3_sysvq0asl(newLen_5, X60Qx_89);
      X60Qx_17 = X60Qx_90;}
    else {
      X60Qx_17 = cap_1;}
    NI64 newCap_2 = X60Qx_17;
    void* X60Qx_91 = alloc_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + newCap_2)));
    LongString_0_sysvq0asl* p_16 = ((LongString_0_sysvq0asl*)X60Qx_91);
    if ((!(p_16 == NIM_NIL))){
      (*p_16).rc_0 = IL64(0);
      (*p_16).fullLen_0 = newLen_5;
      (*p_16).capImpl_0 = newCap_2;
      if (isHeap_0){
        LongString_0_sysvq0asl* old_1 = (*s_41).more_0;
        NI64 X60Qx_92 = min_3_sysvq0asl(oldLen_0, newCap_2);
        copyMem_0_sysvq0asl(((void*)(&(*p_16).data_0[IL64(0)])), ((void*)(&(*old_1).data_0[IL64(0)])), X60Qx_92);
        NB8 X60Qx_93 = arcDec_0_sysvq0asl((&(*old_1).rc_0));
        if (X60Qx_93){
          dealloc_0_sysvq0asl(((void*)old_1));}}
      else {
        NI64 X60Qx_94 = min_3_sysvq0asl(oldLen_0, newCap_2);
        copyMem_0_sysvq0asl(((void*)(&(*p_16).data_0[IL64(0)])), ((void*)(&(*(*s_41).more_0).data_0[IL64(0)])), X60Qx_94);}
      (*s_41).more_0 = p_16;
      (*((NU8*)(&(*s_41).bytes_0))) = ((NU8)((NI64)IL64(255)));
      NI64 X60Qx_95 = min_3_sysvq0asl(oldLen_0, ((NI64)IL64(7)));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&(*s_41).bytes_0)) + 1ull)))), ((void*)(&(*p_16).data_0[IL64(0)])), X60Qx_95);}
    else {
      oomHandler_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + newCap_2)));
      (*s_41).bytes_0 = ((NU64)21760775509248519ull);
      (*s_41).more_0 = NIM_NIL;}}}
void transitionToLong_0_sysvq0asl(string_0_sysvq0asl* s_42, NI64 sl_0, NI64 newLen_6){
  NI64 X60Qx_96 = ssResize_0_sysvq0asl(newLen_6);
  NI64 newCap_3 = max_3_sysvq0asl(newLen_6, X60Qx_96);
  void* X60Qx_97 = alloc_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + newCap_3)));
  LongString_0_sysvq0asl* p_17 = ((LongString_0_sysvq0asl*)X60Qx_97);
  if ((!(p_17 == NIM_NIL))){
    (*p_17).rc_0 = IL64(0);
    (*p_17).fullLen_0 = newLen_6;
    (*p_17).capImpl_0 = newCap_3;
    copyMem_0_sysvq0asl(((void*)(&(*p_17).data_0[IL64(0)])), ((void*)((NC8*)((NU64)(((NU64)(&(*s_42).bytes_0)) + 1ull)))), sl_0);
    (*s_42).more_0 = p_17;
    (*((NU8*)(&(*s_42).bytes_0))) = ((NU8)((NI64)IL64(255)));
    NI64 X60Qx_98 = min_3_sysvq0asl(sl_0, ((NI64)IL64(7)));
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&(*s_42).bytes_0)) + 1ull)))), ((void*)(&(*p_17).data_0[IL64(0)])), X60Qx_98);}
  else {
    oomHandler_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + newCap_3)));
    (*s_42).bytes_0 = ((NU64)21760775509248519ull);
    (*s_42).more_0 = NIM_NIL;}}
void prepareMutation_0_sysvq0asl(string_0_sysvq0asl* s_44){
  NI64 sl_4 = ((NI64)(*((NU8*)(&(*s_44).bytes_0))));
  NB8 X60Qx_101;
  if (sl_4 == ((NI64)IL64(254))){
    X60Qx_101 = NIM_TRUE;}
  else {
    NB8 X60Qx_102;
    if (sl_4 == ((NI64)IL64(255))){
      NB8 X60Qx_103 = arcIsUnique_0_sysvq0asl((&(*(*s_44).more_0).rc_0));
      X60Qx_102 = (!X60Qx_103);}
    else {
      X60Qx_102 = NIM_FALSE;}
    X60Qx_101 = X60Qx_102;}
  if (X60Qx_101){
    if (sl_4 == ((NI64)IL64(255))){
      NB8 X60Qx_104 = arcDec_0_sysvq0asl((&(*(*s_44).more_0).rc_0));}
    LongString_0_sysvq0asl* old_2 = (*s_44).more_0;
    NI64 oldLen_1 = (*old_2).fullLen_0;
    void* X60Qx_105 = alloc_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + oldLen_1)));
    LongString_0_sysvq0asl* p_18 = ((LongString_0_sysvq0asl*)X60Qx_105);
    if ((!(p_18 == NIM_NIL))){
      (*p_18).rc_0 = IL64(0);
      (*p_18).fullLen_0 = oldLen_1;
      (*p_18).capImpl_0 = oldLen_1;
      copyMem_0_sysvq0asl(((void*)(&(*p_18).data_0[IL64(0)])), ((void*)(&(*old_2).data_0[IL64(0)])), oldLen_1);
      (*s_44).more_0 = p_18;
      (*((NU8*)(&(*s_44).bytes_0))) = ((NU8)((NI64)IL64(255)));}
    else {
      oomHandler_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + oldLen_1)));
      (*s_44).bytes_0 = ((NU64)21760775509248519ull);
      (*s_44).more_0 = NIM_NIL;}}}
NC8* beginStore_0_sysvq0asl(string_0_sysvq0asl* s_45, NI64 newLen_7, NI64 start_2){
  NC8* result_70;
  NI64 sl_5 = ((NI64)(*((NU8*)(&(*s_45).bytes_0))));
  NI64 X60Qx_18;
  if (((NI64)IL64(14)) < sl_5){
    X60Qx_18 = (*(*s_45).more_0).fullLen_0;}
  else {
    X60Qx_18 = sl_5;}
  NI64 curLen_0 = X60Qx_18;
  NB8 X60Qx_106;
  if (newLen_7 <= ((NI64)IL64(14))){
    X60Qx_106 = (sl_5 <= ((NI64)IL64(14)));}
  else {
    X60Qx_106 = NIM_FALSE;}
  if (X60Qx_106){
    if ((!(newLen_7 == curLen_0))){
      (*((NU8*)(&(*s_45).bytes_0))) = ((NU8)newLen_7);}
    result_70 = ((NC8*)((NU64)(((NU64)((NC8*)((NU64)(((NU64)(&(*s_45).bytes_0)) + 1ull)))) + ((NU64)start_2))));}
  else {
    if (sl_5 <= ((NI64)IL64(14))){
      transitionToLong_0_sysvq0asl(s_45, curLen_0, newLen_7);
      result_70 = ((NC8*)((NU64)(((NU64)(&(*(*s_45).more_0).data_0[IL64(0)])) + ((NU64)start_2))));}
    else {
      ensureUniqueLong_0_sysvq0asl(s_45, curLen_0, newLen_7);
      result_70 = ((NC8*)((NU64)(((NU64)(&(*(*s_45).more_0).data_0[IL64(0)])) + ((NU64)start_2))));}}
  return result_70;}
static inline void endStore_0_sysvq0asl(string_0_sysvq0asl* s_46){
  if (((NI64)IL64(14)) < ((NI64)(*((NU8*)(&(*s_46).bytes_0))))){
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&(*s_46).bytes_0)) + 1ull)))), ((void*)(&(*(*s_46).more_0).data_0[IL64(0)])), ((NI64)IL64(7)));}}
void add_1_sysvq0asl(string_0_sysvq0asl* s_47, NC8 c_0){
  NI64 sl_6 = ((NI64)(*((NU8*)(&(*s_47).bytes_0))));
  if (sl_6 < ((NI64)IL64(14))){
    NI64 newLen_14 = ((NI64)(sl_6 + IL64(1)));
    ((NC8*)((NU64)(((NU64)(&(*s_47).bytes_0)) + 1ull)))[sl_6] = c_0;
    (*((NU8*)(&(*s_47).bytes_0))) = ((NU8)newLen_14);}
  else {
    if (((NI64)IL64(14)) < sl_6){
      NI64 l_1 = (*(*s_47).more_0).fullLen_0;
      NB8 X60Qx_107;
      NB8 X60Qx_108;
      if (sl_6 == ((NI64)IL64(255))){
        NB8 X60Qx_109 = arcIsUnique_0_sysvq0asl((&(*(*s_47).more_0).rc_0));
        X60Qx_108 = X60Qx_109;}
      else {
        X60Qx_108 = NIM_FALSE;}
      if (X60Qx_108){
        X60Qx_107 = (l_1 < (*(*s_47).more_0).capImpl_0);}
      else {
        X60Qx_107 = NIM_FALSE;}
      if (X60Qx_107){
        (*(*s_47).more_0).data_0[l_1] = c_0;
        (*(*s_47).more_0).fullLen_0 = ((NI64)(l_1 + IL64(1)));
        if (l_1 < ((NI64)IL64(7))){
          ((NC8*)((NU64)(((NU64)(&(*s_47).bytes_0)) + 1ull)))[l_1] = c_0;}}
      else {
        NI64 oldLen_2 = (*(*s_47).more_0).fullLen_0;
        ensureUniqueLong_0_sysvq0asl(s_47, oldLen_2, ((NI64)(oldLen_2 + IL64(1))));
        if (((NI64)(*((NU8*)(&(*s_47).bytes_0)))) == ((NI64)IL64(255))){
          (*(*s_47).more_0).data_0[oldLen_2] = c_0;
          if (oldLen_2 < ((NI64)IL64(7))){
            ((NC8*)((NU64)(((NU64)(&(*s_47).bytes_0)) + 1ull)))[oldLen_2] = c_0;}}}}
    else {
      transitionToLong_0_sysvq0asl(s_47, sl_6, ((NI64)(sl_6 + IL64(1))));
      if (((NI64)(*((NU8*)(&(*s_47).bytes_0)))) == ((NI64)IL64(255))){
        (*(*s_47).more_0).data_0[sl_6] = c_0;}}}}
void add_2_sysvq0asl(string_0_sysvq0asl* s_48, string_0_sysvq0asl part_0){
  NI64 partLen_0 = len_4_sysvq0asl(part_0);
  if (partLen_0 == IL64(0)){
    return;}
  NC8* partData_0 = rawData_1_sysvq0asl((&part_0));
  NI64 sl_7 = ((NI64)(*((NU8*)(&(*s_48).bytes_0))));
  if (sl_7 <= ((NI64)IL64(14))){
    NI64 sLen_0 = sl_7;
    NI64 newLen_15 = ((NI64)(sLen_0 + partLen_0));
    if (newLen_15 <= ((NI64)IL64(14))){
      copyMem_0_sysvq0asl(((void*)((NU64)(((NU64)(((NU64)(&(*s_48).bytes_0)) + 1ull)) + ((NU64)sLen_0)))), ((void*)partData_0), partLen_0);
      (*((NU8*)(&(*s_48).bytes_0))) = ((NU8)newLen_15);}
    else {
      transitionToLong_0_sysvq0asl(s_48, sLen_0, newLen_15);
      if (((NI64)(*((NU8*)(&(*s_48).bytes_0)))) == ((NI64)IL64(255))){
        copyMem_0_sysvq0asl(((void*)((NU64)(((NU64)(&(*(*s_48).more_0).data_0[IL64(0)])) + ((NU64)sLen_0)))), ((void*)partData_0), partLen_0);
        copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&(*s_48).bytes_0)) + 1ull)))), ((void*)(&(*(*s_48).more_0).data_0[IL64(0)])), ((NI64)IL64(7)));}}}
  else {
    NI64 sLen_1 = (*(*s_48).more_0).fullLen_0;
    NI64 newLen_16 = ((NI64)(sLen_1 + partLen_0));
    ensureUniqueLong_0_sysvq0asl(s_48, sLen_1, newLen_16);
    if (((NI64)(*((NU8*)(&(*s_48).bytes_0)))) == ((NI64)IL64(255))){
      copyMem_0_sysvq0asl(((void*)((NU64)(((NU64)(&(*(*s_48).more_0).data_0[IL64(0)])) + ((NU64)sLen_1)))), ((void*)partData_0), partLen_0);
      if (sLen_1 < ((NI64)IL64(7))){
        copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&(*s_48).bytes_0)) + 1ull)))), ((void*)(&(*(*s_48).more_0).data_0[IL64(0)])), ((NI64)IL64(7)));}}}}
static inline NU64 zeroSwarPadImplLE_0_sysvq0asl(NU64 bytes_2, NI64 newLen_9){
  NU64 result_72;
  NU64 keepBits_0 = ((NU64)((NI64)(((NI64)(newLen_9 + IL64(1))) * IL64(8))));
  NU64 X60Qx_20;
  if (((NU64)((NI64)(sizeof(NU64) * IL64(8)))) <= keepBits_0){
    X60Qx_20 = ((NU64) ~ 0ull);}
  else {
    X60Qx_20 = ((NU64)(((NU64)(((NU64)IL64(1)) << keepBits_0)) - 1ull));}
  NU64 mask_0 = X60Qx_20;
  result_72 = ((NU64)(((NU64)(bytes_2 & ((NU64)(mask_0 & ((NU64) ~ 255ull))))) | ((NU64)newLen_9)));
  return result_72;}
static inline NU64 zeroSwarPadImpl_0_sysvq0asl(NU64 bytes_3, NI64 newLen_10){
  NU64 result_73;
  NU64 X60Qx_110 = zeroSwarPadImplLE_0_sysvq0asl(bytes_3, newLen_10);
  result_73 = X60Qx_110;
  return result_73;}
void shrink_1_sysvq0asl(string_0_sysvq0asl* s_50, NI64 newLen_12){
  NI64 X60Qx_111 = len_4_sysvq0asl((*s_50));
  if (newLen_12 <= X60Qx_111){
    NI64 sl_8 = ((NI64)(*((NU8*)(&(*s_50).bytes_0))));
    if (sl_8 <= ((NI64)IL64(14))){
      if (newLen_12 <= ((NI64)IL64(7))){
        NU64 X60Qx_112 = zeroSwarPadImpl_0_sysvq0asl((*s_50).bytes_0, newLen_12);
        (*s_50).bytes_0 = X60Qx_112;}
      else {
        (*((NU8*)(&(*s_50).bytes_0))) = ((NU8)newLen_12);}}
    else {
      prepareMutation_0_sysvq0asl(s_50);
      (*(*s_50).more_0).fullLen_0 = newLen_12;
      NI64 X60Qx_113 = min_3_sysvq0asl(newLen_12, ((NI64)IL64(7)));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&(*s_50).bytes_0)) + 1ull)))), ((void*)(&(*(*s_50).more_0).data_0[IL64(0)])), X60Qx_113);}}}
void setLen_1_sysvq0asl(string_0_sysvq0asl* s_51, NI64 newLen_13){
  NI64 X60Qx_114 = len_4_sysvq0asl((*s_51));
  if (newLen_13 <= X60Qx_114){
    shrink_1_sysvq0asl(s_51, newLen_13);
    return;}
  NI64 sl_9 = ((NI64)(*((NU8*)(&(*s_51).bytes_0))));
  if (sl_9 <= ((NI64)IL64(14))){
    NI64 curLen_1 = len_4_sysvq0asl((*s_51));
    if (newLen_13 <= ((NI64)IL64(14))){
      NC8* inl_0 = ((NC8*)((NU64)(((NU64)(&(*s_51).bytes_0)) + 1ull)));
      if (curLen_1 < newLen_13){
        zeroMem_0_sysvq0asl(((void*)((NU64)(((NU64)(((NU64)(&(*s_51).bytes_0)) + 1ull)) + ((NU64)curLen_1)))), ((NI64)(newLen_13 - curLen_1)));
        (*((NU8*)(&(*s_51).bytes_0))) = ((NU8)newLen_13);}
      else {
        if (newLen_13 <= ((NI64)IL64(7))){
          NU64 X60Qx_115 = zeroSwarPadImpl_0_sysvq0asl((*s_51).bytes_0, newLen_13);
          (*s_51).bytes_0 = X60Qx_115;}
        else {
          (*((NU8*)(&(*s_51).bytes_0))) = ((NU8)newLen_13);}}}
    else {
      transitionToLong_0_sysvq0asl(s_51, curLen_1, newLen_13);
      if (((NI64)(*((NU8*)(&(*s_51).bytes_0)))) == ((NI64)IL64(255))){
        zeroMem_0_sysvq0asl(((void*)((NU64)(((NU64)(&(*(*s_51).more_0).data_0[IL64(0)])) + ((NU64)curLen_1)))), ((NI64)(newLen_13 - curLen_1)));}}}
  else {
    NI64 curLen_2 = len_4_sysvq0asl((*s_51));
    ensureUniqueLong_0_sysvq0asl(s_51, curLen_2, newLen_13);
    if (((NI64)(*((NU8*)(&(*s_51).bytes_0)))) == ((NI64)IL64(255))){
      if (curLen_2 < newLen_13){
        zeroMem_0_sysvq0asl(((void*)((NU64)(((NU64)(&(*(*s_51).more_0).data_0[IL64(0)])) + ((NU64)curLen_2)))), ((NI64)(newLen_13 - curLen_2)));}
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&(*s_51).bytes_0)) + 1ull)))), ((void*)(&(*(*s_51).more_0).data_0[IL64(0)])), ((NI64)IL64(7)));}}}
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
string_0_sysvq0asl substr_0_sysvq0asl(string_0_sysvq0asl s_54, NI64 first_0, NI64 last_0){
  string_0_sysvq0asl result_75;
  nimStrWasMoved((&result_75));
  nimStrDestroy(result_75);
  result_75 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  NI64 sLen_2 = len_4_sysvq0asl(s_54);
  NI64 f_2 = max_3_sysvq0asl(first_0, IL64(0));
  NI64 X60Qx_120 = min_3_sysvq0asl(last_0, ((NI64)(sLen_2 - IL64(1))));
  NI64 l_2 = ((NI64)(X60Qx_120 + IL64(1)));
  if (l_2 <= f_2){
    return result_75;}
  NI64 newLen_17 = ((NI64)(l_2 - f_2));
  NC8* src_7 = rawData_1_sysvq0asl((&s_54));
  if (newLen_17 <= ((NI64)IL64(14))){
    (*((NU8*)(&result_75.bytes_0))) = ((NU8)newLen_17);
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&result_75.bytes_0)) + 1ull)))), ((void*)((NU64)(((NU64)src_7) + ((NU64)f_2)))), newLen_17);}
  else {
    void* X60Qx_121 = alloc_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + newLen_17)));
    LongString_0_sysvq0asl* p_19 = ((LongString_0_sysvq0asl*)X60Qx_121);
    if ((!(p_19 == NIM_NIL))){
      (*p_19).rc_0 = IL64(0);
      (*p_19).fullLen_0 = newLen_17;
      (*p_19).capImpl_0 = newLen_17;
      copyMem_0_sysvq0asl(((void*)(&(*p_19).data_0[IL64(0)])), ((void*)((NU64)(((NU64)src_7) + ((NU64)f_2)))), newLen_17);
      result_75.more_0 = p_19;
      (*((NU8*)(&result_75.bytes_0))) = ((NU8)((NI64)IL64(255)));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&result_75.bytes_0)) + 1ull)))), ((void*)(&(*p_19).data_0[IL64(0)])), ((NI64)IL64(7)));}
    else {
      oomHandler_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + newLen_17)));
      result_75.bytes_0 = ((NU64)21760775509248519ull);
      result_75.more_0 = NIM_NIL;}}
  return result_75;}
static inline NI64 ctzImpl_0_sysvq0asl(NU64 x_294){
  NI64 result_78;
  NI32 X60Qx_125 = __builtin_ctzll(((NU64)x_294));
  result_78 = ((NI64)X60Qx_125);
  return result_78;}
static inline NI64 cmpInlineBytes_0_sysvq0asl(NC8* a_11, NC8* b_7, NI64 n_3){
  NI64 result_82;
  result_82 = IL64(0);
  {
    NI64 X60Qlf_0 = IL64(0);
    NI64 X60Qlf_1 = n_3;
    NI64 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 < X60Qlf_1){
        {
          NC8 X60Qii_2 = a_11[X60Qlf_2];
          NC8 X60Qii_3 = b_7[X60Qlf_2];
          if (X60Qii_2 < X60Qii_3){
            return IL64(-1);}
          if (X60Qii_3 < X60Qii_2){
            return IL64(1);}}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_82;}
static inline NI64 cmpShortInlineLE_0_sysvq0asl(NU64 abytes_1, NU64 bbytes_1, NI64 aslen_1, NI64 bslen_1){
  NI64 result_84;
  NI64 minLen_1 = min_3_sysvq0asl(aslen_1, bslen_1);
  if (IL64(0) < minLen_1){
    NU64 diffMask_0 = ((NU64)(((NU64)(1ull << ((NI64)(minLen_1 * IL64(8))))) - 1ull));
    NU64 diff_1 = ((NU64)(((NU64)(((NU64)(abytes_1 ^ bbytes_1)) >> IL64(8))) & diffMask_0));
    if ((!(diff_1 == ((NU64)IL64(0))))){
      NI64 X60Qx_129 = ctzImpl_0_sysvq0asl(diff_1);
      NI64 byteShift_0 = ((NI64)(((NI64)(((NI64)(((NI64)X60Qx_129) >> ((NU64)IL64(3)))) * IL64(8))) + IL64(8)));
      NU64 ac_2 = ((NU64)(((NU64)(abytes_1 >> byteShift_0)) & 255ull));
      NU64 bc_2 = ((NU64)(((NU64)(bbytes_1 >> byteShift_0)) & 255ull));
      if (ac_2 < bc_2){
        return IL64(-1);}
      return IL64(1);}}
  result_84 = ((NI64)(aslen_1 - bslen_1));
  return result_84;}
static inline NI64 cmpShortInline_0_sysvq0asl(NU64 abytes_2, NU64 bbytes_2, NI64 aslen_2, NI64 bslen_2){
  NI64 result_85;
  NI64 X60Qx_130 = cmpShortInlineLE_0_sysvq0asl(abytes_2, bbytes_2, aslen_2, bslen_2);
  result_85 = X60Qx_130;
  return result_85;}
NI64 cmpStringPtrs_0_sysvq0asl(string_0_sysvq0asl* a_12, string_0_sysvq0asl* b_8){
  NI64 result_86;
  NU64 abytes_3 = (*a_12).bytes_0;
  NU64 bbytes_3 = (*b_8).bytes_0;
  NI64 aslen_3 = ssLenOf_0_sysvq0asl(abytes_3);
  NI64 bslen_3 = ssLenOf_0_sysvq0asl(bbytes_3);
  NB8 X60Qx_131;
  if (aslen_3 <= ((NI64)IL64(7))){
    X60Qx_131 = (bslen_3 <= ((NI64)IL64(7)));}
  else {
    X60Qx_131 = NIM_FALSE;}
  if (X60Qx_131){
    NI64 X60Qx_132 = cmpShortInline_0_sysvq0asl(abytes_3, bbytes_3, aslen_3, bslen_3);
    result_86 = X60Qx_132;
    return result_86;}
  NB8 X60Qx_133;
  if (aslen_3 <= ((NI64)IL64(14))){
    X60Qx_133 = (bslen_3 <= ((NI64)IL64(14)));}
  else {
    X60Qx_133 = NIM_FALSE;}
  if (X60Qx_133){
    NI64 minLen_2 = min_3_sysvq0asl(aslen_3, bslen_3);
    NI64 pfxLen_0 = min_3_sysvq0asl(minLen_2, ((NI64)IL64(7)));
    NI64 X60Qx_134 = cmpInlineBytes_0_sysvq0asl(((NC8*)((NU64)(((NU64)a_12) + 1ull))), ((NC8*)((NU64)(((NU64)b_8) + 1ull))), pfxLen_0);
    result_86 = X60Qx_134;
    if ((!(result_86 == IL64(0)))){
      return result_86;}
    if (((NI64)IL64(7)) < minLen_2){
      NI64 X60Qx_135 = cmpInlineBytes_0_sysvq0asl(((NC8*)((NU64)(((NU64)(((NU64)a_12) + 1ull)) + ((NU64)((NI64)IL64(7)))))), ((NC8*)((NU64)(((NU64)(((NU64)b_8) + 1ull)) + ((NU64)((NI64)IL64(7)))))), ((NI64)(minLen_2 - ((NI64)IL64(7)))));
      result_86 = X60Qx_135;}
    if (result_86 == IL64(0)){
      result_86 = ((NI64)(aslen_3 - bslen_3));}
    return result_86;}
  NI64 X60Qx_22;
  if (((NI64)IL64(14)) < aslen_3){
    X60Qx_22 = (*(*a_12).more_0).fullLen_0;}
  else {
    X60Qx_22 = aslen_3;}
  NI64 la_0 = X60Qx_22;
  NI64 X60Qx_23;
  if (((NI64)IL64(14)) < bslen_3){
    X60Qx_23 = (*(*b_8).more_0).fullLen_0;}
  else {
    X60Qx_23 = bslen_3;}
  NI64 lb_0 = X60Qx_23;
  NI64 minLen_3 = min_3_sysvq0asl(la_0, lb_0);
  NI64 pfxLen_1 = min_3_sysvq0asl(minLen_3, ((NI64)IL64(7)));
  NI64 X60Qx_136 = cmpInlineBytes_0_sysvq0asl(((NC8*)((NU64)(((NU64)a_12) + 1ull))), ((NC8*)((NU64)(((NU64)b_8) + 1ull))), pfxLen_1);
  result_86 = X60Qx_136;
  if ((!(result_86 == IL64(0)))){
    return result_86;}
  if (minLen_3 <= ((NI64)IL64(7))){
    result_86 = ((NI64)(la_0 - lb_0));
    return result_86;}
  NC8* X60Qx_24;
  if (((NI64)IL64(14)) < aslen_3){
    X60Qx_24 = ((NC8*)((NU64)(((NU64)(&(*(*a_12).more_0).data_0[IL64(0)])) + ((NU64)((NI64)IL64(7))))));}
  else {
    X60Qx_24 = ((NC8*)((NU64)(((NU64)(((NU64)a_12) + 1ull)) + ((NU64)((NI64)IL64(7))))));}
  NC8* ap_0 = X60Qx_24;
  NC8* X60Qx_25;
  if (((NI64)IL64(14)) < bslen_3){
    X60Qx_25 = ((NC8*)((NU64)(((NU64)(&(*(*b_8).more_0).data_0[IL64(0)])) + ((NU64)((NI64)IL64(7))))));}
  else {
    X60Qx_25 = ((NC8*)((NU64)(((NU64)(((NU64)b_8) + 1ull)) + ((NU64)((NI64)IL64(7))))));}
  NC8* bp_0 = X60Qx_25;
  NI64 X60Qx_137 = cmpMem_0_sysvq0asl(((void*)ap_0), ((void*)bp_0), ((NI64)(minLen_3 - ((NI64)IL64(7)))));
  result_86 = X60Qx_137;
  if (result_86 == IL64(0)){
    result_86 = ((NI64)(la_0 - lb_0));}
  return result_86;}
NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_13, string_0_sysvq0asl b_9){
  NB8 result_87;
  NU64 abytes_4 = a_13.bytes_0;
  NU64 bbytes_4 = b_9.bytes_0;
  NI64 aslen_4 = ssLenOf_0_sysvq0asl(abytes_4);
  NI64 bslen_4 = ssLenOf_0_sysvq0asl(bbytes_4);
  NB8 X60Qx_138;
  if (aslen_4 <= ((NI64)IL64(7))){
    X60Qx_138 = (bslen_4 <= ((NI64)IL64(7)));}
  else {
    X60Qx_138 = NIM_FALSE;}
  if (X60Qx_138){
    result_87 = (abytes_4 == bbytes_4);
    return result_87;}
  NI64 X60Qx_26;
  if (((NI64)IL64(14)) < aslen_4){
    X60Qx_26 = (*a_13.more_0).fullLen_0;}
  else {
    X60Qx_26 = aslen_4;}
  NI64 la_1 = X60Qx_26;
  NI64 X60Qx_27;
  if (((NI64)IL64(14)) < bslen_4){
    X60Qx_27 = (*b_9.more_0).fullLen_0;}
  else {
    X60Qx_27 = bslen_4;}
  NI64 lb_1 = X60Qx_27;
  if ((!(la_1 == lb_1))){
    return NIM_FALSE;}
  if (la_1 == IL64(0)){
    return NIM_TRUE;}
  NB8 X60Qx_139;
  if (aslen_4 <= ((NI64)IL64(14))){
    X60Qx_139 = (bslen_4 <= ((NI64)IL64(14)));}
  else {
    X60Qx_139 = NIM_FALSE;}
  if (X60Qx_139){
    if ((!(abytes_4 == bbytes_4))){
      return NIM_FALSE;}
    NI64 X60Qx_140 = cmpMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(((NU64)(&a_13)) + 1ull)) + ((NU64)((NI64)IL64(7))))))), ((void*)((NC8*)((NU64)(((NU64)(((NU64)(&b_9)) + 1ull)) + ((NU64)((NI64)IL64(7))))))), ((NI64)(la_1 - ((NI64)IL64(7)))));
    result_87 = (X60Qx_140 == IL64(0));
    return result_87;}
  NI64 X60Qx_141 = cmpStringPtrs_0_sysvq0asl((&a_13), (&b_9));
  result_87 = (X60Qx_141 == IL64(0));
  return result_87;}
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
string_0_sysvq0asl newString_0_sysvq0asl(NI64 len_2){
  string_0_sysvq0asl result_94;
  nimStrWasMoved((&result_94));
  nimStrDestroy(result_94);
  result_94 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  if (len_2 <= IL64(0)){
    return result_94;}
  if (len_2 <= ((NI64)IL64(14))){
    (*((NU8*)(&result_94.bytes_0))) = ((NU8)len_2);
    zeroMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&result_94.bytes_0)) + 1ull)))), len_2);}
  else {
    void* X60Qx_153 = alloc_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + len_2)));
    LongString_0_sysvq0asl* p_20 = ((LongString_0_sysvq0asl*)X60Qx_153);
    if ((!(p_20 == NIM_NIL))){
      zeroMem_0_sysvq0asl(((void*)p_20), ((NI64)(((NI64)IL64(24)) + len_2)));
      (*p_20).rc_0 = IL64(0);
      (*p_20).fullLen_0 = len_2;
      (*p_20).capImpl_0 = len_2;
      result_94.more_0 = p_20;
      (*((NU8*)(&result_94.bytes_0))) = ((NU8)((NI64)IL64(255)));}
    else {
      oomHandler_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + len_2)));
      result_94.bytes_0 = ((NU64)21760775509248519ull);
      result_94.more_0 = NIM_NIL;}}
  return result_94;}
string_0_sysvq0asl newStringOfCap_0_sysvq0asl(NI64 len_3){
  string_0_sysvq0asl result_95;
  nimStrWasMoved((&result_95));
  nimStrDestroy(result_95);
  result_95 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  if (len_3 <= ((NI64)IL64(14))){
    return result_95;}
  void* X60Qx_154 = alloc_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + len_3)));
  LongString_0_sysvq0asl* p_21 = ((LongString_0_sysvq0asl*)X60Qx_154);
  if ((!(p_21 == NIM_NIL))){
    zeroMem_0_sysvq0asl(((void*)p_21), ((NI64)(((NI64)IL64(24)) + len_3)));
    (*p_21).rc_0 = IL64(0);
    (*p_21).fullLen_0 = IL64(0);
    (*p_21).capImpl_0 = len_3;
    result_95.more_0 = p_21;
    (*((NU8*)(&result_95.bytes_0))) = ((NU8)((NI64)IL64(255)));}
  else {
    oomHandler_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + len_3)));
    result_95.bytes_0 = ((NU64)21760775509248519ull);
    result_95.more_0 = NIM_NIL;}
  return result_95;}
string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_18, string_0_sysvq0asl b_14){
  string_0_sysvq0asl result_96;
  nimStrWasMoved((&result_96));
  nimStrDestroy(result_96);
  result_96 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  NI64 X60Qx_155 = len_4_sysvq0asl(a_18);
  NI64 X60Qx_156 = len_4_sysvq0asl(b_14);
  NI64 rlen_0 = ((NI64)(X60Qx_155 + X60Qx_156));
  if (rlen_0 == IL64(0)){
    return result_96;}
  if (rlen_0 <= ((NI64)IL64(14))){
    NI64 al_0 = len_4_sysvq0asl(a_18);
    (*((NU8*)(&result_96.bytes_0))) = ((NU8)rlen_0);
    if (IL64(0) < al_0){
      NC8* X60Qx_157 = rawData_1_sysvq0asl((&a_18));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&result_96.bytes_0)) + 1ull)))), ((void*)X60Qx_157), al_0);}
    NI64 X60Qx_158 = len_4_sysvq0asl(b_14);
    if (IL64(0) < X60Qx_158){
      NC8* X60Qx_159 = rawData_1_sysvq0asl((&b_14));
      NI64 X60Qx_160 = len_4_sysvq0asl(b_14);
      copyMem_0_sysvq0asl(((void*)((NU64)(((NU64)(((NU64)(&result_96.bytes_0)) + 1ull)) + ((NU64)al_0)))), ((void*)X60Qx_159), X60Qx_160);}}
  else {
    void* X60Qx_161 = alloc_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + rlen_0)));
    LongString_0_sysvq0asl* p_22 = ((LongString_0_sysvq0asl*)X60Qx_161);
    if ((!(p_22 == NIM_NIL))){
      (*p_22).rc_0 = IL64(0);
      (*p_22).fullLen_0 = rlen_0;
      (*p_22).capImpl_0 = rlen_0;
      NI64 al_1 = len_4_sysvq0asl(a_18);
      if (IL64(0) < al_1){
        NC8* X60Qx_162 = rawData_1_sysvq0asl((&a_18));
        copyMem_0_sysvq0asl(((void*)(&(*p_22).data_0[IL64(0)])), ((void*)X60Qx_162), al_1);}
      NI64 X60Qx_163 = len_4_sysvq0asl(b_14);
      if (IL64(0) < X60Qx_163){
        NC8* X60Qx_164 = rawData_1_sysvq0asl((&b_14));
        NI64 X60Qx_165 = len_4_sysvq0asl(b_14);
        copyMem_0_sysvq0asl(((void*)((NU64)(((NU64)(&(*p_22).data_0[IL64(0)])) + ((NU64)al_1)))), ((void*)X60Qx_164), X60Qx_165);}
      result_96.more_0 = p_22;
      (*((NU8*)(&result_96.bytes_0))) = ((NU8)((NI64)IL64(255)));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&result_96.bytes_0)) + 1ull)))), ((void*)(&(*p_22).data_0[IL64(0)])), ((NI64)IL64(7)));}
    else {
      oomHandler_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + rlen_0)));
      result_96.bytes_0 = ((NU64)21760775509248519ull);
      result_96.more_0 = NIM_NIL;}}
  return result_96;}
static inline string_0_sysvq0asl terminatingZero_0_sysvq0asl(string_0_sysvq0asl s_58){
  string_0_sysvq0asl result_100;
  nimStrWasMoved((&result_100));
  nimStrDestroy(result_100);
  string_0_sysvq0asl X60Qx_168 = ampQ_0_sysvq0asl(s_58, (string_0_sysvq0asl){
    .bytes_0 = 1ull, .more_0 = NIM_NIL}
  );
  result_100 = X60Qx_168;
  NI64 X60Qx_169 = len_4_sysvq0asl(s_58);
  shrink_1_sysvq0asl((&result_100), X60Qx_169);
  return result_100;}
string_0_sysvq0asl borrowCStringUnsafe_0_sysvq0asl(NC8* s_59, NI64 l_0){
  string_0_sysvq0asl result_101;
  nimStrWasMoved((&result_101));
  nimStrDestroy(result_101);
  result_101 = (string_0_sysvq0asl){
    .bytes_0 = 0ull, .more_0 = NIM_NIL}
  ;
  if (l_0 <= IL64(0)){
    return result_101;}
  if (l_0 <= ((NI64)IL64(14))){
    (*((NU8*)(&result_101.bytes_0))) = ((NU8)l_0);
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&result_101.bytes_0)) + 1ull)))), ((void*)s_59), l_0);}
  else {
    void* X60Qx_170 = alloc_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + l_0)));
    LongString_0_sysvq0asl* p_23 = ((LongString_0_sysvq0asl*)X60Qx_170);
    if ((!(p_23 == NIM_NIL))){
      (*p_23).rc_0 = IL64(0);
      (*p_23).fullLen_0 = l_0;
      (*p_23).capImpl_0 = l_0;
      copyMem_0_sysvq0asl(((void*)(&(*p_23).data_0[IL64(0)])), ((void*)s_59), l_0);
      result_101.more_0 = p_23;
      (*((NU8*)(&result_101.bytes_0))) = ((NU8)((NI64)IL64(255)));
      copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&result_101.bytes_0)) + 1ull)))), ((void*)(&(*p_23).data_0[IL64(0)])), ((NI64)IL64(7)));}
    else {
      oomHandler_0_sysvq0asl(((NI64)(((NI64)IL64(24)) + l_0)));
      result_101.bytes_0 = ((NU64)21760775509248519ull);
      result_101.more_0 = NIM_NIL;}}
  return result_101;}
string_0_sysvq0asl nimBorrowCStringUnsafe(NC8* s_60){
  string_0_sysvq0asl result_102;
  nimStrWasMoved((&result_102));
  nimStrDestroy(result_102);
  NI64 X60Qx_171 = len_5_sysvq0asl(s_60);
  string_0_sysvq0asl X60Qx_172 = borrowCStringUnsafe_0_sysvq0asl(s_60, X60Qx_171);
  result_102 = X60Qx_172;
  return result_102;}
void ensureTerminatingZero_0_sysvq0asl(string_0_sysvq0asl* s_61){
  NI64 oldLen_3 = len_4_sysvq0asl((*s_61));
  add_1_sysvq0asl(s_61, (NC8)'\000');
  shrink_1_sysvq0asl(s_61, oldLen_3);}
NC8* toCString_0_sysvq0asl(string_0_sysvq0asl* s_62){
  NC8* result_103;
  ensureTerminatingZero_0_sysvq0asl(s_62);
  NC8* X60Qx_173 = rawData_1_sysvq0asl((&(*s_62)));
  result_103 = ((NC8*)X60Qx_173);
  return result_103;}
static inline openArray_0_Ijk0jkw1_has9tn57v toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_65){
  openArray_0_Ijk0jkw1_has9tn57v result_108;
  NC8* X60Qx_175 = readRawData_0_sysvq0asl((&(*s_65)), IL64(0));
  NI64 X60Qx_176 = len_4_sysvq0asl((*s_65));
  result_108 = (openArray_0_Ijk0jkw1_has9tn57v){
    .a_0 = X60Qx_175, .len_0 = X60Qx_176}
  ;
  return result_108;}
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0){
  NI64 X60Qx_177 = __atomic_add_fetch((&(*memLoc_0)), IL64(1), __ATOMIC_SEQ_CST);}
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1){
  NB8 result_118;
  NI64 X60Qx_178 = __atomic_sub_fetch((&(*memLoc_1)), IL64(1), __ATOMIC_SEQ_CST);
  result_118 = (X60Qx_178 < IL64(0));
  return result_118;}
static inline NB8 arcIsUnique_0_sysvq0asl(NI64* memLoc_2){
  NB8 result_119;
  NI64 X60Qx_179 = __atomic_load_n((&(*memLoc_2)), __ATOMIC_ACQUIRE);
  result_119 = (X60Qx_179 == IL64(0));
  return result_119;}
void writeErr_0_sysvq0asl(NI64 x_311){
  fprintf(stderr, "%lld", x_311);}
void writeErr_1_sysvq0asl(NU64 x_312){
  fprintf(stderr, "%llu", x_312);}
void writeErr_2_sysvq0asl(string_0_sysvq0asl s_66){
  NC8* X60Qx_180 = readRawData_0_sysvq0asl((&s_66), IL64(0));
  NI64 X60Qx_181 = len_4_sysvq0asl(s_66);
  NU64 X60Qx_182 = fwrite(((void*)X60Qx_180), 1ull, ((NU64)X60Qx_181), stderr);}
void writeErr_3_sysvq0asl(NC8* s_67){
  NI64 X60Qx_183 = len_5_sysvq0asl(s_67);
  NU64 X60Qx_184 = fwrite(((void*)s_67), 1ull, ((NU64)X60Qx_183), stderr);}
void panic_0_sysvq0asl(string_0_sysvq0asl s_68){
  writeErr_2_sysvq0asl(s_68);
  exit(((NI32)IL64(1)));}
static inline NI64 nimIcheckAB(NI64 i_18, NI64 a_32, NI64 b_18){
  NI64 result_120;
  NB8 X60Qx_185;
  if (a_32 <= i_18){
    X60Qx_185 = (i_18 <= b_18);}
  else {
    X60Qx_185 = NIM_FALSE;}
  if (X60Qx_185){
    result_120 = ((NI64)(i_18 - a_32));}
  else {
    result_120 = IL64(0);
    raiseIndexError3_0_Ice8haj1_sysvq0asl(i_18, a_32, b_18);}
  return result_120;}
static inline NI64 nimIcheckB(NI64 i_19, NI64 b_19){
  NI64 result_121;
  NB8 X60Qx_186;
  if (IL64(0) <= i_19){
    X60Qx_186 = (i_19 <= b_19);}
  else {
    X60Qx_186 = NIM_FALSE;}
  if (X60Qx_186){
    result_121 = i_19;}
  else {
    result_121 = IL64(0);
    raiseIndexError3_0_Ice8haj1_sysvq0asl(i_19, IL64(0), b_19);}
  return result_121;}
static inline NU64 nimUcheckAB(NU64 i_20, NU64 a_33, NU64 b_20){
  NU64 result_122;
  result_122 = ((NU64)(i_20 - a_33));
  if (b_20 < result_122){
    raiseIndexError3_0_Ils6gq61_sysvq0asl(i_20, a_33, b_20);}
  return result_122;}
static inline NU64 nimUcheckB(NU64 i_21, NU64 b_21){
  NU64 result_123;
  result_123 = i_21;
  if (b_21 < result_123){
    raiseIndexError3_0_Ils6gq61_sysvq0asl(i_21, ((NU64)IL64(0)), b_21);}
  return result_123;}
static inline void nimInvalidObjConv(string_0_sysvq0asl name_0){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 7235433442201987582ull, .more_0 = (&strlit_0_I15539159382304113184_sysvq0asl)}
  );
  writeErr_2_sysvq0asl(name_0);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561ull, .more_0 = NIM_NIL}
  );
  exit(((NI32)IL64(1)));}
static inline void nimChckNilDisp(void* p_15){
  if (p_15 == NIM_NIL){
    writeErr_2_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2338616626601092094ull, .more_0 = (&strlit_0_I14281474217946372742_sysvq0asl)}
    );
    exit(((NI32)IL64(1)));}}
void procAddrError_0_sysvq0asl(NC8* name_1){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 7935452960416293886ull, .more_0 = (&strlit_0_I10604297744791418982_sysvq0asl)}
  );
  writeErr_3_sysvq0asl(name_1);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561ull, .more_0 = NIM_NIL}
  );
  exit(((NI32)IL64(1)));}
void* nimLoadLibrary(NC8* path_2){
  void* result_124;
  int flags_0 = ((NI32)IL64(2));
  void* X60Qx_187 = dlopen(path_2, flags_0);
  result_124 = X60Qx_187;
  return result_124;}
void* nimGetProcAddr(void* lib_3, NC8* name_3){
  void* result_125;
  void* X60Qx_188 = dlsym(lib_3, name_3);
  result_125 = X60Qx_188;
  if (result_125 == NIM_NIL){
    procAddrError_0_sysvq0asl(name_3);}
  return result_125;}
void* nimDynlibLoadStep(void* prev_0, NC8* cand_0){
  void* result_126;
  if ((!(prev_0 == NIM_NIL))){
    result_126 = prev_0;}
  else {
    void* X60Qx_189 = nimLoadLibrary(cand_0);
    result_126 = X60Qx_189;}
  return result_126;}
void* nimDynlibCheck(void* lib_4, NC8* path_3){
  void* result_127;
  if (lib_4 == NIM_NIL){
    writeErr_2_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 7935452960416293886ull, .more_0 = (&strlit_0_I16690852185662743073_sysvq0asl)}
    );
    writeErr_3_sysvq0asl(path_3);
    writeErr_2_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 2561ull, .more_0 = NIM_NIL}
    );
    exit(((NI32)IL64(1)));}
  result_127 = lib_4;
  return result_127;}
static inline NC8 chr_0_sysvq0asl(NI64 u_0){
  NC8 result_130;
  result_130 = ((NC8)((NI64)u_0));
  return result_130;}
static inline void utoa2Digits_0_sysvq0asl(openArray_0_Ijk0jkw1_has9tn57v buf_1, NI64 pos_0, NU32 digits_0){
  NI64 X60Qx_191 = nimIcheckB(((NI64)((NU32)(((NU32)IL64(2)) * digits_0))), IL64(199));
  putQ_10_If2353w_sysvq0asl(buf_1, pos_0, digits100_0_sysvq0asl.a[X60Qx_191]);
  NI64 X60Qx_192 = nimIcheckB(((NI64)((NU32)(((NU32)(((NU32)IL64(2)) * digits_0)) + ((NU32)IL64(1))))), IL64(199));
  putQ_10_If2353w_sysvq0asl(buf_1, ((NI64)(pos_0 + IL64(1))), digits100_0_sysvq0asl.a[X60Qx_192]);}
static inline NI64 trailingZeros2Digits_0_sysvq0asl(NU32 digits_1){
  NI64 result_131;
  NI64 X60Qx_193 = nimIcheckB(((NI64)digits_1), IL64(99));
  result_131 = ((NI64)trailingZeros100_0_sysvq0asl.a[X60Qx_193]);
  return result_131;}
Double_0_sysvq0asl constructDouble_0_sysvq0asl(NF64 value_3){
  Double_0_sysvq0asl result_148;
  NU64 X60Qx_220;
  copyMem_0_sysvq0asl((&X60Qx_220), (&value_3), sizeof(NU64));
  result_148 = (Double_0_sysvq0asl){
    .bits_0 = X60Qx_220}
  ;
  return result_148;}
NU64 physicalSignificand_1_sysvq0asl(Double_0_sysvq0asl this_3){
  NU64 result_149;
  result_149 = ((NU64)(this_3.bits_0 & ((NU64)4503599627370495ull)));
  return result_149;}
NU64 physicalExponent_1_sysvq0asl(Double_0_sysvq0asl this_4){
  NU64 result_150;
  result_150 = ((NU64)(((NU64)(this_4.bits_0 & ((NU64)9218868437227405312ull))) >> ((NI64)(((NI64)IL64(53)) - IL64(1)))));
  return result_150;}
NI64 signBit_1_sysvq0asl(Double_0_sysvq0asl this_5){
  NI64 result_151;
  result_151 = ((NI64)(!(((NU64)(this_5.bits_0 & ((NU64)9223372036854775808ull))) == ((NU64)IL64(0)))));
  return result_151;}
static inline NI64 dbFloorDivPow2_0_sysvq0asl(NI64 x_323, NI64 n_6){
  NI64 result_152;
  result_152 = ((NI64)(((NI64)x_323) >> ((NU64)n_6)));
  return result_152;}
static inline NI64 dbFloorLog2Pow10_0_sysvq0asl(NI64 e_2){
  NI64 result_153;
  NI64 X60Qx_221 = dbFloorDivPow2_0_sysvq0asl(((NI64)(e_2 * IL64(1741647))), IL64(19));
  result_153 = X60Qx_221;
  return result_153;}
static inline NI64 dbFloorLog10Pow2_0_sysvq0asl(NI64 e_3){
  NI64 result_154;
  NI64 X60Qx_222 = dbFloorDivPow2_0_sysvq0asl(((NI64)(e_3 * IL64(1262611))), IL64(22));
  result_154 = X60Qx_222;
  return result_154;}
static inline NI64 dbFloorLog10ThreeQQuartersPow2_0_sysvq0asl(NI64 e_4){
  NI64 result_155;
  NI64 X60Qx_223 = dbFloorDivPow2_0_sysvq0asl(((NI64)(((NI64)(e_4 * IL64(1262611))) - IL64(524031))), IL64(22));
  result_155 = X60Qx_223;
  return result_155;}
static inline uint64x2_0_sysvq0asl computePow10_0_sysvq0asl(NI64 k_1){
  uint64x2_0_sysvq0asl result_156;
  NI64 X60Qx_224 = nimIcheckB(((NI64)(k_1 - ((NI64)IL64(-292)))), IL64(618));
  result_156 = pow10_3.a[X60Qx_224];
  return result_156;}
static inline NB8 multipleOfPow2_1_sysvq0asl(NU64 value_4, NI64 e2_1){
  NB8 result_157;
  NB8 X60Qx_225;
  if (e2_1 < IL64(64)){
    X60Qx_225 = (((NU64)(value_4 & ((NU64)(((NU64)(((NU64)IL64(1)) << e2_1)) - ((NU64)IL64(1)))))) == ((NU64)IL64(0)));}
  else {
    X60Qx_225 = NIM_FALSE;}
  result_157 = X60Qx_225;
  return result_157;}
static inline NB8 multipleOfPow5_0_sysvq0asl(NU64 value_5, NI64 e5_0){
  NB8 result_158;
  NI64 X60Qx_226 = nimIcheckB(e5_0, IL64(24));
  MulCmp_0_sysvq0asl m5_0 = mod5_0.a[X60Qx_226];
  result_158 = (((NU64)(value_5 * m5_0.mul_0)) <= m5_0.cmp_0);
  return result_158;}
static inline FloatingDecimal64_0_sysvq0asl toDecimal64AsymmetricInterval_0_sysvq0asl(NI64 e2_2){
  FloatingDecimal64_0_sysvq0asl result_159;
  NI64 minusK_2 = dbFloorLog10ThreeQQuartersPow2_0_sysvq0asl(e2_2);
  NI64 X60Qx_227 = dbFloorLog2Pow10_0_sysvq0asl(((NI64)-minusK_2));
  NI64 betaMinus1_2 = ((NI64)(e2_2 + X60Qx_227));
  uint64x2_0_sysvq0asl pow10_4 = computePow10_0_sysvq0asl(((NI64)-minusK_2));
  NU64 lowerEndpoint_0 = ((NU64)(((NU64)(pow10_4.hi_0 - ((NU64)(pow10_4.hi_0 >> ((NI64)(((NI64)IL64(53)) + IL64(1))))))) >> ((NI64)(((NI64)(IL64(64) - ((NI64)IL64(53)))) - betaMinus1_2))));
  NU64 upperEndpoint_0 = ((NU64)(((NU64)(pow10_4.hi_0 + ((NU64)(pow10_4.hi_0 >> ((NI64)(((NI64)IL64(53)) + IL64(0))))))) >> ((NI64)(((NI64)(IL64(64) - ((NI64)IL64(53)))) - betaMinus1_2))));
  NB8 X60Qx_228;
  if (IL64(2) <= e2_2){
    X60Qx_228 = (e2_2 <= IL64(3));}
  else {
    X60Qx_228 = NIM_FALSE;}
  NB8 lowerEndpointIsInteger_0 = X60Qx_228;
  NU64 xi_0 = ((NU64)(lowerEndpoint_0 + ((NU64)(!lowerEndpointIsInteger_0))));
  NU64 zi_0 = upperEndpoint_0;
  NU64 q_5 = ((NU64)(zi_0 / ((NU64)IL64(10))));
  if (xi_0 <= ((NU64)(q_5 * ((NU64)IL64(10))))){
    result_159 = (FloatingDecimal64_0_sysvq0asl){
      .significand_0 = q_5, .exponent_0 = ((NI64)(minusK_2 + IL64(1)))}
    ;
    return result_159;}
  q_5 = ((NU64)(((NU64)(((NU64)(pow10_4.hi_0 >> ((NI64)(((NI64)(IL64(64) - ((NI64)(((NI64)IL64(53)) + IL64(1))))) - betaMinus1_2)))) + ((NU64)IL64(1)))) / ((NU64)IL64(2))));
  if (e2_2 == IL64(-77)){
    dec_0_Idgnuqw1_sysvq0asl((&q_5), ((NU64)((NI64)(!(((NU64)(q_5 % ((NU64)IL64(2)))) == ((NU64)IL64(0)))))));}
  else {
    inc_0_Ineawm41_party5a2l1((&q_5), ((NU64)((NI64)(q_5 < xi_0))));}
  result_159 = (FloatingDecimal64_0_sysvq0asl){
    .significand_0 = q_5, .exponent_0 = minusK_2}
  ;
  return result_159;}
static inline NU32 computeDelta_0_sysvq0asl(uint64x2_0_sysvq0asl pow10_0, NI64 betaMinus1_0){
  NU32 result_160;
  result_160 = ((NU32)((NU64)(pow10_0.hi_0 >> ((NI64)(((NI64)(IL64(64) - IL64(1))) - betaMinus1_0)))));
  return result_160;}
static inline NU32 dbLo32_0_sysvq0asl(NU64 x_324){
  NU32 result_161;
  result_161 = ((NU32)x_324);
  return result_161;}
static inline NU32 dbHi32_0_sysvq0asl(NU64 x_325){
  NU32 result_162;
  result_162 = ((NU32)((NU64)(x_325 >> IL64(32))));
  return result_162;}
static inline uint64x2_0_sysvq0asl mul128_0_sysvq0asl(NU64 a_34, NU64 b_22){
  uint64x2_0_sysvq0asl result_163;
  NU32 X60Qx_229 = dbLo32_0_sysvq0asl(a_34);
  NU32 X60Qx_230 = dbLo32_0_sysvq0asl(b_22);
  NU64 b00_0 = ((NU64)(((NU64)X60Qx_229) * ((NU64)X60Qx_230)));
  NU32 X60Qx_231 = dbLo32_0_sysvq0asl(a_34);
  NU32 X60Qx_232 = dbHi32_0_sysvq0asl(b_22);
  NU64 b01_1 = ((NU64)(((NU64)X60Qx_231) * ((NU64)X60Qx_232)));
  NU32 X60Qx_233 = dbHi32_0_sysvq0asl(a_34);
  NU32 X60Qx_234 = dbLo32_0_sysvq0asl(b_22);
  NU64 b10_0 = ((NU64)(((NU64)X60Qx_233) * ((NU64)X60Qx_234)));
  NU32 X60Qx_235 = dbHi32_0_sysvq0asl(a_34);
  NU32 X60Qx_236 = dbHi32_0_sysvq0asl(b_22);
  NU64 b11_1 = ((NU64)(((NU64)X60Qx_235) * ((NU64)X60Qx_236)));
  NU32 X60Qx_237 = dbHi32_0_sysvq0asl(b00_0);
  NU64 mid1_0 = ((NU64)(b10_0 + ((NU64)X60Qx_237)));
  NU32 X60Qx_238 = dbLo32_0_sysvq0asl(mid1_0);
  NU64 mid2_0 = ((NU64)(b01_1 + ((NU64)X60Qx_238)));
  NU32 X60Qx_239 = dbHi32_0_sysvq0asl(mid1_0);
  NU32 X60Qx_240 = dbHi32_0_sysvq0asl(mid2_0);
  NU64 hi_1 = ((NU64)(((NU64)(b11_1 + ((NU64)X60Qx_239))) + ((NU64)X60Qx_240)));
  NU32 X60Qx_241 = dbLo32_0_sysvq0asl(b00_0);
  NU32 X60Qx_242 = dbLo32_0_sysvq0asl(mid2_0);
  NU64 lo_0 = ((NU64)(((NU64)X60Qx_241) | ((NU64)(((NU64)X60Qx_242) << IL64(32)))));
  result_163 = (uint64x2_0_sysvq0asl){
    .hi_0 = hi_1, .lo_0 = lo_0}
  ;
  return result_163;}
static inline NU64 mulShift_0_sysvq0asl(NU64 x_326, uint64x2_0_sysvq0asl y_197){
  NU64 result_164;
  uint64x2_0_sysvq0asl p1_0 = mul128_0_sysvq0asl(x_326, y_197.hi_0);
  uint64x2_0_sysvq0asl p0_0 = mul128_0_sysvq0asl(x_326, y_197.lo_0);
  plusQeQ_0_Iar0t5x_sysvq0asl((&p1_0.lo_0), p0_0.hi_0);
  inc_0_Ineawm41_party5a2l1((&p1_0.hi_0), ((NU64)((NI64)(p1_0.lo_0 < p0_0.hi_0))));
  result_164 = p1_0.hi_0;
  return result_164;}
static inline NB8 mulParity_0_sysvq0asl(NU64 twoF_0, uint64x2_0_sysvq0asl pow10_1, NI64 betaMinus1_1){
  NB8 result_165;
  NU64 p01_0 = ((NU64)(twoF_0 * pow10_1.hi_0));
  uint64x2_0_sysvq0asl X60Qx_243 = mul128_0_sysvq0asl(twoF_0, pow10_1.lo_0);
  NU64 p10_0 = X60Qx_243.hi_0;
  NU64 mid_1 = ((NU64)(p01_0 + p10_0));
  result_165 = (!(((NU64)(mid_1 & ((NU64)(((NU64)IL64(1)) << ((NI64)(IL64(64) - betaMinus1_1)))))) == ((NU64)IL64(0))));
  return result_165;}
static inline NB8 isIntegralEndpoint_0_sysvq0asl(NU64 twoF_1, NI64 e2_3, NI64 minusK_0){
  NB8 result_166;
  if (e2_3 < IL64(-2)){
    return NIM_FALSE;}
  if (e2_3 <= IL64(9)){
    return NIM_TRUE;}
  if (e2_3 <= IL64(86)){
    NB8 X60Qx_244 = multipleOfPow5_0_sysvq0asl(twoF_1, minusK_0);
    result_166 = X60Qx_244;
    return result_166;}
  result_166 = NIM_FALSE;
  return result_166;}
static inline NB8 isIntegralMidpoint_0_sysvq0asl(NU64 twoF_2, NI64 e2_4, NI64 minusK_1){
  NB8 result_167;
  if (e2_4 < IL64(-4)){
    NB8 X60Qx_245 = multipleOfPow2_1_sysvq0asl(twoF_2, ((NI64)(((NI64)(minusK_1 - e2_4)) + IL64(1))));
    result_167 = X60Qx_245;
    return result_167;}
  if (e2_4 <= IL64(9)){
    return NIM_TRUE;}
  if (e2_4 <= IL64(86)){
    NB8 X60Qx_246 = multipleOfPow5_0_sysvq0asl(twoF_2, minusK_1);
    result_167 = X60Qx_246;
    return result_167;}
  result_167 = NIM_FALSE;
  return result_167;}
FloatingDecimal64_0_sysvq0asl toDecimal64_0_sysvq0asl(NU64 ieeeSignificand_1, NU64 ieeeExponent_1){
  FloatingDecimal64_0_sysvq0asl result_168;
  NU64 m2_0;
  NI64 e2_5;
  if ((!(ieeeExponent_1 == ((NU64)IL64(0))))){
    m2_0 = ((NU64)(((NU64)4503599627370496ull) | ieeeSignificand_1));
    e2_5 = ((NI64)(((NI64)ieeeExponent_1) - ((NI64)IL64(1075))));
    NB8 X60Qx_247;
    NB8 X60Qx_248;
    if (IL64(0) <= ((NI64)-e2_5)){
      X60Qx_248 = (((NI64)-e2_5) < ((NI64)IL64(53)));}
    else {
      X60Qx_248 = NIM_FALSE;}
    if (X60Qx_248){
      NB8 X60Qx_249 = multipleOfPow2_1_sysvq0asl(m2_0, ((NI64)-e2_5));
      X60Qx_247 = X60Qx_249;}
    else {
      X60Qx_247 = NIM_FALSE;}
    if (X60Qx_247){
      result_168 = (FloatingDecimal64_0_sysvq0asl){
        .significand_0 = ((NU64)(m2_0 >> ((NI64)-e2_5))), .exponent_0 = IL64(0)}
      ;
      return result_168;}
    NB8 X60Qx_250;
    if (ieeeSignificand_1 == ((NU64)IL64(0))){
      X60Qx_250 = (((NU64)IL64(1)) < ieeeExponent_1);}
    else {
      X60Qx_250 = NIM_FALSE;}
    if (X60Qx_250){
      FloatingDecimal64_0_sysvq0asl X60Qx_251 = toDecimal64AsymmetricInterval_0_sysvq0asl(e2_5);
      result_168 = X60Qx_251;
      return result_168;}}
  else {
    m2_0 = ieeeSignificand_1;
    e2_5 = ((NI64)(IL64(1) - ((NI64)IL64(1075))));}
  NB8 isEven_1 = (((NU64)(m2_0 % ((NU64)IL64(2)))) == ((NU64)IL64(0)));
  NB8 acceptLower_0 = isEven_1;
  NB8 acceptUpper_0 = isEven_1;
  NI64 X60Qx_252 = dbFloorLog10Pow2_0_sysvq0asl(e2_5);
  NI64 minusK_3 = ((NI64)(X60Qx_252 - ((NI64)IL64(2))));
  NI64 X60Qx_253 = dbFloorLog2Pow10_0_sysvq0asl(((NI64)-minusK_3));
  NI64 betaMinus1_3 = ((NI64)(e2_5 + X60Qx_253));
  uint64x2_0_sysvq0asl pow10_5 = computePow10_0_sysvq0asl(((NI64)-minusK_3));
  NU32 delta_0 = computeDelta_0_sysvq0asl(pow10_5, betaMinus1_3);
  NU64 twoFl_0 = ((NU64)(((NU64)(((NU64)IL64(2)) * m2_0)) - ((NU64)IL64(1))));
  NU64 twoFc_0 = ((NU64)(((NU64)IL64(2)) * m2_0));
  NU64 twoFr_0 = ((NU64)(((NU64)(((NU64)IL64(2)) * m2_0)) + ((NU64)IL64(1))));
  NU64 zi_1 = mulShift_0_sysvq0asl(((NU64)(twoFr_0 << betaMinus1_3)), pow10_5);
  NU64 q_6 = ((NU64)(zi_1 / ((NU64)((NU32)1000ull))));
  NU32 r_2 = ((NU32)(((NU32)zi_1) - ((NU32)(((NU32)1000ull) * ((NU32)q_6)))));
  if (r_2 < delta_0){
    NB8 X60Qx_254;
    NB8 X60Qx_255;
    if ((!(r_2 == ((NU32)IL64(0))))){
      X60Qx_255 = NIM_TRUE;}
    else {
      X60Qx_255 = acceptUpper_0;}
    if (X60Qx_255){
      X60Qx_254 = NIM_TRUE;}
    else {
      NB8 X60Qx_256 = isIntegralEndpoint_0_sysvq0asl(twoFr_0, e2_5, minusK_3);
      X60Qx_254 = (!X60Qx_256);}
    if (X60Qx_254){
      result_168 = (FloatingDecimal64_0_sysvq0asl){
        .significand_0 = q_6, .exponent_0 = ((NI64)(((NI64)(minusK_3 + ((NI64)IL64(2)))) + IL64(1)))}
      ;
      return result_168;}
    dec_1_Ifi4w3m1_sysvq0asl((&q_6));
    r_2 = ((NU32)1000ull);}
  else {
    if (r_2 == delta_0){
      NB8 X60Qx_257;
      NB8 X60Qx_258;
      if (acceptLower_0){
        NB8 X60Qx_259 = isIntegralEndpoint_0_sysvq0asl(twoFl_0, e2_5, minusK_3);
        X60Qx_258 = X60Qx_259;}
      else {
        X60Qx_258 = NIM_FALSE;}
      if (X60Qx_258){
        X60Qx_257 = NIM_TRUE;}
      else {
        NB8 X60Qx_260 = mulParity_0_sysvq0asl(twoFl_0, pow10_5, betaMinus1_3);
        X60Qx_257 = X60Qx_260;}
      if (X60Qx_257){
        result_168 = (FloatingDecimal64_0_sysvq0asl){
          .significand_0 = q_6, .exponent_0 = ((NI64)(((NI64)(minusK_3 + ((NI64)IL64(2)))) + IL64(1)))}
        ;
        return result_168;}}
    else {
      }}
  q_6 = ((NU64)(q_6 * ((NU64)IL64(10))));
  NU32 dist_0 = ((NU32)(((NU32)(r_2 - ((NU32)(delta_0 / ((NU32)IL64(2)))))) + ((NU32)(((NU32)100ull) / ((NU32)IL64(2))))));
  NU32 distQQ_0 = ((NU32)(dist_0 / ((NU32)IL64(100))));
  plusQeQ_0_Iar0t5x_sysvq0asl((&q_6), ((NU64)distQQ_0));
  if (dist_0 == ((NU32)(distQQ_0 * ((NU32)IL64(100))))){
    NB8 approxYParity_0 = (!(((NU32)(dist_0 & ((NU32)IL64(1)))) == ((NU32)IL64(0))));
    NB8 X60Qx_261 = mulParity_0_sysvq0asl(twoFc_0, pow10_5, betaMinus1_3);
    if ((!(X60Qx_261 == approxYParity_0))){
      dec_1_Ifi4w3m1_sysvq0asl((&q_6));}
    else {
      NB8 X60Qx_262;
      if ((!(((NU64)(q_6 % ((NU64)IL64(2)))) == ((NU64)IL64(0))))){
        NB8 X60Qx_263 = isIntegralMidpoint_0_sysvq0asl(twoFc_0, e2_5, minusK_3);
        X60Qx_262 = X60Qx_263;}
      else {
        X60Qx_262 = NIM_FALSE;}
      if (X60Qx_262){
        dec_1_Ifi4w3m1_sysvq0asl((&q_6));}}}
  result_168 = (FloatingDecimal64_0_sysvq0asl){
    .significand_0 = q_6, .exponent_0 = ((NI64)(minusK_3 + ((NI64)IL64(2))))}
  ;
  return result_168;}
static inline NI64 utoa8DigitsSkipTrailingZeros_0_sysvq0asl(openArray_0_Ijk0jkw1_has9tn57v buf_3, NI64 pos_3, NU32 digits_3){
  NI64 result_169;
  NU32 q_7 = ((NU32)(digits_3 / ((NU32)IL64(10000))));
  NU32 r_3 = ((NU32)(digits_3 % ((NU32)IL64(10000))));
  NU32 qH_0 = ((NU32)(q_7 / ((NU32)IL64(100))));
  NU32 qL_0 = ((NU32)(q_7 % ((NU32)IL64(100))));
  utoa2Digits_0_sysvq0asl(buf_3, pos_3, qH_0);
  utoa2Digits_0_sysvq0asl(buf_3, ((NI64)(pos_3 + IL64(2))), qL_0);
  if (r_3 == ((NU32)IL64(0))){
    NU32 X60Qx_38;
    if (qL_0 == ((NU32)IL64(0))){
      X60Qx_38 = qH_0;}
    else {
      X60Qx_38 = qL_0;}
    NI64 X60Qx_39;
    if (qL_0 == ((NU32)IL64(0))){
      X60Qx_39 = IL64(6);}
    else {
      X60Qx_39 = IL64(4);}
    NI64 X60Qx_264 = trailingZeros2Digits_0_sysvq0asl(X60Qx_38);
    result_169 = ((NI64)(X60Qx_264 + X60Qx_39));}
  else {
    NU32 rH_1 = ((NU32)(r_3 / ((NU32)IL64(100))));
    NU32 rL_1 = ((NU32)(r_3 % ((NU32)IL64(100))));
    utoa2Digits_0_sysvq0asl(buf_3, ((NI64)(pos_3 + IL64(4))), rH_1);
    utoa2Digits_0_sysvq0asl(buf_3, ((NI64)(pos_3 + IL64(6))), rL_1);
    NU32 X60Qx_40;
    if (rL_1 == ((NU32)IL64(0))){
      X60Qx_40 = rH_1;}
    else {
      X60Qx_40 = rL_1;}
    NI64 X60Qx_41;
    if (rL_1 == ((NU32)IL64(0))){
      X60Qx_41 = IL64(2);}
    else {
      X60Qx_41 = IL64(0);}
    NI64 X60Qx_265 = trailingZeros2Digits_0_sysvq0asl(X60Qx_40);
    result_169 = ((NI64)(X60Qx_265 + X60Qx_41));}
  return result_169;}
static inline NI64 printDecimalDigitsBackwards_1_sysvq0asl(openArray_0_Ijk0jkw1_has9tn57v buf_4, NI64 pos_4, NU64 output64_0){
  NI64 result_170;
  NI64 pos_9 = pos_4;
  NU64 output64_1 = output64_0;
  NI64 tz_2 = IL64(0);
  NI64 nd_1 = IL64(0);
  if (((NU64)100000000ull) <= output64_1){
    NU64 q_8 = ((NU64)(output64_1 / ((NU64)100000000ull)));
    NU32 r_4 = ((NU32)((NU64)(output64_1 % ((NU64)100000000ull))));
    output64_1 = q_8;
    dec_0_Iw9ew8i1_ospaexnw61((&pos_9), IL64(8));
    if ((!(r_4 == ((NU32)IL64(0))))){
      NI64 X60Qx_266 = utoa8DigitsSkipTrailingZeros_0_sysvq0asl(buf_4, pos_9, r_4);
      tz_2 = X60Qx_266;}
    else {
      tz_2 = IL64(8);}
    nd_1 = IL64(8);}
  NU32 output_2 = ((NU32)output64_1);
  if (((NU32)IL64(10000)) <= output_2){
    NU32 q_9 = ((NU32)(output_2 / ((NU32)IL64(10000))));
    NU32 r_5 = ((NU32)(output_2 % ((NU32)IL64(10000))));
    output_2 = q_9;
    dec_0_Iw9ew8i1_ospaexnw61((&pos_9), IL64(4));
    if ((!(r_5 == ((NU32)IL64(0))))){
      NU32 rH_2 = ((NU32)(r_5 / ((NU32)IL64(100))));
      NU32 rL_2 = ((NU32)(r_5 % ((NU32)IL64(100))));
      utoa2Digits_0_sysvq0asl(buf_4, pos_9, rH_2);
      utoa2Digits_0_sysvq0asl(buf_4, ((NI64)(pos_9 + IL64(2))), rL_2);
      if (tz_2 == nd_1){
        NU32 X60Qx_42;
        if (rL_2 == ((NU32)IL64(0))){
          X60Qx_42 = rH_2;}
        else {
          X60Qx_42 = rL_2;}
        NI64 X60Qx_43;
        if (rL_2 == ((NU32)IL64(0))){
          X60Qx_43 = IL64(2);}
        else {
          X60Qx_43 = IL64(0);}
        NI64 X60Qx_267 = trailingZeros2Digits_0_sysvq0asl(X60Qx_42);
        inc_0_Iwdk9lf_party5a2l1((&tz_2), ((NI64)(X60Qx_267 + X60Qx_43)));}}
    else {
      if (tz_2 == nd_1){
        inc_0_Iwdk9lf_party5a2l1((&tz_2), IL64(4));}
      else {
        {
          NI64 X60Qlf_10 = IL64(0);
          NI64 X60Qlf_11 = IL64(3);
          NI64 X60Qlf_12 = X60Qlf_10;
          {
            while (X60Qlf_12 <= X60Qlf_11){
              {
                putQ_10_If2353w_sysvq0asl(buf_4, ((NI64)(pos_9 + X60Qlf_12)), (NC8)'0');}
              inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_12));}}
          whileStmtLabel_1: ;}
        forStmtLabel_0: ;}}
    inc_0_Iwdk9lf_party5a2l1((&nd_1), IL64(4));}
  if (((NU32)IL64(100)) <= output_2){
    NU32 q_10 = ((NU32)(output_2 / ((NU32)IL64(100))));
    NU32 r_6 = ((NU32)(output_2 % ((NU32)IL64(100))));
    output_2 = q_10;
    dec_0_Iw9ew8i1_ospaexnw61((&pos_9), IL64(2));
    utoa2Digits_0_sysvq0asl(buf_4, pos_9, r_6);
    if (tz_2 == nd_1){
      NI64 X60Qx_268 = trailingZeros2Digits_0_sysvq0asl(r_6);
      inc_0_Iwdk9lf_party5a2l1((&tz_2), X60Qx_268);}
    inc_0_Iwdk9lf_party5a2l1((&nd_1), IL64(2));
    if (((NU32)IL64(100)) <= output_2){
      NU32 q2_1 = ((NU32)(output_2 / ((NU32)IL64(100))));
      NU32 r2_1 = ((NU32)(output_2 % ((NU32)IL64(100))));
      output_2 = q2_1;
      dec_0_Iw9ew8i1_ospaexnw61((&pos_9), IL64(2));
      utoa2Digits_0_sysvq0asl(buf_4, pos_9, r2_1);
      if (tz_2 == nd_1){
        NI64 X60Qx_269 = trailingZeros2Digits_0_sysvq0asl(r2_1);
        inc_0_Iwdk9lf_party5a2l1((&tz_2), X60Qx_269);}
      inc_0_Iwdk9lf_party5a2l1((&nd_1), IL64(2));}}
  if (((NU32)IL64(10)) <= output_2){
    NU32 q_11 = output_2;
    dec_0_Iw9ew8i1_ospaexnw61((&pos_9), IL64(2));
    utoa2Digits_0_sysvq0asl(buf_4, pos_9, q_11);
    if (tz_2 == nd_1){
      NI64 X60Qx_270 = trailingZeros2Digits_0_sysvq0asl(q_11);
      inc_0_Iwdk9lf_party5a2l1((&tz_2), X60Qx_270);}}
  else {
    NU32 q_12 = output_2;
    dec_1_I2mwrey1_envto7w6l1((&pos_9));
    NC8 X60Qx_271 = chr_0_sysvq0asl(((NI64)(((NI64)(NC8)'0') + ((NI64)q_12))));
    putQ_10_If2353w_sysvq0asl(buf_4, pos_9, X60Qx_271);}
  result_170 = tz_2;
  return result_170;}
static inline NI64 decimalLength_1_sysvq0asl(NU64 v_3){
  NI64 result_171;
  if ((!(((NU32)((NU64)(v_3 >> IL64(32)))) == ((NU32)IL64(0))))){
    if (((NU64)10000000000000000ull) <= v_3){
      return IL64(17);}
    if (((NU64)1000000000000000ull) <= v_3){
      return IL64(16);}
    if (((NU64)100000000000000ull) <= v_3){
      return IL64(15);}
    if (((NU64)10000000000000ull) <= v_3){
      return IL64(14);}
    if (((NU64)1000000000000ull) <= v_3){
      return IL64(13);}
    if (((NU64)100000000000ull) <= v_3){
      return IL64(12);}
    if (((NU64)10000000000ull) <= v_3){
      return IL64(11);}
    return IL64(10);}
  NU32 v32_0 = ((NU32)v_3);
  if (((NU32)1000000000ull) <= v32_0){
    return IL64(10);}
  if (((NU32)100000000ull) <= v32_0){
    return IL64(9);}
  if (((NU32)10000000ull) <= v32_0){
    return IL64(8);}
  if (((NU32)1000000ull) <= v32_0){
    return IL64(7);}
  if (((NU32)100000ull) <= v32_0){
    return IL64(6);}
  if (((NU32)10000ull) <= v32_0){
    return IL64(5);}
  if (((NU32)1000ull) <= v32_0){
    return IL64(4);}
  if (((NU32)100ull) <= v32_0){
    return IL64(3);}
  if (((NU32)10ull) <= v32_0){
    return IL64(2);}
  result_171 = IL64(1);
  return result_171;}
static inline NI64 formatDigits_1_sysvq0asl(openArray_0_Ijk0jkw1_has9tn57v buffer_2, NI64 pos_5, NU64 digits_4, NI64 decimalExponent_1, NB8 forceTrailingDotZero_2){
  NI64 result_172;
  NI64 pos_10 = pos_5;
  NI64 numDigits_1 = decimalLength_1_sysvq0asl(digits_4);
  NI64 decimalPoint_1 = ((NI64)(numDigits_1 + decimalExponent_1));
  NB8 X60Qx_272;
  if (((NI64)IL64(-6)) <= decimalPoint_1){
    X60Qx_272 = (decimalPoint_1 <= ((NI64)IL64(17)));}
  else {
    X60Qx_272 = NIM_FALSE;}
  NB8 useFixed_1 = X60Qx_272;
  {
    NI64 X60Qlf_13 = IL64(0);
    NI64 X60Qlf_14 = IL64(32);
    NI64 X60Qlf_15 = X60Qlf_13;
    {
      while (X60Qlf_15 < X60Qlf_14){
        {
          putQ_10_If2353w_sysvq0asl(buffer_2, ((NI64)(pos_10 + X60Qlf_15)), (NC8)'0');}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_15));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  NI64 decimalDigitsPosition_1;
  if (useFixed_1){
    if (decimalPoint_1 <= IL64(0)){
      decimalDigitsPosition_1 = ((NI64)(IL64(2) - decimalPoint_1));}
    else {
      decimalDigitsPosition_1 = IL64(0);}}
  else {
    decimalDigitsPosition_1 = IL64(1);}
  NI64 digitsEnd_1 = ((NI64)(((NI64)(pos_10 + decimalDigitsPosition_1)) + numDigits_1));
  NI64 tz_3 = printDecimalDigitsBackwards_1_sysvq0asl(buffer_2, digitsEnd_1, digits_4);
  dec_0_Iw9ew8i1_ospaexnw61((&digitsEnd_1), tz_3);
  dec_0_Iw9ew8i1_ospaexnw61((&numDigits_1), tz_3);
  if (useFixed_1){
    if (decimalPoint_1 <= IL64(0)){
      putQ_10_If2353w_sysvq0asl(buffer_2, ((NI64)(pos_10 + IL64(1))), (NC8)'.');
      pos_10 = digitsEnd_1;}
    else {
      if (decimalPoint_1 < numDigits_1){
        X60Qt_0_IAarrayAcS8ZS16_sysvq0asl tmp_2 = default_23_Imn3jdi_sysvq0asl();
        {
          NI64 X60Qlf_16 = IL64(0);
          NI64 X60Qlf_17 = IL64(16);
          NI64 X60Qlf_18 = X60Qlf_16;
          {
            while (X60Qlf_18 < X60Qlf_17){
              {
                NI64 X60Qx_273 = nimIcheckB(X60Qlf_18, IL64(15));
                NC8* X60Qx_274 = getQ_10_I5nt6we_has9tn57v(buffer_2, ((NI64)(((NI64)(X60Qlf_18 + pos_10)) + decimalPoint_1)));
                tmp_2.a[X60Qx_273] = (*X60Qx_274);}
              inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_18));}}
          whileStmtLabel_3: ;}
        forStmtLabel_2: ;
        {
          NI64 X60Qlf_19 = IL64(0);
          NI64 X60Qlf_20 = IL64(16);
          NI64 X60Qlf_21 = X60Qlf_19;
          {
            while (X60Qlf_21 < X60Qlf_20){
              {
                NI64 X60Qx_275 = nimIcheckB(X60Qlf_21, IL64(15));
                putQ_10_If2353w_sysvq0asl(buffer_2, ((NI64)(((NI64)(((NI64)(X60Qlf_21 + pos_10)) + decimalPoint_1)) + IL64(1))), tmp_2.a[X60Qx_275]);}
              inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_21));}}
          whileStmtLabel_5: ;}
        forStmtLabel_4: ;
        putQ_10_If2353w_sysvq0asl(buffer_2, ((NI64)(pos_10 + decimalPoint_1)), (NC8)'.');
        pos_10 = ((NI64)(digitsEnd_1 + IL64(1)));}
      else {
        inc_0_Iwdk9lf_party5a2l1((&pos_10), decimalPoint_1);
        if (forceTrailingDotZero_2){
          putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, (NC8)'.');
          putQ_10_If2353w_sysvq0asl(buffer_2, ((NI64)(pos_10 + IL64(1))), (NC8)'0');
          inc_0_Iwdk9lf_party5a2l1((&pos_10), IL64(2));}}}}
  else {
    NC8* X60Qx_276 = getQ_10_I5nt6we_has9tn57v(buffer_2, ((NI64)(pos_10 + IL64(1))));
    putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, (*X60Qx_276));
    if (numDigits_1 == IL64(1)){
      inc_1_Irn1g7r1_aif7a4qfr((&pos_10));}
    else {
      putQ_10_If2353w_sysvq0asl(buffer_2, ((NI64)(pos_10 + IL64(1))), (NC8)'.');
      pos_10 = digitsEnd_1;}
    NI64 scientificExponent_1 = ((NI64)(decimalPoint_1 - IL64(1)));
    putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, (NC8)'e');
    NC8 X60Qx_44;
    if (scientificExponent_1 < IL64(0)){
      X60Qx_44 = (NC8)'-';}
    else {
      X60Qx_44 = (NC8)'+';}
    putQ_10_If2353w_sysvq0asl(buffer_2, ((NI64)(pos_10 + IL64(1))), X60Qx_44);
    inc_0_Iwdk9lf_party5a2l1((&pos_10), IL64(2));
    NI64 X60Qx_45;
    if (scientificExponent_1 < IL64(0)){
      X60Qx_45 = ((NI64)-scientificExponent_1);}
    else {
      X60Qx_45 = scientificExponent_1;}
    NU32 k_4 = ((NU32)X60Qx_45);
    if (k_4 < ((NU32)IL64(10))){
      NC8 X60Qx_277 = chr_0_sysvq0asl(((NI64)(((NI64)(NC8)'0') + ((NI64)k_4))));
      putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, X60Qx_277);
      inc_1_Irn1g7r1_aif7a4qfr((&pos_10));}
    else {
      if (k_4 < ((NU32)IL64(100))){
        utoa2Digits_0_sysvq0asl(buffer_2, pos_10, k_4);
        inc_0_Iwdk9lf_party5a2l1((&pos_10), IL64(2));}
      else {
        NU32 q_13 = ((NU32)(k_4 / ((NU32)IL64(100))));
        NU32 r_7 = ((NU32)(k_4 % ((NU32)IL64(100))));
        NC8 X60Qx_278 = chr_0_sysvq0asl(((NI64)(((NI64)(NC8)'0') + ((NI64)q_13))));
        putQ_10_If2353w_sysvq0asl(buffer_2, pos_10, X60Qx_278);
        inc_1_Irn1g7r1_aif7a4qfr((&pos_10));
        utoa2Digits_0_sysvq0asl(buffer_2, pos_10, r_7);
        inc_0_Iwdk9lf_party5a2l1((&pos_10), IL64(2));}}}
  result_172 = pos_10;
  return result_172;}
NI64 toChars_0_sysvq0asl(openArray_0_Ijk0jkw1_has9tn57v buffer_3, NF64 v_4, NB8 forceTrailingDotZero_3){
  NI64 result_173;
  NI64 pos_11 = IL64(0);
  Double_0_sysvq0asl double_0 = constructDouble_0_sysvq0asl(v_4);
  NU64 significand_1 = physicalSignificand_1_sysvq0asl(double_0);
  NU64 exponent_1 = physicalExponent_1_sysvq0asl(double_0);
  if ((!(exponent_1 == ((NU64)2047ull)))){
    putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'-');
    NI64 X60Qx_279 = signBit_1_sysvq0asl(double_0);
    inc_0_Iwdk9lf_party5a2l1((&pos_11), X60Qx_279);
    NB8 X60Qx_280;
    if ((!(exponent_1 == ((NU64)IL64(0))))){
      X60Qx_280 = NIM_TRUE;}
    else {
      X60Qx_280 = (!(significand_1 == ((NU64)IL64(0))));}
    if (X60Qx_280){
      FloatingDecimal64_0_sysvq0asl dec_1 = toDecimal64_0_sysvq0asl(significand_1, exponent_1);
      NI64 X60Qx_281 = formatDigits_1_sysvq0asl(buffer_3, pos_11, dec_1.significand_0, ((NI64)dec_1.exponent_0), forceTrailingDotZero_3);
      result_173 = X60Qx_281;
      return result_173;}
    else {
      putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'0');
      putQ_10_If2353w_sysvq0asl(buffer_3, ((NI64)(pos_11 + IL64(1))), (NC8)'.');
      putQ_10_If2353w_sysvq0asl(buffer_3, ((NI64)(pos_11 + IL64(2))), (NC8)'0');
      putQ_10_If2353w_sysvq0asl(buffer_3, ((NI64)(pos_11 + IL64(3))), (NC8)' ');
      NI64 X60Qx_46;
      if (forceTrailingDotZero_3){
        X60Qx_46 = IL64(3);}
      else {
        X60Qx_46 = IL64(1);}
      inc_0_Iwdk9lf_party5a2l1((&pos_11), X60Qx_46);
      return pos_11;}}
  if (significand_1 == ((NU64)IL64(0))){
    putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'-');
    NI64 X60Qx_282 = signBit_1_sysvq0asl(double_0);
    inc_0_Iwdk9lf_party5a2l1((&pos_11), X60Qx_282);
    putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'i');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI64)(pos_11 + IL64(1))), (NC8)'n');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI64)(pos_11 + IL64(2))), (NC8)'f');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI64)(pos_11 + IL64(3))), (NC8)' ');
    result_173 = ((NI64)(pos_11 + IL64(3)));
    return result_173;}
  else {
    putQ_10_If2353w_sysvq0asl(buffer_3, pos_11, (NC8)'n');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI64)(pos_11 + IL64(1))), (NC8)'a');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI64)(pos_11 + IL64(2))), (NC8)'n');
    putQ_10_If2353w_sysvq0asl(buffer_3, ((NI64)(pos_11 + IL64(3))), (NC8)' ');
    result_173 = ((NI64)(pos_11 + IL64(3)));
    return result_173;}
  return result_173;}
void addFloat_0_sysvq0asl(string_0_sysvq0asl* result_0, NF64 x_327){
  X60Qt_0_IAarrayAcS8ZS65_sysvq0asl buffer_4 = default_23_Iu3awv61_sysvq0asl();
  openArray_0_Ijk0jkw1_has9tn57v X60Qx_283 = toOpenArray_0_I9ym4m81_sysvq0asl((&buffer_4));
  NI64 n_7 = toChars_0_sysvq0asl(X60Qx_283, x_327, NIM_TRUE);
  {
    NI64 X60Qlf_22 = IL64(0);
    NI64 X60Qlf_23 = n_7;
    NI64 X60Qlf_24 = X60Qlf_22;
    {
      while (X60Qlf_24 < X60Qlf_23){
        {
          NI64 X60Qx_284 = nimIcheckB(X60Qlf_24, IL64(64));
          add_1_sysvq0asl(result_0, buffer_4.a[X60Qx_284]);}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_24));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
static inline string_0_sysvq0asl getQ_14_sysvq0asl(string_0_sysvq0asl s_75, HSlice_0_I6e0t4q1_aif7a4qfr x_336){
  string_0_sysvq0asl result_186;
  nimStrWasMoved((&result_186));
  nimStrDestroy(result_186);
  string_0_sysvq0asl X60Qx_296 = substr_0_sysvq0asl(s_75, x_336.a_0, x_336.b_0);
  result_186 = X60Qx_296;
  return result_186;}
void raiseIndexError3_0_Ice8haj1_sysvq0asl(NI64 i_65, NI64 a_45, NI64 b_34){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8007532514336729598ull, .more_0 = (&strlit_0_I11614695157650328859_sysvq0asl)}
  );
  writeErr_0_sysvq0asl(i_65);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2336921205458477063ull, .more_0 = NIM_NIL}
  );
  writeErr_0_sysvq0asl(a_45);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3026434ull, .more_0 = NIM_NIL}
  );
  writeErr_0_sysvq0asl(b_34);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561ull, .more_0 = NIM_NIL}
  );
  exit(((NI32)IL64(1)));}
void raiseIndexError3_0_Ils6gq61_sysvq0asl(NU64 i_66, NU64 a_46, NU64 b_35){
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 8007532514336729598ull, .more_0 = (&strlit_0_I11614695157650328859_sysvq0asl)}
  );
  writeErr_1_sysvq0asl(i_66);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2336921205458477063ull, .more_0 = NIM_NIL}
  );
  writeErr_1_sysvq0asl(a_46);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3026434ull, .more_0 = NIM_NIL}
  );
  writeErr_1_sysvq0asl(b_35);
  writeErr_2_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 2561ull, .more_0 = NIM_NIL}
  );
  exit(((NI32)IL64(1)));}
static inline void putQ_10_If2353w_sysvq0asl(openArray_0_Ijk0jkw1_has9tn57v x_358, NI64 i_67, NC8 elem_12){
  NB8 X60Qx_300;
  if (IL64(0) <= i_67){
    X60Qx_300 = (i_67 < x_358.len_0);}
  else {
    X60Qx_300 = NIM_FALSE;}
  if ((!X60Qx_300)){
    panic_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8029189632630337278ull, .more_0 = (&strlit_0_I14872370265633446329_str7j0ifg)}
    );}
  NC8* X60Qx_301 = getQ_10_I5nt6we_has9tn57v(x_358, i_67);
  (*X60Qx_301) = elem_12;}
static inline void dec_0_Idgnuqw1_sysvq0asl(NU64* x_362, NU64 y_210){
  (*x_362) = ((NU64)((*x_362) - y_210));}
static inline void plusQeQ_0_Iar0t5x_sysvq0asl(NU64* x_364, NU64 y_212){
  (*x_364) = ((NU64)((*x_364) + y_212));}
static inline void dec_1_Ifi4w3m1_sysvq0asl(NU64* x_365){
  (*x_365) = ((NU64)((*x_365) - ((NU64)IL64(1))));}
static inline X60Qt_0_IAarrayAcS8ZS16_sysvq0asl default_23_Imn3jdi_sysvq0asl(void){
  X60Qt_0_IAarrayAcS8ZS16_sysvq0asl result_193;
  {
    NI64 X60Qlf_28 = ((NI64)IL64(0));
    NI64 X60Qlf_29 = ((NI64)IL64(15));
    NI64 X60Qlf_30 = X60Qlf_28;
    {
      while (X60Qlf_30 <= X60Qlf_29){
        {
          NI64 X60Qx_303 = nimIcheckB(X60Qlf_30, IL64(15));
          result_193.a[X60Qx_303] = (NC8)'\000';}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_30));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_193;}
static inline X60Qt_0_IAarrayAcS8ZS65_sysvq0asl default_23_Iu3awv61_sysvq0asl(void){
  X60Qt_0_IAarrayAcS8ZS65_sysvq0asl result_194;
  {
    NI64 X60Qlf_31 = ((NI64)IL64(0));
    NI64 X60Qlf_32 = ((NI64)IL64(64));
    NI64 X60Qlf_33 = X60Qlf_31;
    {
      while (X60Qlf_33 <= X60Qlf_32){
        {
          NI64 X60Qx_304 = nimIcheckB(X60Qlf_33, IL64(64));
          result_194.a[X60Qx_304] = (NC8)'\000';}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_33));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_194;}
static inline openArray_0_Ijk0jkw1_has9tn57v toOpenArray_0_I9ym4m81_sysvq0asl(X60Qt_0_IAarrayAcS8ZS65_sysvq0asl* x_368){
  openArray_0_Ijk0jkw1_has9tn57v result_195;
  openArray_0_Ijk0jkw1_has9tn57v X60Qx_47;
  if (((NI64)(((NI64)(((NI64)((NI64)IL64(64))) - ((NI64)((NI64)IL64(0))))) + IL64(1))) == IL64(0)){
    X60Qx_47 = (openArray_0_Ijk0jkw1_has9tn57v){
      .a_0 = NIM_NIL, .len_0 = IL64(0)}
    ;}
  else {
    X60Qx_47 = (openArray_0_Ijk0jkw1_has9tn57v){
      .a_0 = ((NC8*)(&(*x_368))), .len_0 = ((NI64)(((NI64)(((NI64)((NI64)IL64(64))) - ((NI64)((NI64)IL64(0))))) + IL64(1)))}
    ;}
  result_195 = X60Qx_47;
  return result_195;}
void eQwasmovedQ_ArefSX45xception0sysvq0asl_0_sysvq0asl(X60Qt_0_IArefSX45xception0sysvq0asl_sysvq0asl** dest_0){
  (*dest_0) = NIM_NIL;}
void X60Qini_0_sysvq0asl(void){
  if (X60QiniGuard_0_sysvq0asl){
    return;}
  X60QiniGuard_0_sysvq0asl = NIM_TRUE;
  eQwasmovedQ_ArefSX45xception0sysvq0asl_0_sysvq0asl((&exc_0_sysvq0asl));}
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1){
  (*x_1) = ((NI64)((*x_1) + ((NI64)IL64(1))));}
static inline void inc_0_Ineawm41_party5a2l1(NU64* x_8, NU64 y_2){
  (*x_8) = ((NU64)((*x_8) + y_2));}
static inline void dec_0_Iw9ew8i1_ospaexnw61(NI64* x_7, NI64 y_3){
  (*x_7) = ((NI64)((*x_7) - y_3));}
static inline void inc_0_Iwdk9lf_party5a2l1(NI64* x_10, NI64 y_3){
  (*x_10) = ((NI64)((*x_10) + y_3));}
static inline void dec_1_I2mwrey1_envto7w6l1(NI64* x_8){
  (*x_8) = ((NI64)((*x_8) - ((NI64)IL64(1))));}
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
static void __attribute__((constructor)) init(void) {gExitFlush_0_sysvq0asl = nimNoopFlush_0_sysvq0asl;
oomHandler_0_sysvq0asl = continueAfterOutOfMem_0_sysvq0asl;
}

