#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n], k=0;
        f(0,n)
        {
            cin>>a[i];
            if(a[i]==i+1)
                k++;
        }
        if(k==n)
        {
            cout<<"no\n";
            continue;
        }
        sort(a, a+n);
        k=0;
        f(0,n)
        {
            if(a[i]==i+1)
                k++;
        }
        if(k==n)
            cout<<"yes\n";
        else cout<<"no\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
