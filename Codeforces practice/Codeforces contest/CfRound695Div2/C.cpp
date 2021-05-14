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
    
    ll n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    ll a[n1], b[n2], c[n3];
    for(ll i=0;i<n1;i++){
        cin >> a[i];
    }
    for(ll i=0;i<n2;i++){
        cin >> b[i];
    }
    for(ll i=0;i<n3;i++){
        cin >> c[i];
    }
    sort(a,a+n1);
    sort(b,b+n2);
    sort(c,c+n3);
    ll sum1, sum2, sum3, sum;
    sum = sum1 = sum2 = sum3 = 0;
    for(ll i=0;i<n1;i++){
        sum1+=a[i];
    }
    for(ll i=0;i<n2;i++){
        sum2+=b[i];
    }
    for(ll i=0;i<n3;i++){
        sum3+=c[i];
    }
    sum = sum1 + sum2 + sum3;
    ll ans = max({sum-2*(a[0]+b[0]), sum-2*(b[0]+c[0]), sum-2*(c[0]+a[0]), sum-2*sum1, sum-2*sum2, sum-2*sum3});
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}