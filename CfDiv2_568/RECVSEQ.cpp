#include<bits/stdc++.h>
using namespace std;
void ans(int n,int a[]){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
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
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        set<int> dt;
        int d[n-1];
        d[0]=a[1]-a[0];
        dt.insert(d[0]);
        for(int i=1;i<n-1;i++){
            d[i]=a[i+1]-a[i];
            dt.insert(d[i]);
        }
        int min_diff = 0;
        int a1[n]={0};
        int a2[n]={0};
        while(!dt.empty()){
            //cout<<*(dt.begin())<<"\n";
            int cd = *(dt.begin());
            dt.erase(*(dt.begin()));
            //cout<<cd<<"\n";
            int diff = 0;
            //cout<<"a1 ";
            for(int i=0;i<n;i++){
                a1[i]=a[0]+(i*cd);
                //cout<<a1[i]<<" ";
                //cout<<a[i]<<" ";
                if(a1[i]!=a[i]){
                    diff++;
                }
            }
            //cout<<"\n";
            if(diff == 1){
                ans(n,a1);
                break;
            }
            else if(diff == 0){
                ans(n,a);
                break;
            }
            diff = 0;
            //cout<<"a2 ";
            a2[1]=a[1];
            a2[0]=a2[1]-cd;
            //cout<<a2[0]<<" "<<a2[1]<<" ";
            if(a2[0]!=a[0]){
                diff++;
            }
            if(a2[1]!=a[1]){
                diff++;
            }
            for(int i=2;i<n;i++){
                a2[i]=a2[0]+(i*cd);
                //cout<<a2[i]<<" ";
                if(a2[i]!=a[i]){
                    diff++;
                }
            }
            //cout<<"\n";
            if(diff == 1){
                ans(n,a2);
                break;
            }
            else if(diff == 0){
                ans(n,a);
                break;
            }
        }

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}