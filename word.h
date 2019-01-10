#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED
//Set an arbitrary string size, can change this later.
#define stringsize 20
//Set a list size to arbitrary value
#define listsize 100
//Structure to keep track of a word and how many times it appears
typedef struct{
    short _freqency;
    char _word[stringsize];

} word;

#endif // WORD_H_INCLUDED
