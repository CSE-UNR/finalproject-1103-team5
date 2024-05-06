//MD / Amanda


#include <stdio.h>
#define MAX_SIZE 100
#define space ' '
#define period '.'
#define lower_o 'o'
#define upper_o 'O'
#define zero '0'

void load_image(char image[MAX_SIZE][MAX_SIZE], int *insize);
void display_image(char image[MAX_SIZE][MAX_SIZE], int insize);
void edit_image(char image[MAX_SIZE][MAX_SIZE], int insize);
	void crop_image(char image[MAX_SIZE][MAX_SIZE], int *insize);
	void dim_brighten_image(char image[MAX_SIZE][MAX_SIZE], int insize);
void exit_image(char image[MAX_SIZE][MAX_SIZE], int insize);
void save_image(char image[MAX_SIZE][MAX_SIZE], int insize);

int main(){

int options, options2, insize = 0, image[MAX_SIZE][MAX_SIZE] ;
space = 0;

do {
	printf("***AMANDASGRAM***\n");
	printf("1: Load image\n2: Display image\n3: Edit image\n0: Exit\n");
	scanf("%d ", &options);
	switch(options){
		case 1:
			//load_image(int image[size][size], int *insize);
			break;
		case 2:
			//display_image(int image[size][size], int insize);
			break;
		case 3:
			edit_image(int image[MAX_SIZE][MAX_SIZE], int insize);
			break;
		case 4: 
			//exit_image(int image[size][size], int insize);
			break;
		default: 
			printf("Invalid input.");
			break;
		}
	} while (options != 4);
	return 0;


}
void edit_image(int image[MAX_SIZE][MAX_SIZE], int insize);
	do {
		printf("Choose what change you would like to make:\n1: Crop Image.\n2: Dim or Brighten Image.\n");
		switch (options2){
			case 1: 
				crop_image(int image[MAX_SIZE][MAX_SIZE], int *insize);
				break;
			case 2:
				dim_brighten_image(int image[MAX_SIZE][MAX_SIZE], int insize);
				break;
			default:
				printf("Invalid options.");
				break;
		}
		
	}
void crop_image(int image[MAX_SIZE][MAX_SIZE], int *insize){
	int options3;
	printf("what size do you want the image to be?");
	scanf("%d", &options3);
	switch (options3){
		case 1:
			for(i = 0; i < size; i++)
	}
}