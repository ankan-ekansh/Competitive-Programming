#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("i.txt", "rt", stdin);
        freopen("o.txt", "wt", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int kx[n],ky[n];
        for(int i=0;i<n;i++){
            cin>>kx[i]>>ky[i];
        }
        int wkx,wky;
        cin>>wkx>>wky;
        int flag=0;
        for(int i=0;i<n;i++){
            if((wkx!=kx[i])&&(wky!=ky[i])&&((((ky[i]-wky)/(kx[i]-wkx))!=1)||(((ky[i]-wky)/(kx[i]-wkx))!=-1))){
                    if(ky[i]-wky == 2 || wky-ky[i] == 2){
                        if(kx[i]-wkx == 1 || wkx-kx[i] == 1){
                            cout<<"YES"<<"\n";
                flag=1;
                break;
                        }
                    }
                    if(kx[i]-wkx == 2 || wkx-kx[i] == 2){
                        if(ky[i]-wky == 1 || wky-ky[i] == 1){
                            cout<<"YES"<<"\n";
                flag=1;
                break;
                        }
                    }
            }
        }
        if(flag==0)
            cout<<"NO"<<"\n";

    }


/*    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
  */  return 0;
}
