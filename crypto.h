#ifndef encoder_h
#define encoder_h

#include <string.h>
#include "linkedlist.h"

#define MASK 0b10110100

void strxormask (char *s); ///Encodes (or decodes) a string using a simple XOR mask (defined in crypto.h)

void llxormask (Node *p); ///Encodes (or decodes) a linked list of characters using a simple XOR mask (defined in crypto.h)

#endif // encoder_h
