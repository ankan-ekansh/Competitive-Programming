#include<bits/stdc++.h>
#define M 64
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
        if(n%2 != 0){
            cout<<n<<"\n";
        }
        else{
            int temp=n;
            int k=0;
            int bin[32];
            while(temp>0){
                int d = temp%2;
                bin[k++]=d;
                temp = temp/2;
            }
            int no=0;
            for(int i=k-1,c=0;i>=0;i--){
                no = no + (1<<c++)*bin[i];
            }
            cout<<no<<"\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        //cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}