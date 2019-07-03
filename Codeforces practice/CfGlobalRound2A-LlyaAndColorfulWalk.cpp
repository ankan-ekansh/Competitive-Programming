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
    
    int n;
    cin>>n;
    vector<int> v;
    v.resize(n);
    int x=0,y=n-1;
    cin>>v[0];
    for(int i=1;i<n;i++){
        cin>>v[i];
        if(v[0]!=v[i]){
            x=i;
        }
    }
    for(int i=0;i<n;i++){
        if(v[i]!=v[n-1]){
            y=i;
            break;
        }
    }
    int dmax = max(x,n-y-1);
    cout<<dmax<<"\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}