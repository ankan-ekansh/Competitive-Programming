/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        sort(s.begin(), s.end());
        if(s[0] != s[k-1]){
            cout << s[k-1] << "\n";
        }
        else{
            cout << s[0];
            if(s[k] != s[n-1]){
                for(int i=k;i<n;i++){
                    cout << s[i];
                }
                cout << "\n";
            }
            else{
                for(int i=0;i<ceil(n-k)/k;i++){
                    cout << s[n-1];
                }
                cout << "\n";
            }
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}