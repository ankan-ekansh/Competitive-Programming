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
    
    string a, b;
    int k, n;
    cin >> n >> k;
    cin >> a;
    b = a;
    for(int i=k;i<n;i++){
        b[i] = b[i-k];
    }
    // cout << b << "\n";
    if(b >= a){
        cout << n << "\n";
        cout << b << "\n";
    }
    else{
        bool found = false;
        for(ll i=k-1;i>=0;i--){
            if(!found && b[i] == '9'){
                // cout << "----\n";
                b[i] = '0';
            }
            else if(!found && b[i] != '9'){
                found = true;
                b[i] = b[i] + 1;
                break;
            }
        }
        for(ll i=k;i<n;i++){
            b[i] = b[i-k];
        }
        cout << n << "\n";
        cout << b << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}