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
#include <string.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef NU8 FileMode_0_syn1lfpjv;

#define fmRead_0_syn1lfpjv ((NU8)IL64(0))
#define fmWrite_0_syn1lfpjv ((NU8)IL64(1))
#define fmReadWrite_0_syn1lfpjv ((NU8)IL64(2))
#define fmReadWriteExisting_0_syn1lfpjv ((NU8)IL64(3))
#define fmAppend_0_syn1lfpjv ((NU8)IL64(4))
typedef NU8 FileSeekPos_0_syn1lfpjv;

#define fspSet_0_syn1lfpjv ((NU8)IL64(0))
#define fspCur_0_syn1lfpjv ((NU8)IL64(1))
#define fspEnd_0_syn1lfpjv ((NU8)IL64(2))
typedef NU8 FilePermission_0_syn1lfpjv;

#define fpUserExec_0_syn1lfpjv ((NU8)IL64(0))
#define fpUserWrite_0_syn1lfpjv ((NU8)IL64(1))
#define fpUserRead_0_syn1lfpjv ((NU8)IL64(2))
#define fpGroupExec_0_syn1lfpjv ((NU8)IL64(3))
#define fpGroupWrite_0_syn1lfpjv ((NU8)IL64(4))
#define fpGroupRead_0_syn1lfpjv ((NU8)IL64(5))
#define fpOthersExec_0_syn1lfpjv ((NU8)IL64(6))
#define fpOthersWrite_0_syn1lfpjv ((NU8)IL64(7))
#define fpOthersRead_0_syn1lfpjv ((NU8)IL64(8))
typedef struct X60Qt_0_IAarrayAcS8ZS80_syn1lfpjv{
  NC8 a[IL64(80)];}
X60Qt_0_IAarrayAcS8ZS80_syn1lfpjv;
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
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_oswd7dmm{
  ErrorCode_0_sysvq0asl fld_0;
  NI64 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_oswd7dmm;
typedef struct LongString_0_sysvq0asl{
  NI64 fullLen_0;
  NI64 rc_0;
  NI64 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_37, NI64 start_0);
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32);
static inline string_0_sysvq0asl terminatingZero_0_sysvq0asl(string_0_sysvq0asl s_58);
static inline void nimStrDestroy(string_0_sysvq0asl s_39);
extern void cExit_0_sysvq0asl(NI64 code_1);
extern string_0_sysvq0asl newString_0_sysvq0asl(NI64 len_2);
extern NC8* beginStore_0_sysvq0asl(string_0_sysvq0asl* s_45, NI64 newLen_7, NI64 start_2);
static inline void endStore_0_sysvq0asl(string_0_sysvq0asl* s_46);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_48, string_0_sysvq0asl part_0);
extern void setLen_1_sysvq0asl(string_0_sysvq0asl* s_51, NI64 newLen_13);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_for2ybv4p1(void);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_18, string_0_sysvq0asl b_14);
extern void shrink_1_sysvq0asl(string_0_sysvq0asl* s_50, NI64 newLen_12);
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1);
extern void dealloc_0_sysvq0asl(void* p_10);
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI64 size_3);
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0);
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0);
NB8 X60QiniGuard_0_syn1lfpjv;
void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0){
  NC8* X60Qx_2 = readRawData_0_sysvq0asl((&s_0), IL64(0));
  NI64 X60Qx_3 = len_4_sysvq0asl(s_0);
  NU64 X60Qx_4 = fwrite(((void*)X60Qx_2), 1ull, ((NU64)X60Qx_3), f_6);}
void write_7_syn1lfpjv(FILE* f_13, NC8 c_1){
  NI32 X60Qx_5 = fputc(((NI32)c_1), f_13);}
void close_0_syn1lfpjv(FILE* f_16){
  NI32 X60Qx_6 = fclose(f_16);}
NI64 readBuffer_0_syn1lfpjv(FILE* f_18, void* buffer_1, NI64 size_3){
  NI64 result_5;
  NU64 X60Qx_8 = fread(buffer_1, 1ull, ((NU64)size_3), f_18);
  result_5 = ((NI64)X60Qx_8);
  return result_5;}
