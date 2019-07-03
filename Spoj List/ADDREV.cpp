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
 
        string s1,s2;
        cin>>s1>>s2;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        //cout<<s1<<" "<<s2<<"\n";
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        int sum = n1+n2;
        string s = to_string(sum);
        reverse(s.begin(),s.end());
        sum = stoi(s);
        cout<<sum<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}