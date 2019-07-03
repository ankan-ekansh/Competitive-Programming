
////// Accepted ///////

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
 
    int64_t n,s,q;
    cin>>n>>s>>q;
    int64_t a[27]={0};
    for(int64_t i=1;i<=26;i++){
        a[i]=a[i-1]+i;
        //cout<<a[i]<<" ";
    }
    //cout<<"\n";
    int64_t r = (n*s)%351;
    int64_t d = (n*s)/351;
    //cout<<d<<" "<<r<<"\n";
    while(q--){
        int64_t i,j;
        cin>>i>>j;
        int64_t nc = (i-1)*s + j;
        for(int64_t i=1;i<26;i++){
            if(nc>351){
                nc = nc%351;
            }
            if(nc % a[26] == 0){
                cout<<'z'<<"\n";
                break;
            }
            else if(nc<a[i+1] && nc>=a[i]){
                int x = i;
                //cout<<"i ="<<i<<"\n";
                int count = a[i];
                //cout<<"Count: "<<count<<"\n";
                int diff = nc - count;
                if(diff == 0){
                    cout<<(char)(x + 96)<<"\n";
                    break;
                }
                cout<<(char)((int)'a' + diff - 1)<<"\n";
                break;
            }
        }
    }
 
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}