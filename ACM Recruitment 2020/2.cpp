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
 
        int x, y, z, l, b, h;
        cin >> x >> y >> z;
        cin >> l >> b >> h;
        int count = 0;
        if(x <= l && y <= b && z <= h){
            count++;
        }
        if(x <= l && y <= h && z <= b){
            count++;
        }
        if(x <= h && y <= b && z <= l){
            count++;
        }
        if(x <= h && y <= l && z <= b){
            count++;
        }
        if(x <= b && y <= l && z <= h){
            count++;
        }
        if(x <= b && y <= h && z <= l){
            count++;
        }
        cout << 4 * count <<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}