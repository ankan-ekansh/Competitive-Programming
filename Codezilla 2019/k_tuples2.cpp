#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int64_t c[1000007];
int64_t fact[1000007];
bool primes[1000007];
void sieve(){
    memset(primes, true, sizeof(primes));
    for(int64_t i=2;i*i<=1000000;i++){
        if(primes[i]){
            for(int64_t j=i*i;j<=1000000;j+=i){
                primes[j] = false;
            }
        }
    }
    for(int64_t i=2;i<=1000000;i++){
        c[i] = c[i-1];
        if(primes[i]){
            c[i]++;
        }
    }
}
int64_t power(int64_t a, int64_t b){
    if (b == 0){
        return 1;
    }
    else if(b == 1){
        return a % mod;
    }
    else if(a == 1){
        return 1;
    }
    else{
        int64_t x = power(a, b/2);
        if(b % 2 == 0){
            return (x * x) % mod;
        }
        else{
            return (((x * x) % mod) * a) % mod;
        }
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
    // fact[0] = 1;
    // fact[1] = 1;
    // for(int64_t i=2;i<=1000000;i++){
    //     fact[i]=(fact[i-1] * i) % mod;
    // }
    sieve();
    int t;
    cin>>t;
    while(t--){
 
        int64_t n, k;
        cin >> n >> k;
        // int64_t x = fact[n];
        // int64_t c = 0;
        // for(int64_t i = 2; i<=n;i++){
        //     if(primes[i]){
        //         // cout << i << "\n";
        //         // c+=1;
        //     }
        // }
        cout << power(k % mod, c[n]) << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}