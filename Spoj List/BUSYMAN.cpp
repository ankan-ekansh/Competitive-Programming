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
 
        int n;
        cin>>n;
        int s[n], e[n];
        vector<pair<int, int>> p;
        for(int i=0;i<n;i++){
            cin>>s[i]>>e[i];
            p.push_back(make_pair(e[i], s[i]));
        }
        sort(p.begin(), p.end());
        int c = 1;
        int x = 0;
        for(int i=1;i<n;i++){
            if(p[i].second >= p[x].first){
                c++;
                x = i;
            }
            //cout<<p[i].first<<" "<<p[i].second<<"\n";
        }
        cout<<c<<"\n";
        //cout<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}