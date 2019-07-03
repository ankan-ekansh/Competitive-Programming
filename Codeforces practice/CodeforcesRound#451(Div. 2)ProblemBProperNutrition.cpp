#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    unsigned long long int n,a,b;
    cin>>n;
    cin>>a;
    cin>>b;
    unsigned long long int x,y;
    x=0;
    y=0;
    bool flag=0;
    for(unsigned long long int i = 0;i<=(n/a);i++){
        if((n-a*i)%b == 0){
            y=(n-a*i)/b;
            x=i;
            flag = true;
            break;
        }
    }
    if(flag == true && y>=0){
        cout<<"YES\n";
        cout<<x<<" "<<y<<endl;
    }
    else
        cout<<"NO\n";


//    #ifndef ONLINE_JUDGE
//        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
//    #endif
    return 0;
}

