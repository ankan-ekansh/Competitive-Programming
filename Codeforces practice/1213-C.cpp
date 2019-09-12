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
    int a[11][11]={
        {0},
        {1, 3, 6, 10, 15, 21, 28, 36, 45, 45},
        {2, 6, 12, 20, 20, 20, 20, 20, 20, 20},
        {3, 9, 18, 20, 25, 33, 34, 38, 45, 45},
        {4, 12, 14, 20, 20, 20, 20, 20, 20, 20},
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
        {6, 8, 16, 20, 20, 20, 20, 20, 20, 20},
        {7, 11, 12, 20, 25, 27, 36, 42, 45, 45},
        {8, 14, 18, 20, 20, 20, 20, 20, 20, 20},
        {9, 17, 24, 30, 35, 39, 42, 44, 45, 45}
    };
    while(t--){
 
        int64_t n, m;
        cin >> n >> m;
        int64_t nt = n/m;
        int64_t l = 0;
        int64_t ans = 0;
        if(m % 10 == 5){
            l = nt/2;
            ans+=(l * a[5][9]);
            ans+=(a[5][(nt % 2) - 1]);
        }
        else if((m % 10) == 0){
            l = nt;
            ans+=(l * a[0][9]);
        }
        else if((m % 10) % 2 == 0){
            l = nt/5;
            // cout << nt % 5 << "\n";
            // cout << a[m % 10][nt % 5] << "\n";
            ans+=(l * a[m % 10][9]);
            // cout << ans << "\n";
            ans+=(a[m % 10][(nt % 5) - 1]);
            // cout << ans << "\n";
        }
        else if((m % 10) % 2 != 0){
            l = nt/10;
            ans+=(l * a[m % 10][9]);
            ans+=(a[m % 10][(nt % 10) - 1]);
        }
        cout << ans << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}