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
#include <math.h>
#include <stdio.h>
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef NU8 Mode_0_nifjp9lau1;

#define UsesMem_0_nifjp9lau1 ((NU8)IL64(0))
#define UsesFile_0_nifjp9lau1 ((NU8)IL64(1))
typedef struct string_0_sysvq0asl{
  NU64 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
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
typedef struct openArray_0_Ijk0jkw1_has9tn57v{
  NC8* a_0;
  NI64 len_0;}
openArray_0_Ijk0jkw1_has9tn57v;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[IL64(32)];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct X60Qt_0_IAarrayAcS8ZS12_nifjp9lau1{
  NC8 a[IL64(12)];}
X60Qt_0_IAarrayAcS8ZS12_nifjp9lau1;
typedef struct LongString_0_sysvq0asl{
  NI64 fullLen_0;
  NI64 rc_0;
  NI64 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef NU8 FloatClass_0_mat7cnfv21;

#define fcNormal_0_mat7cnfv21 ((NU8)IL64(0))
#define fcSubnormal_0_mat7cnfv21 ((NU8)IL64(1))
#define fcZero_0_mat7cnfv21 ((NU8)IL64(2))
#define fcNegZero_0_mat7cnfv21 ((NU8)IL64(3))
#define fcNan_0_mat7cnfv21 ((NU8)IL64(4))
#define fcInf_0_mat7cnfv21 ((NU8)IL64(5))
#define fcNegInf_0_mat7cnfv21 ((NU8)IL64(6))
typedef N_NIMCALL_PTR(NB8,  X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(string_0_sysvq0asl,  X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7)(string_0_sysvq0asl);
typedef N_NIMCALL_PTR(void,  X60Qt_0_ISstring0sysvq0aslSR0SEAnimcallZAfalseZAR31_vfsc9jn7)(string_0_sysvq0asl, string_0_sysvq0asl);
void attachLineInfo_1_nifjp9lau1(Builder_0_nifjp9lau1* b_27, NI32 col_2, NI32 line_2, string_0_sysvq0asl file_2);
static inline void minusQeQ_0_Isqosxa_nifjp9lau1(NI64* x_10, NI64 y_3);
static inline FloatClass_0_mat7cnfv21 classify_0_Iva37xy1_nifjp9lau1(NF64 x_13);
static inline NB8 signbit_0_I8usf6p_nifjp9lau1(NF64 x_18);
void eQwasmovedQ_SX42uilder0nifjp9lau1_0_nifjp9lau1(Builder_0_nifjp9lau1* dest_0);
void eQdestroyQ_SX42uilder0nifjp9lau1_0_nifjp9lau1(Builder_0_nifjp9lau1* dest_0);
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40);
static inline NB8 vfsExists_0_vfsc9jn7(string_0_sysvq0asl path_3);
static inline string_0_sysvq0asl vfsRead_0_vfsc9jn7(string_0_sysvq0asl path_1);
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_14, string_0_sysvq0asl b_10);
static inline void nimStrDestroy(string_0_sysvq0asl s_39);
static inline void vfsWrite_0_vfsc9jn7(string_0_sysvq0asl path_2, string_0_sysvq0asl content_0);
extern void write_0_syn1lfpjv(FILE* f_6, string_0_sysvq0asl s_0);
extern LongString_0_sysvq0asl const strlit_0_I14676000009897902695_assy765wm;
extern void write_7_syn1lfpjv(FILE* f_13, NC8 c_1);
extern void quit_0_syn1lfpjv(NI64 value_0);
extern void add_2_sysvq0asl(string_0_sysvq0asl* s_48, string_0_sysvq0asl part_0);
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32);
static inline void plusQeQ_0_Ihg6mz11_mat7cnfv21(NI64* x_147, NI64 y_41);
extern void add_1_sysvq0asl(string_0_sysvq0asl* s_47, NC8 c_0);
static inline NC8 getQ_9_sysvq0asl(string_0_sysvq0asl s_52, NI64 i_14);
static inline void dec_1_I2mwrey1_envto7w6l1(NI64* x_8);
extern void setLen_1_sysvq0asl(string_0_sysvq0asl* s_51, NI64 newLen_13);
extern LongString_0_sysvq0asl const strlit_0_I7901555537561129428_lex3r1urc1;
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1);
static inline openArray_0_Ijk0jkw1_has9tn57v toOpenArray_2_sysvq0asl(string_0_sysvq0asl* s_65);
static inline NI64 len_6_Iroq7kd1_has9tn57v(openArray_0_Ijk0jkw1_has9tn57v a_6);
static inline NC8* getQ_10_I5nt6we_has9tn57v(openArray_0_Ijk0jkw1_has9tn57v x_14, NI64 idx_1);
extern string_0_sysvq0asl dollarQ_1_sysvq0asl(NI64 x_225);
extern string_0_sysvq0asl dollarQ_0_sysvq0asl(NU64 x_224);
extern void addFloat_0_sysvq0asl(string_0_sysvq0asl* result_0, NF64 x_327);
static inline void putQ_9_sysvq0asl(string_0_sysvq0asl* s_53, NI64 i_15, NC8 c_1);
static inline NI64 nimIcheckB(NI64 i_19, NI64 b_19);
extern LongString_0_sysvq0asl const strlit_0_I8031254106179394417_dir38pj6l;
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_assy765wm(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_for2ybv4p1(void);
extern void X60Qini_0_mat7cnfv21(void);
extern void X60Qini_0_str7j0ifg(void);
extern void X60Qini_0_vfsc9jn7(void);
static inline NI64 ssLenOf_0_sysvq0asl(NU64 bytes_0);
static inline void arcInc_0_sysvq0asl(NI64* memLoc_0);
extern X60Qt_0_ISstring0sysvq0aslAboolZAnimcallZAfalseZAR32_vfsc9jn7 existsRelay_0_vfsc9jn7;
extern X60Qt_0_ISstring0sysvq0aslSR0AnimcallZAfalseZAR29_vfsc9jn7 readBytesRelay_0_vfsc9jn7;
extern NB8 equalStrings_0_sysvq0asl(string_0_sysvq0asl a_13, string_0_sysvq0asl b_9);
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1);
extern void dealloc_0_sysvq0asl(void* p_10);
extern X60Qt_0_ISstring0sysvq0aslSR0SEAnimcallZAfalseZAR31_vfsc9jn7 writeBytesRelay_0_vfsc9jn7;
extern void panic_0_sysvq0asl(string_0_sysvq0asl s_68);
extern LongString_0_sysvq0asl const strlit_0_I14131790745264837101_sysvq0asl;
static inline NC8* readRawData_0_sysvq0asl(string_0_sysvq0asl* s_37, NI64 start_0);
extern LongString_0_sysvq0asl const strlit_0_I14694606176902936784_has9tn57v;
extern LongString_0_sysvq0asl const strlit_0_I11927585966806674622_sysvq0asl;
extern void prepareMutation_0_sysvq0asl(string_0_sysvq0asl* s_44);
extern void raiseIndexError3_0_Ice8haj1_sysvq0asl(NI64 i_65, NI64 a_45, NI64 b_34);
LongString_0_sysvq0asl const strlit_0_I10206930254104378444_nifjp9lau1 = {
  .fullLen_0 = IL64(19), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "unpaired \'(\' or \')\'"}
