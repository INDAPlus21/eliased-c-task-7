#include <stdio.h>                
#include <stdlib.h>
#include <math.h>

int compare_function(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

int main()
{
    int howmanynums;
    scanf("%d", &howmanynums);
    int abssum = 0; 
    int *numvec = malloc(howmanynums * sizeof(int));
    for(int i=0; i < howmanynums; i++) {
        scanf("%d", &numvec[i]);
    }

    qsort(numvec, howmanynums, sizeof(int), compare_function); // Sorts alphabetically. Don't need to use cmpfunc 
    for(int i=howmanynums/2; i < howmanynums; i++) {
        abssum = abssum + numvec[i];
    }
    printf("%d", abssum);
}