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
    
    ll n, k;
    cin >> n >> k;
    vector<pair<pair<ll, ll>, ll>> v;
    for(ll i=0;i<n;i++){
        ll t, a, b;
        cin >> t >> a >> b;
        v.push_back({{t, a}, b});
    }
    sort(v.begin(), v.end());
    // for(ll i=0;i<n;i++){
    //     cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second << "\n";
    // }
    // priority_queue<ll> alice, bob;  // individual books liked by each
    vector<ll> alice, bob;
    ll ans = 0;
    ll acnt = 0, bcnt = 0;
    for(ll i=0;i<n;i++){
        if(!v[i].first.second && !v[i].second){
            continue;
        }
        else if(v[i].first.second && !v[i].second){
            // alice likes the book
            if(acnt < k){
                alice.push_back(v[i].first.first);
                ans += v[i].first.first;
                acnt++;
            }
        }
        else if(!v[i].first.second && v[i].second){
            // bob likes the book
            if(bcnt < k){
                bob.push_back(v[i].first.first);
                ans += v[i].first.first;
                bcnt++;
            }
        }
        else if(v[i].first.second && v[i].second){
            // both alice and bob like the book
            // 1) Can include this and remove one from alice
            // 2) Can include this and remove one from bob
            // 3) Can include this and remove one from both alice and bob
            if(acnt < k || bcnt < k){
                // alice.push(v[i].first.first);
                // bob.push(v[i].first.first);
                ans += v[i].first.first;
                acnt++;
                bcnt++;
                if(acnt > k && alice.size()){
                    ans -= alice.back();
                    alice.pop_back();
                    acnt--;
                }
                if(bcnt > k && bob.size()){
                    ans -= bob.back();
                    bob.pop_back();
                    bcnt--;
                }
            }
            else{
                if(alice.size() && bob.size()){
                    ll rem = alice.back() + bob.back();
                    if(rem > v[i].first.first){
                        alice.pop_back();
                        bob.pop_back();
                        ans -= rem;
                        ans += v[i].first.first;
                    }
                }
                else if(alice.size()){
                    ll rem = alice.back();
                    if(rem > v[i].first.first){
                        alice.pop_back();
                        ans -= rem;
                        ans += v[i].first.first;
                        bcnt++;
                    }
                }
                else if(bob.size()){
                    ll rem = bob.back();
                    if(rem > v[i].first.first){
                        bob.pop_back();
                        ans -= rem;
                        ans += v[i].first.first;
                        acnt++;
                    }
                }
            }
            
        }
    }
    if(acnt < k || bcnt < k){
        cout << "-1\n";
        return 0;
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}