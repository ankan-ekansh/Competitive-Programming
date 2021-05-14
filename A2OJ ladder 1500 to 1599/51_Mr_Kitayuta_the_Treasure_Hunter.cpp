/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
int n, d;
int a[30001];
int mxm;
// int dp[30001][3001];
unordered_map<pair<int, int>, int, hash_pair> dp;
int solve(int i, int c){
    if(i > mxm){
        // return dp[i][c] = 0;
        return dp[{i, c}] = 0;
    }
    if(dp.find({i, c}) != dp.end()){
        return dp[{i, c}];
    }
    if(c == 1){
        return dp[{i, c}] = a[i] + max(solve(i+c, c), solve(i+c+1, c+1));
    }
    int ch1 = a[i] + solve(i+c-1, c-1);
    int ch2 = a[i] + solve(i+c, c);
    int ch3 = a[i] + solve(i+c+1, c+1);
    return dp[{i, c}] = max({ch1, ch2, ch3});
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // memset(dp, -1, sizeof(dp));
    cin >> n >> d;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        mxm = max(mxm, x);
        a[x]++;
    }
    cout << solve(d, d) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}