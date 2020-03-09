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
string s;
ll prefhash[1000007];
ll prefmodinv[1000007];
ll suffhash[1000007];
ll pows[1000007];
ll p = 33;
ll m = 1e9+7;
ll inv = modPrimeInverse(p, m);
ll n;
ll generate_hash(){

    pows[0] = 1;
    prefmodinv[0] = modPrimeInverse(1, m);
    prefhash[0] = (s[0] - 'a' + 1);
    // cout << pows[0] << "\n";
    // cout << s.substr(0, 0+1) << " " << prefhash[0] << "\n";
    for(ll i=1;i<n;i++){
        pows[i] = (pows[i-1]*p)%m;
        prefmodinv[i] = (prefmodinv[i-1]*inv)%m;
        // cout << pows[i] << "\n";
        prefhash[i] = (prefhash[i-1] + ((s[i]-'a'+1)*(pows[i]))%m)%m;
        // cout << s.substr(0, i+1) << " " << prefhash[i] << "\n";
    }
    // for(ll i=0;i<n;i++){
    //     cout << s.substr(0, i+1) << " " << prefhash[i] << "\n";
    // }
    // suffhash[0] = prefhash[n-1];
    // // cout << prefmodinv[0] << "\n";
    // cout << s.substr(0, n-0+1) << " " << suffhash[0] << "\n";
    // for(ll i=1;i<n;i++){
    //     prefmodinv[i] = (prefmodinv[i-1]*inv)%m;
    //     // prefmodinv[i] = modPrimeInverse(pows[i], m);
    //     suffhash[i] = (((prefhash[n-1] - prefhash[i-1] + m)%m)*prefmodinv[i])%m;
    //     // cout << prefmodinv[i] << "\n";
    //     cout << s.substr(i, n-i+1) << " " << suffhash[i] << "\n";
    // }
    // // for(ll i=0;i<n;i++){
    // //     cout << s.substr(i, n-i+1) << " " << suffhash[i] << "\n";
    // // }
}
ll get_substring_hash(ll l, ll r){
    ll ans = 0;
    if(l > 0)
        ans = (((prefhash[r] - prefhash[l-1])%m)*prefmodinv[l])%m;
    else
        ans = prefhash[r];
    ans = (ans + m) % m;
    // cout << "fun: " << l << ", " << r << " : " << s.substr(l, r-l+1) << " " << ans << "\n";
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    n = s.length();
    generate_hash();
    for(ll i=n-1;i>=0;i--){
        if(get_substring_hash(0, i) != get_substring_hash(n-i-1,n-1)){
            continue;
        }
        bool ok = false;
        for(ll j=1;j+i<n-1;j++){
            if(get_substring_hash(j, j+i) == get_substring_hash(0, i)){
                ok = true;
                break;
            }
        }
        if(ok){
            cout << s.substr(0, i+1) << "\n";
            return 0;
        }
    }
    cout << "Just a legend\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}