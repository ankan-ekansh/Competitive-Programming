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
    
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int j=0;j<m;j++){
        cin >> b[j];
    }
    int ans = 0;
    int rs = 1;
    while(rs <= k){
        if(k % rs != 0){
            rs++;
            continue;
        }
        int cs = k/rs;
        // cout << "Rs " << rs << "\n";
        // cout << "Cs " << cs << "\n";
        for(int i=0;i<=n-rs;i++){
            bool f = true;
            // cout << "Row = ";
            for(int j=i;j<=i+rs-1;j++){
                // cout << j << " ";
                if(a[j] != 1){
                    f = false;
                    break;
                }
            }
            // cout << "\n";
            if(f){
                for(int h=0;h<=m-cs;h++){
                    bool g = true;
                    // cout << "Col = ";
                    for(int j=h;j<=m-cs;j++){
                        // cout << j << " ";
                        if(b[j] != 1){
                            g = false;
                            break;
                        }
                    }
                    // cout << "\n";
                    if(g){
                        ans++;
                    }
                }
            }
        }
        rs++;
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}