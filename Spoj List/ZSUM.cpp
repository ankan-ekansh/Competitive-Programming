#include<bits/stdc++.h>
#define mod 10000007
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

    while(1){
        int64_t n, k;
        cin >> n >> k;
        if(n == 0 && k == 0){
            break;
        }
        cout << (((((power(n, k) + power(n, n)) % mod) + (2 * power(n-1, k))) % mod) + (2 * power(n-1, n-1))) % mod << "\n";
        
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}