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
    
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n][m];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    cout << (m*(m-1))/2 << "\n";
    for(ll i=1;i<=m;i++){
        for(ll j=i+1;j<=m;j++){
            if(k){
                cout << j << " " << i << "\n";
            }
            else{
                cout << i << " " << j << "\n";
            }
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}