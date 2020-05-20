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
pair<ll, ll> plot(pair<ll, ll> p, char c){
    if(c == 'U'){
        p.second+=1;
    }    
    else if(c == 'D'){
        p.second-=1;
    }
    else if(c == 'L'){
        p.first-=1;
    }
    else{
        p.first+=1;
    }
    return p;
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
 
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll k = 0;
        pair<ll, ll> curr = {0, 0};
        pair<ll, ll> points[n+7];
        for(ll i=1;i<=n;i++){
            points[i] = plot(curr, s[i-1]);
            curr = points[i-1];
        }
        ll l = 1;
        ll r = n;
        ll left = -1;
        ll right = -1;
        ll a = 1000000000;
        while(l != r){
            ll mid = l + (r - l)/2;
            if(points[l] == points[mid]){
                r = mid;
                if(a > mid - l + 1){
                    a = mid - l + 1;
                    left = l;
                    right = mid;
                }
            }
            else if(points[mid] == points[r]){
                l = mid;
                if(a > r - mid + 1){
                    a = r - mid + 1;
                    left = mid;
                    right = r;
                }
            }
            // else{
            //     l = mid;
            // }
        }
        cout << left << " " << right << " " << a << "\n";

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}