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
        
        ll n, k;
        cin >> n >> k;
        if(k % n){
            cout << "2\n";
        }
        else{
            cout << "0\n";
        }
        ll a[n][n];
        memset(a, 0, sizeof(a));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(!k){
                    break;
                }
                a[j][(j+i)%n] = 1;
                k--;
            }
            if(!k){
                break;
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cout << a[i][j];
            }
            cout << "\n";
        }
        
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}