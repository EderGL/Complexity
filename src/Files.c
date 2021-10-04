#include <stdio.h>
#include <stdlib.h>

#include "../lib/Files.h"

#define EXISTS "r"

static ERROR_CODE readLine(FILE *file, char *buffer, size_t bufsize){
    fgets(buffer, bufsize,file);
    if(fgets(buffer, bufsize,file))return FEOF;
    return EXIT_SUCCESS;
}

static ERROR_CODE readCSVLine(FILE *file, long long *buffer, size_t bufsize){

}

static long long tokeniseLine(long long *buffer, size_t bufsize, char *tok ){


}

static ERROR_CODE fileFound(FILE *file){

    if(file==NULL){
        fprintf(stderr,"FILE NOT FOUND ERROR %d  IN FILE: %s: LINE: %d\n", FILE_NOT_FOUND, __FILE__, __LINE__);
        return FILE_NOT_FOUND;
    }
    return ERROR_OK;
}


FILE* newFile(char* fileName, char *mode){

    FILE* myFile = NULL;

    myFile = fopen(fileName, mode);
    fprintf(stderr, "%p\n",myFile);
    if(fileFound(myFile)==FILE_NOT_FOUND){
        fputs("File not Found\n",stderr);
    }
    return myFile;
}


FILE* closeFile(FILE *file){
    fclose(file); // free
    file=NULL;
    return file;
}


ERROR_CODE csvFileWrite(FILE* file, const int columns, const int rows, long long data[][columns], double tiempoRecursive[], double tiempoSequential[]){
  int columnIndex = 0;
  for(int rowIndex=0; rowIndex<rows; rowIndex++){
    fprintf(file,"%f, ",tiempoRecursive[rowIndex]);
    fprintf(file,"%f, ",tiempoSequential[rowIndex]);
      for(columnIndex=0; columnIndex<(columns-1); columnIndex++){
          fprintf(file, "%lld, ", data[rowIndex][columnIndex]);
      }
      fprintf(file, "%lld\n", data[rowIndex][columnIndex]);
  }
  return ERROR_OK;
}

ERROR_CODE printHeaders(FILE* file, const int columns, char *data[]){
    int columnName=0;
    puts("headers");
    for(columnName=0; columnName<(columns-1); columnName++)
    fprintf(file, "%d %s, ", columnName, data[columnName]);
    fprintf(file, "%d %s\n", columnName, data[columnName]);

    return ERROR_OK;
}

ERROR_CODE readLongCSV(FILE *file, int rows, int columns, long long *data[columns]){
    long long *buffer = NULL;
    buffer = calloc(BUFSIZ, sizeof(long long));
    for(int row=0; row<rows; row++){

    }
}
