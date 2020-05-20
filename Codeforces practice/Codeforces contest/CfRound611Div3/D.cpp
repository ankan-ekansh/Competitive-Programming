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

    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    ll a[n];
    ll s = LLONG_MAX;
    ll l = LLONG_MIN;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]] = 1;
        s = min(s, a[i]);
        l = max(l, a[i]);
    }
    sort(a, a+n);
    ll t = m;
    ll ans = 0;
    vector<ll> v;
    queue<ll> q;
    while(t){
        for(int i=0;i<n;i++){
            if(mp[a[i]] == 1){
                if(mp[a[i] - 1] == 0){
                    ans++;
                    v.push_back(a[i] - 1);
                    q.push(a[i] - 1);
                    mp[a[i] - 1] = 2;
                    t--;
                }
                if(t==0){
                    break;
                }
                if(mp[a[i] + 1] == 0){
                    ans++;
                    v.push_back(a[i] + 1);
                    q.push(a[i] + 1);
                    mp[a[i] + 1] = 2;
                    t--;
                }
                if(t==0){
                    break;
                }
            }
        }
        while(!q.empty() && t > 0){
            ll x = q.front();
            q.pop();
            if(mp[x - 1] == 0){
                mp[x-1] = 2;
                q.push(x-1);
                v.push_back(x-1);
                t--;
                ans++;
            }
            if(t == 0){
                break;
            }
            if(mp[x + 1] == 0){
                mp[x+1] = 2;
                q.push(x+1);
                v.push_back(x+1);
                t--;
                ans++;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << ans << "\n";
    for(int i=)

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}