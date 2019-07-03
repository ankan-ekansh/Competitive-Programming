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
    int temp;
    int tempstatus;
    int laststatus;
    cout<<"1 1\n"<<flush;
    coins--;
    cin>>startstatus;
    if(startstatus==-1){
        exit(0);
    }
    if(startstatus==1){
        cout<<"2\n"<<flush;
        coins=coins-c;
        startstatus=0;
        cout<<"3 1"<<flush;
        exit(0);
    }
    while(low<=high && coins>0){

        mid=(low+high)/2;
        if(mid==low && mid==high-1){
            if(startstatus==0 && endstatus==1){
                x=high;
                break;
            }
        }
        int z=(high-low)/2;
        if((midstatus==0 && coins>=(c+z+1) && laststatus==1)){
            temp=low+2;
            if(temp==high){
                cout<<"3 "<<high<<endl<<flush;
                exit(0);
            }
            while(coins>0){
                if(temp==high){
                cout<<"3 "<<high<<endl<<flush;
                exit(0);
            }
                cout<<"1 "<<temp<<endl<<flush;
                coins--;
                cin>>tempstatus;
                if(tempstatus==-1){
                    exit(0);
                }
                if(tempstatus==1){
                    cout<<"2\n"<<flush;
                    coins=coins-c;
                    cout<<"1 "<<temp-1<<endl<<flush;
                    coins--;
                    cin>>tempstatus;
                    if(tempstatus==-1){
                        exit(0);
                    }
                    if(tempstatus==1){
                        cout<<"3 "<<temp-1<<endl<<flush;
                        exit(0);
                    }
                    else{
                        cout<<"3 "<<temp<<endl<<flush;
                        exit(0);
                    }
//                    cout<<"3 "<<low<<endl<<flush;
//                    exit(0);
                }
            temp+=2;
            }
            if(coins<=0){
                exit(0);
            }
        }
        int y = (high-mid)/2;
        if((midstatus==0 && coins>=(c+y+1) && laststatus==0)){
            temp=mid+2;
            if(temp==high){
                cout<<"3 "<<high<<endl<<flush;
                exit(0);
            }
            while(coins>0){
                if(temp==high){
                    cout<<"3 "<<high<<endl<<flush;
                    exit(0);
                }
                cout<<"1 "<<temp<<endl<<flush;
                coins--;
                cin>>tempstatus;
                if(tempstatus==-1){
                    exit(0);
                }
                if(tempstatus==1){
                    cout<<"2\n"<<flush;
                    coins=coins-c;
                    cout<<"1 "<<temp-1<<endl<<flush;
                    coins--;
                    cin>>tempstatus;
                    if(tempstatus==-1){
                        exit(0);
                    }
                    if(tempstatus==1){
                        cout<<"3 "<<temp-1<<endl<<flush;
                        exit(0);
                    }
                    else{
                        cout<<"3 "<<temp<<endl<<flush;
                        exit(0);
                    }
                }
                temp=temp+2;

            }
/*            mid=mid+2;
            while(coins>0){
                cout<<"1 "<<mid<<endl<<flush;
                coins--;
                cin>>midstatus;
                if(midstatus==1){
//                    cout<<"3 "<<mid<<endl<<flush;
//                    exit(0);
                    cout<<"2\n"<<flush;
                    coins=coins-c;
                    cout<<"1 "<<mid-1<<endl<<flush;
                    coins--;
                    cin>>midstatus;
                    if(midstatus==1){
                        cout<<"3 "<<mid-1<<endl<<flush;
                        exit(0);
                    }
                    else{
                        cout<<"3 "<<mid<<endl<<flush;
                        exit(0);
                    }
                }
//                if(midstatus==1 && laststatus==1){
//                    cout<<"3 "<<mid<<endl<<flush;
//                    exit(0);
//                }
//                laststatus=midstatus;
                mid+=2;;
            }
            */
            if(coins<=0){
                exit(0);
            }
        }

        if(midstatus==0 && coins>=c+1){
            cout<<"1 "<<mid<<endl<<flush;
            coins--;
            cin>>midstatus;
            if(midstatus==-1){
                exit(0);
            }
            if(midstatus==0)
                laststatus=0;
        }


        if(startstatus==0 && midstatus==0 && endstatus==1){
            low=mid;
            startstatus=midstatus;
        }

        if(startstatus==0 && midstatus==1 && endstatus==1){
            high=mid;
            endstatus=midstatus;
        }
        if(midstatus==1 && coins>=c){
            cout<<"2\n"<<flush;
            coins=coins-c;
            midstatus=0;
            laststatus=1;
        }
        if(midstatus==-1){
            exit(0);
        }
    }
    cout<<"3 "<<x<<flush;





    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

