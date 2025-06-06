/*
 * AUTOGENERATED by mrustc
 */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <assert.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>
typedef uint32_t RUST_CHAR;
typedef uint8_t RUST_BOOL;
typedef struct { void* PTR; size_t META; } SLICE_PTR;
typedef struct { void* PTR; void* META; } TRAITOBJ_PTR;
typedef struct { void (*drop)(void*); size_t size; size_t align; } VTABLE_HDR;
typedef struct { char _d; } tUNIT;
typedef char tBANG;
typedef struct { char _d; } tTYPEID;
static inline size_t ALIGN_TO(size_t s, size_t a) { return (s + a-1) / a * a; }

extern void _Unwind_Resume(void) __attribute__((noreturn));
#define ALIGNOF(t) __alignof__(t)
extern __thread jmp_buf*    mrustc_panic_target;
extern __thread void* mrustc_panic_value;
static inline uint64_t __builtin_clz64(uint64_t v) {
	return ( (v >> 32) != 0 ? __builtin_clz(v>>32) : 32 + __builtin_clz(v));
}
static inline uint64_t __builtin_ctz64(uint64_t v) {
	return ((v&0xFFFFFFFF) == 0 ? __builtin_ctz(v>>32) + 32 : __builtin_ctz(v));
}
static inline uint8_t __mrustc_atomicloop8(volatile uint8_t* slot, uint8_t param, int ordering, uint8_t (*cb)(uint8_t, uint8_t)) { int ordering_load = (ordering == memory_order_release || ordering == memory_order_acq_rel ? memory_order_relaxed : ordering); for(;;) { uint8_t v = atomic_load_explicit((_Atomic uint8_t*)slot, ordering_load); if( atomic_compare_exchange_strong_explicit((_Atomic uint8_t*)slot, &v, cb(v, param), ordering, ordering_load) ) return v; }}
static inline uint16_t __mrustc_atomicloop16(volatile uint16_t* slot, uint16_t param, int ordering, uint16_t (*cb)(uint16_t, uint16_t)) { int ordering_load = (ordering == memory_order_release || ordering == memory_order_acq_rel ? memory_order_relaxed : ordering); for(;;) { uint16_t v = atomic_load_explicit((_Atomic uint16_t*)slot, ordering_load); if( atomic_compare_exchange_strong_explicit((_Atomic uint16_t*)slot, &v, cb(v, param), ordering, ordering_load) ) return v; }}
static inline uint32_t __mrustc_atomicloop32(volatile uint32_t* slot, uint32_t param, int ordering, uint32_t (*cb)(uint32_t, uint32_t)) { int ordering_load = (ordering == memory_order_release || ordering == memory_order_acq_rel ? memory_order_relaxed : ordering); for(;;) { uint32_t v = atomic_load_explicit((_Atomic uint32_t*)slot, ordering_load); if( atomic_compare_exchange_strong_explicit((_Atomic uint32_t*)slot, &v, cb(v, param), ordering, ordering_load) ) return v; }}
static inline uint64_t __mrustc_atomicloop64(volatile uint64_t* slot, uint64_t param, int ordering, uint64_t (*cb)(uint64_t, uint64_t)) { int ordering_load = (ordering == memory_order_release || ordering == memory_order_acq_rel ? memory_order_relaxed : ordering); for(;;) { uint64_t v = atomic_load_explicit((_Atomic uint64_t*)slot, ordering_load); if( atomic_compare_exchange_strong_explicit((_Atomic uint64_t*)slot, &v, cb(v, param), ordering, ordering_load) ) return v; }}
typedef unsigned __int128 uint128_t;
typedef signed __int128 int128_t;
static inline uint128_t __builtin_bswap128(uint128_t v) {
	uint64_t lo = __builtin_bswap64((uint64_t)v);
	uint64_t hi = __builtin_bswap64((uint64_t)(v>>64));
	return ((uint128_t)lo << 64) | (uint128_t)hi;
}
static inline uint128_t intrinsic_ctlz_u128(uint128_t v) {
	return (v == 0 ? 128 : (v >> 64 != 0 ? __builtin_clz64(v>>64) : 64 + __builtin_clz64(v)));
}
static inline uint128_t intrinsic_cttz_u128(uint128_t v) {
	return (v == 0 ? 128 : ((v&0xFFFFFFFFFFFFFFFF) == 0 ? __builtin_ctz64(v>>64) + 64 : __builtin_ctz64(v)));
}

