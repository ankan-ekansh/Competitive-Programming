#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int s,t,a,b,m,n;
    vector<int> apples,oranges;
    cin>>s>>t;
    cin>>a>>b;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        apples.push_back(temp);
    }
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        oranges.push_back(temp);
    }
    vector<int> dapples,doranges;
    for(int i=0;i<m;i++){
        dapples.push_back(a+apples[i]);
    }
    for(int i=0;i<n;i++){
        doranges.push_back(b+oranges[i]);
    }
    dapples.push_back(s);
    dapples.push_back(t);
    dapples.push_back(a);
    dapples.push_back(b);
    doranges.push_back(s);
    doranges.push_back(t);
    doranges.push_back(a);
    doranges.push_back(b);
    sort(dapples.begin(),dapples.end());
    sort(doranges.begin(),doranges.end());
    auto la = lower_bound(dapples.begin(),dapples.end(),s);
    auto ra = upper_bound(dapples.begin(),dapples.end(),t);
    ra--;
    int napples = abs(ra-la-1);
    auto lo = lower_bound(doranges.begin(),doranges.end(),s);
    auto ro = upper_bound(doranges.begin(),doranges.end(),t);
    ro--;
    int noranges = abs(ro-lo-1);
    cout<<napples<<endl<<noranges<<endl;
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

