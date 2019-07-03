#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int64_t t;
    cin>>t;
    while(t--){
 
        string s;
        char d;
        cin>>s;
        cin>>d;
        int n = s.size();
        int m = min(s.back(),d);
        for(int i=n-1;i>=0;i--){
            if(s[i] < m){
                m = s[i];
            }
            else if(s[i] > m){
                s.erase(i,1);
            }
        }
        s.resize(n,d);
        cout<<s<<"\n";

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}