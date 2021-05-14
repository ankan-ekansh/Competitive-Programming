#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
vector<ll> adjacencyList[100007];   // array of vectors :- every node's neighbours are stored in a vector
vector<ll> visited(100007);
// like for example 
/*
            1
          /  \
        /     \
      /        \    
    2           3
  /   \       /   \
4       5   6       7   
adjacencyList[1] - [2, 3]
adjacencyList[2] - [1, 4, 4]
adjacencyList[3] - [1, 6, 7]
adjacencyList[4] - [2]
adjacencyList[5] - [2]
adjacencyList[6] - [3]
adjacencyList[7] - [3]
*/
// One method for dfs (in trees)
void dfs1(ll currentNode, ll parentNode = -1){
    cout << currentNode << "\n";
    for(ll nextNode : adjacencyList[currentNode]){
        if(nextNode == parentNode){     // since adjacency list of a node also includes its parent, if we keep track of current node's parent at each recursion, we can avoid infinite loop
            continue;
        }
        dfs1(nextNode, currentNode);
    }
}
// Another method for dfs (in trees and graph with visited array)
void dfs2(ll currentNode){
    visited[currentNode] = true;    // mark current node as visited
    cout << currentNode << "\n";
    for(ll nextNode : adjacencyList[currentNode]){
        if(!visited[nextNode]){
            dfs2(nextNode);
        }
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

    cin >> n >> m;  // n nodes, m edges
    for(ll i=0;i<m;i++){
        ll u, v;
        cin >> u >> v;
        // for undirected graph
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);

        // for directed graph, ie we can go from u -> v only
        // adjacencyList[u].push_back(v);
    }
    // suppose tree is rooted at 1
    // then dfs from 1 will be
    dfs1(1);

    cout << "\n";
    // dfs using visited array
    dfs2(1);

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}