static inline NB8 failed_0_syn1lfpjv(FILE* f_20){
  NB8 result_6;
  NI32 X60Qx_9 = ferror(f_20);
  result_6 = (!(X60Qx_9 == ((NI32)IL64(0))));
  return result_6;}
NB8 open_0_syn1lfpjv(FILE** f_22, string_0_sysvq0asl filename_1, FileMode_0_syn1lfpjv mode_2, NI64 bufSize_0){
  NB8 result_7;
  NC8* X60Qx_0;
  switch (mode_2){
    case IL64(0):
    {
      X60Qx_0 = (NC8*)"rb";}
    break;
    case IL64(1):
    {
      X60Qx_0 = (NC8*)"wb";}
    break;
    case IL64(2):
    {
      X60Qx_0 = (NC8*)"w+b";}
    break;
    case IL64(3):
    {
      X60Qx_0 = (NC8*)"r+b";}
    break;
    case IL64(4):
    {
      X60Qx_0 = (NC8*)"ab";}
    break;}
  NC8* m_0 = X60Qx_0;
  string_0_sysvq0asl tmpFilename_0 = terminatingZero_0_sysvq0asl(filename_1);
  NC8* X60Qx_10 = readRawData_0_sysvq0asl((&tmpFilename_0), IL64(0));
  NC8* rawFilename_0 = ((NC8*)X60Qx_10);
  FILE* X60Qx_11 = fopen(rawFilename_0, m_0);
  (*f_22) = X60Qx_11;
  if ((!((*f_22) == NIM_NIL))){
    result_7 = NIM_TRUE;
    if (IL64(0) <= bufSize_0){
      NI32 X60Qx_12 = setvbuf((*f_22), NIM_NIL, ((NI32)IL64(0)), ((NU64)bufSize_0));}}
  else {
    result_7 = NIM_FALSE;}
  nimStrDestroy(tmpFilename_0);
  return result_7;
  nimStrDestroy(tmpFilename_0);
  return result_7;}
void quit_0_syn1lfpjv(NI64 value_0){
  cExit_0_sysvq0asl(value_0);}
void quit_1_syn1lfpjv(string_0_sysvq0asl msg_0){
  write_0_syn1lfpjv(stdout, msg_0);
  write_7_syn1lfpjv(stdout, (NC8)'\012');
  quit_0_syn1lfpjv(((NI64)IL64(1)));}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr readAll_0_syn1lfpjv(FILE* f_28){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr result_11;
  result_11.fld_0 = IL64(0);
  result_11 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr){
    .fld_0 = IL64(0), .fld_1 = (string_0_sysvq0asl){
      .bytes_0 = 0ull, .more_0 = NIM_NIL}}
  ;
  string_0_sysvq0asl buffer_3 = newString_0_sysvq0asl(((NI64)IL64(4000)));
  {
    while (NIM_TRUE){
      NC8* X60Qx_18 = beginStore_0_sysvq0asl((&buffer_3), ((NI64)IL64(4000)), IL64(0));
      NI64 bytesRead_0 = readBuffer_0_syn1lfpjv(f_28, ((void*)X60Qx_18), ((NI64)IL64(4000)));
      endStore_0_sysvq0asl((&buffer_3));
      if (bytesRead_0 == ((NI64)IL64(4000))){
        add_2_sysvq0asl((&result_11.fld_1), buffer_3);}
      else {
        setLen_1_sysvq0asl((&buffer_3), bytesRead_0);
        add_2_sysvq0asl((&result_11.fld_1), buffer_3);
        goto whileStmtLabel_0;}}}
  whileStmtLabel_0: ;
  NB8 X60Qx_19 = failed_0_syn1lfpjv(f_28);
  if (X60Qx_19){
    nimStrDestroy(buffer_3);
    return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr){
      .fld_0 = IL64(11), .fld_1 = result_11.fld_1}
    ;}
  nimStrDestroy(buffer_3);
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr){
    .fld_0 = IL64(0), .fld_1 = result_11.fld_1}
  ;
  nimStrDestroy(buffer_3);
  return result_11;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr readFile_0_syn1lfpjv(string_0_sysvq0asl filename_4){
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr result_12;
  result_12.fld_0 = IL64(0);
  result_12 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr){
    .fld_0 = IL64(0), .fld_1 = (string_0_sysvq0asl){
      .bytes_0 = 0ull, .more_0 = NIM_NIL}}
  ;
  FILE* f_37;
  NB8 X60Qx_20 = open_0_syn1lfpjv((&f_37), filename_4, IL64(0), IL64(-1));
  if (X60Qx_20){
    X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr X60QcanRaise_0 = readAll_0_syn1lfpjv(f_37);
    if (X60QcanRaise_0.fld_0){
      close_0_syn1lfpjv(f_37);
      return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr){
        .fld_0 = X60QcanRaise_0.fld_0, .fld_1 = result_12.fld_1}
      ;}
    nimStrDestroy(result_12.fld_1);
    string_0_sysvq0asl X60Qx_21 = nimStrDup(X60QcanRaise_0.fld_1);
    result_12 = (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr){
      .fld_0 = IL64(0), .fld_1 = X60Qx_21}
    ;
    close_0_syn1lfpjv(f_37);}
  else {
    return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr){
      .fld_0 = IL64(11), .fld_1 = result_12.fld_1}
    ;}
  return (X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr){
    .fld_0 = IL64(0), .fld_1 = result_12.fld_1}
  ;}
