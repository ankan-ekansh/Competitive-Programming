#include<bits/stdc++.h>
using namespace std;
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "rt", stdin);
    //     freopen("output.txt", "wt", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n,m;
    cin>>n>>m;
    //long long a[n];
    vector<long long> a;
    long long s[n]={0};
    vector<long long> b;
    long long temp;
    cin>>temp;
    a.push_back(temp);
    s[0]=a[0];
    for(long long i=1;i<n;i++){
        long long x;
        cin>>x;
        a.push_back(x);
        s[i]=s[i-1]+a[i];
    }
    for(long long i=0;i<n;i++){
        if(i==0 && a[i] < m){
            cout<<"0 ";
        }
        else{
            if(s[i]<=m){
                cout<<"0 ";
            }
            else{
                b.clear();
                copy(a.begin(),a.begin()+i,back_inserter(b));
                sort(b.begin(),b.end(),greater<long long>());
                // cout<<"\n"<<i<<"\n";
                // for(auto j=b.begin();j!=b.end();j++){
                //     cout<<*j<<" ";
                // }
                // cout<<"\n";
                int no = 1;
                long long reduce = 0;
                for(auto j=b.begin();j!=b.end();j++){
                    reduce+=(*j);
                    // if(s[i-1] - reduce <= a[i]){
                    if(s[i-1] - reduce + a[i] <= m){
                        break;
                    }
                    no++;
                }
                cout<<no<<" ";
            }
        }
    }

    // #ifndef ONLINE_JUDGE
    //     cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    // #endif
    return 0;
}