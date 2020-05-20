#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[10007], b[10007];
ll n, k;
// ll ans1 = LLONG_MAX, ans2 = LLONG_MAX;
ll fun(ll i, ll s, ll st){
	cout << i << " " << s << " " << st << "\n";
	if(s > k){
		return 0;
	}
	if(i >= n){
		return s;
	}
	ll ans1 = LLONG_MAX, ans2 = LLONG_MAX;
	if(st == 0){
		if(s + a[i-1] <= k){
			ans1 = min(ans1, fun(i+1, s+a[i-1], 0));
		}
		if(s + a[i-1] + b[i-1] <= k){
			ans1 = min(ans2, fun(i+1, s+a[i-1]+b[i-1], 1));
		}
	}
	if(st == 1){
		if(s + b[i-1] <= k){
			ans1 = min(ans1, fun(i+1, s+b[i-1], 1));
		}
		if(s + a[i-1] + b[i-1] <= k){
			ans1 = min(ans2, fun(i+1, s+a[i-1]+b[i-1], 0));
		}
	}
	cout << ans1 << " " << ans2 << "\n";
	return min(ans1, ans2);
}
int main() {
	// your code goes here
	cin >> n >> k;
	for(ll i=0;i<n;i++){
		cin >> a[i];
	}
	for(ll i=0;i<n;i++){
		cin >> b[i];
	}
	cout << min(fun(1, 0, a[0]), fun(1, 0, b[0]));
	// fun(0, 0);
	return 0;
}