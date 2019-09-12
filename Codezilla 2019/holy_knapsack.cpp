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
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for(int64_t i=0;i<n;i++){
        cin >> a[i];
    }
    int64_t i = 0, j = 0;
    int64_t sum = 0;
    int64_t cost = INT64_MAX;
    while(i < n && j < n){
        cost = min(cost, abs(sum - k));
        if(sum <= k){
            sum+=a[j];
            j++;
        }
        else if(sum > k){
            sum-=a[i];
            i++;
        }
        cost = min(cost, abs(sum - k));
    }
    cout << cost << "\n";
    
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}