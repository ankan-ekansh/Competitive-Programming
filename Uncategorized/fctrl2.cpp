#include<bits/stdc++.h>
using namespace std;

int f[300];

int main(){
    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt", "rt", stdin);
    //    freopen("output.txt", "wt", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c=0;

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        f[0]=1;
        int nd=1;
        int t;

        for(int i=1;i<=n;i++){
            for(int j=0;j<nd;j++){
                t = f[j]*i + c;                 //temporarily stores value of updated cell
                f[j]=t%10;                      //updates each cell by the ones place value of t
                c=t/10;                         //remaining part of t is carried over
            }
            while(c!=0){
                f[nd]=c%10;                      //loop runs till carry is adjusted
                c=c/10;
                nd++;                            //increments to fill other cells with digits of carry
            }



        }
        for(int i=nd-1;i>=0;i--){
            cout<<f[i];
        }
        cout<<"\n";
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

