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
    
    ll v;
    cin >> v;
    ll a[11];
    ll min_v = 0x3f3f3f3f;
    for(ll i=1;i<=9;i++){
        cin >> a[i];
        min_v = min(min_v, a[i]);
    }
    ll d = 0;
    for(ll i=1;i<=9;i++){
        if(a[i] == min_v){
            d = max(d, i);
        }
    }
    ll l = v/min_v;
    string ans = "";
    for(ll i=0;i<l;i++){
        ans.push_back((char)('0' + d));
    }
    ll rem_v = v - min_v * l;
    ll idx = 0;
    while(rem_v > 0 && idx < l){
        for(ll i=9;i>=1;i--){
            // if(i == d){
            //     continue;
            // }
            if(a[i] <= rem_v + min_v){
                rem_v = rem_v + min_v - a[i];
                ans[idx] = (char)(i + '0');
                idx++;
                break;
            }
        }
    }
    if(ans.length() == 0){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}