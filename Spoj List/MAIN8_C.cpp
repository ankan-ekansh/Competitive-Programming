#include<bits/stdc++.h>
bool fun(long long a[], long long n, long long k, long long m){
    long long t=0;
    for(long long i=0;i<n;i++){
        t+=(a[i]/m);
    }
    if(t<k){
        return false;
    }
    else{
        return true;
    }
}
using namespace std;
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
 
        long long n, k;
        cin >> n >> k;
        long long a[n];
        for(long long i=0;i<n;i++){
            cin >> a[i];
        }
        long long l = 1, r = 1000000000;
        while(abs(l-r)>1){
            long long m = l + (r-l)/2;
            if(fun(a, n, k, m) == false){
                r=m-1;
            }
            else{
                l=m;
            }
        }
        if(fun(a, n, k, r) == true){
            cout << r << "\n";
        }
        else if(fun(a, n, k, r) == false){
            if(fun(a, n, k, l) == true){
                cout << l << "\n";
            }
            else{
                cout << "0\n";
            }
        }
        else{
            cout << "0\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}