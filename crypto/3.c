#include <stdio.h>
#include <string.h>

void rail_fence_cipher_encrypt(char *text, int key) {
    int len = strlen(text);
    char rail[key][len];
    
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < len; j++) {
            rail[i][j] = '\n';
        }
    }

    int row = 0, col = 0;
    int dir_down = 0;
    
    for (int i = 0; i < len; i++) {
        rail[row][col++] = text[i];
        
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;
        
        row += dir_down ? 1 : -1;
    }

    printf("Cipher Text: ");
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < len; j++) {
            if (rail[i][j] != '\n')
                printf("%c", rail[i][j]);
        }
    }
    printf("\n");
}

int main() {
    char text[100];
    int key;
    
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter key (number of rails): ");
    scanf("%d", &key);
    
    rail_fence_cipher_encrypt(text, key);
    
    return 0;
}
