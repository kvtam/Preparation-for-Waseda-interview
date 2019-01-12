/*
    Author: Kyle Tam
    Reason: source for function defs
    Objective: In C count the frequency of each word in an Html file
    Created: January 10, 2019
    Last Rev: January 10, 2019
*/
#include "word.h"
#include <string.h>

//Function for comparing if 2 words are equal
//Pre
bool wordsAreEqual(const word w1,const word w2)
{
    return(!strcmp(w1._word,w2._word));

}
//function to remove html tags
//Preconditions: same as parseFile()
//Postconditions: ch now holds a character not within a tag
void removeHTML(FILE *fp,char *ch)
{

    //If the character is '<'
    if((*ch)=='<'){
        //read until '>'
        while(!(feof(fp)))
        {
        fscanf(fp,"%c",ch);
            if((*ch)=='>')
            {
                //Have to read the next char before exiting
                fscanf(fp,"%c",ch);
                    if((*ch)=='<')
                        continue;
                //else
                break;
            }
        }
    }
}

