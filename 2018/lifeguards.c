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
    int timeCheck, timeCovered=0, totalLifeguards, i, j, k;
    fscanf(fpin, "%d", &totalLifeguards);
    for (i = 0; i < 1000; i++){
      schedule[i] = 0;
    }
    //assembling the array
    for (i = 0; i < totalLifeguards; i++){
      int start, end;
      fscanf(fpin, "%d %d", &start, &end);
      //fprintf(fpout, "the pair is %d%d\n", start, end);
      
      for (j = 0; j < (end - start); j++){
	schedule[start + j] += 1;
	DBG_PRINT("schedule's %d element is %d\n", start + j, schedule[start+j]);

      }
    }
    rewind(fpin);
    fscanf(fpin, "%d", &totalLifeguards); //useless and gets first one out of way           
    //checking the array one at a time
    for (i = 0; i < totalLifeguards; i++){
      int start, end;
      timeCheck = 0;
       //useless and gets first one out of way
     
      fscanf(fpin, "%d %d", &start, &end);
      DBG_PRINT("did it rewind: %d %d\n", start, end);
      for (j = 0; j <(end - start); j++){
	schedule[start + j] -= 1;
      }
      for (k = 0; k < 1000; k++){
	if (schedule[k] != 0){
	  timeCheck += 1;
	  DBG_PRINT("schedule[%d] is %d right now\n", k, schedule[k]);
	  //DBG_PRINT("timeCheck is %d right now", timeCheck);
	}
      }
      if (timeCheck >= timeCovered){
	timeCovered = timeCheck;
      }
      for (j = 0; j <(end - start); j++){
        schedule[start + j] += 1;
      }
    }

    for (i = 0; i < 1000; i++){
      //DBG_PRINT ("%d\n", schedule[i]);
    }
    fprintf(fpout, "%d", timeCovered);
    
    

    fclose(fpin);
    fclose(fpout);
    return 0;
}
