#include<bits/stdc++.h>
using namespace std;
int64_t nCr(int64_t n, int64_t r) 
{
    int64_t C[r+1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1;
    for(int64_t i = 1; i <= n; i++) 
    { 
        for(int64_t j = min(i, r); j > 0; j--)  
            C[j] = (C[j] + C[j-1]); 
    } 
    return C[r]; 
} 
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
 
        int64_t n, k;
        cin >> n >> k;
        map<int64_t, int64_t> m;
        for(int i=0;i<n;i++){
            int64_t x;
            cin >> x;
            m[x]++;
        }
        int64_t c = 0;
        int64_t ans = 1;
        int64_t f1 = 0, f2 = 0;
        bool flag = false;
        auto i = m.begin();
        for(i=m.begin();i!=m.end();i++){
            if((c + (*i).second) < k){
                c+=(*i).second;
            }
            else{
                flag = true;
                f1 = k - c;
                f2 = (*i).second;
                break;
            }
        }
        ans = nCr(f2, f1);

        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}