ErrorCode_0_sysvq0asl writeFile_0_syn1lfpjv(string_0_sysvq0asl filename_5, string_0_sysvq0asl content_0){
  FILE* f_38;
  NB8 X60Qx_22 = open_0_syn1lfpjv((&f_38), filename_5, IL64(1), IL64(-1));
  if (X60Qx_22){
    write_0_syn1lfpjv(f_38, content_0);
    close_0_syn1lfpjv(f_38);}
  else {
    return IL64(11);}
  return IL64(0);}
void X60Qini_0_syn1lfpjv(void){
  if (X60QiniGuard_0_syn1lfpjv){
    return;}
  X60QiniGuard_0_syn1lfpjv = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_for2ybv4p1();}
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_37, NI64 start_0){
  NC8* result_65;
  if (((NI64)IL64(14)) < ((NI64)(*((NU8*)(&(*s_37).bytes_0))))){
    result_65 = ((NC8*)((NU64)(((NU64)(&(*(*s_37).more_0).data_0[IL64(0)])) + ((NU64)start_0))));}
  else {
    result_65 = ((NC8*)((NU64)(((NU64)((NC8*)((NU64)(((NU64)(&(*s_37).bytes_0)) + 1ull)))) + ((NU64)start_0))));}
  return result_65;}
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32){
  NI64 result_60;
  result_60 = ((NI64)(*((NU8*)(&s_32.bytes_0))));
  if (((NI64)IL64(14)) < result_60){
    result_60 = (*s_32.more_0).fullLen_0;}
  return result_60;}
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
static inline void nimStrDestroy(string_0_sysvq0asl s_39){
  if (((NI64)(*((NU8*)(&s_39.bytes_0)))) == ((NI64)IL64(255))){
    NB8 X60Qx_80 = arcDec_0_sysvq0asl((&(*s_39.more_0).rc_0));
    if (X60Qx_80){
      dealloc_0_sysvq0asl(((void*)s_39.more_0));}}}
static inline void endStore_0_sysvq0asl(string_0_sysvq0asl* s_46){
  if (((NI64)IL64(14)) < ((NI64)(*((NU8*)(&(*s_46).bytes_0))))){
    copyMem_0_sysvq0asl(((void*)((NC8*)((NU64)(((NU64)(&(*s_46).bytes_0)) + 1ull)))), ((void*)(&(*(*s_46).more_0).data_0[IL64(0)])), ((NI64)IL64(7)));}}
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
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1){
  NB8 result_118;
  NI64 X60Qx_178 = __atomic_sub_fetch((&(*memLoc_1)), IL64(1), __ATOMIC_SEQ_CST);
  result_118 = (X60Qx_178 < IL64(0));
  return result_118;}
static inline void copyMem_0_sysvq0asl(void* dest_4, void* src_3, NI64 size_3){
  memcpy(dest_4, src_3, ((size_t)size_3));}
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0){
  NI64 result_57;
  result_57 = ((NI64)((NU64)(bytes_0 & 255ull)));
  return result_57;}
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0){
  NI64 X60Qx_177 = __atomic_add_fetch((&(*memLoc_0)), IL64(1), __ATOMIC_SEQ_CST);}
