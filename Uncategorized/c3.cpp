#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[100][100];
    int t;
    int n,m,x1,x2,y1,y2,q;
    int sum=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&q);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        while(q--){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            for(int i=x1-1;i<x2;i++){
                for(int j=y1-1;j<y2;j++){
                    sum+=a[i][j];
                }
            }
            printf("%d\n",sum);
                    sum=0;
        }
    }
}
