#include<bits/stdc++.h>
using namespace std;
long power(long x, long a){
    if(a == 0){
        return 1;
    }
    else if(a == 1){
        return x;
    }
    else{
        long y = power(x, a/2);
        if(a % 2 == 0){
            return y * y;
        }
        else{
            return y * x * y;
        }
    }
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
    cin>>t;
    while(t--){
 
        long n;
        cin >> n;
        long nd = log10(n);
        long p = n/power(10, nd);
        // cout << "\n" << nd << "\n";
        long ans = 9 * nd;
        // cout << nd << "\n\n";
        // ans = ans + (long)(n/ceil(pow(10, nd)));
        string s;
        nd++;
        for(long i=1;i<=nd;i++){
            s+='1';
        }
        long q = stol(s);
        for(long i=1;i<=p;i++){
            if(n >= (i*q)){
                ans++;
            }
        }
        // ans = ans + p;
        // if((n % p == 0) && (p != 1)){
        //     ans--;
        // }
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}