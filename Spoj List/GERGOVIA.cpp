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
            ll a[n];
            ll cost = 0;
            queue<pair<ll, ll>> neg,pos;
            for(ll i=0;i<n;i++){
                cin>>a[i];
                if(a[i] < 0){
                    neg.push(make_pair(a[i], i));
                }
                if(a[i] > 0){
                    pos.push(make_pair(a[i], i));
                }
            }
            while(!neg.empty()){
                ll s = neg.front().first;
                ll sp = neg.front().second;
                ll b = pos.front().first;
                ll bp = pos.front().second;
                if(abs(s) == abs(b)){
                    cost+=(abs(s) * abs(sp-bp));
                    neg.pop();
                    pos.pop();
                }
                else if(abs(s) > abs(b)){
                    cost+=(abs(b) * abs(bp-sp));
                    neg.front().first = b+s;
                    pos.pop();
                }
                else{
                    cost+=(abs(s) * abs(bp-sp));
                    pos.front().first = b+s;
                    neg.pop();
                }
            }
            cout<<cost<<"\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}