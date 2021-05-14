#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<pair<ll, ll>> vpll;
typedef std::vector<vll> vvll;
typedef std::pair<ll, ll> pll;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define RANDOM srand(time(0))
#define mod 998244353 // 10^9 + 7
#define MAXN 1000005
 
#define test ll tc;cin>>tc;while(tc--)
#define lcm(x,y) (x*y)/(__gcd(x,y)) 
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define rep(i,a,b) F(i,a,b-1) 
#define mem(a,b) memset(a,b,sizeof(a)) //int A[n][m]; mem(A,-1);
#define r(l,r) rand()%(r-l+1) + l;
const ll INF = 1ll*1000*1000*1000*1000*1000*1000 + 7;
 
/*
For segment trees
 
pair<ll, ll> t[4*MAXN];
 
pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b) 
{
    // Define your required operation here
    // if (a.first > b.first) 
    //     return a;
    // if (b.first > a.first)
    //     return b;
    // return make_pair(a.first, a.second + b.second);
}
 
void build(ll a[], ll v, ll tl, ll tr) 
{
    if (tl == tr) 
    {
        t[v] = make_pair(a[tl], 1);
    } else 
    {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
 
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
 
pair<ll, ll> op(ll v, ll tl, ll tr, ll l, ll r) 
{
    if (l > r)
        // return make_pair(-INF, 0);
 
    if (l == tl && r == tr)
        return t[v];
 
    ll tm = (tl + tr) / 2;
 
    return combine(op(v*2, tl, tm, l, min(r, tm)), op(v*2+1, tm+1, tr, max(l, tm+1), r));
}
 
void update(ll v, ll tl, ll tr, ll pos, ll new_val) 
{
    if (tl == tr) 
    {
        t[v] = make_pair(new_val, 1);
    } 
    else 
    {
        ll tm = (tl + tr) / 2;
 
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
 
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}
*/

 
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i=5; i*i <= n; i+=6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
 
bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b) 
{ 
    if(a.first!=b.first)
        return (a.first > b.first);
    return (a.second < b.second); 
} 
 
ll power(ll a, ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2 == 1)
        return (power(a, b-1) * a) % mod;
    
    ll q = power(a, b/2);
    return (q*q) % mod;
}
 
 
 
// vll seive;
// void Seive()
// {
//     const ll maxn = 1000005;
//     seive.resize(maxn);
//     for(ll i=0;i<maxn;i++) 
//         seive[i]=i;
 
//     for(ll i=2;i<=maxn;i+=2)
//     seive[i] = 2;
 
//     seive[1] = -1;
//     seive[0] = -1;
    
//     for (ll i = 3; i <= maxn; i += 2)
//     {
//         if (i == seive[i])
//             for (ll j = i * i ; j < maxn ; j += i)
//                 if (seive[j] == j)
//                     seive[j] = i;
//     }
// }

vll digits(ll n)
{
    vll dig;

    while(n!=0)
    {
        dig.pb(n%10);
        n/=10;
    }

    reverse(dig.begin(), dig.end());

    return dig;
}

bool prime[MAXN];

void soe(ll n)
{
    mem(prime, true);

    for(ll p=2; p*p<=n; p++)
    {
        if(prime[p] == true)
        {
            for(ll i=p*p; i<=n; i+=p)
                prime[i] = false;
        }
    }
}





int main()
{
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        // freopen("output.txt", "w", stdout);
    #endif
 
    fast;

    ll t=1;   
    ll dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    ll dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

    char grid[50][50];
    bool vis[50][50];
    ll level[50][50];

    while(1)
    {
        ll h, w;
        cin>>h>>w;

        if(h==0 and w==0)
            break;

        
        mem(vis, false);
        mem(level, 0);

        queue<pll> q;

        ll ans=0;

        for(ll i=0; i<h; i++)
        {
            for(ll j=0; j<w; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j] == 'A')
                {
                    level[i][j] = 1;
                    vis[i][j] = 1;
                    q.push({i, j});
                    ans = 1;
                }
            }
        }



        while(!q.empty())
        {
            pll p = q.front();

            q.pop();

            for(ll i=0; i<8; i++)
            {
                ll x = dx[i]+p.ff;
                ll y = dy[i]+p.ss;

                if(x>=0 and x<h and y>=0 and y<w and grid[x][y]-grid[p.ff][p.ss]==1)
                {
                    if(!vis[x][y])
                    {
                        level[x][y] = level[p.ff][p.ss] + 1;
                        vis[x][y] = 1;

                        ans = max(ans, level[x][y]);

                        q.push({x, y});
                    }
                }
            }
        }
        // for(ll i=0;i<h;i++) {
        //     for(ll j=0;j<w;j++) {
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        cout<<"Case "<<t++<<": "<<ans<<"\n";
    }



    #ifndef ONLINE_JUDGE
        cout<<"\nt = "<<1.0*clock() / CLOCKS_PER_SEC<<"s\n";
    #endif

    return 0;
}