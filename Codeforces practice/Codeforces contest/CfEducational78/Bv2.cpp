#include<bits/stdc++.h>
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
    while(t--){
 
        long long a, b;
        cin >> a >> b;
        if(b < a){
            swap(a, b);
        }
        long long d = b - a;
        d = ((long long)sqrt(1 + 8*d) - 1)/2;
        long long n = d;
        d = (d*(d+1))/2;
        a = a + d;
        n+=(2*abs(b-a));
        cout << n << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}