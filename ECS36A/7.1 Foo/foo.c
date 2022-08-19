#include <stdio.h>

int _Foo(int n, int n4, int n3, int n2, int n1) 
{
    if (n == 0) {
        return n4;
    } else if (n == 1) {
        return n3;
    } else if (n == 2) {
        return n2;
    } else if (n == 3) {
        return n1;
    } else {
        return _Foo(n-1, n3, n2, n1, n3+n2+n1-n4+1); 
    }
}

int Foo(int n) {
    return _Foo(n,3,6,2,7);
}

int main() {
    int n;
    printf("Enter a value for n: ");
    scanf("%d", &n);
    printf("Foo(%d) = %d\n", n, Foo(n));
}