;
LongString_0_sysvq0asl const strlit_0_I2641880525336905210_nifjp9lau1 = {
  .fullLen_0 = IL64(21), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "no separator required"}
;
LongString_0_sysvq0asl const strlit_0_I2857462522550599008_nifjp9lau1 = {
  .fullLen_0 = IL64(43), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "generating \')\' would produce a syntax error"}
;
LongString_0_sysvq0asl const strlit_0_I2246750106930142149_nifjp9lau1 = {
  .fullLen_0 = IL64(9), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "(.vendor "}
;
LongString_0_sysvq0asl const strlit_0_I15962761803738331083_nifjp9lau1 = {
  .fullLen_0 = IL64(10), .rc_0 = IL64(0), .capImpl_0 = IL64(0), .data_0 = "(.dialect "}
;
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 const ControlChars_0_nifjp9lau1 = {
  .a = {
    0ull, 0ull, 0ull, 0ull, 140ull, 3ull, 0ull, 4ull, 1ull, 0ull, 0ull, 56ull, 0ull, 0ull, 0ull, 104ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull}}
;
static string_0_sysvq0asl const HexChars_0 = {
  .bytes_0 = 3906085646303834366ull, .more_0 = (&strlit_0_I7901555537561129428_lex3r1urc1)}
;
NB8 X60QiniGuard_0_nifjp9lau1;
Builder_0_nifjp9lau1 open_0_nifjp9lau1(string_0_sysvq0asl filename_0, NB8 compact_0, FileWriteMode_0_vfsc9jn7 writeMode_0){
  Builder_0_nifjp9lau1 result_1;
  eQwasmovedQ_SX42uilder0nifjp9lau1_0_nifjp9lau1((&result_1));
  eQdestroyQ_SX42uilder0nifjp9lau1_0_nifjp9lau1((&result_1));
  string_0_sysvq0asl X60Qx_17 = nimStrDup(filename_0);
  result_1 = (Builder_0_nifjp9lau1){
    .buffer_0 = (string_0_sysvq0asl){
      .bytes_0 = 0ull, .more_0 = NIM_NIL}
    , .mode_0 = IL64(1), .writeMode_0 = writeMode_0, .compact_0 = compact_0, .filename_0 = X60Qx_17, .nesting_0 = ((NI64)IL64(0)), .offs_0 = ((NI64)IL64(0))}
  ;
  return result_1;}
void close_0_nifjp9lau1(Builder_0_nifjp9lau1* b_2){
  if ((*b_2).mode_0 == IL64(1)){
    NB8 X60Qx_16;
    NB8 X60Qx_20;
    if ((*b_2).writeMode_0 == IL64(1)){
      NB8 X60Qx_21 = vfsExists_0_vfsc9jn7((*b_2).filename_0);
      X60Qx_20 = X60Qx_21;}
    else {
      X60Qx_20 = NIM_FALSE;}
    if (X60Qx_20){
      string_0_sysvq0asl X60Qtmp_2 = vfsRead_0_vfsc9jn7((*b_2).filename_0);
      NB8 X60Qx_22 = eqQ_20_sysvq0asl(X60Qtmp_2, (*b_2).buffer_0);
      X60Qx_16 = X60Qx_22;
      nimStrDestroy(X60Qtmp_2);}
    else {
      X60Qx_16 = NIM_FALSE;}
    if (X60Qx_16){
      }
    else {
      vfsWrite_0_vfsc9jn7((*b_2).filename_0, (*b_2).buffer_0);}}
  if ((!((*b_2).nesting_0 == IL64(0)))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 8390880602273963006ull, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 7310021012394767870ull, .more_0 = (&strlit_0_I10206930254104378444_nifjp9lau1)}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(IL64(1));}}
