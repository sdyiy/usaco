#include <stdio.h>

#ifdef DEBUG 
#define DBG_PRINT(fmt, args...) fprintf(stderr,fmt, ##args)
#else
#define DBG_PRINT(fmt, args...) /* Do nothing */
#endif

struct board {
    int x1, y1, x2, y2;
};

// return the range of a that is not blocked by range b
int get_visble_range(int a1, int a2, int b1, int b2) {
    if ( (a2 <=b1) || (a1>=b2) || 
         ((a1<b1) && (a2>b2)))
        return a2-a1;
    else if ((a1>=b1) && (b2>=a2))
        return 0;
    else if (a1<b1)
        return (b1-a1);
    else 
        return (a2-b2);
}

void print_board(struct board b) {
    printf("%4d %4d %4d %4d\n",b.x1,b.y1,b.x2,b.y2);    
}

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
    struct board lawn, cow;
    fscanf(fpin,"%d %d %d %d\n",&lawn.x1,&lawn.y1,&lawn.x2,&lawn.y2);
    fscanf(fpin,"%d %d %d %d\n",&cow.x1,&cow.y1,&cow.x2,&cow.y2);
    fclose(fpin);
    int xx = get_visble_range(lawn.x1, lawn.x2, cow.x1, cow.x2);
    int yy = get_visble_range(lawn.y1, lawn.y2, cow.y1, cow.y2);
    int size;
    if (xx && yy) 
        size=(lawn.x2-lawn.x1)*(lawn.y2-lawn.y1);
    else if (xx)
        size=xx*(lawn.y2-lawn.y1);
    else if (yy)
        size=yy*(lawn.x2-lawn.x1);
    else 
        size=0;
    print_board(lawn);
    print_board(cow);
    DBG_PRINT("xx=%d yy=%d size=%d\n",xx,yy,size);
    fprintf(fpout,"%d\n",size);
    fclose(fpout);
    return 0;
}
