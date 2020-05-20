#include<bits/stdc++.h>
#define mod 1000000007
#define inv_mod 111111112
using namespace std;
int64_t power(int64_t a, int64_t b){
    if(b == 0){
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
            return ((x % mod) * (x % mod)) % mod;
        }        
        else{
            return ((((x % mod) * (x % mod)) % mod) * (a % mod)) % mod;
        }
    }
    
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        int64_t n;
        cin >> n;
        int64_t ans = 0;
        ans = 10 * (power(10, n) - 1);
        // cout << ans << "\n";
        int64_t a1 = 0;
        int64_t a2 = 0;
        a2 = n / mod;
        ans = ((ans % mod) * inv_mod) % mod;
        // cout << ans << "\n";
        a1 = ans / mod;
        if((ans % mod) < (n % mod)){
            ans = mod + (ans % mod);
            ans = ans - (n % mod);
            ans = ans % mod;
        }
        else{
            ans = (ans % mod) - (n % mod);
        }
        ans = (((ans * 5) % mod) * inv_mod)%mod;
        ans = (ans + (n % mod)) % mod;
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}