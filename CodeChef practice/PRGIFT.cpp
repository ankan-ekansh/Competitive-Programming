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

        /* ---------- AC Code ---------
        int n,k;
        cin>>n>>k;
        int c=0;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2 == 0){
                c++;
            }
        }
        if(k==0 && c==n){
            cout<<"NO\n";
            continue;
        }
        if(k<=c){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        */
        int n,r;
        cin>>n>>r;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int l = 0;
        bool found = false;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                l = 0;
                //int count = 0;
                for(int k=i;k<=j;k++){
                    //cout<<a[k]<<" ";
                    if(a[k] % 2 == 0){
                        l++;
                        //count++;
                    }
                }
                if(l == r /*&& count > 0*/){
                    found = true;
                    break;
                }
                //cout<<"\n";
            }
            if(found){
                break;
            }
        }
        if(found){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        //cout<<"Next\n\n";
        
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}