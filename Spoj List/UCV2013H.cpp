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
int n, m;
int a[255][255];
bool vis[255][255];
bool check(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m && !vis[i][j] && a[i][j] == 1){
        return true;
    }
    else{
        return false;
    }
}
void dfs(int i, int j, int* ss){
    vis[i][j] = true;
    (*ss)++;
    if(check(i, j-1)){
        dfs(i, j-1, ss);
    }
    if(check(i, j+1)){
        dfs(i, j+1, ss);
    }
    if(check(i-1, j)){
        dfs(i-1, j, ss);
    }
    if(check(i+1, j)){
        dfs(i+1, j, ss);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    while(n != 0 && m != 0){
        memset(vis, false, sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        map<int, int> s;
        int ns = 0, ss = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] == 1 && !vis[i][j]){
                    ss = 0;
                    dfs(i, j, &ss);
                    s[ss]++;
                    ns++;
                }
            }
        }
        cout << ns << "\n";
        for(auto i=s.begin();i!=s.end();i++){
            cout <<(*i).first << " " << (*i).second << "\n";
        }
        cin >> n >> m;
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}