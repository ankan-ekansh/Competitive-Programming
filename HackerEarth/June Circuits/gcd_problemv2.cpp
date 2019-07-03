#include<bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
ll ncr[100007];
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
ll nd[100007];
ll count(ll n){
    if(nd[n] != 0){
        return nd[n];
    }
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++){ 
        if (n % i == 0){ 
            if (n / i == i) 
                cnt++; 
            else
                cnt = cnt + 2; 
        } 
    }
    nd[n] = cnt;
    return cnt; 
}
ll p[25007];
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
        ll d = 1;
        ll ans = 0;
        while((n/d) >= 4){
            cout<<d<<"\n";
            if(count(d) == 1)
                ans = (ans + (ncrmodm(n/d) * power(d))%m)%m;
            else if(count(d) == 2){
                ll term = power(d) - 1;
                ans = (ans + (ncrmodm(n/d) * term)%m)%m;
            }
            else if(count(d) >= 3){
                ll term = power(d);
                ll ct = 0;
                ll td = 2;
                ll tt[2] = {0};
                while(ct < 2){
                    if(d % td == 0){
                        tt[ct++] = d/td;
                    }
                    td++;
                }
                ll g = __gcd(tt[0], tt[1]);
                term = term - power(tt[0]) - power(tt[1]) + power(g);
                ans = (ans + (ncrmodm(n/d) * term)%m)%m;
            }
            d++;
        }
        cout<<"\n"<<ans<<"\n";        

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}