#ifndef STDATOMIC_H
#define STDATOMIC_H

#include <stdint.h>

#include "irq_arch.h"

//From /usr/include/boost/config/compiler/cray.hpp
// These constants should be provided by the
// compiler, at least when -hgnu is asserted on the command line.
#ifndef __ATOMIC_RELAXED
#define __ATOMIC_RELAXED 0
#define __ATOMIC_CONSUME 1
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_RELEASE 3
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_SEQ_CST 5
#endif

#ifndef __USE_ISOCXX11
/* Define the 16-bit and 32-bit character types.  */
//~ typedef __uint_least8_t char8_t;
//~ typedef __uint_least16_t char16_t;
//~ typedef __uint_least32_t char32_t;
typedef int8_t __INT_LEAST8_TYPE__;
typedef uint8_t __UINT_LEAST8_TYPE__;
typedef int16_t __INT_LEAST16_TYPE__;
typedef uint16_t __UINT_LEAST16_TYPE__;
typedef int32_t __INT_LEAST32_TYPE__;
typedef uint32_t __UINT_LEAST32_TYPE__;
typedef int64_t __INT_LEAST64_TYPE__;
typedef uint64_t __UINT_LEAST64_TYPE__;
typedef int32_t __INT_FAST8_TYPE__;
typedef uint32_t __UINT_FAST8_TYPE__;
typedef int32_t __INT_FAST16_TYPE__;
typedef uint32_t __UINT_FAST16_TYPE__;
typedef int32_t __INT_FAST32_TYPE__;
typedef uint32_t __UINT_FAST32_TYPE__;
typedef int64_t __INT_FAST64_TYPE__;
typedef uint64_t __UINT_FAST64_TYPE__;
typedef int32_t * __INTPTR_TYPE__;
typedef uint32_t * __UINTPTR_TYPE__;
//~ typedef char16_t __CHAR16_TYPE__;
//~ typedef char32_t __CHAR32_TYPE__;
typedef int16_t __CHAR16_TYPE__;
typedef int32_t __CHAR32_TYPE__;
#endif

typedef enum
  {
    memory_order_relaxed = __ATOMIC_RELAXED,
    memory_order_consume = __ATOMIC_CONSUME,
    memory_order_acquire = __ATOMIC_ACQUIRE,
    memory_order_release = __ATOMIC_RELEASE,
    memory_order_acq_rel = __ATOMIC_ACQ_REL,
    memory_order_seq_cst = __ATOMIC_SEQ_CST
  } memory_order;

#ifndef __auto_type
#define __auto_type
#endif

#define _Atomic
typedef _Atomic _Bool atomic_bool;
typedef _Atomic char atomic_char;
typedef _Atomic signed char atomic_schar;
typedef _Atomic unsigned char atomic_uchar;
typedef _Atomic short atomic_short;
typedef _Atomic unsigned short atomic_ushort;
typedef _Atomic int atomic_int;
typedef _Atomic unsigned int atomic_uint;
typedef _Atomic long atomic_long;
typedef _Atomic unsigned long atomic_ulong;
typedef _Atomic long long atomic_llong;
typedef _Atomic unsigned long long atomic_ullong;
typedef _Atomic __CHAR16_TYPE__ atomic_char16_t;
typedef _Atomic __CHAR32_TYPE__ atomic_char32_t;
typedef _Atomic __WCHAR_TYPE__ atomic_wchar_t;
typedef _Atomic __INT_LEAST8_TYPE__ atomic_int_least8_t;
typedef _Atomic __UINT_LEAST8_TYPE__ atomic_uint_least8_t;
typedef _Atomic __INT_LEAST16_TYPE__ atomic_int_least16_t;
typedef _Atomic __UINT_LEAST16_TYPE__ atomic_uint_least16_t;
typedef _Atomic __INT_LEAST32_TYPE__ atomic_int_least32_t;
typedef _Atomic __UINT_LEAST32_TYPE__ atomic_uint_least32_t;
typedef _Atomic __INT_LEAST64_TYPE__ atomic_int_least64_t;
typedef _Atomic __UINT_LEAST64_TYPE__ atomic_uint_least64_t;
typedef _Atomic __INT_FAST8_TYPE__ atomic_int_fast8_t;
typedef _Atomic __UINT_FAST8_TYPE__ atomic_uint_fast8_t;
typedef _Atomic __INT_FAST16_TYPE__ atomic_int_fast16_t;
typedef _Atomic __UINT_FAST16_TYPE__ atomic_uint_fast16_t;
typedef _Atomic __INT_FAST32_TYPE__ atomic_int_fast32_t;
typedef _Atomic __UINT_FAST32_TYPE__ atomic_uint_fast32_t;
typedef _Atomic __INT_FAST64_TYPE__ atomic_int_fast64_t;
typedef _Atomic __UINT_FAST64_TYPE__ atomic_uint_fast64_t;
typedef _Atomic __INTPTR_TYPE__ atomic_intptr_t;
typedef _Atomic __UINTPTR_TYPE__ atomic_uintptr_t;
typedef _Atomic __SIZE_TYPE__ atomic_size_t;
typedef _Atomic __PTRDIFF_TYPE__ atomic_ptrdiff_t;
typedef _Atomic __INTMAX_TYPE__ atomic_intmax_t;
typedef _Atomic __UINTMAX_TYPE__ atomic_uintmax_t;

#ifndef ATOMIC_VAR_INIT
#define ATOMIC_VAR_INIT(x) (x)
#endif

atomic_int_least16_t atomic_load_explicit(atomic_int_least16_t * ptr, const int mo);
void atomic_store_explicit(atomic_int_least16_t * ptr, atomic_int_least16_t val, const int mo);

#endif /* STDATOMIC_H */
