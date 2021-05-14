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
    string s;
    cin >> s;
    if(k == 2){
        string sa = s, sb = s;
        for(ll i=0;i<s.length();i++){
            if(i % 2 == 0){
                sa[i] = 'A';
                sb[i] = 'B';
            }
            else{
                sa[i] = 'B';
                sb[i] = 'A';
            }
        }
        ll ca = 0, cb = 0;
        for(ll i=0;i<s.length();i++){
            if(s[i] != sa[i]){
                ca++;
            }
            if(s[i] != sb[i]){
                cb++;
            }
        }
        ll ans = min(ca, cb);
        cout << ans << "\n";
        if(ca < cb){
            cout << sa << "\n";
        }
        else{
            cout << sb << "\n";
        }
        return 0;
    }
    ll ans = 0;
    for(ll i=1;i<n;i++){
        if(s[i] == s[i-1]){
            if(s[i-1] != 'A' && s[i+1] != 'A'){
                s[i] = 'A';
                ans++;
            }
            else if(s[i-1] != 'B' && s[i+1] != 'B'){
                s[i] = 'B';
                ans++;
            }
            else if(s[i-1] != 'C' && s[i+1] != 'C'){
                s[i] = 'C';
                ans++;
            }
        }
    }
    cout << ans << "\n";
    cout << s << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}