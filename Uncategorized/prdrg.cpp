#include<bits/stdc++.h>
using namespace std;
long int x[30],y[30];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    x[0]=0;
    y[0]=1;
    x[1]=1;
    y[1]=2;

    for(int i=2;i<=25;i++){
        x[i]=(x[i-1]*y[i-2])+(x[i-2]*y[i-1]);
        y[i]=2*y[i-1]*y[i-2];
        long int h = __gcd(x[i], y[i]);
        if(h!=0){
            x[i]=x[i]/h;
            y[i]=y[i]/h;
        }
    }


    int t;
    cin>>t;
    while(t--){

    int n;
    cin>>n;
    cout<<x[n]<<" "<<y[n]<<" ";

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

