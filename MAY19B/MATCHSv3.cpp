/* 
    Partial Correct Solution
*/

#include<bits/stdc++.h>
using namespace std;
int64_t c;
void next_turn(){
    c=1-c;
}
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
        if(n<m){
            swap(n,m);
        }
        if(n%m == 0){
            cout<<"Ari\n";
            continue;
        }
        else{
            c=0;
            while(n>0 && m>0){
                if(n<m){
                    swap(n,m);
                }
                double r = (double)n/(double)m;
                if(r-2>=0 && n%m!=0){
                    next_turn();
                    n = n - (r-1)*m;
                }
                else if(r-2>=0 && n%m==0){
                    break;
                }
                else{
                    n=n%m;
                    next_turn();
                }
            }
        }
        if(c==0){
            cout<<"Ari\n";
        }
        else{
            cout<<"Rich\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}