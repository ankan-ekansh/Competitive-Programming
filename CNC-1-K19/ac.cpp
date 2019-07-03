#include<bits/stdc++.h>
using namespace std;
#define ll long long
int p[1000001];
void sieve()
{
    for(ll i=2;i<=1000000;i++)
        p[i]=1;
    for(ll i=2;i<=1000000;i++)
    {
        if(p[i]==0)
            continue;
        for(ll j=2*i;j<=1000000;j+=i)
        {
            p[j]=0;
        }
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t;
    sieve();
    for(ll i=1;i<=1000000;i++)
    {
        if(p[i])
            p[i]=__builtin_popcount(i)+p[i-1];
        else
            p[i]=p[i-1];
    }#include<bits/stdc++.h>
    using namespace std;
    
    int main(){
        #ifndef ONLINE_JUDGE
            freopen("input.txt", "rt", stdin);
            freopen("output.txt", "wt", stdout);
        #endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    
        int t;
        cin>>t;
        while(t--){
    
    
    
        }
        #ifndef ONLINE_JUDGE
            cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
        #endif
        return 0;
    }
    
    
        
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<p[r]-p[l-1]<<"\n";
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}