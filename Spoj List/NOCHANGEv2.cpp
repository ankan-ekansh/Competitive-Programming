/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x, k;
ll v[100007];
bool dp[100007];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> x >> k;
    for(ll i=1;i<=k;i++){
        cin >> v[i];
        v[i] += v[i-1];
    }
    dp[0] = true;
    for(ll i=1;i<=k;i++){
        for(ll j=1;j<=x;j++){   
            if(j >= v[i])
                dp[j] = dp[j] | dp[j-v[i]];
        }
    }
    if(dp[x]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}