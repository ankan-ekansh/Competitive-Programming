#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
 
        ll k, n, a, b;
        cin >> k >> n >> a >> b;
        if(k - (n * a) > 0){
            cout<<n<<"\n";
        }
        else{
            ll ans = n;
            ll diff = a-b;
            ll c = k - (n * a);
            ll turns = ceil( (double)(1-c)/((double)diff) );
            if(turns > n){
                cout<<"-1\n";
            }
            else{
                cout<<ans-turns<<"\n";
            }
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}