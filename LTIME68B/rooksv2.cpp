#include<bits/stdc++.h>
using namespace std;
map<int,int> r,c,fr,fc;
int no=0;
vector<int> tempr,tempc;
void checkrc(int x,int y){
	if(r.find(x)==r.end() && c.find(y)==c.end()){
		fr.insert(pair<int, int>(x, 0));
		r.insert(pair<int, int>(x, 0));
		fc.insert(pair<int, int>(y, 0));
		c.insert(pair<int, int>(y, 0));
        no++;
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
    		r.insert(pair<int, int>(tr, i));
            c.insert(pair<int, int>(tc, i));
    	}
        //for(auto i=0;i!=tr.end();i++){
        //    tempr.push_back(i->first);
        //}
        //for(auto j=0;j!=tc.end();j++){
        //    tempc.push_back(j->first);
        //}
 		for(int i=1;i<=n;i++){
 			for(int j=1;j<=n;j++){
 				checkrc(i,j);
 			}
 		}
 		cout<<no<<" ";

 		for(auto i=fr.begin(),j=fc.begin();i!=fr.end(),j!=fc.end();i++,j++){
 			cout<<i->first<<" "<<j->first<<" ";
 		}
 		cout<<endl;
 		r.clear();
 		c.clear();
 		fr.clear();
 		fc.clear();
        no = 0;
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    