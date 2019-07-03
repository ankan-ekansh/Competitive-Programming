#include<bits/stdc++.h>
#define M 1000000007
#define inv_mod 500000004
using namespace std;
int64_t power(int64_t m, int64_t n){
    if(n == 0){
        return 1;
    }
    else if(n == 1){
        return m;
    }
    else{
        int64_t x = power(m, n/2);
        if(n % 2 == 0){
            return ((x%M)*(x%M))%M;
        }
        else{
            return ((( (x%M)*(m%M)) % M ) * (x%M) ) % M;
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
    int64_t t;
    cin>>t;
    while(t--){
 
        int64_t n,k;
        cin>>n>>k;
        // int64_t r = (k-1)/(n-1);
        // if(n == 2){
        //     cout<<(((( (k-1)  %  M) * (k % M)) % M) * ((power(2, M-2))%M))%M <<"\n";
        //     continue;
        // }
        // cout<<"r: "<<r<<"\n";
        // cout<<"inv modulo of 2: "<<((power(2, M-2))%M)<<"\n";
        // int64_t ans = (((((k-1)%M) * ((r+1)%M))%M) - ( ((((((n-1)%M)*(r%M))%M)*((r+1)%M))%M)*((power(2, M-2))%M))%M )%M;
        // cout<<ans<<"\n";
        // // int64_t a = k;
        // // int64_t b = n+k-1;
        // // int64_t r = (((a-1)%M) * (power(b-a , M-2)%M))%M;
        // // int64_t ans = (((((((a-1)%M) + (((((((a%M)*((r+1)%M))%M) * ((r+2)%M)) % M) * ((power(2, M-2))%M)) % M))%M) - (a%M))%M)%M)%M - ((((((b%M)*(r%M))%M)*((r+1)%M))%M)*((power(2, M-2))%M))%M - (r%M);
        // // cout<<ans<<"\n";
        int64_t a = k-1;
        int64_t d = n-1;
        // int64_t r = 1LL + (int64_t)ceil((double)a/(double)d);
        // r = r - 1LL;
        int64_t x = a/d;
        //cout<<"x = "<<x<<"\n";
        int64_t l = a - ((x)*d);
        //cout<<"l = "<<l<<"\n";
        // int64_t ans = (((((2*(a%M))%M) - ((((r-1)%M)*(d%M))%M))%M) * (((r%M)*power(2, M-2))%M))%M;
        //int64_t ans = ((((k-1)*(x+1))%M) - ((((((n-1)*(x))%M)*(x+1))%M)*(inv_mod))%M)%M;
        int64_t ans = (((((x+1)%M)*inv_mod)%M)*((a%M)+(l%M))%M)%M;
        cout<<ans<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}