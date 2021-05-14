/*
    Stay motivated and keep working hard
*/
// Logic : Kadane's algorithm on + - + - and - + - + type array of absolute differences
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
    ll a[n+7];
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll x[n+7] = {0}, y[n+7] = {0};
    for(ll i=1;i<n;i++){
        x[i] = abs(a[i] - a[i+1]);
        if(i % 2){
            y[i] = -x[i];
        }
        else{
            y[i] = x[i];
            x[i] = -x[i];
        }
    }
    // for(ll i=1;i<n;i++){
    //     cout << x[i] << " " << y[i] << "\n";
    // }
    ll max_so_far = INT_MIN, min_ending_here = 0;
    for(ll i=1;i<n;i++){
        min_ending_here += x[i];
        if(max_so_far < min_ending_here){
            max_so_far = min_ending_here;
        }
        if(min_ending_here < 0){
            min_ending_here = 0;
        }
    }
    min_ending_here = 0;
    for(ll i=1;i<n;i++){
        min_ending_here += y[i];
        if(max_so_far < min_ending_here){
            max_so_far = min_ending_here;
        }
        if(min_ending_here < 0){
            min_ending_here = 0;
        }
    }
    cout << max_so_far << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}