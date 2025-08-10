#include <stdio.h>

static int fact(int num){
  if(num == 1)
    return 1;
  else
    return num * fact(num-1);
}

int main(int argc, char *argv[])
{
  printf("fact of %d is %d\n", 5, fact(5));
  return 0;
}

