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
 
        ll n, s, k;
        cin >> n >> s >> k;
        ll ans = 0, ans2 = 0, a[k];
        map<ll, ll> m;
        for(ll i=0;i<k;i++){
            cin >> a[i];
            m[a[i]] = 1;
        }
        bool flag1 = false, flag2 = false;
        for(ll i=s;i>=1;i--){
            if(m[i] == 0){
                flag1 = true;
                break;
            }
            else{
                ans++;
            }
        }
        for(ll i=s;i<=n;i++){
            if(m[i] == 0){
                flag2 = true;
                break;
            }
            else{
                ans2++;
            }
        }
        // cout << ans << " " << ans2 << "\n";
        // cout << flag1 << " " << flag2 << "\n";
        if(flag1 == true && flag2 == false){
            cout << ans << "\n";
        }
        else if(flag1 == false && flag2 == true){
            cout << ans2 << "\n";
        }
        else if(flag1 == true && flag2 == true){
            cout << min(ans, ans2) << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}