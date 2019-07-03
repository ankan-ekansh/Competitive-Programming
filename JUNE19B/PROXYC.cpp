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
 
        int l;
        cin>>l;
        string s;
        cin>>s;
        int p=0;
        int proxy=0;
        for(int i=0;i<l;i++){
            if(s[i] == 'P'){
                p++;
            }
        }
        long double a = (long double)p/(long double)l;
        for(int i=0;i<l;i++){
            if((long double)p/(long double)l >= 0.75){
                break;
            }
            else{
                if(i != 0 && i != 1 && i != l-1 && i != l-2){
                    if(s[i] == 'A'){
                        if((s[i-1] == 'P' || s[i-2] == 'P') && (s[i+1] == 'P' || s[i+2] == 'P')){
                            p++;
                            proxy++;
                        }
                    }
                }
            }
        }
        if((long double)p/(long double)l >= 0.75){
            cout<<proxy<<"\n";
        }
        else{
            cout<<"-1\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}