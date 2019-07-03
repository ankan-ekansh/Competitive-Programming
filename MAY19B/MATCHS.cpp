#include<bits/stdc++.h>
using namespace std;
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
    while(t--){
        int64_t c=0;
        int64_t n,m;
        cin>>n>>m;
        while(n*m != 0){
            if(n>=m){
                // n=n-(m*(n/m));
                // if(m%n == 0){
                //     n=n+m;
                // }
                // n=n-m;
                n=n%m;
                //cout<<n<<" "<<m<<"\n";
                c++;
            }
            else if(n<=m){
                // m=m-(n*(m/n));
                // if(n%m == 0){
                //     m=m+n;
                // }
                // m=m-n;
                m=m%n;
                //cout<<n<<" "<<m<<"\n";
                c++;
            }
        }
        //cout<<c<<"\n";
        //cout<<n<<" "<<m<<"\n";
        if(c%2==0){
            cout<<"Rich\n";
        }
        else{
            cout<<"Ari\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}