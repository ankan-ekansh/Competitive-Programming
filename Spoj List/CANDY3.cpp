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
    long long t;
    cin>>t;
    while(t--){
 
        long long n;
        cin>>n;
        //long long a[n];
        long long sum = 0;
        for(long long i=0;i<n;i++){
            long long x;
            cin>>x;
            sum=(sum+(x % n))%n;
        }
        long long avg = sum / n;
        if((avg * n) == sum){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}