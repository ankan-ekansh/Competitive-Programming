#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	int ans = 0;
	for(int i=0;i<n-2;i+=3){
		a[i]+=k;
		a[i+1]+=k;
		a[i+2]+=k;
		if(a[i] > 5 || a[i+1] > 5 || a[i+2] > 5){
			continue;
		}
		else{
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}