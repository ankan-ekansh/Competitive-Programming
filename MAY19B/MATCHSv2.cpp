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
    int t;
    cin>>t;
    while(t--){
 
        int64_t n,m;
        cin>>n>>m;
        int64_t c = 0;
        if(m>n){
            swap(n,m);
        }
        if(n/m >= 2){
            cout<<"Ari\n";
            continue;
        }
        else if(n == m){
            cout<<"Ari\n";
            continue;
        }
        else{
            while(n*m !=0){
                if(n<m){
                    swap(n,m);
                }
                n=n%m;
                c++;
            }
        }
        if(c%2 == 0){
            cout<<"Rich\n";
        }
        else{
            cout<<"Ari\n";
        }
    }
 
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}