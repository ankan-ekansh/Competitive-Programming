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
    
    int n;
    cin >> n;
    int a[n+7];
    int s[n+7] = {0};
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int ans;
    if(a[1] == 1){
        s[1] = 1;
        ans = 0;
    }
    else{
        s[1] = 0;
        ans = 1;
    }
    for(int i=2;i<=n;i++){
        if(a[i] == 0){
            s[i] = s[i-1];
        }
        else{
            s[i] = s[i-1] + 1;
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << s[i] << " ";
    // }
    // cout << "\n";
    if(n == 1){
        if(a[1] == 1){
            cout << "0\n";
        }
        else{
            cout << "1\n";
        }
        exit(0);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            // cout << "1 to " << i << " " << s[i] << "\n";
            // cout << "1 to " << j << " " << s[j] << "\n";
            // cout << "1 to " << n << " " << s[n] << "\n";
            // cout << j << " to " << n << " " << s[n] - s[j-1] << "\n";
            // cout << i << " to " << j << " " << s[j] - s[i-1] << "\n";
            ans = max(ans, s[i] + s[n] - s[j-1] + max(s[j] - s[i-1], j-i+1 - s[j] + s[i-1]));
            // cout << ans << "\n";
        }
    }
    if(ans > n){
        ans = 0;
    }
    cout << ans << "\n";
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}