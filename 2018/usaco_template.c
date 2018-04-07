#include <stdio.h>
#include <stdlib.h> //abs value
#ifdef DEBUG 
#define DBG_PRINT(fmt, args...) fprintf(stderr,fmt, ##args)
#else
#define DBG_PRINT(fmt, args...) /* Do nothing */
#endif

int main() {
    FILE * fpin, *fpout;
    if ((fpin = fopen("billboard.in","r"))==NULL) {
        fprintf(stderr,"Unable to open billboard.in for reading\n");
        return 1;
    }
    if ((fpout = fopen("billboard.out","w"))==NULL) {
        fprintf(stderr,"Unable to open billboard.out for writing\n");
        return 1;
    }
    
    

    fclose(fpin);
    fclose(fpout);
    return 0;
}
