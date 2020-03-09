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
 
        ll p, m, n;
        cin >> p >> m >> n;
        ll p_s, p_ns, c_s, c_ns;
        ll k = n/m;
        // cout << "k = " << k << "\n";
        if(n % m == 0){
            c_s = (k-1)*m + 2;
            cout << c_s << "\n";
        }
        else{
            p_ns = (k-1)*m + 2;
            c_s = k*m + 3;
            if(c_s >= p){
                // while(c_s >= p){
                //     k--;
                //     c_s = k*m + 2;
                // }
                // c_s = k*(((p-2)/m)*k) + 2;
                ll x = ((p-2)/m);
                c_s = x*m + 2;
                while(c_s >= p){
                    x--;
                    c_s = x*m + 2;
                }
                cout << c_s << "\n";
                continue;
            }
            // cout << "n % m = " << n % m << "\n";
            // cout << "Before iterations c_s : " << c_s << "\n";
            for(ll i=1;i<(n%m);i++){
                c_s++;
            }
            // cout << "After iterations c_s : " << c_s <<"\n";
            if(c_s <= p){
                cout << c_s << "\n";
            }
            else{
                cout << k*m + 2 << "\n";
            }
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}