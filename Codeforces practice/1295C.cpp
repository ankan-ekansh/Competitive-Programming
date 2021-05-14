/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
        // set<int> st[26];
        vector<int> st[26];
        string s, t;
        cin >> s;
        cin >> t;
        string z;
        for(int i=0;i<s.length();i++){
            // st[s[i]-'a'].insert(i);
            st[s[i]-'a'].push_back(i);
        }
        // for(int i=0;i<26;i++){
        //     cout << (char)(i+'a') << " : ";
        //     for(int j : st[i]){
        //         cout << j << " ";
        //     }
        //     cout << "\n";
        // }
        bool flag = true;
        int k=-1, ans=0;
        for(int i=0;i<t.length();i++){
            auto it = lower_bound(st[t[i]-'a'].begin(), st[t[i]-'a'].end(), k+1);
            if(it == st[t[i]-'a'].end()){
                // k = 0;
                it = lower_bound(st[t[i]-'a'].begin(), st[t[i]-'a'].end(), 0);
                if(it == st[t[i]-'a'].end()){
                    flag = false;
                    break;
                }
                else{
                    ans++;
                    k = *it;
                }
            }
            else{
                k = *it;
            }
        }
        ans++;
        // cout << flag << "\n";
        if(!flag){
            cout << "-1\n";
            continue;
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}