#include<bits/stdc++.h>
#define ll long long
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

        ll n;
        cin>>n;
        if(!n){
            break;
        }
        else{
            ll x;
            ll cost = 0;
            cin>>x;
            for(ll i=1;i<n;i++){
                ll y;
                cin>>y;
                y+=x;
                cost+=abs(x);
                x=y;
            }
            cout<<cost<<"\n";
        }

    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}