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
#include <assert.h> //for debug
#include "word.h"

#define filename "The Linux Kernel HOWTO_ Compiling the kernel.html"


word list[listsize];// make the word list global for now
short num_of_words=0;//Variable for the actual number of words

//check the list to see if the word is already in it
//returns position of a word in the array or -1 if not there
//precondition: Word object is built and is lowercase
//postcondition: it is known whether object is in list and it's location
short inList(const word w1)
{
    assert(num_of_words!=listsize);///for debug, make sure list can hold everything
    short temp=0;
        //iterate through the list and return if the word is in the list
        for(temp;temp<num_of_words;temp++)
        {
            if(wordsAreEqual(w1,list[temp]))
                return temp;
        }
        //only get to this point if the word is not in the list
        return -1;
}
//Function to update the word list
//precondition: word object is built and lower case
//postcondition: word object is in the list
void listUpdate(word w1)
{
    //First check if word is in the list
    short ret =inList(w1);
    //if not add it to the list
    //and update the number of words in the list
    if(ret==-1)
    {
        w1._freqency=1;
        list[num_of_words]=w1;
        num_of_words++;
    }
    else //word is already in the list
    {
        list[ret]._freqency++;
    }
}

//Parse the file and read all relevant info into a buffer
//Preconditions: file is opened successfully
//Postconditions: file_pointer points to eof
void parseFile(FILE *fp)
{
    char ch[2]={""};
    word w1={1,0,""};
        //Keep reading until EOF
        while(!(feof(fp)))
        {
        assert(w1._wordsize!=stringsize);///for debug
            //read single character
            fscanf(fp,"%c",ch);
            removeHTML(fp,ch);

     /*       if((isalpha(*ch))||isspace(*ch))
            {
                *ch=tolower(*ch);
                printf(ch); ///for debug
            }
       */     //Check if a roman character
            if(isalpha(*ch))//if it is throw it into lowercase
            {
                *ch=tolower(*ch);
                //put it into the word object and update the size of the word
                w1._word[w1._wordsize]=*ch;
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
                listUpdate(w1);
                //reset the temp word
                word temp_word={1,0,""};
                w1=temp_word;
            }

        }


}
//Function to print each word and its count
//precondition: word list is constructed
//postcondition: words are printed to console
void printWords(void)
{
    short temp=0;

        for(temp;temp<num_of_words;temp++)
        {
            word current_word=list[temp];
          /*  //if the
                if(!current_word._wordsize)
                {
                    printf("Total unique words: %d",num_of_words);
                    break;
                }
*/
            printf("The word: \"%s\" was found %d times \n",current_word._word,current_word._freqency);

        }
}

int main()
{
    //File i/o
    FILE *file_ptr;
    file_ptr= fopen(filename,"r");
    parseFile(file_ptr);
    printWords();
    return 0;
}
