#include<bits/stdc++.h>
using namespace std;
int a[11][11];
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
        
        int r,c;
        cin>>r>>c;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>a[i][j];
            }
        }
        bool found = false;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                int count=0;
                if(i-1 >= 1){
                    count++;
                }
                if(i+1 <= r){
                    count++;
                }
                if(j-1 >= 1){
                    count++;
                }
                if(j+1 <= c){
                    count++;
                }
                if(count>a[i][j]){
                    found = true;
                }
                else{
                    found = false;
                    break;
                }
             }
            if(!found){
                break;
            }
        }
        if(found){
            cout<<"Stable\n";
        }
        else{
            cout<<"Unstable\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}