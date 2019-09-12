#include<bits/stdc++.h>
using namespace std;
long long mod(string s, long long m){
    long long res = 0;
    for(long long i=0;i<s.length();i++){
        res = (res*10 + (long long)(s[i]) - '0')%m;
    }
    return res;
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
 
        long long n;
        cin>>n;
        string s;
        cin>>s;
        long long rem = mod(s, n);
        long long x = rem;
        long long y = n - x;
        if(x == y){
            cout<<((2*x) - 1)<<"\n";
        }
        else{
            cout<<(2*min(x, y))<<"\n";
        }

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}