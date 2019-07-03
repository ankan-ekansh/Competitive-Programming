#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
long long int p = 1;
long long int func(long long int n){
    if(n<10)
        return max(1LL,n);
    return max(n%10 * func(n/10), 9 * func(n/10 - 1));
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long int n;
    cin>>n;
    //func(n);
    cout<<func(n)<<"\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}