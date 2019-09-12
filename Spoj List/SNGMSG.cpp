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
 
        string k,m;
        cin>>k;
        cin>>m;
        int j=0, order = 0;
        for(int i=0;i<m.size();i++){
            //cout<<(int)m[i]<<" "<<k[j]<<"\n";
            int a = m[i] - ( int(k[j]) - 48);
            if(a < 97){
                a = a + 122 - 96;
            }
            if(j == 0 && order == 1){
                order = 0;
                j=-1;
            }
            else if(j == (k.size()-1) && order == 0){
                order = 1;
                j=k.size();
            }
            if(order == 0){
                j++;
            }
            else if(order == 1){
                j--;
            }
            //cout<<a<<"\n";
            //cout<<"\n"<<(char)a<<"\n";
            cout<<(char)a;
        }
        cout<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}