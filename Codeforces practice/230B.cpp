#include<bits/stdc++.h>
using namespace std;
bool p[1000007];
void sieve(){
    memset(p, true, sizeof(p));
    for(int64_t i=2;i*i<=1000005;i++){
        if(p[i]){
            for(int64_t j=i*i;j<=1000005;j+=i){
                p[j] = false;
            }
        }
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

    int64_t n;
    cin >> n;
    sieve();
    for(int64_t i=0;i<n;i++){
        int64_t x;
        cin >> x;
        if(x == 1){
            cout << "NO\n";
            continue;
        }
        int64_t y = (int64_t)sqrt(x);
        if(y * y == x && p[y]){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}