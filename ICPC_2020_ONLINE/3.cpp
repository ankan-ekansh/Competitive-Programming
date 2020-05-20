#include<bits/stdc++.h>
using namespace std;
bool overlap(int x1, int x2, int y1, int y2) {
  return (x1 <= y2) && (y1 <= x2);
}
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
        for(int i=0;i<n;i++){
            cin >> l[i] >> r[i] >> v[i];
        }
        vector<int> x,y,z;
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(overlap(l[i],r[i],l[j],r[j])){
                    if(v[i] == v[j]){
                        // x.push_back(l[i]);
                        // y.push_back(r[i]);
                        // z.push_back(v[i]);
                        // x.push_back(l[j]);
                        // y.push_back(r[j]);
                        // z.push_back(v[j]);
                        if(l[i] <= l[j]){
                            x.push_back(l[i]);
                            y.push_back(r[j]);
                        }
                        else{
                            x.push_back(l[j]);
                            y.push_back(r[i]);
                        }
                        z.push_back(v[i]);
                    }
                }
            }
        }
        // for(int i=0;i<x.size();i++){
        //     cout << x[i] << " " << y[i] << " " << z[i] << "\n";
        // }
        // cout << "\n";
        // bool flag = false;
        for(int i=0;i<x.size();i++){
            for(int j=i+1;j<x.size();j++){
                if(overlap(x[i],y[i],x[j],y[j])){
                    if(v[i] == v[j]){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag){
                break;
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