/*
    Stay motivated and keep working hard
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
        ll n, cx;
        cin >> n >> cx;
        // ll ans = LLONG_MAX;
        bool flag = false;
        ll maxd = LLONG_MIN, maxdiff = LLONG_MIN;
        for(ll i=0;i<n;i++){
            ll d, h;
            cin >> d >> h;
            maxd = max(maxd, d);
            maxdiff = max(maxdiff, d-h);
        }
        ll turns = 1;
        cx -= maxd;     //deal max damage in final blow such that it cant regenerate which counts towards minimizing turns
        if(cx > 0){
            if(maxdiff <= 0){
                turns = -1;
            }
            else{
                turns += cx/maxdiff;
                if(cx % maxdiff){
                    turns++;
                }
            }
        }
        cout << turns << "\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}