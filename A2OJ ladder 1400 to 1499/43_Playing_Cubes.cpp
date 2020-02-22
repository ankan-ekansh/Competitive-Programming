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
    
    int n, m;
    cin >> n >> m;
    string s1 = "", s2 = "";
    int r = n, b = m;
    int i=0;
    if(r){
        s1+='R';
        r--;
        i++;
        int t = 1;
        while((r > 0 || b > 0) && (i < (n + m))){
            if(t){
                if(s1[i-1] == 'R'){
                    if(b > 0){
                        b--;
                        s1+='B';
                        i++;
                    }
                    else{
                        r--;
                        s1+='R';
                        i++;
                    }
                }
                else{
                    if(r > 0){
                        r--;
                        s1+='R';
                        i++;
                    }
                    else{
                        b--;
                        s1+='B';
                        i++;
                    }
                }
            }
            else{
                if(s1[i-1] == 'R'){
                    if(r > 0){
                        r--;
                        s1+='R';
                        i++;
                    }
                    else{
                        b--;
                        s1+='B';
                        i++;
                    }
                }
                else{
                    if(b > 0){
                        b--;
                        s1+='B';
                        i++;
                    }
                    else{
                        r--;
                        s1+='R';
                        i++;
                    }
                }
            }
            t = 1 - t;
        }
    }
    i=0;
    r = n;
    b = m;
    //int t=1;
    if(b){
        s2+='B';
        b--;
        i++;
        int t = 1;
        while((r > 0 || b > 0) && (i < (n + m))){
            if(t){
                if(s2[i-1] == 'R'){
                    if(b > 0){
                        b--;
                        s2+='B';
                        i++;
                    }
                    else{
                        r--;
                        s2+='R';
                        i++;
                    }
                }
                else{
                    if(r > 0){
                        r--;
                        s2+='R';
                        i++;
                    }
                    else{
                        b--;
                        s2+='B';
                        i++;
                    }
                }
            }
            else{
                if(s2[i-1] == 'R'){
                    if(r > 0){
                        r--;
                        s2+='R';
                        i++;
                    }
                    else{
                        b--;
                        s2+='B';
                        i++;
                    }
                }
                else{
                    if(b > 0){
                        b--;
                        s2+='B';
                        i++;
                    }
                    else{
                        r--;
                        s2+='R';
                        i++;
                    }
                }
            }
            t = 1 - t;
        }
    }
    int ans = 0;
    int a1 = 0, a2 = 0;
    for(int i=0;i<(n+m-1);i++){
        if(s1[i] == s1[i+1]){
            a1++;
        }
    }
    for(int i=0;i<(n+m-1);i++){
        if(s2[i] == s2[i+1]){
            a2++;
        }
    }
    // cout << s1 << " " << s2 << "\n";
    ans = max(a1, a2);
    cout << ans << " " << (n + m - 1) - ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}