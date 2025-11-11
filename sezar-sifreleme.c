#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*
    In this code, I'm going to implement Caesar's Cipher(Caesar's cryptography algorithm) and I'm going to try to find the
    plaintext, by trying all possible outcomes until it reaches the plaintext.
*/ 

void encrypt(char *, int);
void decrypt(char *, int);
void AllOutcomes(char *, char *);

int main(void){

    char text[100];
    
    printf("Enter plaintext: ");
    fgets(text, 100, stdin);

    int key;
    printf("Enter key: "); 
    scanf("%d", &key);
    
    char plaintext[100];
    strcpy(plaintext, text);
    printf("Plaintext: %s\n", text);

    encrypt(text, key);
    printf("Encrypted: %s\n", text);

    char ciphertext[100];
    strcpy(ciphertext, text);

    AllOutcomes(ciphertext, plaintext);

    decrypt(text, key);

    printf("Decrypted: %s\n", text);
    printf("Press any key...\n");
    getch();

    return 0;
}

void encrypt(char *text, int key){

    key = key  % 26;

    char c = text[0];
    int i = 0;
    
    while(c != '\0'){

        if(c >= 'A' && c <= 'Z'){
            text[i] = 'A' + (text[i] - 'A' + key) % 26;
        }

        if(c >= 'a' && c <= 'z'){
            text[i] = 'a' + (text[i] - 'a' + key) % 26;
        }       
        i++;
        c = text[i];
    }

}

void decrypt(char *text, int key){

    key = key  % 26;

    char c = text[0];
    int i = 0;
    
    while(c != '\0'){

        if(c >= 'A' && c <= 'Z'){
            text[i] = 'A' + (text[i] - 'A' - key + 26) % 26; 
        }

        if(c >= 'a' && c <= 'z'){
            text[i] = 'a' + (text[i] - 'a' - key + 26) % 26;
        }       
        i++;
        c = text[i];
    }

}

void AllOutcomes(char *ciphertext, char *plaintext){
    
    char temp[100];
    strcpy(temp, ciphertext);

    for(int i = 0; i < 26 ; i++){  // 0 and 26 would be the same.

        decrypt(ciphertext,i);

        if(strcmp(plaintext, ciphertext) == 0){
            printf("Key is: 26k + %d, where k = {0,1,2,3 ...}\n", i);
            break;
        }
        printf("%d. possible: %s", i+1, ciphertext);
        strcpy(ciphertext, temp);
    }

}