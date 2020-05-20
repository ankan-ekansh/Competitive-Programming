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

    string p, q;
    cin >> p;
    cin >> q;
    bool flag = true;
    for(int i=0;i<p.length()-1;i++){
        if(p[i] == q[i] && p[i+1] == q[i+1]){
            continue;
        }
        if(p[i] != q[i] && p[i+1] == q[i+1]){
            if(p[i] == '0' && p[i+1] == '0' && q[i] == '1'){
                flag = false;
                break;
            }
            else if(p[i] == '0' && p[i+1] == '1' && q[i] == '1'){
                p[i] = '1';
                p[i+1] = '1';
                continue;
            }
            else if(p[i] == '1' && p[i+1] == '0' && q[i] == '0'){
                flag = false;
                break;
            }
            else if(p[i] == '1' && p[i+1] == '1' && q[i] == '0'){
                p[i] = '0';
                p[i+1] = '1';
            }
        }
        if(p[i] == q[i] && p[i+1] != q[i+1]){
            if(p[i] == '0' && p[i+1] == '0' && q[i+1] == '1'){
                // flag = false;
                // break;
                continue;
            }
            else if(p[i] == '1' && p[i+1] == '0' && q[i+1] == '1'){
                p[i] = '1';
                p[i+1] = '1';
                continue;
            }
            else if(p[i] == '0' && p[i+1] == '1' && q[i+1] == '0'){
                // flag = false;
                // break;
                continue;
            }
            else if(p[i] == '1' && p[i+1] == '1' && q[i+1] == '0'){
                p[i] = '1';
                p[i+1] = '0';
            }
        }
        if(p[i] != q[i] && p[i+1] != q[i+1]){
            if(p[i] == '0' && p[i+1] == '0' && q[i] == '1' && q[i+1] == '1'){
                flag = false;
                break;
            }
            else if(p[i] == '0' && p[i+1] == '1' && q[i] == '1' && q[i+1] == '0'){
                // p[i] = '1';
                // p[i+1] = '1';
                // continue;
                flag = false;
                break;
            }
            else if(p[i] == '1' && p[i+1] == '0' && q[i] == '0' && q[i+1] == '1'){
                flag = false;
                break;
            }
            else if(p[i] == '1' && p[i+1] == '1' && q[i] == '0' && q[i+1] == '0'){
                p[i] = '0';
                p[i+1] = '1';
                continue;
            }
        }
    }
        cout << p << "\n" << q << "\n";
        if(flag && (p == q)){
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