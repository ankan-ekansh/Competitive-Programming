#include<bits/stdc++.h>
using namespace std;
bool bsearch(int a[], int x, int n){
    int l = 0, h = n;
    while(l <= h){
        int mid = (l+h)/2;
        if(a[mid] > x){
            h = mid-1;
        }
        else if(a[mid] < x){
            l = mid + 1;
        }
        else{
            return true;
        }
    }
        return false;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        // cout<<a[i]<<"\n";
    }
    sort(a, a+n);
    long c = 0;
    for(int i=0;i<n;i++){
        if(bsearch(a, a[i] + k, n)){
            c++;
        }
    }
    cout<<c<<"\n";

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}