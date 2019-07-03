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
    int midstatus=0;
    int startstatus=0;
    int endstatus=1;
    bool found = false;
    cin>>n>>c;
    int y=1;
    int x=1;
    int low=1;
    int high=n;
    int mid;
    while(low<=high){


        mid=(low+high)/2;
        if(midstatus==0){
            cout<<"1 "<<mid<<endl<<flush;
            coins--;
            cin>>midstatus;
            if(midstatus==1){
                cout<<"2\n"<<flush;
                coins=coins-c;
            }
            if(startstatus==0 && midstatus==0 && endstatus==1){
                low=mid+1;
                if(startstatus==0){
                    cout<<"1 "<<low<<endl<<flush;
                    coins--;
                    cin>>startstatus;
                    if(startstatus==1){
                        x=low;
                        break;
                    }
                }
                }
            }
            if(startstatus==0 && midstatus==1 && endstatus==1){
                high=mid-1;
                if(endstatus==1){
                    cout<<"1 "<<high<<endl<<flush;
                    coins--;
                    cin>>endstatus;
                    if(endstatus==1){
                        cout<<"2\n"<<flush;
                        coins=coins-c;
            }
        }
            }

            if(mid==low+1 && mid==high-1){
                if(startstatus==0 && midstatus==1){
                    x=mid;
                    break;
                    }
                }
                                midstatus=0;
            }
    cout<<"3 "<<x<<flush;





    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

