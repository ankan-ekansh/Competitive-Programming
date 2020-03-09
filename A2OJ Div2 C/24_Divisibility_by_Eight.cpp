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
ll fun(string s){
    string t;
    if(s.length() > 3){
        t = s.substr(s.length() - 3, 3);
    }
    else{
        t = s;
    }
    if(stoi(t) % 8 == 0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string n;
    cin >> n;
    bool flag = false;
    ll sum = 0;
    ll l = n.length();
    ll i=-1, j=-1,k=-1;
    for(i=0;i<l;i++){
        sum = (n[i] - '0');
        if(sum % 8 == 0){
            cout << "YES\n";
            cout << n[i];
            flag = true;
            break;
        }
        for(j=i+1;j<l;j++){
            sum=sum*10 + (n[j]-'0');
            if(sum % 8 == 0){
                cout << "YES\n";
                cout << n[i] << n[j];
                flag = true;
                break;
            }
            for(k=j+1;k<l;k++){
                sum=sum*10 + (n[k]-'0');
                if(sum % 8 == 0){
                    cout << "YES\n";
                    cout << n[i] << n[j] << n[k];
                    flag = true;
                    break;
                }
                sum = (n[i]-'0')*10 + (n[j]-'0');
            }
            if(flag){
                break;
            }
            sum=(n[i] - '0');
        }
        if(flag){
            break;
        }
    }
    if(!flag){
        cout << "NO\n";
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}