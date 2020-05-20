#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<ll, map<ll, ll>> m;
int main() {
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "rt", stdin);
        // freopen("output.txt", "wt", stdout);
    #endif
	// your code goes here
	int ans = 0;
	m[1][2] = 1;
    m[2][2] = 1, m[2][3] = 1;
    m[3][3] = 1;
    for(auto p : m[1]){
        m[2][p.first] += m[1][p.first];
    }
    for(auto p : m[2]){
        cout << p.first << " " << p.second << "\n";
    }
    cout << "\n";
    for(auto p : m[2]){
        m[3][p.first] += m[2][p.first];
    }
    for(auto p : m[3]){
        cout << p.first << " " << p.second << "\n";
    }
	// cout << ans << "\n";
	return 0;
}