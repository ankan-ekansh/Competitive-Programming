#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007
// int64_t recursive(int64_t n){
//     if(n==1)
//         return 2*n;
//     else{
//         return recursive(n-1)+n-1+2*n;
//     }
// }
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int64_t t;
    cin>>t;
    while(t--){
 
        int64_t n;
        cin>>n;
        //cout<<recursive(n)<<"\n";
        cout<<(((n%MOD) *( (3*n%MOD)%MOD+1)%MOD )%MOD )/2<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}