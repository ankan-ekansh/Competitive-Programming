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
    char grid[101][101];
    // unordered_map<pair<int, int>, pair<int, int>> parent;
    pair<int, int> parent[101][101];
    int dist[101][101];
    bool vis[101][101];
    int w, h;
    vector<pair<int, int>> path;
    bool check(int x, int y){
        if(x >= 0 && x < h && y >= 0 && y < w && !vis[x][y]){
            return true;
        }
        else{
            return false;
        }
    }
    void bfs(pair<int, int> s, pair<int, int> d){
        queue<pair<int, int>> q;
        q.push(s);
        vis[s.first][s.second] = true;
        dist[s.first][s.second] = 0;
        parent[s.first][s.second] = make_pair(-1, -1);
        while(!q.empty()){
            pair<int, int> u = q.front();
            int ux = u.first;
            int uy = u.second;
            q.pop();
            // if(ux == d.first && uy == d.second){
            //     return;
            // }
            if(check(ux, uy-1)){
                dist[ux][uy-1] = dist[ux][uy] + 1;
                parent[ux][uy-1] = make_pair(ux, uy);
                vis[ux][uy-1] = true;
                q.push(make_pair(ux, uy-1));
            }
            if(check(ux, uy+1)){
                dist[ux][uy+1] = dist[ux][uy] + 1;
                parent[ux][uy+1] = make_pair(ux, uy);
                vis[ux][uy+1] = true;
                q.push(make_pair(ux, uy+1));
            }
            if(check(ux-1, uy)){
                dist[ux-1][uy] = dist[ux][uy] + 1;
                parent[ux-1][uy] = make_pair(ux, uy);
                vis[ux-1][uy] = true;
                q.push(make_pair(ux-1, uy));
            }
            if(check(ux+1, uy)){
                dist[ux+1][uy] = dist[ux][uy] + 1;
                parent[ux+1][uy] = make_pair(ux, uy);
                vis[ux+1][uy] = true;
                q.push(make_pair(ux+1, uy));
            }
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
        
        cin >> w >> h;
        vector<pair<int, int>> l;
        for(int i=0;i<h;i++){
            string str;
            cin >> str;
            for(int j=0;j<w;j++){
                grid[i][j] = str[j];
                if(grid[i][j] == 'C'){
                    l.push_back(make_pair(i, j));
                }
                if(grid[i][j] == '*'){
                    vis[i][j] = true;
                }
            }
        }
        // cout << l[0].first << " " << l[0].second << "\n";
        // cout << l[1].first << " " << l[1].second << "\n";
        bfs(l[0], l[1]);
        cout << dist[l[1].first][l[1].second] << "\n";
        path.push_back(l[1]);
        pair<int, int> temp = parent[l[1].first][l[1].second];
        while(temp.first != -1 && temp.second != -1){
            path.push_back(temp);
            cout << temp.first << " " << temp.second << "\n";
            grid[temp.first][temp.second] = '-';
            temp = parent[temp.first][temp.second];
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        int mirrors = 0;
        for(int i=1;i<path.size()-1;i++){
            int x0 = path[i-1].first;
            int y0 = path[i-1].second;
            int x1 = path[i].first;
            int y1 = path[i].second;
            int x2 = path[i+1].first;
            int y2 = path[i+1].second;
            if((x0 == x1 && y1 == y2) || (y0 == y1 && x1 == x2)){
                mirrors++;
            }
        }
        cout << mirrors << "\n";
     
        #ifndef ONLINE_JUDGE
            cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
        #endif
        return 0;
    } 