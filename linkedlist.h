#ifndef linkedlist_h
#define linkedlist_h

#include <stdlib.h>
#include <stdio.h>

struct node{
    unsigned char c;
    struct node *next;
};

typedef struct node Node;

void append(char c, Node **p); ///Returns the length of the list

int listlen(Node *p); ///Returns the length of the list

void printl(Node *p); ///Prints the list contents

int strllcmp(char *s, Node *p); ///Compares the list to a regular C string (char array). Returns 0 on equal, 1 on different

int llcmp(Node *p, Node *q); ///Compares two lists. Returns 0 on equal, 1 on different

void fromstring(char *s, Node **p); ///Creates a linked list from regular C string (char array)

void destroy(Node **p); ///Frees the entire list

void splitonzero(Node *p, Node **q); ///Separates p into two lists on a \0 character (first part in p, second in q)

#endif // linkedlist_h
