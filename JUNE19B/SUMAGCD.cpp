#include<bits/stdc++.h>
using namespace std;
// int primes[100000];
// int sieve(int n){
//     bool prime[n+1];
//     memset(prime, true, sizeof(prime));
//     for(int p=2;p*p<=n;p++){
//         if(prime[p]==true){
//             for(int i=p*2;i<=n;i+=p){
//                 prime[i]=false;
//             }
//         }
//     }
//     int k=0;
//     for(int p=2;p<=n;p++)
//         if(prime[p])
//             primes[k++]=p;
//     return k;
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
    while(t--){
 
        int n;
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        vector<int>::iterator it = unique(a.begin(), a.begin()+n);
        a.resize(distance(a.begin(), it));
        int s = a.size();
        if(s == 1){
            cout<<2*a[0]<<"\n";
            continue;
        }
        else if(s == 2){
            cout<<a[0]+a[1]<<"\n";
            continue;
        }
        int pr[s]={0},po[s]={0};
        pr[1]=a[0];
        for(int i=2;i<s;i++){
            pr[i]=__gcd(pr[i-1], a[i-1]);
        }
        po[s-2]=a[s-1];
        for(int i=s-3;i>=0;i--){
            po[i]=__gcd(po[i+1], a[i+1]);
        }
        //for(int i=0;i<n;i++){
            //cout<<pr[i]<<" ";
        //}
        //cout<<"\n";
        //for(int i=0;i<n;i++){
            //cout<<po[i]<<" ";
        //}
        //cout<<"\n";
        int s_max = 0;
        for(int i=0;i<s;i++){
            int s = a[i] + __gcd(pr[i], po[i]);
            if(s > s_max){
                s_max = s;
            }
        }
        cout<<s_max<<"\n";
        

        // sort(a,a+n);
        // int l = a[n-1];
        // int g = a[0];
        // int g_max = 0;
        // for(int i=1;i<n-2;i++){
        //     g = __gcd(g,a[i]);
        // }
        // int g1 = __gcd(g,a[n-2]);
        // int g2 = __gcd(g,a[n-1]);
        // if(g1+a[n-1] > g2+a[n-2]){
        //     cout<<g1+a[n-1]<<"\n";
        // }
        // else{
        //     cout<<g2+a[n-2]<<"\n";
        // }
        //cout<<l+g<<"\n";

 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}