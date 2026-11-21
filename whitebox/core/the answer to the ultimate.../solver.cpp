#include <new>

void foo(int const** x) {
    static int test = 42;
    *x = &test;
}

/* You must define this macro */
#define USER_CALL(x) foo(&x)