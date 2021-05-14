/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isHill(int a[], int n, int i){
    return (i > 0 && i < n-1 && a[i] > a[i-1] && a[i] > a[i+1]);
}
bool isValley(int a[], int n, int i){
    return (i > 0 && i < n-1 && a[i] < a[i-1] && a[i] < a[i+1]);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin >> n;
        int a[n];
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        int iv = 0;
        int hv[n] = {0};
        for(int i=1;i<n-1;i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                iv++;
                hv[i] = 1;
            }
            if(a[i] < a[i-1] && a[i] < a[i+1]){
                iv++;
                hv[i] = 1;
            }
        }
        int ans = iv;
        for(int i=1;i<n-1;i++){
            int tmp = a[i];
            a[i] = a[i-1];
            ans = min(ans, iv - hv[i-1] - hv[i] - hv[i+1] + isHill(a,n,i) + isValley(a,n,i) + isHill(a,n,i-1) + isValley(a,n,i-1) + isHill(a,n,i+1) + isValley(a,n,i+1));
            a[i] = a[i+1];
            ans = min(ans, iv - hv[i-1] - hv[i] - hv[i+1] + isHill(a,n,i) + isValley(a,n,i) + isHill(a,n,i-1) + isValley(a,n,i-1) + isHill(a,n,i+1) + isValley(a,n,i+1));
            a[i] = tmp;
        }
        cout << ans << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}