static inline int slice_cmp(SLICE_PTR l, SLICE_PTR r) {
	int rv = memcmp(l.PTR, r.PTR, l.META < r.META ? l.META : r.META);
	if(rv != 0) return rv;
	if(l.META < r.META) return -1;
	if(l.META > r.META) return 1;
	return 0;
}
static inline SLICE_PTR make_sliceptr(void* ptr, size_t s) { SLICE_PTR rv = { ptr, s }; return rv; }
static inline TRAITOBJ_PTR make_traitobjptr(void* ptr, void* vt) { TRAITOBJ_PTR rv = { ptr, vt }; return rv; }

static inline size_t mrustc_max(size_t a, size_t b) { return a < b ? b : a; }
static inline void noop_drop(tUNIT *p) { }

static inline size_t mrustc_string_search_linear(SLICE_PTR val, size_t count, SLICE_PTR* options) {
	for(size_t i = 0; i < count; i ++) {
		int cmp = slice_cmp(val, options[i]);
		if(cmp < 0) break;
		if(cmp == 0) return i;
	}
	return SIZE_MAX;
}
static const uint8_t __mrustc_revmap[16] = { 0, 8, 4,12, 2,10, 6,14,  1, 9, 5,13, 3, 7,15};
static inline uint8_t __mrustc_bitrev8(uint8_t v) { if(v==0||v==0xFF) return v; return __mrustc_revmap[v>>4]|(__mrustc_revmap[v&15]<<4); }
static inline uint16_t __mrustc_bitrev16(uint16_t v) { if(v==0) return 0; return ((uint16_t)__mrustc_bitrev8(v>>8))|((uint16_t)__mrustc_bitrev8(v)<<8); }
static inline uint32_t __mrustc_bitrev32(uint32_t v) { if(v==0) return 0; return ((uint32_t)__mrustc_bitrev16(v>>16))|((uint32_t)__mrustc_bitrev16(v)<<16); }
static inline uint64_t __mrustc_bitrev64(uint64_t v) { if(v==0) return 0; return ((uint64_t)__mrustc_bitrev32(v>>32))|((uint64_t)__mrustc_bitrev32(v)<<32); }
static inline uint128_t __mrustc_bitrev128(uint128_t v) { if(v==0) return 0; uint128_t rv = ((uint128_t)__mrustc_bitrev64(v>>64))|((uint128_t)__mrustc_bitrev64(v)<<64); return rv; }
static inline uint8_t __mrustc_op_umax8(uint8_t a, uint8_t b) { return (a > b ? a : b); }
static inline uint8_t __mrustc_op_umin8(uint8_t a, uint8_t b) { return (a < b ? a : b); }
static inline uint8_t __mrustc_op_imax8(uint8_t a, uint8_t b) { return ((int8_t)a > (int8_t)b ? a : b); }
static inline uint8_t __mrustc_op_imin8(uint8_t a, uint8_t b) { return ((int8_t)a < (int8_t)b ? a : b); }
static inline uint8_t __mrustc_op_and_not8(uint8_t a, uint8_t b) { return ~(a & b); }
static inline uint16_t __mrustc_op_umax16(uint16_t a, uint16_t b) { return (a > b ? a : b); }
static inline uint16_t __mrustc_op_umin16(uint16_t a, uint16_t b) { return (a < b ? a : b); }
static inline uint16_t __mrustc_op_imax16(uint16_t a, uint16_t b) { return ((int16_t)a > (int16_t)b ? a : b); }
static inline uint16_t __mrustc_op_imin16(uint16_t a, uint16_t b) { return ((int16_t)a < (int16_t)b ? a : b); }
static inline uint16_t __mrustc_op_and_not16(uint16_t a, uint16_t b) { return ~(a & b); }
static inline uint32_t __mrustc_op_umax32(uint32_t a, uint32_t b) { return (a > b ? a : b); }
static inline uint32_t __mrustc_op_umin32(uint32_t a, uint32_t b) { return (a < b ? a : b); }
static inline uint32_t __mrustc_op_imax32(uint32_t a, uint32_t b) { return ((int32_t)a > (int32_t)b ? a : b); }
static inline uint32_t __mrustc_op_imin32(uint32_t a, uint32_t b) { return ((int32_t)a < (int32_t)b ? a : b); }
static inline uint32_t __mrustc_op_and_not32(uint32_t a, uint32_t b) { return ~(a & b); }
static inline uint64_t __mrustc_op_umax64(uint64_t a, uint64_t b) { return (a > b ? a : b); }
static inline uint64_t __mrustc_op_umin64(uint64_t a, uint64_t b) { return (a < b ? a : b); }
static inline uint64_t __mrustc_op_imax64(uint64_t a, uint64_t b) { return ((int64_t)a > (int64_t)b ? a : b); }
static inline uint64_t __mrustc_op_imin64(uint64_t a, uint64_t b) { return ((int64_t)a < (int64_t)b ? a : b); }
static inline uint64_t __mrustc_op_and_not64(uint64_t a, uint64_t b) { return ~(a & b); }
// enum ::"core-0_0_0"::cmp::Ordering
struct e_ZRG2cE9core0_0_03cmp8Ordering0g {
	int8_t TAG;
};
typedef char sizeof_assert_ZRG2cE9core0_0_03cmp8Ordering0g[ (sizeof(struct e_ZRG2cE9core0_0_03cmp8Ordering0g) == 1) ? 1 : -1 ];
struct s_ZRG2cE9core0_0_03fmt9Formatter0g;
// struct ::"core-0_0_0"::result::Result#Ok<(),::"core-0_0_0"::fmt::Error/*S*/,>
struct s_ZRG2cE9core0_0_06resultG8ResultOk2gT0G2c_A3fmt5Error0g  {
	/*@0*/uint8_t _1; // u8
	/*@1*/// ZST; // ()
} __attribute__((__aligned__(1),)) ;
typedef char sizeof_assert_ZRG2cE9core0_0_06resultG8ResultOk2gT0G2c_A3fmt5Error0g[ (sizeof(struct s_ZRG2cE9core0_0_06resultG8ResultOk2gT0G2c_A3fmt5Error0g) == 1) ? 1 : -1 ];
typedef char alignof_assert_ZRG2cE9core0_0_06resultG8ResultOk2gT0G2c_A3fmt5Error0g[ (ALIGNOF(struct s_ZRG2cE9core0_0_06resultG8ResultOk2gT0G2c_A3fmt5Error0g) == 1) ? 1 : -1 ];
// struct ::"core-0_0_0"::fmt::Error
struct s_ZRG2cE9core0_0_03fmt5Error0g  {
	char _d;
} __attribute__((__aligned__(1),)) ;
typedef char alignof_assert_ZRG2cE9core0_0_03fmt5Error0g[ (ALIGNOF(struct s_ZRG2cE9core0_0_03fmt5Error0g) == 1) ? 1 : -1 ];
// struct ::"core-0_0_0"::result::Result#Err<(),::"core-0_0_0"::fmt::Error/*S*/,>
struct s_ZRG2cE9core0_0_06resultG9ResultErr2gT0G2c_A3fmt5Error0g  {
	/*@0*/uint8_t _1; // u8
	/*@1*/// ZST; // ::"core-0_0_0"::fmt::Error/*S*/
} __attribute__((__aligned__(1),)) ;
typedef char sizeof_assert_ZRG2cE9core0_0_06resultG9ResultErr2gT0G2c_A3fmt5Error0g[ (sizeof(struct s_ZRG2cE9core0_0_06resultG9ResultErr2gT0G2c_A3fmt5Error0g) == 1) ? 1 : -1 ];
typedef char alignof_assert_ZRG2cE9core0_0_06resultG9ResultErr2gT0G2c_A3fmt5Error0g[ (ALIGNOF(struct s_ZRG2cE9core0_0_06resultG9ResultErr2gT0G2c_A3fmt5Error0g) == 1) ? 1 : -1 ];
// enum ::"core-0_0_0"::result::Result<(),::"core-0_0_0"::fmt::Error/*S*/,>
struct e_ZRG2cE9core0_0_06result6Result2gT0G2c_A3fmt5Error0g {
	union {
		struct s_ZRG2cE9core0_0_06resultG8ResultOk2gT0G2c_A3fmt5Error0g var_0;
		struct s_ZRG2cE9core0_0_06resultG9ResultErr2gT0G2c_A3fmt5Error0g var_1;
		uint8_t TAG;
	} DATA;
};
typedef char sizeof_assert_ZRG2cE9core0_0_06result6Result2gT0G2c_A3fmt5Error0g[ (sizeof(struct e_ZRG2cE9core0_0_06result6Result2gT0G2c_A3fmt5Error0g) == 1) ? 1 : -1 ];
// struct ::"core-0_0_0"::fmt::builders::DebugTuple<'#omitted,'#omitted,>
struct s_ZRG3cE9core0_0_03fmt8builders10DebugTuple0g  {
	/*@0*/struct e_ZRG2cE9core0_0_06result6Result2gT0G2c_A3fmt5Error0g _1; // ::"core-0_0_0"::result::Result<(),::"core-0_0_0"::fmt::Error/*S*/,>/*E*/
	/*@1*/RUST_BOOL _3; // bool
	/*@8*/struct s_ZRG2cE9core0_0_03fmt9Formatter0g *_0; // &'#omitted mut ::"core-0_0_0"::fmt::Formatter<'#omitted,>/*S*/
	/*@16*/uintptr_t _2; // usize
} ;
typedef char sizeof_assert_ZRG3cE9core0_0_03fmt8builders10DebugTuple0g[ (sizeof(struct s_ZRG3cE9core0_0_03fmt8builders10DebugTuple0g) == 24) ? 1 : -1 ];
typedef char alignof_assert_ZRG3cE9core0_0_03fmt8builders10DebugTuple0g[ (ALIGNOF(struct s_ZRG3cE9core0_0_03fmt8builders10DebugTuple0g) == 8) ? 1 : -1 ];
struct s_ZRG2cE9core0_0_05panic9PanicInfo0g;
// PROTO extern "Rust" <u64 as ::"core-0_0_0"::cmp::Ord>::cmp<'#local4,'#local5,>
static struct e_ZRG2cE9core0_0_03cmp8Ordering0g  ZRQCg2cE9core0_0_03cmp3Ord0g_B0g(
		uint64_t *arg0, // &'#local4 u64
		uint64_t *arg1 // &'#local5 u64
		) // -> ::"core-0_0_0"::cmp::Ordering/*E*/
