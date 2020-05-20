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
ll n, m;
char a[57][57];
bool vis[57][57][4][2], vis2[57][57];
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
void dfs(ll i, ll j, ll dirn, ll turns){
    if(turns > 1 || i > n || i < 1 || j > m || j < 1){
        return;
    }
    if(vis[i][j][dirn][turns] || a[i][j] == 'W'){
        return;
    }
    vis[i][j][dirn][turns] = 1;
    vis2[i][j] = 1;
    for(ll k=0;k<4;k++){
        dfs(i+dx[k], j+dy[k], k, turns + (k != dirn));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(a[i][j] == 'B'){
                memset(vis, false, sizeof(vis));
                memset(vis2, false, sizeof(vis2));
                vis2[i][j] = true;
                for(ll k=0;k<4;k++){
                    dfs(i+dx[k], j+dy[k], k, 0);
                }
                bool ok = true;
                for(ll x=1;x<=n;x++){
                    for(ll y=1;y<=m;y++){
                        if(a[x][y] == 'B'){
                            ok &= (vis2[x][y]);
                        }
                    }
                }
                if(!ok){
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}