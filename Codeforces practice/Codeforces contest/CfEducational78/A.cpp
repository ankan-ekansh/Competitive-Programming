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
 
        string p, h;
        cin >> p;
        cin >> h;
        // map<char, int> m;
        // for(int i=0;i<p.length();i++){
        //     m[p[i]]++;
        // }
        // int a[h.length()]={0};
        // for(int i=0;i<h.length();i++){
        //     if(m[h[i]]){
        //         a[i]++;
        //     }
        // }
        
        bool flag = false;
        for(int i=0;i<h.length();i++){
            for(int j=1;j<=h.length()-i;j++){
                string s = h.substr(i, j);
                // cout << s << "\n";
                if(is_permutation(s.begin(), s.end(), p.begin()) && s.length() == p.length()){
                    flag = true;
                    // cout << s << "\n";
                }
            }
        }
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        // cout << "---" << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}