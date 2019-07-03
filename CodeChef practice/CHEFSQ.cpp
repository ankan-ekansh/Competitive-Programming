#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    cin>>t;
    //cout<<t<<"\n";
    while(t--){
 
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;
        int b[m];
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        int c=0;
        for(int i=0,j=0;i<n && j<m;i++){
            if(a[i]==b[j]){
                c++;
                j++;
            }
            // if(c==m){
            //     break;
            // }
        }
        if(c==m){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}