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
    // cin>>t;
    t = 1;
    while(t--){
        
        ll n, k;
        cin >> n >> k;
        ll a[n+7];
        ll arr[n+7] = {0};
        map<ll, ll> freq;
        for(ll i=1;i<=n;i++){
            cin >> a[i];
            if(a[i] % k == 0){
                arr[i] = freq[a[i]/k];
            }
            freq[a[i]]++;
        }
        freq.clear();
        for(ll i=n;i>=1;i--){
            if(a[i] % k == 0){
                arr[i] = arr[i] * freq[a[i] * k];
            }
            freq[a[i]]++;
        }
        for(ll i=1;i<=n;i++){
            arr[i] = arr[i-1] + arr[i];
        }
        cout << arr[n] << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}