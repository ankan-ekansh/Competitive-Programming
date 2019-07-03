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
 
        int64_t a,b;
        cin>>a>>b;
        int64_t temp = a;
        bool flag = false;
        vector<int64_t> v;
        int64_t c=0;
        while(temp>0){
            if(temp%b >= 2){
                flag = true;
                break;
            }
            else if(temp%b == 1){
                v.push_back(c);
            }
            temp/=b;
            c++;
        }
        if(flag == true){
            cout<<"NO";
        }
        else{
            cout<<"YES ";
            cout<<v.size()<<"\n";
        // int64_t x=0;
            for(int64_t i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            //x+=(int64_t)pow(b,v[i]);
            }
        }
        cout<<"\n";
        //cout<<x<<"\n";

 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}