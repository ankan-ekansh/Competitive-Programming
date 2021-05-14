/*
    Stay motivated and keep working hard
*/
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
        
        ll a, b, q;
        cin >> a >> b >> q;
        ll mx = max(a, b);
        ll lm = (a*b)/__gcd(a, b);
        while(q--){
            ll l, r;
            cin >> l >> r;
            if(r < mx){
                cout << "0 ";
                continue;
            }
            l = max(l, mx);
            ll right = r / lm;
            ll left = l / lm;
            ll ans = 0;
            if(l < lm*left + mx){
                l = lm*left + mx;
            }
            if(r < lm*right + mx){
                r = lm*right - 1;
                right--;
            }
            if(l > r){
                cout << "0 ";
                continue;
            }
            ans = (right - left) * mx;
            cout << (r - l + 1 - ans) << " ";
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}