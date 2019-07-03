/**********************************

*******Author: Ankan Ekansh********

***********************************/


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
        int x[n],y[n];
        vector<int> a,b;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
            a.push_back(x[i]+y[i]);     //storing values of y+x=C1 of different lines
            b.push_back(x[i]-y[i]);     //storing values of x-y=C2 of different lines
        }
        sort(a.begin(),a.end());    //sorting these in ascending order
        sort(b.begin(),b.end());
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<"\n";
        // }
        // for(int i=0;i<n;i++){
        //     cout<<b[i]<<"\n";
        // }
        int c1=INT_MAX,c2=INT_MAX;
        for(int i=0;i<n-1;i++){
            if(a[i+1]-a[i] < c1){       //finding closest distance between pair of lines with same slope
                c1 = abs(a[i+1]-a[i]);
                //cout<<a[i+1]<<" "<<a[i]<<"\n";
                //cout<<c1<<"\n";
            }
            if(b[i+1]-b[i] < c2){
                c2 = abs(b[i+1]-b[i]);
                //cout<<b[i+1]<<" "<<b[i]<<"\n";
                //cout<<c2<<"\n";
            }
        }
        double ans = (double)min(c1,c2)/(double)2.0;        //minimum of the closes distance is the required distance
        cout<<fixed<<ans<<"\n";
        //printf("%0.6lf\n",ans);
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}