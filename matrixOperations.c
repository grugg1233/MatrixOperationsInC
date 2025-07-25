//Matrix operations add, multiply, transpose, determinant (for 2x2 or 3x3).

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

char * readTheTerminal(void) {
      char * line = malloc(100), * linep = line; 
      size_t  lenmax = 100, len = lenmax; 
      int c; 
      if (line == NULL) 
            return NULL; 
      for(;;) {
            c = fgetc(stdin); 
            if(c == EOF) 
                  break;
            if(--len == 0) {
                  len = lenmax; 
                  char * linen = realloc(linep, lenmax *= 2); 
                  if (linen == NULL) {
                        free(linep); 
                        return NULL; 
                  }
                  line = linen + (line - linep); 
                  linep = linen; 
            } 
            if ((*line++ = c) == '\n') 
                  break; 
      }
      *line = '\0'; 
      return linep; 
}

void addM() { printf("ADD\n"); }
void multM() { printf("MULTIPLY\n"); }
void transM() { printf("TRANSPOSE\n"); }
void detM() { printf("DETERMINANT\n"); }

int isInt(const char* str) {
      while(*str) {
            if(!isdigit(*str) && *str != '\n') return 0; 
            str++; 
      }
      return 1; 
} 

int main() {



//logic for getting matrix size from terminal 
      printf("Note* determinant (for 2x2 ONLY)\n enter the size of matrix one : "); 
      char* m1Size= readTheTerminal(); 
      if(!isInt(m1Size)) { 
            printf("ERROR: incorrect value type entered");       
            return 1;
      } 
      const int m1S = atoi(m1Size); 
      printf("Matrix one is : %dx%d\n", m1S ,m1S); 
      int m1[m1S][m1S]; 
      
      printf("Select operation (add (1) , multiply (2), transpose (3), determinant (4) (for 2x2 ONLY)) type in lower case: ");
      char* operation= readTheTerminal(); 
      if(!isInt(operation)) { 
            printf("ERROR: incorrect value type entered");       
            return 1;
      } 
      int op = atoi(operation); 
      printf("Matrix operation is : "); 

      
      switch(op){
            case(1): 
                  addM();
                  break;
            case(2) :
                  multM();
                  break;
            case(3) : 
                  transM();
                  break;
            
            case (4) : 
                  if(op == 4 && m1S != 2) {
                        printf("Unkown determinant size must be 2x2 for this operation\n"); 
                        break; 
                  }
                  detM();
                  break; 
            default: 
                  printf("Unknown operation: %s\n", operation);
      

      }
      //delete the value sent by the user
      free(m1Size); 
      free(operation);
      return 0; 
      

}