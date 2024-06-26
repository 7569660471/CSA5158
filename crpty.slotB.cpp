#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to encrypt a single character
char encryptChar(char ch, char key) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return ((ch - base + key) % 26) + base;
    }
    return ch; // Non-alphabetical characters remain unchanged
}

// Function to perform polyalphabetic substitution encryption
void polyalphabeticEncrypt(char plaintext[], char key[]) {
    int keyLength = strlen(key);
    int textLength = strlen(plaintext);
    int j = 0; // index for the key

    for (int i = 0; i < textLength; ++i) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = encryptChar(plaintext[i], key[j] - 'A');
            j = (j + 1) % keyLength;
        }
    }
}

int main() {
    char plaintext[100], key[100];

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character if present

    // Input key
    printf("Enter key (only alphabets): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline character if present

    // Encrypt plaintext using polyalphabetic substitution cipher
    polyalphabeticEncrypt(plaintext, key);

    // Output encrypted text
    printf("Encrypted text: %s\n", plaintext);

    return 0;
}