void putPending_0_nifjp9lau1(Builder_0_nifjp9lau1* b_3, string_0_sysvq0asl s_0){
  add_2_sysvq0asl((&(*b_3).buffer_0), s_0);
  NI64 X60Qx_23 = len_4_sysvq0asl(s_0);
  plusQeQ_0_Ihg6mz11_mat7cnfv21((&(*b_3).offs_0), X60Qx_23);}
void drainPending_0_nifjp9lau1(Builder_0_nifjp9lau1* b_4){
  }
void put_0_nifjp9lau1(Builder_0_nifjp9lau1* b_5, string_0_sysvq0asl s_1){
  add_2_sysvq0asl((&(*b_5).buffer_0), s_1);
  NI64 X60Qx_24 = len_4_sysvq0asl(s_1);
  plusQeQ_0_Ihg6mz11_mat7cnfv21((&(*b_5).offs_0), X60Qx_24);}
void put_1_nifjp9lau1(Builder_0_nifjp9lau1* b_6, NC8 s_2){
  add_1_sysvq0asl((&(*b_6).buffer_0), s_2);
  plusQeQ_0_Ihg6mz11_mat7cnfv21((&(*b_6).offs_0), IL64(1));}
void undoWhitespace_0_nifjp9lau1(Builder_0_nifjp9lau1* b_7){
  NI64 X60Qx_25 = len_4_sysvq0asl((*b_7).buffer_0);
  NI64 i_1 = ((NI64)(X60Qx_25 - IL64(1)));
  {
    while (NIM_TRUE){
      NB8 X60Qx_0;
      if (IL64(0) <= i_1){
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_0 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
          .a = {
            0ull, 4ull, 0ull, 0ull, 1ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull}}
        ;
        NC8 X60Qx_26 = getQ_9_sysvq0asl((*b_7).buffer_0, i_1);
        NU64 X60Qdesugar_1 = ((NU)X60Qx_26);
        X60Qx_0 = (((NU8)(X60Qdesugar_0.a[((NU)(X60Qdesugar_1 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_1 & 7ull)))))) != 0ull);}
      else {
        X60Qx_0 = NIM_FALSE;}
      if (X60Qx_0){
        dec_1_I2mwrey1_envto7w6l1((&i_1));
        minusQeQ_0_Isqosxa_nifjp9lau1((&(*b_7).offs_0), IL64(1));}
      else {
        break;}}}
  whileStmtLabel_0: ;
  setLen_1_sysvq0asl((&(*b_7).buffer_0), ((NI64)(i_1 + IL64(1))));}
void escape_0_nifjp9lau1(Builder_0_nifjp9lau1* b_8, NC8 c_0){
  NI64 n_0 = ((NI64)c_0);
  put_1_nifjp9lau1(b_8, (NC8)'\\');
  NC8 X60Qx_27 = getQ_9_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3906085646303834366ull, .more_0 = (&strlit_0_I7901555537561129428_lex3r1urc1)}
  , ((NI64)(((NI64)(((NI64)n_0) >> ((NU64)IL64(4)))) & IL64(15))));
  put_1_nifjp9lau1(b_8, X60Qx_27);
  NC8 X60Qx_28 = getQ_9_sysvq0asl((string_0_sysvq0asl){
    .bytes_0 = 3906085646303834366ull, .more_0 = (&strlit_0_I7901555537561129428_lex3r1urc1)}
  , ((NI64)(n_0 & IL64(15))));
  put_1_nifjp9lau1(b_8, X60Qx_28);}
void addRaw_0_nifjp9lau1(Builder_0_nifjp9lau1* b_9, string_0_sysvq0asl s_3){
  put_0_nifjp9lau1(b_9, s_3);}
void addSep_0_nifjp9lau1(Builder_0_nifjp9lau1* b_10){
  NI64 X60Qx_29 = len_4_sysvq0asl((*b_10).buffer_0);
  if (X60Qx_29 == IL64(0)){
    }
  else {
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_2 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
      .a = {
        0ull, 4ull, 0ull, 0ull, 1ull, 3ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull}}
    ;
    NI64 X60Qx_30 = len_4_sysvq0asl((*b_10).buffer_0);
    NC8 X60Qx_31 = getQ_9_sysvq0asl((*b_10).buffer_0, ((NI64)(X60Qx_30 - IL64(1))));
    NU64 X60Qdesugar_3 = ((NU)X60Qx_31);
    if (((NU8)(X60Qdesugar_2.a[((NU)(X60Qdesugar_3 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_3 & 7ull)))))) != 0ull){
      string_0_sysvq0asl X60Qx_32 = (string_0_sysvq0asl){
        .bytes_0 = 7021223364210421502ull, .more_0 = (&strlit_0_I2641880525336905210_nifjp9lau1)}
      ;}
    else {
      putPending_0_nifjp9lau1(b_10, (string_0_sysvq0asl){
        .bytes_0 = 8193ull, .more_0 = NIM_NIL}
      );}}}
