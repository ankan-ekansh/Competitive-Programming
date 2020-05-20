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

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    int arr[3];
    arr[0] = a, arr[1] = b, arr[2] = c;
    sort(arr, arr+3);
    a = arr[0], b = arr[1], c = arr[2];
    for(int i=0;i<=n;i+=a){
        for(int j=0;j<=n-i;j+=b){
            float z = (float)(n - i - j) / (float)c;
            if(floor(z) == ceil(z)){
                int x = i / a;
                int y = j / b;
                ans = max(ans, x + y + (int)z);
            }
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}