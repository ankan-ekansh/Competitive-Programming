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
bool comp(pair<int, int> p1, pair<int, int> p2){
    return (p1.first > p2.first) || (p1.first == p2.first && p1.second < p2.second);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        int p, t;
        cin >> p >> t;
        v.push_back(make_pair(p, t));
    }
    map<pair<int, int>, int> m;
    
    sort(v.begin(), v.end(), comp);
    for(int i=0;i<n;i++){
        // cout << v[i].first << " " << v[i].second << "\n";
        m[make_pair(v[i].first, -v[i].second)]++;
    }
    int l=1;
    int a[n+10];
    memset(a, 0, sizeof(a));
    for(auto i=m.rbegin();i!=m.rend();i++){
        // cout << (*i).first.first << " " << (*i).first.second << " " << (*i).second << "\n";
        for(int j=1;j<=(*i).second;j++){
            a[l++] = (*i).second;
        }

    }
    // for(int i=1;i<=n;i++){
    //     cout << a[i] << "\n";
    // }
    cout << a[k] << "\n";
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}