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
bool check(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m){
        return true;
    }
    else{
        return false;
    }
}
queue<pair<int, int>> q;
void bfs(int i, int j){
    dis[i][j] = 0;
    q.push(make_pair(i, j));
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
        // cout << a[ui][uj] << " " << ui << " " << uj << "\n";
        if(check(ui, uj-1) && dis[ui][uj]+1 < dis[ui][uj-1]){
            dis[ui][uj-1] = (dis[ui][uj] + 1);
            q.push(make_pair(ui, uj-1));
        }
        if(check(ui, uj+1) && dis[ui][uj]+1 < dis[ui][uj+1]){
            dis[ui][uj+1] = (dis[ui][uj] + 1);
            q.push(make_pair(ui, uj+1));
        }
        if(check(ui-1, uj) && dis[ui][uj]+1 < dis[ui-1][uj]){
            dis[ui-1][uj] = (dis[ui][uj] + 1);
            q.push(make_pair(ui-1, uj));
        }
        if(check(ui+1, uj) && dis[ui][uj]+1 < dis[ui+1][uj]){
            dis[ui+1][uj] = (dis[ui][uj] + 1);
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
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            for(int j=0;j<m;j++){
                a[i][j] = (int)(s[j]-'0');
                if(a[i][j] == 0)
                    dis[i][j] = 10000;
                else
                    dis[i][j] = 0;
                
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
            // vis[v[i].first][v[i].second] = true;
            bfs(v[i].first, v[i].second);
            // q.push(make_pair(v[i].first, v[i].second));
        }
        // bfs(v[0].first, v[0].second);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << dis[i][j] << " ";
            }
            cout << "\n";
        }
        // cout << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}