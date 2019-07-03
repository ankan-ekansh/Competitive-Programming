#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    //ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){

    	float a1,a2,b1,b2,c1,c2;
    	cin>>a1>>b1>>c1>>a2>>b2>>c2;
    	a1=(float)a1/(float)b1;
    	c1=(float)c1/(float)b1;
    	a2=(float)a2/(float)b2;
    	c2=(float)c2/(float)b2;
    	float dist = c1-c2;
    	printf("%0.6f\n",dist);

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    