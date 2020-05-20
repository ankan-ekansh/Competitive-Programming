#include<bits/stdc++.h>
using namespace std;
map<long, long> m;
bool is_odd(long x){
    if(x % 2 == 0){
        m[x]=0;
        m[x/2]++;
        return is_odd(x/2);
    }
    else{
        return true;
    }
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
 
        long n;
        cin >> n;
        long a[n];
        for(long i=0;i<n;i++){
            cin >> a[i];
            m[a[i]]++;
        }
        // for(long i=0;i<n;i++){
        //     int c = 0;
        //     cout << is_odd(a[i],c) << " ";
        // }
        // cout << "\n";
        // for(auto i=m.begin();i!=m.end();i++){
        //     cout << (*i).first << ": " << (*i).second << "\n";
        // }
        // cout << "\n";
        int c = 0;
        for(auto i=m.rbegin();i!=m.rend();i++){
            long x = (*i).first;
            if(x % 2 == 0 && m[x]!=0){
                c++;
                m[x/2]+=m[x];
                m[x]=0;
            }
        }
        cout << c << "\n";
        m.clear();
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}