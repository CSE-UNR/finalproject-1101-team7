
#include <stdio.h>
#define STRINGLENGTH 100
#define MAX_ROWS 500
#define MAX_COLS 500

void scanimage(char FILEIMAGE[], int *rows, int *cols, char imagearray[][MAX_COLS]);//scans image for cols and rows
void displayImage (int rows, int cols, char imagearray[MAX_ROWS][MAX_COLS]);
void crop(int rows, int cols ,char imagearray[][MAX_COLS]);
void SavetoFile(int rows, int cols, char imagearray[MAX_ROWS][MAX_COLS]);
void brighten(int rows, int cols, char imagearray[][MAX_COLS]);
void dim(int rows, int cols, int imagearray[][MAX_COLS]);
void editMenu();


int main(){
//int brighten, dim;
int choice;
int rows = 0, cols = 0;
char FILE_NAME[STRINGLENGTH + 1];
char imagearray[MAX_ROWS][MAX_COLS];

do{
    printf("\nMain Menu\n");
    printf("---------\n");
    printf("1: Load New Image\n2: Display Current Image\n");
    printf("3: Edit Current Image\n4: Exit Program\n");
    printf("What would you like to do: ");
    scanf(" %d", &choice);

        switch (choice) {
    
            case 1: //new image
            
                printf("What is the name of your image? "); 
                scanf("%s", FILE_NAME);
                scanimage(FILE_NAME, &rows, &cols, imagearray);
                
		
		
                break;
                
            case 2: //current image
            
           	displayImage(rows, cols, imagearray);
                break;
                
            case 3: //edit current
            
            	editMenu(&rows, &cols, imagearray);
                break;
                
            case 4: //exit program
            
                printf("Exiting Program . . .");
                break;
                
            default:
            printf("Invalid choice. Try again.\n"); 

        } 

    }while (choice != 4);

return 0;
}

void scanimage(char FILEIMAGE[], int *rows, int *cols, char imagearray[][MAX_COLS]) {
	int i = 0, j = 0;
    FILE *fri;
    fri = fopen(FILEIMAGE, "r");
    if (fri == NULL) {
        printf("Error: unable to open image.\n");
        return;
    } else {
        *cols = 0;
        while (fscanf(fri, "%c", &imagearray[i][j]) == 1) {
        printf("%c \n",imagearray[i][j]);
         	if(imagearray[i][j] == '\n'){
         		if(j > *cols){
         			  *cols = j + 1;
         			  printf("%d j value", j);
         		}
         		j = 0;
         		i++;
         		printf("%d i value \n", i);
         	}else{
         		j++;
         	}
         }
         
         *rows = i;
         fclose(fri);
         }
         printf("dimensions %d x %d \n",*rows, *cols);
        }
         		
//Needs data on the number of columns and rows from the file
//the function below scans the image array in its integer and converts it to the character values to display

void displayImage (int rows, int cols, char imagearray[rows][cols])
{
	printf("this is the row value: %d \n", rows);
	printf("this is the column value: %d \n", cols);
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 22; j++)
		{
			printf("%c", imagearray[i][j]);
		}
		printf("\n");
	}


	printf("%d this is the row value\n", rows);
	printf("%d this is the column value\n", cols);
	for (int i = 0; i < rows; i++) {
        	for (int j = 0; j < cols; j++) {
           		 printf("%c", imagearray[i][j]);
        }
        printf("\n");
    }// for whatever reason when executed the code only reads the first line and tosses the rest of the values. however in the scan function it would display the values correctly
}

//creates a new file to save the new array into.
void SavetoFile(int rows, int cols, char imagearray[MAX_ROWS][MAX_COLS]){
	
	FILE *file = fopen("output_image.txt", "w");
		fprintf(file, "%d %d\n", cols, rows);
		
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				fprintf(file, "%d ", imagearray[i][j]);
			}
			fprintf(file, "\n");
		}
	
	fclose(file);
}


