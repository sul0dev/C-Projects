#include <stdio.h>
#include <string.h>
#include <ctype.h>

char letters[26] = {'A', 'B', 'C', 'D', 'E',
                    'F', 'G', 'H', 'I', 'J',
                    'K', 'L', 'M', 'N', 'O',
                    'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z'};

int findLetterIndex(char arr[], char target){
    for(int i = 0; i < 26; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    char word[100];
    int key;

    printf("Type a word to encrypt it (uppercase only): ");
    scanf("%s", word);

    printf("Type a key to encrypt the word: ");
    scanf("%d", &key);

    printf("Encrypted text: ");
    for(int i = 0; word[i] != '\0'; i++){
        if(isalpha(word[i])){
            char upper = toupper(word[i]); // küçük harfse büyüt
            int index = findLetterIndex(letters, upper);
            if(index != -1){
                int newIndex = (index + key) % 26;
                printf("%c", letters[newIndex]);
            } else {
                printf("%c", word[i]); // harf değilse olduğu gibi yaz
            }
        } else {
            printf("%c", word[i]); // harf değilse olduğu gibi yaz
        }
    }

    printf("\n");
    return 0;
}
