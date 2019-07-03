#include<bits/stdc++.h>
using namespace std;
bool vow(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    else{
        return false;
    }
}
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
 
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ct = 0;
        //cout<<s<<"\n";
        if(n == 1){
            cout<<"0\n";
            continue;
        }
        for(int i=0;i<n-1;i++){
            if(!(vow(s[i])) && vow(s[i+1])){
                ct++;
            }
        }
        cout<<ct<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}