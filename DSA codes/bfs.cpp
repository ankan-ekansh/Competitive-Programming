#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int n,s;
queue<int> q;
int vis[100];
vector<int> d(n),p(n);
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    adj.resize(n);
    char st[100];
    for(int i=0;i<n;i++){
        vector<int> v;
        //cout<<flush;
        cin.getline(st,100);
        if(!(strlen(st)>0)){
            i--;
            continue;
        }
        cout<<"String is "<<st<<" i "<<i<<"\n"<<flush;
        fflush(stdin);
        for(int j=0;j<strlen(st);j++){
            if(st[j]!=' '){
                int a = (int)st[j]-48;
                v.push_back(a);
            }
        }
        for(auto j=v.begin();j!=v.end();j++){
            cout<<"Value "<<*j<<" "<<flush;
        }
        cout<<"\n"<<flush;
        adj[i]=v;
        
        s=0;
        q.push(0);
        vis[s]=true;
        p[s]=-1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int u:adj[v]){
                if(!vis[u]){
                    vis[u]=true;
                    cout<<u<<"\n";
                    q.push(u);
                    d[u]=d[v]+1;
                    p[u]=v;
                }
            }
        }
        

    }
    for(int j=0;j<n;j++){
        for(int k=0;k<adj[j].size();k++){
           cout<<adj[j][k]<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}