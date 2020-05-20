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
        cin >> n;
        int a[n+1], b[n+1], c[n+1];
        memset(c, 0, sizeof(c));
        for(int i=1;i<=n;i++){
            cin >> a[i];
            b[a[i]] = i;
        }
        int swaps = n-1;
        for(int i=1;i<=n && swaps > 0;i++){
            for(int j=b[i]; j>=1; j--){
                if(j == n && c[j] == 0){
                    swap(a[j-1], a[j]);
                    b[a[j]]--;
                    b[a[j+1]]++;
                    c[j] = 1;
                }
            }
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}