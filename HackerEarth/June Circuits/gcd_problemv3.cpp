#include<bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
map<ll, ll> mp;
ll ncr[100007];
ll p[100007];
ll ncrmodm(ll n){
    if(ncr[n] != 0){
        return ncr[n];
    }
    ll r = 4;
    int c[r+1];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = min(i, r) ; j > 0 ; j--){
            c[j] = ((c[j])%m + (c[j-1])%m)%m;
        }
    }
    ncr[n] = c[r];
    return c[r];
}
ll power(ll n){
    if(p[n] != 0){
        return p[n];
    }
    p[n] = (((((n * n)%m)*n)%m)*n)%m;
    return p[n];
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
 
        ll n;
        cin>>n;
        ll ans = 0;
        ll g = n/4;
        while(g >= 1){
            ll c = 0;
            if((n / g) >= 4){
                c = ncrmodm(n / g);
                ll temp = 2 * g;
                while(temp <= n){
                    if((n / temp) >= 4){
                        c-=(mp[temp]);
                    }
                    temp+=g;
                }
            }
            mp[g]=c;
            //cout<<c<<"\n";
            ans+=((((power(g))%m)*(c%m))%m);
            g--;
        }
        cout<<ans%m<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}