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

int options, insize = 0, image[size][size] ;

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
