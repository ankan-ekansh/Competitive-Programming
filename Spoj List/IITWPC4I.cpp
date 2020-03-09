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
    ll parent[300007], nodes, edges;
    unordered_map<ll, ll> m;
    pair<ll, pair<ll, ll>> p[300007];
    void make_set(){
        for(ll i=0;i<300007;i++){
            parent[i] = i;
        }
    }
    ll find_parent(ll x){
        ll temp = x;
        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return parent[temp] = x;
    }
    void union_set(ll a, ll b){
        ll x = find_parent(a);
        ll y = find_parent(b);
        // cout << x << " " << parent[x] << ", " << y << " " << parent[y] << "\n";
        // parent[x] = parent[y];
        // cout << x << " " << parent[x] << ", " << y << " " << parent[y] << "\n";
        // // cout << m[parent[x]] << " " << m[parent[y]] << "\n";
        // m[parent[x]] = m[parent[x]] || m[parent[y]];
        // cout << m[parent[x]] << " " << m[parent[y]] << "\n";
        if(m[parent[x]] == 1 && m[parent[y]] == 0){
            parent[y] = parent[x];
            m[parent[y]] = m[parent[x]];
        }
        else if(m[parent[y]] == 1 && m[parent[x]] == 0){
            parent[x] = parent[y];
            m[parent[x]] = m[parent[y]];
        }
        else{
            parent[x] = parent[y];
            m[parent[x]] = m[parent[y]];
        }
    }
    ll kruskal(){
        ll minimumCost = 0, cost, x, y;
        for(ll i=0;i<edges;i++){
            x = p[i].second.first;
            y = p[i].second.second;
            cost = p[i].first;
            if(find_parent(x) != find_parent(y)){
                if(m[find_parent(x)] && m[find_parent(y)]){
                    continue;
                }
                union_set(x, y);
                minimumCost+=cost;
            }
        }
        return minimumCost;
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
            make_set();
            m.clear();
            cin >> nodes;
            cin >> edges;
            for(ll i=1;i<=nodes;i++){
                ll x;
                cin >> x;
                m[i] = x;
            }
            for(ll i=0;i<edges;i++){
                ll x, y, cost;
                cin >> x >> y >> cost;
                p[i] = make_pair(cost, make_pair(x, y));
            }
            sort(p, p+edges);
            ll ans = kruskal();
            bool flag = true;
            for(ll i=1;i<=nodes;i++){
                // cout << i << " - " << m[i] << " ; " << parent[i] << "\n";
                if(m[find_parent(i)] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << ans << "\n";
            }
            else{
                cout << "impossible\n";
            }
            
     
        }
        #ifndef ONLINE_JUDGE
            cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
        #endif
        return 0;
    } 