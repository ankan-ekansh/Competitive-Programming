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
        ll a[n];
        // ll u = 0;
        // map<ll, ll> m;
        set<ll> m;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            m.insert(a[i]);
        }
        if(m.size() == 1){
            cout << "1\n";
            for(ll i=0;i<n;i++){
                cout << "1 ";
            }
            cout << "\n";
            continue;
        }
        if(n % 2 == 0){
            cout << "2\n";
            for(ll i=0;i<n/2;i++){
                cout << "1 2 ";
            }
            cout << "\n";
            continue;
        }
        else{
            bool same = false;
            ll v = 0;
            vector<ll> ans;
            ll col = 0;
            // cout << v+1 << " ";
            ans.push_back(v+1);
            v = 1 - v;
            for(ll i=1;i<n;i++){
                if(a[i-1] == a[i] && !same){
                    // cout << 2 - v << " ";
                    ans.push_back(2-v);
                    // v = 1 - v;
                    same = true;
                }
                else{
                    // cout << v + 1 << " ";
                    ans.push_back(v+1);
                    v = 1 - v;
                }
            }
            // if(a[0] == a[n-1] && same){
            //     if(a[n-2] )
            //         ans.pop_back();
            //         ans.push_back(2);
            // }
            if(!same && a[0] != a[n-1]){
                ans.pop_back();
                ans.push_back(3);
                cout << "3\n";
                for(ll i=0;i<ans.size();i++){
                    cout << ans[i] << " ";
                }
                cout << "\n";
                continue;
            }
            cout << "2\n";
            for(ll i=0;i<ans.size();i++){
                cout << ans[i] << " ";
            }
            cout << "\n";
            continue;
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}