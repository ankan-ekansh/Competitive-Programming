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
char a[1007][1007];
bool vis[1007][1007];
bool visi[1007][1007];
bool check(ll i, ll j){
    if(i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.'){
        return true;
    }
    return false;
}
ll bfs(ll x, ll y){
    ll ans = 1;
    visi[x][y] = true;
    queue<pair<ll, ll>> q;
    q.push({x, y});
    while(!q.empty()){
        pair<ll, ll> u = q.front();
        q.pop();
        ll i = u.first;
        ll j = u.second;
        if(check(i-1, j) && !visi[i-1][j] && vis[i-1][j]){
            q.push({i-1, j});
            visi[i-1][j] = true;
            ans++;
        }
        if(check(i+1, j) && !visi[i+1][j] && vis[i+1][j]){
            q.push({i+1, j});
            visi[i+1][j] = true;
            ans++;
        }
        if(check(i, j-1) && !visi[i][j-1] && vis[i][j-1]){
            q.push({i, j-1});
            visi[i][j-1] = true;
            ans++;
        }
        if(check(i, j+1) && !visi[i][j+1] && vis[i][j+1]){
            q.push({i, j+1});
            visi[i][j+1] = true;
            ans++;
        }
        if(check(i+1, j+1) && !visi[i+1][j+1] && vis[i+1][j+1]){
            q.push({i+1, j+1});
            visi[i+1][j+1] = true;
            ans++;
        }
        if(check(i-1, j+1) && !visi[i-1][j+1] && vis[i-1][j+1]){
            q.push({i-1, j+1});
            visi[i-1][j+1] = true;
            ans++;
        }
        if(check(i-1, j-1) && !visi[i-1][j-1] && vis[i-1][j-1]){
            q.push({i-1, j-1});
            visi[i-1][j-1] = true;
            ans++;
        }
        if(check(i+1, j-1) && !visi[i+1][j-1] && vis[i+1][j-1]){
            q.push({i+1, j-1});
            visi[i+1][j-1] = true;
            ans++;
        }
    }
    return ans;
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
    for(ll i=0;i<n;i++){
        string s;
        cin >> s;
        for(ll j=0;j<m;j++){
            a[i][j] = s[j];
        }
    }
    vector<pair<ll, ll>> p;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(a[i][j] == '#'){
                if(check(i-1, j) && !vis[i-1][j]){
                    p.push_back({i-1, j});
                    vis[i-1][j] = true;
                }
                if(check(i+1, j) && !vis[i+1][j]){
                    p.push_back({i+1, j});
                    vis[i+1][j] = true;
                }
                if(check(i, j-1) && !vis[i][j-1]){
                    p.push_back({i, j-1});
                    vis[i][j-1] = true;
                }
                if(check(i, j+1) && !vis[i][j+1]){
                    p.push_back({i, j+1});
                    vis[i][j+1] = true;
                }
                if(check(i+1, j+1) && !vis[i+1][j+1]){
                    p.push_back({i+1, j+1});
                    vis[i+1][j+1] = true;
                }
                if(check(i-1, j+1) && !vis[i-1][j+1]){
                    p.push_back({i-1, j+1});
                    vis[i-1][j+1] = true;
                }
                if(check(i-1, j-1) && !vis[i-1][j-1]){
                    p.push_back({i-1, j-1});
                    vis[i-1][j-1] = true;
                }
                if(check(i+1, j-1) && !vis[i+1][j-1]){
                    p.push_back({i+1, j-1});
                    vis[i+1][j-1] = true;
                }
            }
        }
    }
    ll ans;
    if(p.size() == 0){
        ans = 0;
    }
    else{
        ans = 1;
    }
    for(ll i=0;i<p.size();i++){
        if(!visi[p[i].first][p[i].second]){
            // for(ll i=0;i<n;i++){
            //     for(ll j=0;j<m;j++){
            //         cout << vis[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
            ans = max(ans, bfs(p[i].first, p[i].second));
            // for(ll i=0;i<n;i++){
            //     for(ll j=0;j<m;j++){
            //         cout << visi[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}