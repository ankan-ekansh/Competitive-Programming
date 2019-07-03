#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        // int a,b,c,d;
        // cin>>a>>b>>c>>d;
        // if((a == b && c == d) || (a == c && b == d) || (a == d && b == c)){
        //     cout<<"YES\n";
        // }
        // else{
        //     cout<<"NO\n";
        // }
        int a[4];
        for(int i=0;i<4;i++){
            cin>>a[i];
        }
        sort(a,a+4);
        if(a[0] == a[1] && a[2] == a[3]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}