#ifndef stego_h
#define stego_h

// SOIL é a biblioteca para leitura das imagens
#include "SOIL.h"
#include <stdio.h>
#include <stdlib.h>

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

#endif // stego_h
