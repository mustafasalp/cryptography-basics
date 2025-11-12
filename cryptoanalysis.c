#include <stdio.h>
#include <stdlib.h>

/*
    This code is an implementation of basic **cryptanalysis**.

    What is cryptanalysis?
    → It is the study and analysis of encrypted text to find statistical patterns,
      often used to break substitution or transposition ciphers.
    → One common method is **frequency analysis**, which counts how often each
      letter appears in a text to identify common characters (like 'E' in English).
*/

int main(void){

    int charachters[257] = {0}; // Frequency table for all ASCII characters (0–256)
    int total = 0, count = 0, c = 0;  

    // Open file for reading and writing ("r+"). Used here mainly for reading.
    FILE *file = fopen("metin-mockingbird-book.txt","r+");

    if(file == NULL){ // check if file cannot be opened
        printf("File could not be opened\n");
        return 1;
    }

    // Read file character by character until End Of File (EOF)
    while((c = fgetc(file)) != EOF){
        charachters[c]++; // Increment frequency for this ASCII value.
        count++;          // Count total characters read
    }

    printf("Character [ASCII CODE]: (Percentage) Count\n");

    // Print characters that appeared at least once
    for(int i = 0 ; i < 256 ; i++){
        if(charachters[i] > 0){
            // %% prints a literal '%' sign
            printf("%c [%d]: (%% %.3f) %d\n", 
                   i, i, 
                   (charachters[i] * 100)/(float)count, 
                   charachters[i]);
            total += charachters[i]; // For validation of total count
        }
    }

    // Verify that the total counted matches total read
    printf("Total character count: %d/%d\n", total, count);

    return 0;
}
