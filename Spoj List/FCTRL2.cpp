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
 
        int n;
        cin>>n;
        int64_t a[10000]={0};
        int k=1;
        a[0]=1;
        int carry = 0;
        for(int i=1;i<=n;i++){
            // for(int j=0;j<=k;j++){
            //     a[j]=a[j]*i;
            // }
            // int j=0;
            // int64_t temp = a[j];
            // for(j=0;j<=k;j++){
            //     while(temp!=0){
            //         a[j]=a[j]%10;
            //         a[j+1]=a[j+1] + temp/10;
            //         temp = temp/10;
            //         k++;
            //     }
            // }
            for(int j=0;j<k;j++){
                int prod = a[j]*i + carry;
                a[j] = prod % 10;
                carry = prod / 10;
            }
            while(carry){
                a[k]=carry%10;
                carry/=10;
                k++;
            }
        }

        for(int j=k-1;j>=0;j--){
            cout<<a[j];
        }

        cout<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}