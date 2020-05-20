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
    ll ctr = 1;
    while(t--){
 
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        pair<int, int> me = {0, 0};
        pair<int, int> pep = {x, y};
        // vector<int> mytime[s.length()+7], peptime[s.length() + 7];
        map<pair<int, int>, vector<int>> mytime, peptime;
        peptime[pep].push_back(0);
        mytime[{x, y}].push_back(abs(x)+abs(y));
        for(int i=0;i<s.length();i++){
            if(s[i] == 'N'){
                pep.second += 1;
            }
            if(s[i] == 'E'){
                pep.first += 1;
            }
            if(s[i] == 'W'){
                pep.first -= 1;
            }
            if(s[i] == 'S'){
                pep.second -= 1;
            }
            // peptime[i].push_back(i); 
            peptime[pep].push_back(i+1);
            mytime[pep].push_back(abs(pep.first) + abs(pep.second));
        }
        // for(auto p : peptime){
        //     cout << p.first.first << " " << p.first.second << " : ";
        //     for(int tm : p.second){
        //         cout << tm << " ";
        //     }
        //     cout << "\n";
        // }
        // for(auto p : mytime){
        //     cout << p.first.first << " " << p.first.second << " : ";
        //     for(int tm : p.second){
        //         cout << tm << " ";
        //     }
        //     cout << "\n";
        // }


        pep = {x, y};
        int ans = 99999999;
        for(int t1 : peptime[pep]){
                for(int t2 : mytime[pep]){
                    if(t2 <= t1){
                        ans = min(ans, t1);
                    }
                }
        }
        for(int i=0;i<s.length();i++){
            if(s[i] == 'N'){
                pep.second += 1;
            }
            if(s[i] == 'E'){
                pep.first += 1;
            }
            if(s[i] == 'W'){
                pep.first -= 1;
            }
            if(s[i] == 'S'){
                pep.second -= 1;
            }
            // peptime[i].push_back(i); 
            // peptime[pep].push_back(i);
            // mytime[pep].push_back(pep.first + pep.second);
            for(int t1 : peptime[pep]){
                for(int t2 : mytime[pep]){
                    if(t2 <= t1){
                        ans = min(ans, t1);
                    }
                }
            }
        }
        if(ans != 99999999){
                cout << "Case #" << ctr++ << ": " << ans << "\n";
            }
            else{
                cout << "Case #" << ctr++ << ": " << "IMPOSSIBLE" << "\n";
        }
        // cout << "Case #" << ctr++ << ": ";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}