#include<bits/stdc++.h>
using namespace std;
int s(int n){
    int t = n;
    int sum = 0;
    while(t){
        sum+=(t%10);
        t/=10;
    }
    return sum;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int num = n;
    while(true){
        if(s(num) % 4 == 0){
            cout<<num<<"\n";
            break;
        }
        else{
            num++;
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}