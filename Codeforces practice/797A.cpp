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
    
    ll n, k;
    cin >> n >> k;
    vector<ll> f;
    ll t = n;
    while(t % 2 == 0){
        f.push_back(2);
        t/=2;
    }
    for(ll i=3;i*i<=t;i+=2){
        while(t % i == 0){
            f.push_back(i);
            t/=i;
        }
    }
    if(t > 1){
        f.push_back(t);
    }
    while(f.size() > k){
        ll tmp = f.back();
        f.pop_back();
        *f.rbegin() = *f.rbegin() * tmp;
    }
    if(f.size() != k){
        cout << "-1\n";
    }
    else{
        for(ll x : f){
            cout << x << " "; 
        }
        cout << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}