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
        string s;
        cin >> s;
        vector<ll> v;
        for(ll i=0;i<s.length();i++){
            if(s[i] == '0'){
                v.push_back(i);
            }
        }
        // for(ll i=0;i<v.size();i++){
        //     cout << v[i] << " ";
        // }
        // cout << "\n";
        ll front = 0;
        for(ll i=0;i<v.size();i++){
            if(v[i] - front <= k){
                k = k - (v[i] - front);
                v[i] = front;
                front++;
            }
            else{
                // v[i] = max(v[i] - k, front);
                v[i] = v[i] - k;
                break;
            }
            // cout << k << " - ";
        }
        // cout << "\n";
        // for(ll i=0;i<v.size();i++){
        //     cout << v[i] << " ";
        // }
        // cout << "\n";
        string ans(s.length(), '1');
        // cout << ans << "\n";
        for(ll i=0;i<v.size();i++){
            ans[v[i]] = '0';
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}