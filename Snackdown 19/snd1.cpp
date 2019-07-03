#include<bits/stdc++.h>
using namespace std;
int main(){

    int a[10000];
    bool s[10000];
    int t;
    int i;
    int nt;
    cin>>t;
    int days=0;
    while(t--){
        int n;
        cin>>n;
        for(i=0;i<n;i++){
            s[i]=false;
            cin>>a[i];
        }
        s[0]=true;
        nt=1;
        while(s[n-1]!=true){
            for(i=0;i<nt;i++){
                for(int j=nt;j<nt+a[i];j++){
                    s[j]=true;

                }
                 nt=nt+a[i-1];

            }

            days++;
        }


    cout<<days;
    }
}


