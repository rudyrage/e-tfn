#include <stdio.h>
#include <ctype.h>

void caesar_encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

void caesar_decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base - shift + 26) % 26 + base;
        }
    }
}

int main() {
    char text[1000];
    int shift;

    printf("Enter text: ");
    scanf("%s", text); 

    printf("Enter shift: ");
    scanf("%d", &shift);

    caesar_encrypt(text, shift);
    printf("Encrypted: %s\n", text);

    caesar_decrypt(text, shift);
    printf("Decrypted: %s\n", text);

    return 0;
}
