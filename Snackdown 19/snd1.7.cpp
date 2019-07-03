#include<bits/stdc++.h>
long int a[100001];

using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t;
    scanf("%ld",&t);
    while(t--){
        long int n;
        long int i;
        long int days=0;
        scanf("%ld",&n);
        a[0]=1;
        for(i=1;i<=n;i++){
            scanf("%ld",&a[i]);
        }
        long int sum=0;
        for(i=1;i<=n;i++){
            sum=sum+a[i];
            a[i]=sum;
        }
        long int nt;
        nt=1;
       while(nt<=n){
           if(nt<n){

                a[0]=a[0]+a[nt];
                nt=a[0];
           }
            if(nt>=n){
            days++;
            break;
           }
            else
                days++;
       }
        printf("%ld\n",days);
    }
    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
