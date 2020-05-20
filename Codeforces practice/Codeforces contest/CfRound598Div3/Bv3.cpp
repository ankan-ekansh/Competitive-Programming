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
 
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int i = 0;
        while(i < n){
            int j = min_element(a.begin() + i, a.end()) - a.begin();
            int temp = a[j];
            a.erase(a.begin() + j);
            a.insert(a.begin() + i, temp);
            if(i == j){
                i = j + 1;
            }
            else{
                i = j;
            }
        }
        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}