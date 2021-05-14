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
    // cin>>t;
    t = 1;
    while(t--){
        
        ll cost[26] = {0};
        for(ll i=0;i<26;i++){
            cin >> cost[i];
        }
        ll X;
        cin >> X;
        string ans = "";
        ll pos = 25;
        for(ll i=25;i>=0;i--){
            if(cost[i] <= X){
                pos = i;
                break;
            }
        }
        while(X > 0 && pos >= 0){
            ll tmp = X / cost[pos];
            for(ll i=0;i<tmp;i++){
                ans.push_back((char)('a'+pos));
            }
            X -= tmp*cost[pos];
            pos--;
        }
        
        if(ans.length() && X == 0){
            cout << ans << "\n";
        }
        else{
            cout << "0\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}