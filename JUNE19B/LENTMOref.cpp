#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int li;
 
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        li n; cin>>n;
        li arr[n];
        for(li i=0;i<n;i++) cin>>arr[i];
        li k,x; cin>>k>>x;
       
        li sm=0;
        for(li i=0;i<n;i++) sm+=arr[i];
       
        for(li i=0;i<n;i++){
            arr[i]= (arr[i]^x)-arr[i];
        }
       
       
        li mm=sm;
        sort(arr,arr+n,greater<li>());
//        for(li i=0;i<n;i++) cout<<arr[i]<<" ";
//        cout<<endl;
       
        li pv=0;
        for(li i=0;arr[i]>0;i++) pv++;
       
        if(k%2){
            if(n>k) for(li i=0;arr[i]>0;i++) sm+=arr[i];
            else{
                for(li i=0;i<k;i++) sm+=arr[i];
            }
        }
        else{
            if(n>k){
                if(pv%2==0){
                    for(li i=0;arr[i]>0;i++) sm+=arr[i];
                }
                else{
                    li p1=pv-1,p2=pv+1;
                    li am=sm,bm=sm;
                    for(li i=0;i<p1;i++) am+=arr[i];
                    for(li i=0;i<p2;i++) bm+=arr[i];
                    sm=max(am,bm);
                }
            }
            else{
                for(li i=0;i<k;i++) sm+=arr[i];
            }
        }
       
        cout<<max(mm,sm)<<endl;
    }
}