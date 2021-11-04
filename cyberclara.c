#include <stdio.h>                
#include <stdlib.h>
#include <string.h>

// Both need to be 42 because  the destination array needs to be the same size as the start string. 
// And it did work for the first two examples because Kattis didn't have names that reached the maximum size (?) 

int main()
{
    int howmanynames;
    scanf("%d", &howmanynames);
    char namevec[howmanynames*2][42];  
    char accvec[howmanynames][42]; // Accvec is the vector in which we add the unique first name + surname 
    for(int i=0; i < howmanynames*2; i++) {
        scanf("%s", &namevec[i][0]);
    }
    for(int i=0; i < howmanynames; i++) {
        char *concated = strcat(strcat(namevec[i], " "),  namevec[i+howmanynames]);
        strcpy(accvec[i], concated); //namevec[i];
    }
    /*int cmpfunc(const void *lhs, const void *rhs) {
        return strcmp(lhs, rhs);
    }*/
    //char notduplicatevec[howmanynames][42];     
    int count = 0;
    qsort(accvec, howmanynames, sizeof(char)*42, strcmp); // Sorts alphabetically. Don't need to use cmpfunc 
    for(int i = 0; i < howmanynames; i++) { 
        if (strcmp(accvec[i],accvec[i+1]) != 0) { // When it's sorted alphabetically we can compare directly. If the strings are equal, strcmp returns 0 (it tests that they are not equal)
            count++;
        }
    }

    printf("%d", count);

    return 0;
}