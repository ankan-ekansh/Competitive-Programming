#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input4.txt", "rt", stdin);
        freopen("output4.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int t;
    cin>>t;
    while(t--){

    	long long int n;
    	cin>>n;
    	vector<long long int> a;
    	for(long long int i=0;i<n;i++){
    		long long int temp;
    		cin>>temp;
    		a.push_back(temp);
    	}
    	sort(a.begin(),a.end(),greater<int>());
    	cout<<a[0]<<"\n";

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    