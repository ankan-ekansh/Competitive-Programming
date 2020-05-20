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
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        int n;
        cin >> n;
        map<pair<int, int>, int> m;
        vector<pair<int, int>> v;
        string s;
        cin >> s;
        pair<int, int> p = {0, 0};
        m[p]++;
        for(int i=0;i<n;i++){
            if(s[i] == 'U')
                p.second++;
            if(s[i] == 'D')
                p.second--;
            if(s[i] == 'L')
                p.first--;
            if(s[i] == 'R')
                p.first++;
            if(m[p]){
                ll x = m[p];
                v.push_back({x, i+1});
            }
            m[p] = i + 2;
        }
        if(v.size() == 0){
            cout << "-1\n";
        }
        else{
            ll ans = LLONG_MAX;
            ll left = -1, right = -1;
            for(int i=0;i<v.size();i++){
                if(v[i].second - v[i].first < ans){
                    left = v[i].first;
                    right = v[i].second;
                    ans = right - left;
                }
            }
            cout << left << " " << right << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}