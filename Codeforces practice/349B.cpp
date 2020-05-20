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
    
    int v;
    cin >> v;
    vector<pair<int, int>> a;
    for(int i=1;i<=9;i++){
        // cin >> a[i];
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    while(v > 0){
        v-=a[0].first;
        ans.push_back(a[0].second);
    }
    reverse(ans.begin(), ans.end());
    for(int x : ans){
        cout << x;
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}