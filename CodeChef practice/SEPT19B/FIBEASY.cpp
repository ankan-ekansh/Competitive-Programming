#include<bits/stdc++.h>
using namespace std;
int fib[61];
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

    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=60;i++){
        fib[i] = (fib[i-1] + fib[i-2]) % 10;
    }

    int t;
    cin>>t;
    while(t--){
 
        int64_t n;
        cin >> n;
        int64_t temp = n;
        int64_t b = 0;
        while(temp){
            temp/=2;
            b++;
        }
        int64_t p = (int64_t)power(2, b - 2);
        cout << fib[((2 * p) - 1) % 60] << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}