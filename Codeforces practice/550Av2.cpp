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

    string s;
    cin >> s;
    size_t f = s.find("AB");
    size_t g;
    bool flag = false;
    // while(f != string::npos){
    //     g = s.find("BA", f+1);
    //     if(g != string::npos){
    //         flag = true;
    //         break;
    //     }
    //     f = s.find("AB",f+1);
    // }
    if(f != string::npos){
        g = s.find("BA",f+2);
        if(g != string::npos){
            flag = true;
            // break;
        }
    }
    // cout << f << " " << g << "\n";
    f = s.find("BA");
    if(f != string::npos){
        g = s.find("AB",f+2);
        if(g != string::npos){
            flag = true;
            // break;
        }
    }
    // cout << f << " " << g << "\n";
    if(flag){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}