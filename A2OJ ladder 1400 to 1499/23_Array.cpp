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
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    set<int> s1,s2,s3;
    for(int i=0;i<n;i++){
        if(a[i] < 0){
            s1.insert(a[i]);
        }
        else if(a[i] > 0){
            s2.insert(a[i]);
        }
        else{
            s3.insert(a[i]);
        }
    }
    // if(s3.size() == 0){
    //     if(s1.size() % 2 == 0){
    //         s3.insert(*s1.begin());
    //         s1.erase(s1.begin());
    //     }
    //     else if(s2.size() > 1)
    // }
    if(s1.size() % 2 == 0 && s2.size() > 0){
        // cout << "Case 1\n";
        s3.insert(*s1.begin());
        s1.erase(s1.begin());
    }
    if(s2.size() == 0 && s1.size() > 2){
        // cout << "Case 2\n";
        s2.insert(*s1.begin());
        s1.erase(s1.begin());
        s2.insert(*s1.begin());
        s1.erase(s1.begin());
    }
    if(s1.size() % 2 == 0){
        s3.insert(*s1.begin());
        s1.erase(s1.begin());
    }
    cout << s1.size() << " ";
    for(auto i=s1.begin();i!=s1.end();i++){
        cout << *i << " ";
    }
    cout << "\n";
    cout << s2.size() << " ";
    for(auto i=s2.begin();i!=s2.end();i++){
        cout << *i << " ";
    }
    cout << "\n";
    cout << s3.size() << " ";
    for(auto i=s3.begin();i!=s3.end();i++){
        cout << *i << " ";
    }
    cout << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}