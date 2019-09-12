#include<bits/stdc++.h>
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
 
        int n;
        cin>>n;
        int a[n] = {0}, prs[n] = {0}, pos[n] = {0};
        cin>>a[0];
        prs[0] = a[0];
        pos[n-1] = prs[0];
        for(int i=1;i<n;i++){
            cin>>a[i];
            prs[i] = prs[i-1] ^ a[i];
            pos[n-i-1] = prs[i];
        }
        long long ans = 0;
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

// 2 7 5 5 2 7 = 10
// 1 1 1 1 1 = 10