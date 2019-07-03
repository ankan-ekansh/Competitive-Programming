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
        cin.get();
        string a;
        getline(cin,a);
        int m;
        cin>>m;
        cin.get();
        string b;
        getline(cin,b);
        bool flag = false;
        for(int i=0;i<a.size()-2*m-1;i++){
            string c = a.substr(i,2*m-1);
            if(b.compare(c) == 0){
                // s=i;
                // e=i+m-1;
                flag = true;
                break;
            }
        }
        // for(int i=s;i<=e;i++){
        //     cout<<b[i];
        // }
        if(flag){
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