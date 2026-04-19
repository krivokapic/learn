CFLAGS := -fsanitize=address,leak -g3 -O0 -std=gnu11 -Wall -Wextra -Wpedantic -Werror -Wconversion -pedantic # -lm 

hashtable: hashtables.o arena.o
	@gcc $(CFLAGS) $^ -o hashtable
hashtable.o: hashtables.c arena.h base.h
	@gcc $(CFLAGS) -c hashtables.c -o hashtables.o
arrMax: maxArrayRecursion.c
	@gcc -Wall -g maxArrayRecursion.c -o maxArrayRecursion
qsort: quicksort.c
	@gcc -g quicksort.c -o quicksort
bfs: bfs.c
	@gcc -g bfs.c -o bfs
arena.o: arena.c arena.h
	@gcc $(CFLAGS) -c arena.c -o arena.o
