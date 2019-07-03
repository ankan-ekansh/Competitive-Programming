#include<bits/stdc++.h>
using namespace std;
bool comp(int a, int b){
    return a > b;
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

    set<int, greater<int>> s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    if(s.size()<2){
        cout<<"0\n";
    }
    else{
        auto i = s.begin();
        auto j = s.begin();
        j++;
        cout<<(*j) % (*i)<<"\n";
    }

    // vector<int> s;
    // int f_max = 0, s_max = 0;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     s.push_back(x);
    //     if(x > f_max){
    //         f_max = x;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     if(s[i] > s_max && s[i] != f_max){
    //         s_max = s[i];
    //     }
    // }
    // cout<<s_max % f_max<<"\n";

    // sort(s.begin(), s.end(), comp);
    // unique(s.begin(),s.end());
    // auto i = s.begin();
    // auto j = s.begin();
    // j++;
    // cout<<(*j) % (*i)<<"\n";


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}