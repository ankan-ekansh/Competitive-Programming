#include<bits/stdc++.h>
#define i64 int64_t
using namespace std;
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
 
        i64 an,bn;
        cin>>an;
        vector<i64> a;
        a.resize(an);
        for(i64 i = 0; i < an ; i++){
            cin>>a[i];
        }
        cin >> bn;
        vector<i64> b;
        b.resize(bn);
        for(i64 i = 0;i < bn ; i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        i64 ans = abs(a[0] - b[0]);
        i64 ia = 0,ib = 0;
        while(ia < an && ib < bn){
            ans = min(ans,abs(a[ia] - b[ib]));
            if( a[ia] > b[ib] ){
                ib++;
            }
            else{
                ia++;
            }
        }
        cout<<ans<<"\n"; 
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}