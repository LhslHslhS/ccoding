#include <stdio.h>

long long unsigned fib (int n) {
    if (n == 1) {
        return 1;
    }else if (n == 2)
    {
        return 1;
    }else{
        return fib(n - 1) + fib(n - 2);
         
    }
}

long long unsigned factorial (int n) {
    int nexti = 1;
    for ( int i = 1; i <= n; ++i ) {
        nexti *= i;
    }
    return nexti;
}

long long unsigned com (int n, int r) {
    if (r == 0 || r == n)
    {
        return 1;
    }else{
        return com(n - 1 , r - 1) + com(n - 1 , r);
    }
}

long long unsigned com2 (int n, int r) {
    if (r == 0 || r == n)
    {
        return 1;
    }else{
        return com2(n-1,r-1) * n /r;
    }
}

int main ( int argc, char const *argv[] ) {
    printf("%lld\n" , factorial(10));

    int n = 11, r = 4;

    if (com(n, r) == (factorial(n)/(factorial(n-r)*factorial(r)))) printf("true\n");
    else printf("false\n");

    for ( int n = 0; n < 50; ++n ) {
        for ( int r = 0; r <= n; ++r ) {
            if ( r == n)
            {
                printf("1\n");
            }else
            {
                printf("%lld ", com2(n,r));
            }
        }
    }

    printf("\n");

    return 0;
}
