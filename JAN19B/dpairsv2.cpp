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
    map<lli,lli> p,q;
    for(lli i=0;i<n;i++){
        cin>>a[i];
        p[a[i]]=i;
    }
    for(lli i=0;i<m;i++){
        cin>>b[i];
        q[b[i]]=i;
    }
    sort(a,a+n);
    sort(b,b+m);
    lli counter = n+m-1;
    for(lli i=0;i<m;i++){
        cout<<p[a[0]]<<" "<<q[b[i]]<<endl;

    }
//    cout<<endl;
    for(lli i=1;i<n;i++){
        cout<<p[a[i]]<<" "<<q[b[m-1]]<<endl;
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

