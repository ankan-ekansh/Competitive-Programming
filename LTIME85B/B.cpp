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
        
        ll n;
        cin >> n;
        ll a[n];
        map<ll, ll> m;
        vector<ll> odds;
        for(ll i=0;i<n;i++){
            cin >> a[i];
            m[a[i]]++;
        }
        bool flag = true;
        for(ll i=0;i<n;i++){
            if(m[a[i]] == 1){
                odds.push_back(a[i]);
            }
            if(m[a[i]] > 2){
                flag = false;
                cout << "NO\n";
                break;
            }
        }
        if(!flag){
            continue;
        }
        if(!odds.size()){
            cout << "NO\n";
            continue;
        }
        sort(odds.begin(), odds.end());
        ll mid = *odds.rbegin();
        if(m[mid] == 2){
            cout << "NO\n";
            continue;
        }
        // cout << "YES\n";
        vector<ll> ans1, ans2;
        for(pair<ll, ll> p : m){
            // cout << p.first << " ";
            ans1.push_back(p.first);
        }
        for(pair<ll, ll> p : m){
            if(p.second == 2){
                if(p.first > mid){
                    flag = false;
                    break;
                }
                ans2.push_back(p.first);
            }
        }
        if(!flag){
            cout << "NO\n";
            continue;
        }
        reverse(ans2.begin(), ans2.end());
        cout << "YES\n";
        for(ll x : ans1){
            cout << x << " ";
        }
        for(ll x : ans2){
            cout << x << " ";
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}