#include<bits/stdc++.h>
using namespace std;
int64_t pos[200007];
int64_t ms[200007];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int64_t n, k;
    cin >> n >> k;
    int64_t a[n];
    for(int64_t i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int64_t ans = INT64_MAX;
    for(int64_t i=0;i<n;i++){
        int64_t x = a[i];
        int64_t count = 0;
        pos[x]++;
        if(pos[x] == k){
            ans = min(ans, ms[x]);
        }
        while(x > 0){
            x/=2;
            count++;
            pos[x]++;
            ms[x]+=count;
            if(pos[x] == k){
                ans = min(ans, ms[x]);
            }
        }
    }
    cout << ans << "\n";



    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}