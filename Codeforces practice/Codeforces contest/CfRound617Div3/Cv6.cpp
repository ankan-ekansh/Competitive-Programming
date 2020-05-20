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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ind_x=-1,ind_y=-1;
        bool c1=false;
        for(int i=1;i<s.size();i++){
            if((s[i] == 'D' && s[i-1] == 'U')||(s[i]=='U' && s[i-1] == 'D')||
            (s[i] == 'R' && s[i-1]=='L')||(s[i] == 'L' && s[i-1] == 'R')){
                ind_x=i;ind_y=i+1;
                c1=true;
                break;
            }
        }
        if(!c1){
            int a[n];
            for(int i=0;i<n;i++){
                if(s[i]=='L')a[i]=1;
                else if(s[i]=='R')a[i]=-1;
                else if(s[i]=='U')a[i]=5;
                else a[i]=-5;
            }
            int sum=0;
            if(n>=4){
                sum=a[0]+a[1]+a[2]+a[3];
            if(sum==0){
                cout << 1 << " " << 4 << "\n";
                continue;
            }
            bool c=false;
                for(int i=4;i<s.size();i++){
                    sum+=a[i]-a[i-4];
                    if(sum==0){
                        cout<<i-2<<" "<<i+1<<"\n";
                        c=true;
                        break;}
                    }
                    if(!c)cout<<-1<<"\n";
                }
            else{cout<<-1<<"\n";
            continue;}
        
        }
        else cout<<ind_x<<" "<<ind_y<<endl;
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}