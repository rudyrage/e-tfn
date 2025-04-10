#include <stdio.h>
#include <string.h>

#define MAX 3

void encrypt(char message[], int key[MAX][MAX]) {
    int len = strlen(message);
    int matrix[MAX][1];
    
    printf("Cipher Text: ");
    
    for (int i = 0; i < len; i += MAX) {
        for (int j = 0; j < MAX; j++) {
            matrix[j][0] = message[i + j] - 'A';
        }
        
        for (int j = 0; j < MAX; j++) {
            int sum = 0;
            for (int k = 0; k < MAX; k++) {
                sum += key[j][k] * matrix[k][0];
            }
            printf("%c", (sum % 26) + 'A');
        }
    }
    printf("\n");
}

int main() {
    char message[100];
    int key[MAX][MAX] = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}
    };

    printf("Enter message (only uppercase): ");
    fgets(message, sizeof(message), stdin);
    
    int len = strlen(message);
    if (len % MAX != 0) {
        int pad_len = MAX - (len % MAX);
        for (int i = 0; i < pad_len; i++) {
            message[len + i] = 'X';
        }
        message[len + pad_len] = '\0';
    }

    encrypt(message, key);
    
    return 0;
}
