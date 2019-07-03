#include<bits/stdc++.h>
using namespace std;
int main(){
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "rt", stdin);
//        freopen("output.txt", "wt", stdout);
//    #endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);


    int n;
    cin>>n;
    int a,b;
    a=n/100;
    b=n%100;
    if(b%10<5){
        cout<<(a*100 + (b/10)*10);
    }
    else if(b%10>=5){
        cout<<(a*100 + ((b/10)+1)*10);
    }



//    #ifndef ONLINE_JUDGE
//        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
//    #endif
    return 0;
}

