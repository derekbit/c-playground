#include <stdio.h>

int main()
{
    printf("main function\n");
}

__attribute__((constructor(102))) static int before_func_1()
{
    printf("before function with priority 102\n");
}

__attribute__((constructor(101))) static int before_func_2()
{
    printf("before function with priority 101\n");
}
