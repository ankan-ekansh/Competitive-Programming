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
    
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    char ac = 'G', bc = 'B';
    if(b < a){
        swap(a, b);
        swap(ac, bc);
    }
    if(b > (a+1)*k){
        cout << "NO\n";
        return 0;
    }
    ll extra = b - a;
    string ans;
    for(ll i=0;i<a;i++){
        ans += bc;
        if(extra){
            for(ll j=0;j<k-1 && extra > 0; j++){
                ans += bc;
                extra--;
            }
        }
        ans += ac;
    }
    if(extra > 0){
        for(ll i=0;i<extra;i++){
            ans += bc;
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}