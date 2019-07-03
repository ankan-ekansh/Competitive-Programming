#include<bits/stdc++.h>
#define lli long long int
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

        lli n,a,b;
        cin>>n>>a>>b;
        lli arr[n]={0};
        for(lli i = 0;i<n;i++){
            cin>>arr[i];
        }
        lli j=0;
        lli pa=0,pb=0,pca=0,pcb=0;
        for(lli i=0;i<n;i++){
            if(arr[i]%a==0 && arr[i]%b==0){
                pca++;
            }
            if(arr[i]%a==0 && arr[i]%b!=0){
                pa++;
            }
            if(arr[i]%a!=0 && arr[i]%b==0){
                pb++;
            }
        }
        pa=pa+pca;
        if(pa>pb){
            cout<<"BOB\n";
        }
        else if(pa<pb){
            cout<<"ALICE\n";
        }
        else if(pa==pb){
            cout<<"ALICE\n";
        }


    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

