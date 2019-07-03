#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        int i;
        int days=0;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int nt1,nt2;
        nt1=1;
        nt2=1;
        for(i=0;i<nt1;i++){
            nt2=nt2+a[i];
            if(nt2>=n){
                days++;
                break;
            }
            if(i==(nt1-1)){
                nt1=nt2;
                days++;
                i=-1;
            }
        }
        printf("%d\n",days);
    }
}
