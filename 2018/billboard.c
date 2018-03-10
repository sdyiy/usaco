#include <stdio.h>
int main () {
  FILE *fin, *fout;
  int c;
  fin = fopen("billboard.in", "r");
  fout = fopen("billboard.out", "w");
  while ((c = getc(fin)) != EOF)
   
    putc (c, fout);
  
  if(fout == NULL) {
    printf("Error opening file to write\n");
    return 1;
  }
  fprintf(fout,"%d\n",15);
  fclose(fout);
}
