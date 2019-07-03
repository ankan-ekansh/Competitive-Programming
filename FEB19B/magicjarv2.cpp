#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input4.txt", "rt", stdin);
        freopen("output4.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t;
    cin>>t;
	while(t--){
    	lli n;
    	cin>>n;
    	lli a[n],max=0;
    	for(lli i=0;i<n;i++){
    		cin>>a[i];
    		if(a[i]>max){
                max=a[i];
            }
    	}
    	lli j=0;
    	bool flag=false;
		for(lli i=0;i<n;i++){
    		if(a[i]==max && flag==false){
    			flag=true;
				j+=max;
   				continue;
  			}
   			j+=a[i]-1;
   		}
   		cout<<j<<"\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
 }