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
    
    string s;
    cin >> s;
    ll a, b;
    cin >> a >> b;
    ll pref[s.length()+7] = {0}, suff[s.length()+7] = {0};
    for(ll i=0;i<s.length();i++){
        ll x = (s[i]-'0');
        if(i == 0){
            pref[i] = x % a;
        }
        else{
            pref[i] = (10*pref[i-1] + x)%a;
        }
        
    }
    ll p_10 = 1;
    for(ll i=s.length()-1;i>=0;i--){
        ll x = (s[i]-'0');
        if(i == s.length() - 1){
            suff[i] = x % b;
        }
        else{
            suff[i] = (suff[i+1] + x*p_10)%b;
        }
        p_10 = (p_10 * 10)%b;
    }
    // for(ll i=0;i<s.length();i++){
    //     cout << pref[i] << " ";
    // }
    // cout << "\n";
    // for(ll i=0;i<s.length();i++){
    //     cout << suff[i] << " ";
    // }
    // cout << "\n";
    for(ll i=0;i<s.length()-1;i++){
        if(pref[i] == 0 && suff[i+1] == 0 && s[i+1] != '0'){
            cout << "YES\n";
            for(ll j=0;j<=i;j++){
                cout << s[j];
            }
            cout << "\n";
            for(ll j=i+1;j<s.length();j++){
                cout << s[j];
            }
            cout << "\n";
            return 0;
        }
    }
    cout << "NO\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}