;
// EXTERN extern "Rust" <::"core-0_0_0"::fmt::Formatter<'static,>/*S*/ /*- <'#omitted,>*/>::debug_tuple<'#omitted,'static,>
extern struct s_ZRG3cE9core0_0_03fmt8builders10DebugTuple0g  ZRIG2cE9core0_0_03fmt9Formatter0g11debug_tuple0g(
		struct s_ZRG2cE9core0_0_03fmt9Formatter0g *arg0, // &'#omitted mut ::"core-0_0_0"::fmt::Formatter<'#omitted,>/*S*/
		SLICE_PTR arg1 // &'static str
		) // -> ::"core-0_0_0"::fmt::builders::DebugTuple<'#omitted,'#omitted,>/*S*/
;
// EXTERN extern "Rust" <::"core-0_0_0"::fmt::builders::DebugTuple<'#omitted,'#omitted,>/*S*/ /*- <'#omitted,'#omitted,>*/>::field<'#local0,'#omitted,>
extern struct s_ZRG3cE9core0_0_03fmt8builders10DebugTuple0g * ZRIG3cE9core0_0_03fmt8builders10DebugTuple0g5field0g(
		struct s_ZRG3cE9core0_0_03fmt8builders10DebugTuple0g *arg0, // &'#local0 mut ::"core-0_0_0"::fmt::builders::DebugTuple<'#omitted,'#omitted,>/*S*/
		TRAITOBJ_PTR arg1 // &'#omitted dyn (::"core-0_0_0"::fmt::Debug+'#omitted)
		) // -> &'#local0 mut ::"core-0_0_0"::fmt::builders::DebugTuple<'#omitted,'#omitted,>/*S*/
