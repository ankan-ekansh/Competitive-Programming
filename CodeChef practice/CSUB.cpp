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
    int t;
    cin>>t;
    while(t--){
 
        long long n;
        cin>>n;
        long long c = 0;
        string s;
        cin>>s;
        for(long long i=0;i<n;i++){
            if(s[i] == '1'){
                c++;
            }
        }
        cout<<(c*(c+1))/2<<"\n";    //finding pairs of 1s
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}