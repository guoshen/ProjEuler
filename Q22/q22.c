/** Problem 22: Using names.txt (right click and 'Save Link/Target As...'), a 
46K text file containing over five-thousand first names, 
begin by sorting it into alphabetical order. Then working out 
the alphabetical value for each name, multiply this value by its alphabetical 
position in the list to obtain a name score.

What is the total of all the name scores in the file?

Note of Caution: Due to the sheer amount of memory, the program 
requires when reading the file
it might exceed the memory bounds on some systems. 
In that case you would read a part of the file
each time and calculate the scores accordingly.


See Question @: https://projecteuler.net/problem=22
Solved by: Shengyuan Guo in 2013
**/

#include <stdio.h>
#include "utils.h"
#include <string.h>


int return_namescore(char *);
int letterscore(char);
void assign_score(char *,int *, int);



int main()
{
    printf("The score is %d",return_namescore("p022_names.txt"));
    return 0;
}
void assign_score(char * str,int * ctr, int elementnum)

{
if(str)
{
    int i;
    for (i=0; i<strlen(str); i++)
    {
        *ctr+=letterscore(str[i])*elementnum;

    }
}

}

int letterscore(char letter)
{

    if(letter>='A' && letter<='Z') /// uppercase
    {
        return (int)letter-64;
    }
    else if(letter>='a'&& letter <='z') ///lowercase
    {
        return (int)letter-96;
    }
    else
        return 0; ///not a letter


}

int return_namescore(char * filename)
{
    FILE * file;
    file=fopen(filename,"r");

    if(file==NULL)
    {
        printf("Error file Not Found! \n");
        return -1;
    }
    char line[50000];
    fgets(line,50000, file);

    //printf("line:%s", line);
    int length=0;
    char ** arrofnames=split(line,"\",\"",&length);
    quicksort_strs(arrofnames,length);
    FILE * file_output;


    //print sorted arrofnames to output.txt file for ref;
    file_output=fopen("output.txt","w");


    int i;
    for(i=0; i<length; i++)
    {
        fprintf(file_output,"%s\n", arrofnames[i]);
    }
    /// calculate score
    int score=0;
    for(i=0; i<length; i++)
    {
        assign_score(arrofnames[i],&score,i+1);
    }

    freeArray(arrofnames,length);

    return score;
}
