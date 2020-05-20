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
int n;
bool check(int i, int j){
    if(i >=1 && i <= 2 && j >= 1 && j <= n){
        return true;
    }
    else if((j == 0 && i == 1) || (j == n+1 && i == 2)){
        return true;
    }
    return false;
}
int a[3][300007];
bool vis[3][300007];
void bfs(){
    queue<pair<int, int>> q;
    memset(vis, false, sizeof(vis));
    q.push({1, 0});
    vis[1][0] = true;
    while(!q.empty()){
        pair<int, int> p = q.front();
        int pi = p.first;
        int pj = p.second;
        if(a[pi][pj] == 1 || a[pi][pj] == 2){
            if(check(pi-1, pj)){
                if(a[pi-1][pj] != 1 && a[pi-1][pj] != 2 && !vis[pi-1][pj]){
                    vis[pi-1][pj] = true;
                    q.push({pi-1, pj});
                }
            }
            if(check(pi+1, pj)){
                if(a[pi+1][pj] != 1 && a[pi+1][pj] != 2 && !vis[pi+1][pj]){
                    vis[pi+1][pj] = true;
                    q.push({pi+1, pj});
                }
            }
            
        }
        else{

        }
    }
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
 
        cin >> n;

 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}