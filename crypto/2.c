#include <stdio.h>

void shift_cipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

int main() {
    char text[100];
    int shift;
    
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter shift value: ");
    scanf("%d", &shift);
    
    shift_cipher(text, shift);
    
    printf("Ciphered text: %s", text);
    
    return 0;
}
