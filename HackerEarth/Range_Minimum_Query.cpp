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
int n;
int tree[400007];
int a[100007];
void build(int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
    }
    else{
        int mid = (start + end)/2;
        build(2*node, start, mid);
        build(2*node + 1, mid+1, end);
        tree[node] = min(tree[2*node], tree[2*node + 1]);
    }
}
void update(int node, int start, int end, int idx, int val){
    if(start == end){
        a[idx] = val;
        tree[node] = val;
    }
    else{
        int mid = (start + end)/2;
        if(start <= idx && idx <= mid){
            update(2*node, start, mid, idx, val);
        }
        else{
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}
int query(int node, int start, int end, int l, int r){
    if(r < start or end < l){
        return INT_MAX;
    }
    if(l <= start && r >= end){
        return tree[node];
    }
    int mid = (start + end)/2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1, p2);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        tree[i] = INT_MAX;
    }
    build(1, 1, n);
    // for(int i=1;i<=n;i++){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    // for(int i=1;i<=n;i++){
    //     cout << tree[i] << " ";
    // }
    // cout << "\n";
    for(int i=0;i<q;i++){
        char a;
        int b, c;
        cin >> a >> b >> c;
        if(a == 'q'){
            cout << query(1, 1, n, b, c) << "\n";
        }
        else{
            update(1, 1, n, b, c);
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}