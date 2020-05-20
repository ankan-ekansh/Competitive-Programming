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

    int n, m;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for(int i=0;i<m;i++){
        cin >> b[i]; 
    }
    sort(a,a+n);
    sort(b,b+m);
    int c[n] = {0}, d[m] = {0};

    int ans = 0;
    for(int i=0;i<n;i++){
        if(!c[i]){
            for(int j=0;j<m;j++){
                if(!d[j] && abs(b[j] - a[i]) <= 1){
                    ans++;
                    d[j] = 1;
                    break;
                }
            }
        }
        c[i] = 1;
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}