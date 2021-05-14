/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int, int>> memo(10000001, {0, 0});
pair<int, int> fun(int a){
    if(memo[a].first != 0 && memo[a].second != 0){
        return memo[a];
    }
    for(int i=2;i*i<=a;i++){
        if(a % i == 0){
            if(a/i != i){
                if(__gcd(i + a/i, a) == 1){
                    memo[a] = {i, a/i};
                    return {i, a/i};
                }
            }
        }
    }
    memo[a] = {-1, -1};
    return {-1, -1};
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int a[n];
    int ans[2][n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        pair<int, int> d = fun(a[i]);
        if(d.first == -1 || d.second == -1){
            ans[0][i] = -1, ans[1][i] = -1;
        }
        else{
            ans[0][i] = d.first, ans[1][i] = d.second;
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[0][i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n;i++){
        cout << ans[1][i] << " ";
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}