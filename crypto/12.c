#include <stdio.h>

long long int extended_euclidean_algorithm(long long int a, long long int b, long long int *x, long long int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    
    long long int x1, y1;
    long long int gcd = extended_euclidean_algorithm(b, a % b, &x1, &y1);
    
    *x = y1;
    *y = x1 - (a / b) * y1;
    
    return gcd;
}

int main() {
    long long int a, b, x, y;
    
    printf("Enter two numbers: ");
    scanf("%lld %lld", &a, &b);
    
    long long int gcd = extended_euclidean_algorithm(a, b, &x, &y);
    
    printf("GCD of %lld and %lld is: %lld\n", a, b, gcd);
    printf("Coefficients x and y are: x = %lld, y = %lld\n", x, y);
    
    return 0;
}
