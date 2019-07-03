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

    	int n,k;
    	cin>>n>>k;
    	map<int,int> kr,kc;
    	for(int i=0;i<k;i++){
    		int tr,tc;
    		cin>>tr>>tc;
    		kr.insert(pair<int,int>(tr,i));
    		kc.insert(pair<int,int>(tc,i));
    	}
    	vector<int> vr,vc;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			if(kr.find(i)!=kr.end()){
    				break;
    			}
    			else if(kc.find(j)!=kc.end()){
    				continue;
    			}
    			else
    			{
    				vr.push_back(i);
    				kr.insert(pair<int,int>(i,0));
    				vc.push_back(j);
    				kc.insert(pair<int,int>(j,0));
    			}
    		}
    	}
    	int s = vr.size();
    	cout<<s<<" ";
    	for(int i=0;i<s;i++){
    		cout<<vr[i]<<" "<<vc[i]<<" ";
    	}
    	cout<<endl;
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    