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

    map<int, int> m;
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int x=0;
    for(int i=0;i<n;i++){
        m[x+1]++;
        x+=a[i];
    }
    m[x+1]++;
    for(int i=2;i<=x;i++){
        m[i]+=m[i-1];
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int t;
        cin >> t;
        cout << m[t] << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}