#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int64_t ans[1000001];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int64_t t;
    cin>>t;
    ans[0]=0;
    for(int64_t i=1;i<=1000000;i++){
        ans[i]=((i + ans[i-1])%MOD + (i*ans[i-1])%MOD)%MOD;
    }
    while(t--){
 
        int64_t n;
        cin>>n;
        cout<<ans[n]<<"\n";

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}