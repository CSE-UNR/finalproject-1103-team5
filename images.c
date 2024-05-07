//MD / Amanda
//05/07/2024
//Images (Final Project)
//1103-team-5


#include <stdio.h>

#define MAX_SIZE 100
#define MAX_Pixel 5

const char pixels[] = {' ', '.', 'o', 'O', '0'};


//functions
void load_image(char *filename, int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void display_image(const int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols);
void edit_image(int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void crop_image(int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols);
void dim_brighten_image(int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols, int newpixel);
void exit_image(int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols);
void save_image(char *filename, const int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols);
void clear_image();

int numRows = 0;
int numCols = 0;
int imageLoaded = 0;
int global_Array[MAX_SIZE][MAX_SIZE] = {0};

int main(){

int options;
int rows = 0;
int cols = 0;
char filename[100];

do {
printf("***AMANDASGRAM***\n1: Load image\n2: Display image\n3: Edit image\n0: Exit\n");
scanf("%d", &options);
switch(options){
case 1:
printf("Enter the file name: \n");
                scanf("%s", filename);
                load_image(filename, global_Array, &rows, &cols);
                break;
case 2:
display_image(global_Array, rows, cols);
break;

case 3:
edit_image(global_Array, &rows, &cols);
break;
case 0:
exit_image(global_Array, rows, cols);
break;

default:
printf("Invalid input.");
break;
}
} while (options != 0);
return 0;


}



void load_image(char *filename, int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error. Unable to upload file: %s\n", filename);
        return;
    }
    int numColsTemp = 0;
    int numRowsTemp = 0;
   
   int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            numRows++;
     
            if (numCols == 0) {
                numCols = numColsTemp;
            }

       
            numColsTemp = 0;
        } else {
 
            if (c >= '0' && c <= '9') {
                global_Array[numRows][numColsTemp++] = c - '0';
            }
        }
    }

    if (numColsTemp > 0) {
        numRows++;
    }
    if(imageLoaded){
    clear_image();
    }

    fclose(file);
}

void clear_image() {
   
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            global_Array[i][j] = 0;
        }
    }
    numRows = 0;
    numCols = 0;
    imageLoaded = 0;
}

void display_image(const int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols){

printf("Displaying current image: \n\n");
for(int i = 0; i < numRows; i++){
    for(int j = 0; j < numCols; j++){
   
    if (global_Array[i][j] == 0) { //Low Brightness
    printf(" ");
    }
    if (global_Array[i][j] == 1) {
    printf(".");
    }
    if (global_Array[i][j] == 2) {
    printf("o");
    }
    if (global_Array[i][j] == 3) {
    printf("O");
    }
    if (global_Array[i][j] == 4) {
    printf("0");
    }
    if (global_Array[i][j] == 6) { //High Brightness
    printf(".");
    }
    else if (global_Array[i][j] >= 5 || global_Array[i][j] <= -1 ) {
    printf("%d ", global_Array[i][j]);
    }
   
       
    }
    printf("\n");
    }
 
}


void edit_image(int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols){
int eOptions;
printf("***AMANDASGRAM***\n");
printf("Edit:\n");
printf("Choose what changes you would like to make:\n");
printf("1: Crop Image.\n");
printf("2: Brighten Image.\n");
printf("3: Dim Image.\n");
scanf("%d", &eOptions);


if (eOptions == 1){
crop_image(global_Array, rows, cols);
}
else if (eOptions == 2){
dim_brighten_image(global_Array, *rows, *cols, 1);
}
else if (eOptions == 3){
dim_brighten_image(global_Array, *rows, *cols, -1);
}else{
printf("Invalid options.");
return;
}


char save_changes;
    printf("Would you like to save the edited image? (y/n): ");
    scanf(" %c", &save_changes);

    if (save_changes == 'y') {
        char filename[100];
        printf("Enter the filename to save the image: ");
        scanf("%s", filename);
        save_image(filename, global_Array, *rows, *cols);
        clear_image();
    }
}
void crop_image(int global_Array[MAX_SIZE][MAX_SIZE], int *rows, int *cols){
int left, right, top, bottom;
printf("First left column (1-21): ");
    scanf("%d", &left);
    printf("Last right column(1-21): ");
    scanf("%d", &right);
    printf("Top row(1-12): ");
    scanf("%d", &top);
    printf("Bottom row(1-12): ");
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
            global_Array[i][j] = (global_Array[i][j] + newpixel + MAX_Pixel) % MAX_Pixel;
        }
    }

    printf("New Brightness has been set.\n");
}

void exit_image(int global_Array[MAX_SIZE][MAX_SIZE], int rows, int cols){
printf("Goodbye!\n");
}

void save_image(char *filename, const int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error uploading file: %s\n", filename);
        return;
    }

    fprintf(file, "%d%d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", image[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Image saved in %s.\n", filename);
}
