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
    int b[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    int l=0, r=0;
    sort(b,b+n);
    for(int i=0;i<n-1;i++){
        if(a[i] > a[i+1]){
            l = i;
            break;
        }
    }
    for(int i=n-1;i>=1;i--){
        if(a[i] < a[i-1]){
            r = i;
            break;
        }
    }
    int i=0;
    bool flag = true;
    for(i=0;i<l;i++){
        if(a[i] != b[i]){
            flag = false;
            break;
        }
    }
    for(int j=r;j>=l;j--,i++){
        if(a[j] != b[i]){
            flag = false;
            break;
        }
    }
    for(;i<n;i++){
        if(a[i] != b[i]){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "yes\n";
        cout << l+1 << " " << r+1 << "\n";
    }
    else{
        cout << "no\n";
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}