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
 
        int x,y;
        cin>>x>>y;
        if((x == y) || (y == (x-2))){
            if(x % 2 == 0){
                cout<<(x+y)<<"\n";
            }
            else{
                cout<<(x+y-1)<<"\n";
            }
        }
        else{
            cout<<"No Number\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}