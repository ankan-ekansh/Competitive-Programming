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
    
    int n, t;
    cin >> n >> t;
    if(t == 10){
        if(n == 1){
            cout << "-1\n";
            return 0;
        }
        for(int i=0;i<n-1;i++){
            cout << 1;
        }
        cout << 0 << "\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        cout << t;
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}