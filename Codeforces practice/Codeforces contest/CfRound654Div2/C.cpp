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
        
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        if((a + b) < (n + m)){
            cout << "No\n";
        }
        else{
            if(min(a, b) >= m){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}