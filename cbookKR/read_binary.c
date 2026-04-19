#include <stdio.h>
#include <stdint.h>

int main(void){
    FILE *fp = fopen("bin/pointers", "rb");
    if(fp == NULL){
        printf("Error opening file\n");
        return 1;
    }
    printf("fp = %p\n", (void*)fp);

    uint32_t variable_from_file;

    fread(&variable_from_file, sizeof(uint32_t), 1, fp);
    printf("variable_from_file = 0x%X\n", variable_from_file);
}
