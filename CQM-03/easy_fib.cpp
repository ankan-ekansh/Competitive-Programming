#include<bits/stdc++.h>
using namespace std;
vector<int64_t> a;
int64_t p(int64_t k){
    int64_t f = 1;
    for(int64_t i=1;i<=k;i++){
        f = f*2;
    }
    return f;
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
    a.resize(61);
    a[0]=0;
    a[1]=1;
    //cout<<a[0]<<" "<<a[1]<<" ";
    for(int i=2;i<60;i++){
        a[i]=(a[i-1]%10 + a[i-2]%10)%10;
        //if(i==60){
        //    cout<<"\n";
        //}
        //cout<<a[i]<<" ";
    }
    //cout<<"\n";
    //cout<<a[62]<<" "<<a[62%60]<<"\n";
    while(t--){
 
        // int64_t x;
        // cin>>x;
        // x=x%60;
        // int64_t c=0;
        // while(x>0){
        //     c+=x/2;
        //     x/=2;
        // }
        // cout<<c<<"\n";

        int64_t n;
        cin>>n;
        int64_t x = n;
        int64_t c = 0;
        while(x>0){
            //cout<<x<<"\n";
            //cout<<c<<"\n";
            x/=2;
            c++;
        }
        //cout<<c<<"\n";
        //cout<<c%60<<"\n";
        //cout<<p(c-1)<<"\n";
        //cout<<a[ (2*p(c-1) - 1) % 60]<<"\n";
        //cout<<c-2<<"\n\n";
        cout<<a[ (int64_t)((int64_t)(2*(pow(2,c-2))) - 1) % 60]<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}