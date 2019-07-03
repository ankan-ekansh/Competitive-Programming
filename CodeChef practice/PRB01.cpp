#include<bits/stdc++.h>
using namespace std;
bool prime[1000050];
void sieve(){
    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=1000000;i++){
        if(prime[i]){
            //prime[i]=true;
            for(int j=i*i;j<=100000;j+=i){
                prime[j]=false;
            }
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
    cout.tie(NULL);
    int t;
    cin>>t;
    sieve();
    int c=0;
    // prime[1]=false;
    // for(int i=1;i<=100000;i++){
    //     if(prime[i]){
    //         cout<<i<<"\n";
    //         c++;
    //     }
    // }
    // cout<<c<<"\n";
    while(t--){
 
        int n;
        cin>>n;
        if(prime[n]){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;   
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}