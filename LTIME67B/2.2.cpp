#include<bits/stdc++.h>

using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int t,n,i,yb,mb,db,yc,mc,dc,q1,q2;
    long long d1,d2,age=0;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long int m[n+1],sm=0,s[n+1];
        s[0]=0;
        for(i=1;i<=n;i++)
        {
            cin >> m[i];
            sm+=m[i];
            s[i]=s[i-1]+m[i];
        }
        cin >> yb >> mb >> db;
        cin >> yc >> mc >> dc;
        d1=yb*sm + s[mb-1] + db;
        d2=yc*sm + s[mc-1] + dc;
        q1=yb/4;q2=yc/4;
        if(yb%4==0)
            q2=q2-1;
        age=d2-d1 + q2-q1 + 1;

        cout << age << endl;
       // cout << d1 << " " << d2;
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
