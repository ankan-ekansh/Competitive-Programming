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
        
        string s;
        cin >> s;
        ll ans[s.length()+7];
        memset(ans, -1, sizeof(ans));
        stack<pair<char, ll>> st;
        ll last = -1;
        for(ll i=s.length()-1;i>=0;i--){
            if(!st.empty()){
                if(s[i] == '(' && st.top().first == ')'){
                    ans[i+1] = st.top().second;
                    st.pop();
                    last = ans[i+1];
                }
                else if(s[i] == ')'){
                    st.push({s[i], i+1});
                    ans[i+1] = last;
                }
            }
            else{
                if(s[i] == '('){
                    ans[i+1] = -1;
                    last = -1;
                }
                else{
                    st.push({s[i], i+1});
                    ans[i+1] = last;
                }
            }
        }
        ll q;
        cin >> q;
        while(q--){
            ll idx;
            cin >> idx;
            cout << ans[idx] << "\n";

        }
        // for(ll i=1;i<=s.length();i++){
        //     cout << ans[i] << " ";
        // }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}