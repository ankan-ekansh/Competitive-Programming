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
    
    ll n, x, y;
    cin >> n >> x >> y;
    if(n > y){
        cout << "-1\n";
        return 0;
    }
    ll largest = y - (n-1);
    if(largest*largest + (n-1) < x){
        cout << "-1\n";
    }
    else{
        cout << largest << " ";
        for(ll i=1;i<n;i++){
            cout << "1 ";
        }
        cout << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}