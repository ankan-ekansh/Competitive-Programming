#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007

inline ll mul(ll x, ll y, ll m)
{
    ll z = 1LL * x * y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll add(ll x, ll y, ll m)
{
    ll z = x + y;
    if (z >= m)
        z %= m;
    return z;
}
inline ll sub(ll x, ll y, ll m)
{
    ll z = x - y;
    if (z < 0)
        z += m;
    z %= m;
    return z;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ll t;
    cin >> t;
    ll modinv = 500000004;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a1 = k, ak = n + k - 1;
        ll ans = sub(a1, 1, mod);
        ll m;
        if ((a1 - 1) % (ak - a1))
            m = (a1 - 1) / (ak - a1) + 1;
        else
            m = (a1 - 1) / (ak - a1);
        ans = sub(ans, m, mod);
        ll k1 = mul(add(m, 1, mod), add(m, 2, mod), mod);
        k1 = mul(k1, modinv, mod);
        k1 = sub(k1, 1, mod);
        k1 = mul(k1, a1, mod);
        ll k2 = mul(add(m, 1, mod), m % mod, mod);
        k2 = mul(k2, modinv, mod);
        k2 = mul(k2, ak, mod);
        k1 = sub(k1, k2, mod);
        ans = add(ans, k1, mod);
        k1 = (m + 1) * a1, k2 = m * ak + 1;
        ans += abs(k1 - k2);
        cout << ans << "\n";
    }
    return 0;
}