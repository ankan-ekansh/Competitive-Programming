#include<bits/stdc++.h>
using namespace std;
#define flash ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define endl "\n"
#define int long long
typedef long long ll;
typedef long double ld;
const int mod = 1000000007;
bool isPrime(ll n){for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
ll factorial(ll n){return (n==1 || n==0) ? 1:n*factorial(n-1);}
ll power(ll x,ll y){ll res=1;x=x;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res%mod;}
ll ncr(ll n,ll r){ll res=1;if(r>n)return 0;if(r>n-r)r=n-r;for(ll i=0;i<r;i++){res*=(n-i);res/=(i+1);}return res;}
ll gcd(ll a,ll b){if (a==0)return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return (a/gcd(a,b)*b);}
ll max(ll a,ll b){ll ans=a>b?a:b;return ans;}
ll min(ll a,ll b){ll ans=a<b?a:b;return ans;}
int isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
  
        if (j == M) 
            return i; 
    } 
  
    return -1; 
} 
signed main()
{
    flash;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<string>v;
        v.pb("UD");v.pb("DU");v.pb("RL");v.pb("LR");
        v.pb("LDRU");v.pb("LURD");v.pb("RULD");v.pb("RDLU");
        v.pb("DRUL");v.pb("DLUR");v.pb("URDL");v.pb("ULDR");
        int i,res;
        for(i=0;i<12;i++)
        {
        	int res=isSubstring(v[i],s);
        	if(res==-1)
        		continue;
        	else
        	{
        		if(i<4)
        		cout<<res+1<<" "<<res+2<<endl;
        		else
        		cout<<res+1<<" "<<res+4<<endl;
        		break;
        	}
        }
        if(i==12)
        	cout<<"-1"<<endl;
    }
    return 0;
}