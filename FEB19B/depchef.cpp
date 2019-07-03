#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input3.txt", "rt", stdin);
        freopen("output3.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){

    	int n;
    	cin>>n;
    	int a[n],d[n];
    	vector<int> dv;
    	for(int i=0;i<n;i++){
    		cin>>a[i];
    	}
    	for(int i=0;i<n;i++){
    		cin>>d[i];
    	}
    	for(int i=0;i<n;i++){
    		if(i==0){
    			if(a[n-1] + a[1] < d[0]){
    				dv.push_back(d[0]);
    			}
    		}
    		else if(i==(n-1)){
    			if(a[n-2] + a[0] < d[n-1]){
    				dv.push_back(d[n-1]);
    			}
    		}
    		else{
    			if(a[i-1] + a[i+1] < d[i]){
    				dv.push_back(d[i]);
    			}
    		}
    	}
    	if(dv.empty()){
    		cout<<"-1\n";
    	}
    	else{
    		sort(dv.begin(),dv.end());
    		cout<<dv[dv.size()-1]<<"\n";
    	}
    	

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    