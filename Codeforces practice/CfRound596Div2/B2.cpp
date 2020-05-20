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
        int a[n+7];
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        unordered_map<int,int> m;
        int uni = 0;
        for(int i=1;i<=d;i++){
            if(!m[a[i]]){
                uni++;
            }
            m[a[i]]++;
        }
        int ans = INT_MAX;
        ans = min(ans, uni);
        // cout << "Unique: " << uni << "\n";
        for(int i=2;i<=n-d+1;i++){
            // cout << i << " " << i + d - 1 << "\n";
            if(a[i-1] == a[i+d-1]){
                continue;
            }
            else{
                if(!m[a[i+d-1]]){
                    uni++;
                    m[a[i+d-1]]++;
                }
                else{
                    m[a[i+d-1]]++;
                }
                if(m[a[i-1]] == 1){
                    m[a[i-1]]--;
                    uni--;
                }
                else{
                    m[a[i-1]]--;
                }
            }
            // cout << "Unique: " << uni << "\n";
            ans = min(ans, uni);
        }
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}