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
    
    string s,t;
    cin >> s >> t;
    int n = s.length();
    string z = t;
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            z[i] = (char)('a' + j);
            if(z > s && z < t){
                flag = true;
                break;
            }
            // z[i] = s[i];
            z[i] = t[i];
        }
        if(flag){
            break;
        }
    }
    if(flag){
        cout << z << "\n";
    }
    else{
        z = s;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                z[i] = (char)('a' + j);
                if(z > s && z < t){
                    flag = true;
                    break;
                }
                // z[i] = s[i];
                z[i] = s[i];
            }
            if(flag){
                break;
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