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

    int64_t n;
    cin>>n;
    int64_t d[n+3];
    for(int64_t i=1;i<=n;i++){
        cin>>d[i];
    }
    int64_t d1=0,d2=0;
    int64_t s,e;
    cin>>s>>e;
    for(int64_t i=s;i!=e;i++){
        if(i>n){
            i = i%n;
        }
        if(i==e){
            //d1+=d[i];
            break;
        }
        d1+=d[i];
        cout<<d1<<"\n";
    }
    for(int64_t i=e;i!=s;i++){
        if(i>n){
            i=i%n;
        }
        if(i==s){
            break;
        }
        d2+=d[i];
        cout<<d2<<"\n";
    }
    cout<<d1<<" "<<d2<<"\n";
    cout<<min(d1,d2)<<"\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}