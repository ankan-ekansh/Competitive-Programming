#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[57][57];
int l;
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
bool check(int i, int j, bool vis[][57], int h, int w){
    if(i>=0 && i < h && j>=0 && j<w && vis[i][j] == false){
        return true;
    }
    else{
        return false;
    }
}
void bfs(int x, int y, int h, int w){
    bool vis[57][57];
    int dis[57][57];
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    vis[x][y] = true;
    dis[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        pair<int, int> p = q.front();
        int px = p.first;
        int py = p.second;
        // cout << px << " " << py << " " << a[px][py] << " " << dis[px][py] << " " << l << "\n";
        q.pop();
        if(check(px-1, py-1, vis, h, w) && (int)(a[px-1][py-1] - a[px][py]) == 1){
            vis[px-1][py-1] = true;
            dis[px-1][py-1] = dis[px][py] + 1;
            l = max(l, dis[px-1][py-1]);
            q.push(make_pair(px-1, py-1));
        }
        if(check(px-1, py, vis, h, w) && (int)(a[px-1][py] - a[px][py]) == 1){
            vis[px-1][py] = true;
            dis[px-1][py] = dis[px][py] + 1;
            l = max(l, dis[px-1][py]);
            q.push(make_pair(px-1, py));
        }
        if(check(px-1, py+1, vis, h, w) && (int)(a[px-1][py+1] - a[px][py]) == 1){
            vis[px-1][py+1] = true;
            dis[px-1][py+1] = dis[px][py] + 1;
            l = max(l, dis[px-1][py+1]);
            q.push(make_pair(px-1, py+1));
        }
        if(check(px, py+1, vis, h, w) && (int)(a[px][py+1] - a[px][py]) == 1){
            vis[px][py+1] = true;
            dis[px][py+1] = dis[px][py] + 1;
            l = max(l, dis[px][py+1]);
            q.push(make_pair(px, py+1));
        }
        if(check(px+1, py+1, vis, h, w) && (int)(a[px+1][py+1] - a[px][py]) == 1){
            vis[px+1][py+1] = true;
            dis[px+1][py+1] = dis[px][py] + 1;
            l = max(l, dis[px+1][py+1]);
            q.push(make_pair(px+1, py+1));
        }
        if(check(px+1, py, vis, h, w) && (int)(a[px+1][py] - a[px][py]) == 1){
            vis[px+1][py] = true;
            dis[px+1][py] = dis[px][py] + 1;
            l = max(l, dis[px+1][py]);
            q.push(make_pair(px+1, py));
        }
        if(check(px+1, py-1, vis, h, w) && (int)(a[px+1][py-1] - a[px][py]) == 1){
            vis[px+1][py-1] = true;
            dis[px+1][py-1] = dis[px][py] + 1;
            l = max(l, dis[px+1][py-1]);
            q.push(make_pair(px+1, py-1));
        }
        if(check(px, py-1, vis, h, w) && (int)(a[px][py-1] - a[px][py]) == 1){
            vis[px][py-1] = true;
            dis[px][py-1] = dis[px][py] + 1;
            l = max(l, dis[px][py-1]);
            q.push(make_pair(px, py-1));
        }
    }    
    // cout << "\n";
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, w;
    cin >> h >> w;
    int t=1;
    while(h != 0 && w != 0){
        l=0;
        vector<pair<int, int>> p;
        for(int i=0;i<h;i++){
            string s;
            cin >> s;
            for(int j=0;j<w;j++){
                a[i][j] = s[j];
                // cout << a[i][j] << " ";
                if(s[j] == 'A'){
                    p.push_back(make_pair(i, j));
                }
            }
            // cout << "\n";
        }
        for(auto i=p.begin();i!=p.end();i++){
            bfs((*i).first, (*i).second, h, w);
        }
        cout << "Case " << t++ << ": ";
        if(p.size() == 0)
            cout << l << "\n";
        else
            cout << l + 1 << "\n";
        cin >> h >> w;
    }



    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}