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
        
        ll b, p, f, h, c;
        cin >> b >> p >> f;
        cin >> h >> c;
        b /= 2;
        if(h < c){
            swap(h, c);
            swap(p, f);
        }
        ll ans = 0;
        ll ct = min(b, p);
        b -= ct;
        p -= ct;
        ans += h*ct;
        ct = min(b, f);
        b -= ct;
        f -= ct;
        ans += c*ct;
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}