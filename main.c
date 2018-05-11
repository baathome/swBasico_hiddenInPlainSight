#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"
#include "stego.h"
#include "linkedlist.h"

int main(int argc, char** argv)
{
    Img pic;
    if(argc < 1) {
        printf("loader [img]\n");
        exit(1);
    }
    load(argv[1], &pic);

    printf("Primeiros 10 pixels da imagem:\n");
    for(int i=0; i<10; i++) {
        printf("[%02X %02X %02X] ", pic.img[i].r, pic.img[i].g, pic.img[i].b);
    }
    printf("\n");



    Node *p=0, *q=0;
    char s[5]="test";
    char s2[15]="hello world";

    fromstring(s, &p);
    fromstring(s2, &q);

    writestego(&pic, s, s2);
    readstego(pic, &p, &q);

    printf("\npassword = ");
    printl(p);
    printf("\nmsg = ");
    printl(q);
    printf("\n\n");



    free(pic.img);



    printf("\n%d\n",strllcmp(s,p));
    printf("\n%d\n",llcmp(p,q));

    destroy(p);
    destroy(q);


    Node *password=0, *message=0;


    destroy(password);
    destroy(message);
    return 0;
}
