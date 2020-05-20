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
    int t = n;
    int ans = 0;
    int c = 1;
    vector<pair<int, int>> v1, v2;
    while(t--){
        int l;
        cin >> l;
        int a[l];
        int amin = INT_MAX, amax = INT_MIN;
        // int imin = -1, imax = l;
        for(int i=0;i<l;i++){
            cin >> a[i];
            if(a[i] < amin){
                amin = a[i];
            }
            if(a[i] > amax){
                amax = a[i];
            }
        }
        // for(int i=0;i<l;i++){
        //     if(a[i] == amin){
        //         imin = i;
        //         break;
        //     }
        // }
        // for(int i=l-1;i>=0;i--){
        //     if(a[i] == amax){
        //         imax = i;
        //         break;
        //     }
        // }
        // if(imax > imin || l == 1){
        //     ans+=(2*(n-1-c)) + 1;
        //     cout << ans << "\n";
        // }
        // c++;
        bool flag = false;
        for(int i=0;i<l-1;i++){
            for(int j=i+1;j<l;j++){
                if(a[i] < a[j]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag || l == 1){
            ans+=(2*(n-1-v1.size()) + 1);
            v1.push_back(make_pair(amin, amax));
        }
        else{
            v2.push_back(make_pair(amin, amax));
        }
    }
    // cout << ans << "\n";
    for(int i=0;i<v2.size()-1;i++){
        for(int j=0;j<v2.size();j++){
            if(v2[i].second < v2[j].first){
                ans++;
            }
            if(v2[j].second < v2[i].first){
                ans++;
            }
        }
    }

    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}