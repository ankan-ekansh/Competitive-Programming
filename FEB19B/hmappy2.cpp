#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "rt", stdin);
        freopen("output1.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--){

    	long long int n,a,b,k;
    	cin>>n>>a>>b>>k;
    	long long int na=0,nb=0,nc=0,nf=0;
    	na = n/a;
    	nb = n/b;
    	long long int lcm = (a*b)/(__gcd(a,b));
    	nc = n/lcm;
    	na = na - nc;
    	nb = nb - nc;
    	nf = na+nb;
    	if(nf>=k){
    		cout<<"Win\n";
    	}
    	else{
    		cout<<"Lose\n";
    	}

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


    