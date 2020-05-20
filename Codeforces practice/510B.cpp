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
bool ok;
vector<vector<bool>> vis(57, vector<bool>(57));
vector<vector<char>> a(57, vector<char>(57));
vector<vector<ll>> dis(57, vector<ll>(57));
bool check(ll i, ll j){
    return (i >=0 && i < n && j >=0 && j < m);
}
void dfs(ll i, ll j, vector<vector<bool>> &v, vector<vector<ll>> &d){
    // cout << i << " " << j << " " << a[i][j] << " " << s << "\n";
    v[i][j] = true;
    if(check(i+1, j)){
        if(a[i][j] == a[i+1][j]){
            if(!v[i+1][j]){
                d[i+1][j] = d[i][j] + 1;
                dfs(i+1, j, v, d);
            }
            else if((d[i+1][j] - d[i][j]) >= 3){
                ok = true;
                // cout << "---1\n";
            }
        }
    }
    if(check(i, j+1)){
        if(a[i][j] == a[i][j+1]){
            if(!v[i][j+1]){
                d[i][j+1] = d[i][j] + 1;
                dfs(i, j+1, v, d);
            }
            else if((d[i][j+1] - d[i][j]) >= 3){
                ok = true;
                // cout << "---2\n";
            }
        }
    }
    if(check(i-1, j)){
        if(a[i][j] == a[i-1][j]){
            if(!v[i-1][j]){
                d[i-1][j] = d[i][j] + 1;
                dfs(i-1, j, v, d);
            }
            else if((d[i-1][j] - d[i][j]) >= 3){
                ok = true;
                // cout << "---3\n";
            }
        }
    }
    if(check(i, j-1)){
        if(a[i][j] == a[i][j-1]){
            if(!v[i][j-1]){
                d[i][j-1] = d[i][j] + 1;
                dfs(i, j-1, v, d);
            }
            else if((d[i][j-1] - d[i][j]) >= 3){
                ok = true;
                // cout << "---4\n";
            }
        }
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
    map<char, vector<pair<ll, ll>>> mp;
    for(ll i=0;i<n;i++){
        string s;
        cin >> s;
        for(ll j=0;j<m;j++){
            a[i][j] = s[j];
            mp[a[i][j]].push_back({i, j});
        }
    }
    // dfs(0, 0, vis);
    ok = false;
    for(auto p : mp){
        // dis.assign(0, vector<ll>(57));
        // vis.assign(false, vector<bool>(57));
        fill(dis.begin(), dis.end(), vector<ll>(57, 0));
        fill(vis.begin(), vis.end(), vector<bool>(57, false));
        // if(!ok){
        //     dfs(p.second.first, p.second.second, vis, dis);
        // }
        // else{
        //     break;
        // }
        if(!ok){
            for(auto vec : p.second){
                dfs(vec.first, vec.second, vis, dis);
            }
        }
        else{
            break;
        }
    }
    if(ok){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}