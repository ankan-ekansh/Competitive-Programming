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
        int a;
        cin>>a;
        int min = a;
        int pos = 0;
        for(int i=1;i<n;i++){
            cin>>a;
            if(a < min){
                min = a;
                pos = i;
            }
        }
        cout<<pos+1<<"\n";
 
        // int n;
        // cin>>n;
        // int a[n]={0},ps[n]={0},ss[n]={0};
        // cin>>a[0];
        // ps[0]=a[0];
        // for(int i=1;i<n;i++){
        //     cin>>a[i];
        //     ps[i]=ps[i-1]+a[i];
        // }
        // ss[0]=ps[n-1];
        // int min_diff = ps[0]+ss[0];
        // int min_pos = 0;
        // for(int i=1;i<n;i++){
        //     ss[i]=ss[0]-ps[i-1];
        //     if(ss[i] + ps[i] < min_diff){
        //         min_diff = ss[i] + ps[i];
        //         min_pos = i;
        //     }
        // }
        // cout<<min_pos+1<<"\n";
        // for(int i=0;i<n;i++){
        //     cout<<ps[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<n;i++){
        //     cout<<ss[i]<<" ";
        // }
        // cout<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}