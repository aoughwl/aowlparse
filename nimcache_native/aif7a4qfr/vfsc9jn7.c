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
typedef struct VfsBlob_0_vfsc9jn7 VfsBlob_0_vfsc9jn7;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef NU8 FileWriteMode_0_vfsc9jn7;

#define AlwaysWrite_0_vfsc9jn7 ((NU8)IL64(0))
#define OnlyIfChanged_0_vfsc9jn7 ((NU8)IL64(1))
typedef struct MemFile_0_memlzdyby{
  void* mem_0;
  NI64 size_0;
  int handle_0;
  int flags_0;}
MemFile_0_memlzdyby;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_vfsc9jn7)(VfsBlob_0_vfsc9jn7*);
typedef struct VfsBlob_0_vfsc9jn7{
  void* data_0;
  NI64 size_0;
  MemFile_0_memlzdyby mf_0;
  void* cookie_0;
  X60Qt_0_IAmutSX56fsX42lob0vfsc9jn7ZSEAnimcallZAfalseZAR37_vfsc9jn7 cleanup_0;}
VfsBlob_0_vfsc9jn7;
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
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_oswd7dmm{
  ErrorCode_0_sysvq0asl fld_0;
  NI64 fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslAiS64_oswd7dmm;
typedef struct string_0_sysvq0asl{
  NU64 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr{
  ErrorCode_0_sysvq0asl fld_0;
  string_0_sysvq0asl fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr;
typedef struct X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby{
  ErrorCode_0_sysvq0asl fld_0;
  MemFile_0_memlzdyby fld_1;}
X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSX4demX46ile0memlzdyby_memlzdyby;
typedef N_NIMCALL_PTR(VfsBlob_0_vfsc9jn7,  X60Qt_0_ISstring0sysvq0aslSX56fsX42lob0vfsc9jn7AnimcallZAfalseZAR47_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISstring0sysvq0aslSR0SEAnimcallZAfalseZAR31_vfsc9jn7)(string_0_sysvq0asl, string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NI64,  X60Qt_0_ISstring0sysvq0aslAiS64ZAnimcallZAfalseZAR32_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(NI64,  X60Qt_0_IAiS64ZAnimcallZAfalseZAR15_vfsc9jn7)(void);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISstring0sysvq0aslSEAnimcallZAfalseZAR28_vfsc9jn7)(string_0_sysvq0asl);
typedef struct LongString_0_sysvq0asl{
  NI64 fullLen_0;
  NI64 rc_0;
  NI64 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38);
extern X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr readFile_0_syn1lfpjv(string_0_sysvq0asl filename_4);
static inline void nimStrDestroy(string_0_sysvq0asl s_39);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40);
extern ErrorCode_0_sysvq0asl writeFile_0_syn1lfpjv(string_0_sysvq0asl filename_5, string_0_sysvq0asl content_0);
extern string_0_sysvq0asl ampQ_0_sysvq0asl(string_0_sysvq0asl a_18, string_0_sysvq0asl b_14);
extern void quit_1_syn1lfpjv(string_0_sysvq0asl msg_0);
extern NB8 fileExists_0_osc4bsu0d1(string_0_sysvq0asl filename_0);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_memlzdyby(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_timsagyye1(void);
extern void X60Qini_0_oswd7dmm(void);
extern void X60Qini_0_cmdqs323n1(void);
extern void X60Qini_0_ospaexnw61(void);
extern void X60Qini_0_osalirkw71(void);
extern void X60Qini_0_osc4bsu0d1(void);
extern void X60Qini_0_ossk30t39(void);
extern void X60Qini_0_dir38pj6l(void);
extern void X60Qini_0_pat4k2dls(void);
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1);
extern void dealloc_0_sysvq0asl(void* p_10);
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0);
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0);
LongString_0_sysvq0asl const strlit_0_I12909424938976562878_vfsc9jn7 = {
  .fullLen_0 = IL64(19), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "vfs: write failed: "}
;
X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7 readBytesRelay_0_vfsc9jn7;
X60Qt_0_ISstring0sysvq0aslSR0SEAnimcallZAfalseZAR31_vfsc9jn7 writeBytesRelay_0_vfsc9jn7;
X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7 existsRelay_0_vfsc9jn7;
NB8 X60QiniGuard_0_vfsc9jn7;
string_0_sysvq0asl readBytes_0_vfsc9jn7(string_0_sysvq0asl p_2){
  string_0_sysvq0asl result_3;
  nimStrWasMoved((&result_3));
  string_0_sysvq0asl X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  X60Qt_0_IAtupleSX45rrorX43ode0sysvq0aslSstring0R20_aif7a4qfr X60QcanRaise_0 = readFile_0_syn1lfpjv(p_2);
  if (X60QcanRaise_0.fld_0){
    goto X60Qexlab_3;}
  nimStrDestroy(X60Qx_2);
  string_0_sysvq0asl X60Qx_7 = nimStrDup(X60QcanRaise_0.fld_1);
  X60Qx_2 = X60Qx_7;
  if (NIM_FALSE){
    X60Qexlab_3: ;
    nimStrDestroy(X60Qx_2);
    X60Qx_2 = (string_0_sysvq0asl){
      .bytes_0 = 0ull, .more_0 = NIM_NIL}
    ;}
  nimStrDestroy(result_3);
  result_3 = X60Qx_2;
  nimStrWasMoved((&X60Qx_2));
  nimStrDestroy(X60Qx_2);
  return result_3;
  nimStrDestroy(X60Qx_2);
  return result_3;}
