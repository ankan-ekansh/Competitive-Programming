#include<bits/stdc++.h>
using namespace std;
long double c[1000007];
long double cc[1000007];
bool check(uint64_t n,uint64_t x, uint64_t m){
    uint64_t i = 0;
    uint64_t tn = n;
    for(i=1;i<=m;i++){
        tn-=x;
        tn+=floor(tn/100);
    }
    if(tn <= 0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "rt", stdin);
       freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    uint64_t n,m;
    cin>>n>>m;
    c[1]=1;
    cc[1]=1;
    uint64_t t = m;
    if(n==1){
        cout<<"1\n";
        exit(0);
    }
    for(uint64_t i=2;i<=t;i++){
        c[i]=c[i-1]+c[i-1]/100;
        cc[i]=cc[i-1]+c[i];
    }
    uint64_t x = (uint64_t)round((n*c[m])/(cc[m]));
    //cout<<x<<"\n";
    // bool a1 = check(n,x-3,m);
    // bool a2 = check(n,x-2,m);
    // bool a3 = check(n,x-1,m);
    // bool a4 = check(n,x,m);
    // bool a5 = check(n,x+1,m);
    // bool a6 = check(n,x+2,m);
    // bool a7 = check(n,x+3,m);
    // bool a1 = check(n,x-1,m);
    // bool a2 = check(n,x,m);
    // bool a3 = check(n,x+1,m);
    // if(a1)
    //     cout<<x-1<<"\n";
    // else if(a2){
    //     cout<<x<<"\n";
    // }
    // else if(a3){
    //     cout<<x+1<<"\n";
    // }

    //cout<<a1<<" "<<a2<<" "<<a3<<"\n";
    // if(a1){
    //     cout<<x-3<<"\n";
    // }
    // else if(a2){
    //     cout<<x-2<<"\n";
    // }
    // else if(a3){
    //     cout<<x-1<<"\n";
    // }
    // else if(a4){
    //     cout<<x<<"\n";
    // }
    // else if(a5){
    //     cout<<x+1<<"\n";
    // }
    // else if(a6){
    //     cout<<x+2<<"\n";
    // }
    // else if(a7){
    //     cout<<x+3<<"\n";
    // }

    cout<<fixed<<((n*c[m])/(cc[m]))<<"\n";

    #ifndef ONLINE_JUDGE
       cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


//1000000000000000000 956478 = 9900990099009901
//564789541235465897 999999 = 5591975655796693