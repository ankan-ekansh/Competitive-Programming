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
        int a[n];
        cin>>a[0];
        cin>>a[1];
        int x = __gcd(a[0],a[1]);
        for(int i=2;i<n;i++){
            cin>>a[i];
            x = __gcd(x,a[i]);
        }
        for(int i=0;i<n;i++){
            a[i]/=x;
            cout<<a[i]<<" ";
        }
        cout<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}