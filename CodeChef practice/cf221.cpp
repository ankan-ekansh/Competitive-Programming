#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t a,b,n,t;
    cin>>a>>b>>n;
    int64_t days = 0;
    for(t=0;t<n;){
    	t+=a;
    	if(t>=n){
    		days++;
    		break;
    	}
    	t-=b;
    	days++;
    }
    cout<<days<<endl;

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


