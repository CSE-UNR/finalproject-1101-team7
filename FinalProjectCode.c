//author: Alex Robinson && Sasha Mason-Sanchez
//date: 5/3/2024
//Purpose: Final Project
//main code starts on 216

// void names: scanimage, editMenu, SavetoFile, displayImage, crop, brighten, dim

#include <stdio.h>
#define STRINGLENGTH 100

void scanimage(char *image_file, int *width, int *height){//scans image for height and width

	FILE *file = fopen(image_file, "r");
	if(file == NULL){
		printf("Error: unable to open image.\n");
		return;
	}

	int file_width = 0;
	int file_height = 0;
	char image;
	
	while((image = fgetc(file)) != EOF){
		if(image == '\n'){
			file_height ++;
			
			if (file_width > *width){
				*width = file_width;
			}
			
			file_width = 0;
				
		} else if(image != ' ' && image != '.' && image != 'o' && image != 'O' && image != '0'){	
			printf("Error! invalage character detected in image. \n");
			*width = 0;
			*height = 0;
			fclose(file);
			return;
		
		} else {
			file_width++;
		}
	}
	
	if (file_width > 0){
		file_height++;
	}
	
	*width = file_width;
	*height = file_height;
	fclose(file);
}





//creates a new file to save the new array into.
void SavetoFile(int rows, int cols, int imagearray[][cols]){
	char choice;
	char name[STRINGLENGTH];
	int rowi, coli;
	
	do{
		printf("would you like to save this image?(y/n): ");
		scanf(" %c", &choice);
		switch(choice){
			case 'y':
			case 'Y':
				printf("What would you like the file name be?\n");
				printf("enter here: ");
				fgets(name, STRINGLENGTH, stdin);
				FILE *fpr;
				fpr = fopen(name, "w");
				for(int rowi = 0; rowi < rows; rowi++){
	 				for(int coli = 0; coli < cols; coli++){
	 					fprintf(fpr, "%d", imagearray[rowi][coli]);
	 				}
	 				fprintf(fpr, "%d", imagearray[rowi][coli]);
	 			}
				fclose(fpr);
				break;
			
			case 'n':
			case 'N':
				printf("Not saving the image...\n");
				break;
			
			default:
				printf("Invalid choice. Try again.\n");
		}
	} while(choice != 'n' || choice != 'N');
}

//Needs data on the number of columns and rows from the file
//the function below scans the image array in its integer and converts it to the character values to display
void displayImage (int rows, int cols, int imagearray[][cols]){
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
void crop(int rows, int cols ,int imagearray[][cols], int startcol, int endcol, int startrow, int endrow){

//int image[rows][cols];
	
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
/*
void crop(int rows, int cols ,int imagearray[][cols], int startcol, int endcol, int startrow, int endrow){
	
	printf("the image you want to crop is %d x %d.\n", endrow - startrow +1, endcol - startcol + 1);

	for(int rowi = startrow; rowi <= endrow; rowi++){
	 	for(int coli = startcol; coli <= endcol; coli++){
	 		print("%c", image[rowi][coli]);
	 	}
	 	printf("\n");
	 }
}
*/
int brighten(int rows, int cols, int imagearray[][cols]){
	for(int rowi = 0; rowi < rows; rowi++){
		for(int coli = 0; coli < cols; coli++){
	 		imagearray[rowi][coli] = imagearray[rowi][coli] + 1;
	 	}
	}
	return imagearray[rows][cols];
}
int dim(int rows, int cols, int imagearray[][cols]){
	for(int rowi = 0; rowi < rows; rowi++){
		for(int coli = 0; coli < cols; coli++){
	 		imagearray[rowi][coli] = imagearray[rowi][coli] - 1;
	 	}
	}
	return imagearray[rows][cols];
}

void editMenu(){

	int width, height, ec;
	int rows, cols;
	int imagearray[rows][cols];
	char image_file;

	
    //scanimage(char image_file, int width, int height);
    
    do{
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
                  imagearray[rows][cols] = dim(rows, cols, imagearray);
                	//displayImage ( rows,  cols,  imagearray[rows][cols]);
                	//SavetoFile( rows, cols, imagearray[rows][cols]);
                    break;
                    
                case 3: //bright
                  imagearray[rows][cols] = brighten(rows, cols, imagearray);
                	//displayImage ( rows, cols, imagearray[rows][cols]);
                	//SavetoFile(rows, cols, imagearray[rows][cols]);
                    break;
                
                case 4: //exit program
                
                    printf("Exiting Program . . .");
                    break;
                    
                default:
                printf("Invalid choice. Try again.\n"); 
            
                }
    }while (ec != 4);
    
}
int main(){

int brighten, dim;
int choice, ec;
int width = 0, height = 0;
char FILE_NAME[STRINGLENGTH];
int cols, rows;
int imagearray;
int image_file;

do{
    printf("\nMain Menu\n");
    printf("---------\n");
    printf("1: Load New Image\n2: Display Current Image\n");
    printf("3: Edit Current Image\n4: Exit Program\n");
    printf("\nWhat would you like to do: ");
    scanf(" %d", &choice);

        switch (choice) {
    
            case 1: //new image
                printf("What is the name of your image?");
                scanf("%s",FILE_NAME);
            	FILE *fpr;
		fpr = fopen(FILE_NAME, "r");
            	if(fpr == NULL){
			printf("cannot open\n");
		}else{
		scanimage(FILE_NAME, &width, &height);
                }
                break;
                
            case 2: //current image
            	
            
                break;
                
            case 3: //edit current
            
              editMenu(ec);
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




