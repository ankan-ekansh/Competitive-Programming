#include<bits/stdc++.h>
using namespace std;
// bool primes[100050];
// int n = 100050;
// void sieve(){
//     memset(primes, true, sizeof(primes));
//     for(int p=2; p*p <= n; p++){
//         if(primes[p]){
//             for(int i = p*2; i<=n; i+=p){
//                 primes[i]=false;
//             }
//         }
//     }
// }
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    // sieve();
    while(t--){
 
        int a, b;
        cin>>a>>b;
        if(a < 4)
            cout<<(min(3, b) - a + 1)<<"\n";
        else
            cout<<"0\n";
        // int c = 0;
        // // cout<<primes[0]<<" "<<primes[1]<<"\n";
        // for(int i = a; i<=b; i++){
        //     if(primes[i]){
        //         if(i < 5){
        //             c++;
        //         }
        //         else if(i > 5){
        //             if(((i % 6) == 1) || ((i % 6) == 5)){
        //                 c++;
        //             }
        //         }
        //     }
        // }
        // cout<<c<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}