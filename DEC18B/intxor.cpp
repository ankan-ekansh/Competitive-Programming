#include<bits/stdc++.h>
using namespace std;
int main(){
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "rt", stdin);
//        freopen("output.txt", "wt", stdout);
//    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        long int a[50050];long int b[50050];
        int k=n-1;
        int l=n-1;
        int check;
/*      for(int i=1;i<=n;i++){
            cout<<"1 "<<i<<" "<<i<<" "<<i<<endl<<flush;
            cin>>a[i-1];
        }
        cout<<"2 ";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl<<flush;
        cin>>check;
        if(check==-1)
            exit(0);
*/      if(n%4==0){
            cout<<"1 "<<n-1<<" "<<n-2<<" "<<n-3<<endl<<flush;
            cin>>b[k];
            if(b[k--] == -1)
                exit(0);
            cout<<"1 "<<n<<" "<<n-2<<" "<<n-3<<endl<<flush;
            cin>>b[k];
            if(b[k--] == -1)
                exit(0);
            cout<<"1 "<<n<<" "<<n-1<<" "<<n-3<<endl<<flush;
            cin>>b[k];
            if(b[k--] == -1)
                exit(0);
            cout<<"1 "<<n<<" "<<n-1" "<<n-2<<endl<<flush;
            cin>>b[k];
            if(b[k--] == -1)
                exit(0);
            a[l--]=b[k]^b[k+1]^b[k+2];
            a[l--]=b[k]^b[k+1]^b[k+3];
            a[l--]=b[k]^b[k+2]^b[k+3];
            a[l--]=b[k+1]^b[k+2]^b[k+3];
        }
        while(l>=8){

        }




    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

