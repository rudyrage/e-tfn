#include <stdio.h>

int power(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int is_primitive_root(int candidate, int p) {
    int seen[p]; 
    for (int i = 0; i < p; i++)
        seen[i] = 0;

    for (int i = 1; i < p; i++) {
        int val = power(candidate, i, p);
        if (seen[val])
            return 0; 
        seen[val] = 1;
    }
    return 1;
}

int main() {
    int p;
    printf("Enter a prime number: ");
    scanf("%d", &p);

    if (p <= 1) {
        printf("Input must be a prime number greater than 1\n");
        return 0;
    }

    printf("Primitive roots of %d are:\n", p);
    for (int g = 2; g < p; g++) {
        if (is_primitive_root(g, p)) {
            printf("%d ", g);
        }
    }
    printf("\n");
    return 0;
}
