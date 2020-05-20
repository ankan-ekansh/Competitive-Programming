#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d, e, f;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    int s1, s2;
    s1 = min(a, d);
    s2 = min(b, min(c, d));
    int ans1 = 0, ans2 = 0;
    ans1=(s1*e) + (f * min(b, min(c, d-s1)));
    ans2=(s2*f) + (e * min(a, d-s2));
    cout << max(ans1, ans2) << "\n";
    // int ans = 0;
    // if((s1 * e) > (s2 * f)){
    //     ans+=(s1*e);
    //     a-=s1;
    //     d-=s1;
    //     ans+=(f * min(b, min(c, d)));
    // }
    // else{
    //     ans+=(s2*f);
    //     b-=s2;
    //     c-=s2;
    //     d-=s2;
    //     ans+=(e * min(a, d));
    // }
    // cout << ans << "\n";



    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}