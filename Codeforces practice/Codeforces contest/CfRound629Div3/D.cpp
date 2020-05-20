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

#define mod 1000000007

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
    while(t--){
 
        ll n;
        cin>>n;
        map <ll,ll> mp;
        vector <ll> a(n);
        for(ll i=0; i<n; i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        if((int)mp.size()==1){
            cout<<1<<"\n";
            for(ll i=0; i<n; i++)
            cout<<1<<" ";
            cout<<"\n";
            continue;
        }
    
        if(n%2==0){ 
            cout<<2<<"\n";
            for(ll i=0; i<n; i++){
                if(i%2==0) 
                    cout<<2<<" ";
                else 
                    cout<<1<<" ";
            }
        }
        else{  
            vector <int> ans(n);
            ans[0]=0;
            int f=0;
            for(ll i=1; i<n-1; i++){
                if((a[i]==a[i-1])&&(f==0)){ 
                    f=1;
                    ans[i]=ans[i-1];
                }
                else 
                    ans[i]=1-ans[i-1];
            }
            if(f==1){
                ans[n-1]=1-ans[n-2];
                cout<<2<<"\n";
            }
            else{ 
                if(a[n-1]==a[n-2]){
                    ans[n-1]=ans[n-2];
                    cout<<2<<"\n";
                }
                else{
                    ans[n-1]=2;
                    cout<<3<<"\n";
                }
            }
            for(ll i=0; i<n; i++)
                cout<<ans[i]+1<<" ";
        }
        cout<<"\n"; 
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}