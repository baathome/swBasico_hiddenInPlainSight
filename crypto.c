#include "crypto.h"

///Encodes (or decodes) a string using a simple XOR mask (defined in crypto.h)
///@param s is the string to be encoded
void strxormask (char *s)
{
    int len = strlen(s);
    for(int i=0; i<len; i++){
        s[i] ^= MASK;
    }
}


///Encodes (or decodes) a linked list of characters using a simple XOR mask (defined in crypto.h)
///@param s is the list to be encoded
void llxormask (Node *p)
{
	while(p){
		p->c ^= MASK;
		p=p->next;
	}
}
