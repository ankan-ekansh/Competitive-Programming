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
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        size_t one = -1, zero = n;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                one = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                zero = i;
                break;
            }
        }
        if(one == -1 || zero == n){
            cout << s << "\n";
            continue;
        }
        if(one > zero){
            cout << s << "\n";
            continue;
        }
        else{
            string ans;
            string s1 = s.substr(0, one);
            string s2 = s.substr(zero+1);
            // cout << s1 << " " << s2 << "\n";
            ans = s1 + '0' + s2;
            cout << ans << "\n";
        }
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}