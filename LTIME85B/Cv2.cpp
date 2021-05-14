#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
        ll n, k;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        if(k == 1LL){   
            ll val_x=-1,mxm=-1;
            for(ll i=0;i<=31;i++){
                ll val = (1LL << i);
                ll ans = 0;
                for(ll i=0;i<n;i++){
                    ans += (a[i]&val);
                }
                if(ans > mxm){
                    mxm = ans;
                    val_x = val;
                }
            }
            cout << val_x << "\n";
        }
        if(k > 1){
            ll val_x = -1, mxm = -1;
            for(ll i=0;i<=30;i++){
                for(ll j=i+1;j<=31;j++){
                    ll val = (1LL << i) + (1LL << j);
                    ll ans = 0;
                    for(ll i=0;i<n;i++){
                        ans+=a[i]&val;
                    }
                    if(ans > mxm){
                        mxm = ans;
                        val_x = val;
                    }
                }
            }
            cout << val_x << "\n";
        }

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}