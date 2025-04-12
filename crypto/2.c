#include <stdio.h>

void shift_encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

void shift_decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        }
    }
}

int main() {
    char text[100];
    int shift;

    printf("Enter the text: ");
    scanf("%s", text);  

    printf("Enter shift value: ");
    scanf("%d", &shift);

    shift_encrypt(text, shift);
    printf("Encrypted text: %s\n", text);

    shift_decrypt(text, shift);
    printf("Decrypted text: %s\n", text);

    return 0;
}
