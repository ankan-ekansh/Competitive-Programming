#include<bits/stdc++.h>
#define i64 int64_t
using namespace std;
bool comp(i64 a,i64 b){
    return (a>b);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    i64 t;
    cin>>t;
    while(t--){
 
        i64 n;
        vector<i64> m,w;
        cin>>n;
        m.resize(n);
        w.resize(n);
        for(i64 i=0;i<n;i++){
            cin>>m[i];
        }
        for(i64 i=0;i<n;i++){
            cin>>w[i];
        }
        sort(m.begin(),m.end(),comp);
        sort(w.begin(),w.end(),comp);
        // for(i64 i=0;i<n;i++){
        //     cout<<m[i]<<" ";
        // }
        // cout<<"\n";
        // for(i64 i=0;i<n;i++){
        //     cout<<w[i]<<" ";
        // }
        // cout<<"\n";
        // i64 sum = 0;
        // for(i64 i=0;i<n;i++){
        //     sum+=m[i]*w[i];
        // }
        // cout<<sum<<"\n";
        cout<<inner_product(m.begin(),m.end(),w.begin(),0)<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}