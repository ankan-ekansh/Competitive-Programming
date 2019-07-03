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

    long long n;
    cin>>n;
    if(n <= 1){
        return 0;
    }
    if(ceil(log2(n)) == floor(log2(n))){
        cout<<"TAK\n";
    }
    else{
        cout<<"NIE\n";
    }
    // if(__builtin_popcount(n) == 1){
    //     cout<<"TAK\n";
    // }
    // else{
    //     cout<<"NIE\n";
    // }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}