#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fptr;
  
  /* Opens the file if it exists */

  fptr = fopen(argv[1], "r");
  if (fptr == NULL) {
    printf("Error opening file");
    return -1;
  }
  
  char array[1000] = {0};
  char *ptr = &array[0];
  
  long *mark = malloc(sizeof(long));
  int depth = 0;
  char c;

  do {
    
    c = fgetc(fptr);
    if (feof(fptr)) {
      break;
    }

    /* Move the pointer forward */
    if (c == '>') {
      ++ptr;
    }

    /* Move the pointer backward */
    else if (c == '<') {
      --ptr;
      if (ptr < 0) {
        fclose(fptr);
        printf("Pointer below 0 not allowed");
        return -1;
      }
    }
    
    /* Add/subtract 1 at the to memory at the location of the data pointer */
    else if (c == '+') {
      ++*ptr;
    }
    else if (c == '-') {
      --*ptr;
    }

    /* Print or scan a character */
    else if (c == '.') {
      printf("%c", *ptr);
    }
    else if (c == ',') {
      scanf("%c", ptr);
    }
    
    /* Looping - if the value at the data pointer is 0, break from the loop
     * else go back to the first brcket
     */
    
    else if (c == '[') {
      *(mark + depth) = ftell(fptr);
      ++depth;
      mark = realloc(mark, depth*sizeof(*mark));
    }
    else if (c == ']') {
      if (*ptr) {
        fseek(fptr, *(mark + depth - 1), SEEK_SET);
        continue;
      }
      --depth;
      mark = realloc(mark, depth*sizeof(*mark));
    } 
  } while (1);

  printf("\n");
  free(mark);
  /* Closing the file */
  fclose(fptr);
  return 0;
}
