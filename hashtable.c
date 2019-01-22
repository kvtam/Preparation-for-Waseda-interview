/*
    Author: Kyle Tam
    Reason: source for function defs
    Objective: In C count the frequency of each word in an Html file
    Created: January 17, 2019
    Last Rev: January 17, 2019
*/
#include "hashtable.h"
#include "word.h"
#include <stdlib.h>
//function to search the node for searching through a set of nodes for a specific key insert the word if not there
//Precondition: We already know the word we are searching for
//Postcondition: Word is in the list
//return frequency of the word
///TODO: Change return type
int searchnode(word w1,hashtable t1, short val)
{
     node *nodeptr= malloc(sizeof(node));
     *nodeptr=(t1._table[val]);
    //while not at the end of the list find the word
    while(NULL!=(*nodeptr)._next){
        if(wordsAreEqual(w1,(*nodeptr)._node_word))
        {
            (*nodeptr)._freqency++;
           return (*nodeptr)._freqency;
        }
       nodeptr= (*nodeptr)._next;
    }
    //if we get here word is not in the list, so insert it
    insert(*nodeptr,w1);
    return 1;
}
// function to insert the word into the open hashed list
//precondition: n1._next points to a NULL
//postcondition: word is in the list
void insert(node n1, word w1)
{
    node *temp=malloc(sizeof(node));
    temp->_node_word=w1;
    temp->_freqency=1;
    temp->_next=NULL;
    n1._next=temp;
}

