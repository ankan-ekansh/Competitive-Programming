#include<bits/stdc++.h>
#define M 1000000007
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
 
        long long n,k;
        cin>>n>>k;
        long long sum = 0;
        long long temp = k-1;
        while(temp>0){
            sum=(sum+temp)%M;
            temp = temp - (n-1);
        }
        cout<<sum%M<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}