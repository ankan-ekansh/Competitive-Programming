#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p;
    p = (int*)malloc(sizeof(int));
    *p = 10;
    printf("%d\n", *p);
    free(p);
    p = (int*)malloc(3*sizeof(int));
    *p = 10, *(p+1) = 20, *(p+2) = 30;
    p[0] = 1, p[1] = 2, p[2] = 3;
    printf("%d %d %d\n", *p, *(p+1), *(p+2));
    printf("%d %d %d\n", p[0], p[1], p[2]);
    free(p);
}