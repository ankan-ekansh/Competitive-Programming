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
    	cin.ignore();
    	string s;
    	getline(cin,s);
    	int c=0;
    	for(int i=0;i<n;i++){
    		if(s[i]=='0'&& s[i+1]!='1' && s[i-1]!='1'){
    			s[i]='1';
    			c++;
    		}
    	}
    	cout<<c<<endl;

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    