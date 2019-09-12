#include<bits/stdc++.h>
#define mod 1000000007
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
 
        long long n;
        cin>>n;

        long long h[n],a[n];
        vector<pair<long long, long long>> m;
        for(long long i=0;i<n;i++){
            cin>>h[i];
        }
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        for(long long i=0;i<n;i++){
            m.push_back(make_pair(h[i], a[i]));
        }
        long long ans = 0;
        long long ctr = 1;
        sort(m.begin(),m.end());
        // for(auto i=m.begin();i!=m.end();i++){
        //     cout<<(*i).first<<" "<<(*i).second<<"\n";

        // }
        for(auto i=m.begin();i!=m.end();i++){
            //ans = (ans + (((*i).first + (*i).second)*(ctr++))%mod)%mod;
            long long nh = ((*i).first + (*i).second)%mod;
            long long term = ((nh%mod) * (ctr%mod))%mod;
            ans = (( ans % mod ) + (term % mod) )%mod;
            ctr++;
        }
        cout<<ans%mod<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}