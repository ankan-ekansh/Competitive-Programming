#include<bits/stdc++.h>
using namespace std;
int pr[1000001];
void sieve(){
	for(long long i=2;i<=1000000;i++){
    	pr[i]=1;
    }
    for(long long i=2;i<=1000000;i++){
    	if(pr[i]==0){
    		continue;
    	}
       for(long long j=2*i;j<=1000000;j+=i){
          pr[j]=0;
        }
    }
    

}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long q;
    sieve();
    for(long long i=1;i<=1000000;i++){
    	if(pr[i]){
    		pr[i]=__builtin_popcount(i)+pr[i-1];
    	}
    	else{
    		pr[i]=pr[i-1];
    	}
    }
    cin>>q;
    while(q--){
        long long l,r;
        cin>>l>>r;
        cout<<pr[r]-pr[l-1]<<"\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    