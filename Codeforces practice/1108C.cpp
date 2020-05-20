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
    
    ll n;
    cin >> n;
    vector<string> poss(6);

    char c[] = {'B', 'G', 'R'};
    // cout << c[0] << " " << c[1] << " " << c[2] << "\n";
    ll i = 0;
    do{
        // string s = c[0] + c[1] + c[2];
        string s = "BRG";
        s[0] = c[0];
        s[1] = c[1];
        s[2] = c[2];
        // cout << s << "\n";
        // cout << c[0] << " " << c[1] << " " << c[2] << "\n";
        // ll i = 0;
        for(ll j=0;j<n;j++){
            poss[i] += s;
        }
        i++;
    }
    while(next_permutation(c, c + 3));
    // for(ll i=0;i<6;i++){
    //     cout << poss[i] << "\n";
    // }
    ll mincost = LLONG_MAX;
    string s;
    cin >> s;
    ll idx = 0;
    for(ll i=0;i<6;i++){
        ll cost = 0;
        for(ll j=0;j<n;j++){
            if(s[j] != poss[i][j]){
                cost++;
            }
        }
        // mincost = min(mincost, cost);
        if(cost < mincost){
            idx = i;
            mincost = cost;
        }
    }
    cout << mincost << "\n";
    for(ll i=0;i<n;i++){
        cout << poss[idx][i];
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}