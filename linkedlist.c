#include "linkedlist.h"

///Appends a new node to the end of the list
void append(char c, Node **p)
{
    if(!(*p)){
        *p = (Node *) calloc(1, sizeof(Node));
        (*p)->c = c;
    }
    else if(!((*p)->next)){
        (*p)->next = (Node *) calloc(1, sizeof(Node));
        ((*p)->next)->c = c;
    }
    else{
        append(c, &((*p)->next));
    }
}

///Returns the length of the list
int listlen(Node *p)
{
    if(!p) return 0;
    return (1 + listlen(p->next));
}


///Prints the list contents
void printl(Node *p)
{
    if(!p) return;
    putchar(p->c);
    printl(p->next);
}


///Compares the list to a regular C string (char array). Returns 0 on equal, 1 on different
int strllcmp(char *s, Node *p)
{
    if(!*s || !p){
        if(!*s && !p) return 0;
        return 1;
    }
    if(*s != p->c) return 1;
    strllcmp(s+1, p->next);
}


///Compares two lists. Returns 0 on equal, 1 on different
int llcmp(Node *p, Node *q)
{
    if(!p || !q){
        if(!p && !q) return 0;
        return 1;
    }
    if(p->c != q->c) return 1;
    llcmp(p->next, q->next);
}

///Creates a linked list from regular C string (char array)
void fromstring(char *s, Node **p)
{
    int i=0;
    while(s[i]){
        append(s[i], p);
        i++;
    }
}


///Frees the entire list
void destroy(Node **p)
{
    Node *tmp;
    while(*p){
        tmp=*p;
        *p=(*p)->next;
        free(tmp);
    }
    *p=0;
}


///Separates p into two lists on a \0 character (first part in p, second in q)
void splitonzero(Node *p, Node **q)
{
	if(!p) return;
	if(!(p->next)) return;
	while(p->next->c){
		p=p->next;
	}

	(*q)=p->next->next;

	free(p->next);

	p->next=0;

	if(!(*q)) return;
	if(!((*q)->next)) return;

	Node (*aux)=(*q);
	while(aux->next->c){
		aux=aux->next;
	}
	free(aux->next);
	aux->next=0;

}
