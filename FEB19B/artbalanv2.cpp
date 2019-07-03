#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input5.txt", "rt", stdin);
        freopen("output5.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){

    	char s[1000007];
    	cin>>s;
    	map<int,int> hash;
    	for(int i=0;i!=strlen(s);i++){
    	 	hash[s[i]-65]++;
    	}
    	int ce=0,co=0,fs=0,min=0,max=0;
    	for(auto i=hash.begin();i!=hash.end();i++){
    		cout<<i->first<<" "<<i->second<<" ";
    		if(i->second % 2 == 0 && i->second != 0)
    			ce++;
    		else if(i->second % 2 !=0 && i->second !=0)
    			co++;
    		fs+=i->second;
    		if(i->second > max){
    			max = i->second;
    		}
    		if(i->second < min){
    			min = i->second;
    		}
    		cout<<"\n";
    	}
    	if(fs%2==0){
    		int pivot = fs/(co+ce);
    		if(pivot * (co+ce) == fs){
    			int cost = 0,tf=(co+ce);
    			for(auto i=hash.begin();i!=hash.end();i++){
    				cost+=abs(i->second - pivot);
    				tf-=2;
    				if(tf<1){
    					break;
    				}
    			}
    			cout<<cost<<"\n";
    		}
    		else if( pivot * (co+ce+1) == fs)
    	}
    	else{

    	}
    	cout<<"\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    