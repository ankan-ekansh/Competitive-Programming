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

    int n;
    cin >> n;
    map<string,int> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(m[s] == 0){
            m[s]++;
            cout << "OK\n";
        }
        else{
            string temp = s;
            s = s + to_string(m[s]);
            m[temp]++;
            cout << s << "\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}