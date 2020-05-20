#include<bits/stdc++.h>
using namespace std;
int64_t p[10000007];
void sieve(){
    for(int64_t i=2;i<=10000000;i++){
        if(!p[i]){
            for(int64_t j=2*i;j<=10000000;j+=i){
                p[j]++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int64_t t;
    cin >> t;
    int64_t c = 1;
    while(t--){
        int64_t a, b, k;
        cin >> a >> b >> k;
        int64_t ans = 0;
        for(int64_t i=a;i<=b;i++){
            if(p[i] == k){
                ans++;
            }
            if(p[i] == 0 && k == 1){
            	ans++;
            }
        }
        cout << "Case #" << c++ <<": "<< ans << "\n";
    }
}