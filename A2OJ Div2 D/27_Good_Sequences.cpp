/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool prime[100007];
vector<int> pfactors[100007];
int dp[100007], a[100007];
int n;
void sieve(){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int p = 2; p <= 100000; p++){
        dp[p] = 1;
        if(prime[p]){
            pfactors[p].push_back(p);
            for(int j = 2*p; j <= 100000; j+=p){
                prime[j] = false;
                pfactors[j].push_back(p);
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
    
    sieve();
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = 1;
    for(int i=0;i<n;i++){
        int mxm = 1;
        for(int pf : pfactors[a[i]]){
            mxm = max(mxm, dp[pf]);
        }
        ans = max(ans, mxm);
        for(int pf : pfactors[a[i]]){
            dp[pf] = max(dp[pf], mxm + 1);
        }
    }
    cout << ans << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}