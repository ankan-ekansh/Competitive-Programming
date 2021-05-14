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
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a, a+n);
        set<ll> st;
        for(ll i=0;i<n;i++){
            if(!(a[i] % k)){
                continue;
            }
            else{
                ll x = a[i] / k;
                while(st.count((x+1)*k)){
                    x++;
                }
                st.insert((x+1)*k);
                a[i] = ((x+1)*k - a[i]);
                // a[i] = (x+1)*k;
            }
        }
        cout << *max_element(a, a+n) << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}