//MD / Amanda


#include <stdio.h>
#define MAX_SIZE 100
#define MAX_Pixel 5
const char pixels[] = (' ', '.', 'o', 'O', '0');

void load_image(char *filename, int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void display_image(int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols);
void edit_image(int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
	void crop_image(int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
	void dim_brighten_image(int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols, int newpixel);
void exit_image(int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols);
void save_image(char *filename, const int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main(){

int options, rows = 0, cols = 0, global_Array[[MAX_SIZE][MAX_SIZE] = {0};

do {
	printf("***AMANDASGRAM***\n");
	printf("1: Load image\n2: Display image\n3: Edit image\n0: Exit\n");
	scanf("%d ", &options);
	switch(options){
		case 1:
			printf("Enter the file name: ");
                scanf("%s", filename);
                loadImage(filename, global_Array, &rows, &cols);
                break;
		case 2:
			display_image(global_Array[[MAX_SIZE][MAX_SIZE], rows, cols);
			break;
		case 3:
			edit_image(global_Array[[MAX_SIZE][MAX_SIZE], &rows, &cols);
			break;
		case 0: 
			exit_image(global_Array[[MAX_SIZE][MAX_SIZE], rows, cols);
			break;
		default: 
			printf("Invalid input.");
			break;
		}
	} while (options != 4);
	return 0;


}
void loadImage(char *filename, int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error, unable to upload file %s\n", filename);
        return;
    }

    fscanf(file, "%d %d", rows, cols);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }

    fclose(file);
    printf("Image uploaded sucessfully.\n");
}
void edit_image(int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols){
	int eOptions2;
	printf("***AMANDASGRAM***\nEdit:\nChoose what changes you would like to make:\n1: Crop Image.\n2: Brighten Image.\n3: Dim Image.\n");
	scanf("%d ", eOptions2);
	switch (eOptions2){
		case 1: 
			crop_image(global_Array[MAX_SIZE][MAX_SIZE], rows, cols);
			break;
		case 2:
			dim_brighten_image(global_Array[MAX_SIZE][MAX_SIZE], *rows, *cols, 1);
			break;
		case 3:
			dim_brighten_image(global_Array[MAX_SIZE][MAX_SIZE], *rows, *cols, -1);
			break;
		default:
			printf("Invalid options.");
			break;
		}
	char save_changes;
    printf("Would you like to save the edited image? (y/n): ");
    scanf(" %c", &saveChoice);

    if (saveChoice == 'y') {
        char filename[100];
        printf("Enter the filename to save the image: ");
        scanf("%s", filename);
        saveImage(filename, image, *rows, *cols);
    }
}
void crop_image(int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols){
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
    int crop[MAX_SIZE][MAX_SIZE] = {0};

    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            crop[i][j] = global_Array[top + i][left + j];
        }
    }

    *rows = new_rows;
    *cols = new_cols;

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            global_Array[i][j] = crop[i][j];
        }
    }
    printf("Image has been Cropped.\n");
	
}
void dim_brighten_image(int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols, int newpixel) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            global_Array[i][j] = (global_Array[i][j] + newpixel + pixels) % pixels;
        }
    }

    printf("New Brightness has been set.\n");
}
void save_image(char *filename, const int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error uploading file: %s\n", filename);
        return;
    }

    fprintf(file, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Image saved in %s.\n", filename);
}
void exit_image(){
printf("Goodbye!\n");
return 0;
}