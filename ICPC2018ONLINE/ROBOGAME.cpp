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
 
        string s;
        cin >> s;
        int a[s.length() + 15];
        memset(a, 0, sizeof(a));
        for(int i=0;i<s.length();i++){
            if(s[i] == '.'){
                continue;
            }
            else{
                if(i + 1 - (s[i] - '0') >= 1){
                    a[i + 1 - (s[i] - '0')]++;
                }
                else{
                    a[1]++;
                }
                a[i + 1 + (s[i] - '0') + 1]--;
            }
        }
        bool flag = true;
        for(int i=1;i<=s.length()+9;i++){
            a[i]+=a[i-1];
            if(a[i] > 1){
                cout << "unsafe\n";
                flag = false;
                break; 
            }
        }
        // for(int i=1;i<=s.length()+9;i++){
        //     cout << a[i] << " ";
        // }
        // cout << "\n";
        if(flag){
            cout << "safe\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}