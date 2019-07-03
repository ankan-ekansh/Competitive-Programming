#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        int temp,d,sum=0;
        cin>>n;
        temp=n;
        while(temp>0){
            d=temp%10;
            sum+=d;
            temp/=10;
        }
        cout<<sum<<endl;
    }
    return 0;
}
