/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 501;
ll adj[MAX][MAX];
ll dp[MAX][MAX];
ll n;
const ll INF = 0x3f3f3f3f;
bool ok[MAX];
vector<ll> query;
vector<ll> ans;
// void init(ll x){
//     // for(ll i=1;i<=n;i++){
//     //     for(ll j=1;j<=n;j++){
//     //         dp[i][j] = adj[i][j];
//     //     }
//     // }
//     for(ll i=1;i<=n;i++){
//         dp[i][x] = adj[i][x];
//         dp[x][i] = adj[x][i];
//     }
// }
void fun(ll k){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
}
ll eval(){
    ll s = 0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(ok[i] && ok[j])
                s += dp[i][j];
        }
    }
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin >> adj[i][j];
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            dp[i][j] = adj[i][j];
        }
    }
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        query.push_back(x);
    }
    reverse(query.begin(), query.end());
    for(ll x : query){
        // init(x);
        ok[x] = true;
        fun(x);
        // cout << eval() << " ";
        ans.push_back(eval());
    }
    reverse(ans.begin(), ans.end());
    for(ll sum : ans){
        cout << sum << " ";
    }
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}