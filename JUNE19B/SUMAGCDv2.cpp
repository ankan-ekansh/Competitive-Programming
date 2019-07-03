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
        int a[n];
        map<int,int> m;
        int mx = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]=1;
            mx = max(mx, a[i]);
        }
        for(auto i = m.begin();i!=m.end();i++){
            int j = (*i).first * 2;
            while(j<=mx){
                if(m[j])
                    m[j]++;
                j=j+(*i).first;
            }
        }
        for(auto i = m.begin();i!=m.end();i++){
            if(m[(*i).first])
            cout<<(*i).first<<" "<<(*i).second<<"\n";
        }
        cout<<"\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}