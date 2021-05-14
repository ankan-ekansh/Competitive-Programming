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
    
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll tot = 0, dots = 0;
    bool flag = false;
    for(ll i=0;i<n;i++){
        if(s[i] == '.'){
            tot++;
        }
        if(s[i] == '.' && !flag){   // start of .
            flag = true;
            dots++;
        }
        else if(s[i] == '.' && flag){   // middle of .
            continue;
        }
        else if(s[i] != '.'){   // end + 1 of .
            flag = false;
        }
    }
    for(ll i=0;i<m;i++){
        ll p;
        char c;
        cin >> p >> c;
        p--;
        if(p == 0){
            if(c == '.' && s[p] == '.'){
                s[p] = c;
                cout << tot - dots << "\n";
                continue;
            }
            else if(c != '.' && s[p] != '.'){
                s[p] = c;
                cout << tot - dots << "\n";
                continue;
            }
            else if(c == '.' && s[p] != '.'){
                tot++;
                if(s[p+1] == '.'){
                    s[p] = c;
                    cout << tot - dots << "\n";
                    continue;
                }
                else{
                    dots++;
                }
            }
            else{
                tot--;
                if(s[p+1] == '.'){
                    s[p] = c;
                    cout << tot - dots << "\n";
                    continue;
                }
                else{
                    dots--;
                }
            }
        }
        else if(p == n-1){
            if(c == '.' && s[p] == '.'){
                s[p] = c;
                cout << tot - dots << "\n";
                continue;
            }
            else if(c != '.' && s[p] != '.'){
                s[p] = c;
                cout << tot - dots << "\n";
                continue;
            }
            else if(c == '.' && s[p] != '.'){
                tot++;
                if(s[p-1] == '.'){
                    s[p] = c;
                    cout << tot - dots << "\n";
                    continue;
                }
                else{
                    dots++;
                }
            }
            else{
                tot--;
                if(s[p-1] == '.'){
                    s[p] = c;
                    cout << tot - dots << "\n";
                    continue;
                }
                else{
                    dots--;
                }
            }
        }
        else{
            if(c == '.' && s[p] == '.'){
                s[p] = c;
                cout << tot - dots << "\n";
                continue;
            }
            else if(c != '.' && s[p] != '.'){
                s[p] = c;
                cout << tot - dots << "\n";
                continue;
            }
            else if(c == '.' && s[p] != '.'){
                tot++;
                if(s[p-1] == '.' && s[p+1] == '.'){
                    dots--;
                }
                else if(s[p-1] != '.' && s[p+1] != '.'){
                    dots++;
                }
                else{
                    s[p] = c;
                    cout << tot - dots << "\n";
                    continue;
                }
            }
            else{
                tot--;
                if(s[p-1] == '.' && s[p+1] == '.'){
                    dots++;
                }
                else if(s[p-1] != '.' && s[p+1] != '.'){
                    dots--;
                }
                else{
                    s[p] = c;
                    cout << tot - dots << "\n";
                    continue;
                }
            }
        }
        s[p] = c;
        cout << tot - dots << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}