#include<bits/stdc++.h>
long long x,y;
long long extendedEuclid(long long a, long long b, long long *x, long long *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    long long x1, y1;
    long long g = extendedEuclid(b%a, a, &x1, &y1);
    *x = y1 - (b/a)*x1;
    *y = x1;
    return g;
}
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int n = 1;
    while(t--){
 
        long long a,b,c;
        cin>>a>>b>>c;
        long long g = __gcd(a, b);
        if(c % g != 0){
            cout<<"Case "<<n<<": "<<"No\n";
        }
        else{
            cout<<"Case "<<n<<": "<<"Yes\n";
        }
        n++;
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}