#include<bits/stdc++.h>
using namespace std;
vector<int> adj[6];
vector<bool> vis(10);
void dfs(int v){
    cout<<"v = "<<v<<"\n";
    vis[v]=true;
    for(int u:adj[v]){
        //cout<<"u = "<<u<<"\n";
        if(!vis[u]){
            dfs(u);
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
    cout.tie(NULL);
    int n=6;
    //cin>>n;
    fflush(stdin);
    for(int i=0;i<n;i++){
        vector<int> v;
        char s[100];
        cin.getline(s,100);
        //cout<<"String is "<<s<<"\n";
        for(int j=0;j<strlen(s);j++){
            if(s[j]!=' '){
                int a = (int)s[j]-48;
                v.push_back(a);
            }
        }
        for(auto j=v.begin();j!=v.end();j++){
            //cout<<"Value "<<*j<<" ";
        }
        //cout<<"\n";
        adj[i]=v;
    }
    //for(int i=0;i<5;i++)
        dfs(0);
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
/*              

*/
