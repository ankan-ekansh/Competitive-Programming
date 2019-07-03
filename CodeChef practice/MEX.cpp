#include<bits/stdc++.h>
using namespace std;
bool a[200010];
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
        memset(a,0,sizeof(a));
        int n,k;
        cin>>n>>k;
        int c = k;
        //cout<<c<<"\n";
        int l=0,s=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[x]=true;
            if(x>l){
                l=x;
            }
        }
        for(int i=0;i<=l;i++){
            s=i;
            if(a[i]==false && c>0){
                s=i;
                a[i]=true;
                //cout<<"c: "<<c<<"\n";
                c--;
            }
            else if(a[i]==false && c==0){
                s=i;
                break;
            }
        }
        //cout<<"s="<<s<<"\n";
        while(c){
            while(a[s]){
                s++;
            }
            a[s]=true;
            c--;
        }
        // while(c){
        //     a[s]=true;
        //     s++;
        //     c--;
        // }
        // cout<<"c: "<<c<<"\n";
        // while(a[s]!=false){
        //     //a[s]=true;
        //     s++;
        // }
        // for(int i=0;i<=l;i++){
        //     if(a[i]){
        //         cout<<i<<" ";
        //     }
        // }
        //cout<<"\n";
        //cout<<s<<"\n";
        while(a[s]==true){
            s++;
        }
        cout<<s<<"\n";
        
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}