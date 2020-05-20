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

    ll n, m;
    cin >> n >> m;
    ll p_in_team = n / m;
    ll rem_p = n % m;
    ll k_min = ((rem_p * (p_in_team + 1) * (p_in_team)) / 2 ) + ((m - rem_p)*(p_in_team)*(p_in_team - 1)) / 2;
    ll k_max = ((n - m + 1) * (n - m)) / 2;
    cout << k_min << " " << k_max << "\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}