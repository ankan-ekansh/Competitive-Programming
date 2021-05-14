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
    
    ll k;
    cin >> k;
    char c[10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
    ll a[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ll tmp = 1;
    ll cur = 1;
    while(tmp < k){
        for(int i=0;i<10 && tmp < k;i++){
            tmp = tmp / cur;
            a[i] = cur+1;
            tmp = tmp * a[i];
        }
        cur++;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<a[i];j++){
            cout << c[i];
        }
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}