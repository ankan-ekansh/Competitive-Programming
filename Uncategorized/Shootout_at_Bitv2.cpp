#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    ll p[n];
    for(ll i=0;i<n;i++){
        cin >> p[i];
    }
    sort(p, p+n, greater<ll>());
    ll ans = 0;
    vector<pair<ll, ll>> v;
    v.push_back(make_pair(p[0], 1));
    ll j = 0;
    for(ll i=1;i<n;i++){
        if(p[i] != p[i-1]){
            v.push_back(make_pair(p[i], 1));
            j++;
        }
        else{
            v[j].second++;
        }
    }
    ll s = v.size();
    ll update[s+7]={0};
    ll a[s+7];
    for(ll i=0;i<s;i++){
        // v[i].second = v[i].second + update[i];
        // if(v[i].second < 0){
        //     v[i].second = 0;
        // }
        ll temp = v[i].second + update[i];
        if(temp < 0){
            temp = 0;
        }
        a[i] = temp;
        // cout << "temp " << temp << "\n";
        update[i+1] = update[i] + update[i+1];
        update[i+1] = update[i+1] - temp;
        update[s+1] = update[s+1] + temp;
    }

    v[s-1].second = v[s-1].second + update[s-1];
    update[s+1] = update[s+1] + v[s-1].second;
    
    //cout << v[0].first << " " << v[0].second << "\n";
    for(ll i=1;i<s;i++){
        //cout << v[i].first << " " << v[i].second << "\n";
        //cout << update[i] << "\n";
        update[i]+=update[i-1];
    }
    // update[s] = update[s] + update[s-1];
    // for(ll i=0;i<s;i++){
    //     cout << update[i] << "\n";
    //     if((update[i] + v[i].second) > 0){
    //         ans+=((v[i].first)*(update[i] + v[i].second));
    //     }
    // }
    //cout << update[s] << "\n";
    for(ll i=0;i<s;i++){
        ans+=(a[i] * v[i].first);
    }
    cout << ans << "\n";
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}