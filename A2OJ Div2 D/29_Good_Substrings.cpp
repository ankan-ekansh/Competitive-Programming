/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll p = 31, m = 18014398777917439;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    string t;
    cin >> t;
    ll k;
    cin >> k;
    ll badctr = 0;
    ll bad[s.length() + 7] = {0};
    for(ll i=0;i<s.length();i++){
        if(t[(s[i] - 'a')] == '0'){
            badctr++;
        }
        bad[i] = badctr;
    }
    unordered_set<ll> hashes;
    ll cp = 1;
    for(ll i=0;i<s.length();i++){
        ll hash = 0;
        cp = 1;
        for(ll j=i;j<s.length();j++){
            if(i == 0){
                if(bad[j] <= k){
                    hash = (hash + ((cp % m) * (s[j] - 'a' + 1)) % m) % m;
                    cp = (cp * p) % m;
                    hashes.insert(hash);
                }
            }
            else{
                if(bad[j] - bad[i-1] <= k){
                    hash = (hash + ((cp % m) * (s[j] - 'a' + 1)) % m) % m;
                    cp = (cp * p) % m;
                    hashes.insert(hash);
                }
            }
        }
    }
    cout << hashes.size() << "\n";
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}