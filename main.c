#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*return 1 means that user entered something wrong
 * return 0 means that program work correctly */
void lower(char * str){
    unsigned long len = strlen(str);
    for(int i = 0; i < len; i++){
        str[i] = tolower(str[i]);
    }
}
int compare(const char * strA, const char * strB){
    for(int i = 0; i < strlen(strB); i++){
        if(strA[i] == strB[i]){
            printf("Nespravny vstup.\n");
            return 1;
        }
    }
}

int readstr( char * line, const char * b, unsigned counter, unsigned N){
    //creating array for count letters in text
    int arr[strlen(b)];
    //char ** limb = (char**)malloc(strlen(line)*sizeof(char*));
    // cut string from "
    for(int i = 0; i < strlen(line); i++){
        printf("%c", line[i]);
        if(line[i] == '"') line[i] == ' ';
    }

    //cut row to the words ,.-;:'!?
    /*
    char *delwords = strtok(line, " ");
    while (delwords != NULL) {
        limb[counter]=delwords;
        printf("%s\n",limb[counter]);
        counter++;
        delwords = strtok(NULL, " ");
    }
    //take count of letters in text and return if don't have some letters from "zkratka"
    unsigned long lenb = strlen(b);//не работает потому что то с стрленом не правильно надо добавить знак 0 при копировании
    char *word;
    for(int j = 0; j < counter; j++ ){
        strcpy(word,limb[j]);
        unsigned long lenw = strlen(word);
        word[counter-1] = '\0';
        printf("%s, %lu", word, lenw);
        for(int i = 0; i < lenb; i++ ){
            for(int k = 0; k < lenw; k++){
                if(b[i] == word[k]) arr[i]++;
                printf("%d, %c = %c %lu",arr[i], b[i], word[k], lenw);
            }
        }
    }

    for(int i = 0; i < lenb; i++){
        printf("The letter '%c' occurs %du times in text '", b[i], arr[i]);
        for(int i = 0; i < counter; i++){
            printf("%s ",limb[i]);
        }
        printf("'\n");
    }*/
}
int main() {
    char * a = (char*)malloc(1000 * sizeof(char*));
    char * b = (char*)malloc(1000 * sizeof(char*));
    char * line = (char*)malloc(102 * sizeof(char*));
    unsigned N = 0, rezultcount = 0, counter = 0;
    char ch, kov;
    printf("Zkratka:\n");
    scanf(" %s", a);

    //scaning abbreviation and check condition
    strcpy(b, a);
    lower(b);
    compare(a, b);

    //add line
    printf("Problemy:\n");
    scanf(" %c", &ch);
    if(ch != '?' && ch != '#'){
        printf("Nespravny vstup.\n");
        return 1;
    }
    scanf(" %c", &kov);
    if(kov != '"'){
        printf("Nespravny vstup.\n");
        return 1;
    }
    fgets(line,1000, stdin);
    readstr(line, b, counter, N);
    if(ch == '?'){

    }else if(ch == '#'){
        for(int i=0; i < N; i++){
            printf("> limit %d: %lu\n", i, rezultcount);
        }
        return 0;
    }else{
        printf("Nespravny vstup.2\n");
        return 1;
    }
    return 0;
}

