#include<bits/stdc++.h>
using namespace std;
int main(){
    //#ifndef ONLINE_JUDGE
    //    freopen("input.txt", "rt", stdin);
    //    freopen("output.txt", "wt", stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int coins = 1000;
    int n,c;
    int status=0;
    bool found = false;
    cin>>n>>c;
    int y=1;
    int x=1;
    while(coins>0 && found == false){
        if(status==0){
            cout<<"1 "<<y<<endl<<flush;
            coins--;
            cin>>status;
            if(status==1){
                x=y;
                break;
            }
            y++;
        }
        if(status==1){
            cout<<"2\n"<<flush;
            coins=coins-c;
            status=0;
        }
        if(status==-1){
            continue;
        }

    }
    cout<<"3 "<<x<<flush;


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

