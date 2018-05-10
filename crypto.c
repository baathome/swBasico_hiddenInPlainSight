#include "crypto.h"

///Encodes (or decodes) a string using a simple XOR mask (defined in crypto.h)
///@param s is the string to be encoded
void xormask (char *s)
{
    int len = strlen(s);
    for(int i=0; i<len; i++){
        s[i] ^= MASK;
    }
}
