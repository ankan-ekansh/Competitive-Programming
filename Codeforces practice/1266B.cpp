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
    
    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    ll white = 0, black = 0;    // i % 2 == 0 then first color is black (even = equal white black)
                                // odd => black = white + 1
                                // i % 2 != 0 then first color is white
                                // even = equal, odd => white = black + 1
    for(ll i=0;i<n;i++){
        if(i % 2 == 0){
            if(a[i] % 2 == 0){
                white += a[i]/2;
                black += a[i]/2;
            }
            else{
                white += a[i]/2 + 1;
                black += a[i]/2;
            }
        }
        else{
            if(a[i] % 2 == 0){
                white += a[i]/2;
                black += a[i]/2;
            }
            else{
                white += a[i]/2;
                black += a[i]/2 + 1;
            }
        }
    }
    cout << min(white, black) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}