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
        ll a[n+7] = {-1};
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        bool ok = false, flag = false;
        if(n == 1){
            if(a[0] == k){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
            continue;
        }
        for(ll i=0;i<n;i++){
            if(a[i] == k){
                ok = true;
            }
            if((a[i] >= k) && (a[i+1] >= k || a[i+2] >= k)){
                flag = true;
            }
        }
        if(ok && flag){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}