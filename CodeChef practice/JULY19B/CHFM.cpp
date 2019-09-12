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
    ll t;
    cin>>t;
    while(t--){
 
        ll n;
        cin>>n;
        ll a[n];
        ll sum = 0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(((sum/n)*n) != sum){
            cout<<"Impossible\n";
        }
        else{
            bool flag = false;
            for(ll i=0;i<n;i++){
                if(a[i] == (sum/n)){
                    flag = true;
                    cout<<i+1<<"\n";
                    break;
                }
            }
            if(!flag){
                cout<<"Impossible\n";
            }
        }

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}