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
    int a[n], b[n];
    map<int, int> m;
    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
        m[a[i]] = 1;
    }
    // for(int i=0;i<n-1;i++){
    //     if(a[i] != 0 && a[i+1] != 0){
    //         if((a[i] % 2 == 0 && a[i+1] % 2 != 0) || (a[i] % 2 != 0 && a[i+1] % 2 == 0)){
    //             ans++;
    //         }
    //     }
    // }
    int o=0, e=0;
    for(int i=1;i<=n;i++){
        if(m[i] == 0){
            if(i % 2 == 0){
                e++;
            }
            else{
                o++;           
            }
        }
    }
    if(n%2==0){
    	e=n/2 - e;
    	o=n/2 - o;
    }
    else{
    	e=n/2 - e;
    	o=n/2 + 1 - o;
    }
    for(int i=0;i<n;i++){
        if(i == 0){
            if(a[i+1] % 2 == 0){
                if(a[i] == 0){
                    if(e){
                        e--;
                        a[i] = 2;
                        b[i] = 2;
                    }
                    else{
                        ans+=1;
                        o--;
                        a[i] = 1;
                        b[i] = 1;
                    }
                }
            }
            else{
                if(a[i] == 0){
                    if(o){
                        o--;
                        a[i] = 1;
                        b[i] = 1;
                    }
                    else{
                        ans+=1;
                        e--;
                        a[i] = 2;
                        b[i] = 2;
                    }
                }
            }
        }
        if(i == n-1){
            if(a[i-1] % 2 == 0){
                if(a[i] == 0){
                    if(e){
                        e--;
                        a[i] = 2;
                        b[i] = 2;
                    }
                    else{
                        ans+=1;
                        o--;
                        a[i] = 1;
                        b[i] = 1;
                    }
                }
            }
            else{
                if(a[i] == 0){
                    if(o){
                        o--;
                        a[i] = 1;
                        b[i] = 1;
                    }
                    else{
                        ans+=1;
                        e--;
                        a[i] = 2;
                        b[i] = 2;
                    }
                }
            }
        }
        else{
            if(a[i] == 0){
                // cout << a[i] << "\n";
                if(a[i-1] % 2 == 0 && a[i+1] % 2 == 0){
                    if(e){
                        e--;
                        a[i] = 2;
                        b[i] = 2;
                    }
                    else{
                        o--;
                        ans+=2;
                        a[i] = 1;
                        b[i] = 1;
                    }
                }
                else if((a[i-1] % 2 == 0 && a[i+1] % 2 != 0) || (a[i-1] % 2 != 0 && a[i+1] % 2 == 0)){
                    if(e >= o && e){
                        e--;
                        a[i] = 2;
                        b[i] = 1;
                        ans++;
                    }
                    else if(o >= e && o){
                        o--;
                        a[i] = 1;
                        b[i] = 2;
                        ans++;
                    }
                }
                else if(a[i-1] % 2 !=0 && a[i+1] % 2 != 0){
                    if(o){
                        o--;
                        a[i] = 1;
                        b[i] = 1;
                    }
                    else{
                        e--;
                        a[i] = 2;
                        b[i] = 2;
                        ans+=2;
                    }
                }
            }
        }
    }
    // cout << ans << "\n";
    int ans2 = 0, ans3 = 0;
    for(int i=0;i<n-1;i++){
        cout << a[i] << " or " << b[i] << "\n";
        if(a[i] != 0 && a[i+1] != 0){
            if((a[i] % 2 == 0 && a[i+1] % 2 != 0) || (a[i] % 2 != 0 && a[i+1] % 2 == 0)){
                ans2++;
            }
            if((b[i] % 2 == 0 && b[i+1] % 2 != 0) || (b[i] % 2 != 0 && b[i+1] % 2 == 0)){
                ans3++;
            }
        }
    }
    cout << min(ans2, ans3) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}