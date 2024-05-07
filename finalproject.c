#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRINGLENGTH 100
#define MAX 1000


void scan_image(const char *file_path, int *rows, int *cols, int **chars){//scans image for cols and rows

	FILE *file = fopen(file_path, "r");
	
	if(file == NULL){
		printf("Error: unable to open image.\n");
		return;
	}
	
	*rows = 0;
	*cols = 0;
	char buffer[MAX];
	
		while(fgets(buffer, sizeof(buffer), file) != NULL){
			(rows)++;
			int len = strlen(buffer) - 1;
			if(len > *cols){
				*cols = len;
			}
		}
		
		fclose(file);
}

//creates a new file to save the new array into.
void SavetoFile(int rows, int cols, int imagearray[MAX][MAX]){
	
	FILE *file = fopen("output_image.txt", "w");
	
	if(file == NULL){
		printf("Error: unable to open image.\n");
		return;
	}
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
void displayImage (const char *file_path){
	
	FILE *file = fopen(file_path, "r");
	
	if(file == NULL){
		printf("Error: Cannot open file");
		return;
	}
	
	char buffer[MAX];
	
	while (fgets(buffer, sizeof(buffer), file) != NULL){
		printf("%s", buffer);
	}
	
	fclose(file);
}

//zooms in on picture
/*void crop(int rows, int cols ,int imagearray[][MAX_COLS], int startcol, int endcol, int startrow, int endrow){

	
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
int choice, *chars;
int rows, cols;
char file_name[MAX];
int imagearray[MAX][MAX];

do{
    printf("\nMain Menu\n");
    printf("---------\n");
    printf("1: Load New Image\n2: Display Current Image\n");
    printf("3: Edit Current Image\n4: Exit Program\n");
    printf("\nWhat would you like to do: ");
    scanf(" %d", &choice);

        switch (choice) {
    
            case 1: //new image
            
                printf("Enter the file name you would like to open: "); 
                scanf(" %s", file_name);
                scan_image(file_name, &rows, &cols, &chars);
                
                printf("File Specs\n");
                printf("----------\n2");
                printf("Rows: %d\n", rows);
    		printf("Columns: %d\n", cols);
                
		
		
                break;
                
            case 2: //current image
            	printf("\n");
		displayImage(file_name);
		free(chars);
		printf("\n");
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


