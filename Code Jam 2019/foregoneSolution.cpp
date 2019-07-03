#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "rt", stdin);
        freopen("output1.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int cn = 0;
    while(t--){
 
        int64_t n;
        cin>>n;
        int64_t temp = n,a=0,count=0;
        while(temp>0){
            int x = temp % 10;
            if(x==4){
                a=a+(int64_t)(ceil(pow(10,count)));
                //a=a*10 + 1;
                //cout<<a<<"\n";
            }
            else if(x==8){
                a=a+2*(int64_t)(ceil(pow(10,count)));
            }
            else if(x==5){
                a=a+3*(int64_t)(ceil(pow(10,count)));
            }
            else if(x==9){
                a=a+2*(int64_t)(ceil(pow(10,count)));
            }
            temp = temp/10;
            ++count;
        }
        //a=a*(int64_t)(ceil(pow(10,count)))+1;
        if(a==0){
            if(n%2==0 && n%4==0){
                a=n/2 -1 ;
            }
            else{
                if(n+1 % 4 ==0)
                    a=(n+1)/2 -1;
                else{
                    a=1;
                }
            }
        }
        
       /*if(a==0){
           a=1;
       }
       */
        //a=a+(count*10)+1;
        cout<<"Case #"<<++cn<<": "<<a<<" "<<n-a<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}