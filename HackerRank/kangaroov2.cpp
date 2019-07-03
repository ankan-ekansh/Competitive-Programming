#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//21 6 47 3
    //21 6 47 3: 21,27,33,39,45,51,57,63		47,50,53,56,59
    int x1,v1,x2,v2;
    cin>>x1>>v1>>x2>>v2;
    if(x1<x2 && v1<v2){
        cout<<"NO\n";
        exit(0);
    }
    if(x2<x1 && v2<v1){
        cout<<"NO\n";
        exit(0);
    }
    else{
        int flag=0;
        if(x1>x2){
            int d = x1-x2;
            while(x1>=x2){
                x1+=v1;
                x2+=v2;
                if(x1-x2 < d){
                    d=x1-x2;
                    continue;
                }
                else if(x1-x2 > d){
                    cout<<"NO\n";
                    exit(0);
                }
                else if(x1<x2){
                    cout<<"NO\n";
                    exit(0);
                }
                else if(x1==x2){
                    cout<<"YES\n";
                    exit(0);
                }
            }
            if(flag==0){
                cout<<"NO\n";
            }
        }
        if(x2>x1){
            int flag = 0;
            int d = x2-x1;
            while(x2>=x1){
                x1+=v1;
                x2+=v2;
                if(x2-x1 < d){
                    d=x2-x1;
                    continue;
                }
                else if(x2-x1 > d){
                    cout<<"NO\n";
                    exit(0);
                }
                else if(x2<x1){
                    cout<<"NO\n";
                    exit(0);
                }
                else if(x1==x2){
                    cout<<"YES\n";
                    exit(0);
                }
            }
            if(flag==0){
                cout<<"NO\n";
            }
        }
    }

    return 0;
}

