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

    	int64_t n;
    	cin>>n;
    	int64_t c=0;
    	int64_t w=-1;
    	while(n!=1){
    			int64_t sr = sqrt(n);
    			if(sr * sr == n){
    				n=sr;
    				if(n==1 && c%2==0){
    					w=1;
    					break;
    				}
    				else if(n==1 && c%2!=0){
    					w=2;
    					break;
    				}
    				c++;
    				continue;
    			}
    			else{
    				n=n-1;
    				if(n==1 && c%2==0){
    					w=1;
    					break;
    				}
    				else if(n==1 && c%2!=0){
    					w=2;
    					break;
    				}
    				c++;
    				continue;
    			}
    	}
    	if(w==1){
    		cout<<"GANDEY\n";
    	}
    	else if(w==2){
    		cout<<"GHATAK\n";
    	}
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    