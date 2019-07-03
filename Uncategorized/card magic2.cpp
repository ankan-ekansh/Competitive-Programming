#include<bits/stdc++.h>
using namespace std;
long int a[100050];
long int b[100050];

int main(){
  #ifndef ONLINE_JUDGE
        freopen("i.txt", "rt", stdin);
        freopen("o.txt", "wt", stdout);
	#endif

 ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        for(long int i=0;i<n;i++){
            cin>>a[i];
        }
        long int smallest=a[0];
        long int pos=0;
        for(long int i=1;i<n;i++){
            if(a[i]<smallest){
                smallest=a[i];
                pos=i;
            }
            else if(a[i]==smallest && a[i-1]!=a[i]){
                pos=i;
                break;
            }
            else if(a[i]==smallest && a[i+1]!=a[i]){
                pos=i;
            }
        }
        int k=0;
        int flag=0;
        for(int i=pos;i<n;i++){
            b[k++]=a[i];
        }
        for(int i=0;i<pos;i++){
            b[k++]=a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                flag=1;
            }
        }
        if(flag!=0)
            cout<<"NO"<<"\n";
        else
            cout<<"YES"<<"\n";



    }



/*    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    */
    return 0;
}
