/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int find_changes(int currentState[3], int goalState[3]){
    int res = 0;
    for(int i=0;i<3;i++){
        res += abs(currentState[i] - goalState[i]);
    }
    return res/2;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int currentState[3] = {0}, goalState[3] = {n/3, n/3, n/3};
    for(int i=0;i<n;i++){
        currentState[s[i]-'0']++;
    }
    int initialChanges = find_changes(currentState, goalState);
    int currentChanges = 0;
    for(int i=0;i<n;i++){
        currentState[s[i]-'0']--;
        for(int j=0;j<3;j++){
            if(!goalState[j]){
                continue;
            }
            int change = (j != (s[i] - '0'));
            goalState[j]--;
            if(currentChanges + change + find_changes(currentState, goalState) == initialChanges){
                s[i] = j + '0';
                currentChanges += change;
                break;
            }
            goalState[j]++;
        }
    }
    cout << s << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}