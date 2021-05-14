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
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> df;
    int dc = 0;
    for(char c : s){
        if(df[c] == 0){
            dc++;
            df[c]++;
        }
    }
    map<char, int> f;
    int fc = 0;
    int i=0, j=0;
    int ans = INT_MAX;
    while(i < n){
        while(j < n && fc < dc){
            f[s[j]]++;
            if(f[s[j]] == 1){
                fc++;
            }
            j++;
        }
        if(fc == dc){
            ans = min(ans, j-i);
        }
        f[s[i]]--;
        if(f[s[i]] == 0){
            fc--;
        }
        i++;
    }
    // cout << i << " " << j << "\n";
    // ans = min(ans, j-i);
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}