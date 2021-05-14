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
    
    string s1, s2;
    cin >> s1 >> s2;
    ll n = s1.length(), m = s2.length();
    ll k = min(n, m);
    vector<ll> divisors;
    for(ll i=1;i*i<=k;i++){
        if(k % i == 0){
            divisors.push_back(i);
            if(i != (k/i)){
                divisors.push_back(k/i);
            }
        }
    }
    ll ans = 0;
    for(ll i=0;i<divisors.size();i++){
        if(n % divisors[i] == 0 && m % divisors[i] == 0){
            bool flag = true;
            ll left = 0, right = 0;
            while(left < n){
                if(right == divisors[i]){
                    right = 0;
                }
                if(s1[left] != s1[right]){
                    flag = false;
                    break;
                }
                left++;
                right++;
            }
            if(flag){
                ll left = 0, right = 0;
                while(left < m){
                    if(right == divisors[i]){
                        right = 0;
                    }
                    if(s2[left] != s1[right]){
                        flag = false;
                        break;
                    }
                    left++;
                    right++;
                }
            }
            if(flag){
                ans++;
            }
        }
    }
    cout << ans << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}