#include <stdio.h>

#ifdef DEBUG
#define DBG_PRINT(fmt, args...) fprintf(stderr,fmt, ##args)
#else
#define DBG_PRINT(fmt, args...) /* Do nothing */
#endif

int main() {
  FILE * fpin, *fpout;
  if ((fpin = fopen("outofplace.in","r"))==NULL) {
    fprintf(stderr,"Unable to open billboard.in for reading\n");
    return 1;
  }
  if ((fpout = fopen("outofplace.out","w"))==NULL) {
    fprintf(stderr,"Unable to open billboard.out for writing\n");
    return 1;
  }
  int numberOfCows = 0,toggle = 0, i, j, wrongCowIndex, rightCowIndex = 0, distinctNumberCount = 0;
  wrongCowIndex = 0;
  fscanf(fpin, "%d", &numberOfCows);
  int cowLine[numberOfCows];

  for (j = 0; j < numberOfCows; j++) {
    fscanf(fpin, "%d", &cowLine[j]);
    DBG_PRINT("%d\n", cowLine[j]);
  }
  
  
  //for loop starts at 1 because first element doesn't need to be checked
  
  for (i = 0; i < numberOfCows; i++){
    if (cowLine[i] > cowLine[i+1]){
      if (i == 0){
	wrongCowIndex = 0;
	break;
      } else /*if (cowLine[i] <= cowLine[i-1])*/{
      wrongCowIndex = i;
      break;
      }   
 }
    else if (cowLine[i] < cowLine[i-1]){
      wrongCowIndex = i;
    }
  }

  DBG_PRINT("WRONG COW INDEX: %d\n", wrongCowIndex);

  //no swaps needed 
  if (cowLine[0] > cowLine[wrongCowIndex]){
    rightCowIndex = 0;
    distinctNumberCount += 1;
    DBG_PRINT("added 1");
    }
  //if (cowLine[0] == cowLine[wrongCowIndex]){
    //rightCowIndex = 0;
    
    //DBG_PRINT("its supposed to be at 0");}
  else {
     //currently the wrong cow has moved to the right side of the line, WCI > RCI
    for (i = 0; i < numberOfCows; i++){
      if (i == wrongCowIndex){
	continue;
      }
      if (cowLine[i-1] <= cowLine[wrongCowIndex] && cowLine[i] >= cowLine[wrongCowIndex]){
	rightCowIndex = i - 1;
	DBG_PRINT("ITS SUPPOSED TO BE AT INDEX %d", rightCowIndex); //PRINT THING HERE
	toggle = 1;
	break;
	printf("This shouldn't get printed");
      }
    }
    
    
  } 
    //end of else
  
  if (toggle == 0){
    DBG_PRINT("probably at end, rightcowindex is %d", numberOfCows);
    rightCowIndex = numberOfCows;
  }
  
  if (wrongCowIndex > rightCowIndex){
    for (i = rightCowIndex + 1; i < wrongCowIndex; i++){
      
      if (cowLine[i] != cowLine[i-1]){
	distinctNumberCount += 1;
      }
    }
  } else if (wrongCowIndex < rightCowIndex){
    for (i = rightCowIndex; i > wrongCowIndex; i--){
      
      if (cowLine[i] != cowLine[i-1]){
        distinctNumberCount += 1;
      }
    }
  }
  
  fprintf(fpout, "%d", distinctNumberCount);
  
  

  fclose(fpin);
  fclose(fpout);
  return 0;
}

