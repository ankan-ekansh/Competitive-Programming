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
// ll a[1007][1007];
bool vis[1007][1007];
ll n;
vector<pair<ll, ll>> p;
bool r[1007], c[1007];
// bool check(ll i, ll j){
//     if(i >= 1 && i <= m && j >= 1 && j <= n){
//         return true;
//     }
//     return false;
// }
// void bfs(pair<ll, ll> s){
//     queue<pair<ll, ll>> q;
//     q.push(s);
//     vis[s.first][s.second] = true;
//     while(!q.empty()){
//         pair<ll, ll> u = q.front();
//         ll ux = u.first;
//         ll uy = u.second;
//         ll uux = ux, uuy = uy;
//         for(ll i=0;i<4;i++){
//             uux = uux + dr[i];
//             uuy = uuy + dc[i];
//             if(check(uux, uuy) && !vis[uux][uuy]){

//             }
//         }
//     }
// }
void dfs(pair<ll, ll> s){
    vis[s.first][s.second] = true;
    ll px = s.first;
    ll py = s.second;
    for(ll i=0;i<n;i++){
        if(!vis[p[i].first][p[i].second] && (p[i].first == px || p[i].second == py)){
            dfs(p[i]);
        }
    }
}
// void fun(ll x, ll y){
//     r[x] = true;
//     c[y] = true;
// }
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(ll i=0;i<n;i++){
        ll x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    ll ct = 0;
    for(ll i=0;i<n;i++){
        ll px = p[i].first;
        ll py = p[i].second;
        if(!vis[px][py]){
            ct++;
            dfs(p[i]);
        }
    }     
    cout << ct - 1 << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}