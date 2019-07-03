#include<bits/stdc++.h>
using namespace std;
vector<int> r,c,fr,fc;
void checkrc(int x,int y){
	if(!binary_search(r.begin(),r.end(),x) && !binary_search(c.begin(),c.end(),y)){
		fr.push_back(x);
		r.push_back(x);
		fc.push_back(y);
		c.push_back(y);
	}
}
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
    	int tr,tc;
    	for(int i=0;i<k;i++){
    		cin>>tr>>tc;
    		r.push_back(tr);
    		c.push_back(tc);
    	}
    	sort(r.begin(),r.end());
 		sort(c.begin(),c.end());
 		for(int i=1;i<=n;i++){
 			for(int j=1;j<=n;j++){
 				sort(r.begin(),r.end());
 				sort(c.begin(),c.end());
 				checkrc(i,j);
 			}
 		}
 		cout<<fr.size()<<" ";

 		for(auto i=fr.begin(),j=fc.begin();i!=fr.end(),j!=fc.end();i++,j++){
 			cout<<*i<<" "<<*j<<" ";
 		}
 		cout<<endl;
 		r.clear();
 		c.clear();
 		fr.clear();
 		fc.clear();
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    