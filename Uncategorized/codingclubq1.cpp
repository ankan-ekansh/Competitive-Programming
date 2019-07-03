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
        int a,b;
        cin>>a>>b;
        int flag = 0;
        for(int i=1;i<=pow(((a*a)+(b*b)),0.5);i++){
            if(((a*a) + (b*b) == i*i) || ((a*a)+(i*i) == b*b) || (((i*i) + (b*b) == a*a))){
                cout<<"yes\n";
                flag = 1;
                break;
            }
            else
                continue;
        }
        if(flag == 0){
            cout<<"no\n";
        }



    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

