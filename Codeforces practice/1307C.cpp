/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int brute(string s){
    int ans = 0;
    map<string, int> m;
    for(int i=0;i<s.length();i++){  // start index
        // m[s.substr(i,1)]++;
        string tmp = s.substr(i,1);
        m[tmp]++;
        for(int j=1;j<s.length();j++){      // common difference
            // for(int k=i+j;k<s.length();k+=j){
            //     tmp+=s[k];
            //     m[tmp]++;
            // }
            if(i+j < s.length()){
                tmp+=s[i+j];
                m[tmp]++;
            }
            else{
                break;
            }
            // cout << tmp << "\n";
            tmp = s.substr(i,1);
            // cout << tmp << "\n";
        }
    }
    for(auto p : m){
        // cout << p.first << " " << p.second << "\n";
        ans = max(ans, p.second);
    }
    return ans;
}

ll solve(string s){
    ll dp[26][26] = {0};
    ll freq[26] = {0};
    for(ll i=0;i<s.length();i++){
        for(ll j=0;j<26;j++){
            dp[j][s[i]-'a']+=freq[j];
        }
        freq[s[i]-'a']++;
    }
    ll ans = 0;
    for(ll i=0;i<26;i++){
        ans = max(ans, freq[i]);
    }
    for(ll i=0;i<26;i++){
        for(ll j=0;j<26;j++){
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    // cout << brute(s) << "\n";
    cout << solve(s) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}