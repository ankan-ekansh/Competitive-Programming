/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n, q;
    cin >> n >> q;
    vector<pair<ll, ll>> q1(n);
    vector<pair<ll, ll>> q2(q);
    vector<pair<ll, ll>> ans(q);
    // pair<ll, ll> q1[n], q2[q], ans[q];
    vector<ll> a(n);
    deque<ll> dq;
    ll pos = -1;
    ll mxm = INT_MIN;
    for(ll i=0;i<n;i++) {
        cin >> a[i];
        dq.push_back(a[i]);
        if(a[i] > mxm) {
            mxm = a[i];
            pos = i;
        }
    }
    for(ll i=0;i<q;i++) {
        ll x;
        cin >> x;
        q2[i] = {i, x-1};
    }
    sort(q2.begin(), q2.end(), cmp);
    ll k = 0;
    // cout << pos << "\n";
    // cout << dq.size() << "\n";
    for(ll i=0;i<pos;i++) {
        ll a = dq.front();
        dq.pop_front();
        ll b = dq.front();
        dq.pop_front();
        q1[i] = {a, b};
        if(b > a) {
            swap(a, b);
        }
        dq.push_front(a);
        dq.push_back(b);
        // if(a == mxm) {
        //     break;
        // }

        // a = dq.front();
        // dq.pop_front();
        // b = dq.front();
        // dq.push_front(a);
        // if(q2[k].second == i) {
        //     a = dq.front();
        //     dq.pop_front();
        //     b = dq.front();
        //     q1[k] = {a, b};
        //     dq.push_front(a);
        //     k++;
        // }
    }
    // for(ll i=0;i<n;i++) {
    //     cout << i << " " << q1[i].first << " " << q1[i].second << "\n";
    // }
    // cout << "---";
    // cout << pos << "\n";
    // for(ll i=0;i<dq.size();i++) {
    //     cout << dq[i] << " ";
    // }
    // cout << "\n";
    // cout << dq.size() << "\n";
    while(k < q) {
        // ll ops = q2[k].second;
        // ops = ops % (n-1);
        // ans[q2[k].first] = q1[ops];
        // k++;
        if(q2[k].second < pos) {
            ans[q2[k].first] = q1[q2[k].second];
        }
        else {
            ll tmppos = q2[k].second - pos;
            tmppos = tmppos % (n-1);
            tmppos += 1;
            ll ele = dq[tmppos];
            // cout << ele << " " << tmppos << "\n";
            ans[q2[k].first] = {mxm, ele}; 
        }
        k++;
    }
    for(ll i=0;i<q;i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}