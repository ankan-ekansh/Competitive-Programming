#include<bits/stdc++.h>
using namespace std;
vector<pair<int64_t, int64_t>> v;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int64_t n;
    cin >> n;
    int64_t p[n];
    for(int64_t i=0;i<n;i++){
        cin >> p[i];
    }
    sort(p, p+n);

    v.push_back(make_pair(p[0], 1));
    int64_t j = 0;
    for(int64_t i=1;i<n;i++){
        if(p[i] != p[i-1]){
            v.push_back(make_pair(p[i], 1));
            j++;
        }
        else{
            v[j].second++;
        }
    }
    int64_t ans = 0;
    for(int64_t i=0;i<(v.size()-1);i++){
        cout << v[i].first << " " << v[i].second << "\n";
        v[i].second = v[i].second - v[i+1].second;
        // if(v[i].second > 0){
        //     ans+=(v[i].first * v[i].second);
        // }
    }
    for(int64_t i=0;i<v.size();i++){
        if(v[i].second > 0){
            ans+=(v[i].first * v[i].second);
        }
    }
    cout << ans << "\n";
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
        