#include<bits/stdc++.h>
using namespace std;
long long fun(long long a, long long b, long long c){
    if(a == b){
        return c;
    }
    return min(fun(a+c, b, c+1), fun(a, b+c, c+1));
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
 
        long long a, b;
        cin >> a >> b;
        cout << fun(a, b, 1) << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}