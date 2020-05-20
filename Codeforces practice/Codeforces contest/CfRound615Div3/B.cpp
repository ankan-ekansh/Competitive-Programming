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
int im, jm;
bool check(int i, int j){
    if(i <= im && j <= jm){
        return true;
    }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        map<pair<int, int>, int> m;
        int n;
        cin >> n;
        pair<int, int> p[n];
        bool flag = true;
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            im = max(im, a);
            jm = max(jm, b);
            p[i] = {a, b};
            m[{a, b}]++;
            if(a < 0 || b < 0){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << "NO\n";
        }
        else{
            bool vis[1007][1007];
            char par[1007][1007];
            for(int i=0;i<1007;i++){
                for(int j=0;j<1007;j++){
                    par[i][j] = '-';
                }
            }
            // memset(par, '-', sizeof(par));
            memset(vis, false, sizeof(vis));
            queue<pair<int, int>> q;
            q.push({0, 0});
            vis[0][0] = true;
            par[0][0] = '0';
            while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();
                int ux = p.first;
                int uy = p.second;
                if(!vis[ux + 1][uy] && check(ux+1, uy)){
                    q.push(make_pair(ux+1, uy));
                    vis[ux+1][uy] = true;
                    par[ux+1][uy] = 'R';
                }
                if(!vis[ux][uy+1] && check(ux, uy+1)){
                    q.push(make_pair(ux, uy+1));
                    vis[ux][uy+1] = true;
                    par[ux][uy+1] = 'U';
                }
            }
            for(int i=0;i<n;i++){
                if(vis[p[i].first][p[i].second] == false){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                cout << "NO\n";
            }
            else{
                while(par[im][jm] != '0'){
                    cout << par[im][jm];
                    if(par[im][jm] == 'U'){
                        im--;
                    }
                    else if(par[im][jm] == 'R'){
                        jm--;
                    }
                }
                cout << "\n";
            }
        }


 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}