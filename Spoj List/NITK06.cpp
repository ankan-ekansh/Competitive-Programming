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
        bool flag = true;
        for(int i=0;i<n-1;i++){
            int x = a[i];
            a[i]-=min(x, a[i+1]);
            a[i+1]-=min(x, a[i+1]);
            if(a[i] == 0 && a[i+1] != 0){
                continue;
            }
            else if(a[i] == 0 && a[i+1] == 0){
                i++;
                continue;
            }
            else if(a[i] != 0 && a[i+1] == 0){
                flag = false;
                break;
            }
        }
        if(flag && a[n-1] == 0){
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