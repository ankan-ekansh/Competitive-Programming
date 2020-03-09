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
ll n;
ll tree[400007];
ll tree2[400007];
ll a[100007];
void build(ll node, ll start, ll end){
    if(start == end){
        tree[node] = a[start];
        tree2[node] = a[start];
    }
    else{
        ll mid = (start + end)/2;
        build(2*node, start, mid);
        build(2*node + 1, mid+1, end);
        // tree[node] = min(tree[2*node], tree[2*node + 1]);
        // tree[node] = max(tree[node], tree[2*node] + tree[2*node + 1]);
        // tree[node] = max(tree[node], max(tree[2*node], tree[2*node + 1]));
        tree[node] = tree[2*node] + tree[2*node + 1];
        tree2[node] = max(tree2[node], max(tree[node], max(tree[2*node], tree[2*node + 1])));
    }
}
// void update(ll node, ll start, ll end, ll idx, ll val){
//     if(start == end){
//         a[idx] = val;
//         tree[node] = val;
//     }
//     else{
//         ll mid = (start + end)/2;
//         if(start <= idx && idx <= mid){
//             update(2*node, start, mid, idx, val);
//         }
//         else{
//             update(2*node+1, mid+1, end, idx, val);
//         }
//         tree[node] = min(tree[2*node], tree[2*node+1]);
//     }
// }
ll query(ll node, ll start, ll end, ll l, ll r){
    if(r < start or end < l){
        return -1000000000000000;
    }
    if(l <= start && r >= end){
        // return max(*(ans), tree[node]);
        return tree2[node];
    }
    ll mid = (start + end)/2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    cout << p1 << " " << p2 << "\n";
    return max(max(p1, p2), p1 + p2);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=4*n;i++){
        tree[i] = -1000000000000000;
        tree2[i] = -1000000000000000;
    }
    for(ll i=1;i<=4*n;i++){
        cout << tree[i] << " ";
    }
    cout << "\n";
    for(ll i=1;i<=4*n;i++){
        cout << tree2[i] << " ";
    }
    cout << "\n";
    build(1, 1, n);
    ll q;
    cin >> q;
    for(ll i=1;i<=4*n;i++){
        cout << tree[i] << " ";
    }
    cout << "\n";
    for(ll i=1;i<=4*n;i++){
        cout << tree2[i] << " ";
    }
    cout << "\n";
    for(ll i=1;i<=q;i++){
        ll l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}