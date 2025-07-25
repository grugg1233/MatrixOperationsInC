//Matrix operations add, multiply, transpose, determinant (for 2x2 or 3x3).

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

int isInt(const char* str) {
      while(*str) {
            if(!isdigit(*str) && *str != '\n') return 0; 
            str++; 
      }
      return 1; 
} 

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

void addM( int m1S,int m1[m1S][m1S]) { 

      printf("Note* determinant (for 2x2 ONLY)\n enter the size of matrix two : "); 
      char* m2Size= readTheTerminal(); 
      if(!isInt(m2Size)) { 
            printf("ERROR: incorrect value type entered");       
            return; 
      } 
      const int m2S = atoi(m2Size); 
      printf("Matrix two is : %dx%d\n", m2S ,m2S); 
      int m2[m2S][m2S]; 

      if(m2S != m1S){ 
            printf("Matricies are not of the same size and thus cannot be added"); 
            free(m2Size); 
            return; 
      }
            //fill the second matrix 
      for(int row = 0; row < m1S ; row++) {
            for(int col = 0; col < m1S; col++) {
                  printf("enter value for row: %d, col: %d :", row, col); 
                  char* val = readTheTerminal(); 
                  if(!isInt(val)) { 
                        printf("ERROR: incorrect value type entered");       
                        return; 
                  } 
                  const int v = atoi(val); 
                  free(val);
                  m2[row][col] = v;
            }
      }

      printf("M1 + M2 = \n"); 

      for(int row = 0; row < m2S ; row++) {
            for(int col = 0; col < m2S; col++) {
                  m1[row][col] = m2[row][col] + m1[row][col];
                  printf("%d ", m1[row][col]);
            }
            printf("\n"); // New line per row
      }



 }
void multM() { printf("MULTIPLY\n"); }
void transM() { printf("TRANSPOSE\n"); }
void detM() { printf("DETERMINANT\n"); }



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
      
      //fill the first matrix 
      for(int row = 0; row < m1S ; row++) {
            for(int col = 0; col < m1S; col++) {
            printf("enter value for row: %d, col: %d :", row, col); 
            char* val= readTheTerminal(); 
            if(!isInt(val)) { 
                  printf("ERROR: incorrect value type entered");       
                  return 1;
            } 
            const int v = atoi(val); 
            free(val); 
                m1[row][col] = v;
            }
      }


//operation

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
                  addM( m1S,m1);
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