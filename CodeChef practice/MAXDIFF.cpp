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
 
        long long n,k;
        cin>>n>>k;
        long long a[n];
        long long ps = 0;
        for(long long i=0;i<n;i++){
            cin>>a[i];
            ps+=a[i];
        }
        sort(a,a+n);
        long long w1 = 0;
        long long w2 = 0;
        for(long long i=0;i<=k-1;i++){
            w1+=a[i];
        }
        for(long long i=n-k;i<n;i++){
            w2+=a[i];
        }
        cout<<max(abs(w1-(ps-w1)), abs(w2-(ps-w2)))<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}