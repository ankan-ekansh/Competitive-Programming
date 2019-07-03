#include<bits/stdc++.h>
using namespace std;
int rev(int n){
    int r,d,s=0;
    while(n>0){
        r=n%10;
        n=n/10;
        s=s*10+r;
    }
    return s;
}
int main(){
/*    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int sum=rev(a)+rev(b);
        cout<<rev(sum)<<"\n";
    }

/*
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    */
    return 0;
}

