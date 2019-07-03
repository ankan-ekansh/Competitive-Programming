#include<bits/stdc++.h>
using namespace std;
int l;
string s,t;
int dp[10050][10050];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //int l;
    cin>>l;
    //string s,t;
    cin>>s>>t;
    //int dp[l+1][l+1]={0};
    int max = 0;
    int lastposi = 0, lastposj = 0;
    for(int i=1;i<=l;i++){
        for(int j=1;j<=l;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j]=dp[i-1][j-1] + 1;
                if(dp[i][j] > max){
                    max = dp[i][j];
                    lastposi = i;
                    lastposj = j;
                }
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    // for(int i=1;i<=l;i++){
    //     for(int j=1;j<=l;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    //lastpos i is the ending of lcs in S and lastposj is the ending of lcs in T
    //cout<<lastposi<<" "<<lastposj<<"\n";
    //cout<<max<<"\n";
    if(lastposi == l){
        cout<<l-max<<"\n";
    }
    else{
        cout<<l<<"\n";
    }



    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}