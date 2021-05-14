/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lcm(ll a, ll b){
    return (a*b)/(__gcd(a, b));
}
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
        if(a > b){
            swap(a, b);
        }
        while(q--){
            ll l, r;
            cin >> l >> r;
            ll ctr = 0;
            ctr = r - b + 1;
            ll n = r / lcm(a, b);
            // cout << " : " << ctr << " : ";
            if(n > 0){
                ctr = ctr - (b * (n-1) + max(0LL, r - n*(lcm(a, b)) + 1));
                // cout << " : " << (b * (n-1) + max(0LL, r - n*(lcm(a, b)) + 1)) << " : ";
            }
            if(b <= l){
                ll ctr2 = (l - b);
                ll m = l / lcm(a, b);
                // cout << " : " << ctr2 << " : ";
                if(m > 0){
                    ctr2 = ctr2 - (b * (m-1) + max(0LL, l - m*(lcm(a, b))));
                    // cout << " : " << (b * (m-1) + max(0LL, l - m*(lcm(a, b)))) << " : ";
                }
                ctr = ctr - ctr2;
                // cout << " ( " << ctr2 << " ) ";
            }
            cout << ctr << " ";
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}