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
        vector<int> v[n];
        int e[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                v[i].push_back(x);
            }
        }
        bool flag = true;
        e[n-1] = *(max_element(v[n-1].begin(),v[n-1].end()));
        long long sum = *(max_element(v[n-1].begin(),v[n-1].end()));
        for(int i=n-2;i>=0;i--){
            e[i]=0;
            for(int j=0;j<n;j++){
                if(v[i][j] < e[i+1]){
                    e[i] = max(e[i], v[i][j]);
                }
            }
            if(e[i] == 0){
                cout<<"-1\n";
                flag = false;
                break;
            }
            sum+=e[i];
        }
        if(flag)
            cout<<sum<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}