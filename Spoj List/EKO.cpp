#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll bsearch(ll h[], ll n, ll m){
    ll low = 1, high = h[n-1], mid;
    ll f = 0;
    ll ans = 0;
    ll remain = 0;
    while(low <= high){
        mid = (low + high)/2;
        f=0;
        //cout<<mid<<"\n";
        for(ll i=0;i<n;i++){
            if(h[i] >= mid){
                f+=(h[i] - mid);
            }
        }
        //cout<<f<<"\n";
        if(f>=m){
            low = mid+1;
            ans = mid;
        }
        else if(f<m){
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin>>n>>m;
    ll h[n];
    for(ll i=0;i<n;i++){
        cin>>h[i];
    }
    sort(h, h+n);
    cout<<bsearch(h, n, m)<<"\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}