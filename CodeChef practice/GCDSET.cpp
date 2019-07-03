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
 
        int64_t l, r, g;
        cin>>l>>r>>g;
        int64_t nm = r/g - l/g;
        if(l % g == 0){
            nm++;
        }
        //cout<<nm<<"\n";
        if(nm == 1){
            //cout<<"1st part\n";
            //if(g <= (r/g * g) && g >= (l/g * g)){
            if(r/g * g == g){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
        else{
            //cout<<"2nd part\n";
            cout<<nm<<"\n";
        }        
        // if(nm == 0){

        // }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}