void writeBytes_0_vfsc9jn7(string_0_sysvq0asl p_3, string_0_sysvq0asl c_0){
  ErrorCode_0_sysvq0asl X60QcanRaise_0 = writeFile_0_syn1lfpjv(p_3, c_0);
  if (X60QcanRaise_0){
    goto X60Qexlab_4;}
  if (NIM_FALSE){
    X60Qexlab_4: ;
    string_0_sysvq0asl X60Qtmp_1 = ampQ_0_sysvq0asl((string_0_sysvq0asl){
      .bytes_0 = 8248096677968639742ull, .more_0 = (&strlit_0_I12909424938976562878_vfsc9jn7)}
    , p_3);
    quit_1_syn1lfpjv(X60Qtmp_1);
    nimStrDestroy(X60Qtmp_1);}}
NB8 fileMaybeExists_0_vfsc9jn7(string_0_sysvq0asl p_4){
  NB8 result_4;
  NB8 X60Qx_3;
  NB8 X60Qx_8 = fileExists_0_osc4bsu0d1(p_4);
  X60Qx_3 = X60Qx_8;
  if (NIM_FALSE){
    X60Qexlab_5: ;
    X60Qx_3 = NIM_FALSE;}
  result_4 = X60Qx_3;
  return result_4;}
string_0_sysvq0asl X60Qanonproc_1_vfsc9jn7(string_0_sysvq0asl path_9){
  string_0_sysvq0asl result_9;
  nimStrWasMoved((&result_9));
  nimStrDestroy(result_9);
  string_0_sysvq0asl X60Qx_11 = readBytes_0_vfsc9jn7(path_9);
  result_9 = X60Qx_11;
  return result_9;}
void X60Qanonproc_2_vfsc9jn7(string_0_sysvq0asl path_11, string_0_sysvq0asl content_2){
  writeBytes_0_vfsc9jn7(path_11, content_2);}
NB8 X60Qanonproc_3_vfsc9jn7(string_0_sysvq0asl path_13){
  NB8 result_10;
  NB8 X60Qx_12 = fileMaybeExists_0_vfsc9jn7(path_13);
  result_10 = X60Qx_12;
  return result_10;}
static inline string_0_sysvq0asl vfsRead_0_vfsc9jn7(string_0_sysvq0asl path_1){
  string_0_sysvq0asl result_14;
  nimStrWasMoved((&result_14));
  nimStrDestroy(result_14);
  string_0_sysvq0asl X60Qx_16 = readBytesRelay_0_vfsc9jn7(path_1);
  result_14 = X60Qx_16;
  return result_14;}
static inline void vfsWrite_0_vfsc9jn7(string_0_sysvq0asl path_2, string_0_sysvq0asl content_0){
  writeBytesRelay_0_vfsc9jn7(path_2, content_0);}
static inline NB8 vfsExists_0_vfsc9jn7(string_0_sysvq0asl path_3){
  NB8 result_15;
  NB8 X60Qx_17 = existsRelay_0_vfsc9jn7(path_3);
  result_15 = X60Qx_17;
  return result_15;}
void X60Qini_0_vfsc9jn7(void){
  if (X60QiniGuard_0_vfsc9jn7){
    return;}
  X60QiniGuard_0_vfsc9jn7 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_memlzdyby();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_timsagyye1();
  X60Qini_0_oswd7dmm();
  X60Qini_0_cmdqs323n1();
  X60Qini_0_ospaexnw61();
  X60Qini_0_osalirkw71();
  X60Qini_0_osc4bsu0d1();
  X60Qini_0_ossk30t39();
  X60Qini_0_dir38pj6l();
  X60Qini_0_pat4k2dls();}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38){
  (*s_38).bytes_0 = ((NU64)IL64(0));}
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
static void __attribute__((constructor)) init(void) {readBytesRelay_0_vfsc9jn7 = X60Qanonproc_1_vfsc9jn7;
writeBytesRelay_0_vfsc9jn7 = X60Qanonproc_2_vfsc9jn7;
existsRelay_0_vfsc9jn7 = X60Qanonproc_3_vfsc9jn7;
}

