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
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
    }
    sort(a, a+n);
    int cars = 0;

    cars+=m[4]; //Pairing up 4s

    if(m[3] >= m[1]){   //Pairing up 3s and 1s
        cars+=m[3];
        m[1] = 0;
    }
    else{
        cars+=m[3];
        m[1]-=m[3];
        m[3] = 0;
    }

    cars+=m[2]/2;
    m[2]%=2;
    // if(m[2] % 2 == 0){     //Pairing up 2s with 2s
    //     cars+=m[2]/2;
    //     m[2] = 0;
    // }
    // else{
    //     cars+=m[2]/2;
    //     m[2] = 1;
    // }
    // if(m[2]){
    //     cars+=m[2]/2;
    //     m[2]%=2;
    // }

    // if(m[2] && m[1] >= 2){  //Pairing up 2s and 1s
    //     cars+=1;
    //     m[2] = 0;
    //     m[1]-=2;
    // }
    // else if(m[2]){
    //     cars+=m[2];
    // }

    cars+=m[1]/4;   //Pairing up 1s
    m[1]%=4;

    if(m[2]){
        if(m[1]){
            m[1]-=2;
        }
        cars++;
    }

    if(m[1] > 0)
        cars++;

    cout << cars << "\n";


    // cars+=m[4];
    // // cout << "4: " << cars << "\n";
    // // if(m[1] <= m[3]){
    // //     m[1]=0;
    // //     cars+=m[3];
    // // }
    // m[1] = max(0, m[1] - m[3]);
    // cars+=m[3];
    // cars+=m[2]/2;
    // m[2]%=2;
    // // if(m[1] <= m[2]){
    // //     m[1]=0;
    // //     cars+=m[2];
    // // }
    // // m[1] = max(0, m[1] - m[2]);
    // if(m[1] >= 2*m[2] && m[2]){
    //     m[1]%=2;
    // }
    // else{
    //     if(m[2])
    //     m[1] = 0;
    // }
    // cars+=m[2];
    // cars+=m[1]/4;
    // m[1]%=4;
    // if(m[1])
    //     cars++;
    // cout << cars << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}