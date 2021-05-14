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
        ll x = 1, sum = 0;
        multiset<ll> s;
        while(sum <= n){
            if(sum == n){
                break;
            }
            if((sum + x) <= n){
                s.insert(x);
                // cout << x << " ";
                sum += x;
                x *= 2;
            }
            else{
                s.insert(n-sum);
                // cout << " ---- " << n-sum << "\n";
                break;
            }
        }
        auto it = s.begin();
        ll tmp = *it;
        it++;
        // cout << tmp << " ";
        cout << s.size() - 1 << "\n";
        while(it != s.end()){
            cout << (*it - tmp) << " ";
            // cout << *it << " ";
            tmp = *it;
            it++;
        }
        cout << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}