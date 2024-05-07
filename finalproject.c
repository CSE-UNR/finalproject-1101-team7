
#include <stdio.h>
#define STRINGLENGTH 100
#define MAX_ROWS 500
#define MAX_COLS 500
int imagearray[MAX_ROWS][MAX_COLS];

void scanimage(char image_file[STRINGLENGTH], int rows, int cols, int imagearray[MAX_ROWS][MAX_COLS]){//scans image for cols and rows
	int i = 0, j = 0;
	char endline;
	FILE *fri;
	fri = fopen(image_file, "r");
	if(fri == NULL){
		printf("Error: unable to open image.\n");
		return;
	}else{
		while(fscanf(fri, "%c", &endline) == 1){
			j++;
			if(endline == '\n'){
			i++;
			j = 0;
			}
			rows = i + 1;
			cols = j + 1;
		}
		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				fscanf(fri, "%d", &imagearray[i][j]);
			}
		}
		for(i = 0; i < rows; i++){
			for(j = 0; j < cols; j++){
				printf("%d", imagearray[i][j]);
			}
		}
			
	}
		fclose(fri);
}
/*
//creates a new file to save the new array into.
void SavetoFile(int rows, int cols, int imagearray[MAX_ROWS][MAX_COLS]){
	
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

//Needs data on the number of columns and rows from the file
//the function below scans the image array in its integer and converts it to the character values to display
void displayImage (int rows, int cols, int imagearray[MAX_ROWS][MAX_COLS]){
	char image[rows][cols];
	for(int rowi = 0; rowi < rows; rowi++){
	 	for(int coli = 0; coli < cols; coli++){
			switch(imagearray[rowi][coli]){
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
	for(int rowi = 0; rowi < rows; rowi++){
	 	for(int coli = 0; coli < cols; coli++){
	 		printf("%c", image[rowi][coli]);
	 	}
	 	printf("\n");
	 }
}

//zooms in on picture
void crop(int rows, int cols ,int imagearray[][MAX_COLS], int startcol, int endcol, int startrow, int endrow){

	
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
	 
char image[rows][cols];
	for(int rowi = 0; rowi < rows; rowi++){
	 	for(int coli = 0; coli < cols; coli++){
			switch(imagearray[rowi][coli]){
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
	for(int rowi = 0; rowi < rows; rowi++){
	 	for(int coli = 0; coli < cols; coli++){
	 		printf("%c", image[rowi][coli]);
	 	}
	 	printf("\n");
	 }
	
	}

int brighten(int rows, int cols, int imagearray[][MAX_COLS]){
	for(int rowi = 0; rowi < rows; rowi++){
		for(int coli = 0; coli < cols; coli++){
	 		imagearray[rowi][coli] +=  1;
	 	}
	}

}

int dim(int rows, int cols, int imagearray[][MAX_COLS]){
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
        printf("4: Save and Exit\n");
        scanf(" %d", &ec);
        
            switch (ec){
            
                case 1: //crop
                
                
                    break;
                
                case 2: //dim
                  	dim(*rows, *cols, imagearray);
                	
                    break;
                    
                case 3: //bright
                  	brighten(*rows, *cols, imagearray);
                	
                    break;
                
                case 4: //exit program
                
                    printf("Exiting Program . . .");
                    break;
                    
                default:
                printf("Invalid choice. Try again.\n"); 
            
                }
    }while (ec != 4);
   
}
*/
int main(){

//int brighten, dim;
int choice;
int rows = 0, cols = 0;
char FILE_NAME[STRINGLENGTH];
int imagearray[MAX_ROWS][MAX_COLS];

do{
    printf("\nMain Menu\n");
    printf("---------\n");
    printf("1: Load New Image\n2: Display Current Image\n");
    printf("3: Edit Current Image\n4: Exit Program\n");
    printf("\nWhat would you like to do: ");
    scanf(" %d", &choice);

        switch (choice) {
    
            case 1: //new image
            
                printf("What is the name of your image? "); 
                scanf(" %s", &FILE_NAME[STRINGLENGTH + 1]);
                scanimage(FILE_NAME, rows, cols, imagearray);
                
		
		
                break;
                
            case 2: //current image
            
           // displayImage(rows, cols, imagearray);
                break;
                
            case 3: //edit current
            
            //	editMenu(&rows, &cols, imagearray);
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




