/*
    Author: Kyle Tam
    Reason: hashtable "class"
    Objective: In C count the frequency of each word in an Html file
    Created: January 17, 2019
    Last Rev: January 17, 2019
*/
#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED
#include "word.h"
typedef struct{
    word _node_word;
    struct node* _next;
}node;
// make a open hash table for holding 26 nodes or "buckets"
typedef struct {
    node _table[26];
} hashtable;
//this is a lookup function for the hash table given the first letter of a word
int searchnode(word w1, hashtable t1, char val);
// insert a new node
void tableinsert(word w1, hashtable t1, char val);
#endif // HASHTABLE_H_INCLUDED
