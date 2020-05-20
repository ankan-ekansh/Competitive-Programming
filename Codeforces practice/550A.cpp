#include<bits/stdc++.h>
using namespace std;
pair<int, int> fun(string s, int pos, int m){
    if(m == 0){
        for(int i=pos+1;i<s.length();i++){
            if(s[i-1] == 'A' && s[i] == 'B'){
                return make_pair(i-1,i);
            }
        }
    }
    else{
        for(int i=pos+1;i<s.length();i++){
            if(s[i-1] == 'B' && s[i] == 'A'){
                return make_pair(i-1, i);
            }
        }
    }
    return make_pair(-1,-1);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    pair<int, int> a = make_pair(-1,-1), b = make_pair(-1,-1);

    a = fun(s, 0, 0);
    if(a.first == -1 || a.second == -1){
        cout << "NO\n";
    }
    else{
        b = fun(s, a.second+1, 1);
        if(b.first == -1 || b.second == -1){
            b = fun(s, 0, 1);
            cout << a.first << " " << a.second << ", " << b.first << " " << b.second << "\n";
            if((b.second < a.first) && (b.first != -1 && b.second != -1)){
                //  cout << a.first << " " << a.second << ", " << b.first << " " << b.second << "\n";
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "YES\n";
        }
    }


    // a = fun(s, 0, 0);
    // b = fun(s, s.length()-1, 1);
    // cout << a.first << " " << a.second << "\n";
    // cout << b.first << " " << b.second << "\n";

    // if(a.first == -1 || b.first == -1 || a.second == -1 || b.second == -1 || a.second == b.first || a.first == b.second){
    //     cout << "NO\n";
    // }
    // else{
    //     cout << "YES\n";
    // }

    

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}