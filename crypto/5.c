#include <stdio.h>
#include <string.h>


void vernam(const char *input, const char *key, char *output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ key[i];
    }
    output[len] = '\0';
}

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];
    char deciphered[100];

    
    printf("Enter the plaintext: ");
    scanf("%99s", plaintext);

    
    printf("Enter the key (same length as plaintext): ");
    scanf("%99s", key);

    if (strlen(plaintext) != strlen(key)) {
        printf("Error: The key must be the same length as the plaintext.\n");
        return 1;
    }

    
    vernam(plaintext, key, ciphertext);

    
    printf("Ciphertext:");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02x ", (unsigned char)ciphertext[i]);
    }
    printf("\n");

    
    vernam(ciphertext, key, deciphered);
    printf("Deciphered text: %s\n", deciphered);

    return 0;
}
