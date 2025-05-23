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
typedef struct { uint64_t lo, hi; } uint128_t;
typedef struct { uint64_t lo, hi; } int128_t;
static inline uint128_t intrinsic_ctlz_u128(uint128_t v);
static inline uint128_t shl128(uint128_t a, uint32_t b);
static inline uint128_t shr128(uint128_t a, uint32_t b);
static inline float make_float(int is_neg, int exp, uint32_t mantissa_bits) { float rv; uint32_t vi=(mantissa_bits&((1<<23)-1))|((exp+127)<<23);if(is_neg)vi|=1<<31; memcpy(&rv, &vi, 4); return rv; }
static inline double make_double(int is_neg, int exp, uint32_t mantissa_bits) { double rv; uint64_t vi=(mantissa_bits&((1ull<<52)-1))|((uint64_t)(exp+1023)<<52);if(is_neg)vi|=1ull<<63; memcpy(&rv, &vi, 4); return rv; }
static inline uint128_t make128_raw(uint64_t hi, uint64_t lo) { uint128_t rv = { lo, hi }; return rv; }
static inline uint128_t make128(uint64_t v) { uint128_t rv = { v, 0 }; return rv; }
static inline float cast128_float(uint128_t v) { int n = intrinsic_ctlz_u128(v).lo; uint128_t y = shl128(v, n); uint64_t a = (y.hi >> ((128-(23+1))-64)); uint64_t b = shr128(y, (64-(23+1))).lo | (y.lo & 0xFFFFFFFFFF); uint64_t m = a + ((b - ((b >> 63) & ~a)) >> 63); uint64_t e = (v.lo == 0 && v.hi == 0) ? 0 : (127 - n)+127-1; uint32_t vi = (e << 23) + m; float rv; memcpy(&rv, &vi, sizeof(rv)); return rv; }
static inline double cast128_double(uint128_t v) { int n = intrinsic_ctlz_u128(v).lo; uint128_t y = shl128(v, n); uint64_t a = (y.hi >> ((128-(52+1))-64)); uint64_t b = shr128(y, (64-(52+1))).lo | (y.lo & 0x7FF); uint64_t m = a + ((b - (b >> 63 & ~a)) >> 63); uint64_t e = (v.lo == 0 && v.hi == 0) ? 0 : (127 - n)+1023-1; uint64_t vi = (e << 52) + m; double rv; memcpy(&rv, &vi, sizeof(rv)); return rv; }
static inline int cmp128(uint128_t a, uint128_t b) { if(a.hi != b.hi) return a.hi < b.hi ? -1 : 1; if(a.lo != b.lo) return a.lo < b.lo ? -1 : 1; return 0; }
static inline bool add128_o(uint128_t a, uint128_t b, uint128_t* o) { o->lo = a.lo + b.lo; o->hi = a.hi + b.hi + (o->lo < a.lo ? 1 : 0); return (o->hi < a.hi); }
static inline bool sub128_o(uint128_t a, uint128_t b, uint128_t* o) { o->lo = a.lo - b.lo; o->hi = a.hi - b.hi - (a.lo < b.lo ? 1 : 0); return (o->hi > a.hi); }
static inline bool mul128_o(uint128_t a, uint128_t b, uint128_t* o) { bool of = false; o->hi = 0; o->lo = 0; for(int i=0;i<128;i++){ uint64_t m = (1ull << (i % 64)); if(a.hi==0&&a.lo<m)   break; if(i>=64&&a.hi<m) break; if( m & (i >= 64 ? a.hi : a.lo) ) of |= add128_o(*o, b, o); b.hi = (b.hi << 1) | (b.lo >> 63); b.lo = (b.lo << 1); } return of;}
static inline bool div128_o(uint128_t a, uint128_t b, uint128_t* q, uint128_t* r) { if(a.hi == 0 && b.hi == 0) { if(q) { q->hi=0; q->lo = a.lo / b.lo; } if(r) { r->hi=0; r->lo = a.lo % b.lo; } return false; } if(cmp128(a, b) < 0) { if(q) { q->hi=0; q->lo=0; } if(r) *r = a; return false; } uint128_t a_div_2 = {(a.lo>>1)|(a.hi << 63), a.hi>>1}; int shift = 0; while( cmp128(a_div_2, b) >= 0 && shift < 128 ) { shift += 1; b.hi = (b.hi<<1)|(b.lo>>63); b.lo <<= 1; } if(shift == 128) return true; uint128_t mask = { /*lo=*/(shift >= 64 ? 0 : (1ull << shift)), /*hi=*/(shift < 64 ? 0 : 1ull << (shift-64)) }; shift ++; if(q) { q->hi = 0; q->lo = 0; } while(shift--) { if( cmp128(a, b) >= 0 ) { if(q) add128_o(*q, mask, q); sub128_o(a, b, &a); } mask.lo = (mask.lo >> 1) | (mask.hi << 63); mask.hi >>= 1; b.lo = (b.lo >> 1) | (b.hi << 63); b.hi >>= 1; } if(r) *r = a; return false;}
static inline uint128_t add128(uint128_t a, uint128_t b) { uint128_t v; add128_o(a, b, &v); return v; }
static inline uint128_t sub128(uint128_t a, uint128_t b) { uint128_t v; sub128_o(a, b, &v); return v; }
static inline uint128_t mul128(uint128_t a, uint128_t b) { uint128_t v; mul128_o(a, b, &v); return v; }
static inline uint128_t div128(uint128_t a, uint128_t b) { uint128_t v; div128_o(a, b, &v, NULL); return v; }
static inline uint128_t mod128(uint128_t a, uint128_t b) { uint128_t v; div128_o(a, b, NULL, &v); return v;}
static inline uint128_t and128(uint128_t a, uint128_t b) { uint128_t v = { a.lo & b.lo, a.hi & b.hi }; return v; }
static inline uint128_t or128 (uint128_t a, uint128_t b) { uint128_t v = { a.lo | b.lo, a.hi | b.hi }; return v; }
static inline uint128_t xor128(uint128_t a, uint128_t b) { uint128_t v = { a.lo ^ b.lo, a.hi ^ b.hi }; return v; }
static inline uint128_t shl128(uint128_t a, uint32_t b) { uint128_t v; if(b == 0) { return a; } else if(b < 64) { v.lo = a.lo << b; v.hi = (a.hi << b) | (a.lo >> (64 - b)); } else { v.hi = a.lo << (b - 64); v.lo = 0; } return v; }
static inline uint128_t shr128(uint128_t a, uint32_t b) { uint128_t v; if(b == 0) { return a; } else if(b < 64) { v.lo = (a.lo >> b)|(a.hi << (64 - b)); v.hi = a.hi >> b; } else { v.lo = a.hi >> (b - 64); v.hi = 0; } return v; }
static inline uint128_t popcount128(uint128_t a) { uint128_t v = { __builtin_popcountll(a.lo) + __builtin_popcountll(a.hi), 0 }; return v; }
static inline uint128_t __builtin_bswap128(uint128_t v) { uint128_t rv = { __builtin_bswap64(v.hi), __builtin_bswap64(v.lo) }; return rv; }
static inline uint128_t intrinsic_ctlz_u128(uint128_t v) {
	uint128_t rv = { (v.hi != 0 ? __builtin_clz64(v.hi) : (v.lo != 0 ? 64 + __builtin_clz64(v.lo) : 128)), 0 };
	return rv;
}
static inline uint128_t intrinsic_cttz_u128(uint128_t v) {
	uint128_t rv = { (v.lo == 0 ? (v.hi == 0 ? 128 : __builtin_ctz64(v.hi) + 64) : __builtin_ctz64(v.lo)), 0 };
	return rv;
}
static inline int128_t make128s_raw(uint64_t hi, uint64_t lo) { int128_t rv = { lo, hi }; return rv; }
static inline int128_t make128s(int64_t v) { int128_t rv = { v, (v < 0 ? -1 : 0) }; return rv; }
static inline int128_t neg128s(int128_t v) { int128_t rv = { ~v.lo+1, ~v.hi + (v.lo == 0) }; return rv; }
static inline float cast128s_float(int128_t v) { int sgn = (v.hi >> 63); int128_t abs = sgn ? neg128s(v) : v; return (sgn ? -1.0 : 1.0) * cast128_float(make128_raw(v.hi,v.lo)); }
static inline double cast128s_double(int128_t v) { int sgn = (v.hi >> 63); int128_t abs = sgn ? neg128s(v) : v; return (sgn ? -1.0 : 1.0) * cast128_double(make128_raw(v.hi,v.lo)); }
static inline int cmp128s(int128_t a, int128_t b) { if(a.hi != b.hi) return (int64_t)a.hi < (int64_t)b.hi ? -1 : 1; if(a.lo != b.lo) return a.lo < b.lo ? -1 : 1; return 0; }
static inline bool add128s_o(int128_t a, int128_t b, int128_t* o) { bool sgna=a.hi>>63; bool sgnb=b.hi>>63; add128_o(*(uint128_t*)&a, *(uint128_t*)&b, (uint128_t*)o); bool sgno = o->hi>>63; return (sgna==sgnb && sgno != sgna); }
static inline bool sub128s_o(int128_t a, int128_t b, int128_t* o) { bool sgna=a.hi>>63; bool sgnb=b.hi>>63; sub128_o(*(uint128_t*)&a, *(uint128_t*)&b, (uint128_t*)o); bool sgno = o->hi>>63; return (sgna!=sgnb && sgno != sgna); }
static inline bool mul128s_o(int128_t a, int128_t b, int128_t* o) { bool sgna = (a.hi >> 63); bool sgnb = (b.hi >> 63); if(sgna) a = neg128s(a); if(sgnb) b = neg128s(b); bool rv = mul128_o(*(uint128_t*)&a, *(uint128_t*)&b, (uint128_t*)o); if(sgna != sgnb) *o = neg128s(*o); return rv; }
static inline bool div128s_o(int128_t a, int128_t b, int128_t* q, int128_t* r) { bool sgna = (a.hi >> 63) != 0; bool sgnb = (b.hi >> 63) != 0; if(sgna) a = neg128s(a); if(sgnb) b = neg128s(b); bool rv = div128_o(*(uint128_t*)&a, *(uint128_t*)&b, (uint128_t*)q, (uint128_t*)r); if(sgna != sgnb && q) *q = neg128s(*q); if(sgna && r) *r = neg128s(*r); return rv; }
static inline int128_t add128s(int128_t a, int128_t b) { int128_t v; add128s_o(a, b, &v); return v; }
static inline int128_t sub128s(int128_t a, int128_t b) { int128_t v; sub128s_o(a, b, &v); return v; }
static inline int128_t mul128s(int128_t a, int128_t b) { int128_t v; mul128s_o(a, b, &v); return v; }
static inline int128_t div128s(int128_t a, int128_t b) { int128_t v; div128s_o(a, b, &v, NULL); return v; }
static inline int128_t mod128s(int128_t a, int128_t b) { int128_t v; div128s_o(a, b, NULL, &v); return v; }
static inline int128_t and128s(int128_t a, int128_t b) { int128_t v = { a.lo & b.lo, a.hi & b.hi }; return v; }
static inline int128_t or128s (int128_t a, int128_t b) { int128_t v = { a.lo | b.lo, a.hi | b.hi }; return v; }
static inline int128_t xor128s(int128_t a, int128_t b) { int128_t v = { a.lo ^ b.lo, a.hi ^ b.hi }; return v; }
static inline int128_t shl128s(int128_t a, uint32_t b) { int128_t v; if(b == 0) { return a; } else if(b < 64) { v.lo = a.lo << b; v.hi = (a.hi << b) | (a.lo >> (64 - b)); } else { v.hi = a.lo << (b - 64); v.lo = 0; } return v; }
static inline int128_t shr128s(int128_t a, uint32_t b) { int128_t v; if(b == 0) { return a; } else if(b < 64) { v.lo = (a.lo >> b)|(a.hi << (64 - b)); v.hi = (int64_t)a.hi >> b; } else { v.lo = (int64_t)a.hi >> (b - 64); v.hi = (int64_t)a.hi < 0 ? -1 : 0; } return v; }
static inline uint128_t int128_to_uint128(int128_t a) { return make128_raw(a.lo, a.hi); }
static inline int128_t uint128_to_int128(uint128_t a) { return make128s_raw(a.lo, a.hi); }

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
static inline uint128_t __mrustc_bitrev128(uint128_t v) { uint128_t rv = { __mrustc_bitrev64(v.hi), __mrustc_bitrev64(v.lo) }; return rv; }
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
