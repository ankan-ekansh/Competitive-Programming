#include<bits/stdc++.h>
using namespace std;
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
 
        int n, k, d;
        cin >> n >> k >> d;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int ans = INT_MAX;
        for(int i=0;i<=n-d;i++){
            set<int> s;
            s.insert(a+i, a+i+d);
            int si = s.size();
            ans = min(ans, si);
        }
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}