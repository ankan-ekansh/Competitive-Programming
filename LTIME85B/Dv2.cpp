#include<bits/stdc++.h>
using namespace std;
 
#define ll          long long int
#define ld          long double
#define pb          push_back
#define mp          make_pair
#define ff          first
#define se          second
#define endl        '\n'
#define fd(n)       fixed<<setprecision(n)
#define MAX         100000000000000000
#define MAXN        10000005
#define mod         998244353  
#define pi          3.1415926535897932384626433
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,i;
        cin>>n;
        ld g[n],a[n],b[n],sum1=0,sum2=0;
        for(i=0;i<n;i++){
            cin>>g[i]>>a[i]>>b[i];
            sum1+=(g[i]/(a[i]+b[i]))*b[i];
            sum2+=(g[i]/(a[i]+b[i]))*a[i];
        }
        cout<<fd(6)<<sum1<<" ";
        cout<<fd(6)<<sum2<<endl;
    }
}