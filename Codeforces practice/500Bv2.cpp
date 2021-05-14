/*
    Stay motivated and keep working hard
*/
// Logic: Floyd Warshall to get routes from one node to another via intermediate node, then greedily swap arr[i], arr[j] if arr[i] > arr[j]
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int arr[307];
char mat[307][307];
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
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][k] == '1' && mat[k][j] == '1'){
                    mat[i][j] = '1';
                }
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(mat[i][j] == '1'){
                if(arr[j] < arr[i]){
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}