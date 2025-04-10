#include <stdio.h>
#include <ctype.h>

void caesar_cipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

int main() {
    char input_text[1000];
    int shift_value;

    printf("Enter text: ");
    fgets(input_text, sizeof(input_text), stdin);

    printf("Enter shift: ");
    scanf("%d", &shift_value);

    caesar_cipher(input_text, shift_value);
    printf("Encrypted text: %s", input_text);

    return 0;
}
