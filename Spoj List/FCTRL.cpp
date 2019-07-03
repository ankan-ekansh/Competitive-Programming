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
    while(t--){
 
        i64 n;
        cin>>n;
        i64 x = 5;
        i64 z = 0;
        while(x<=n){
            z+=(n/x);
            x = x*5;
        }
        cout<<z<<"\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}