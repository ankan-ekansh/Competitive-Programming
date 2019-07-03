#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[50][50];
void asgn(int n,int m){
    int c = 0,ch = 0,pos = 0;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            /*c=0;
            c++;
            if(i-1 >= 0 && a[i-1][j]==0){
                a[i-1][j]=c;
            }
            c++;
            if(j+1 < m && a[i][j+1]==0){
                a[i][j+1]=c;
            }
            c++;
            if(i+1 < n && a[i+1][j]==0){
                a[i+1][j]=c;
            }
            c++;
            if(j-1 >= 0 && a[i][j-1]==0){
                a[i][j-1]=c;
            }
            */
            if(i%2==0){
                if()
            }
            if(i%2!=0){
                ch=1;
            }


        }
    }

}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){

        int n,m;
        cin>>n>>m;
//        int a[n][m]={0};
        asgn(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
                a[i][j]=0;
            }
            cout<<endl;
        }
        cout<<endl;

    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

