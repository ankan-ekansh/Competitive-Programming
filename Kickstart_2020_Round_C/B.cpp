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
char a[37][37];
bool vis[37][37];
ll r, c;
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};
bool flag;
bool check(ll i, ll j){
    return (i >=0 && i < r && j>=0 && j < c);
}
ll visct = 0;
void bfs(ll x, ll y){
    queue<pair<ll, ll>> q;
    q.push({x, y});
    vis[x][y] = true;
    visct++;
    while(!q.empty()){
        pair<ll, ll> p = q.front();
        q.pop();
        ll ux = p.first, uy = p.second;
        if(check(ux+1, uy)){
            if(!vis[ux+1][uy]){
                // cout << ux << " " << uy << " : " << ux+1 << " " << uy << "\n";
                // cout << "----\n";
                visct = 0;
                break;
            }
        }
        // cout << ux << " " << uy << "\n";
        while(check(ux, uy+1) && !vis[ux][uy+1] && a[ux][uy+1] == a[ux][uy]){
            q.push({ux, uy+1});
            vis[ux][uy+1] = true;
            visct++;
            uy++;
        }
        ux = p.first, uy = p.second;
        while(check(ux, uy-1) && !vis[ux][uy-1] && a[ux][uy-1] == a[ux][uy]){
            q.push({ux, uy-1});
            vis[ux][uy-1] = true;
            visct++;
            uy--;
        }
        ux = p.first, uy = p.second;
        while(check(ux-1, uy) && !vis[ux-1][uy] && a[ux-1][uy] == a[ux][uy]){
            q.push({ux-1, uy});
            vis[ux-1][uy] = true;
            visct++;
            ux--;
        }
        ux = p.first, uy = p.second;
        while(check(ux+1, uy) && !vis[ux+1][uy] && a[ux+1][uy] == a[ux][uy]){
            q.push({ux+1, uy});
            vis[ux+1][uy] = true;
            visct++;
            ux++;
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
    int t;
    cin>>t;
    int tc=1;
    while(t--){
 
        
        cin >> r >> c;
        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                cin >> a[i][j];
            }
        }
        flag = false;
        for(ll i=0;i<c;i++){
            memset(vis, false, sizeof(vis));
            visct = 0;
            // cout << "Starting 1st bfs from " << r-1 << ", " << i << "\n";
            // unordered_set<char> s;
            vector<char> s;
            // s.insert(a[r-1][i]);
            s.push_back(a[r-1][i]);
            bfs(r-1, i);
            for(ll j=r-1;j>=0;j--){
                for(ll k=0;k<c;k++){
                    if(i == k){
                        continue;
                    }
                    if(!vis[j][k]){
                        // s.insert(a[j][k]);
                        s.push_back(a[j][k]);
                        bfs(j, k);
                    }
                }
            }
            if(visct == r*c){
                // cout << "YES\n";
                cout << "Case #" << tc++ << ":" << " ";
                flag = true;
                for(auto c : s){
                    cout << c;
                }
                cout << "\n";
                break;
            }
            memset(vis, false, sizeof(vis));
            s.clear();
            visct = 0;
            // cout << "Starting 1st bfs from " << r-1 << ", " << i << "\n";
            // s.insert(a[r-1][i]);
            s.push_back(a[r-1][i]);
            bfs(r-1, i);
            for(ll j=r-1;j>=0;j--){
                for(ll k=c-1;k>=0;k--){
                    if(i == k){
                        continue;
                    }
                    if(!vis[j][k]){
                        // s.insert(a[j][k]);
                        s.push_back(a[j][k]);
                        bfs(j, k);
                    }
                }
            }
            if(visct == r*c){
                // cout << "YES\n";
                cout << "Case #" << tc++ << ":" << " ";
                flag = true;
                for(auto c : s){
                    cout << c;
                }
                cout << "\n";
                break;
            }
        }
        if(!flag){
            cout << "Case #" << tc++ << ":" << " -1\n";
        }
        // cout << flag << "\n";

        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}