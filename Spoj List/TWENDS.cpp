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
int a[1001];
int dp[1001][1001];
int fun(int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i == j){
        return dp[i][j] = a[i];
    }
    if(j == i+1){
        return dp[i][j] = max(a[i], a[j]);
    }
    //return dp[i][j] = max(dp[i][j], max( max(a[i] + fun(i+1, j-1), a[i] + fun(i+2, j) ) , max(a[j] + fun(i, j-2), a[j] + fun(i+1, j-1))));
    // return dp[i][j] = max(dp[i][j], max(max(a[i]+fun(i+1,j-1), a[i]+fun(i+2,j)), max(a[j]+fun(i,j-2), a[j]+fun(i+1,j-1))));
    // if(a[i+1] < a[j] && a[i] > a[j]){
    //     return dp[i][j] = max(dp[i][j], a[i]+fun(i+1,j-1));
    // }
    // else if(a[i+1] >= a[j] && a[i] > a[j]){
    //     return dp[i][j] = max(dp[i][j], a[i]+fun(i+2,j));
    // }
    // if(a[i] < a[j-1] && a[j] > a[i]){
    //     return dp[i][j] = max(dp[i][j], a[j]+fun(i,j-2));
    // }
    // else if(a[i] < a[j-1] && a[j] > a[i]){
    //     return dp[i][j] = max(dp[i][j], a[j]+fun(i+1,j-1));
    // }
    return dp[i][j] = max(dp[i][j], max(a[i]+fun()))
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int k = 1;
    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        int s = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            s+=a[i];
        }
        memset(dp, -1, sizeof(dp));
        int a1 = fun(1, n);
        int i = 1, j = n;
        int a2 = s - a1;
        // while(i <= j){
        //     if(a[i] > a[j]){
        //         a2+=a[i];
        //         i++;
        //     }
        //     else{
        //         a2+=a[j];
        //         j--;
        //     }
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        cout << a1 << " " << a2 << "\n";
        cout << "In game " << k << ", the greedy strategy might lose by as many as " << a1-a2 << " points.\n";
        k++;
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}