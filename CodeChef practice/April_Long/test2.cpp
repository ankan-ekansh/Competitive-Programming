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
unordered_map<ll, map<ll, ll>> m;
void fun(int n){
    int tmp = n;
	// int c = 0;
	while(n % 2 == 0){
		// cout << "2 ";
        m[tmp][2]++;
		// c=1;
		n/=2;
	}
	for(int i=3;i*i<=n;i+=2){
		while(n % i == 0){
			// cout << i << " ";
            m[tmp][i]++;
			// c++;
			n/=i;
		}
		// c++;
	}
	if(n > 2){
		// cout << n << " ";
        m[tmp][n]++;
		// c++;
	}
	// return c;
}
int main(){
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "rt", stdin);
        freopen("output2.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=1;i<=1000000;i++){
		fun(i);
	}
    // cout << m[256][2] << "\n";
    ll mxm = 0;
    for(int i=2;i<=100000;i++){
        cout << i << " = ";
        for(auto p : m[i]){
            cout << p.first << "^" << p.second << " * ";
        }
        cout << "\n";
        // cout << (*(m[i].rbegin())).first << " " << (*(m[i].rbegin())).second << "\n";
        // auto it = m[i].end();
        // cout << i << " : ";
        // cout << (*it).first << " " << (*it).second << "\n";
        // cout << m[i].size() << "\n";
        mxm = max(mxm, (ll)m[i].size());
    }
    cout << mxm << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}