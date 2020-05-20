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
 
        string r, s;
        cin >> s >> r;
        ll ans = 0;
        ll c = 0;
        ll i = 0, j = 0, l = 0;
        bool flag = false;
        ll a2 = 0, c2 = 0;
        if(s[i] != r[i]){
            j++;
            flag = true;
            a2++;
            c2++;
        }
        while(i <= j && i < s.length() && j < s.length()){
            // cout << i << " " << j << " " << flag << "\n";
            if(s[j] != r[j]){
                j++;
                flag = true;
                a2++;
                c2++;
            }
            else{
                if(flag){
                    l += j - i;
                    c++;
                    flag = false;
                }
                i = j+1;
                j = i;
            }
        }
        if(flag){
            l+= j - i;
            c++;
            flag = false;
        }
        // cout << l << " " << c << " " << l * c << "\n";
        ans = l * c;
        // cout << a2*c2 << "\n";
        cout << min(ans, min((ll)s.length(), a2*c2)) << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}