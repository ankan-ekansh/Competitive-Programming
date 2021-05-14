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
        
        string s;
        cin >> s;
        ll n = s.length();
        ll m1 = -1, m2 = -1, m3 = -1;
        ll prev = -1;
        for(ll i=0;i<n;i++){
            if(m1 == -1 && s[i] == 'R'){
                m1 = i;
            }
            if(s[i] == 'R'){
                if(prev == -1){
                    m2 = i;
                    prev = i;
                }
                else{
                    m2 = max(m2, abs(i-prev));
                    prev = i;
                }
                m3 = i;
            }
        }
        // cout << m1 << " " << m2 << " " << m3 << "\n";
        cout << max({m1+1, m2, n-m3}) << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}