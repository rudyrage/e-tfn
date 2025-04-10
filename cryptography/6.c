#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void otp_cipher(char *plaintext, char *key, char *ciphertext) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int i;

    for (i = 0; i < plaintext_len; i++) {
        if (isalpha(plaintext[i])) {
            int base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = ((plaintext[i] - base + (key[i] - base)) % 26) + base;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];

    printf("Enter the plaintext: ");
    if (fgets(plaintext, sizeof(plaintext), stdin) == NULL) {
        printf("Error: Invalid input for plaintext.\n");
        return 1;
    }
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    
    srand(time(NULL));
    for (int i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            int base = isupper(plaintext[i]) ? 'A' : 'a';
            key[i] = (rand() % 26) + base;
        } else {
            key[i] = plaintext[i];
        }
    }
    key[strlen(plaintext)] = '\0';

    otp_cipher(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Key: %s\n", key);

    return 0;
}
