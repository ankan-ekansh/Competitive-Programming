/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isDivisor(string& s1, string &s2, ll sz){
    if(s1.length() % sz != 0 || s2.length() % sz != 0){
        return false;
    }
    for(ll i=0;i<s1.length();i++){
        if(s1[i] != s1[i%sz]){
            return false;
        }
    }
    for(ll i=0;i<s2.length();i++){
        if(s2[i] != s1[i%sz]){
            return false;
        }
    }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s1, s2;
    cin >> s1 >> s2;
    ll sz = min(s1.length(), s2.length());
    ll ans = 0;
    for(ll i=1;i<=sz;i++){
        ans += isDivisor(s1, s2, i);
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}