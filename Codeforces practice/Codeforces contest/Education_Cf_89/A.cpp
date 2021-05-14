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
        
        ll x, y;
        cin >> x >> y;
        ll a = x, b = y;
        ll ans1 = 0, ans2 = 0;
        ll items1 = min(a/2, b);    // when 2a and 1b
        a -= 2*items1;
        b -= items1;
        ans1 = items1;
        ans1 += min(a, b/2);
        cout << a << " " << b << "\n";
        a = x, b = y;
        ll items2 = min(a, b/2);    // when 1a and 2b
        a -= items2;
        b -= 2*items2;
        ans2 = items2;
        ans2 += min(a/2, b);
        cout << a << " " << b << "\n";
        cout << max(ans1, ans2) << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}