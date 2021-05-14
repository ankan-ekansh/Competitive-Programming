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
    
    ll n, k;
    cin >> n >> k;
    deque<ll> dq;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        dq.push_back(x);
    }
    ll ctr = 0;
    while(!dq.empty()){
        ll l = dq.front(), r = dq.back();
        if(l <= k && r > k){
            ctr++;
            dq.pop_front();
        }
        else if(r <= k && l > k){
            ctr++;
            dq.pop_back();
        }
        else if(r <= k && l <= k){
            if(dq.size() == 1){
                ctr += 1;
                dq.pop_front();
            }
            else{
                ctr += 2;
                dq.pop_back();
                dq.pop_front();
            }
        }
        else{
            break;
        }
    }
    cout << ctr << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}