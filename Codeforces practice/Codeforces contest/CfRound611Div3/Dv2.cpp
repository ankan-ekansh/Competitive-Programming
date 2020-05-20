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
    int a[n];
    set<int> points;
    queue<int> q;
    map<int, int> mp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        points.insert(a[i]);
        q.push(a[i]);
        mp[a[i]] = 0;
    }
    int ct = 0;
    vector<int> ans;
    ll dis = 0;
    while(!q.empty() && ct < m){
        int u = q.front();
        q.pop();
        if(!points.count(u - 1)){
            points.insert(u - 1);
            q.push(u-1);
            ct++;
            // cout << u-1 << " ";
            ans.push_back(u-1);
            mp[u-1] = mp[u] + 1;
            dis+=mp[u-1];
        }
        if(ct == m){
            break;
        }
        if(!points.count(u + 1)){
            points.insert(u + 1);
            q.push(u + 1);
            // cout << u+1 << " ";
            ans.push_back(u+1);
            mp[u+1] = mp[u] + 1;
            dis+=mp[u+1];
            ct++;
        }
    }
    cout << dis << "\n";
    for(auto i : ans){
        cout << i << " ";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}