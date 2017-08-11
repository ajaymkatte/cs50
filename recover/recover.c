/**
 * Recovers JPEGS from a corrupted file, because it's worth it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// define BYTE
typedef uint8_t  BYTE;

// define JPEGS structure
typedef struct{
    BYTE pixels;
}JPEGS;

// define the size
#define size 512

// main starts from here
int main (int argc, char *argv[])
{
    
    // check if the command-line-argument is not equal to 2
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename.\n");
        return 1;
    }
    char *image = argv[1];
    
    // open the raw file and check if it's in fact in the repository
    FILE *input = fopen(image, "r");
    if(input == NULL)
    {
        fprintf(stderr, "%s couldn't be opened.\n", image);
        return 2;
    }
    
    // temporary variable to access .raw file
    JPEGS buffer[size];
    
    // temporary storage to keep track of the number of jpegs found
    int filenum = 000;
    char *filename = malloc(sizeof(char *));
    
    // read a fresh batch of BYTES
    int x = fread(&buffer, size, 1, input);
    do
    {
        
        if( buffer[0].pixels == 0xff &&
            buffer[1].pixels == 0xd8 &&
            buffer[2].pixels == 0xff &&
            (buffer[3].pixels & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", filenum);
            FILE *img = fopen(filename, "w");
            do{
                
                //write 
                fwrite(&buffer, size, 1, img);
                
                // checks size read
                x = fread(&buffer, size, 1, input);
                
                // checks if hit the end of the file
                if(x < 1)
                    break;
            }
            while(buffer[0].pixels != 0xff ||
            buffer[1].pixels != 0xd8 ||
            buffer[2].pixels != 0xff ||
            (buffer[3].pixels & 0xf0) != 0xe0);
            
            // close the open image file
            fclose(img);
            
            // increment the filenumber
            ++filenum;
        }
        else
        {
            x = fread(&buffer, size, 1, input);
            
            // checks if hit the end of the file
            if(x < 1)
                break;
        }
    }while(x == 1);
    
    // free filename
    free(filename);
    
    // close the raw file
    fclose(input);
    
    // that's it folks
    return 0;
}