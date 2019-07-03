#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lli n,m;
    cin>>n>>m;
    lli a[n],b[m];
    for(lli i=0;i<n;i++){
        cin>>a[i];
    }
    for(lli i=0;i<m;i++){
        cin>>b[i];
    }
    set<lli> s;
    lli t = n+m-1;
    {
        for(lli i=0;i<n;i++){
            for(lli j=m-1;j>=0;j--){
                lli temp = s.size();
                lli sum = a[i]+b[j];
                s.insert(sum);
                if(temp != s.size() && t>0){
                    cout<<i<<" "<<j<<endl;
                    t--;
                }
                if(!(t>0)){
                    exit(0);
                }
            }
        }
    }



    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

