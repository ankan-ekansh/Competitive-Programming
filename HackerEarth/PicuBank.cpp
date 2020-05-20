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
 
        long long d, a, m, b, x;
        cin >> d >> a >> m >> b >> x;
        x = x - d;
        long long l = 1, r = 1000000000;
        while(l<r){
            long long mid = (l+r+1)/2;
            long long q = mid/(m+1);
            long long p = mid - q;
            if((p*a + q*b) < x){    //false             000000111111
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        if((b*(l/(m+1)) + (a*(l-(l/(m+1))))) >= x){
            // cout << "-----------------------------------\n";
            cout << l << "\n";
        }
        else
            cout << l+1 << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}