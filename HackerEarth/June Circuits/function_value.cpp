#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll power(ll a, ll b, ll m){
    if(b == 0){
        return 1;
    }
    if(b == 1){
        return a%m;
    }
    ll x = power(a, b/2, m);
    if(b % 2 == 0){
        return ((x%m)*(x%m))%m;
    }
    else{
        return ((((x%m)*(a%m))%m)*(x%m))%m;
    }
}
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y);
    if(g == 1){
        ll res = (x%m + m) % m; 
        return res;
    }
    else{
        return 0;
    }

}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        ll m;
        cin>>m;
        ll mod_inv_2 = modInverse(2, m);
        ll mod_inv_9 = modInverse(9, m);
        ll mod_inv_8 = modInverse(8, m);
        ll mod_inv_4 = modInverse(4, m);
        ll l, r;
        cin>>l>>r;
        ll n = 0, ne = 0, no = 0;
        n = r - l + 1;
        ll largest_even_pow_term = 0, first_odd = 0, smallest_even = 0;
        ll odd_sum = 0, even_sum = 0;
        if((l % 2 == 0) && (r % 2 == 0)){
            no = n/2;
            ne = n - no;
            largest_even_pow_term = power(3, (r/2)-1, m);
            first_odd = power(3, l/2, m);
            //if(l != 2)
                smallest_even = (((((power(-1, (l/2)-1, m) * (power(-3, (l/2)-1, m) - 1)%m)%m) * 3)%m) * mod_inv_4)%m;
            // if(l == 2){
            //     smallest_even = 0;
            // }
        }
        else if((l % 2 != 0) && (r % 2 != 0)){
            ne = n/2;
            no = n - ne;
            largest_even_pow_term = power(3, ((r-1)/2)-1, m);
            first_odd = power(3, (l-1)/2, m);
            //if(l != 1)
                smallest_even = (((((power(-1, ((l+1)/2)-1, m) * (power(-3, ((l+1)/2)-1, m) - 1)%m)%m) * 3)%m) * mod_inv_4)%m;
            // if(l == 1){
            //     smallest_even = 0;
            // }
        }
        else if((l % 2 != 0) && (r % 2 == 0)){
            no = n/2;
            ne = n - no;
            largest_even_pow_term = power(3, (r/2)-1, m);
            //cout<<largest_even_pow_term<<"\n";
            first_odd = power(3, (l-1)/2, m);
            //if(l != 1)
                smallest_even = (((((power(-1, ((l+1)/2)-1, m) * (power(-3, ((l+1)/2)-1, m) - 1)%m)%m) * 3)%m) * mod_inv_4)%m;
            // if(l == 1){
            //     smallest_even = 0;
            // }
            //cout<<smallest_even<<"\n";
        }
        else if((l % 2 == 0) && (r % 2 != 0)){
            no = n/2;
            ne = n - no;
            largest_even_pow_term = power(3, ((r-1)/2)-1, m);
            first_odd = power(3, l/2, m);
            //if(l != 2)
                smallest_even = (((((power(-1, (l/2)-1, m) * (power(-3, (l/2)-1, m) - 1)%m)%m) * 3)%m) * mod_inv_4)%m;
            // if(l == 2){
            //     smallest_even = 0;
            // }
        }
        odd_sum = (((first_odd * (power(3, no, m) - 1))%m)*(mod_inv_2 % m))%m;
        if(ne % 2 == 0){
            //cout<<largest_even_pow_term<<"\n";
            //even_sum = (((((largest_even_pow_term * (power(9, ne/2, m) - 1))%m) * (mod_inv_8 % m))%m) * (mod_inv_9 % m))%m;
            even_sum = (largest_even_pow_term * (((((power(9, ne/2, m) - 1) * mod_inv_8)%m)*mod_inv_9)%m))%m;
            cout<<even_sum<<"\n";
        }
        else{
            even_sum = (((((largest_even_pow_term * (power(9, ne/2, m) - 1))%m) * (mod_inv_8 % m))%m) * (mod_inv_9 % m))%m;
            even_sum = (even_sum + smallest_even)%m;
        }
        //cout<<ne<<"\n";
        // if(even_sum == 1){
        //     even_sum = 9;
        // }
        even_sum = (((2 * even_sum)%m) + (ne % m))%m;
        cout<<odd_sum<<" "<<even_sum<<"\n";
        cout<<((odd_sum%m) + (even_sum)%m)%m<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}