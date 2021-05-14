#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> cases;
unordered_map<int, int> dist, vis;
int cnt;
int di[] = {1, 0};
int dj[] = {0, 1};
vector<vector<int>> mat(3, vector<int>(3));
int power(int a, int b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a;
    }
    else{
        int x = power(a, b/2);
        if(b % 2 == 0){
            return x*x;
        }
        else{
            return x*a*x;
        }
    }
}
int matToState(){
    int state = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            state = state*10 + mat[i][j];
        }
    }
    return state;
}
int getPositionfromRowCol(int i, int j){
    return 3*i + j;
}
int getElement(int state, int pos){
    int j;
    j = state;
    j /= power(10, pos);
    return j%10;
}
int setElement(int state, int pos, int element){
    int newState = 0;
    int tmp1, tmp2;
    tmp1 = state;
    tmp2 = tmp1 % power(10, pos);
    newState = tmp2 + element * power(10, pos);
    tmp1 /= power(10, pos+1);
    tmp1 *= power(10, pos+1);
    newState += tmp1;
    return newState;
}
bool isPrime(int element){
    if(element == 2 || element == 3 || element == 5 || element == 7 || element == 11 || element == 13 || element == 17 || element == 19){
        return true;
    }
    return false;
}
int interchange(int state, int pos1, int pos2){
    int element1 = getElement(state, pos1);
    int element2 = getElement(state, pos2);
    int newState = 0;
    newState = setElement(state, pos1, element2);
    newState = setElement(newState, pos2, element1);
    return newState;
}
void solve(){
    queue<pair<int, int>> q;
    vis.clear();
    int startState = 123456789;
    q.push({startState, 0});
    while(!q.empty()){
        pair<int, int> currentState = q.front();
        // cout << currentState.first << " " << currentState.second << "\n";
        q.pop();
        dist[currentState.first] = currentState.second;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<2;k++){
                    int newi = i + di[k];
                    int newj = j + dj[k];
                    if(newi >= 3 || newj >= 3){
                        continue;
                    }
                    int element1 = getElement(currentState.first, getPositionfromRowCol(i, j));
                    int element2 = getElement(currentState.first, getPositionfromRowCol(newi, newj));
                    if(!isPrime(element1+element2)){
                        continue;
                    }
                    int newState = interchange(currentState.first, getPositionfromRowCol(i, j), getPositionfromRowCol(newi, newj));
                    if(vis[newState] != 0){
                        continue;
                    }
                    vis[newState] = 1;
                    q.push({newState, currentState.second + 1});
                }
            }
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
    int t;
    cin>>t;
    while(t--){
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin >> mat[i][j];
            }
        }
        int state = matToState();
        // cout << state << "\n";
        cases.push_back(state);
        dist[state] = -1;
        
    }
    solve();
    for(int i=0;i<cases.size();i++){
        cout << dist[cases[i]] << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}