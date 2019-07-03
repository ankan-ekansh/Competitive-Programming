#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        int d,q;
        cin>>d;
        int di;
        int pi;
        int pips[32] = {0};
        for(int i=1;i<=d;i++){
            cin>>di>>pi;
            for(int j=di;j<=31;j++){
                pips[j]+=pi;
            }
        }
        int deadi,reqi;
        cin>>q;
        for(int i=1;i<=q;i++){
            cin>>deadi>>reqi;
            if(pips[deadi]>=reqi){
                cout<<"Go Camp\n";
            }
            else
                cout<<"Go Sleep\n";

        }
//        for(int i=1;i<=31;i++){
//            cout<<"Day "<<i<<" : "<<"Solved: "<<pips[i]<<endl;
//        }


    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

