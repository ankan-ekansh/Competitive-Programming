#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(pair<char, int> p, pair<char, int> q){
    return p.second > q.second;
}
string fun(string s, int k){
    vector<pair<char, int>> v;
        map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        for(pair<char, int> p : mp){
            v.push_back({p.first, p.second});
        }
        sort(v.begin(), v.end(), comp);
        vector<char> ans;
        int ctr = 0;
        bool found = false;
        for(int i=0;i<v.size();i++){
            if(i == 0 || v[i].second != v[i-1].second){
                ctr++;
            }
            if(ctr == k){
                ans.push_back(v[i].first);
                found = true;
            }
            // cout << i << "\n";
        }
        if(!found){
            return "-1";
        }
        sort(ans.begin(), ans.end());
        string anss = string(1, ans[0]);
        return anss;
}
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
        
        string s;
        int k;
        cin >> s;
        cin >> k;
        cout << fun(s, k) << "\n";
        
    }
    return 0;
}