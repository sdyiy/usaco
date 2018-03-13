#include <stdio.h>
int main () {
  //opening/reading files
  FILE *fin, *fout;
  int c;
  fin = fopen("billboard.in", "r");
  fout = fopen("billboard.out", "w");
  //declare variables to store input
  int x1, x2, a1, a2, y1, y2, b1, b2;

  int array[8] = {};
  //reading input file, assigning input to variables
  if (fscanf(fin,"%d", &x1) == 1){
   
  };
  //WITHOUT THE IF STATEMENT YOULL NEED: fprintf(fout, "%d\n", x1);
  if (fscanf(fin,"%d", &y1) == 1){

  };
  //fscanf(fin,"%d", &y1);
  
  if (fscanf(fin,"%d", &x2) == 1){

  };
  //fscanf(fin,"%d", &x2);
  
  if (fscanf(fin,"%d", &y2) == 1){

  };
  //fscanf(fin,"%d", &y2);
  //fprintf(fout, "%d\n", y2);

  if (fscanf(fin,"%d", &a1) == 1){

  };
  //fscanf(fin,"%d", &a1);
  //fprintf(fout, "%d\n", a1);

  if (fscanf(fin,"%d", &b1) == 1){

  };
  //fscanf(fin,"%d", &b1);
  //fprintf(fout, "%d\n", b1);

  if (fscanf(fin,"%d", &a2) == 1){

  };
  //fscanf(fin,"%d", &a2);
  //fprintf(fout, "%d\n", a2);

  if (fscanf(fin,"%d", &b2) == 1){

  };
  //fscanf(fin,"%d", &b2);
  
  //fprintf(fout, "%d\n", b2);
  
  //print to test all variables assigned correctly COMMENTED OUT
  //fprintf(fout, "%d, %d, %d, %d, %d, %d, %d, %d\n", x1, y1, x2, y2, a1, b1, a2, b2);
  //variable for area of back billboard
  int backgroundArea = (y2 - y1)*(x2 - x1);
  
  //OKAY TIME TO START THE ACTUAL STUFF.
  if ((a1 <= x1) && (a2 >= x2)){
    //variable for height of relevant front billboard                                                      
    int heightOfFront = 0;
    //the width of front billboard is larger or equal to back billboard
    if ((b2 >= y2) && (b1 <= y1)){
      //the entire back billboard is covered
      printf("The entire thing is covered: 0\n");
	  fprintf(fout, "0\n");
    }
    else if ((b2 >= y1) && (b2 <= y2)){
      //not the entire back billboard is covered, it covers the lower half
      if (b1 >= y1){
	    //bottom edge of front billboard is above bottom edge of back billboard
	    heightOfFront = b2 - b1; //height of relevant front billboard is front billboard height
	    fprintf(fout, "%d\n", backgroundArea - (heightOfFront * (x2 - x1)));
	  }
	  else if (b1 <= y1){
	    //bottom edge of front billboard is below bottom edge of back billboard
	    heightOfFront = b2 - y1; //height of relevant front billboard is front - back
	    fprintf(fout, "%d\n", backgroundArea - (heightOfFront * (x2 - x1)));
	  }
    }
    else if ((b1 >= y1) && (b1 <= y2)){
      //not the entire back billboard is covered, it covers the upper half
      if (b2 >= y2){
	heightOfFront = y2 - b1; //height of relevant front billboard is front - back
	fprintf(fout, "%d\n", backgroundArea - (heightOfFront * (x2 - x1)));
      }
      else {
	fprintf (fout, "uh there's some kind of error no. 1\n");
      }
    }
  }

  if ((b1 <= y1) && (b2 >= y2)){
    //variable for height of relevant front billboard                                                      
    int widthOfFront = 0;
    //the height of front billboard is larger or equal to back billboard
    if ((a2 >= x1) && (a2 <= x2)){
      //front billboard covers left side of back billboard
      if (a1 >= x1){
	//left edge of front billboard is to the right of left edge of back billboard
	widthOfFront = a2 - a1; //relevant width of front billboard is front billboard width
	fprintf(fout, "%d\n", backgroundArea - (widthOfFront * (y2 - y1)));
      }
      else if (a1 <= x1){
	//left edge of front billboard is to the left of left edge of back billboard
	widthOfFront = a2 - x1; //relevant with of front billboard is front - back
	fprintf(fout, "%d\n", backgroundArea - (widthOfFront * (y2 - y1)));
      }
    }
    else if ((a1 >= x1) && (a1 <= x2)){
      //front billboard covers right side of back billboard
      if (a2 >= x2){
	widthOfFront = x2 - a1;
	fprintf(fout, "%d\n", backgroundArea - (widthOfFront * (y2 - y1)));
      }
    }
      
  }
  else {
    //nothing relevant is covered, you need the entire tarp
    fprintf (fout, "%d\n", backgroundArea);
  }






  while ((c = getc(fin)) != EOF){
    //for(int x = 0; x < 5; x++){
      
    //fscanf(fin, "%d", &c);
    //fprintf(fout, "%d\n", c);
    

    /*for (int i = 0; i < 8; i++){
      if (array[i] == 0){
	fscanf(fin, "%d", &array[i]);
	printf("%i", array[i]);
	      
	    
      
      }
  }*/
  
}


 
  
   
  /*for (int i = 1; i < 9; i++){
    if (i == 1){
      fscanf(fin, "%i", &x1);
      printf("%i",x1);
    }
    if (i == 2){
      fscanf(fin, "%d", &y1);
      printf("%i", y1);
    }
    if (i == 3){
      fscanf(fin, "%d",&c);
      x2 = c;
    }
    if (i == 4){
      fscanf(fin, "%d",&c);
      y2 = c;
    }
    */
    
    

    //fscanf(fin,"%i",&c);
      printf("%i",c);
      //fprintf(fout, "hello i am %d\n", c);
    
     
    //printf("%i is the thing", c);
  
  if(fout == NULL) {
    printf("Error opening file to write\n");
    return 1;
  }
  //fprintf(fout,"%d\n",15);
  fclose(fout);
}