void addIdent_0_nifjp9lau1(Builder_0_nifjp9lau1* b_12, string_0_sysvq0asl s_5){
  addSep_0_nifjp9lau1(b_12);
  NI64 X60Qx_33 = len_4_sysvq0asl(s_5);
  if (IL64(0) < X60Qx_33){
    NC8 c_3 = getQ_9_sysvq0asl(s_5, IL64(0));
    NB8 X60Qx_1;
    NB8 X60Qx_2;
    if (c_3 < (NC8)' '){
      X60Qx_2 = NIM_TRUE;}
    else {
      X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_4 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
        .a = {
          0ull, 0ull, 0ull, 0ull, 0ull, 104ull, 255ull, 3ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 64ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull}}
      ;
      NU64 X60Qdesugar_5 = ((NU)c_3);
      X60Qx_2 = (((NU8)(X60Qdesugar_4.a[((NU)(X60Qdesugar_5 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_5 & 7ull)))))) != 0ull);}
    if (X60Qx_2){
      X60Qx_1 = NIM_TRUE;}
    else {
      NB8 X60Qx_3;
      if (c_3 < (NC8)' '){
        X60Qx_3 = NIM_TRUE;}
      else {
        X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_6 = ControlChars_0_nifjp9lau1;
        NU64 X60Qdesugar_7 = ((NU)c_3);
        X60Qx_3 = (((NU8)(X60Qdesugar_6.a[((NU)(X60Qdesugar_7 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_7 & 7ull)))))) != 0ull);}
      X60Qx_1 = X60Qx_3;}
    if (X60Qx_1){
      escape_0_nifjp9lau1(b_12, c_3);}
    else {
      put_1_nifjp9lau1(b_12, c_3);}
    {
      NI64 X60Qlf_0 = IL64(1);
      NI64 X60Qlf_1 = len_4_sysvq0asl(s_5);
      NI64 X60Qlf_2 = X60Qlf_0;
      {
        while (X60Qlf_2 < X60Qlf_1){
          {
            NC8 X60Qii_2 = getQ_9_sysvq0asl(s_5, X60Qlf_2);
            NB8 X60Qx_4;
            if (X60Qii_2 < (NC8)' '){
              X60Qx_4 = NIM_TRUE;}
            else {
              X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_8 = ControlChars_0_nifjp9lau1;
              X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_9 = (X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1){
                .a = {
                  0ull, 0ull, 0ull, 0ull, 0ull, 64ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull, 0ull}}
              ;
              X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_10;
              NI64 X60Qdesugar_11 = IL64(0);
              while (X60Qdesugar_11 < IL64(32)){
                X60Qdesugar_10.a[X60Qdesugar_11] = ((NU8)(X60Qdesugar_8.a[X60Qdesugar_11] | X60Qdesugar_9.a[X60Qdesugar_11]));
                X60Qdesugar_11 = ((NI)(X60Qdesugar_11 + IL64(1)));}
              X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_12 = X60Qdesugar_10;
              NU64 X60Qdesugar_13 = ((NU)X60Qii_2);
              X60Qx_4 = (((NU8)(X60Qdesugar_12.a[((NU)(X60Qdesugar_13 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_13 & 7ull)))))) != 0ull);}
            if (X60Qx_4){
              escape_0_nifjp9lau1(b_12, X60Qii_2);}
            else {
              put_1_nifjp9lau1(b_12, X60Qii_2);}}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_2));}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}}
void addStrLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_18, string_0_sysvq0asl s_11){
  addSep_0_nifjp9lau1(b_18);
  put_1_nifjp9lau1(b_18, (NC8)'\"');
  {
    openArray_0_Ijk0jkw1_has9tn57v X60Qlf_6 = toOpenArray_2_sysvq0asl((&s_11));
    NI64 X60Qlf_7 = IL64(0);
    {
      while (NIM_TRUE){
        NI64 X60Qx_49 = len_6_Iroq7kd1_has9tn57v(X60Qlf_6);
        if (X60Qlf_7 < X60Qx_49){
          {
            NC8* X60Qii_2 = getQ_10_I5nt6we_has9tn57v(X60Qlf_6, X60Qlf_7);
            NB8 X60Qx_9;
            if ((*X60Qii_2) < (NC8)' '){
              X60Qx_9 = NIM_TRUE;}
            else {
              X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_20 = ControlChars_0_nifjp9lau1;
              NU64 X60Qdesugar_21 = ((NU)(*X60Qii_2));
              X60Qx_9 = (((NU8)(X60Qdesugar_20.a[((NU)(X60Qdesugar_21 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_21 & 7ull)))))) != 0ull);}
            if (X60Qx_9){
              escape_0_nifjp9lau1(b_18, (*X60Qii_2));}
            else {
              put_1_nifjp9lau1(b_18, (*X60Qii_2));}}
          inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_7));}
        else {
          break;}}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  put_1_nifjp9lau1(b_18, (NC8)'\"');}
