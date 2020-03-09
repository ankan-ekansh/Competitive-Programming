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
template <typename T>
T myMax(T a, T b){
    return (a > b)? a : b;
}
int dp[1007][1007];
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
 
        int a[1007];
        int la = 0;
        int x;
        cin >> x;
        if(x == 0){
            continue;
        }
        while(x){
            a[la++] = x;
            cin >> x;
        }
        int b[1007];
        int lb = 0;
        cin >> x;
        int ans = 0;
        while(1){
            lb = 0;
            if(x == 0){
                break;
            }
            while(x){
                b[lb++] = x;
                cin >> x;
            }
            for(int i=0;i<=la;i++){
                for(int j=0;j<=lb;j++){
                    if(i == 0 || j == 0){
                        dp[i][j] = 0;
                    }
                    else if(a[i-1] == b[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = myMax(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            // for(int i=0;i<=la;i++){
            //     for(int j=0;j<=lb;j++){
            //         cout << dp[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << dp[la][lb] << "\n";
            ans = max(ans, dp[la][lb]);
            cin >> x;
        }
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}