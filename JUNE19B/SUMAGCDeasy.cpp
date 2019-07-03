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
        sort(a.begin(),a.end(),greater<int>());
        vector<int>::iterator it = unique(a.begin(), a.end());
        a.resize(distance(a.begin(), it));
        if(a.size() == 1){
            cout<<2*a[0]<<"\n";
            continue;
        }
        vector<int>::iterator it1 = a.begin();
        int s1=*it1;
        int s2=*(++it1);
        int s3=*it1;
        for(;it1!=a.end();it1++){
            s3=__gcd(s3, *it1);
        }
        cout<<max(s1 + __gcd(s2, s3), s2 + __gcd(s1, s3))<<"\n";
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}