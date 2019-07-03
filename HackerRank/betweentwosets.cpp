#include<bits/stdc++.h>
using namespace std;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
//    for(int i=0;i<n;i++){
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<m;i++){
//        cout<<b[i]<<" ";
//    }
//    cout<<endl;
    int l;
    l = b[0];
    for(int i=0;i<m;i++){
        if(l>b[i]){
            l=b[i];
        }
    }
//    cout<<l<<endl;
    vector<int> v;
    int flag;
    for(int i=1;i<=l;i++){
        for(int j=0;j<m;j++){
            if(b[j]%i==0){
                flag = 1;
                continue;
            }
            else{
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            v.push_back(i);
        }
    }
    int count = 0;
    flag = 0;
//    for(auto i=v.begin();i!=v.end();i++){
//        cout<<*i<<endl;
//    }
    for(auto i=v.begin();i!=v.end();i++){
        for(int j=0;j<n;j++){
            if(*i % a[j] == 0){
                flag = 1;
                continue;
            }
            else{
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}

