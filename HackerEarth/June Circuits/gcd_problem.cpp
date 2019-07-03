#include<bits/stdc++.h>
#define ll long long
#define m 1000000007
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
 
        ll n;
        cin>>n;
        ll ans = 0;
        ll c = 0;
        for(ll i = 1 ; i<=n ; i++){
            for(ll j = i+1 ; j<=n ; j++){
                for(ll k = j+1 ; k<=n ; k++){
                    for(ll l = k+1 ; l<=n ; l++){
                        ll g = __gcd(i, j);
                        g = __gcd(g, k);
                        g = __gcd(g, l);
                        if(g == 1){
                            c++;
                        }
                        //cout<<i<<" "<<j<<" "<<k<<" "<<l<<" : "<<g<<"\n";
                        ans=(ans%m+(g*g*g*g))%m;
                    }
                }
            }
        }
        cout<<"gcd 1 = "<<c<<"\n";
        cout<<ans<<"\n";
        //cout<<"N = "<<n<<" ,"<<ans<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}