void addEmpty_0_nifjp9lau1(Builder_0_nifjp9lau1* b_19, NI64 count_0){
  addSep_0_nifjp9lau1(b_19);
  {
    NI64 X60Qlf_8 = IL64(1);
    NI64 X60Qlf_9 = count_0;
    NI64 X60Qlf_10 = X60Qlf_8;
    {
      while (X60Qlf_10 <= X60Qlf_9){
        {
          put_1_nifjp9lau1(b_19, (NC8)'.');}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_10));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;}
void addCharLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_20, NC8 c_2){
  addSep_0_nifjp9lau1(b_20);
  put_1_nifjp9lau1(b_20, (NC8)'\'');
  NB8 X60Qx_10;
  if (c_2 < (NC8)' '){
    X60Qx_10 = NIM_TRUE;}
  else {
    X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_22 = ControlChars_0_nifjp9lau1;
    NU64 X60Qdesugar_23 = ((NU)c_2);
    X60Qx_10 = (((NU8)(X60Qdesugar_22.a[((NU)(X60Qdesugar_23 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_23 & 7ull)))))) != 0ull);}
  if (X60Qx_10){
    escape_0_nifjp9lau1(b_20, c_2);}
  else {
    put_1_nifjp9lau1(b_20, c_2);}
  put_1_nifjp9lau1(b_20, (NC8)'\'');}
void addIntLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_21, NI64 i_0){
  addSep_0_nifjp9lau1(b_21);
  string_0_sysvq0asl X60Qtmp_3 = dollarQ_1_sysvq0asl(i_0);
  put_0_nifjp9lau1(b_21, X60Qtmp_3);
  nimStrDestroy(X60Qtmp_3);}
void addUIntLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_22, NU64 u_0){
  addSep_0_nifjp9lau1(b_22);
  string_0_sysvq0asl X60Qtmp_4 = dollarQ_0_sysvq0asl(u_0);
  put_0_nifjp9lau1(b_22, X60Qtmp_4);
  add_1_sysvq0asl((&(*b_22).buffer_0), (NC8)'u');
  plusQeQ_0_Ihg6mz11_mat7cnfv21((&(*b_22).offs_0), IL64(1));
  nimStrDestroy(X60Qtmp_4);}
void addFloatLit_0_nifjp9lau1(Builder_0_nifjp9lau1* b_24, NF64 f_0, NI32 col_1, NI32 line_1, string_0_sysvq0asl file_1){
  addSep_0_nifjp9lau1(b_24);
  NB8 X60Qx_50;
  NB8 X60Qx_51;
  if ((!(col_1 == ((NI32)IL64(0))))){
    X60Qx_51 = NIM_TRUE;}
  else {
    X60Qx_51 = (!(line_1 == ((NI32)IL64(0))));}
  if (X60Qx_51){
    X60Qx_50 = NIM_TRUE;}
  else {
    NI64 X60Qx_52 = len_4_sysvq0asl(file_1);
    X60Qx_50 = (IL64(0) < X60Qx_52);}
  NB8 hasInfo_0 = X60Qx_50;
  FloatClass_0_mat7cnfv21 X60Qx_53 = classify_0_Iva37xy1_nifjp9lau1(f_0);
  switch (X60Qx_53){
    case IL64(5):
    {
      put_0_nifjp9lau1(b_24, (string_0_sysvq0asl){
        .bytes_0 = 439939049476ull, .more_0 = NIM_NIL}
      );
      if (hasInfo_0){
        attachLineInfo_1_nifjp9lau1(b_24, col_1, line_1, file_1);}
      put_1_nifjp9lau1(b_24, (NC8)')');}
    break;
    case IL64(4):
    {
      put_0_nifjp9lau1(b_24, (string_0_sysvq0asl){
        .bytes_0 = 474081011716ull, .more_0 = NIM_NIL}
      );
      if (hasInfo_0){
        attachLineInfo_1_nifjp9lau1(b_24, col_1, line_1, file_1);}
      put_1_nifjp9lau1(b_24, (NC8)')');}
    break;
    case IL64(6):
    {
      put_0_nifjp9lau1(b_24, (string_0_sysvq0asl){
        .bytes_0 = 7380952732111087623ull, .more_0 = NIM_NIL}
      );
      if (hasInfo_0){
        attachLineInfo_1_nifjp9lau1(b_24, col_1, line_1, file_1);}
      put_1_nifjp9lau1(b_24, (NC8)')');}
    break;
    case IL64(3):
    {
      put_0_nifjp9lau1(b_24, (string_0_sysvq0asl){
        .bytes_0 = 206933339396ull, .more_0 = NIM_NIL}
      );
      if (hasInfo_0){
        attachLineInfo_1_nifjp9lau1(b_24, col_1, line_1, file_1);}}
    break;
    case IL64(0):
    case IL64(1):
    case IL64(2):
    {
      NI64 myLen_0 = len_4_sysvq0asl((*b_24).buffer_0);
      addFloat_0_sysvq0asl((&(*b_24).buffer_0), f_0);
      {
        NI64 X60Qlf_11 = myLen_0;
        NI64 X60Qlf_12 = len_4_sysvq0asl((*b_24).buffer_0);
        NI64 X60Qlf_13 = X60Qlf_11;
        {
          while (X60Qlf_13 < X60Qlf_12){
            {
              NC8 X60Qx_54 = getQ_9_sysvq0asl((*b_24).buffer_0, X60Qlf_13);
              if (X60Qx_54 == (NC8)'e'){
                putQ_9_sysvq0asl((&(*b_24).buffer_0), X60Qlf_13, (NC8)'E');}}
            inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_13));}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;
      NI64 X60Qx_55 = len_4_sysvq0asl((*b_24).buffer_0);
      plusQeQ_0_Ihg6mz11_mat7cnfv21((&(*b_24).offs_0), ((NI64)(X60Qx_55 - myLen_0)));
      if (hasInfo_0){
        attachLineInfo_1_nifjp9lau1(b_24, col_1, line_1, file_1);}}
    break;}}
