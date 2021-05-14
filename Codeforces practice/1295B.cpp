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
        
       ll n, x;
       cin >> n >> x;
       string s;
       cin >> s;
       ll bal[n+7] = {0};
       for(ll i=0;i<n;i++){
           if(i == 0){
               bal[i] = (s[i] == '0' ? 1 : -1);
           }
           else{
               bal[i] = bal[i-1] + (s[i] == '0' ? 1 : -1);
           }
       }
        //    for(ll i=0;i<n;i++){
        //        cout << bal[i] << " ";
        //    }
        ll ans = 0;
        if(x == 0){
            ans = 1;
        }
        if(bal[n-1] == 0){
            // cout << "-1\n";
            // continue;
            bool flag = false;
            for(ll i=0;i<n;i++){
                if(bal[i] == x){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cout << "-1\n";
                continue;
            }
            else{
                cout << "0\n";
                continue;
            }
        }
        else{
            for(ll i=0;i<n;i++){
                ll a = x - bal[i];
                ll b = bal[n-1];
                // cout << a << "/" << b << " " << a % b << "\n";
                if(a >= 0 && b > 0 || a <= 0 && b < 0){
                    if((a % b) == 0){
                        ans++;
                    }
                }
            }
            cout << ans << "\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}