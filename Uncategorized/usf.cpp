#include<bits/stdc++.h>
using namespace std;
int primes[100050];
int a[100050];
bool b[100050];
int sieve(int n){
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*2;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    int k=0;
    for(int p=2;p<=n;p++)
        if(prime[p])
            primes[k++]=p;
    return k;
}
int largest(int arr[], int n){
    return *max_element(arr, arr+n);
}
bool comp(int a,int b){
    return a>b;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int maximum = largest(a,n);
        int k = sieve(maximum);
        int np=0;
        int ls=0;
        vector<int> un;
        memset(b, true, sizeof(b));
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                if(a[j]%primes[i] != 0){
                    b[j]=false;
                }
            }
            for(int j=0;j<n;j++){
                if(b[j]){
                    ls++;
                }
            }
            un.push_back(++np*ls);
            ls=0;
        }
        sort(un.begin(),un.end(),comp);
        cout<<un[0]<<"\n";
        un.clear();
    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

