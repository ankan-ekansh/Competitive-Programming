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
    
    ll n;
    cin >> n;
    vector<ll> a;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    map<ll, bool> m1, m2;
    set<ll> mi, ma;
    for(ll i=0;i<n;i++){
        if(m1[a[i] - 1] == true){
            mi.insert(a[i] - 1);
        }
        else if(m1[a[i]] == true){
            mi.insert(a[i]);
        }
        else if(m1[a[i] + 1] == true){
            mi.insert(a[i] + 1);
        }
        else{
            mi.insert(a[i] + 1);
            m1[a[i] + 1] = true;
        }
    }
    for(ll i=0;i<n;i++){
        if(m2[a[i] - 1] == false){
            ma.insert(a[i] - 1);
            m2[a[i] - 1] = true;
        }
        else if(m2[a[i]] == false){
            ma.insert(a[i]);
            m2[a[i]] = true;
        }
        else if(m2[a[i] + 1] == false){
            ma.insert(a[i] + 1);
            m2[a[i] + 1] = true;
        }
    }
    cout << mi.size() << " " << m2.size() << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}