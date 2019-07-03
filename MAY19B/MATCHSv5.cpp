#include<bits/stdc++.h>
using namespace std;
int64_t c;
void next_turn(){
    c=1-c;
}
int64_t possible(int64_t n,int64_t m){
    long double r = (long double)n/(long double)m;
    return (int64_t)r;
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
        //cout<<n<<" "<<m<<"\n";
        if(n<m){
            swap(n,m);
        }
        if(n%m==0){
            cout<<"Ari\n";
            continue;
        }
        else{
            c=0;
            bool flag = false;
            while(n>0 && m>0){
                if(n<m){
                    swap(n,m);
                }
                int64_t r = possible(n,m);
                if(r>=2 && c==0){
                    cout<<"Ari\n";
                    flag = true;
                    break;
                }
                else if(r>=2 && c==1){
                    cout<<"Rich\n";
                    flag = true;
                    break;
                }
                else{
                    n=n%m;
                    next_turn();
                }
            }
            if(c==0 && flag == false){
                cout<<"Ari\n";
            }
            else if(c==1 && flag == false){
                cout<<"Rich\n";
            }
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}