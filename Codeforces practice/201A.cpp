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
    
    ll ans[101] = {0};
    ans[1] = 1;
    ll times = 4;
    ll ctr = 1;
    ll val = 3;
    for(ll i=2;i<=100;i++){
        if(ctr == times){
            ans[i] = val;
            val += 2;
            times += 4;
            ctr = 1;
        }
        else{
            ans[i] = val;
            ctr++;
        }
    }
    // for(ll i=1;i<=25;i++){
    //     cout << i << " " << ans[i] << "\n";
    // }
    ll x;
    cin >> x;   // for x = 3, n = 3 is not valid, instead n = 5 is the ans
    if(x == 3){
        cout << "5" << "\n";
        return 0;
    }
    cout << ans[x] << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}