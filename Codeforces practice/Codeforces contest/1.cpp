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

        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        //cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
        if(l1==l2 && r1==r2){
            cout<<l1<<" "<<r1<<endl;
        }
        else if(r1==l2){
            cout<<l1<<" "<<r2<<endl;
        }
        else if(l1==l2 && r1!=r2){
            cout<<r1<<" "<<r2<<endl;
        }
        else if(l1!=l2 && r1==r2){
            cout<<l1<<" "<<l2<<endl;
        }
        else{
            if(abs(r1-l1) > abs(r2-l2)){
                if(l1<l2)
                    cout<<l2<<" "<<r2<<endl;
                else if(l1>l2){
                    cout<<l1<<" "<<r2<<endl;
                }
            }
            else if(abs(r1-l1) < abs(r2-l2)){
                if(l1>l2)
                    cout<<l1<<" "<<r2<<endl;
                else if(l1<l2)
                    cout<<l1<<" "<<r2<<endl;
            }
            else if(l1 < l2){
                cout<<l1<<" "<<r2<<endl;
            }
        }

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

