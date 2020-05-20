#include<bits/stdc++.h>
using namespace std;
int cmp(const void* ap, const void* bp){ 
    const int* a = (int*)ap; 
    const int* b = (int*)bp; 
    if (*a < *b) 
        return -1; 
    else if (*a > *b) 
        return 1; 
    else
        return 0; 
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
    cin >> n;
    int a[101], p[101], ns[101], ps[101];
    memset(a, 0, sizeof(a));
    memset(p, 0, sizeof(p));
    memset(ns, 0, sizeof(ns));
    memset(ps, 0, sizeof(ps));
    int l=INT_MAX, h=INT_MIN;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        p[x]++;
        l=min(l,x);
        h=max(h,x);
    }
    // cout << l << " " << h << "\n";
    ns[l]=p[l];
    ps[l]=l;
    a[0]=l;
    int k=1;
    for(int i=l+1;i<=h;i++){
        if(p[i]){
            a[k++]=i;
        }
        ns[i]=ns[i-1]+p[i];
        if(p[i]){
            ps[i]=ps[i-1]+i*p[i];
        }
        else{
            ps[i]=ps[i-1];
        }
    }
    // for(int i=l;i<=h;i++){
    //     cout << i << " : " << ns[i] << " " << ps[i] << "\n";
    // }
    
    // for(int i=0;i<k;i++){
    //     cout << a[i] << "\n";
    // }

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        auto i = lower_bound(a, a+k, x);
        if(i == a+k){
            cout << ns[h] << " " << ps[h] << "\n";
        }
        else{
            // cout << i-a+1 << "\n";
            cout << ns[i-a+1] << " " << ps[i-a+1] << "\n";
        }
    }

    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}