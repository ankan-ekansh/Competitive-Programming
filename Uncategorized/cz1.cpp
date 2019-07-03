#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        int x[1000],y[1000];
        cin>>n>>m>>q;
        for(int i=0;i<q;i++){
            cin>>x[i]>>y[i];
        }
        sort(y,y+q);
        int cost=y[q-1]-y[0];
        cout<<cost<<endl;
    }
    return 0;
}
