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
 
        int64_t n, k;
        cin >> n >> k;
        int64_t p = pow(2, k);
        int64_t s = pow(2, (int64_t)log2(n));
        int64_t l = pow(2, (int64_t)ceil(log2(n)));
        int64_t count = (( s / p ) / 2) * p;
        // cout << ((s >> k) & 1) << "\n";
        // cout << count << "\n\n";
        if(( s >> k) & 1){
            int x = (n - s) / p;
            int y = (n - s) % p;
            count+=((x+1)/2) * p;
            if(x % 2 == 0)
                count+=(y);
            // cout << count << "\n\n";
        }
        else{
            int x = (n - s) / p;
            int y = (n - s) % p;
            count+=(x/2) * p;
            // cout << count << "\n\n";
            if(x % 2 != 0){
                count+=(y);
            }
            // cout << count << "\n\n";
        }
        if((n >> k) & 1){
            count++;
        }
        cout << count << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}