//zooms in on picture
void crop(int rows, int cols ,char imagearray[][MAX_COLS]){
	int startcol, endcol, startrow, endrow;
	char cropedimage[rows +1][cols +1];
	croppedimage = imagearray[rows + 1][cols + 1];
	 croppedimage[0][1] = 1;
	 croppedimage[1][0] = 1;
	 croppedimage[rows +1][0] = rows
	 croppedimage[0][cols + 1] = cols;
	 char image[rows][cols];
	image = imagearray[rows][cols]
	for(int rowi = 0; rowi < rows; rowi++){
	 	for(int coli = 0; coli < cols; coli++){
			switch(image[rowi +1][coli + 1]){
				case 0:
					image[rowi][coli] = ' ';
					break;
				case 1:
					image[rowi][coli] = '.';
					break;
				case 2:
					image[rowi][coli] = 'o';
					break;
				case 3:
					image[rowi][coli] = 'O';
					break;
				case 4:
					image[rowi][coli] = '0';
					break;
				default:
					image[rowi][coli] = '?';
			}
		}
	}
	for(int rowi2 = 0; rowi2 < rows; rowi2++){
	 	for(int2 coli = 0; coli2 < cols; coli2++){
	 		printf("%c", image[rowi2][coli2]);
	 	}
	 	printf("\n");
	 }
	printf("\n");
	printf("the image you want to crop is %d x %d.\n", cols, rows);
	printf("what would you like the starting column to be on the left side?: ");
	scanf(" %d", &startcol);
	printf("what would you like the end column to be?: ");
	scanf(" %d", &endcol);
	printf("what would you like the starting Row?: ");
	scanf(" %d", &startrow);
	printf("what would you like the starting column to be on the left side?: ");
	scanf(" %d", &endrow);
		f
	 

	for(int rowi4 = startrow; rowi4 < endrow; rowi4++){
	 	for(int coli4 = startcol; coli4 < endcol; coli4++){
	 		printf("%c", image[rowi4][coli4]);
	 	}
	 	printf("\n");
	 }
	
	}

void brighten(int rows, int cols, char imagearray[][MAX_COLS]){
	for(int rowi = 0; rowi < rows; rowi++){
		for(int coli = 0; coli < cols; coli++){
	 		imagearray[rowi][coli] +=  1;
	 	}
	}

}

void dim(int rows, int cols, int imagearray[][MAX_COLS]){
	for(int rowi = 0; rowi < rows; rowi++){
		for(int coli = 0; coli < cols; coli++){
	 		imagearray[rowi][coli] -= 1;
	 	}
	}

}

void editMenu(){

	int *rows, *cols, ec;
	int imagearray[MAX_ROWS][MAX_COLS];
	char image_file;
    
    do{
        printf("How would you like to edit your image?\n");
        printf("\nEdit Menu\n");
        printf("---------\n");
        printf("1: Crop Image\n");
        printf("2: Dim Image\n");
        printf("3: Brighten Image\n");
        printf("4: Exit\n");
        scanf(" %d", &ec);
        
            switch (ec){
            
                case 1: //crop
                
                	crop(rows,cols,imagearray);
                	saveimage(rows,cols,imagearray);
                	
                    break;
                
                case 2: //dim
                  	dim(*rows, *cols, imagearray);
                  	displayImage(rows,cols,imagearray);
                  	saveimage(rows,cols,imagearray);
                	
                    break;
                    
                case 3: //bright
                  	brighten(*rows, *cols, imagearray);
                  	displayImage(rows,cols,imagearray);
                  	saveimage(rows,cols,imagearray);
                  	
                	
                    break;
                
                case 4: //exit program
                
                    printf("Exiting Program . . .");
                    break;
                    
                default:
                printf("Invalid choice. Try again.\n"); 
            
                }
    }while (ec != 4);
   
}






