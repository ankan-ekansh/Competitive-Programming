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
ll a[500007];
ll tree[4*500007];
void build(ll node, ll start, ll end, ll state){
    if(start == end){
        tree[node] = a[start];
    }
    else{
        ll mid = start + (end - start)/2;
        build(2*node, start, mid, 1 - state);
        build(2*node + 1, mid+1, end, 1 - state);
        if(state == 1){
            tree[node] = tree[2*node] | tree[2*node + 1];
        }
        else{
            tree[node] = tree[2*node] ^ tree[2*node + 1];
        }
    }
}
void update(ll node, ll start, ll end, ll state, ll idx, ll val){
    if(start == end){
        a[idx] = val;
        tree[node] = val;
    }
    else{
        ll mid = start + (end - start)/2;
        if(start <= idx && idx <= mid){
            update(2*node, start, mid, 1 - state, idx, val);
        }
        else{
            update(2*node+1, mid+1, end, 1 - state, idx, val);
        }
        // tree[node] = min(tree[2*node], tree[2*node+1]);
        if(state == 1){
            tree[node] = tree[2*node] | tree[2*node + 1];
        }
        else{
            tree[node] = tree[2*node] ^ tree[2*node + 1];
        }
    }
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
    ll t = binaryExponentiation(2, n);
    for(ll i=1;i<=t;i++){
        cin >> a[i];
    }
    ll state = n % 2;
    build(1, 1, t, state);
    // for(ll i=1;i<=4*t;i++){
    //     cout << tree[i] << " ";
    // }
    for(ll i=0;i<m;i++){
        ll x, y;
        cin >> x >> y;
        update(1, 1, t, state, x, y);
        cout << tree[1] << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}