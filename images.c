//Authors: Amanda DeBurle, MD Islam
#include <stdio.h>
#define ROWS 5
#define COLS 5
#define size 100
#define space ' '
#define period '.'
#define lower_o 'o'
#define upper_o 'O'
#define zero '0'

void load_image();
void display_image();
void edit_image();
void crop_image();
void dim_brighten_image();
void exit_image();
void save_image();

char image[ROWS][COLS];
char fileName;
int main(){

int option;
int choice;
int fileName, width, height;
do{
printf("\n***AMANDASGRAM***\n");
printf(" 1: Load image\n 2: Display image\n 3: Edit image\n 0: Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch(choice){
case 1:
	
    load_image(fileName, width, height);
break;

case 2:
void display_image();
break;

case 3:
void edit_image();
break;

case 0:
printf("Exiting program\n");
break;
}
}while(choice != 0);
}

void load_image(){
	printf("Whats the name of the image file?: ");
   	scanf("%s", &fileName);
FILE *fptr = fopen(fileName, "r");
if(fptr == NULL){
printf("Error: File not found!\n");
return;
}
else{
printf("Image loaded successfully!\n");
}
fclose(fptr);
}
void display_image(){
printf("Displaying current image: \n");
for(int i = 0; i < ROWS; i++){
for(int j = 0; j < COLS; j++){
printf("%c", image[i][j]);
}
printf("\n");
}
}

