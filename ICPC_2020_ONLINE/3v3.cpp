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
        cin >> n;
        int l[n],r[n],v[n];
        vector<pair<int, pair<int,int>>> p;
        for(int i=0;i<n;i++){
            cin >> l[i] >> r[i] >> v[i];
            p.push_back(make_pair(l[i],make_pair(r[i],v[i])));
        }
        sort(p.begin(),p.end());
        // for(int i=0;i<n;i++){
        //     //cout << p[i].first << " " << p[i].second.first << " " << p[i].second.second << "\n";
        // }
        bool flag = false;
        for(int i=0;i<n-2;i++){
            if(v[i] == v[i+1] && v[i+1] == v[i+2]){
                if(((p[i].first <= p[i+1].first) && (p[i].second.first >= p[i+1].second.first)) || ((p[i+2].first <= p[i+1].first) && (p[i+1].second.first <= p[i+2].second.first))){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }

 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}