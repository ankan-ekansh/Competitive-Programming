#include<bits/stdc++.h>
using namespace std;
uint64_t digitSum(uint64_t n){
    uint64_t temp = n,s=0;
    while(temp>0){
        s+=temp%10;
        temp/=10;
    }
    return s;
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
 
        uint64_t n,s=0;
        cin>>n;
        uint64_t temp = n;
        // while(temp>0){
        //     s += temp%10;
        //     temp/=10;
        // }
        s = digitSum(n);
        while(n%s!=0){
            if(n%s == 0){
                break;
            }
            ++n;
            s = digitSum(n);
            // if(n%10 == 9){
            //     s = s-8;
            // }
            // else
            // {
            //     s++;
            // }
            
        }
        cout<<n<<"\n";

    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}