;
// EXTERN extern "Rust" <::"core-0_0_0"::fmt::builders::DebugTuple<'#omitted,'#omitted,>/*S*/ /*- <'#omitted,'#omitted,>*/>::finish<'#local1,>
extern struct e_ZRG2cE9core0_0_06result6Result2gT0G2c_A3fmt5Error0g  ZRIG3cE9core0_0_03fmt8builders10DebugTuple0g6finish0g(
		struct s_ZRG3cE9core0_0_03fmt8builders10DebugTuple0g *arg0 // &'#local1 mut ::"core-0_0_0"::fmt::builders::DebugTuple<'#omitted,'#omitted,>/*S*/
		) // -> ::"core-0_0_0"::result::Result<(),::"core-0_0_0"::fmt::Error/*S*/,>/*E*/
;
// <u64 as ::"core-0_0_0"::cmp::Ord>::cmp<'#local4,'#local5,>
static struct e_ZRG2cE9core0_0_03cmp8Ordering0g  ZRQCg2cE9core0_0_03cmp3Ord0g_B0g(
		uint64_t *arg0, // &'#local4 u64
		uint64_t *arg1 // &'#local5 u64
		) // -> ::"core-0_0_0"::cmp::Ordering/*E*/

{
	struct e_ZRG2cE9core0_0_03cmp8Ordering0g rv;
	RUST_BOOL var0;	// bool
	uint64_t var1;	// u64
	uint64_t var2;	// u64
	uint64_t var3;	// u64
	uint64_t var4;	// u64
	var1 = (*arg0);	// _1 = Use(a0*)
	var2 = (*arg1);	// _2 = Use(a1*)
	var0 = var1 == var2;	// _0 = BinOp(_1 EQ _2)
	if(var0) goto bb1; else goto bb2;
	// ^ If( _0 : 1, 2)
bb1:
	rv.TAG = 0ll;	// retval = Variant(::"core-0_0_0"::cmp::Ordering #1, {})
	return rv;
	// ^ Return
bb2:
	var3 = (*arg0);	// _3 = Use(a0*)
	var4 = (*arg1);	// _4 = Use(a1*)
	var0 = var3 < var4;	// _0 = BinOp(_3 LT _4)
	if(var0) goto bb3; else goto bb4;
	// ^ If( _0 : 3, 4)
bb3:
	rv.TAG = -1ll;	// retval = Variant(::"core-0_0_0"::cmp::Ordering #0, {})
	return rv;
	// ^ Return
bb4:
	rv.TAG = 1ll;	// retval = Variant(::"core-0_0_0"::cmp::Ordering #2, {})
	return rv;
	// ^ Return
}
