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
        
        ll n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> st;
        for(ll i=0;i<n;i++){
            while(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
                i++;
                if(i == n){
                    break;
                }
            }
            if(i == n){
                break;
            }
            st.push(s[i]);
        }
        cout << st.size() / 2 << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}