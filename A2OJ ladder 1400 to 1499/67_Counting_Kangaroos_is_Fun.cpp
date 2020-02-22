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
    sort(a, a+n);
    if(n%2==0){
        int b[n/2], c[n/2];
        for(int i=0;i<n/2;i++){
            b[i] = a[i];
        }
        for(int i=0;i<n/2;i++){
            c[i] = a[i+(n/2)];
        }
        // for(int i=0;i<n/2;i++){
        //     cout << b[i] << " ";
        // }
        // cout << "\n";
        // for(int i=0;i<n/2;i++){
        //     cout << c[i] << " ";
        // }
        // cout << "\n";
        int i=0, j=0;
        int ans = n;
        while(i != n/2 && j != n/2){
            // cout << i << " " << j << "\n";
            if(b[i]*2 <= c[j]){
                i++;
                j++;
                ans--;
            }
            else{
                j++;
            }
        }
        cout << ans << "\n";
    }
    else{
        // int b1[n/2+7], c1[n/2+7], b2[n/2+7], c2[n/2+7];
        // for(int i=0;i<n/2;i++){
        //     b[i] = a[i];
        // }
        // for(int i=0;i<n/2;i++){
        //     c[i] = a[i+(n/2)];
        // }
        int b[n/2+7], c[n/2+7];
        for(int i=0;i<=n/2;i++){
            b[i] = a[i];
        }
        for(int i=0;i<n/2;i++){
            c[i] = a[i+(n/2)+1];
        }
        // for(int i=0;i<=n/2;i++){
        //     cout << b[i] << " ";
        // }
        // cout << "\n";
        // for(int i=0;i<n/2;i++){
        //     cout << c[i] << " ";
        // }
        // cout << "\n";
        int i=0, j=0;
        int ans = n;
        while(i != (n/2 + 1) && j != n/2){
            // cout << i << " " << j << "\n";
            if(b[i]*2 <= c[j]){
                i++;
                j++;
                ans--;
            }
            else{
                j++;
            }
        }
        cout << ans << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}