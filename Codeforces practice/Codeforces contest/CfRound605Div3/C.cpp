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

    int64_t n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char c[k];
    map<char, int64_t> m;
    for(int64_t i=0;i<k;i++){
        cin >> c[i];
        m[c[i]]++;
    }
    vector<int64_t> v;
    int64_t j=0;
    for(int64_t i=0;i<n;i++){
        // cout << s[i] << "\n";
        if(m[s[i]]){
            j++;
        }
        else{
            v.push_back(j);
            j=0;
        }
    }
    v.push_back(j);
    int64_t ans = 0;
    for(int64_t i=0;i<v.size();i++){
        // cout << v[i] << "\n";
        ans+=(v[i]*(v[i]+1))/2;
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}