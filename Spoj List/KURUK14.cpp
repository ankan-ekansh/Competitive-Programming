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
        int index[n]={0};
        // int pre[n]={0};
        // int post[n]={0};
        // for(int i=0;i<n;i++){
        //     pre[i]=i;
        //     post[i]=n-i-1;
        // }
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            index[a[i]]++;
            index[n-a[i]-1]++;
        }
        // for(int i=0;i<n;i++){
            // if(index[i] > 1){
            //     index[n-i-1]++;
            //     index[i]--;
            // }
        // }
        bool flag = true;
        for(int i=0;i<n;i++){
            //cout<<index[i]<<"\n";
            if(index[i] <= 1){
                flag = false;
            }
        }
        if(flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}