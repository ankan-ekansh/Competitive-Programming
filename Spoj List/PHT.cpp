#include<bits/stdc++.h>
#define i64 int64_t
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    i64 t;
    cin>>t;
    i64 c=0;
    while(t--){
        i64 n;
        cin>>n;
        i64 ans = (int)((sqrt(n+1)))-1;
        cout<<"Case "<<++c<<": "<<ans<<'\n';
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}