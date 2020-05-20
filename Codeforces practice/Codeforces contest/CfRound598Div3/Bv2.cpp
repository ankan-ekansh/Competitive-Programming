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
    int t;
    cin>>t;
    while(t--){
 
        int n;
        cin >> n;
        int a[n+1], b[n+1];
        memset(b, 0, sizeof(b));
        map<int, int> m;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            m[a[i]] = i;
        }
        int i=1, swaps = n-1;
        while(i<n && swaps > 0){
            if(m[i] != i){
                for(int j=m[i]-1;j>=i && swaps > 0;j--){
                    if(!b[j]){
                        swap(a[j], a[j+1]);
                        m[a[j+1]]--;
                        m[a[j]]++;
                        swaps--;
                        b[j] = 1;
                    }
                    else{
                        break;
                    }
                }
            }
            i++;
        }
        for(int i=1;i<=n;i++){
            cout << a[i] << " ";
        }
        cout << "\n";
        
 
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}