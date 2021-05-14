/*
    Stay motivated and keep working hard
*/
// Logic : DSU according to matrix entries, then store all representatives as a set
// and find all reachable nodes from it, sort in increasing order
// and keep track of index order for every representative of a connected componenet
#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 307;
int par[N];
int n;
int arr[N];
char mat[N][N];
void init(){
    for(int i=0;i<N;i++){
        par[i] = i;
    }
}
int root(int a){
    while(a != par[a]){
        a = par[a];
        // par[a] = par[par[a]];
    }
    return a;
}
void dsu(int a, int b){
    int pa = root(a);
    int pb = root(b);
    if(pa != pb){
        par[pb] = pa;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    init();
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            mat[i][j] = s[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == '1'){
                if(root(i) != root(j)){
                    dsu(i, j);
                }
            }
        }
    }
    int ppar[N];
    set<int> repr;
    for(int i=0;i<n;i++){
        // cout << i << " " << root(i) << "\n";
        ppar[i] = root(i);
        repr.insert(ppar[i]);
    }
    vector<int> idx, ele;
    for(auto represent : repr){
        for(int i=0;i<n;i++){
            if(represent == ppar[i]){
                idx.push_back(i);
                ele.push_back(arr[i]);
            }
        }
        sort(all(ele));
        for(int i=0;i<idx.size();i++){
            arr[idx[i]] = ele[i];
        }
        idx.clear();
        ele.clear();
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}