#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin>>s;
    int64_t n;
    cin>>n;
    vector<int64_t> a;
    a.resize(n);
    for(int64_t i=0;i<n;i++){
        cin>>a[i];
    }
    int64_t f[10]={0};
    for(char c:s){
        int64_t temp = c - '0';
        f[temp]++;
    }
    int64_t ans = 1;
    for(int64_t i=0;i<n;i++){
        ans = ( (ans%mod) * (f[a[i]]%mod) ) % mod;
    }
    cout<<ans<<"\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}