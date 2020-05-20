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
        int u=0, d=0, r=0, l=0, ud=0, rl=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'U'){
                u++;
            }
            if(s[i] == 'D'){
                d++;
            }
            if(s[i] == 'R'){
                r++;
            }
            if(s[i] == 'L'){
                l++;
            }
        }
        ud = min(u, d);
        rl = min(r, l);
        if(ud == 0 && rl == 0){
            cout << "0\n";
        }
        else if(ud == 0 && rl != 0){
            cout << "2\n";
            cout << "RL\n";
        }
        else if(ud != 0 && rl == 0){
            cout << "2\n";
            cout << "UD\n";
        }
        else{
            cout << 2*(ud + rl) << "\n";
            for(int i=0;i<ud;i++){
                cout << "U";
            }
            for(int i=0;i<rl;i++){
                cout << "R";
            }
            for(int i=0;i<ud;i++){
                cout << "D";
            }
            for(int i=0;i<rl;i++){
                cout << "L";
            }
            cout << "\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}