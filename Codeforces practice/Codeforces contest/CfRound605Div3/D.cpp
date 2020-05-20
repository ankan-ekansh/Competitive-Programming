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

    long n;
    cin >> n;
    long a[n];
    long ans = 0;
    for(long i=0;i<n;i++){
        cin >> a[i];
    }
    long l[n]={0}, r[n+1]={0};
    l[0] = 1;
    for(long i=1;i<n;i++){
        if(a[i] > a[i-1]){
            l[i] = l[i-1] + 1;
            ans = max(ans, l[i]);
        }
        else{
            l[i] = 1;
        }
    }
    // if(ans != n){
    //     ans++;
    // }
    r[n] = 0;
    for(long i=n-1;i>=0;i--){
        if(a[i+1] > a[i]){
            r[i] = r[i+1] + 1;
        }
        else{
            r[i] = 1;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout << l[i] << " ";
    // }
    // cout << "\n";
    // for(int i=0;i<n;i++){
    //     cout << r[i] << " ";
    // }
    // cout << "\n";
    // for(int i=n-1;i>0;i--) { 
	// 	if((a[i+1]-a[i-1])>1) 
	// 		ans = max(ans, l[i-1] + r[i+1]); 
	// }
    // ans = max(ans, r[0]-1);
    // cout << ans << "\n";
    for(int i=0;i<n;i++){
        if(i == 0){
            ans = max(ans, r[1]);
            // cout << i << " " << ans << "\n";
        }
        else{
            if(a[i-1] < a[i+1]){
                ans = max(ans, l[i-1] + r[i+1]);
            }
            // ans = max(ans, l[i-1] + r[i+1]);
            // cout << i << " " << ans << "\n";
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}