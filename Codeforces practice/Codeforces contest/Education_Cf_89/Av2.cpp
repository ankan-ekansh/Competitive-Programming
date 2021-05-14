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
        
        ll a, b;
        cin >> a >> b;
        // if(a == 0 || b == 0){
        //     cout << "0\n";
        //     continue;
        // }
        // cout << max((a+b)/3, max(min(a/2, b), min(a, b/2))) << "\n";
        if(b > a){
            swap(a, b);
        }
        cout << min((a+b)/3, b) << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}