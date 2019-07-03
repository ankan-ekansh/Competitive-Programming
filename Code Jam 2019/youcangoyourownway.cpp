#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "rt", stdin);
        freopen("output2.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int cn = 0;
    while(t--){
 
        int64_t n,p;
        cin>>n;
        p=(2*n)-2;
        char l[1000000]={0};
        cin>>l;
        char m[1000000]={0};
        int64_t x=0,y=0,ctr=0;      //x means horizontal, y means vertical pos
        for(int i=0;i<p;i++){
            if(l[i]=='S'){
                m[i]='E';
                x++;
                continue;
            }
            else if(l[i]=='E'){
                m[i]='S';
                y++;
                continue;
            }
            if(x==n-1 && y==n-1){
                 break;
            }
        }
        cout<<"Case #"<<++cn<<": "<<m<<"\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}