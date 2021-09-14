#include "storage_mgr.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void initStorageManager (void){

}

RC createPageFile (char *fileName){

    FILE *fileAux;
    //Open the file in writing mode
    //Also indicating that it is a binary file
    fileAux = fopen(fileName, "wb");

    //Checking that the file exists
    if (fileAux == NULL){
        printf("File opening file: %s", fileName);
        return RC_FILE_NOT_FOUND
    } else{
        //Comment
        fseek(fileAux, PAGE_SIZE, SEEK_SET);
        fputc('\0', fileAux);

        //Need to close the file after writing on it
        fclose(fileAux);

        //Return the ReturnCode that everything is ok
        return RC_OK
    }
}
