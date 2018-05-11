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

    if(!strcmp(argv[2], "-c")){
        char message[1001];
        char password[101];

        printf("\nDigite sua mensagem: ");
        gets(message);

        printf("\nDigite uma senha: ");
        gets(password);

        strxormask(message);
        strxormask(password);

        writestego(&pic, password, message);

        int i=-1;
        while(argv[1][++i]!='.');
        argv[1][++i] = 'b';
        argv[1][++i] = 'm';
        argv[1][++i] = 'p';
        argv[1][++i] = 0;

        SOIL_save_image(argv[1], SOIL_SAVE_TYPE_BMP, pic.width, pic.height, 3, pic.img);
    }
    else if(!strcmp(argv[2], "-d")){
        Node *pass=0, *msg=0;

        readstego(pic, &pass, &msg);

        llxormask(pass);

        if(!strllcmp(argv[3], pass)){
            llxormask(msg);
            printf("\nMensagem: ");
            printl(msg);
        }
        else{
            printf("\nSenha Incorreta\n");
            printl(msg);
        }
        printf("\n");

        destroy(&pass);
        destroy(&msg);
    }

    free(pic.img);
    return 0;
}
