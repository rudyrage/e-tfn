#include <stdio.h>

long long int euclidean_algorithm(long long int a, long long int b) {
    while (b != 0) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    long long int a, b;
    
    printf("Enter two numbers: ");
    scanf("%lld %lld", &a, &b);
    
    long long int gcd = euclidean_algorithm(a, b);
    
    printf("GCD of %lld and %lld is: %lld\n", a, b, gcd);
    
    return 0;
}
