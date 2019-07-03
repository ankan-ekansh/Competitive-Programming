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
    	//some cases, AABBB, AABBBCCCC, AABBBB, AABBBBB
    	char s[1000001];
    	cin>>s;
    	char fa[91]={0};
    	for(int i=0;i!=strlen(s);i++){
    		char c = s[i];
    		fa[c]++;
    	}
    	vector<int> a;
    	for(int i=65;i<=90;i++){
    		if(fa[i]>0){
    			a.push_back(fa[i]);
    		}
    	}
    	//for(auto i=a.begin();i!=a.end();i++){
    	//	cout<<*i<<" ";
    	//}
    	//cout<<"\n";
    	sort(a.begin(),a.end());
    	int max = a[a.size()-1];
    	int min = a[0];
    	int mid = (max+min)/2;
    	if(mid-min == max-mid){
    		cout<<(2*(mid-min))<<"\n";
    	}
    	else{
    		cout<<min<<"\n";
    	}
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    