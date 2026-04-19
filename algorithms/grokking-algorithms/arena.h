#include "base.h"

#define ARENA_HEADER (sizeof(Arena))
#define ARENA_ALIGN (sizeof(void *))

typedef struct Arena Arena;
struct Arena {
    u64 reserve_space;
    u64 pos;
};

Arena* arena_create(u64 reserve_size);
void arena_destroy(Arena *arena);
void* arena_push(Arena *arena, u64 size, b32 non_zero);
void arena_pop(Arena *arena, u64 size);
void arena_pop_to(Arena *arena, u64 pos);
void arena_clear(Arena *arena);

#define PUSH_STRUCT(arena, T) (T*)arena_push((arena), sizeof(T), false)
#define PUSH_STRUCT_NZ(arena, T) (T*)arena_push((arena), sizeof(T), true)
#define PUSH_ARRAY(arena, T, n) (T*)arena_push((arena), sizeof(T) * (n), false)
#define PUSH_ARRAY_NZ(arena, T, n) (T*)arena_push((arena), sizeof(T) * (n), true)
#define PUSH_BYTES(arena, T, n) (T*)arena_push((arena), (n), false)
#define PUSH_BYTES_NZ(arena, T, n) (T*)arena_push((arena), (n), true)

u32 get_pagesize(void);

