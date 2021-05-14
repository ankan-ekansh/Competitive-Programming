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
    
    string s;
    cin >> s;
    char c = s[s.length()-1];
    string ans;
    // ans.push_back(c);
    for(ll i=s.length()-1;i>=0;i--){
        if(s[i] > c){
            c = s[i];
        }
        if(s[i] == c){
            // cout << i << "\n";
            ans.push_back(c);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}