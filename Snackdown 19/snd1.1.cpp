#include<bits/stdc++.h>
using namespace std;
int main(){

    int a[100000];
    bool s[100000];
    int t;
    int i;
    int nt1,nt2;
    cin>>t;
    int days=0;
    while(t--){
        days=0;
        int n;
        cin>>n;
        for(i=0;i<n;i++){
            s[i]=false;
            cin>>a[i];
        }
        s[0]=true;
        nt1=1;
        nt2=1;
        while(s[n-1]!=true){
            for(i=0;i<nt1;i++){
                for(int j=nt2;j<nt2+a[i];j++){
                    s[j]=true;
                }
                 nt2=nt2+a[i];
            }
            nt1=nt2;
            days++;
        }
    cout<<days<<endl;;
    }
}


