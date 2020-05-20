#include<bits/stdc++.h>
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
 
        long long a, b;
        cin >> a >> b;
        long long diff = abs(b - a);
        if(a == b){
            cout << "0\n";
            continue;
        }
        long long n;
        vector<long long> v;
        for(n=0;n<=45000;n++){
            long long k = (2*diff) - (n*(n+1));
            if((1-(4*k)) >= 0){
                long long x = -1 +(-1)*(long long)sqrt(1-(4*k));
                x/=2;
                long long y = -1 + (long long)sqrt(1-(4*k));
                y/=2;
                if(x>=0 && (((n-x)*(n+x+1)) == 2*diff)){
                    //cout << n+x << "\n";
                    v.push_back(n+x);
                }
                if(y>=0 && (((n-y)*(n+y+1)) == 2*diff)){
                    //cout << n+y << "\n";
                    v.push_back(n+y);
                }
            }
        }
        // for(n=0;n<=45000;n++){
        //     for(m=0;m<n;m++){
        //         if(((n-m)*(n+m+1)) == 2*diff){
        //             v.push_back(n+m);
        //             break;
        //         }
        //     }
        // }
        // long long l=0, r=45000;
        // while(l<=r){
        //     long long x = l + (r-l)/2;
        //     for(m=0;m<=x;m++){
        //         if(((x-m)*(x+m+1)) == 2*diff){
        //             v.push_back(x+m);
        //             break;
        //         }
        //     }
        //     if(((x-m)*(x+m+1)) < 2*diff){
        //         r=x-1;
        //     }x
        //     else if(((x-m)*(x+m+1)) > 2*diff){
        //         l=x+1;
        //     }
        // }
        sort(v.begin(), v.end());
        // cout << v.size() << "\n";
        cout << v[0] << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}