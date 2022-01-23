#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//string compare function
int compare_strings (const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main(){
    const char string[] = "print happy against monkey need different effect sheep paper horse parallel journey kind account opinion lock knowledge look weather join market space married who nerve responsible payment again while rhythm prison opposite special why authority rest school operation river year shake than shame push when question road waiting Zoo respect that ring then very theory water tomorrow wheel umbrella the view walk twist unit voice waste together week weight yesterday tooth you young Zibra will yellow brain verse Xray cloud adjustment between where connection branch care needle about with addition cart button control desire Xman cloth balance";
    char inputString[sizeof(string)];
    char delimiter[] = " ";
    char *ptr;
    char *word[100];
    char *smallLetterWord[97];
    int arraySize;
    int boolArr[100] = {0};
    
    printf("Enter String\n");
    scanf("%[^\n]%*c",inputString);
    
    //Check Input String
    if(strncmp(inputString,string, sizeof(string)) == 0){
        printf("\n");
    }else{
        printf("\nError! Wrong Input String\n\n");
        printf("The Correct String =\n%s\n", string);
        return 0;
    }

    //split Input String
    ptr = strtok(inputString, delimiter);
    arraySize = 0;
    word[arraySize]=ptr;
    while(ptr!=NULL){
        word[arraySize] = ptr;
        ptr = strtok(NULL, delimiter);
        arraySize+=1;
    }

    //copy splited array for sorting purpose
    memcpy(smallLetterWord, word, sizeof(word));
    
    //change copied array to lower case, remark the upper case's word using int array
    for(int i=0; i<arraySize; i++){
        ptr = smallLetterWord[i];
        while(*ptr){
            if(isupper(*ptr)){
                *ptr = tolower(*ptr);
                boolArr[i] = 1;
            }
            ptr++;
        }
    }

    //sort copied array in alphabetical order
    size_t wordCount = sizeof smallLetterWord/sizeof *smallLetterWord;
    qsort(smallLetterWord, wordCount, sizeof *smallLetterWord, compare_strings);
    
    //search upper case words by int array and change it back to upper case 
    for(int i=0; i<arraySize; i++){
        if(boolArr[i]==1){
            int upperNum = i;
            for(int j=0; j<arraySize; j++){
                int result = strcmp(word[i], smallLetterWord[j]);
                if(result==0){
                    ptr = smallLetterWord[j];
                    *ptr = toupper(*ptr);
                }else{
                    continue;
                }
            }
        }else{
            continue;
        }  
    }
    //print sorted array
    for(int i=0; i<arraySize; i++){
        printf("Word[%d] : %s\n", i, smallLetterWord[i]);
    }

    return 0;
}