#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

/*
    In this code, I've implemented substitution cipher(Yerine Koyma Şifrelemesi). Which is a simple replacement cryptography algorithm.
    Encrypts and decrypts messages(up to 100 char) by replacing each letter in the plaintext
    with a corresponding letter from a shuffled 26-letter key (substitution alphabet).
*/

void encrypt(char *, char *,char *);
void decrypt(char *, char *, char *);
void CreateKey(char *, char *);
void swap(char *, char *);
int FindIndex(char *, char);

int main(void){

    srand(time(NULL)); // For randomness

    char plaintext[100];
    char key[27];
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    char alphabet2[27];
    strcpy(alphabet2, alphabet);
    char ciphertext[100];

    printf("Enter plaintext: ");
    fgets(plaintext, 100, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("1- Enter your key in english alphabet \n");
    printf("2- Let us generate a random key \n");
    printf("?: ");

    int choice;
    scanf("%d", &choice);
    getchar();

    if(choice == 1){
       printf("Enter your key: ");
       fgets(key, 26, stdin);
       key[strcspn(key, "\n")] = '\0';
    }
    else if(choice == 2){
        CreateKey(key, alphabet2);
    }
    else{
        printf("Wrong choice try again! ");
        return 1;
    }
    printf("Key     : %s\n", key);

    printf("Alphabet: %s\n", alphabet);
    encrypt(key,plaintext,ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(key, ciphertext, alphabet);

    return 0;
}

void  CreateKey(char *key, char *alphabet){
    
    for(int i = 0 ; i < 26 ; i++){
        int n = rand() % 26; // [0-25]
        swap(&alphabet[i], &alphabet[n]);
    }    
    alphabet[26] = '\0';
    strcpy(key, alphabet);
}

void swap(char *c1, char *c2){
    char c = *c1;
    *c1 = *c2;
    *c2 = c;
}

void encrypt(char *key, char *plaintext, char *ciphertext){

    int size = strlen(plaintext);

    for(int i = 0 ; i < size ; i++)
    {
        if(isupper(plaintext[i])){
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        }else if(islower(plaintext[i])){
            ciphertext[i] = key[plaintext[i] - 'a'];     
        }else{
            ciphertext[i] = plaintext[i]; 
        }
    }

    ciphertext[size] = '\0';
}

void decrypt(char *key, char *ciphertext, char *alphabet){
    
    char plaintext[100];
    int size = strlen(ciphertext);
    for(int i = 0 ; i < size ; i++)
    {
        if(isupper(ciphertext[i])){
            plaintext[i] = toupper(alphabet[FindIndex(key, ciphertext[i])]);
        }else if(islower(ciphertext[i])){
            plaintext[i] = alphabet[FindIndex(key, ciphertext[i])];
        }else{
            plaintext[i] = ciphertext[i]; 
        }
    }
    plaintext[size] = '\0';
    printf("plaintext: %s", plaintext);
}

int FindIndex(char *key, char c){

    int size = strlen(key);

    for(int i = 0 ; i < size ; i++)
        if(key[i] == c)
            return i;
}