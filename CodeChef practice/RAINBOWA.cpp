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
 
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool flag = false;
        int s=1;
        int l=0,r=0;
        int b=0,e=n-1;
        while(s<7){
            if(a[b] != s || a[e] != s){
                flag = true;
                break;
            }
            l=0,r=0;
            while(b<n && a[b]==s){
                r++;
                b++;
            }
            while(e>=0 && a[e]==s){
                l++;
                e--;
            }
            if(l!=r){
                flag = true;
                break;
            }
            s++;
        }
        if(s == 7 && b<=e){
            for(int i=b;i<=e;i++){
                if(a[i]!=s){
                    flag = true;
                    break;
                }
            }
        }
        else{
            flag = true;
        }
        if(!flag){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}