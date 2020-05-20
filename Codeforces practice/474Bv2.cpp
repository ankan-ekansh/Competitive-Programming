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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        a[i]+=a[i-1];
    }
    int q;
    cin >> q;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        auto j = upper_bound(a.begin(),a.end(),x);
        auto k = j;
        k--;
        if(j != a.end()){
            if(*k != x){
                //cout << x << ": ";
                cout << j - a.begin() + 1<< "\n";
            }
            else{
                //cout << x << ": ";
                cout << j - a.begin() << "\n";
            }
        }
        else{
            cout << n << "\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}