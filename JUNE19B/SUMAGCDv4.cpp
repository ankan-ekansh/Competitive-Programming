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
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        vector<int>::iterator it = unique(a.begin(), a.begin()+n);
        a.resize(distance(a.begin(), it));
        int s = a.size();
        if(s == 1){
            cout<<2*a[0]<<"\n";
            continue;
        }
        int l = a[s-1];
        int sl = a[s-2];
        int h1 = l;
        int h2 = sl;
        for(int i=0;i<s-2;i++){
            if(h2 + __gcd(a[i], h1) > h1 + __gcd(a[i], h2)){
                h1 = __gcd(a[i], h1);
            }
            else if(h2 + __gcd(a[i], h1) > h1 + __gcd(a[i], h2)){
                h2 = __gcd(a[i], h2);
            }
            else{
                h2 = __gcd(a[i], h2);
            }
        }
        cout<<h1+h2<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}