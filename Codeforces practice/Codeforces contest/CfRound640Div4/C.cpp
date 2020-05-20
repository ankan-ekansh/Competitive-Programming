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
 
        ll n, k;
        cin >> n >> k;
        ll l = 1, r = 1e16;
        ll mid;
        while(l <= r){
            mid = (l+r)/2;
            // cout << mid << "\n";
            if(mid % n == 0){
                mid++;
            }
            ll prev_muls = mid/n;
            if((mid - prev_muls) == k){
                // cout << mid << "\n";
                // r = mid;
                // if(mid % n != 0)
                    break;
                // else
                    // r = mid;
            }
            else if(mid - prev_muls < k){
                l = mid + 1;
            }
            else if(mid - prev_muls > k){
                r = mid - 1;
            }
        }
        if(l > r){
            swap(l, r);
        }
        // cout << l << " " << mid << " " << r << "\n";
        // if(mid % n == 0){
        //     cout << l << "\n";
        // }
        // else{
        //     cout << mid << "\n";
        // }
        cout << mid << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}