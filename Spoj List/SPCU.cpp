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
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<"\n";
        bool flag = true;
        for(int i=0;i<n;i++){
            //cout<<a[i]<<" ";
            // if(i == 0){
            //     if(a[i] != 0){
            //         flag = false;
            //         break;
            //     }
            // }
            // else if(a[i] - a[i-1] > 1){
            //     //cout<<a[i]<<"\n";
            //     flag = false;
            //     break;
            // }


            if(a[i] > i){
                flag = false;
                break;
            }
        }
        //cout<<"\n";
        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
 
    }
    //#ifndef ONLINE_JUDGE
    //    cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    //#endif
    return 0;
}