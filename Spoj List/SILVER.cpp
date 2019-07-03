#include<bits/stdc++.h>
using namespace std;
long long power(long long a, long long b){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a;
    }
    long long x = power(a, b/2);
    if(b % 2 == 0){
        return x*x;
    }
    else{
        return x*a*x;
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

    while(1){
        long long n;
        cin>>n;
        if(n == 0){
            break;
        }
        else{
            long long low = floor(log2(n));
            long long high = ceil(log2(n));
            //cout<<low<<" "<<high<<"\n";
            if((power(2, low) <= n) && (n < power(2, high))){
                cout<<low<<"\n";
            }
            if(power(2, low) == power(2, high)){
                cout<<low<<"\n";
            }
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}