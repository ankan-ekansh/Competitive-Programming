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
 
        int n,p;
        cin>>n;
        p=2*n - 2;
        char l[1000000];
        cin>>l;
        char m[1000000];
        int xp=0,yp=0,x=0,y=0,ctr=0;
        if(l[0]=='S'){
            m[ctr++]='E';
            yp++;
            x++;
        }
        else if(l[0]=='E'){
            m[ctr++]='S';
            xp++;
            y++;
        }
        while(ctr<p){
            if(x==n-1 && y==n-1){
                break;
            }
            if(l[ctr]=='E' && yp==y){
                m[ctr++]='S';
                xp++;
                y++;
            }
            else if(l[ctr]=='S' && xp==x){
                m[ctr++]='E';
                yp++;
                x++;
            }
            else if(l[ctr]=='E' && yp!=y){
                m[ctr++]='E';
                xp++;
                x++;
            }
            else if(l[ctr]=='S' && xp!=x){
                m[ctr++]='S';
                yp++;
                y++;
            }
        }
        cout<<"Case #"<<++cn<<": "<<m<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}