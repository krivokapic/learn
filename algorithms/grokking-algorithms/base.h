#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define FREE(p) do { free(p); (p) = NULL; } while(0)

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef s8 b8;
typedef s32 b32;

typedef uintptr_t uptr;

#define KB(n) ((u64)(n) << 10)
#define MB(n) ((u64)(n) << 20)
#define GB(n) ((u64)(n) << 30)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ALIGN_UP_POW2(n, p) (((u64)(n) + ((u64)(p) - 1)) & (~((u64)(p) - 1)))

typedef struct {
    u8 *str;
    u64 size;
} string8;

typedef struct {
    u16 *str;
    u64 size;
} string16;

typedef struct {
    u32 *str;
    u64 size;
} string32;

#define STR8_LIT(s) (string8){ (u8*)(s), sizeof((s)) - 1 }
#define STR16_LIT(s) (string16){ (u16*)(s), sizeof((s)) - 1 }
#define STR32_LIT(s) (string32){ (u32*)(s), sizeof((s)) - 1 }

#define STR_FMT(s) (int)(s).size, (char*)(s).str
