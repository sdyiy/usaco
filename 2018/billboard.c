#include <stdio.h>
int main () {
  //opening/reading files
  FILE *fin, *fout;
  int c;
  fin = fopen("billboard.in", "r");
  fout = fopen("billboard.out", "w");
  
  
  //while ((c = getc(fin)) != EOF)
   
    for (int i = 1; i < 9; i++)
      if (i == 1)
	c = getc(fin);
     
	printf("%i", c);
  
  if(fout == NULL) {
    printf("Error opening file to write\n");
    return 1;
  }
  fprintf(fout,"%d\n",15);
  fclose(fout);
}
