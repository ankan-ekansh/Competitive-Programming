#include<bits/stdc++.h>
using namespace std;
bool comp(int a, int b){
    cout<<a<<" "<<b<<"\n";
    return a>b;
}
int main(){
    /*#ifndef ONLINE_JUDGE
        freopen("i.txt", "rt", stdin);
        freopen("o.txt", "wt", stdout);
	#endif*/

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    sort(a,a+5,comp);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }



    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
