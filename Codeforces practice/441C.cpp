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
    
    ll n, m, k;
    cin >> n >> m >> k;
    ll x = 1, y = 1;
    bool inc = true;
    for(ll i=0;i<k-1;i++){
        cout << "2 " << x << " " << y << " ";
        if(inc){
            y++;
            if(y == m+1){
                x++;
                y--;
                inc = false;
            }
        }
        else{
            y--;
            if(y == 0){
                x++;
                y++;
                inc = true;
            }
        }
        cout << x << " " << y << "\n";
        if(inc){
            y++;
            if(y == m+1){
                x++;
                y--;
                inc = false;
            }
        }
        else{
            y--;
            if(y == 0){
                x++;
                y++;
                inc = true;
            }
        }
    }
    // cout << "\n";
    ll cnt = 0;
    vector<pair<ll, ll>> v;
    while(x <= n && y <= m){
        v.push_back({x, y});
        if(inc){
            y++;
            if(y == m+1){
                x++;
                y--;
                inc = false;
            }
        }
        else{
            y--;
            if(y == 0){
                x++;
                y++;
                inc = true;
            }
        }
    }
    cout << v.size() << " ";
    for(ll i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << " ";
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}