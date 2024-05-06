//MD / Amanda


#include <stdio.h>
#define size 100
#define space ' '
#define period '.'
#define lower_o 'o'
#define upper_o 'O'
#define zero '0'

void load_image(int image[size][size], int *insize);
void display_image(int image[size][size], int insize);
void edit_image(int image[size][size], int insize);
	void crop_image(int image[size][size], int *insize);
	void dim_brighten_image(int image[size][size], int insize);
void exit_image(int image[size][size], int insize);
void save_image(int image[size][size], int insize);

int main(){

int options, options2, insize = 0, image[size][size] ;
space = 0;

do {
	printf("***AMANDASGRAM***\n");
	printf("1: Load image\n2: Display image\n3: Edit image\n0: Exit\n");
	scanf("%d ", &options);
	switch(options){
		case 1:
			load_image(int image[size][size], int *insize);
			break;
		case 2:
			display_image(int image[size][size], int insize);
			break;
		case 3:
			edit_image(int image[size][size], int insize);
			break;
		case 4: 
			exit_image(int image[size][size], int insize);
			break;
		default: 
			printf("Invalid input.");
			break;
		}
	} while (options != 4);
	return 0;


}
void edit_image(int image[size][size], int insize);
	do {
		printf("Choose what change you would like to make:\n1: Crop Image.\n2: Dim or Brighten Image.\n");
		switch (options2){
			case 1: 
				crop_image(int image[size][size], int *insize);
				break;
			case 2:
				dim_brighten_image(int image[size][size], int insize);
				break;
			default:
				printf("Invalid options.");
				break;
		}
		
	}
void crop_image(int image[size][size], int *size){
	int options3;
	printf("what size do you want the image to be?");
	scanf("%d", &options3);
}