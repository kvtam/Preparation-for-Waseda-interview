/*
    Author: Kyle Tam
    Reason: Header to organize code
    Objective: In C count the frequency of each word in an Html file
    Created: January 9, 2019
    Last Rev: January 10, 2019
*/
#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED
//Set an arbitrary string size, can change this later.
#define stringsize 20
//Set a list size to arbitrary value
#define listsize 350
#include <stdbool.h>
#include <stdio.h>
//Structure to keep track of a word and how many times it appears
typedef struct{
    short _freqency;
    short _wordsize;
    char _word[stringsize];

} word;

bool wordsAreEqual(const word w1,const word w2);
void removeHTML(FILE *fp,char *ch);


#endif // WORD_H_INCLUDED
