#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int a;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<t;i++){
        cout<<v[i]<<endl;
    }

}
