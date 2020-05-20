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

    string a, b;
    cin >> a >> b;
    int fa[27], fb[27];
    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));
    for(int i=0;i<a.length();i++){
        fa[a[i] - 'a']++;
        fb[b[i] - 'a']++;
    }
    for(int i=0;i<=25;i++){
        if(fa[i] != fb[i]){
            cout << "-1\n";
            exit(0);
        }
    }
    string c = a + a;
    size_t found = c.find(b);
    if(found != string::npos){
        //cout << c << " " << b << "\n";
        //cout << found << "\n";
        cout << min(found, (c.length()/2) - found) << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}