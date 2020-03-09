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
    
    int a[101]={0};
    a[1] = 1;
    for(int i=2;i<=100;i++){
        a[i] = (i*i) + a[i-1];
    }
    while(1){
 
        int n;
        cin>>n;
        if(n)
            cout<<a[n]<<"\n";
        else
            break;
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}