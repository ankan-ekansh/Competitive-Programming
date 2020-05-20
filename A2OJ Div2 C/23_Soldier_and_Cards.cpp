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
    deque<int> dq1, dq2;
    map<pair<int, int>, int> vis;
    int s1, s2;
    cin >> s1;
    for(int i=0;i<s1;i++){
        int x;
        cin >> x;
        dq1.push_back(x);
    }
    cin >> s2;
    for(int i=0;i<s2;i++){
        int x;
        cin >> x;
        dq2.push_back(x);
    }
    int rounds = 0;
    int winner = 0;
    while(!dq1.empty() && !dq2.empty()){
        if(rounds > 100000){
            winner = -1;
            break;
        }
        // if(vis[{dq1.front(), dq2.front()}]){
        //     winner = -1;
        //     break;
        // }
        if(dq1.front() > dq2.front()){
            rounds++;
            int f = dq2.front();
            dq2.pop_front();
            int s = dq1.front();
            dq1.pop_front();
            dq1.push_back(f);
            dq1.push_back(s);
            vis[{f, s}] = 1;
            // vis[{s, f}] = 1;
        }
        else{
            rounds++;
            int f = dq1.front();
            dq1.pop_front();
            int s = dq2.front();
            dq2.pop_front();
            dq2.push_back(f);
            dq2.push_back(s);
            vis[{f, s}] = 1;
            // vis[{s, f}] = 1;
        }
    }
    if(winner == -1){
        cout << "-1\n";
    }
    else{
        if(dq1.empty()){
            cout << rounds << " ";
            cout << "2\n";
        }
        else if(dq2.empty()){
            cout << rounds << " ";
            cout << "1\n";
        }
        else{
            cout << "-1\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}