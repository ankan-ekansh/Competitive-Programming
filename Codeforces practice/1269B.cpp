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
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for(ll i=0;i<n;i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    set<ll> x;
    for(ll i=0;i<n;i++){
        x.insert((b[0] - a[i] + m) % m);
    }
    map<ll, ll> fa, fb;
    for(ll i=0;i<n;i++){
        fb[b[i]]++;
    }
    bool flag = false;
    ll ans = 0;
    for(ll xt : x){
        for(ll i=0;i<n;i++){
            fa[(a[i] + xt)%m]++;
        }
        if(fa == fb){
            ans = xt;
            break;
        }
        fa.clear();
    }
    cout << ans << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}