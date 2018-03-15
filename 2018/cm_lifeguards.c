#include <stdio.h>

#ifdef DEBUG 
#define DBG_PRINT(fmt, args...) fprintf(stderr,fmt, ##args)
#else
#define DBG_PRINT(fmt, args...) /* Do nothing */
#endif

struct guard {
    int st,ed; //start and end time
    int uniq_time;
};

struct guard gd[100];

void set_vector(char v[1000], struct guard g, int init) {
    int i;
    if (init) {
        for (i=0; i<1000; i++)
            v[i]=0;
    }
    for (i=g.st; i<g.ed;i++)
        v[i]=1;
}

int cnt_vector(const char v[1000]) {
    int cnt=0;
    int i;
    for (i=0; i<1000;i++)
        if (v[i]) cnt++;
    return cnt;
}

int main () {
    FILE *fpin, *fpout;
    if ((fpin = fopen("lifeguards.in","r"))==NULL) {
        fprintf(stderr,"Unable to open lifeguards.in for reading\n");
        return 1;
    }
    if ((fpout = fopen("lifeguards.out","w"))==NULL) {
        fprintf(stderr,"Unable to open lifeguards.out for writing\n");
        return 1;
    }
    int n_gd;
    int i;
    fscanf(fpin,"%d\n",&n_gd);
    for (i=0; i<n_gd;i++)
        fscanf(fpin, "%d %d\n",&gd[i].st, &gd[i].ed);
    fclose(fpin);
    
   // calculate and find the unique time of each guard
    for (i=0; i < n_gd; i++) {
        // for each g[i], find it's unique time
        char v[1000];
        int j;
        set_vector(v,gd[i],1);
        DBG_PRINT("Initial vector size of %d is %d\n",i,cnt_vector(v));
        for (j=0; j<n_gd; j++) {
            int k;
            if (j!=i) { //skip itself
                for (k=gd[j].st;k<gd[j].ed;k++)
                    v[k]=0;
            }
        }
        gd[i].uniq_time=cnt_vector(v);
    }
    
    // find the guard that has the minimum unique time
    int m=0, min_time;
    min_time=gd[0].uniq_time;
    for (i=1;i<n_gd;i++) {
        if (gd[i].uniq_time<min_time) {
            m=i;
            min_time=gd[i].uniq_time;
        }
    }
    
    char v[1000];
    set_vector(v,gd[0],1);
    for (i=1;i<n_gd;i++)
        set_vector(v,gd[i],0);
    for (i=0;i<n_gd;i++)
        DBG_PRINT("%d %d %d\n",gd[i].st,gd[i].ed,gd[i].uniq_time);
    DBG_PRINT("min is %d with uniq_time=%d\n",m, min_time);

    fprintf(fpout,"%d\n",cnt_vector(v)-min_time);
    fclose(fpout);
}
