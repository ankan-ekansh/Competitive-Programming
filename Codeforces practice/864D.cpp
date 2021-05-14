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
    
    ll n;
    cin >> n;
    ll a[n];
    ll freq[n+7] = {0};
    bool vis[n+7] = {false};
    for(ll i=0;i<n;i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    vector<ll> v;
    for(ll i=1;i<=n;i++){
        if(!freq[i]){
            v.push_back(i);
        }
    }
    ll i = 0, j = 0, ans = 0;
    while((i < v.size()) && j < n){
        // cout << i << " " << j << "\n";
        if(freq[a[j]] == 1){
            j++;
        }
        else if((a[j] > v[i]) || (vis[a[j]] == true)){
            freq[a[j]]--;
            // cout << j << " " << i << " : ";
            // cout << a[j] << " " << v[i] << "\n";
            a[j] = v[i];
            ans++;
            j++;
            i++;
        }
        else{
            vis[a[j]] = true;
            j++;
        }


    }
    cout << ans << "\n";
    for(ll i=0;i<n;i++){
        cout << a[i] << " ";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}