static inline NC8 b62Char_0_nifjp9lau1(NI64 d_0){
  NC8 result_7;
  NC8 X60Qx_11;
  if (d_0 < IL64(10)){
    X60Qx_11 = ((NC8)((NI64)(((NI64)(NC8)'0') + d_0)));}
  else {
    if (d_0 < IL64(36)){
      X60Qx_11 = ((NC8)((NI64)(((NI64)(((NI64)(NC8)'A') + d_0)) - IL64(10))));}
    else {
      X60Qx_11 = ((NC8)((NI64)(((NI64)(((NI64)(NC8)'a') + d_0)) - IL64(36))));}}
  result_7 = X60Qx_11;
  return result_7;}
void addB62Unsigned_0_nifjp9lau1(Builder_0_nifjp9lau1* b_25, NU64 n0_0){
  if (n0_0 == ((NU64)IL64(0))){
    put_1_nifjp9lau1(b_25, (NC8)'0');}
  else {
    X60Qt_0_IAarrayAcS8ZS12_nifjp9lau1 buf_0;
    NI64 i_6 = IL64(0);
    NU64 n_1 = n0_0;
    {
      while (((NU64)0ull) < n_1){
        NI64 X60Qx_56 = nimIcheckB(i_6, IL64(11));
        NC8 X60Qx_57 = b62Char_0_nifjp9lau1(((NI64)((NU64)(n_1 % ((NU64)62ull)))));
        buf_0.a[X60Qx_56] = X60Qx_57;
        n_1 = ((NU64)(n_1 / ((NU64)62ull)));
        inc_1_Irn1g7r1_aif7a4qfr((&i_6));}}
    whileStmtLabel_0: ;
    {
      while (IL64(0) < i_6){
        dec_1_I2mwrey1_envto7w6l1((&i_6));
        NI64 X60Qx_58 = nimIcheckB(i_6, IL64(11));
        put_1_nifjp9lau1(b_25, buf_0.a[X60Qx_58]);}}
    whileStmtLabel_1: ;}}
static inline void addLineDiff_0_nifjp9lau1(Builder_0_nifjp9lau1* b_26, NI32 x_0, NB8 emitZero_0){
  if (x_0 < ((NI32)IL64(0))){
    put_1_nifjp9lau1(b_26, (NC8)'~');
    addB62Unsigned_0_nifjp9lau1(b_26, ((NU64)((NI64)-((NI64)x_0))));}
  else {
    if (((NI32)IL64(0)) < x_0){
      addB62Unsigned_0_nifjp9lau1(b_26, ((NU64)x_0));}
    else {
      if (emitZero_0){
        put_1_nifjp9lau1(b_26, (NC8)'0');}}}}
void attachLineInfo_1_nifjp9lau1(Builder_0_nifjp9lau1* b_27, NI32 col_2, NI32 line_2, string_0_sysvq0asl file_2){
  NB8 X60Qx_59;
  NB8 X60Qx_60;
  if (col_2 == ((NI32)IL64(0))){
    X60Qx_60 = (line_2 == ((NI32)IL64(0)));}
  else {
    X60Qx_60 = NIM_FALSE;}
  if (X60Qx_60){
    NI64 X60Qx_61 = len_4_sysvq0asl(file_2);
    X60Qx_59 = (X60Qx_61 == IL64(0));}
  else {
    X60Qx_59 = NIM_FALSE;}
  if (X60Qx_59){
    return;}
  drainPending_0_nifjp9lau1(b_27);
  if (col_2 < ((NI32)IL64(0))){
    put_1_nifjp9lau1(b_27, (NC8)'~');
    addB62Unsigned_0_nifjp9lau1(b_27, ((NU64)((NI64)-((NI64)col_2))));}
  else {
    put_1_nifjp9lau1(b_27, (NC8)'@');
    if (((NI32)IL64(0)) < col_2){
      addB62Unsigned_0_nifjp9lau1(b_27, ((NU64)col_2));}}
  NB8 X60Qx_62;
  if ((!(line_2 == ((NI32)IL64(0))))){
    X60Qx_62 = NIM_TRUE;}
  else {
    NI64 X60Qx_63 = len_4_sysvq0asl(file_2);
    X60Qx_62 = (IL64(0) < X60Qx_63);}
  if (X60Qx_62){
    put_1_nifjp9lau1(b_27, (NC8)',');
    addLineDiff_0_nifjp9lau1(b_27, line_2, NIM_FALSE);}
  NI64 X60Qx_64 = len_4_sysvq0asl(file_2);
  if (IL64(0) < X60Qx_64){
    put_1_nifjp9lau1(b_27, (NC8)',');
    {
      openArray_0_Ijk0jkw1_has9tn57v X60Qlf_14 = toOpenArray_2_sysvq0asl((&file_2));
      NI64 X60Qlf_15 = IL64(0);
      {
        while (NIM_TRUE){
          NI64 X60Qx_65 = len_6_Iroq7kd1_has9tn57v(X60Qlf_14);
          if (X60Qlf_15 < X60Qx_65){
            {
              NC8* X60Qii_2 = getQ_10_I5nt6we_has9tn57v(X60Qlf_14, X60Qlf_15);
              NB8 X60Qx_12;
              if ((*X60Qii_2) < (NC8)' '){
                X60Qx_12 = NIM_TRUE;}
              else {
                X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1 X60Qdesugar_24 = ControlChars_0_nifjp9lau1;
                NU64 X60Qdesugar_25 = ((NU)(*X60Qii_2));
                X60Qx_12 = (((NU8)(X60Qdesugar_24.a[((NU)(X60Qdesugar_25 >> 3ull))] & ((NU8)(1ull << ((NU)(X60Qdesugar_25 & 7ull)))))) != 0ull);}
              if (X60Qx_12){
                escape_0_nifjp9lau1(b_27, (*X60Qii_2));}
              else {
                put_1_nifjp9lau1(b_27, (*X60Qii_2));}}
            inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_15));}
          else {
            break;}}}
      whileStmtLabel_1: ;}
    forStmtLabel_0: ;}}
