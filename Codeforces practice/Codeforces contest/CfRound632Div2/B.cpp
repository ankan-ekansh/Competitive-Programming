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
 
        ll n;
        cin >> n;
        ll a[n], b[n];
        ll pos[n] = {0}, neg[n] = {0};
        cin >> a[0];
        if(a[0] > 0){
            pos[0] = 1;
        }
        else if(a[0] < 0){
            neg[0] = 1;
        }
        for(ll i=1;i<n;i++){
            cin >> a[i];
            if(a[i] > 0){
                pos[i] = pos[i-1] + 1;
                neg[i] = neg[i-1];
            }
            else if(a[i] < 0){
                neg[i] = neg[i-1] + 1;
                pos[i] = pos[i-1];
            }
            else{
                pos[i] = pos[i-1];
                neg[i] = neg[i-1];
            }
        }
        for(ll i=0;i<n;i++){
            cin >> b[i];
        }
        // for(ll i=0;i<n;i++){
        //     cout << pos[i] << " " << neg[i] << "\n";
        // }
        bool ok = true;
        if(a[0] != b[0]){
            cout << "NO\n";
            continue;
        }
        for(ll i=n-1;i>=1;i--){
            if(b[i] > a[i] && pos[i-1] > 0){
                continue;
            }
            else if(b[i] < a[i] && neg[i-1] > 0){
                continue;
            }
            else if(a[i] == b[i]){
                continue;
            }
            else{
                ok = false;

                // cout << i << " -----" << pos[i-1] << " " << neg[i-1] << "\n";
                break;
            }
        }
        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}