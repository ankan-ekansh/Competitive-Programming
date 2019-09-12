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
 
        long n, k;
        cin >> n >> k;
        map<long, long> m;
        long a[n+1];
        for(long i=0;i<n;i++){
            cin >> a[i];
            m[a[i]]++;
        }
        auto i = m.begin();
        auto j = i;
        j++;
        for(;j!=m.end();j++){
            (*j).second = (*i).second + (*j).second;
            i++;
        }
        for(long i=0;i<n;i++){
            cout << m[a[i]] - 1  << " ";
        }
        cout << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}