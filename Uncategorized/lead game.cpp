#include<bits/stdc++.h>
using namespace std;
int main(){
    int r;
    int a[10000],b[10000];
    int x,y,t;
    int cx,cy;
    int cl1,cl2,l1m,l2m;
    cin>>r;
    for(int i=0;i<r;i++){
        cin>>x>>y;
        cx+=x;
        cy+=y;
        a[i]=cx;
        b[i]=cy;
        }
    for(int i=0;i<r;i++){
        if(a[i]>b[i]){
            t=a[i];
            a[i]=1;
            b[i]=t-b[i];
    }
        if(a[i]<b[i]){
            t=a[i];
            a[i]=2;
            b[i]=b[i]-t;
        }
}
    for(int i=0;i<r;i++){
        if(a[i]==1){
            if(b[i]>l1m){
                l1m=b[i];
                cl1=i;
            }
        }
        else if(a[i]==2){
            if(b[i]>l2m){
                l2m=b[i];
                cl2=i;
            }
        }
    }
    if(l1m>l2m)
        cout<<a[cl1]<<" "<<l1m;
    else
        cout<<a[cl2]<<" "<<l2m;

}
