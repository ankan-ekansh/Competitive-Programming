#include<bits/stdc++.h>
using namespace std;
int main(){
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "rt", stdin);
//        freopen("output.txt", "wt", stdout);
//    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++){
//        cout<<n<<"%"<<i<<" = "<<n%i<<endl;
        v.push_back(n%i);
    }
    sort(v.begin(),v.end(),greater<int>());
    cout<<v[0];


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

