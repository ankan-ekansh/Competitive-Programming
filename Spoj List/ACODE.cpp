#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    while(s[0]!='0'){
        // string s;
        // cin >> s;
        // if(stoll(s) == 0){
        //     exit(0);
        // }
        long long n = s.length();
        long long dp[5007];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(long long i=1;i<n;i++){
            if((s[i]-'0') != 0){
                dp[i]=dp[i-1];
            }
            long long t = (10*(s[i-1]-'0')) + (s[i]-'0');
            if(t>=10 && t<=26){
                if(i==1){
                    dp[i]+=1;
                }
                else{
                    dp[i]+=dp[i-2];
                }
            }
        }
        cout << dp[n-1] << "\n";
        cin >> s;
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}