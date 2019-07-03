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
 
        int64_t a,b,c;
        cin>>a>>b>>c;
        int64_t d = (b*b)-(4*a*c);
        if(a!=0){
            if(d==0){
                cout<<"1\n";
            }
            else if(d<0){
                cout<<"0\n";
            }
        else{
                cout<<"2\n";
            }
        }
       
 
    }
    #ifndef ONLINE_JUDGE
        //cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}