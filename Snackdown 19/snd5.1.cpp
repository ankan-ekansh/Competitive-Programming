#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        int p=1;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int f=1;
        for(int i=n-1;i>0;i--){
            if(a[i-1]==a[i]){
                f++;
            }
            if((a[i-1]!=a[i])&&(i%2!=0)){
                p=p*(f);
                f=1;
            }
            if((a[i-1]!=a[i])&&(i%2==0)){
                p=p*1;
                f=1;
            }
            if(i==1){
                p=p*(f);
            }
        }
        cout<<p<<endl;
    }
}
