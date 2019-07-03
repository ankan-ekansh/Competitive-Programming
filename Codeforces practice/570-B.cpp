#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
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
        set<ll> s;
        ll mi = LLONG_MAX, ma = 0;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            mi = min(mi, a[i]);
            ma = max(ma, a[i]);
            s.insert(a[i]);
        }
        if((mi + k) >= (ma - k)){
            cout<<mi+k<<"\n";
            continue;
        }
        else{
            cout<<"-1\n";
        }
        // ll sum = 0;
        // for(auto i=s.begin();i!=s.end();i++){
        //     sum+=*i;
        // }
        // ll a1 = floor((double)sum/(double)s.size());
        // ll a2 = ceil((double)sum/(double)s.size());

        // ll c1 = 0, c2 = 0;
        // for(ll i = 0;i<n;i++){
        //     // if(a1 > a[i]){
        //     //     if((a1 - a[i]) > k){
        //     //         c1++;
        //     //     }
        //     // }
        //     // else if(a1 < a[i]){
        //     //     if((a[i] - a1) > k){
        //     //         c1++;
        //     //     }
        //     // }
        //     // else if(a2 > a[i]){
        //     //     if((a2 - a[i]) > k){
        //     //         c2++;
        //     //     }
        //     // }
        //     // else if(a2 < a[i]){
        //     //     if((a[i] - a2) > k){
        //     //         c2++;
        //     //     }
        //     // }
        //     if(abs(a1 - a[i]) > k){
        //         c1++;
        //     }
        //     else if(abs(a2 - a[i]) > k){
        //         c2++;
        //     }
        // }
        // // cout<<"Averages: "<<a1<<" "<<a2<<"\n";
        // //cout<<c1<<" "<<c2<<"\n";
        // if(c1 == 0 && c2 != 0){
        //     cout<<a1<<"\n";
        // }
        // else if(c1 != 0 && c2 == 0){
        //     cout<<a2<<"\n";
        // }
        // else if(c1 != 0 && c2 != 0){
        //     cout<<"-1\n";
        // }
        // else if(c1 == 0 && c2 == 0){
        //     cout<<a1<<"\n";
        // }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}