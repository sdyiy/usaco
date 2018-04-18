#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG 
#define DBG(fmt, args...) fprintf(stderr,fmt, ##args)
#else
#define DBG(fmt, args...) /* Do nothing */
#endif

struct xpos_t {
    int x;
    int pos;
};

int cmp_xpos (const void * a, const void *b) {
    return ((struct xpos_t *) a)->x - ((struct xpos_t *) b)->x;
}

int N;
struct xpos_t xpos[100*1000];
int main() {
    FILE * fpin, *fpout;
    if ((fpin = fopen("sort.in","r"))==NULL) {
        fprintf(stderr,"Unable to open sort.in for reading\n");
        return 1;
    }
    if ((fpout = fopen("sort.out","w"))==NULL) {
        fprintf(stderr,"Unable to open sort.out for writing\n");
        return 1;
    }
    
    fscanf(fpin,"%d",&N);
    int i;
    for (i=0;i<N;i++)  {
        fscanf(fpin,"%d",&xpos[i].x);
        xpos[i].pos=i;
        DBG("%d %d\n",xpos[i].x,xpos[i].pos);
    }
    qsort(xpos,N,sizeof(struct xpos_t), cmp_xpos);
    DBG("-----------\n");
    for (i=0;i<N;i++) 
        DBG("%d %d\n",xpos[i].x,xpos[i].pos);
    int max=0;
    int tmp;
    for (i=0;i<N;i++) {
        tmp=xpos[i].pos-i+1;
        if (tmp>max)
            max=tmp;
    }
    DBG("MAX=%d\n",max);
    fprintf(fpout,"%d\n",max);
    fclose(fpin);
    fclose(fpout);
    return 0;
}
