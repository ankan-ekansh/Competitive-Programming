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
    // int t;
    // cin>>t;
    // while(t--){
 
        string s, ans;
        int n;
        cin >> n;
        cin >> s;
        int invert = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                ans.push_back('0');
            }
            else if(s[i] == '2'){
                ans.push_back('1');
                ans.push_back('1');
            }
            else if(s[i] == '3'){
                ans.push_back('0');
                ans.push_back('1');
            }
            else if(s[i] == '4'){
                for(int j=0;j<ans.size();j++){
                    if(ans[j] == '0'){
                        ans[j] = '1';
                    }
                    else{
                        ans[j] = '0';
                    }
                }
            }
        }
        for(int i=0;i<ans.size();i++){
           // if(invert % 2 == 0){
                if(ans[i] == '0'){
                    cout << 'a';
                }
                else{
                    cout << 'b';
                }
           // }
            // else{
            //     if(ans[i] == '0'){
            //         cout << 'b';
            //     }
            //     else{
            //         cout << 'a';
            //     }
            // }
        }
 
//    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}