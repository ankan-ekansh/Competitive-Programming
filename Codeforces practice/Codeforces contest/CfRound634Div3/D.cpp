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
    int t;
    cin>>t;
    while(t--){
 
        ll x;
        ll a[10][10];
        ll fr[10] = {0};
        ll fc[10] = {0};
        // memset(f, 0, sizeof(f));
        for(ll i=1;i<=9;i++){
            bool flag = false;
            string s;
            cin >> s;
            for(ll j=1;j<=9;j++){
                x = s[j-1] - '0';
                a[i][j] = x;
                if(x == 1){
                    fr[i]=1;
                    fc[j]=1;
                }
                // if(i % 3 == 1 && j % 3 == 1){
                //     if(x != 1)
                //         cout << "1";
                //     else{
                //         cout << x;
                //         cout << "1";
                //         j++;
                //     }
                // }
                // else{
                //     cout << x;
                // }
            }
            // cout << "\n";
        }
        ll tries = 9;
        for(ll i=1;i<=9;i++){
            for(ll j=1;j<=9;j++){
                if(((i == 1 && j == 1) || (i == 2 && j == 4) || (i == 3 && j == 7) || (i == 4 && j == 2) || (i == 5 && j == 5) || (i == 6 && j == 8) || (i == 7 && j == 3) || (i == 8 && j == 6) || (i == 9 && j == 9) )){
                    cout << (a[i][j] + 1)%9 + 1;
                }
                else{
                    cout << a[i][j];
                }
            }
            cout << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}