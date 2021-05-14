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
    
    string s;
    cin >> s;
    ll ansEven = 0, ansOdd = 0;
    ll even[2], odd[2];
    even[0] = even[1] = odd[0] = odd[1] = 0;
    for(ll i=0;i<s.length();i++){
        ansOdd++;
        if(i % 2){
            ansOdd += odd[s[i] - 'a'];
            ansEven += even[s[i] - 'a'];
            odd[s[i] - 'a']++;
        }
        else{
            ansOdd += even[s[i] - 'a'];
            ansEven += odd[s[i] - 'a'];
            even[s[i] - 'a']++;
        }
    }
    cout << ansEven << " " << ansOdd << "\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}