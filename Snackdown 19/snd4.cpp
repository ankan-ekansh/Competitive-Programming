#include<bits/stdc++.h>
using namespace std;
long int a[100000],b[100000],c[100000];
void check(int n){
    bool flag=true;
    for(int i=0;i<n;i++){
        if(c[i]==b[i])
            flag=true;
        if(c[i]!=b[i]){
            flag=false;
            break;
        }
    }
    if(flag==true)
        cout<<"TAK\n";
    else
        cout<<"NIE\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<n-2;i++){
            c[i]=a[i]+1;
            c[i+1]=a[i]+2;
            c[i+2]=a[i]+3;
        }
    }
}
