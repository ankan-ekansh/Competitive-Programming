#include<bits/stdc++.h>
#define ll long long
#define pb push_back
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
int isSubstring(string s1, string s2){ 
    int M = s1.length(); 
    int N = s2.length(); 
    for(int i = 0; i <= N - M; i++){ 
        int j;
        for (j = 0; j < M; j++){
            if(s2[i + j] != s1[j]){
                break; 
            }
        }
        if(j == M)
            return i; 
    } 
    return -1; 
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
 
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<string> v;
        v.pb("UD");
        v.pb("DU");
        v.pb("RL");
        v.pb("LR");
        v.pb("LDRU");
        v.pb("LURD");
        v.pb("RULD");
        v.pb("RDLU");
        v.pb("DRUL");
        v.pb("DLUR");
        v.pb("URDL");
        v.pb("ULDR");
        int i,res;
        for(i=0;i<12;i++){
        	int res=isSubstring(v[i],s);
        	if(res == -1)
        		continue;
        	else{
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
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}