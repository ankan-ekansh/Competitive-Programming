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

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int l=0,r=0;
    int i=0;
    for(i=0;i<n;i++){
        if(a[i] > a[i+1]){
            l = i;
            break;
        }
    }
    for(i=l;i<n;i++){
        if(a[i] < a[i+1]){
            r = i;
            break;
        }
    }
    bool flag = true;
    for(int j=r;j<l;j++){
        if(a[j] > a[j-1]){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "yes\n" << l+1 << " " << r+1 << "\n";
    }
    else{
        cout << "no\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}