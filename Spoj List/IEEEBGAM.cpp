#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        int n;
        cin>>n;
        
        if(n==1){
            cout<<"0.50000000\n";
        }
        else{
            // cout.precision(8);
            // cout.setf( std::ios::fixed, std:: ios::floatfield );
            // cout<<(double)(n-1)/(double)n;
            // cout<<"\n";
            double ans = (double)(n)/(double)(n+1);
            printf("%.8f\n",ans);
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}