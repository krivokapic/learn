#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_VECTORS 3
#define DATA_SIZE 4

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} Vector;

void vector_init(Vector *v) {
  v->data = malloc(sizeof(int) * DATA_SIZE);
  v->size = 0;
  v->capacity = DATA_SIZE;
};

void vector_push(Vector *v, int x) {
  if (v->size == v->capacity) {
    v->capacity *= 2;
    v->data = realloc(v->data, v->capacity * sizeof(int));
  }
  v->data[v->size] = x;
  v->size++;
};

void vector_free(Vector *v) {
  free(v->data);
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
}

void print_items(Vector *v) {
  Vector *p = v; // pointer that will walk the array

  for (int i = 0; i < NUM_OF_VECTORS; i++, p++) {
    printf("vector_array[%d] -> %p:\n", i, (void *)p);
    printf("\t-size: %ld\n", p->size);
    printf("\t-capacity: %ld\n", p->capacity);
    printf("\t-data: %p\n", (void *)p->data);
    for (int j = 0; j < DATA_SIZE; j++) {
      if(p->data == NULL) 
          printf("\t\t-data[%d]: %p\n", j, p->data);
      else
          printf("\t\t-data[%d]: %d\n", j, p->data[j]);
    }
  }
}

int main(void) {
  Vector vector_array[NUM_OF_VECTORS] = {0};

  // printf("vector_array: %p\n", vector_array);
  // printf("vector_array: %p\n", &(*vector_array));
  // return 0;

  // Vector **vectors = malloc(sizeof(Vector*) * SIZE);
  // for(int i = 0; i < SIZE; i++){
  //     //vectors[i] = malloc(sizeof(Vector));
  //     //vector_init(vectors[i]);
  //     vector_array[i] = (Vector *)malloc(sizeof(Vector));
  //     vector_init(vectors[i]);
  // }

  printf("==========\n");
  printf("declare:\n");
  printf("==========\n");

  print_items(vector_array);

  printf("==========\n");
  printf("init:\n");
  printf("==========\n");
  for (int i = 0; i < NUM_OF_VECTORS; i++) {
    vector_init(&vector_array[i]);
  }
  print_items(vector_array);
  printf("==========\n");
  printf("add data values to each vector:\n");
  printf("==========\n");
  for (int i = 0; i < NUM_OF_VECTORS; i++) {
    for (int j = 0; j < DATA_SIZE; j++) {
      vector_push(&vector_array[i], j + i * 10);
    }
  }

  // Free memory for each vector and array
  // for (int i = 0; i < num_vectors; i++) {
  //  vector_free(vectors[i]);
  //  free(vectors[i]);
  //}
  // free(vectors);

  print_items(vector_array);

  return 0;
}
