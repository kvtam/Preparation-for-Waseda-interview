/*
    Author: Kyle Tam
    Reason: Source code for Dr. Kimura's interview
    Objective: In C count the frequency of each word in an Html file
    Created: January 8, 2019
    Last Rev: January 10, 2019

*/
/*  Notes from Jan 9: Compiles
    Code currently prints out the whole html doc with one char per line in thee console window
    This verifies: File is opened correctly, File is being read to eof
    next step: remove html tags

    update:
    Code currently prints the words in the file printing a new line on a space
    Code also removes html tags
    This verifies: The characters being printed are not within html tags
    next step: make the characters into words.

    Notes from Jan 10: Compiles
    Code prints out all characters that are either letters, returns, or spaces
    This verifies: That everything in the console is either a letter or a space of some sort
    next step: match cases because The != the from the code's pov

    update:
    Code now prints everything in lowercase
    This verifies: That I can match cases
    next step: to put the words into "strings"

    Notes from Jan 11: Compiles
    Code now puts the words in a list with their frequencies
    This verifies: That I can identify words and count them correctly
    next step: figure out contractions

    Notes from Jan 12: compiles
    Code now works fully and identifies contractions
    This verifies: identification of contraction
    next step: make code look nicer

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "word.h"
#include "hashtable.h"

#define filename "The Linux Kernel HOWTO_ Compiling the kernel.html"

hashtable table;
//Parse the file and read all relevant info into a buffer
//Preconditions: file is opened successfully
//Postconditions: file_pointer points to eof
void parseFile(FILE *fp)
{
    //to hold the character gathered from the filestream for some reason the min size has to be 2 or else I get garbage on the output
    char ch[2]={""};
    short val=0;
    int ret;
    word w1={0,""};
        //Keep reading until EOF
        while(!(feof(fp)))
        {
            //read single character
            fscanf(fp,"%c",ch);
            removeHTML(fp,ch);
            //Check if a roman character
            if(isalpha(*ch))//if it is throw it into lowercase
            {
                *ch=tolower(*ch);
                //put it into the word object and update the size of the word
                w1._word[w1._wordsize]=*ch;
                //get the first letter to use as an index
                    if(w1._wordsize==0)
                    {
                        ///TODO
                        ///Code for some reason stops after one interation and only catches the 't'
                        val=(*ch)-97;
                    }
                w1._wordsize++;
            }
            //if it's not a roman char then end the word only if the temp
            //word has something in it
            else if(w1._wordsize)
            {
                    //Check for 's and 't
               if((*ch)==39) //if apostrophe
                {
                        //read next cha
                    fscanf(fp,"%c",ch);
                    *ch=tolower(*ch);
                    if((*ch)=='t'||(*ch)=='s')
                    {
                        w1._word[w1._wordsize]=39;
                        w1._word[w1._wordsize+1]=(*ch);
                        w1._wordsize+=2;
                    }

                }
                //update the list with the word
          //      listUpdate(w1);

                ret=searchnode(w1,table,val);
                //reset the temp word
                word temp_word={0,""};
                w1=temp_word;
            }

        }


}
//Function to print each word and its count
//precondition: word list is constructed
//postcondition: words are printed to console
void printWords(void)
{
    int i;
    node *nodeptr= malloc(sizeof(node));

    for(i=0;i<26;i++)
    {

        *nodeptr=(table._table[i]);
        while(NULL!=(*nodeptr)._next)
        {

            printf("The word %s appears %d times \n",(*nodeptr)._node_word._word,(*nodeptr)._freqency);
            nodeptr=(*nodeptr)._next;
        }
    }

    short temp=0;

}

int main()
{
    //File i/o
    FILE *file_ptr;

    file_ptr= fopen(filename,"r");
    parseFile(file_ptr);
    //print function
    printWords();
    return 0;
}
