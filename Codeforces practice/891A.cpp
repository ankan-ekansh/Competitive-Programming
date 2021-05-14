/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int a[n];
    int ones = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] == 1){
            ones++;
        }
    }
    if(ones){
        cout << n - ones << "\n";
        return 0;
    }
    int mnm = INT_MAX;
    for(int i=0;i<n;i++){
        int g = a[i];
        for(int j=i;j<n;j++){
            g = __gcd(g, a[j]);
            if(g == 1){
                mnm = min(mnm, j-i);
            }
        }
    }
    if(mnm == INT_MAX){
        cout << "-1\n";
        return 0;
    }
    cout << mnm + n - 1 << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}