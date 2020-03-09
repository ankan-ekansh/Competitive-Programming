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
    ll t;
    cin>>t;
    while(t--){
 
        ll n;       
        cin>>n;
        string s;
        cin>>s;
        ll index[27]={0};
        ll cost = 0;
        for(ll i = 0;i<s.length(); i+=2){
            // cout<<s[i]<<"\n";
            index[s[i]-97]++;
            char r = (char)(s[i+1] + 32);
            if(index[r-97]>0){
                index[r-97]--;
                continue;
            }
            else{
                cost++;
            }
        }
        cout<<cost<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}