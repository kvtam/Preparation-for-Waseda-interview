/*
    Author: Kyle Tam
    Reason: Source code for Dr. Kimura's interview
    Objective: In C count the frequency of each word in an Html file
    Created: January 8, 2019
    Last Rev: January 9, 2019

*/
/*  Notes from Jan 9: Compiles
    Code currently prints out the whole html doc with one char per line in thee console window
    This verifies: File is opened correctly, File is being read to eof
    next step: remove html tags

    update:
    Code currently prints the words in the file printing a new line on a space
    Code also removes html tags
    This verifies: The characters being printed are not within html tags
    next step make the characters into words.



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Set an arbitrary string size, can change this later.
#define stringsize 20
//Set a list size to arbitrary value
#define listsize 100
#define filename "The Linux Kernel HOWTO_ Compiling the kernel.html"

//Structure to keep track of a word and how many times it appears
typedef struct{
    short _freqency;
    char _word[stringsize];

} word;
// make the word list global for now
word list[listsize];
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
//Parse the file and read all relevant info into a buffer
//Preconditions: file is opened successfully
//Postconditions: file_pointer points to eof
void parseFile(FILE *fp)
{
    char ch[2]={""};
        //Keep reading until EOF
        while(!(feof(fp)))
        {
        //read single character
        fscanf(fp,"%c",ch);
        removeHTML(fp,ch);
        printf(ch);
        if(*(ch)==" ")
        printf("\n");
        }


}

int main()
{
    //File i/o
    FILE *file_ptr;
    file_ptr= fopen(filename,"r");
    parseFile(file_ptr);
/*
    char buff[20]={""};
    fscanf(file_ptr,"%c",buff);
    if((*buff)== '<')
        printf("works\n");
*/
    // create an array of the structs containing the words and their count


    //char a[]="Hello world!\n";
  //  printf(buff);
    return 0;
}
