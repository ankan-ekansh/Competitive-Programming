/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> spf(10000001, 0);
void sieve(){
    spf[1] = 1;
    for(int i=2;i<=10000000;i++){
        if(spf[i] == 0){
            spf[i] = i;
            for(int j=2*i;j<=10000000;j+=i){
                spf[j] = i;
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    sieve();
    int n;
    cin >> n;
    int a[n], ans[2][n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int d1 = spf[a[i]];
        int rem = a[i]/d1;
        while(rem % d1 == 0){
            rem /= d1;
        }
        int d2 = rem;
        if(d1 != 1 && d2 != 1 && __gcd(d1+d2, a[i]) == 1){
            ans[0][i] = d1;
            ans[1][i] = d2;
        }
        else{
            ans[0][i] = -1;
            ans[1][i] = -1;
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[0][i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n;i++){
        cout << ans[1][i] << " ";
    }
    cout << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}