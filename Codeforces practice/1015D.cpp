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
    
    ll n, k, s;
    cin >> n >> k >> s;
    if(s % k == 0){
        ll x = s/k;
        // cout << x << "\n";
        if(x > n-1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            for(ll i=0;i<k;i++){
                if(i % 2 == 0){
                    // cout << "1 ";
                    // cout << 1  << " ";
                    cout << 1 + x << " ";
                }
                else{
                    // cout << 1 + x << "\n";
                    // cout << 1 + x << " ";
                    cout << 1 << " ";
                }
            }
        }
    }
    else{
        ll x = s/k;
        ll y = s%k;
        // cout << x << " " << y << "\n";
        // if(x + y > n-1 || x > n-1 || x == 0){
        if(x == 0 || x + 1 > n-1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            // cout << 1 << " " << 1 + x + y << " ";
            ll steps = 0;
            // cout << 1 + x + y << " ";
            // for(ll i=1;i<k;i++){
            //     if(i % 2 == 0){
            //         // cout << 1 + y << " ";
            //         cout << 1 + y + x << " ";
            //     }
            //     else{
            //         // cout << 1 + x + y << " ";
            //         cout << 1 + y << " ";
            //     }
            // }
            // cout << "--\n"; 
            // cout << 1 + x + 1 << " ";
            // y--;
            ll pos = 1;
            for(ll i=0;i<k;i++){
                if(y){
                    if(i % 2 != 0){
                        // cout << 1 << " ";
                        cout << pos - 1 - x << " ";
                        pos = pos - 1 - x;
                        y--;
                    }
                    else{
                        // cout << 1 + x + 1 << " ";
                        cout << pos + 1 + x << " ";
                        pos = pos + 1 + x;
                        y--;
                    }
                }
                else{
                    // cout << i << "\n";
                    if(i % 2 != 0){
                        cout << pos - x << " ";
                        pos = pos - x;
                    }
                    else{
                        cout << pos + x << " ";
                        pos = pos + x;
                    }
                }
                // cout << y << "\n";
            }
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}