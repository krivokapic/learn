#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "arena.h"

typedef struct{
    string8 *key;             // 8 bytes
    void* value;           // 8 bytes
} key_value;

typedef struct {
    key_value **entries; // 8 bytes
    u16 capacity;       // 2 bytes 
    u16 count;          // 2 bytes
    //u64 *keys; // 8 bytes
    //string32 *values; // 8 bytes
    // u16 size;       // 2 bytes 
    // u16 pos;          // 2 bytes
} hashtable;            // 12 bytes

u32 mix_hash(u32 h);
u32 hash_func(string8 str);
//u32 hash_func(u32 *str, size_t len);
hashtable* hashtable_create(Arena *arena, u16 size);
b32 hashtable_insert(Arena *arena, hashtable *htable, string8 *key, void *value);
void* hashtable_get(hashtable *htable, string8 key);
b32 hashtable_remove(hashtable *htable, string8 key);
void print_htable(hashtable *htable);

int main(void)
{
    Arena *arena = arena_create(KB(10));
    hashtable *htable = hashtable_create(arena, 5);
    print_htable(htable);
    string8 s8 = STR8_LIT("vlada");
    u32 val = 43434;
    hashtable_insert(arena, htable, &s8, &val);
    print_htable(htable);
    string8 tmp = STR8_LIT("vladaa");
    u32 val2 = 5;
    hashtable_insert(arena, htable, &tmp, &val2);
    print_htable(htable);
    u32 *get = (u32*)hashtable_get(htable, STR8_LIT("vlada"));
    printf("get: %u\n", *get);
    b32 deleted = hashtable_remove(htable, STR8_LIT("vlada"));
    printf("deleted: %u\n", deleted);
    print_htable(htable);
    arena_destroy(arena);
    return 0;
}

void print_htable(hashtable *htable){
    printf("====htable====\n");
    printf("%p htable\n%p capacity: %d\n%p count: %d\n%p entries\n",
            (void*)htable, (void*)&htable->capacity, htable->capacity,
            (void*)&htable->count, htable->count,
            (void*)htable->entries
          );
    if(htable->count > 0){
        for (u32 i = 0; i < htable->capacity; i++) {
            if(htable->entries[i] != NULL){
                printf("\tentry: %u: %.*s -> %p\n", i, STR_FMT(*htable->entries[i]->key), htable->entries[i]->value);
            }
        
        }
        //u32 idx = 0;
        //while (htable->entries[idx] != NULL) {
        //    printf("\t\t\t\tPRINTING\n");
        //    printf("\tentry: %u: %.*s -> %p\n", idx, STR_FMT(*htable->entries[idx]->key), htable->entries[idx]->value);
        //    idx += 1;
        //}
        //printf("idx: %u\n", idx);
    }
    //printf("sizeof(hashtable): %zu\n", sizeof(hashtable));
    printf("==============\n");
}


// FNV-1a hash
//u32 hash_func(u32 *str, size_t len) {
u32 hash_func(string8 str) {
    //u8 *s = (u8*)str;    /* unsigned string */
    u8 *s = str.str;    /* unsigned string */

    /* See the FNV parameters at www.isthe.com/chongo/tech/comp/fnv/#FNV-param */
    const u32 FNV_32_PRIME = 0x01000193; /* 16777619 */

    u32 h = 0x811c9dc5; /* 2166136261 */
    //while (len--) {
    while (str.size--) {
        /* xor the bottom with the current octet */
        h ^= *s++;
        /* multiply by the 32 bit FNV magic prime mod 2^32 */
        h *= FNV_32_PRIME;
    }
    h = mix_hash(h);
    return h;
}

u32 mix_hash(u32 h) {
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
    return h;
}

hashtable* hashtable_create(Arena *arena, u16 size){
    u64 total_size = sizeof(hashtable) + (sizeof(key_value) * size);
    hashtable *htable = PUSH_BYTES(arena, hashtable, total_size);
    if(htable == NULL) {return NULL;}
    htable->capacity = size;
    htable->count = 0;
    htable->entries = (key_value**)(htable + 1);

    return htable;
}
void* hashtable_get(hashtable *htable, string8 key){
    u32 hash = hash_func(key);
    u32 idx = hash & (htable->capacity - 1);

    while(htable->entries[idx] != NULL){
        if(strcmp((char*)key.str, (char*)htable->entries[idx]->key->str) == 0){
            return htable->entries[idx]->value;
        }
        // this is called 'linear probing'
        // you just walk ahead and wrap around at the end
        idx++;
        if(idx > htable->capacity)
            idx = 0;
    }

    return NULL;
}
b32 hashtable_insert(Arena *arena, hashtable *htable, string8 *key, void *value){
    if(htable->count == htable->capacity){
        // double the capacity and realloc ?
        // this is done by either
        // - reallocing the whole arena and doubling the size
        // - implementing the reserve size and commit size of the arena
        //   and then if more space is needed, you commit another chuck? of the memory
    }
    u32 hash = hash_func(*key);
    u32 idx = hash & (htable->capacity - 1);
    // if htable is not empty
    if(htable->count > 0){
        // try to find a key
        while(htable->entries[idx] != NULL){
            if(strcmp((char*)key->str, (char*)htable->entries[idx]->key->str) == 0){
                // if found, update it
                htable->entries[idx]->value = value;
                return true;
            }
            // this is called 'linear probing'
            // you just walk ahead and wrap around at the end
            idx++;
            if(idx > htable->capacity)
                idx = 0;
        }
    }
    key_value *val = PUSH_STRUCT(arena, key_value);
    val->key = key;
    val->value = value;
    htable->entries[idx] = val;
    htable->count += 1;

    return true;
}
b32 hashtable_remove(hashtable *htable, string8 key){
    u32 hash = hash_func(key);
    u32 idx = hash & (htable->capacity - 1);

    // try to find a key
    while(htable->entries[idx] != NULL) {
        if(strcmp((char*)key.str, (char*)htable->entries[idx]->key->str) == 0){
            // if found, delete it
            printf("\t\tdeleting: %.*s at idx: %u\n", STR_FMT(*htable->entries[idx]->key), idx);
            htable->entries[idx] = NULL;
            htable->count -= 1;
            return true;
        }
        // this is called 'linear probing'
        // you just walk ahead and wrap around at the end
        idx++;
        if(idx > htable->capacity)
            idx = 0;
    }
    return false;
}
