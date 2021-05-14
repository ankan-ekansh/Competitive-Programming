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
    int t;
    cin>>t;
    while(t--){
        
        string t;
        cin >> t;
        int ones = 0, zeroes = 0;
        for(int i=0;i<t.length();i++){
            if(t[i] == '0'){
                zeroes++;
            }
            else{
                ones++;
            }
        }
        if(ones == 0 || zeroes == 0){
            // period will be 1
            cout << t << "\n";
        }
        else{
            // period will be 2
            int count = max(ones, zeroes);
            for(int i=0;i<2*count && i < t.length();i++){
                cout << "10";
            }
            cout << "\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}