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
        cin>>n;
        int m[50007]={0};
        int a[n];
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=x;
            m[x]++;
        }
        long sum = 0;
        sort(a,a+n);

        long b[50007];
        b[0]=0;
        for(int i=1;i<=50000;i++){
            b[i]=b[i-1]+m[i];
        }
        for(int i=1;i<=50000;i++){
            sum+=(m[i] * b[i]);
        }

        cout<<sum<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}