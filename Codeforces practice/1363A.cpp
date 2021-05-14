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
        
        ll n, x;
        cin >> n >> x;
        ll a[n], odds = 0;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            if(a[i]&1){
                odds++;
            }
        }
        if(!odds){
            cout << "No\n";
        }
        else{
            if(odds == n && !(x&1)){
                cout << "No\n";
            }
            else{
                bool flag = false;
                for(ll i=1;i<=odds;i++){
                    // loop for taking number of odds
                    ll evens = n - odds;
                    ll evensNeeded = x - i;
                    if(evensNeeded <= evens && i&1){
                        cout << "Yes\n";
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    cout << "No\n";
                }
            }
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}