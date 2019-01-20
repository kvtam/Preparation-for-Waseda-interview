/*
    Author: Kyle Tam
    Reason: source for function defs
    Objective: In C count the frequency of each word in an Html file
    Created: January 17, 2019
    Last Rev: January 17, 2019
*/
#include "hashtable.h"
//function to search the node for searching through a set of nodes for a specific key
//Precondition:
//Postcondition:
//return value 0 if not in table, else value if in table
int searchnode(word w1,hashtable t1, char val)
{
     node *nodeptr;
     *nodeptr=(t1._table[val]);

    while(NULL!=(*nodeptr)._next){
        if(wordsAreEqual(w1,(*nodeptr)._node_word))
        {
        }
       nodeptr= (*nodeptr)._next;
    }
    return 0;
}

void insert(word w1,hashtable t1, char val)
{
    if(searchnode(w1,t1,val))
    {

    }
}
