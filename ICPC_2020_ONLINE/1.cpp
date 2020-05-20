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
 
        string s;
        cin >> s;
        int ans = INT_MAX;
        for(int i=0;i<s.length();i++){
            string w;
            for(int j=0;j<i;j++){
                w+=s[j];
            }
            for(int j=i+1;j<s.length();j++){
                w+=s[j];
            }
            // cout << w << "\n";
            int n = stoi(w);
            //cout << n << "\n";
            ans = min(ans, n);
        }
        cout << ans << "\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}