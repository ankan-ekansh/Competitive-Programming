#include<stdio.h>
#include<string.h>
int main(){

    int i;
    int h[200]={0};
    char w[15];
    for(i=97;i<=122;i++){
        scanf("%d",&h[i]);
    }
    scanf("%s",w);
    int l = strlen(w);
    int hmax = 0;
    for(i=0;i<l;i++){
        if(h[(int)w[i]] > hmax){
            hmax = h[(int)w[i]];
        }
    }
    printf("%d",l*hmax);


    return 0;
}
