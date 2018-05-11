#ifndef stego_h
#define stego_h

// SOIL é a biblioteca para leitura das imagens
#include "SOIL.h"
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Um pixel RGB
typedef struct {
    unsigned char r, g, b;
} RGB;

// Uma imagem em RGB
typedef struct {
    int width, height;
    RGB* img;
} Img;

void load(char* name, Img* pic); // Carrega uma imagem para a struct Img

void readstego(Img i, Node **pass, Node **msg); ///Reads encrypted password and message from image

void writestego(Img *pic, char *pass, char *msg); ///Writes encrypted password and message to image

#endif // stego_h
