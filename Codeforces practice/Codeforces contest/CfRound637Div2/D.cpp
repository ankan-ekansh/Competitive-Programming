/*

    Do iterative soln later

*/


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
int n, k;
vector<string> digit(10);
int change[2007][11];
int dp[2007][2007][11];
int fun(int idx, int sum, int d){
    if(idx == n){
        if(sum == 0){
            return dp[idx][sum][d] = 1;
        }
        else{
            return dp[idx][sum][d] = 0;
        }
    }
    if(sum < 0){
        return dp[idx][sum][d] = 0;
    }
    if(dp[idx][sum][d] != -1){
        return dp[idx][sum][d];
    }
    int optimal_max = 0;
    for(int di=9;di>=0;di--){
        int count = change[idx][di];
        if(count != -1 && count <= sum){
            optimal_max = max(optimal_max, fun(idx+1, sum-count, di));
        }
    }
    return dp[idx][sum][d] = optimal_max;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    digit[0]=("1110111");
    digit[1]=("0010010");
    digit[2]=("1011101");
    digit[3]=("1011011");
    digit[4]=("0111010");
    digit[5]=("1101011");
    digit[6]=("1101111");
    digit[7]=("1010010");
    digit[8]=("1111111");
    digit[9]=("1111011");

    cin >> n >> k;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int d = 0; d <= 9; d++){
            int count = 0;
            for(int i = 0; i < 7; i++){
                if(str[i] == '0' && digit[d][i] == '1'){
                    count++;
                }
                else if(str[i] == '1' && digit[d][i] == '0'){
                    count = -1;
                    break;
                }
            }
            change[i][d] = count;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int d=0;d<=9;d++){
    //         cout << change[i][d] << " ";
    //     }
    //     cout << "\n";
    // }
    memset(dp, -0x1, sizeof(dp));
    int ok = fun(0, k, 0);
    // cout << ok << "\n";
    if(!ok){
        cout << "-1\n";
    }
    else{
        int start = 0, sum = k;
        while(start < n){
            for(int d=9;d>=0;d--){
                int count = change[start][d];
                if(sum - count >= 0 && count != -1 && dp[start+1][sum - count][d] == 1){
                    cout << d;
                    start = start + 1;
                    sum = sum - count;
                    break;
                }
            }
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}