#include "stego.h"

// Carrega uma imagem para a struct Img
void load(char* name, Img* pic)
{
    int chan;
    pic->img = (unsigned char*) SOIL_load_image(name, &pic->width, &pic->height, &chan, SOIL_LOAD_RGB);
    if(!pic->img)
    {
        printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
        exit(1);
    }
    printf("Load: %d x %d x %d\n", pic->width, pic->height, chan);
}

///Reads encrypted password and message from image
///@params pic is a struct representing the image (defined in stego.h), pass and msg are linked lists of characters that contain the (encrypted) password and message, respectively
void readstego(Img pic, Node **pass, Node **msg)
{
	char tmp;
	int bitcount=0, i=0, zflag=0;
	while(zflag<2){
		tmp = pic.img[i].r & 0b00000011 << (6-bitcount);
		bitcount += 2;
		if(bitcount == 8){
			if(!tmp){
				zflag++;
			}
			append(tmp, pass);
			bitcount=0;
		}
		tmp = pic.img[i].g & 0b00000011 << (6-bitcount);
		bitcount += 2;
		if(bitcount == 8){
			if(!tmp){
				zflag++;
			}
			append(tmp, pass);
			bitcount=0;
		}
		tmp = pic.img[i].b & 0b00000011 << (6-bitcount);
		bitcount += 2;
		if(bitcount == 8){
			if(!tmp){
				zflag++;
			}
			append(tmp, pass);
			bitcount=0;
		}
		i++;
	}
	splitonzero(*pass, msg);
}


///Writes encrypted password and message to image
///@params pic is a struct representing the image (defined in stego.h), pass and msg are arrays of characters that contain the (encrypted) password and message, respectively
void writestego(Img *pic, char *pass, char *msg)
{
	int bitcount=0, i=0, j=0;
	char breakstate=0;


	while(1){
		pic->img[i].r = (pic->img[i].r & 0b11111100) | (pass[j] >> (6-bitcount));
		bitcount += 2;
		if(bitcount == 8){
			if(!pass[j]){
				breakstate='r';
				break;
			}
			bitcount=0;
			j++;
		}
		pic->img[i].g = (pic->img[i].g & 0b11111100) | (pass[j] >> (6-bitcount));
		bitcount += 2;
		if(bitcount == 8){
			if(!pass[j]){
				breakstate='g';
				break;
			}
			bitcount=0;
			j++;
		}
		pic->img[i].b = (pic->img[i].b & 0b11111100) | (pass[j] >> (6-bitcount));
		bitcount += 2;
		if(bitcount == 8){
			if(!pass[j]){
				breakstate='b';
				break;
			}
			bitcount=0;
			j++;
		}
		i++;
	}

	j=0;


	switch(breakstate){
	case 'r':
		pic->img[i].r = (pic->img[i].r & 0b11111100) | (pass[j] >> (6-bitcount));
		bitcount += 2;
	case 'g':
		pic->img[i].g = (pic->img[i].g & 0b11111100) | (pass[j] >> (6-bitcount));
		bitcount += 2;
	case 'b':
		pic->img[i].b = (pic->img[i].b & 0b11111100) | (pass[j] >> (6-bitcount));
		bitcount += 2;
		i++;
	}


	while(1){
		pic->img[i].r = (pic->img[i].r & 0b11111100) | (msg[j] >> (6-bitcount));
		bitcount += 2;
		if(bitcount == 8){
			if(!msg[j]){
				break;
			}
			bitcount=0;
			j++;
		}
		pic->img[i].g = (pic->img[i].g & 0b11111100) | (msg[j] >> (6-bitcount));
		bitcount += 2;
		if(bitcount == 8){
			if(!msg[j]){
				break;
			}
			bitcount=0;
			j++;
		}
		pic->img[i].b = (pic->img[i].b & 0b11111100) | (msg[j] >> (6-bitcount));
		bitcount += 2;
		if(bitcount == 8){
			if(!msg[j]){
				break;
			}
			bitcount=0;
			j++;
		}
		i++;
	}
}

/*


    printf("Primeiros 10 pixels da imagem:\n");
    for(int i=0; i<10; i++) {
        printf("[%02X %02X %02X] ", pic.img[i].r, pic.img[i].g, pic.img[i].b);
    }
    printf("\n");
*/
