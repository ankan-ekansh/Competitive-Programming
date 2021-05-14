/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "rt", stdin);
        freopen("alchemy_validation_input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    ll tc = 1;
    while(t--){
        
        
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll a = 0;
        for(ll i=0;i<n;i++){
            if(s[i] == 'A'){
                a++;
            }
        }
        cout << "Case #" << tc++ << ": ";
        if(abs(n-2*a) == 1){
            cout << "Y\n";
        }
        else{
            cout << "N\n";
        }

    }
    // #ifndef ONLINE_JUDGE
    //     cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}