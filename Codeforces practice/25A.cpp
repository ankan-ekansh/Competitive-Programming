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

    int n;
    cin >> n;
    int a[n];
    int e = 0, o = 0;
    int ei, oi;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] % 2 == 0){
            e++;
            ei = i;
        }
        else{
            o++;
            oi = i;
        }
    }
    if(e == 1){
        cout << ei+1 << "\n";
    }
    else{
        cout << oi+1 << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}