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

void printM(int size, int mat[size][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%d ", mat[row][col]);
        }
        printf("\n");
    }
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
      printf("Enter Matrix 2 size : "); 
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
      printf("M1: \n"); 
      printM(m1S, m1); 
      printf("M2: \n"); 
      printM(m2S, m2); 
      printf("operation addition : \n"); 
      for(int row = 0; row < m2S ; row++) {
            for(int col = 0; col < m2S; col++) {
                  m1[row][col] = m2[row][col] + m1[row][col];
                  printf("%d ", m1[row][col]);
            }
            printf("\n"); // New line per row
      }



 }
void multM(int m1S,int m1[m1S][m1S]) { 
      
      printf("Enter Matrix 2 size : "); 
      char* m2Size= readTheTerminal(); 
      if(!isInt(m2Size)) { 
            printf("ERROR: incorrect value type entered");       
            return; 
      } 
      const int m2S = atoi(m2Size); 
      printf("Matrix two is : %dx%d\n", m2S ,m2S); 
      int m2[m2S][m2S]; 

      if(m2S != m1S){ 
            printf("M1 cols != M2 rows cannot multiply matricies"); 
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

      printf("M1: \n"); 
      printM(m1S, m1); 
      printf("M2: \n"); 
      printM(m2S, m2); 
      printf("operation multiplication"); 

      int result[m1S][m2S];

      //calculate multiplaction and print
      for (int i = 0; i < m1S; i++) {
            for (int j = 0; j < m2S; j++) {
                  result[i][j] = 0;
                  for (int k = 0; k < m1S; k++) {
                  result[i][j] += m1[i][k] * m2[k][j];
                  }
            }
      }

      printf("M1 * M2 =\n");
      printM(m1S, result);
      
}
void transM(int m1S,int m1[m1S][m1S]) { 
            
      printf("Transpose of the matrix : \n"); 
      printM(m1S, m1);
      printf("is : \n"); 
      int temp[m1S][m1S];
      for(int i = 0; i < m1S; i++) {
            for(int j = 0; j < m1S; j++) {
                  temp[i][j] = m1[j][i]; 
            }
      }
      printf("M1^T =\n");
      printM(m1S, temp);
      

 }
void detM(int m1S,int m1[m1S][m1S]) { printf("DETERMINANT\n"); }



int main() {
      int calculate = 1; 
      while (calculate == 1){
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
                        multM(m1S,m1);
                        break;
                  case(3) : 
                        transM(m1S,m1);
                        break;
                  
                  case (4) : 
                        if(op == 4 && m1S != 2) {
                              printf("Unkown determinant size must be 2x2 for this operation\n"); 
                              break; 
                        }
                        detM(m1S,m1);
                        break; 
                  default: 
                        printf("Unknown operation: %s\n", operation);
            

            }

            
            //delete the value sent by the user
            free(m1Size); 
            free(operation);

            int incorrectinput = 1; 
            while(incorrectinput)
            {
                  printf("Calculate another matrix? (y/n)?"); 
                  char* user = readTheTerminal();  
                  if (*user == 'n' || *user == 'N') {
                        calculate = 0; 
                        break; 
                  }
                  else if (*user == 'y' || *user == 'Y') break; 
                  else {
                        printf("incorrect input type please enter (y/n)");  
                  }
                  free(user);
            }


      }

      return 0; 
      

}