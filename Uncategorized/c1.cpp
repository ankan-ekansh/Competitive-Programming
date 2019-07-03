#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0,n,a[100000];
    scanf("%d",&t);
    for(int x=1;x<=t;x++){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(i==0){
                printf("-1 ");
            }
            else{
                int pos=i;
                for(int j=pos-1;j>=0;j--){
                    if(a[j]>=a[pos]){
                        pos=j;
                        break;
                    }
                }
                if(pos!=i)
                    printf("%d ",a[pos]);
                else
                    printf("-1 ");
            }
        }
    }
}
