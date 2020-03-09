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
int n, m;
int a[183][183];
// bool vis[183][183];
int dis[183][183];
int ans[183][183];
bool check(int i, int j, bool vis[183][183]){
    if(i>=0 && i<n && j>=0 && j<m && !vis[i][j]){
        return true;
    }
    else{
        return false;
    }
}
queue<pair<int, int>> q;
bool vis[183][183];
void bfs(int i, int j){
    // bool vis[183][183];
    // memset(vis, false, sizeof(vis));
    vis[i][j] = true;
    dis[i][j] = 0;
    // q.push(make_pair(i, j));
    while(!q.empty()){
        pair<int, int> p;
        p = q.front();
        q.pop();
        int ui = p.first;
        int uj = p.second;
        // if(a[ui][uj] == 1){
        //     // cout << i << " " << j << " : " << dis[ui][uj] << "\n";
        //     return dis[ui][uj];
        // }
        if(check(ui, uj-1, vis)){
            vis[ui][uj-1] = true;
            dis[ui][uj-1] = min(dis[ui][uj-1], dis[ui][uj] + 1);
            q.push(make_pair(ui, uj-1));
        }
        if(check(ui, uj+1, vis)){
            vis[ui][uj+1] = true;
            dis[ui][uj+1] = min(dis[ui][uj+1], dis[ui][uj] + 1);
            q.push(make_pair(ui, uj+1));
        }
        if(check(ui-1, uj, vis)){
            vis[ui-1][uj] = true;
            dis[ui-1][uj] = min(dis[ui-1][uj], dis[ui][uj] + 1);
            q.push(make_pair(ui-1, uj));
        }
        if(check(ui+1, uj, vis)){
            vis[ui+1][uj] = true;
            dis[ui+1][uj] = min(dis[ui+1][uj], dis[ui][uj] + 1);
            q.push(make_pair(ui+1, uj));
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
 
        cin >> n >> m;
        //memset(dis, INT_MAX, sizeof(dis));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         dis[i][j] = INT_MAX;
        //     }
        // }
        // cout << dis[0][0] << "\n";
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(int j=0;j<m;j++){
                a[i][j] = (int)(s[j]-'0');
                dis[i][j] = 1000;
                if(a[i][j] == 1){
                    v.push_back(make_pair(i, j));
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         ans[i][j] = bfs(i, j);
        //     }
        // }
        for(int i=0;i<v.size();i++){
            // cout << v[i].first << " " << v[i].second << "\n";
            bfs(v[i].first, v[i].second);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << dis[i][j] << " ";
            }
            cout << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}