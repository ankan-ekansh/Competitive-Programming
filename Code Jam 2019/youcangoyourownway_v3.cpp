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
    while(t--){
 
        int n,p;
        cin>>n;
        p= 2*n - 2;
        char l[1000000];
        char m[1000000];
        cin>>l;
        int xp=0,yp=0,x=0,y=0;
        for(int i=0;i<p;i++){
            if(x==n-1 && y==n-1){
                break;
            }
            if(l[i]=='S'){
                yp++;
                if((x+1) != xp && y!=yp && x+1<n){
                    x++;
                    m[i]='E';
                    continue;
                }
                else if(x!=xp && (y+1)!=yp && y+1<n){
                    y++;
                    m[i]='S';
                    continue;
                }
            }
            else if(l[i]=='E'){
                xp++;
                if((x+1) != xp && y!=yp && x+1<n){
                    
                }
            }
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}