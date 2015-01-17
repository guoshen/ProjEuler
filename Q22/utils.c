///Commonly used utilities
#include "utils.h"
#include <stdio.h>

///sorting

void swap_str_ptrs(char  **arg1, char **arg2)
{
     char *tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}
void quicksort_strs(char *args[], unsigned int len)
{
    unsigned int i, pvt=0;

    if (len <= 1)
        return;

    // swap a randomly selected value to the last node
    swap_str_ptrs(args+((unsigned int)rand() % len), args+len-1);

    // reset the pivot index to zero, then scan
    for (i=0; i<len-1; ++i)
    {
        if (strcmp(args[i], args[len-1]) < 0)
            swap_str_ptrs(args+i, args+pvt++);
    }

    // move the pivot value into its place
    swap_str_ptrs(args+pvt, args+len-1);

    // and invoke on the subsequences. does NOT include the pivot-slot
    quicksort_strs(args, pvt++);
    quicksort_strs(args+pvt, len - pvt);
}

///split string seperate by char * delim, num holds the number of seperate parts
char ** split(char str[], char * delim, int * num )
{

    ///create temporary string
    char * tmpstr;
    /// output arr of split
    char ** arrofsplit = NULL;
    int i = 0;
    char *ptr=str;

    ///get the initial division

    tmpstr = strtok (str, delim);

    while (tmpstr != NULL )
    {

        ///change size of array of split words to match current
        arrofsplit = (char **)realloc(arrofsplit, (  i + 1 ) * sizeof( char * ));
        arrofsplit[i] = (char *)malloc(sizeof(char)*(strlen(tmpstr) + 1));
        ///copy temporary string to ith element of output array
        strcpy( arrofsplit[i], tmpstr );
        i++;
        ///get the next division
        tmpstr = strtok(NULL, delim);
    }
    *num=i;

    return arrofsplit;
}
void freeArray(char ** strarr, int length)
{

    int i;
    for(i=0; i<length; i++)
    {
        /// free each individual char *
        free(strarr[i]);
    }
    ///free char **
    free(strarr);

}