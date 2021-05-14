#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9+7;
ll claws[2000007];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    claws[1] = claws[2] = 0;
    claws[3] = claws[4] = 1;
    for(ll i=5;i<=2000000;i++){
        claws[i] = ((claws[i-1] + 2*claws[i-2]) % mod + (i % 3 == 0 ? 1 : 0))%mod;
    }
    int t;
    cin>>t;
    while(t--){
        
        ll n;
        cin >> n;
        cout << (claws[n] * 4ll) % mod << "\n";
        
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}