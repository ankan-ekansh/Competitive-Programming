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
map<ll, ll> spf;
map<ll, map<ll, ll>> m1;
map<ll, map<ll, ll>> m2;
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
void dfs(ll currentNode = 1, ll parentNode = 1){
    tin[currentNode] = ++timer;
    par[currentNode][0] = parentNode;
    // product[currentNode] = product[parentNode] * a[currentNode];
    if(parentNode != currentNode){
        // cout << currentNode << " : ";
        // for(auto p : m2[a[parentNode]]){
        //     cout << p.first << " ";
        //     m2[a[currentNode]][p.first] = m1[a[currentNode]][p.first] + m2[a[parentNode]][p.first];
        // }
        // cout << "\n";
        for(auto p : m2[parentNode]){
            // cout << p.first << " ";
            m2[currentNode][p.first] = m1[a[currentNode]][p.first] + m2[parentNode][p.first];
        }
        // cout << "\n";
        
    }
    // cout << currentNode << ", child of " << parentNode << " m1 : ";
    // for(auto p : m1[a[currentNode]]){
    //     // pws[p.first]+=p.second;
    //     cout << p.first << "^" << p.second << " * ";
    // }
    // cout << "\n";
    // cout << currentNode << ", child of " << parentNode << " m2 : ";
    // for(auto p : m2[a[currentNode]]){
    //     // pws[p.first]+=p.second;
    //     cout << p.first << "^" << p.second << " * ";
    // }
    // cout << "\n";
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
        // freopen("outputnew.txt", "wt", stdout);
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
        m2.clear();
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
            if(m1[a[i]].empty()){
                fun(a[i]);
                // getFactorization(a[i]);
            }
            // m2[a[i]] = m1[a[i]];
            m2[i] = m1[a[i]];
        }
        dfs();
        ll q;
        cin >> q;
        while(q--){
            ll u, v;
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
            // cout << (product[u] * product[v] * a[ancestor])/((product[ancestor]) * (product[ancestor])) << "\n";
            // }
            // for(ll i=1;i<=nodes;i++){
            //     cout << i << " : ";
            //     for(auto p : m2[i]){
            //         // pws[p.first]+=p.second;
            //         cout << p.first << "^" << p.second << " * ";
            //     }
            //     cout << "\n";
            // }
            // for(auto p : m1[a[v]]){
            //     // pws[p.first]+=p.second;
            //     cout << p.first << "^" << p.second << " * ";
            // }
            // cout << "\n";
            map<ll, ll> pws;
            // cout << "u : " << u << " a[u] : " << a[u] << " :- a[1-u] : ";
            for(auto p : m2[u]){
                // pws[p.first]+=p.second;
                pws[p.first] = pws[p.first] + p.second;
                // cout << p.first << "^" << p.second << " * ";
            }
            // cout << "\n";
            // cout << "v : " << v << " a[v] : " << a[v] << " :- a[1-v] : ";
            for(auto p : m2[v]){
                // pws[p.first]+=p.second;
                pws[p.first] = pws[p.first] + p.second;
                // cout << p.first << "^" << p.second << " * ";
                // if(p.first == 11){
                    // cout << "-----------------";
                // }
            }
            // cout << "\n";
            // cout << "lca : " << ancestor << " a[lca] : " << a[ancestor] << " :- a[lca] : ";
            for(auto p : m1[a[ancestor]]){
                // pws[p.first]+=p.second;
                pws[p.first] = pws[p.first] + p.second;
                // cout << p.first << "^" << p.second << " * ";
            }
            // cout << "\n";
            // cout << "1-lca : " << ancestor << " a[lca] : " << a[ancestor] << " :- a[1-lca] : ";
            for(auto p : m2[ancestor]){
                // pws[p.first]-=(2*p.second);
                pws[p.first] = pws[p.first] - (2*p.second);
                // cout << p.first << "^" << p.second << " * ";
            }
            // cout << "\n";
            ll ans = 1;
            for(auto p : pws){
                // cout << p.first << "^" << p.second << " * ";
                ans = ((ans * (p.second + 1)))%mod;
            }
            // cout << "\n";
            cout << ans << "\n";
        }
        
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}