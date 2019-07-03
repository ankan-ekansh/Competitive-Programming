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
    
    int n,q;
    cin>>n>>q;
    int a[n];
    int neg=0,pos=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==-1){
            neg++;
        }
        else{
            pos++;
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int nt = r-l+1;
        if(nt % 2 != 0){
            cout<<"0\n";
        }
        else{
            if(neg>=nt/2 && pos>=nt/2){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}