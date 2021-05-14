/*
    Stay motivated and keep working hard
*/

// 2 4 6 4 2
// 3
// 2 3 6 4 2
//   ^
// Keep sequene of same parity unaltered and use 2 pointers to determine what comes first

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
        
        string s;
        cin >> s;
        vector<ll> even, odd;
        for(char c : s){
            if((c-'0')&1){
                odd.emplace_back(c-'0');
            }
            else{
                even.emplace_back(c-'0');
            }
        }
        ll i=0, j=0;    // i is even pointer, j is odd pointer
        vector<ll> ans;
        while(i < even.size() && j < odd.size()){
            if(even[i] < odd[j]){
                ans.emplace_back(even[i]);
                i++;
            }
            else{
                ans.emplace_back(odd[j]);
                j++;
            }
        }
        while(i < even.size()){
            ans.emplace_back(even[i]);
            i++;
        }
        while(j < odd.size()){
            ans.emplace_back(odd[j]);
            j++;
        }
        for(ll x : ans){
            cout << x;
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}