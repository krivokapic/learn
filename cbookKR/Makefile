BIN_DIR := $(CURDIR)/bin
CFLAGS := -pedantic -g3 -std=gnu11

pointers: pointers.c
	@gcc $(CFLAGS) pointers.c -o $(BIN_DIR)/pointers
dblpointers: double_pointers.c
	@gcc $(CFLAGS) double_pointers.c -o $(BIN_DIR)/double_pointers
readbinary: read_binary.c
	@gcc $(CFLAGS) read_binary.c -o $(BIN_DIR)/read_binary
ll: linked_list.c
	@gcc $(CFLAGS) linked_list.c -o $(BIN_DIR)/linked_list
test: test.c
	@gcc $(CFLAGS) test.c -o $(BIN_DIR)/test
testo1: test.c
	@gcc $(CFLAGS) -O1 test.c -o $(BIN_DIR)/test
testo2: test.c
	@gcc $(CFLAGS) -O2 test.c -o $(BIN_DIR)/test
testo3: test.c
	@gcc $(CFLAGS) -O3 test.c -o $(BIN_DIR)/test
