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
 
        int n;
        cin >> n;
        vector<string> v;
        map<string, int> m0,m1;
        for(int i=0;i<n;i++){
            string s;
            int n;
            cin >> s;
            cin >> n;
            if(m0[s] == 0 && m1[s] == 0){
                v.push_back(s);
            }
            if(n == 0){
                m0[s]++;
            }
            else{
                m1[s]++;
            }
        }
        int ans = 0;
        for(int i=0;i<v.size();i++){
            // cout << m0[v[i]] << " " << m1[v[i]] << "\n";
            if(m0[v[i]] > m1[v[i]]){
                ans+=m0[v[i]];
            }
            else{
                ans+=m1[v[i]];
            }
        }
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}