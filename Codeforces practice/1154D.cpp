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
    
    ll n, b, a;
    cin >> n >> b >> a;
    ll arr[n];
    for(ll i=0;i<n;i++) {
        cin >> arr[i];
    }
    ll tb = b, ta = a;
    ll ans = 0;
    for(ll i=0;i<n;i++) {
        if(tb == 0 && ta == 0) {
            break;
        }
        else if(tb == 0) {
            ta--;
            ans++;
        }
        else if(ta == 0) {
            if(arr[i] == 1) {
                tb--;
                ta = (ta+1 > a) ? a : ta + 1;
                ans++;
            }
            else {
                tb--;
                ans++;
            }
        }
        else if(arr[i] == 1 && ta < a) {
            tb--;
            ta = (ta+1 > a) ? a : ta + 1;
            ans++;
        }
        else {
            ta--;
            ans++;
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}