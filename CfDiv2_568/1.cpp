#include<bits/stdc++.h>
using namespace std;
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "rt", stdin);
    //     freopen("output.txt", "wt", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

 
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int arr[3]={a, b, c};
        sort(arr, arr+3);
        int x = arr[0];
        int y = arr[1];
        int z = arr[2];

        if(x != y && y != z){
            int ans = 0;
            if(y-x < d){
                ans+=(x-(y-d));
            }
            if(z-y < d){
                ans+=((y+d)-z);
            }
            cout<<ans<<"\n";
        }
        else if(x == y || y == z){
            if(x == y){
                int ans = 0;
                if(z-y < d){
                    ans+=((y+d)-z);
                }
                ans+=d;
                cout<<ans<<"\n";
            }
            else if(y == z){
                int ans = 0;
                if(y-x < d){
                    ans+=(x-(y-d));
                }
                ans+=d;
                cout<<ans<<"\n";
            }
        }
 
    // #ifndef ONLINE_JUDGE
    //     cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}