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
        
        ll n;
        cin >> n;
        if(n == 1){
            cout << "0\n";
            continue;
        }
        if(n % 3 != 0){
            cout << "-1\n";
        }
        else{
            ll three = 0, two = 0;
            ll tmp = n;
            while(tmp % 3 == 0){
                three++;
                tmp /= 3;
            }
            // tmp = n;
            while(tmp % 2 == 0){
                two++;
                tmp /= 2;
            }
            if(tmp > 1){
                cout << "-1\n";
                continue;
            }
            if(three < two){
                cout << "-1\n";
                continue;
            }
            // cout << three << " " << two << "\n";
            cout << three + (three - two) << "\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}