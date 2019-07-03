#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c;
void sieve(ll limit, vector<ll> &prime){
    bool mark[limit + 1];
    memset(mark, true, sizeof(mark));
    for(ll p=2; p*p < limit; p++){
        if(mark[p]){
            for(ll i=2*p; i < limit; i+=p){
                mark[i] = false;
            }
        }
    }
    for(ll p=2; p < limit; p++){
        if(mark[p]){
            c++;
            prime.push_back(p);
        }
    }
}
void segmentedSieve(ll n){
    ll limit = floor(sqrt(n))+1;
    vector<ll> prime;
    sieve(limit, prime);
    ll low = limit;
    ll high = 2 * limit;
    while(low < n){
        if(high >= n){
            high = n;
        }
        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));
        for(ll i=0; i<prime.size(); i++){
            ll lowlim = floor(low/prime[i]) * prime[i];
            if(lowlim < low){
                 lowlim+=prime[i];
            }
            for(ll j=lowlim; j<high; j+=prime[i]){
                mark[j-low]=false;
            }
        }
        for(ll i=low; i<high; i++){
            if(mark[i-low]){
                c++;
            }
        }
        low = low + limit;
        high = high + limit;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;
    segmentedSieve(n);
    cout<<c<<"\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}