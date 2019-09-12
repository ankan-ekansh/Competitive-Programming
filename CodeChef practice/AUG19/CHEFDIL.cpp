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
        int no = 0, nz = 0;
        cin>>s;
        for(int i=0;i<s.length();i++){
            if(s[i] == '0'){
                nz++;
            }
            else{
                no++;
            }
        }
        if((nz % 2 != 0) && (no % 2 != 0)){
            cout<<"WIN\n";
        }
        else if((nz % 2 == 0) && (no % 2 != 0)){
            cout<<"WIN\n";
        }
        else{
            cout<<"LOSE\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}