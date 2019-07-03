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
 
        int64_t d,c,l,g;
        cin>>c>>d>>l;
        g = c+d-l/4;
        if(l%4 !=0){
            cout<<"no\n";
            continue;
        }
        if(g<=min(c,2*d) && g>=0){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}