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
    int a[n],b[n];
    cin>>a[0]>>b[0];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[i]=a[i-1]+x;
        b[i]=b[i-1]+y;
    }
    for(int i=0;i<n;i++){
        
    }
    int lead=0,leader;
    for(int i=0;i<n;i++){
        //cout<<a[i]<<" "<<b[i];
        if(a[i]<b[i]){
            if(b[i]-a[i] > lead){
                lead = b[i]-a[i];
                leader = 2;
            }
        }
        else if(a[i]>b[i]){
            if(a[i]-b[i] > lead){
                lead = a[i]-b[i];
                leader = 1;
            }
        }
        //cout<<" "<<lead<<" "<<leader<<"\n";
    }
    cout<<leader<<" "<<lead<<"\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}