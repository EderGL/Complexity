#ifndef Files_H
#define Files_H

#include <stdio.h>

typedef enum{
    MEM_ERROR,//0
    ERROR_OK,
    FILENAME_ERROR,
    FILE_NOT_FOUND, //3
    FEOF
}ERROR_CODE;


FILE* newFile(char *fileName, char *mode);

FILE* closeFile(FILE *file);

ERROR_CODE printHeaders(FILE* file, const int columns, char *data[]);

ERROR_CODE csvFileWrite(FILE* file, const int columns, const int rows, long long data[][columns], double tiempoRecursive[], double tiempoSequential[]);




#endif
