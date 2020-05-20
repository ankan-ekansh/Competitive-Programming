#include<bits/stdc++.h>
using namespace std;
int64_t a[100007];
int64_t b[100007][45];
int64_t power(int64_t a, int64_t b){
    if(b == 0){
        return 1;
    }
    else if(b == 1){
        return a;
    }
    else{
        int64_t x = power(a, b/2);
        if(b % 2 == 0){
            return x * x;
        }
        else{
            return x * x * a;
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

    int64_t n, k;
    cin >> n >> k;
    for(int64_t i=0;i<n;i++){
        cin >> a[i];
    }
    int64_t x[45], y[45];
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for(int64_t i=0;i<n;i++){
        for(int64_t j=0;j<45;j++){
            b[i][j] = (a[i] >> (44-j)) & 1;
        }
    }
    // for(int64_t i=0;i<n;i++){
    //     for(int64_t j=0;j<45;j++){
    //         cout << b[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int64_t temp = 0;
    int64_t t2 = 0;
    // int64_t z = log2(k);
    // cout << z << "\n";
    for(int64_t j=0;j<45;j++){
        int64_t s = 0;
        for(int64_t i=0;i<n;i++){
            if(b[i][j] == 1){
                s++;
            }
        }
        if(s > (n-s)){
            x[j] = 0;
            y[j] = 0;
        }
        else if(s < (n-s)){
            x[j] = 1;
            y[j] = 1;
        }
        else{
            x[j] = 0;
            y[j] = 1;
        }
        // cout << s << " ";
        // if((temp + (power(2, 44-j) * x[j])) > k){
        //     break;
        // }
        // temp+=(power(2, 44-j) * x[j]);
        // t2+=(power(2, 44-j) * (1 - x[j]));
    }
    // cout << "\n";
    for(int64_t j=0;j<45;j++){
        // cout << x[j] << ": ";
        if((temp + (power(2, 44-j) * x[j])) <= k){
            // cout << (power(2, 44-j) * x[j]) << " ";
            temp+=(power(2, 44-j) * x[j]);
        }
        if((t2 + (power(2, 44-j) * y[j])) <= k){
            t2+=(power(2, 44-j) * y[j]);
        }
        //cout << temp << " ";
    }
    // cout << "\n";

    // cout << temp << "\n";
    // cout << temp << " " << t2 << " " << k << "\n";
    int64_t ans = 0;
    int64_t a2 = 0;
    for(int64_t i=0;i<n;i++){
        ans+=(temp ^ a[i]);
        a2+=(t2 ^ a[i]);
    }
    // cout << temp << " " << t2 << "\n";
    cout << max(ans, a2) << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}