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

    	int q;
    	cin>>q;
    	int n;
    	cin>>n;
    	int a[n][n];
    	if(q==2){
    		
    		int s1,s2;
    		int k=1;
    		s1=0,s2=2*(n-1);
    		int c=0;
    		while(s1<=s2){
    			for(int i=0;i<n;i++){
    				for(int j=0;j<n;j++){
    					if(i+j == s1 && c%2==0){
    						a[i][j]=k++;
    					}
    					else if(i+j == s2 && c%2!=0){
    						a[i][j]=k++;
    					}
    				}
    			}
    			if(c%2==0){
    				s1++;
    				c++;
    			}
    			else{
    				s2--;
    				c++;
    			}
    		}
    	}
    	else if(q==1){
    		
    	}
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			cout<<a[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    