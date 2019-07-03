#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int pos;
        for(int i=0;i<n;i++){
            if(a[i]==1)
                pos=i;
            if(a[i+1]!=1)
                break;
        }
        int sum=pos+1;
        int sumsq=pos+1;
        int c=k;
        for(int i=pos;i<n;i++){
            if(c>=0){
                a[i]=1;
                sum+=1;
                sumsq+=1;
                c--;
            }
            else{
                sum+=a[i];
                sumsq+=(a[i]*a[i]);
            }
        }
        if(sum==sumsq)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }


    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
