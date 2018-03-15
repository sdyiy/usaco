#include <stdio.h>

#ifdef DEBUG 
#define DBG_PRINT(fmt, args...) fprintf(stderr,fmt, ##args)
#else
#define DBG_PRINT(fmt, args...) /* Do nothing */
#endif

int main() {
    FILE * fpin, *fpout;
    if ((fpin = fopen("lifeguards.in","r"))==NULL) {
        fprintf(stderr,"Unable to open in for reading\n");
        return 1;
    }
    if ((fpout = fopen("lifeguards.out","w"))==NULL) {
        fprintf(stderr,"Unable to open out for writing\n");
        return 1;
    }
    
    int schedule[1000];
    int totalLifeguards, i, j;
    fscanf(fpin, "%d", &totalLifeguards);

    for (i = 0; i < totalLifeguards; i++){
      int start, end;
      fscanf(fpin, "%d %d", &start, &end);
      //fprintf(fpout, "the pair is %d%d\n", start, end);
      
      for (j = 0; j < (end - start); j++){
	schedule[start + j] += 1;

      }
    }
    
    

    fclose(fpin);
    fclose(fpout);
    return 0;
}
