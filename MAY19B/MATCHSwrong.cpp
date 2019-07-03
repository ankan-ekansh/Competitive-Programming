#include<bits/stdc++.h>
using namespace std;
void recur(int64_t n,int64_t m,int64_t c){
	if(n<=0 || m<=0){
		return;
	}
	cout<<n<<" "<<m<<" "<<c<<"\n";
	if(n>m){
		recur(n-c*m,m,++c);
	}
	else{
		recur(n,m-c*n,++c);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
 
		int64_t n,m,c=0;
		cin>>n>>m;
		recur(n,m,c);
 
	}
	#ifndef ONLINE_JUDGE
		cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
	#endif
	return 0;
}