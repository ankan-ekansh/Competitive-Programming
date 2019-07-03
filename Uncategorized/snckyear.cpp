#include<bits/stdc++.h>
using namespace std;
int main(){
 /*   #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
	#endif
	*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        int y;
        cin>>y;
        if(y==2010 || y==2015 || y==2016 || y==2017 || y==2019)
            cout<<"HOSTED"<<"\n";
        else
            cout<<"NOT HOSTED"<<"\n";

    }


/*    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    */
    return 0;
}
