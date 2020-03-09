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
    long n12=0,n14=0,n34=0,ans=0;
    while(t--){
 
        string s;
        cin >> s;
        if(s == "1/2"){
            n12++;
        }
        else if(s == "1/4"){
            n14++;
        }
        else if(s == "3/4"){
            n34++;
        }
 
    }
    if(n14 < n34){
        ans+=n14+(n34-n14);     //combine 1/4 and 3/4, 1/4s used with 3/4s and 3/4s cant be combined more
        ans+=(n12/2)+(n12%2)+1;    //1/2 can be combined to make 1, remaining slices are waste
    }
    else{
        ans+=n34;   //3/4 are added since they cant be combined, 1/4 are to be combined
        n14=n14-n34;
        n12+=n14/2;
        n14=n14%2;
        ans+=(n12/2)+max(n12%2, n14)+1;
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}