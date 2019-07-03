#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input2.txt", "rt", stdin);
        freopen("output2.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){

    	int n;
    	cin>>n;
    	char s[n][210];
    	int ns=0;
    	bool flag=false;
    	int ps[n][123]={0};
    	for(int i=0;i<n;i++){
    		cin>>s[i];
    		for(int j=0;j!=strlen(s[i]);j++){
    			char c = s[i][j];
    			ps[i][c]++;
    		}
    	}
    	//for(int i=0;i<n;i++){
    	//	for(int j=97;j<=122;j++){
    	//		cout<<(char)j<<" "<<ps[i][j]<<" ";
    	//	}
    	//	cout<<"\n";
    	//}
    	for(int i=97;i<=122;i++){
    		flag = false;
    		int occ = 0;
    		for(int j=0;j<n;j++){
    			if(ps[j][i]==0){
    				flag = true;
    				occ=0;
    				break;
    			}
    			else{
    				occ++;
    			}
    		}
    		if(flag==false && occ>0){
    			ns++;
    		}
    		occ=0;
    	}
    	cout<<ns<<"\n";


    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    