/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool fun(ll x, ll a, ll b){
    return ((x%a)%b != (x%b)%a);
}
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
    // t = 1;
    while(t--){
        
        ll a, b, q;
        cin >> a >> b >> q;
        while(q--){
            ll l, r;
            cin >> l >> r;
            ll ctr = 0;
            for(ll i=l;i<=r;i++){
                if(fun(i, a, b)){
                    ctr++;
                    cout << i << "<->";
                }
            }
            // cout << (r / a) + (r / b) - (r / (lcm(a, b))) - (l / a) - (l / b) + (l / lcm(a, b)) << " ";
            cout << ctr << " \n";
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}