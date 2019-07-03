#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int a,b;
    cin>>a>>b;
    int d=a-b;
    int t=d;
    int n=0;
    while(t>0){
        n++;
        t=t/10;
    }
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=d%10;
        d=d/10;
    }
    for(int i=1;i<9;i++){
        if(arr[n-1]!=i){
            arr[n-1]=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        cout<<arr[i];
    }
    cout<<"\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

