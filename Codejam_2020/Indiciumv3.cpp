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

int mat[51][51], n, k, t;
bool rs[51][51], cs[51][51], ok;
 
void fun(int r, int c, int m){
    if(r == n && c == n + 1 && m == k && !ok){
        ok = true;
        cout << "Case #" << t << ": " << "POSSIBLE\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }
    else if(r > n){
        return;
    }
    else if(c > n){
        fun(r + 1, 1, m);
    }
    for(int i = 1; i <= n && !ok; i++){
        if(!rs[r][i] && !cs[c][i]){
            rs[r][i] = cs[c][i] = true;
            if(r == c){
                m += i;
            }
            mat[r][c] = i;
 
            fun(r, c + 1, m);
 
            rs[r][i] = cs[c][i] = false;
            if(r == c){
                m -= i;
            }
            mat[r][c] = 0;
        }
    }
}
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(t = 1; t <= T; t++){
        cin >> n >> k;
        fun(1, 1, 0);
        if(!ok){
            cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
        }
        ok = false;
    }
    return 0;
}