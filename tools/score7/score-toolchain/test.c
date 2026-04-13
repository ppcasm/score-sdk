#include <setjmp.h>

volatile int x = 0;
jmp_buf env;

int main(void) {
    int v = setjmp(env);

    if (v == 0) {
        x = 123;
        longjmp(env, 7);
    }

    return (x == 123 && v == 7) ? 0 : 1;
}