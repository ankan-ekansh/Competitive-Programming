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

        int n,a,b;
		int pa = 0, pb = 0, pc = 0;
		cin>>n>>a>>b;
		for(int i = 0; i < n; i++){
			int x;
			cin>>x;
			if(x%a == 0){
				pa++;
			}
			if(x%b == 0){
				pb++;
			}
			if(x%a == 0 && x%b == 0){
				pc++;
			}
		}

		if(pa > pb){
			cout<<"BOB\n";
		}else if(pb > pa){
			cout<<"ALICE\n";
		}else{
			if(pc%2 == 0){
				cout<<"ALICE\n";
			}
			else{
				cout<<"BOB\n";
			}

    }

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

