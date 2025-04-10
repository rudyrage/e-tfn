#include <stdio.h>
#include <math.h>

long long int power_mod(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long int p, g, a_private, b_private, a_public, b_public, shared_secret_a, shared_secret_b;
    
    p = 23; // prime number
    g = 5;  // generator
    
    printf("Enter private key for A: ");
    scanf("%lld", &a_private);
    
    printf("Enter private key for B: ");
    scanf("%lld", &b_private);
    
    a_public = power_mod(g, a_private, p);
    b_public = power_mod(g, b_private, p);
    
    shared_secret_a = power_mod(b_public, a_private, p);
    shared_secret_b = power_mod(a_public, b_private, p);
    
    printf("Public key of A: %lld\n", a_public);
    printf("Public key of B: %lld\n", b_public);
    printf("Shared secret computed by A: %lld\n", shared_secret_a);
    printf("Shared secret computed by B: %lld\n", shared_secret_b);
    
    return 0;
}
