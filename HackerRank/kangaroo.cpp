#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1,v1,x2,v2;
    cin>>x1>>v1>>x2>>v2;
    //21 6 47 3: 21,27,33,39,45,51,57,63		47,50,53,56,59
    //x1+(n-1)v1 = x2+(m-1)v2
    if(x1<x2 && v1<v2){
        cout<<"NO\n";
        exit(0);
    }
    else if(x2<x1 && v2<v1){
        cout<<"NO\n";
        exit(0);
    }
    else{
        int flag;
        if(x1<x2){
            while(x1<x2){
                x1+=v1;
                x2+=v2;
                if(x1==x2){
                    flag = 1;
                    break;
                }
                else{
                    flag = 0;
                }
            }
            if(flag==1){
                cout<<"YES\n";
                exit(0);
            }
            else{
                cout<<"NO\n";
                exit(0);
            }
        }
        else if(x2<x1){
            while(x2<x1){
                x1+=v1;
                x2+=v2;
                if(x1==x2){
                    flag = 1;
                    break;
                }
                else{
                    flag = 0;
                }
            }
            if(flag==1){
                cout<<"YES\n";
                exit(0);
            }
            else{
                cout<<"NO\n";
                exit(0);
            }
        }
    }

    return 0;
}

