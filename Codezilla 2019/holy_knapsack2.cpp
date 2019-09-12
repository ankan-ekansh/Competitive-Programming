#include<bits/stdc++.h>
using namespace std;
int main(){
    long n, k;
    cin >> n >> k;
    vector<long> a(n);
    vector<long> b(n);
    for(long i=0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    if(b[0] <= k){
        cout << "0\n";
    }
    else{
        cout << k - b[0] << "\n";
    }

    
return 0;
}