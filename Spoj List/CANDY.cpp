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

    while(1){
        long long n;
        cin>>n;
        if(n == -1){
            break;
        }
        else{
            long long sum = 0;
            long long a[n];
            for(long long i = 0; i<n; i++){
                cin>>a[i];
                sum+=a[i];
            }
            long long avg = sum/n;
            if((n * avg) != sum){
                cout<<"-1\n";
                continue;
            }
            long long count = 0;
            for(long long i = 0; i<n; i++){
                if(a[i] > avg){
                    count+=(a[i]-avg);
                }
            }
            cout<<count<<"\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}