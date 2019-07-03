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

    	int n;
    	cin>>n;
    	bool pr[n+1];
    	memset(pr,true,sizeof(pr));
    	for(int i=2;i*i<=n;i++){
    		if(pr[i]==true){
    			for(int j=i*i;j<=n;j+=i){
    				pr[j]=false;
    			}
    		}
    	}
    	vector<int> p,sp;
    	for(int i=2;i<=n;i++){
    		if(pr[i]==true){
    			//cout<<i<<" ";
    			p.push_back(i);
    		}
    	}
    	//cout<<endl;
    	for(int i=0;i<p.size();i++){
    		for(int j=i+1;j<p.size();j++){
    			sp.push_back(p[i]*p[j]);
    		}
    	}
    	//cout<<sp.size()<<endl;
    	//for(int i=0;i<sp.size();i++){
    	//	cout<<sp[i]<<" ";
    	//}
    	//cout<<endl;
    	int flag = -1;
    	for(int i=0;i<sp.size();i++){
    		for(int j=i;j<sp.size();j++){
    			if(n==(sp[i]+sp[j])){
    				//cout<<sp[i]<<"+"<<sp[j]<<"="<<n<<endl;
    				flag=0;
    				break;
    			}

    		}
    		if(flag==0){
    			break;
    		}
    	}
    	if((flag==0)){
    		cout<<"YES\n";
    	}
    	else{
    		cout<<"NO\n";
    	}
    	


    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    