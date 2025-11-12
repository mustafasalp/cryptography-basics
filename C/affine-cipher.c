#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*
    The Affine cipher is a type of monoalphabetic substitution cipher,
    wherein each letter in an alphabet is mapped to its numeric equivalent,
    encrypted using a simple mathematical function, and converted back to a letter.
    The formula used means that each letter encrypts to one other letter, and back again,
    meaning the cipher is essentially a standard substitution cipher with a rule governing which letter goes to which. 

    The formula is Ax + B
    User enters A and B
*/

void encrypt(char *,char *, char *, int ,int);
void decrypt(char *, char *, int ,int);
int Find_a_Inv(int);
bool is_valid(int ,int);

int main(void){

    int a,b;
    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    char plaintext[100];
    char ciphertext[100];

    printf("Welcome to affine-cipher!\n");
    printf("Format is Ax + B\n");
    printf("Enter A: "); scanf("%d", &a);
    printf("Enter B: "); scanf("%d", &b);
    getchar();

    if(!is_valid(a,b)){
        printf("Run the program again, A and B values are not valid\n");
        printf("A should be coprime to 26 AND B should be between 0-25\n");
        return 1;
    }

    printf("Enter plaintext: ");
    fgets(plaintext, 100, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    encrypt(ciphertext, plaintext, alphabet, a, b);
    decrypt(ciphertext, alphabet, a, b);

    return 0;
}

void encrypt(char *ciphertext, char *plaintext, char *alphabet, int a, int b){

    int size = strlen(plaintext);

    for(int i = 0 ; i < size ; i++){
        if(isupper(plaintext[i])){
            ciphertext[i] = toupper(alphabet[((a*(plaintext[i] - 'A') + b) % 26)]) ; 
        }else if(islower(plaintext[i])){ 
            ciphertext[i] = alphabet[((a*(plaintext[i] - 'a') + b) % 26)]; 
        }else{
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[size] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char *ciphertext, char *alphabet, int a, int b){
    
    int size = strlen(ciphertext);
    char plaintext[100];

    int a_inv = Find_a_Inv(a);

    for(int i = 0 ; i < size ; i++){
        if(isupper(ciphertext[i])){
            plaintext[i] =  toupper(alphabet[((a_inv * ((ciphertext[i] - 'A') - b + 26)) % 26)]);
        }else if(islower(ciphertext[i])){ 
            plaintext[i] = alphabet[((a_inv * ((ciphertext[i] - 'a') - b + 26)) % 26)];
        }else{
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[size] = '\0';
    printf("Plaintext: %s",plaintext);
}

int Find_a_Inv(int a){

    int flag;

    for(int i = 0 ; i < 26 ; i++){

        flag = (a * i) % 26;

        if(flag == 1)
            return i;
    }

    return -1;
}

bool is_valid(int a, int b){
 
    bool a_valid = false;
    bool b_valid = false;

    if(Find_a_Inv(a) != -1)
        a_valid  = true;
    if(b >= 0 && b <= 25)
        b_valid = true;
        
    return (a_valid && b_valid);
}
