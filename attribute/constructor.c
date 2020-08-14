#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("main function\n");
}

__attribute__((constructor)) static int before_func()
{
    printf("Before function\n");
}

__attribute__((destructor)) static int after_func()
{
    printf("After function\n");
}
