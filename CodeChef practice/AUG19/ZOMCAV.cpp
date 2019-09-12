#include<bits/stdc++.h>
using namespace std;
bool comp(long a, long b){
    return a > b;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long t;
    cin>>t;
    while(t--){
 
        long n;
        cin>>n;
        long c[n+1]={0}, h[n]={0};
        long l[n] = {0};
        map<long, long> r;
        for(long i=1;i<=n;i++){
            cin>>c[i];
            long start = i - c[i];
            long stop = i + c[i];
            if(start <= 0){
                start = 1;
            }
            r[start]++;
            if(stop >= n){
                stop = n;
            }
            r[stop + 1]--;
        }

        for(long i=0;i<n;i++){
            cin>>h[i];
        }
        sort(h,h+n);
        long j = 0;
        l[j++] = r[1];
        for(long i=2;i<=n;i++){
            r[i] = r[i-1] + r[i];
            l[j++] = r[i];
        }
        bool status = true;
        sort(l,l+n);
        for(long i=0;i<n;i++){
            if(l[i] != h[i]){
                status = false;
                break;
            }
        }

        if(status){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}