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
    
    ll n;
    cin >> n;
    ll sa = 0, sg = 0;
    string s = "";
    bool flag = true;
    for(ll i=0;i<n;i++){
        ll pa, pg;
        cin >> pa >> pg;
        if(abs(pa + sa - sg) <= 500){
            sa = sa + pa;
            s.push_back('A');
        }
        else if(abs(pg + sg - sa) <= 500){
            sg = sg + pg;
            s.push_back('G');
        }
        else{
            flag = false;
            break;
        }
    }
    if(flag){
        cout << s << "\n";
    }
    else{
        cout << "-1\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}