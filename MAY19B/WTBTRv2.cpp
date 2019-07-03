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
 
        int64_t n;
        cin>>n;
        int64_t x[n],y[n];
        vector<pair<double,pair<pair<int64_t,int64_t>,pair<int64_t,int64_t>>>> distance;
        for(int64_t i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        for(int64_t i=0;i<n-1;i++){
            for(int64_t j=i+1;j<n;j++){
                double d = sqrt(pow(x[j]-x[i],2) + pow(y[j]-y[i],2));
                distance.push_back(make_pair(d,make_pair(make_pair(x[j],y[j]),make_pair(x[i],y[i]))));
            }
        }
        sort(distance.begin(),distance.end());
        for(auto i = distance.begin();i!=distance.end();i++){
            cout<<(*i).first<<" "<<(*i).second.first.first<<" "<<(*i).second.first.second<<" "<<(*i).second.second.first<<" "<<(*i).second.second.second<<"\n";
        }

 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}