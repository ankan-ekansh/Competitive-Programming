/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
        
        ll n, k;
        cin >> n >> k;
        ll tmp = n;
        bool prime = true;
        ll spf = 0;
        for(ll i=2;i*i<=tmp;i++){
            if(tmp % i == 0){
                prime = false;
                spf = i;
                break;
            }
        }
        if(prime){
            cout << n + n + (k-1)*2 << "\n";
        }
        else{
            cout << n + spf + (k-1)*2 << "\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}