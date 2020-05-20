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
    vector<int> m[200007];
    map<int, int> mp;
    vector<pair<int, int>> v;
    int a[200007], b[200007];
    for(int i=1;i<=n;i++){
        cin >> a[i];
        m[a[i]].push_back(i);
        mp[a[i]]++;
    }
    int k=0;
    for(int i=1;i<=n;i++){
        if(mp[i] == 0){
            v.push_back(make_pair(i, m[0][k++]));
        }
    }
    // for(int i=0;i<v.size();i++){
    //     cout << v[i].first << ", " << v[i].second << "\n";
    // }
    if(k>0){
        // for(int i=0;i<k-1;i++){
        //     a[v[i].second] = v[i+1].first;
        // }
        // a[v[k-1].second] = v[0].first;
        int j = k-1;
        while(j>=0){
            for(int i=1;i<=n;i++){
                if(a[i] == 0 && i != v[j].first){
                    a[i] = v[j].first;
                    // cout << i << " " << j << "\n";
                    j--;
                }
                // else{
                //     j--;
                // }
            }
            if(j == 0){
                if(v[0].first == v[1].second){
                    swap(v[0].second, v[1].second);
                    // j = k-1;
                    a[v[0].second] = v[1].first;
                    a[v[1].second] = v[0].first;
                    j--;
                    break;
                }
            }

        }
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << " ";
    }
    
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}