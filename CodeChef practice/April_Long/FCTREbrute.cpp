#include<bits/stdc++.h>
typedef long long ll;
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
ll nodes, edges;
vector<ll> adj[100007];
ll timer;
vector<ll> tin(100007), tout(100007);
vector<vector<ll>> par(100007, vector<ll>(20));
vector<ll> a(100007);
unordered_map<ll, ll> spf;
vector<ll> product(100007, 1);
unordered_map<ll, unordered_map<ll, ll>> m1;
unordered_map<ll, unordered_map<ll, ll>> m2;
#define mod 1000000007
ll N = 1000001;
void sieve(){
    spf[1] = 1;
    for(ll i = 2; i < N; i++){
        spf[i] = i;
    }
    for(ll i=4;i<N;i+=2){
        spf[i] = 2;
    }
    for(ll i=3;i*i<N;i++){
        if(spf[i] == i){
            for(ll j=i*i;j<N;j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}
void getFactorization(ll x){
    ll tmp = x;
    while(x != 1){
        m1[tmp][spf[x]]++;
        // m2[tmp][spf[x]]++;
        x = x / spf[x];
    }
}
void fun(ll n){
    ll tmp = n;
	// int c = 0;
	while(n % 2 == 0){
		// cout << "2 ";
        m1[tmp][2]++;
		// c=1;
		n/=2;
	}
	for(ll i=3;i*i<=n;i+=2){
		while(n % i == 0){
			// cout << i << " ";
            m1[tmp][i]++;
			// c++;
			n/=i;
		}
		// c++;
	}
	if(n > 2){
		// cout << n << " ";
        m1[tmp][n]++;
		// c++;
	}
	// return c;
}
ll f(ll p){
    ll ans = 1;
    ll c = 0;
    while(p % 2 == 0){
        c++;
        p/=2;
    }
    ans = (ans * (c+1)) % mod;
    c = 0;
    for(ll i=3;i*i<=p;i+=2){
        c = 0;
        while(p % i == 0){
            c++;
            p/=i;
        }
        ans = (ans * (c+1)) % mod;
    }
    if(p > 2){
        c = 1;
        ans = (ans * (c+1)) % mod;
    }
    return ans;
}
void dfs(ll currentNode = 1, ll parentNode = 1){
    tin[currentNode] = ++timer;
    par[currentNode][0] = parentNode;
    product[currentNode] = product[parentNode] * a[currentNode];
    for(ll i=1;i<=(ll)(ceil(log2(nodes)));i++){
        par[currentNode][i] = par[par[currentNode][i-1]][i-1];
    }
    for(ll nextNode : adj[currentNode]){
        if(nextNode == parentNode){
            continue;
        }
        // for(auto p : m2[a[currentNode]]){
        //     m2[a[nextNode]][p.first] += m2[a[currentNode]][p.first];
        // }
        dfs(nextNode, currentNode);
    }
    tout[currentNode] = ++timer;
}
bool isAncestor(ll u, ll v){        // u is ancestor of v
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
ll lca(ll u, ll v){
    if(isAncestor(u, v)){
        return u;
    }
    if(isAncestor(v, u)){
        return v;
    }
    for(ll i = (ll)ceil(log2(nodes)); i>=0; i--){
        if(!isAncestor(par[u][i], v)){
            u = par[u][i];
        }
    }
    return par[u][0];
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // for(ll i=1;i<=1000000;i++){
    //     fun(i);
    // }
    // sieve();
    ll t;
    cin >> t;
    while(t--){
        cin >> nodes;
        edges = nodes - 1;
        timer = 0;
        product.assign(100007, 1);
        // m2.clear();
        for(int i=0;i<100007;i++){
            adj[i].clear();
        }
        for(int i=0;i<edges;i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=1;i<=nodes;i++){
            cin >> a[i];
            // if(m1[a[i]].empty()){
            //     fun(a[i]);
            //     // getFactorization(a[i]);
            // }
            // m2[a[i]] = m1[a[i]];
        }
        dfs();
        ll q;
        cin >> q;
        while(q--){
            int u, v;
            cin >> u >> v;
            // cout << u << " " << v << " : ";
            // cout << lca(u, v) << "\n";
            // cout << product[u] << " " << product[v] << "\n";
            // cout << (product[u] * product[v] * product[lca(u, v)])/(product[lca(u, v)] * product[lca(u, v)]) << "\n";
            // if(isAncestor(u, v)){
            //     cout << product[v] / product[par[u][0]] << "\n";
            // }
            // else if(isAncestor(v, u)){
            //     cout << product[u] / product[par[v][0]] << "\n";
            // }
            // else{
            int ancestor = lca(u, v);
            ll p = (product[u] * product[v] * a[ancestor])/((product[ancestor]) * (product[ancestor]));
            cout << f(p) << '\n';
            // cout << (product[u] * product[v] * a[ancestor])/((product[ancestor]) * (product[ancestor])) << "\n";
            // }
            // unordered_map<ll, ll> pws;
            // // cout << "u : " << u << " a[u] : " << a[u] << " :- a[1-u] : ";
            // for(auto p : m2[a[u]]){
            //     pws[p.first]+=p.second;
            //     // cout << p.first << "^" << p.second << " * ";
            // }
            // // cout << "\n";
            // // cout << "v : " << v << " a[v] : " << a[v] << " :- a[1-v] : ";
            // for(auto p : m2[a[v]]){
            //     pws[p.first]+=p.second;
            //     // cout << p.first << "^" << p.second << " * ";
            // }
            // // cout << "\n";
            // // cout << "lca : " << ancestor << " a[lca] : " << a[ancestor] << " :- a[lca] : ";
            // for(auto p : m1[a[ancestor]]){
            //     pws[p.first]+=p.second;
            //     // cout << p.first << "^" << p.second << " * ";
            // }
            // // cout << "\n";
            // // cout << "1-lca : " << ancestor << " a[lca] : " << a[ancestor] << " :- a[1-lca] : ";
            // for(auto p : m2[a[ancestor]]){
            //     pws[p.first]-=(2*p.second);
            //     // cout << p.first << "^" << p.second << " * ";
            // }
            // ll ans = 1;
            // for(auto p : pws){
            //     // cout << p.first << "^" << p.second << " * ";
            //     ans = ((ans * (p.second + 1)))%mod;
            // }
            // // cout << "\n";
            // cout << ans << "\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}



/*
1000
4 10
5 7
10 6
4 5
9 4
2 6
7 7
4 4
7 10
1 9
9 7
9 6
7 2
2 1
9 1
9 4
9 1
2 9
5 3
1 3
10 5
5 7
5 6
5 4
3 3
7 1
5 2
2 3
3 8
9 10
2 2
10 8
6 9
7 1
10 10
7 8
9 3
9 4
10 1
7 5
2 9
2 6
10 7
1 3
6 4
5 8
10 2
7 3
9 2
3 8
4 10
9 1
9 8
8 7
6 1
3 6
5 10
9 5
8 10
4 7
8 9
7 7
5 1
7 5
10 6
7 4
4 6
3 4
1 4
5 9
8 4
7 6
9 3
1 5
9 2
1 5
2 3
8 4
8 3
5 2
6 1
2 7
9 5
1 8
2 5
2 4
10 6
10 6
9 5
3 7
10 4
1 10
7 5
6 1
3 5
7 6
2 5
6 4
9 5
1 2
3 3
8 7
6 2
4 4
4 2
6 4
3 9
6 8
7 10
3 7
6 3
9 9
3 2
10 4
2 1
8 2
9 9
5 7
9 10
10 3
5 2
2 2
7 3
4 5
10 2
3 8
3 7
7 1
8 2
7 8
6 8
9 5
6 3
10 5
8 5
1 2
7 9
7 5
3 9
3 10
8 4
8 8
5 8
8 6
7 1
9 8
2 7
1 4
8 2
1 10
2 3
2 3
9 6
1 9
7 7
5 3
9 3
7 6
1 4
1 2
5 2
4 2
10 3
4 5
9 10
1 6
9 10
3 3
6 10
10 6
5 1
8 9
3 10
6 3
6 6
2 3
10 8
6 4
6 3
5 5
8 9
4 5
6 8
4 5
6 1
9 7
8 8
1 7
8 10
6 7
1 6
1 8
9 9
7 10
10 6
10 10
5 9
9 10
8 8
2 4
1 4
5 4
5 3
8 7
9 7
8 10
2 7
7 3
9 9
4 8
9 6
1 4
5 4
7 6
1 2
3 2
6 1
4 1
4 2
3 6
1 10
4 4
9 1
6 8
8 10
1 9
5 7
6 9
8 10
10 10
5 9
9 9
7 7
7 2
5 10
9 5
4 2
9 2
8 7
2 1
2 6
6 5
2 9
3 9
5 8
10 8
3 10
5 6
2 10
2 5
4 4
4 10
1 1
10 6
3 10
4 4
5 2
8 2
3 1
5 7
7 8
6 9
4 9
8 10
6 1
1 7
4 10
8 3
1 3
10 5
1 9
6 9
10 4
9 4
7 9
6 5
7 9
6 2
1 1
4 1
4 9
9 3
8 1
2 1
9 6
2 3
8 7
5 8
8 7
2 2
6 5
3 8
1 6
4 3
9 8
5 7
8 1
1 3
7 10
3 8
9 4
9 9
3 2
1 1
9 8
8 10
2 9
10 9
7 10
5 3
5 6
3 10
6 8
9 5
5 8
4 2
5 4
4 2
7 6
9 7
7 6
3 5
1 3
4 8
9 8
6 10
10 10
3 4
4 1
7 4
1 5
9 8
9 4
7 8
9 6
1 3
6 6
3 6
10 7
1 2
2 9
1 6
1 6
2 1
7 6
10 10
5 4
8 10
7 8
5 6
7 5
10 8
8 5
6 6
7 8
4 7
3 7
2 9
10 3
8 2
2 7
1 9
5 6
2 4
6 3
8 4
9 10
4 2
4 5
8 5
7 8
9 3
5 7
7 8
2 4
2 4
10 3
3 4
10 3
9 3
2 10
4 1
4 9
5 4
6 10
8 1
6 8
8 3
5 8
1 6
3 8
10 2
7 3
5 8
8 10
9 5
7 10
10 10
2 9
6 10
9 7
10 9
2 2
8 8
5 2
2 7
5 7
5 3
8 9
8 3
10 2
9 3
5 9
6 8
2 8
4 1
7 5
10 10
4 3
10 5
1 2
4 4
7 10
5 7
4 3
5 10
7 7
3 1
3 8
7 6
8 1
7 3
5 3
8 9
5 6
3 4
3 9
3 7
5 9
1 9
10 2
9 3
2 5
10 10
3 6
6 5
4 10
5 5
5 10
8 9
8 1
6 10
8 9
7 4
6 7
4 2
3 1
10 10
7 9
1 1
10 3
7 2
4 10
3 6
3 10
2 8
4 5
8 2
10 8
5 1
2 6
8 2
9 4
2 5
1 10
7 6
4 3
4 1
2 5
6 9
3 3
2 7
1 10
7 9
9 3
1 3
3 8
7 8
1 1
5 7
2 5
7 7
6 9
8 5
9 1
6 4
9 9
2 2
4 10
8 9
5 6
9 1
9 5
5 3
10 4
5 6
7 1
10 7
4 6
7 8
7 8
2 6
6 4
10 7
9 4
9 3
3 5
2 1
9 8
9 2
10 6
1 2
1 8
5 5
4 1
7 4
4 9
5 1
1 1
3 10
9 9
1 4
2 9
8 10
7 3
2 4
2 5
7 6
5 8
8 9
10 3
9 6
6 5
10 1
3 6
1 7
5 1
6 10
5 3
8 10
8 10
7 4
6 7
9 8
1 3
1 10
9 5
8 3
4 8
6 5
8 5
2 6
4 5
10 6
2 2
4 6
3 8
2 9
9 7
4 7
10 8
2 9
10 6
3 10
1 9
4 10
5 2
4 2
2 6
3 1
2 9
9 9
10 2
9 2
1 3
1 8
7 5
1 8
9 7
10 4
8 8
2 10
4 3
5 9
4 3
5 10
7 8
7 8
3 5
7 1
3 7
4 4
4 7
1 1
3 8
8 8
8 2
7 6
6 1
9 7
8 1
3 9
4 2
6 8
1 6
6 10
2 4
1 6
1 7
2 5
8 5
3 5
6 4
7 4
3 7
5 10
5 2
5 6
8 8
9 8
5 7
1 8
4 8
10 7
8 2
2 6
2 10
5 4
10 3
9 4
6 6
1 1
2 6
3 9
5 9
1 1
9 9
10 5
6 6
2 5
9 3
1 4
6 7
7 4
2 10
5 3
5 7
1 1
6 10
8 4
2 1
3 2
3 2
3 4
3 1
3 4
4 2
1 4
1 10
2 6
10 9
7 9
7 5
2 9
10 6
9 6
8 2
5 1
3 6
6 10
5 8
8 3
2 1
8 8
9 9
5 1
2 4
8 9
3 8
10 9
10 3
1 10
3 7
3 5
5 5
10 5
1 2
5 2
6 3
4 8
3 5
2 6
7 3
1 2
9 1
6 6
1 4
9 4
9 4
5 6
3 4
9 10
8 5
10 9
5 10
7 1
6 9
9 1
3 5
3 9
2 5
10 2
2 6
4 1
9 5
10 3
6 2
1 8
10 10
2 6
5 8
4 7
9 7
10 1
10 10
9 8
7 1
7 5
5 5
3 3
4 7
8 9
10 4
1 3
8 1
6 7
10 9
7 8
2 5
1 5
1 2
6 9
7 6
4 7
8 4
6 2
1 6
6 1
4 10
2 5
8 2
3 3
8 8
1 10
9 7
3 10
2 3
6 2
8 5
8 5
5 3
9 10
2 2
6 7
8 2
5 8
5 1
8 6
8 3
9 3
6 10
4 3
6 5
6 2
5 8
8 10
10 9
10 6
4 3
3 4
5 1
4 2
5 4
8 9
3 6
9 5
10 9
10 6
8 9
9 5
4 5
5 1
5 5
1 8
6 7
8 10
9 7
9 8
8 6
7 6
7 7
9 5
7 10
1 5
4 9
5 7
7 5
9 9
10 3
10 6
5 10
6 3
8 10
5 10
8 8
3 3
8 4
2 5
10 6
7 9
4 1
1 5
2 5
9 4
6 4
8 8
9 8
7 10
5 8
8 6
9 9
2 7
5 1
4 5
4 7
2 2
9 10
4 7
8 4
4 2
10 9
2 2
9 4
2 9
3 6
9 6
8 3
6 1
4 6
7 9
10 8
1 3
9 1
4 3
3 7
5 8
1 6
3 4
6 8
6 8
9 10
10 8
4 9
3 2
1 7
2 4
1 10
8 10
6 4
5 2
2 9
8 6
3 8
10 9
3 2
7 9
5 1
2 3
4 10
5 2
9 6
10 1
3 7
1 7
8 1
4 10
9 5
3 7
7 4
3 9
8 8
7 8
6 6
3 1
5 1
6 7
2 3
7 7
7 7
10 10
4 9
2 7
1 9
7 4
5 6
5 5
5 4
2 8
9 4
7 5
6 10
3 7
2 4
3 1
1 2
5 6
8 8
5 9
10 10
6 1
7 3
3 6
9 6
8 7
9 1
7 9
5 8
5 6
6 8
7 1
8 1
3 6
3 7
1 1
8 3
2 2
1 5
7 1
4 1
1 1
3 5
9 1
2 4
5 6
6 7
7 3
2 8
6 1
7 7
1 9
7 7
9 1
2 7
2 5
8 3
6 7
7 8
3 10
1 10
1 10
1 5
3 9
8 6
10 1
1 8
3 2
5 10
3 6
4 4
9 3
3 8
4 1
1 3
1 7
9 2
8 9
3 9
9 6
8 1
2 8
5 2
3 10
9 6
9 10
8 5
2 1
4 3
9 10
4 4
2 2
*/