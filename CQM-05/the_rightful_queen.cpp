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
    
    int n;
    cin>>n;
    int a[n];
    int neg=0,pos=0,zero=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            neg++;
        }
        else if(a[i]>0){
            pos++;
        }
        else{
            zero++;
        }
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    if(neg!=0 && pos==0){
        int cd=a[n-1];
        for(int i=n-2;i>=0;i--){
            cd-=a[i];
        }
        cout<<cd<<"\n";
    }
    else if(neg==0 && pos!=0){
        int cd=a[0];
        for(int i=1;i<n;i++){
            cd-=a[i];
        }
        cout<<abs(cd)<<"\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}