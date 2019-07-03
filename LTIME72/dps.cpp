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
 
        int a[123]={0};
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            a[c]++;
        }
        // int even = 0, odd = 0;
        // for(int i=97;i<=122;i++){
            //cout<<a[i]<<"\n";
            // if(a[i] != 0 && a[i] % 2 == 0){
            //     even++;
            // }
            // else if(a[i] != 0 && a[i] % 2 != 0){
            //     odd++;
            // }

            // if(a[i]){
            //     cout<<a[i]<<" ";
            // }
        // }
        //cout<<"\n";
        //cout<<even<<" "<<odd<<"\n";
        if(s.length() % 2 != 0){
            int o = 0, e = 0;
            for(int i=97;i<=122;i++){
                if(a[i] % 2 == 0){
                    e++;
                }
                else{
                    o++;
                }
            }
            //cout<<o<<"\n";
            if(o == 3 || o == 1){
                cout<<"DPS\n";
            }
            else{
                cout<<"!DPS\n";
            }
        }
        else{
            int o = 0, e = 0;
            for(int i=97;i<=122;i++){
                if(a[i] % 2 == 0){
                    e++;
                }
                else{
                    o++;
                }
            }
            if(o == 2){
                cout<<"DPS\n";
            }
            else{
                cout<<"!DPS\n";
            }
        }
        
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}