void addTree_0_nifjp9lau1(Builder_0_nifjp9lau1* b_31, string_0_sysvq0asl kind_0){
  drainPending_0_nifjp9lau1(b_31);
  if ((!(*b_31).compact_0)){
    if (IL64(0) < (*b_31).nesting_0){
      put_0_nifjp9lau1(b_31, (string_0_sysvq0asl){
        .bytes_0 = 2561ull, .more_0 = NIM_NIL}
      );
      {
        NI64 X60Qlf_18 = IL64(1);
        NI64 X60Qlf_19 = (*b_31).nesting_0;
        NI64 X60Qlf_20 = X60Qlf_18;
        {
          while (X60Qlf_20 <= X60Qlf_19){
            {
              put_1_nifjp9lau1(b_31, (NC8)' ');}
            inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_20));}}
        whileStmtLabel_1: ;}
      forStmtLabel_0: ;}
    put_1_nifjp9lau1(b_31, (NC8)'(');}
  else {
    put_0_nifjp9lau1(b_31, (string_0_sysvq0asl){
      .bytes_0 = 2624002ull, .more_0 = NIM_NIL}
    );}
  put_0_nifjp9lau1(b_31, kind_0);
  inc_1_Irn1g7r1_aif7a4qfr((&(*b_31).nesting_0));}
void endTree_0_nifjp9lau1(Builder_0_nifjp9lau1* b_32){
  if ((!(IL64(0) < (*b_32).nesting_0))){
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 8390880602273963006ull, .more_0 = (&strlit_0_I14676000009897902695_assy765wm)}
    );
    write_0_syn1lfpjv(stdout, (string_0_sysvq0asl){
      .bytes_0 = 8386109761109977086ull, .more_0 = (&strlit_0_I2857462522550599008_nifjp9lau1)}
    );
    write_7_syn1lfpjv(stdout, (NC8)'\012');
    quit_0_syn1lfpjv(IL64(1));}
  if (IL64(0) <= (*b_32).nesting_0){
    dec_1_I2mwrey1_envto7w6l1((&(*b_32).nesting_0));}
  undoWhitespace_0_nifjp9lau1(b_32);
  put_1_nifjp9lau1(b_32, (NC8)')');}
void addStrLit_1_nifjp9lau1(Builder_0_nifjp9lau1* b_35, string_0_sysvq0asl s_13, string_0_sysvq0asl suffix_1, NI32 col_5, NI32 line_5, string_0_sysvq0asl file_5){
  addTree_0_nifjp9lau1(b_35, (string_0_sysvq0asl){
    .bytes_0 = 1718973187ull, .more_0 = NIM_NIL}
  );
  NB8 X60Qx_70;
  NB8 X60Qx_71;
  if ((!(col_5 == ((NI32)IL64(0))))){
    X60Qx_71 = NIM_TRUE;}
  else {
    X60Qx_71 = (!(line_5 == ((NI32)IL64(0))));}
  if (X60Qx_71){
    X60Qx_70 = NIM_TRUE;}
  else {
    NI64 X60Qx_72 = len_4_sysvq0asl(file_5);
    X60Qx_70 = (IL64(0) < X60Qx_72);}
  if (X60Qx_70){
    attachLineInfo_1_nifjp9lau1(b_35, col_5, line_5, file_5);}
  addStrLit_0_nifjp9lau1(b_35, s_13);
  addStrLit_0_nifjp9lau1(b_35, suffix_1);
  endTree_0_nifjp9lau1(b_35);}
static inline void minusQeQ_0_Isqosxa_nifjp9lau1(NI64* x_10, NI64 y_3){
  (*x_10) = ((NI64)((*x_10) - y_3));}
