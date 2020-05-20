#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll modularExponentiation(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modularExponentiation((x*x)%M,n/2,M);
    return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}
ll binaryExponentiation(ll x,ll n){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return binaryExponentiation(x*x,n/2);
    else
        return x*binaryExponentiation(x*x,(n-1)/2);
}
ll GCD(ll A, ll B){
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}
ll extended_GCD(ll a , ll b , ll &x , ll &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1 , y1;
    ll gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return gcd;
}
ll modinv(ll a , ll mod){
    ll x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}
ll modPrimeInverse(ll A,ll M){
    return modularExponentiation(A,M-2,M);
}
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
 
        ll n;
        cin >> n;
        ll a[n+7];
        // vector<ll> a(n);
        for(ll i=1;i<=n;i++){
            cin >> a[i];
        }
        ll pref[n+7] = {0}, suff[n+7] = {0};
        // vector<ll> pref(n+7), suff(n);
        for(ll i=1;i<=n;i++){
            pref[i] = pref[i-1] + a[i];
            suff[n-i+1] = suff[n-i+2] + a[n-i+1];
            // if(i == 0){
            //     pref[i] = a[i];
            // }
            // else{
            //     pref[i] = pref[i-1] + a[i];
            // }
        }
        // for(ll i=n-1;i>=0;i--){
        //     if(i == n-1){
        //         suff[i] = a[i];
        //     }
        //     else{
        //         suff[i] = suff[i+1] + a[i];
        //     }
        // }
        // for(ll i=0;i<n;i++){
        //     cout << pref[i] << " ";
        // }
        // cout << "\n";
        // for(ll i=0;i<n;i++){
        //     cout << suff[i] << " ";
        // }
        // cout << "\n";
        ll left = 0, right = n+1;
        ll turn = 0;
        ll prev_turn = 0;
        ll alice_eat = 0, bob_eat = 0;
        ll rounds = 0;
        while(left < right){
            // cout << prev_turn << "\n";
            if(!turn){
                // auto it = lower_bound(pref.begin()+left, pref.end(), pref[left]+prev_turn+1);
                // if(it - pref.begin() > right){
                //     alice_eat += pref[right] - pref[left];
                //     break;
                // }
                // ll eat = *it - pref[left];
                // alice_eat += eat;
                // prev_turn = eat;
                // left = it - pref.begin();
                // turn = 1 - turn;
                ll tmp = left;
                while(pref[tmp] - pref[left] <= prev_turn){
                    tmp++;
                }
                // cout << "Tmp is " << tmp << "\n";
                if(tmp >= right){
                    alice_eat += pref[right-1] - pref[left];
                    // cout << "Alice eats " << pref[right-1] - pref[left] << "\n";
                    if(pref[right-1] - pref[left] > 0)
                        rounds++;
                    break;
                }
                ll eat = pref[tmp] - pref[left];
                alice_eat += eat;
                prev_turn = eat;
                left = tmp;
                turn = 1 - turn;
                rounds++;
                // cout << "Alice eats " << eat << "\n";
                // cout << "Now left is " << left << "\n";
            }
            else{
                ll tmp = right;
                while(suff[tmp] - suff[right] <= prev_turn){
                    tmp--;
                }
                // cout << "Tmp is " << tmp << "\n";
                if(tmp <= left){
                    bob_eat += suff[left+1] - suff[right];
                    // cout << "Bob eats " << suff[left+1] - suff[right] << "\n";
                    if(suff[left+1] - suff[right] > 0)
                        rounds++;
                    break;
                }
                ll eat = suff[tmp] - suff[right];
                bob_eat += eat;
                prev_turn = eat;
                right = tmp;
                turn = 1 - turn;
                rounds++;
                // cout << "Bob eats " << eat << "\n";
                // cout << "Now right is " << right << "\n";
                // auto it = lower_bound(suff.rbegin(), suff.rend(), suff[left]+prev_turn+1);
                // if(it - suff.rbegin() < left){
                //     bob_eat += suff[left] - suff[right];
                //     break;
                // }
                // ll eat = *it - suff[right];
                // bob_eat += eat;
                // prev_turn = eat;
                // right = it - suff.rbegin();
                // turn = 1 - turn;
            }
        }
        cout << rounds << " ";
        cout << alice_eat << " " << bob_eat << "\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}