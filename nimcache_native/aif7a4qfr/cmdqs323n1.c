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
typedef struct string_0_sysvq0asl string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl LongString_0_sysvq0asl;
typedef struct seq_0_Ixdx2fh1_aif7a4qfr{
  NI64 len_0;
  string_0_sysvq0asl* data_0;}
seq_0_Ixdx2fh1_aif7a4qfr;
typedef struct X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1{
  NU8 a[IL64(32)];}
X60Qt_0_IAarrayAuS8ZS32_cmdqs323n1;
typedef struct string_0_sysvq0asl{
  NU64 bytes_0;
  LongString_0_sysvq0asl* more_0;}
string_0_sysvq0asl;
typedef struct LongString_0_sysvq0asl{
  NI64 fullLen_0;
  NI64 rc_0;
  NI64 capImpl_0;
  NC8 data_0[];}
LongString_0_sysvq0asl;
typedef N_NIMCALL_PTR(void,  X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl)(NI64);
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38);
static inline void nimStrDestroy(string_0_sysvq0asl s_39);
extern string_0_sysvq0asl dollarQ_0_str7j0ifg(NC8* x_1);
static inline void eQwasMoved_1_I5vdnla_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_11);
extern void eQdestroy_1_Ivioh0a_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_10);
static inline seq_0_Ixdx2fh1_aif7a4qfr newSeqUninit_0_Im3cqd9_aif7a4qfr(NI64 size_1);
static inline void add_0_Ig6072n_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_5, string_0_sysvq0asl elem_1);
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1);
extern void X60Qini_0_sysvq0asl(void);
extern void X60Qini_0_wid623gv(void);
extern void X60Qini_0_syn1lfpjv(void);
extern void X60Qini_0_pososrh1q1(void);
extern void X60Qini_0_str7j0ifg(void);
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1);
extern void dealloc_0_sysvq0asl(void* p_10);
static inline NI64 memSizeInBytes_0_I7me00i_aif7a4qfr(NI64 size_3);
extern void* alloc_0_sysvq0asl(NI64 size_10);
extern LongString_0_sysvq0asl const strlit_0_I15750996627617194403_aif7a4qfr;
extern X60Qt_0_IAiS64ZSEAnimcallZAfalseZAR17_sysvq0asl oomHandler_0_sysvq0asl;
static inline NI64 capInBytes_0_Ih2sbn01_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr s_7);
extern NB8 resize_0_I4buliy_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* dest_1, NI64 addedElements_1);
extern NI64 allocatedSize_0_sysvq0asl(void* p_11);
extern int cmdCount;
extern NC8** cmdLine;
NB8 X60QiniGuard_0_cmdqs323n1;
string_0_sysvq0asl paramStr_0_cmdqs323n1(NI64 i_0){
  string_0_sysvq0asl result_1;
  nimStrWasMoved((&result_1));
  NB8 X60Qx_17;
  if (i_0 < ((NI64)cmdCount)){
    X60Qx_17 = (IL64(0) <= i_0);}
  else {
    X60Qx_17 = NIM_FALSE;}
  if (X60Qx_17){
    nimStrDestroy(result_1);
    string_0_sysvq0asl X60Qx_18 = dollarQ_0_str7j0ifg(cmdLine[i_0]);
    result_1 = X60Qx_18;}
  else {
    nimStrDestroy(result_1);
    result_1 = (string_0_sysvq0asl){
      .bytes_0 = 0ull, .more_0 = NIM_NIL}
    ;}
  return result_1;}
NI64 paramCount_0_cmdqs323n1(void){
  NI64 result_2;
  result_2 = ((NI64)((NI32)(cmdCount - ((NI32)IL64(1)))));
  return result_2;}
seq_0_Ixdx2fh1_aif7a4qfr commandLineParams_0_cmdqs323n1(void){
  seq_0_Ixdx2fh1_aif7a4qfr result_3;
  eQwasMoved_1_I5vdnla_aif7a4qfr((&result_3));
  eQdestroy_1_Ivioh0a_aif7a4qfr(result_3);
  seq_0_Ixdx2fh1_aif7a4qfr X60Qx_19 = newSeqUninit_0_Im3cqd9_aif7a4qfr(IL64(0));
  result_3 = X60Qx_19;
  {
    NI64 X60Qlf_0 = IL64(1);
    NI64 X60Qlf_1 = paramCount_0_cmdqs323n1();
    NI64 X60Qlf_2 = X60Qlf_0;
    {
      while (X60Qlf_2 <= X60Qlf_1){
        {
          string_0_sysvq0asl X60Qx_20 = paramStr_0_cmdqs323n1(X60Qlf_2);
          add_0_Ig6072n_aif7a4qfr((&result_3), X60Qx_20);}
        inc_1_Irn1g7r1_aif7a4qfr((&X60Qlf_2));}}
    whileStmtLabel_1: ;}
  forStmtLabel_0: ;
  return result_3;}
void X60Qini_0_cmdqs323n1(void){
  if (X60QiniGuard_0_cmdqs323n1){
    return;}
  X60QiniGuard_0_cmdqs323n1 = NIM_TRUE;
  X60Qini_0_sysvq0asl();
  X60Qini_0_wid623gv();
  X60Qini_0_syn1lfpjv();
  X60Qini_0_pososrh1q1();
  X60Qini_0_str7j0ifg();}
static inline void nimStrWasMoved(string_0_sysvq0asl* s_38){
  (*s_38).bytes_0 = ((NU64)IL64(0));}
static inline void nimStrDestroy(string_0_sysvq0asl s_39){
  if (((NI64)(*((NU8*)(&s_39.bytes_0)))) == ((NI64)IL64(255))){
    NB8 X60Qx_80 = arcDec_0_sysvq0asl((&(*s_39.more_0).rc_0));
    if (X60Qx_80){
      dealloc_0_sysvq0asl(((void*)s_39.more_0));}}}
static inline void eQwasMoved_1_I5vdnla_aif7a4qfr(seq_0_Ixdx2fh1_aif7a4qfr* s_11){
  (*s_11).len_0 = IL64(0);
  (*s_11).data_0 = NIM_NIL;}
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
static inline void inc_1_Irn1g7r1_aif7a4qfr(NI64* x_1){
  (*x_1) = ((NI64)((*x_1) + ((NI64)IL64(1))));}
static inline NB8 arcDec_0_sysvq0asl(NI64* memLoc_1){
  NB8 result_118;
  NI64 X60Qx_178 = __atomic_sub_fetch((&(*memLoc_1)), IL64(1), __ATOMIC_SEQ_CST);
  result_118 = (X60Qx_178 < IL64(0));
  return result_118;}
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
