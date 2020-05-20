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
 
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        ll x = a-b, y = b+a;
        ll cap1 = c-d, cap2 = c+d;
        bool flag = false;
        if(n*x >= cap1 && n*x <= cap2){
            flag = true;
        }
        if(n*y <= cap2 && n*y >= cap1){
            flag = true;
        }
        if(n*x < cap1){
            ll diff = cap1 - (n*x);
            for(ll y2=y;y2>x;y2--){
                if(diff%(y2-x) == 0 && diff/(y2-x) <= n){
                    flag = true;
                    break;
                }
            }
        }
        if(n*y > cap2){
            ll diff = n*y - cap2;
            for(ll x2=x;x2<y;x2++){
                if(diff%(y-x2) == 0 && diff/(y-x2) <= n){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}