static inline FloatClass_0_mat7cnfv21 classify_0_Iva37xy1_nifjp9lau1(NF64 x_13){
  FloatClass_0_mat7cnfv21 result_11;
  string_0_sysvq0asl X60Qx_77 = (string_0_sysvq0asl){
    .bytes_0 = 2334397804780677630ull, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  NI64 r_0 = fpclassify(x_13);
  if (r_0 == FP_NORMAL){
    result_11 = IL64(0);}
  else {
    if (r_0 == FP_SUBNORMAL){
      result_11 = IL64(1);}
    else {
      if (r_0 == FP_ZERO){
        FloatClass_0_mat7cnfv21 X60Qx_14;
        NB8 X60Qx_78 = signbit_0_I8usf6p_nifjp9lau1(x_13);
        if (X60Qx_78){
          X60Qx_14 = IL64(3);}
        else {
          X60Qx_14 = IL64(2);}
        result_11 = X60Qx_14;}
      else {
        if (r_0 == FP_NAN){
          result_11 = IL64(4);}
        else {
          if (r_0 == FP_INFINITE){
            FloatClass_0_mat7cnfv21 X60Qx_15;
            NB8 X60Qx_79 = signbit_0_I8usf6p_nifjp9lau1(x_13);
            if (X60Qx_79){
              X60Qx_15 = IL64(6);}
            else {
              X60Qx_15 = IL64(5);}
            result_11 = X60Qx_15;}
          else {
            result_11 = IL64(4);}}}}}
  return result_11;}
static inline NB8 signbit_0_I8usf6p_nifjp9lau1(NF64 x_18){
  NB8 result_14;
  string_0_sysvq0asl X60Qx_81 = (string_0_sysvq0asl){
    .bytes_0 = 2334397804780677630ull, .more_0 = (&strlit_0_I8031254106179394417_dir38pj6l)}
  ;
  NI64 X60Qx_82 = signbit(x_18);
  result_14 = (!(X60Qx_82 == IL64(0)));
  return result_14;}
void eQwasmovedQ_SX42uilder0nifjp9lau1_0_nifjp9lau1(Builder_0_nifjp9lau1* dest_0){
  nimStrWasMoved((&(*dest_0).buffer_0));
  nimStrWasMoved((&(*dest_0).filename_0));}
void eQdestroyQ_SX42uilder0nifjp9lau1_0_nifjp9lau1(Builder_0_nifjp9lau1* dest_0){
  nimStrDestroy((*dest_0).filename_0);
  nimStrDestroy((*dest_0).buffer_0);}
void X60Qini_0_nifjp9lau1(void){
  if (X60QiniGuard_0_nifjp9lau1){
    return;}
  X60QiniGuard_0_nifjp9lau1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_assy765wm();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_for2ybv4p1();
  X60Qini_0_mat7cnfv21();
  X60Qini_0_str7j0ifg();
  X60Qini_0_vfsc9jn7();}
static inline string_0_sysvq0asl nimStrDup(string_0_sysvq0asl s_40){
  string_0_sysvq0asl result_66;
  NI64 X60Qx_83 = ssLenOf_0_sysvq0asl(s_40.bytes_0);
  if (X60Qx_83 == ((NI64)IL64(255))){
    arcInc_0_sysvq0asl((&(*s_40.more_0).rc_0));}
  result_66 = (string_0_sysvq0asl){
    .bytes_0 = s_40.bytes_0, .more_0 = s_40.more_0}
  ;
  return result_66;}
static inline NB8 vfsExists_0_vfsc9jn7(string_0_sysvq0asl path_3){
  NB8 result_15;
  NB8 X60Qx_17 = existsRelay_0_vfsc9jn7(path_3);
  result_15 = X60Qx_17;
  return result_15;}
static inline string_0_sysvq0asl vfsRead_0_vfsc9jn7(string_0_sysvq0asl path_1){
  string_0_sysvq0asl result_14;
  nimStrWasMoved((&result_14));
  nimStrDestroy(result_14);
  string_0_sysvq0asl X60Qx_16 = readBytesRelay_0_vfsc9jn7(path_1);
  result_14 = X60Qx_16;
  return result_14;}
static inline NB8 eqQ_20_sysvq0asl(string_0_sysvq0asl a_14, string_0_sysvq0asl b_10){
  NB8 result_88;
  NB8 X60Qx_142 = equalStrings_0_sysvq0asl(a_14, b_10);
  result_88 = X60Qx_142;
  return result_88;}
static inline void nimStrDestroy(string_0_sysvq0asl s_39){
  if (((NI64)(*((NU8*)(&s_39.bytes_0)))) == ((NI64)IL64(255))){
    NB8 X60Qx_80 = arcDec_0_sysvq0asl((&(*s_39.more_0).rc_0));
    if (X60Qx_80){
      dealloc_0_sysvq0asl(((void*)s_39.more_0));}}}
static inline void vfsWrite_0_vfsc9jn7(string_0_sysvq0asl path_2, string_0_sysvq0asl content_0){
  writeBytesRelay_0_vfsc9jn7(path_2, content_0);}
static inline NI64 len_4_sysvq0asl(string_0_sysvq0asl s_32){
  NI64 result_60;
  result_60 = ((NI64)(*((NU8*)(&s_32.bytes_0))));
  if (((NI64)IL64(14)) < result_60){
    result_60 = (*s_32.more_0).fullLen_0;}
  return result_60;}
static inline void plusQeQ_0_Ihg6mz11_mat7cnfv21(NI64* x_147, NI64 y_41){
  (*x_147) = ((NI64)((*x_147) + y_41));}
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
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1){
  (*x_1) = ((NI64)((*x_1) + ((NI64)IL64(1))));}
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
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38){
  (*s_38).bytes_0 = ((NU64)IL64(0));}
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
