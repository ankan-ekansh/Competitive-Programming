#include<bits/stdc++.h>
using namespace std;
int a[507][507];
bool vis[507][507];
int n, m;
int c, min_c;
int curr_max;
int ipos, jpos;
int dfs(int i, int j){
    if((i >= m) || (j >= n)){
        return;
    }
    if((i < 0) || (j < 0)){
        return;
    }
    if((i == ipos) && (j == jpos)){
        min_c = min(c, min_c);
        return -1;
    }
    if(a[i][j] > curr_max){
        c++;
    }
    c = dfs(i-1,j);

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
 
        //int n, m;
        cin>>n>>m;
        //int a[n][m];
        //bool vis[n][m]={false};
        int ma = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                if(a[i][j] > ma){
                    ma = a[i][j];
                    ipos = i;
                    jpos = j;
                }
            }
        }
        curr_max = a[0][0];
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}