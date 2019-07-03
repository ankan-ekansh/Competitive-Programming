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

    long long n;
    cin>>n;
    long long a[n];
    long long b[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    set<long long> s;
    s.insert(a[1]-a[0]);
    int s1 = 1;
    vector<int> v;
    int pos = 0;
    for(long long i=1;i<n-1;i++){
        s.insert(a[i+1] - a[i]);
        if(s.size() > s1){
            v.push_back(a[i-1]);
            v.push_back(a[i]);
            v.push_back(a[i+1]);
            pos = i;
            break;
        }
    }
    if(s.size() == 1){
        cout<<"1\n";
    }
    else{

    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}