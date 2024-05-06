//author: Alex Robinson && Sasha Mason-Sanchez
//date: 5/3/2024
//Purpose: Final Project

#include <stdio.h>
#define STRINGLENGTH 100

int main(){
int brightness, dimness;
int choice, ec;
int width, height;
char FILE_NAME[STRINGLENGTH];
int cols, rows;
int imagearray;

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
                scanf("%c",FILE_NAME);
            	FILE *fpr;
		fpr = fopen(FILE_NAME, "r");
            	if(fpr == NULL){
			printf("cannot open\n");
		}
		else{
		scanimage(&rows, &cols, &imagearray[][cols], FILE_NAME);
                break;
                
            case 2: //current image
            	
            
                break;
                
            case 3: //edit current
            
 //               editMenu(ec);
                break;
                
            case 4: //exit program
            
                printf("Exiting Program . . .");
                break;
            default:
            printf("Invalid choice. Try again.\n"); 

        } 

    }

}while (choice != 4);

return 0;

}

void scanimage (int *cols,int *rows, int *imagearray[][cols], char FILE_NAME){//scans file for the image and the number of cols and rows

    FILE *file = fopen(FILE_NAME, "r");
	if(FILE_NAME == NULL){
        	printf("Error: unable to open image.\n");
	}else{
		for(int rowi = 0; rowi >= 0; rowi++){
			for(int coli = 0; coli >= 0; coli++){
	 			fscanf(file,"%d", imagearray[rowi][coli]);
	 			if(imagearray[coli] == ' '){
	 				rowi++;
	 			}
	 			if(imagearray[rowi][coli] == ' '){
	 				int rows = rowi;
	 				int cols = coli;
	 			}
	 		}
		}
	}
}
/*
void editMenu(int ec){

    scan(width, height, image_file);
    
    do{
        printf("\nEdit Menu\n");
        printf("---------\n");
        printf("1: Crop Image\n");
        printf("2: Dim Image\n");
        printf("3: Brighten Image\n");
        printf("4: Save and Exit\n");
        scanf("%d", &ec);
        
            switch (ec){
            
                case 1: //crop
                
                
                    break;
                
                case 2: //dim
                    dim();
                
                    break;
                    
                case 3: //bright
                    brighten();
                
                    break;
                
                case 4: //exit program
                
                    printf("Exiting Program . . .");
                    break;
                    
                default:
                printf("Invalid choice. Try again.\n"); 
            
                }
    }while (ec != 4);
    
}

//creates a new file to save the new array into.
void SavetoFile(int imagearray[int rows][int cols]){
	char choice
	
	do{
		printf("would you like to save this image?(y/n): ")
		scanf(" %c", choice);
		switch(choice){
			case 'y':
				printf("What would you like the file name be?\n");
				printf("enter here: ");
				fgets(name, STRINGLENGTH, stdin);
				FILE *fpr;
				fpr = fopen(name, "w");
				for(int rowi = 0; rowi < rows; rowi++){
	 				for(int coli = 0; coli < cols; coli++){
	 					fprintf(fpr, "%d", imagearray[rowi][coli]);
	 				}
	 			}
				fclose(fpr);
			break;
			
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
	 			}
				fclose(fpr);
			
			case 'n':
				printf("\n");
				break;
			
			case 'N':
				printf("\n");
				break;
		
	}while(choice != 'n' || choice != 'N');
	}





//Needs data on the number of columns and rows from the file
//the function below scans the image array in its integer and converts it to the character values to display
char displayImage (int rows, int cols, int imagearray[][cols]){
	char image;
	for(int rowi = 0; rowi < rows; rowi++){
	 	for(int coli = 0; coli < cols; coli++){
			switch(imagearray[rowi][coli]){
				case 0:
					image[rowi][coli] = " ";
				case 1:
					image[rowi][coli] = ".";
				case 2:
					image[rowi][coli] = "o";
				case 3:
					image[rowi][coli] = "O";
				case 4:
					image[rowi][coli] = "0";
			}
		}
	}
	for(int rowi = 0; rowi < rows; rowi++){
	 	for(int coli = 0; coli < cols; coli++){
	 		print("%c", image[rowi][coli]);
	 	}
	 }
	return 0;

//zooms in on picture
void crop(int rows, int cols ,int imagearray[][cols]){
	int startcol, endcol, startrow, endrow;
	displayImage(rows, cols, imagearray[][cols]);
	printf("\n");
	printf("the image you want to crop is %d x %d.\n");
	printf("what would you like the starting column to be on the left side?: ");
	scanf(" %d", &startcol)
	printf("what would you like the end column to be?: ");
	scanf(" %d", &endcol)
	printf("what would you like the starting Row?: ");
	scanf(" %d", &startrow)
	printf("what would you like the starting column to be on the left side?: ");
	scanf(" %d", &endrow)
	for(int rowi = startrow; rowi <= endrow; rowi++){
	 	for(int coli = startcol; coli <= endcol; coli++){
	 		print("%c", image[rowi][coli]);
	 	}
	 }

void brighten(int rows, int cols, int imagearray[][cols]){
	for(int rowi = 0; rowi < rows; rowi++){
		for(int coli = 0; coli < cols; coli++){
	 		imagearray[rowi][coli] = imagearray[rowi][coli] + 1;
	 	}
	}
}

void dim(int rows, int cols, int imagearray[][cols]){
	for(int rowi = 0; rowi < rows; rowi++){
		for(int coli = 0; coli < cols; coli++){
	 		imagearray[rowi][coli] = imagearray[rowi][coli] - 1;
	 	}
	}
}
*/
