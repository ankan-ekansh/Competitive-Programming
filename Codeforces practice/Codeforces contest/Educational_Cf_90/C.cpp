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
        ll ans = 0;
        ll plus = 0;
        for(ll i=0;i<s.length();i++){
            if(s[i] == '+'){
                plus++;
            }
            else{
                if(!plus){
                    ans += (i+1);
                }
                else{
                    plus--;
                }
            }
        }
        cout << ans + s.length() << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}