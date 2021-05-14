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

    ll n;
    cin >> n;
    long double a[n], b[n];
    long double sum = 0;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        sum += floor(a[i]);
        b[i] = floor(a[i]);
    }
    // cout << "Sum = " << sum << "\n";
    // cout << "Initial elements = ";
    // for(ll i=0;i<n;i++){
    //     cout << b[i] << " ";
    // }
    // cout << "\n";
    for(ll i=0;i<n;i++){
        // cout << i << " " << sum << "\n";
        if(fabs(sum) < 1e-9){
            break;
        }
        if(fabs(a[i] - floor(a[i])) > 1e-9){
            b[i] = b[i] + 1;
            sum += 1;
        }
    }
    // cout << "\n";
    for(ll i=0;i<n;i++){
        cout << b[i] << "\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}