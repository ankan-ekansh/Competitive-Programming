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
    int64_t e = 0, o = 0;
    while(t--){
 
        int64_t x;
        cin >> x;
        if(x % 2 == 0){
            e++;
        }
        else{
            o++;
        }
 
    }
    if(o > e){
        swap(o, e);
    }
    cout << o << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}