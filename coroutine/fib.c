#include <stdlib.h>
#include <stdio.h>
#include <ucontext.h>

ucontext_t main_ctx, fib_ctx;
int fib_res;

char fib_stack[1024 * 32];

static void fib()
{
    int a0 = 0;
    int a1 = 1;

    while (1) {
        fib_res = a0 + a1;
        a0 = a1;
        a1 = fib_res;

        swapcontext(&fib_ctx, &main_ctx);
    }
}

int main(int argc, const char *argv[])
{
    getcontext(&fib_ctx);

    fib_ctx.uc_link = 0;
    fib_ctx.uc_stack.ss_sp = fib_stack;
    fib_ctx.uc_stack.ss_size = sizeof(fib_stack);
    fib_ctx.uc_stack.ss_flags = 0;

    makecontext(&fib_ctx, fib, 0);

    while (1) {
        swapcontext(&main_ctx, &fib_ctx);

        printf("%d\n", fib_res);

        if (fib_res > 100)
            break;
    }

   return 0;
}
