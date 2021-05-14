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
    

    string s, t;
    cin >> s >> t;
    string z = s;
    int n = s.length();
    bool eq = true;
    bool flag = true;
    for(int i=0;i<n;i++){
        if(eq && s[i] != t[i]){
            eq = false;
            if((t[i] - s[i]) >= 2){
                z[i] = (char)(s[i]+1);
            }
            else{
                flag = false;
                break;
            }
        }
        else{
            if(eq && s[i] == t[i]){
                z[i] = s[i];
                continue;
            }
            else if(!eq){
                z[i] = s[i];
            }
        }
    }
    if(flag)
        cout << z << "\n";
    else{
        // cout << "No such string\n";
        z = t;
        eq = true;
        flag = true;
        for(int i=0;i<n;i++){
            if(eq && s[i] != t[i]){
                eq = false;
                if((t[i] - s[i]) >= 2){
                    z[i] = (char)(t[i]-1);
                }
                else{
                    flag = false;
                    break;
                }
            }
            else{
                if(eq && s[i] == t[i]){
                    z[i] = t[i];
                    continue;
                }
                else if(!eq){
                    z[i] = t[i];
                }
            }
        }
        if(flag){
            cout << z << "\n";
        }
        else{
            cout << "No such string\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}