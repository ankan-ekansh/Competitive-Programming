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
    
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    if(a == 0 || b == 0){
        // cout << "NO\n";
        if(max(a, b) > k){
            cout << "NO\n";
            return 0;
        }
        else{
            for(ll i=0;i<n;i++){
                if(a == 0){
                    cout << "B";
                }
                else{
                    cout << "G";
                }
            }
            return 0;
        }
    }
    if(a < b){
        ll ctr = 0, na = 0, nb = 0;
        vector<char> ans;
        ll x = b/a;
        // cout << x << "\n";
        if(x > k){
            cout << "NO\n";
            return 0;
        }
        for(ll i=0;i<n;i++){
            if(ctr == x){
                na++;
                ans.push_back('G');
                ctr = 0;
            }
            else{
                nb++;
                ans.push_back('B');
                ctr++;
            }
            // if(ctr == x){
            //     // cout << "G";
            //     ans.push_back('G');
            //     na++;
            //     ctr = 0;
            // }
            // else{
            //     // cout << "B";
            //     ans.push_back('B');
            //     nb++;
            //     ctr++;
            // }
        }
        cout << na << " " << nb << "\n";
        // if(na != a || nb != b){
        //     cout << "NO\n";
        // }
        // else{
            for(char c : ans){
                cout << c;
            }
        // }
    }
    else{
        ll ctr = 0, na = 0, nb = 0;
        vector<char> ans;
        ll x = a/b;
        // cout << x << "\n";
        if(x > k){
            cout << "NO\n";
            return 0;
        }
        for(ll i=0;i<n;i++){
            if(ctr == x){
                nb++;
                ans.push_back('B');
                ctr = 0;
            }
            else{
                na++;
                ans.push_back('G');
                ctr++;
            }
            // if(ctr == x){
            //     // cout << "B";
            //     ans.push_back('B');
            //     nb++;
            //     ctr = 0;
            // }
            // else{
            //     // cout << "G";
            //     ans.push_back('G');
            //     na++;
            //     ctr++;
            // }
        }
        cout << na << " " << nb << "\n";
        // if(na != a || nb != b){
        //     cout << "NO\n";
        // }
        // else{
            for(char c : ans){
                cout << c;
            }
        // }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}