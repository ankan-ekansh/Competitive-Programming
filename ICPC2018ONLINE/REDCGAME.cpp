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
 
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a,a+n);
        int x,y;
        long sum = 0;
        for(int i=0;i<n;i++){
            if(a[i] >= k){
                x = i;
                break;
            }
            sum+=a[i];
        }
        y = x+1;
        while(x <= n-2){
            // cout << a[x] << " " << a[y] << "\n";
            while(min(a[x], a[y]) > k){
                a[x]--;
                a[y]--;
            }
            // cout << a[x] << " " << a[y] << "\n";
            sum+=a[x];
            x++;
            y++;
        }
        sum+=a[x];
        cout << sum << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}