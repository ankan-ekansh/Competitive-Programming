/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n % 2){
        cout << ":(\n";
        return 0;
    }
    int o,c;
    o = c = n/2;
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            o--;
        }
        if(s[i] == ')'){
            c--;
        }
    }
    int res = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '?' && o > 0){
            s[i] = '(';
            o--;
        }
        if(s[i] == '?' && c > 0){
            s[i] = ')';
            c--;
        }
        res = res + ((s[i] == ')') ? -1 : (s[i] == '(') ? +1 : 0);
        if(res <= 0 && i != n-1){
            res = 1;
            break;
        }
    }
    if(!res){
        cout << s << "\n";
    }
    else{
        cout << ":(\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}