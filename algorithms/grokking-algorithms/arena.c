#include "arena.h"
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>


Arena* arena_create(u64 reserve_size){
    u32 pagesize = get_pagesize();
    reserve_size = ALIGN_UP_POW2(reserve_size, pagesize);

    Arena *arena = (Arena*)malloc(reserve_size);
    arena->reserve_space = reserve_size;
    arena->pos = ARENA_HEADER;

    return arena;
}

void arena_destroy(Arena *arena){
    FREE(arena);
}

void* arena_push(Arena* arena, u64 size, b32 non_zero){
    u64 pos_aligned = ALIGN_UP_POW2(arena->pos, ARENA_ALIGN);
    u64 new_pos = pos_aligned + size;

    if(new_pos > arena->reserve_space) { return NULL; }
    // TODO: if new_pos > commit space

    arena->pos = new_pos;

    u8 *out = (u8*)arena + pos_aligned;

    if(!non_zero){
        memset(out, 0, size);
    }

    return out;
}

void arena_pop(Arena *arena, u64 size){
    size = MIN(size, arena->pos - ARENA_HEADER);
    arena->pos -= size;
}

void arena_pop_to(Arena *arena, u64 pos){
    u64 size = pos < arena->pos ? arena->pos - pos : 0;
    arena_pop(arena, size);
}

void arena_clear(Arena *arena){
    arena_pop_to(arena, ARENA_HEADER);
}

u32 get_pagesize(void){
    return (u32)sysconf(_SC_PAGESIZE);
}
