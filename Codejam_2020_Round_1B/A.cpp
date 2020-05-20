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
    int t;
    cin>>t;
    int nt = 1;
    while(t--){
 
        ll x, y;
        cin >> x >> y;
        if((x % 2 == 0 && y % 2 == 0) || (x % 2 != 0 && y % 2 != 0))
            cout << "Case #" << nt++ << ": IMPOSSIBLE\n";
        else{
            ll a[32] = {0}, b[32] = {0};
            bool inv = false;
            bool ok = true;
            if(x % 2 != 0){
                swap(x, y);
                inv = true;
            }
            string s = "";
            if(!inv && x != 0){
                // s+="S";
                if(y > 0){
                    s+="S";
                }
                else{
                    s+="N";
                }
            }
            else if(inv && x != 0){
                // s+="W";
                if(y > 0){
                    s+="W";
                }
                else{
                    s+="E";
                }
            }
            if(x != 0){
                if(y > 0){
                    y++;
                }
                else{
                    y--;
                }
            }
            ll p = x, q = y;
            ll m = 0, n = 0;
            while(p){
                a[m++] = p%2;
                p/=2;
            }
            while(q){
                b[n++] = q%2;
                q/=2;
            }
            ll c = 0, d = 0;
            p = x, q = y;
            cout << p << " " << q << "\n";
            cout << "m = " << m << " n = " << n << "\n";
            for(ll i=1;i<=31;i++){
                cout << i << "th bit of " << p << " is " << ((p >> i)&1LL) << " ";
                cout << i << "th bit of " << q << " is " << ((q >> i)&1LL) << " \n";
                cout << s << "\n";
                if(((p >> i) & 1LL) && ((q >> i) & 1LL)){
                    ok = false;
                    cout << "#1 " << i << " " << p << " " << q << "\n";
                    break;
                }
                else if(!((p >> i) & 1LL) && !((q >> i) & 1LL)){
                    ok = false;
                    cout << "#2 " << i << " " << p << " " << q << "\n";
                    break;
                }
                else{
                    if(i <= m && (p >> i) & 1LL){
                        if(p > 0){
                            if(!inv){
                                s += "E";
                                // c += 
                            }
                            else{
                                s += "W";
                            }
                        }
                        else if(p < 0){
                            if(!inv){
                                s += "W";
                            }
                            else{
                                s += "E";
                            }
                        }
                    }
                    else if(i <= n && (q >> i) & 1LL){
                        if(q > 0){
                            if(!inv){
                                s += "N";
                            }
                            else{
                                s += "S";
                            }
                        }
                        else if(q < 0){
                            if(!inv){
                                s += "S";
                            }
                            else{
                                s += "N";
                            }
                        }
                    }
                }
            }
            cout << "Case #" << nt++ << ": " << s << "\n";
        }

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}