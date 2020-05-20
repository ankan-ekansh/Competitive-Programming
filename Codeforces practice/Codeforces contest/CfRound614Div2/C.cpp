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
bool a[3][100007];
bool check(int i, int j){
    if(i >= 1 && i <= n && j >= 1 && j <= 2){
        return true;
    }
    return false;
}
int lava_nodes;
void check_lava(int i, int j){
    if(a[i][j] == true){
        if(i == 1){
            if(a[2][j] == true)
                lava_nodes++;
            if(a[2][j-1] == true)
                lava_nodes++;
            if(a[2][j+1] == true)
                lava_nodes++;
            
        }
        else{
            if(a[1][j] == true)
                lava_nodes++;
            if(a[1][j-1] == true)
                lava_nodes++;
            if(a[1][j+1] == true)
                lava_nodes++;
        }
    }
    if(a[i][j] == false){
        if(i == 1){
            if(a[2][j] == true)
                lava_nodes--;
            if(a[2][j-1] == true)
                lava_nodes--;
            if(a[2][j+1] == true)
                lava_nodes--;
            
        }
        else{
            if(a[1][j] == true)
                lava_nodes--;
            if(a[1][j-1] == true)
                lava_nodes--;
            if(a[1][j+1] == true)
                lava_nodes--;
        }
    }
}
void update_lava(int i, int j){
    a[i][j] = !(a[i][j]);
    // cout << a[i][j] << "\n";
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(a, false, sizeof(a));
    int t;
    cin >> n;
    cin >> t;
    while(t--){
 
        int x, y;
        cin >> x >> y;
        update_lava(x, y);
        check_lava(x, y);
        // cout << "Lava nodes :" << lava_nodes << "\n";
        if(lava_nodes > 0){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}