#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return binaryExponentiation(x*x,n/2);
    else
        return x*binaryExponentiation(x*x,(n-1)/2);
}
ll GCD(ll A, ll B){
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
ll modinv(ll a , ll mod){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
ll modPrimeInverse(ll A,ll M){
    return modularExponentiation(A,M-2,M);
}
unordered_map<ll, ll> pws;
ll fun(ll n){
    if(n % 4 == 0){
        return 2;
    }
    else if(n % 2 == 0){
        return 1;
    }
    else{
        return 0;
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
 
        ll n;
        cin >> n;
        ll ans = 0, odd = 0;
        vector<ll> a, pf, val;
        pf.assign(n, 0);
        val.assign(n, 0);
        for(ll i=0;i<n;i++){
            ll x;
            cin >> x;
            a.push_back(x);
        }
        ll len = 0;
        if(a[0] % 2 != 0){
            len = 1;
        }
        else{
            len = 0;
        }
        for(ll i=1;i<n;i++){
            if(a[i] % 2 != 0){
                len++;
            }
            else{
                ans += (len*(len+1))/2;
                len = 0;
            }
        }
        ans += (len*(len+1))/2;
        // cout <<"Odd ans : " << ans << "\n";
        pf[0] = fun(a[0]);
        val[0] = pf[0];
        for(ll i=1;i<n;i++){
            val[i] = fun(a[i]);
            pf[i] = pf[i-1] + val[i];
        }
        // for(ll i=0;i<n;i++){
        //     cout << pf[i] << " ";
        // }
        // cout << "\n";
        // for(ll i=0;i<n;i++){
        //     cout << val[i] << " ";
        // }
        // cout << "\n";
        for(ll i=0;i<n;i++){
            // cout << "Current case : " << pf[i] << " " << val[i] << " " << a[i] << "\n";
            if(val[i] == 2){
                ans += n - i;
                // cout << i << " " << n-1 << " : " << n - i << "\n";
            }
            else{
                // auto it = lower_bound(pf.begin()+i+1, pf.end(), pf[i] + 2);
                auto it = pf.begin();
                if(val[i] == 0){
                    it = lower_bound(pf.begin()+i+1, pf.end(), pf[i] + 2);
                }
                if(val[i] == 1){
                    it = lower_bound(pf.begin()+i+1, pf.end(), pf[i] + 1);
                }
                if(it == pf.end()){
                    // cout << "End case : " << pf[i] << " " << val[i] << " " << a[i] << "\n";
                    it--;
                }
                ll j = it - pf.begin();
                // if(val[i] + val[j] < 2){
                if(!(val[i] + val[j] == 2 || pf[j] - pf[i] == 2)){
                    // cout << i << " " << j << " " << "Not enough; " << val[i] << " " << val[j] << "\n";
                    continue;
                }
                
                if(j != i){
                    // cout << i << " " << j << " : " << n - j << "\n";
                    ans += n - j;
                }
            }
        }
        cout << ans << "\n";
        a.clear();
        pf.clear();
        val.clear();
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    // for(auto p : pws){
    //     cout << p.first << "  " << p.second << "\n";
    // }
    return 0;
}