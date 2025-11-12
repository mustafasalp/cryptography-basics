#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

void MergeWords(char *);
void encrypt(char *, char *, char *, char *);
// void decrypt(char *, char *, char *);

int main(void){

    char plaintext[100];
    char key[100];
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    char ciphertext[100];

    printf("Your plaintext and key should be same by their lower and upper\n");
    printf("For example if your plaintext is \"mustafa salih alp\"");
    printf("Then your key should be like \"alp\".\n\n");

    printf("Enter plaintext(only lower or upper): ");
    fgets(plaintext, 100, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    MergeWords(plaintext);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(plaintext, key, alphabet, ciphertext);
    // decrypt(key, alphabet, ciphertext);

    return 0;
}

void MergeWords(char *plaintext){

    int size = strlen(plaintext);
    int j = 0;

    for(int i = 0; i < size ; i++){
        if(!isspace(plaintext[i])){
            plaintext[j++] = plaintext[i];
        }
    }

    plaintext[j] = '\0';
    printf("plaintext: %s\n", plaintext);
}

void encrypt(char *plaintext, char *key, char *alphabet, char *ciphertext){

    int text_size = strlen(plaintext);
    int key_size = strlen(key);

    if(text_size > key_size){
    
        for(int i = 0 ; i < text_size - key_size ; i++){
            key[i + key_size] = key[i]; 
        }

        key[text_size] = '\0';
        printf("key      : %s\n", key);
        
        for (int i = 0; i < text_size; i++){
        
            if(isupper(plaintext[i])){
                ciphertext[i] = toupper(alphabet[((key[i] - 'A') + (plaintext[i] -'A')) % 26]);
            }else if(islower(plaintext[i])){
                ciphertext[i] = alphabet[((key[i] - 'a') + (plaintext[i] -'a')) % 26];
            }else{
                ciphertext[i] = plaintext[i];
            }
        }
    }else if(key_size > text_size){
        
        for (int i = 0; i < text_size; i++){
        
            if(isupper(plaintext[i])){
                ciphertext[i] = toupper(alphabet[((key[i] - 'A') + (plaintext[i] -'A')) % 26]);
            }else if(islower(plaintext[i])){
                ciphertext[i] = alphabet[((key[i] - 'a') + (plaintext[i] -'a')) % 26];
            }else{
                ciphertext[i] = plaintext[i];
            }
        }   
    }else{
        for (int i = 0; i < text_size; i++){
        
            if(isupper(plaintext[i])){
                ciphertext[i] = toupper(alphabet[((key[i] - 'A') + (plaintext[i] -'A')) % 26]);
            }else if(islower(plaintext[i])){
                ciphertext[i] = alphabet[((key[i] - 'a') + (plaintext[i] -'a')) % 26];
            }else{
                ciphertext[i] = plaintext[i];
            }
        }
    }

    ciphertext[text_size] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char *key, char *alphabet, char *ciphertext){

    // I couldn't find any decryption yet.I will handle soon.
}