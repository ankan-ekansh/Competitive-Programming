#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> a;
    a.resize(n);
    vector<int> b(2,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    int k=0;
    for(int i=0;i<n;i++){
        if(b[0]==0 || b[1]==0){
            break;
        }
        else{
            b[a[i]]--;
            k++;
        }
    }
    cout<<k<<"\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}