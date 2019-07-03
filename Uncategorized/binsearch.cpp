#include<bits/stdc++.h>
using namespace std;
int a[100000];
int n;
int binsearch(int x){
    int low=0, high=n-1;
    int result = -1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==x){
            result=mid;
            high=mid-1;
        }
        if(a[mid]<x)
            low=mid+1;
        else if(a[mid]>x)
            high=mid-1;
    }
    return result;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "rt", stdin);
        freopen("o.txt", "wt", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        int q;
        cin>>n>>q;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<q;i++){
            int x;
            cin>>x;
            int result=binsearch(x);
            cout<<result<<"\n";
        }





    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
