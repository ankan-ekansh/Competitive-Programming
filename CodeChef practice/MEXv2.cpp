#include<bits/stdc++.h>
using namespace std;
bool a[200010];
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
 
        memset(a,0,200010);
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x]=true;
        }
        int j=0;
        for(int i=0;i<k;i++){
            while(a[j]){
                j++;
            }
            j++;
        }
        while(a[j]){
            j++;
        }
        cout<<j<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}