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
    
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll a[n+7] = {0}, b[n+7] = {0};
    if(s[0] == 'a'){
        a[1] = 1, b[1] = 0;
    }
    else{
        a[1] = 0, b[1] = 1;  
    }
    for(ll i=2;i<=n;i++){
        if(s[i-1] == 'a'){
            a[i] = a[i-1] + 1;
        }
        else
            a[i] = a[i-1];
    }
    for(ll i=2;i<=n;i++){
        if(s[i-1] == 'b'){
            b[i] = b[i-1] + 1;
        }
        else
            b[i] = b[i-1];
    }
    // for(ll i=1;i<=n;i++){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    // for(ll i=1;i<=n;i++){
    //     cout << b[i] << " ";
    // }
    // cout << "\n";
    ll l = 1, r = n;
    ll mid = 0;
    ll ans = 0;
    while(l <= r){
        mid = (l+r)/2;
        // cout << mid << "\n";
        bool flag = false;
        ll i=0, j=mid-1;
        while(j < n){
            if(a[j + 1] - a[i] <= k){   // replacing a's to create all b's in substring
                flag = true;
                // cout << mid << "\n";
                ans = max(ans, mid);
                break;
            }
            else if(b[j + 1] - b[i] <= k){  // replacing b's to create all a's in substring
                flag = true;
                // cout << mid << "\n";
                ans = max(ans, mid);
                break;
            }
            else{
                i++;
                j++;
            }
        }
        if(flag){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    // cout << mid << "\n";
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}