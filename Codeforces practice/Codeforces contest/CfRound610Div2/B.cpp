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
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        ll n, p, k;
        cin >> n >> p >> k;
        ll a[n];
        ll s = 0, ct = 0;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            s+=a[i];
        }
        sort(a, a+n);
        for(ll i=0;i<n-1;i++){
            if(p < a[i]){
                break;
            }
            else if(i == n-1){
                if(p >= a[i]){
                    p-=a[i];
                    ct++;
                }
                else{
                    break;
                }
            }
            else if(p-a[i] < a[i+1]){
                // cout << "Group " << a[i] << " " << a[i+1] << "\n";
                ct+=2;
                p-=a[i+1];
                i++;
            }
            else if(p >= a[i]){
                // cout << "Single buy " << a[i] << "\n";
                ct++;
                p-=a[i];
            }
        }
        if(p >= s){
            cout << n << "\n";
        }
        else{
            cout << ct << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}