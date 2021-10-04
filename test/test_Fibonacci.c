#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/Fibonacci.h"
#include "../lib/Files.h"



#define FILENAME "data.db"
#define COLUMNS 3
#define ROWS 30

int main(void){

      FILE* myFile = NULL;
      long long data[ROWS][COLUMNS]={0};
      char* titles[] = {"Recursive Time\0", "Sequential Time\0", "Index\0", "Recursive\0", "Sequential\0" };
      clock_t beginRecursive, endRecursive, beginSequential, endSequential;
      double tiempoRecursive[ROWS], tiempoSequential[ROWS];

      myFile = newFile(FILENAME, "w");
      if(!myFile)return 1;

      for(int index = 0; index<ROWS; index++){
          data[index][0] = index;
          beginRecursive = clock();
          data[index][1] = recursiveFibonacci(index);
          endRecursive = clock();
          tiempoRecursive[index] += (double)(endRecursive - beginRecursive) / CLOCKS_PER_SEC;

          data[index][0] = index;
          beginSequential = clock();
          data[index][2] = sequentialFibonacci(index);
          endSequential = clock();
          tiempoSequential[index] += (double)(endSequential - beginSequential) / CLOCKS_PER_SEC;




      }
      puts("finished");
      printHeaders(myFile, 5, titles);
      csvFileWrite(myFile, COLUMNS, ROWS, data, tiempoRecursive, tiempoSequential);

      closeFile(myFile);
}
