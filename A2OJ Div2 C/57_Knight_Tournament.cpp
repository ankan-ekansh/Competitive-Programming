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
    
    ll n, m;
    cin >> n >> m;
    ll ans[n+7] = {0};
    set<ll> alive;
    for(ll i=1;i<=n;i++){
        alive.insert(i);
    }
    for(ll i=0;i<m;i++){
        ll l, r, x;
        cin >> l >> r >> x;
        // l--;r--;x--;
        auto it = alive.lower_bound(l);
        vector<ll> defeat;
        while(it != alive.end()){
            if(*it > r){
                break;
            }
            if(*it != x){
                defeat.push_back(*it);
                ans[*it] = x;
            }
            it++;
        }
        for(ll i=0;i<defeat.size();i++){
            alive.erase(defeat[i]);
        }
    }
    for(ll i=1;i<=n;i++){
        cout << ans[i] << " ";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}



































// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// ll modularExponentiation(ll x,ll n,ll M){
//     if(n==0)
//         return 1;
//     else if(n%2 == 0)
//         return modularExponentiation((x*x)%M,n/2,M);
//     return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
// }
// ll binaryExponentiation(ll x,ll n){
//     if(n==0)
//         return 1;
//     else if(n%2 == 0)
//         return binaryExponentiation(x*x,n/2);
//     else
//         return x*binaryExponentiation(x*x,(n-1)/2);
// }
// ll GCD(ll A, ll B){
//     if(B==0)
//         return A;
//     else
//         return GCD(B, A % B);
// }
// ll extended_GCD(ll a , ll b , ll &x , ll &y){
//     if(a == 0){
//         x = 0;
//         y = 1;
//         return b;
//     }
//     ll x1 , y1;
//     ll gcd = extended_GCD(b%a , a , x1 , y1);
//     x = y1 - (b/a)*x1;
//     y = x1;
//     return gcd;
// }
// ll modinv(ll a , ll mod){
//     ll x , y;
//     extended_GCD(a , mod , x , y);
//     if(x < 0) x += mod;
//     return x;
// }
// ll modPrimeInverse(ll A,ll M){
//     return modularExponentiation(A,M-2,M);
// }
// int n, m;
// int ans[300007], nex[300007];
// int getnex(int v){
//     if(v == nex[v]){
//         return v;
//     }
//     return nex[v] = getnex(nex[v]);
// }
// int main(){
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "rt", stdin);
//         // freopen("output.txt", "wt", stdout);
//     #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
    
//     cin >> n >> m;
//     nex[0] = 1;
//     for(int i=1;i<=n;i++){
//         nex[i] = i;
//     }
//     int alive = n;
//     for(int i=0;i<m;i++){
//         int l, r, x;
//         cin >> l >> r >> x;
//         int cur = getnex(l);
//         // if(alive == 1){
//         //     break;
//         // }
//         int ctr = 0;
//         while(cur <= r){
//             ctr++;
//             // if(cur == n && nex[cur] == cur){
//             //     cout << "last case\n";
//             //     break;
//             // }
//             if(cur == x){
//                 cout << "cur go brrrrrrrrrr " << cur << " " << nex[cur] << "\n";
//                 cur = cur + 1;
//                 if(alive == 1){
//                     break;
//                 }
//             }
//             else{
//                 ans[cur] = x;
//                 nex[cur] = cur + 1;
//                 alive--;
//             }
//             // if(cur == n){
//             //     cout << "cur go brrr\n";
//             //     cout << nex[cur] << "\n";
//             //     break;
//             // }
//             cur = getnex(cur);
//             if(alive == 1){
//                 break;
//             }
//             if(ctr == 1000){
//                 break;
//             }
//         }
//         if(x == n){
//             nex[x] = 0;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         cout << ans[i] << " ";
//     }

//     #ifndef ONLINE_JUDGE
//         cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
//     #endif
//     return 0;
// }