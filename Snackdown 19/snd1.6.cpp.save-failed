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
        int nt;
        nt=1;
       while(nt<n){
           int c=0;
           int temp=nt;
           while(temp--){
               nt+=a[c++];
               if(nt>=n)
                break;
           }
           days++;
           if(nt>=n)
            break;
       }
        printf("%d\n",days);
    }
}
