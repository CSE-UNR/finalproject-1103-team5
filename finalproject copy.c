//MD / Amanda


#include <stdio.h>
#define MAX_SIZE 100
#define MAX_Pixel 5
const char pixels[] = (' ', '.', 'o', 'O', '0');

void load_image(char *filename, int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void display_image(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);
void edit_image(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
	void crop_image(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
	void dim_brighten_image(int image[MAX_SIZE][MAX_SIZE], int rows, int cols, int newpixel);
void exit_image(int image[MAX_SIZE][MAX_SIZE], int rows, int cols);
void save_image(char *filename, int image[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main(){

int options, rows = 0, cols = 0, image[MAX_SIZE][MAX_SIZE] = {0};

do {
	printf("***AMANDASGRAM***\n");
	printf("1: Load image\n2: Display image\n3: Edit image\n0: Exit\n");
	scanf("%d ", &options);
	switch(options){
		case 1:
			load_image(image[MAX_SIZE][MAX_SIZE], &rows, &cols);
			break;
		case 2:
			display_image(image[MAX_SIZE][MAX_SIZE], rows, cols);
			break;
		case 3:
			edit_image(int image[MAX_SIZE][MAX_SIZE], &rows, &cols);
			break;
		case 0: 
			exit_image(int image[MAX_SIZE][MAX_SIZE], rows, cols);
			break;
		default: 
			printf("Invalid input.");
			break;
		}
	} while (options != 4);
	return 0;


}
void edit_image(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols);{
	int eOptions;
	printf("***AMANDASGRAM***\nEdit:\nChoose what changes you would like to make:\n1: Crop Image.\n2: Brighten Image.\n3: Dim Image.\n");
	scanf("%d ", eOptions2);
	switch (eOptions2){
		case 1: 
			crop_image(image[MAX_SIZE][MAX_SIZE], rows, cols,);
			break;
		case 2:
			dim_brighten_image(image[MAX_SIZE][MAX_SIZE], *rows, *cols, 1);
			break;
		case 3:
			dim_brighten_image(image[MAX_SIZE][MAX_SIZE], *rows, *cols, -1);
			break;
		default:
			printf("Invalid options.");
			break;
		}
}
void crop_image(int image[MAX_SIZE][MAX_SIZE], int *rows, int *cols){
	int left, right, top, bottom;
	printf("First left column: ");
    scanf("%d", &left);
    printf("Last right column: ");
    scanf("%d", &right);
    printf("Top row:: ");
    scanf("%d", &top);
    printf("Bottom row: ");
    scanf("%d", &bottom);
	int new_rows = bottom - top + 1;
    int new_cols = right - left + 1;
    //int cropped[MAX_SIZE][MAX_SIZE] = {0};

    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            crop[i][j] = image[top + i][left + j];
        }
    }

    *rows = new_rows;
    *cols = new_cols;

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            image[i][j] = crop[i][j];
        }
    }
    printf("Image has been Cropped.\n");
	
}
void dim_brighten_image(int image[MAX_SIZE][MAX_SIZE], int rows, int cols, int newpixel) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] = (image[i][j] + newpixel + pixels) % pixels;
        }
    }

    printf("New Brightness has been set.\n");
}
