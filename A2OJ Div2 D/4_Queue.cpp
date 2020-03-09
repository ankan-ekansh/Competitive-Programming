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
    ll a[n+7];
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    // for(ll i=1;i<=n;i++){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    ll no = 0;
    ll s[n+7] = {0};
    s[1] = 0;
    // cout << s[1] << " " << a[1] << "\n";
    if(s[1] <= a[1]){
        no++;
    }
    ll prev = a[1];
    for(ll i=2;i<=n;i++){
        // s[i]=s[i-1]+a[i-1]-dec;
        // cout << s[i] << " " << a[i] << "\n";
        // if(s[i] <= a[i]){
        //     no++;
        // }
        // else{
        //     dec+=a[i];
        // }
        if((s[i-1] + prev) <= a[i]){
            s[i] = s[i-1] + prev;
            // cout << i << " " << s[i] << "\n";
            prev = a[i];
            no++;
        }
        else{
            s[i] = s[i-1];
        }
    }
    // cout << "\n";
    cout << no << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}