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
    while(t--){
 
        ll n;
        cin >> n;
        ll a[n];
        ll pos = 0, neg = 0;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            if(a[i] > 0){
                pos++;
            }
            else{
                neg++;
            }
        }
        if((pos == 0 || neg == 0) && n != 1){
            cout << "-1\n";
            continue;
        }
        ll ans1 = 0, ans2 = 0;
        ll maxsofar = 0;
        bool flag = true;
        bool found = false;
        ll s1 = 0, s2 = 0;
        for(ll i=0;i<n;i++){
            if(!found){
                if(a[i] > 0){
                    found = true;
                    maxsofar = a[i];
                    // s1++;
                    // flag = false;
                }
            }
            else{
                if(flag){
                    if(a[i] > 0){
                        maxsofar = max(maxsofar, a[i]);
                    }
                    else{
                        ans1 += maxsofar;
                        s1++;
                        maxsofar = a[i];
                        flag = false;
                    }
                }
                else{
                    if(a[i] < 0){
                        maxsofar = max(maxsofar, a[i]);
                    }
                    else{
                        ans1 += maxsofar;
                        maxsofar = a[i];
                        s1++;
                        flag = true;
                    }
                }
            }
            // cout << "Ans1 till now " << ans1 << "\n";
            // cout << maxsofar << "\n";
        }
        ans1 += maxsofar;
        s1++;
        flag = false;
        maxsofar = 0;
        found = false;
        for(ll i=0;i<n;i++){
            if(!found){
                if(a[i] < 0){
                    found = true;
                    maxsofar = a[i];
                    // flag = true;
                }
            }
            else{
                if(flag){
                    if(a[i] > 0){
                        maxsofar = max(maxsofar, a[i]);
                    }
                    else{
                        ans2 += maxsofar;
                        s2++;
                        maxsofar = a[i];
                        flag = false;
                    }
                }
                else{
                    if(a[i] < 0){
                        maxsofar = max(maxsofar, a[i]);
                    }
                    else{
                        ans2 += maxsofar;
                        s2++;
                        maxsofar = a[i];
                        flag = true;
                    }
                }
            }
            // cout << "Ans2 till now " << ans2 << "\n";
            // cout << maxsofar << "\n";
        }
        ans2 += maxsofar;
        s2++;
        // cout << max(ans1, ans2) << "\n";
        // cout << s1 << " " << s2 << "\n";
        if(s1 > s2){
            cout << ans1 << "\n";
        }
        else if(s2 > s1){
            cout << ans2 << "\n";
        }
        else{
            cout << max(ans1, ans2) << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}