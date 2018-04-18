#include <stdio.h>
#include <stdlib.h> //abs value
#ifdef DEBUG 
#define DBG_PRINT(fmt, args...) fprintf(stderr,fmt, ##args)
#else
#define DBG_PRINT(fmt, args...) /* Do nothing */
#endif

int map[10][10];
int N;

void pt_map() {
  int i,j;
  DBG_PRINT("--map--\n");
  for (i=0;i<N;i++) {
    for(j=0;j<N;j++)
      DBG_PRINT("%1d",map[i][j]);
    DBG_PRINT("\n");
  }
}

//flip a rectangle of rowxcol
void flip(int row,int col) {
  int i,j;
  for (i=0;i<=row;i++)
    for (j=0;j<=col;j++)
      map[i][j]=map[i][j]? 0 : 1;
  DBG_PRINT("flip(%d,%d)\n",row, col);
  pt_map();
}

int cntFlip(int n) {
  int cnt=0;
  int i;
  if (n==0) {
    map[0][0]=0;
    DBG_PRINT("cntFlip(0)\n");
    pt_map();
    return map[0][0];
  }
  if (map[n][n]) {
    flip(n,n);
    cnt++;
  }
  for (i=n-1;i>=0;i--) {
    if (map[n][i]) {
      cnt++;
      flip(n,i);
    }
    if (map[i][n]) {
      cnt++;
      flip(i,n);
    }
  }
  DBG_PRINT("cntFlip(%d), cnt=%d\n",n,cnt);
  pt_map();
  return cnt + cntFlip(n-1);
}

int main() {
    FILE * fpin, *fpout;
    int cnt;
    if ((fpin = fopen("cowtip.in","r"))==NULL) {
        fprintf(stderr,"Unable to open cowtip.in for reading\n");
        return 1;
    }
    if ((fpout = fopen("cowtip.out","w"))==NULL) {
        fprintf(stderr,"Unable to open cowtip.out for writing\n");
        return 1;
    }
    fscanf(fpin,"%d",&N);
    int i,j;
    for (i=0;i<N;i++) 
      for(j=0;j<N;j++)
	fscanf(fpin,"%1d",&map[i][j]);
    pt_map();
    DBG_PRINT("START_______________\n");
    cnt=cntFlip(N-1);
    DBG_PRINT("END_________________\n");
    DBG_PRINT("cnt=%d\n",cnt);
    pt_map();
    fprintf(fpout,"%d\n",cnt);
    fclose(fpin);
    fclose(fpout);
    return 0;
}
