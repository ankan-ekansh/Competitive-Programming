#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return binaryExponentiation(x*x,n/2);
    else
        return x*binaryExponentiation(x*x,(n-1)/2);
}
ll GCD(ll A, ll B){
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
ll modinv(ll a , ll mod){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
ll modPrimeInverse(ll A,ll M){
    return modularExponentiation(A,M-2,M);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> p(n);
    for(ll i=0;i<n;i++){
        cin >> p[i].second.first >> p[i].first;
        p[i].second.second = i;
    }
    sort(p.begin(), p.end());
    ll k;
    cin >> k;
    vector<pair<ll, ll>> cap(k);
    for(ll i=0;i<k;i++){
        cin >> cap[i].first;
        cap[i].second = i;
    }
    sort(cap.begin(), cap.end());
    ll cost = 0;
    map<ll, bool> taken;
    vector<pair<ll, ll>> ans;
    for(ll i=0;i<k;i++){
        // cout << "Table capacity : " << cap[i].first << " Table index " << cap[i].second << "\n";
        for(ll j=n-1;j>=0;j--){
            // cout << "Cash : " << p[j].first << " Crowd size " << p[j].second.first << " Request index " << p[j].second.second << "\n";
            if(p[j].second.first <= cap[i].first && !taken[p[j].second.second]){
                taken[p[j].second.second] = true;
                cost += p[j].first;
                ans.push_back({p[j].second.second+1, cap[i].second+1});
                break;
            }
        }
    }
    cout << ans.size() << " " << cost << "\n";
    for(ll i=0;i<ans.size();i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}