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
    ll a[n];
    map<ll, ll> s;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        s[a[i]]++;
    }
    ll left = 0, right = n-1;
    while(s.size() >= k){
        if(s[a[right]] == 1){
            s.erase(a[right]);
        }
        else{
            s[a[right]]--;
        }
        right--;
    }
    right++;
    s[a[right]]++;
    // cout << right << " " << s.size() << "\n";
    // if(s[a[right]] == 0){
    //     s[a[right]]++;
    //     right++;
    // }
    // cout << s.size() << "\n";
    while(s.size() == k){
        if(s[a[left]] == 1){
            s.erase(a[left]);
        }
        else{
            s[a[left]]--;
        }
        left++;
    }
    if(left <= right+1 && left >= 1 && left <=n && right+1 >=1 && right+1 <=n)
        cout << left << " " << right+1 << "\n";
    else
        cout << "-1 -1\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}