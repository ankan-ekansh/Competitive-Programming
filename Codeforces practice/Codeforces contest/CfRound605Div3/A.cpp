#include<bits/stdc++.h>
using namespace std;
int dis(int a, int b, int c){
    return abs(a-b) + abs(a-c) + abs(b-c);
}
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
 
        int a[3];
        for(int i=0;i<3;i++){
            cin >> a[i];
        }
        sort(a, a+3);
        if((a[0] == a[1]) && (a[0] == a[2])){
            cout << "0\n";
        }
        else if((a[0] == a[1]) && (a[0] != a[2])){
            cout << min(min(dis(a[0]+1, a[1]+1, a[2]-1), dis(a[0]+1, a[1]+1, a[2])), dis(a[0], a[1], a[2]-1)) << "\n";
        }
        else if((a[1] == a[2]) && (a[1] != a[0])){
            cout << min(min(dis(a[0]+1, a[1]-1, a[2]-1), dis(a[0]+1, a[1], a[2])), dis(a[0], a[1]-1, a[2]-1)) << "\n";
        }
        else{
            cout << dis(a[0]+1,a[1],a[2]-1) << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}