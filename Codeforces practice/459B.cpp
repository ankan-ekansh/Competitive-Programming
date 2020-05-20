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

    ll n;
    cin >> n;
    ll a[n];
    ll x=LLONG_MAX, y=LLONG_MIN, fx=0, fy=0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        x = min(x, a[i]);
        y = max(y, a[i]);
    }
    for(ll i=0;i<n;i++){
        if(a[i] == x)
            fx++;
        if(a[i] == y){
            fy++;
        }
    }
    if(y != x)
        cout << y - x << " " << fy * fx << "\n";
    else{
        cout << "0 " << (fx * (fx - 1))/2 << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}