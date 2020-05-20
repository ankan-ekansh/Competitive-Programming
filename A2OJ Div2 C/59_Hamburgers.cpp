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
string s;
ll hb, hc, hs;
ll nb = 0, ns = 0, nc = 0;
ll cb, cs, cc;
ll burgers = 0;
ll r;
ll x;
ll fun(ll x){
    return max(0LL, (nb*x) - hb)*(cb) + max(0LL, (ns*x) - hs)*(cs) + max(0LL, (nc*x) - hc)*(cc);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> s;
    
    for(ll i=0;i<s.length();i++){
        if(s[i] == 'B'){
            nb++;
        }
        if(s[i] == 'S'){
            ns++;
        }
        if(s[i] == 'C'){
            nc++;
        }
    }
    // cout << nb << " " << ns << " " << nc << "\n";
    
    
    cin >> hb >> hs >> hc;
    // burgers = hb/nb;
    // burgers = min(burgers, min(hs/ns, hc/nc));
    // hb = hb - burgers*nb;
    // hc = hc - burgers*nc;
    // hs = hs - burgers*ns;
    // cout << hb << " " << hs << " " << hc << "\n";
    // cout << "Burgers till now = " << burgers << "\n";
    
    cin >> cb >> cs >> cc;
    
    cin >> r;
    ll mnm = 0, mxm = 1e14;
    while(mnm <= mxm){
        x = mnm + (mxm - mnm)/2;
        // cout << x << " " << max(0LL, nb*x - hb)*(cb) + max(0LL, ns*x - hs)*(cs) + max(0LL, nc*x - hc)*(cc) << "\n";
        // if(max(0LL, nb*x - hb)*(cb) + max(0LL, ns*x - hs)*(cs) + max(0LL, nc*x - hc)*(cc) > r){
        //     mxm = x - 1;
        // }
        // else if(max(0LL, nb*x - hb)*(cb) + max(0LL, ns*x - hs)*(cs) + max(0LL, nc*x - hc)*(cc) == r){
        //     // mnm = x;
        //     break;
        // }
        // else if(max(0LL, nb*x - hb)*(cb) + max(0LL, ns*x - hs)*(cs) + max(0LL, nc*x - hc)*(cc) < r){
        //     mnm = x + 1;
        // }
        if(fun(x) > r){
            mxm = x-1;
        }
        else if(fun(x) == r){
            // cout << " --------- " << "\n";
            break;
        }
        else{
            mnm = x+1;
        }
    }
    if(mnm > mxm){
        swap(mnm, mxm);
    }
    // cout << mnm << " " << x << " " << mxm << "\n";
    if(fun(mxm) <= r){
        cout << mxm << "\n";
    }
    else if(fun(x) <= r){
        cout << x << "\n";
    }
    else if(fun(mnm) <= r){
        cout << mnm << "\n";
    }
    // cout << fun(1000000000001) << "\n";
    // cout << fun(1000000000100) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}