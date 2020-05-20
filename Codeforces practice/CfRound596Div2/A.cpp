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

    int da, db;
    cin >> da >> db;
    if(da == db){
        cout << da << 0 << " " << db << 1; 
    }
    else if(db - 1 == da){
        cout << da << 9 << " " << db << 0;
    }
    else{
        if(da == 9 && db == 1){
            cout << "9 10\n";
        }
        else
            cout << "-1\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}