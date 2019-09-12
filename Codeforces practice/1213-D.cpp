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

    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        m[x]++;
    }
    auto j = m.begin();
    for(auto i=m.begin();i!=m.end();i++){
        if((*i).second >= k){
            cout << "0\n";
            exit(0);
        }
        if((*i).second > (*j).second){
            j = i;
        }
    }
    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}