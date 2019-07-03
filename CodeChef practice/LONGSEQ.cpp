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
    int t;
    cin>>t;
    while(t--){
 
        string s;
        cin>>s;
        int f[2]={0};
        for(auto i = s.begin();i != s.end();i++){
            if(*i == '0'){
                f[0]++;
            }
            else{
                f[1]++;
            }
        }
        if(f[0] == 1 || f[1] == 1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}