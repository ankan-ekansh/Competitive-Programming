#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    sort(a,a+n);
    //1 3 3 5 7 10 20
    if(k==0){
    	cout<<"-1\n";
    	exit(0);
    }
    if(a[k-1]!=a[k]){
    	cout<<a[k-1]<<endl;
    }
    else{
    	cout<<"-1\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    