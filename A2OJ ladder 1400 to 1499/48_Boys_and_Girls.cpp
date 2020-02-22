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
    
    int m, n;
    // cin >> n >> m;
    ifstream is("input.txt");
    int x;
    is >> x;
    n = x;
    is >> x;
    m = x;
    ofstream f;
    f.open("output.txt");
    int a = n, b = m;
    if(a > b){
        while(b){
            f << "BG";
            b--;
            a--;
        }
        while(a){
            f << "B";
            a--;
        }
    }
    else{
        while(a){
            f << "GB";
            b--;
            a--;
        }
        while(b){
            f << "G";
            b--;
        }
    }
    // cout << s << "\n";
    f.close();
    is.close();

    // #ifndef ONLINE_JUDGE
    //     cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}