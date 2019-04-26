#include <stdarg.h>
#include <stdio.h>

void vlist_one_ldouble(va_list *pargs) {
    long double value;

    value = va_arg(*pargs, long double);
    printf(" %Lf", value);
}

void vlist_ldouble(int count, va_list *pargs) {
    printf("Now printing %d long doubles:\n", count);

    for (int i=0; i<count; i++)
        vlist_one_ldouble(pargs);

    printf("\n");
}

void list_ldouble(int count, ...) {
    va_list args;
    va_start(args, count);

    vlist_ldouble(count, &args);

    va_end(args);
    return;
}

int main(void) {
    long double a = 1.1, b=2.2, c=3.3;

    list_ldouble(3, a, b, c);
    list_ldouble(4, 1.1L, 2.2L, 3.3L, 4.4L);

    return 0;
}