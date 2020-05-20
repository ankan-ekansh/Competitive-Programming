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

    int n, p;
    cin >> n >> p;
    int q = 0;
    while(1){
        int t = n - (q*p);
        if(q >= __builtin_popcount(t) && t >=0){
            cout << q << "\n";
            break;
        }
        else if(q != __builtin_popcount(t)){
            q++;
        }
        else if(t < 0){
            cout << "-1\n";
            break;
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}