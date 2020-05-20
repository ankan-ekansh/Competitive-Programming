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
    
    ll n, q, k;
    cin >> n >> q >> k;
    ll a[n + 7];
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    a[n] = 1;
    ll suff[n+7] = {0}, pref[n+7] = {0};
    for(ll i=n-1;i>=0;i--){
        if(a[i] == 1 && a[i+1] == 1){
            suff[i] = suff[i+1] + 1;
        }
        else{
            if(a[i] == 0)
                suff[i] = 0;
            else
                suff[i] = 1;
        }
    }
    for(ll i=0;i<n;i++){
        if(i == 0){
            if(a[i] == 0){
                pref[i] = 0;
            }
            else{
                pref[i] = 1;
            }
        }
        else{
            if(a[i] == 1 && a[i-1] == 1){
                pref[i] = pref[i-1] + 1;
            }
            else{
                if(a[i] == 0){
                    pref[i] = 0;
                }
                else{
                    pref[i] = 1;
                }
            }
        }
    }
    ll maxl = 0;
    for(ll i=0;i<n;i++){
        cout << pref[i] << " " << suff[i] << "\n";
        maxl = max(maxl,  max(suff[i], pref[i]));
        maxl = min(k, maxl);
    }
    cout << "\n";
    ll left = 0, right = n-1;
    string s;
    cin >> s;
    for(ll j = 0; j < q; j++){
        if(s[j] == '!'){
            cout << left << " " << right << " becomes ";
            if(a[right % n] == 1 && a[left % n] == 1){
                pref[(right - 1 + n)%n] -= 1;
                suff[(left - 1 + n) % n] += 1;
                maxl = max(maxl, max(pref[(right - 1 + n)%n], suff[(left - 1 + n)%n]));
                maxl = min(k, maxl);
            }
            else if(a[right % n] == 1 && a[left % n] == 0){
                pref[(right - 1 + n)%n] -= 1;
                suff[(left - 1 + n) % n] = 1;
                maxl = max(maxl, max(pref[(right - 1 + n)%n], suff[(left - 1 + n)%n]));
                maxl = min(k, maxl);
            }
            // else if(a[right % n] == 0 && a[left % n] == 1){

            // }
            left = (left - 1 + n)%n;
            right = (right - 1 + n)%n;
            cout << left << " " << right << "\n";
            for(ll i=0;i<n;i++){
                cout << pref[i] << " " << suff[i] << "\n";
                // maxl = max(maxl,  max(suff[i], pref[i]));
                // maxl = min(k, maxl);
            }
            cout << "\n";
        }
        else{
            cout << maxl << "\n";
        }
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}