#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "rt", stdin);
//        freopen("output.txt", "wt", stdout);
//    #endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);


    int t;
    cin>>t;
    vector<lli> v;
    srand(time(0));
    while(t--){

        lli n,i,j,k,p;

        n = rand()%(1000000-1 + 1) + 1;
        p = rand()%(1000000-n + 1) + n;
//        n = 71;
//        p = 71;
        //M=N%([N/2]+1), then take permutation of lets say i index and the other two are from M+1 to P
        //also make sure that during permutation, n%i does not give 0
//        i = rand()%(p-1 + 1) + 1;
//        j = rand()%(p-1 + 1) + 1;
//        k = rand()%(p-1 + 1) + 1;

//        lli x = (((n%i)%j)%k)%n;
//        cout<<"n "<<n<<" p "<<p<<" i "<<i<<" j "<<j<<" k "<<k<<" x: "<<x<<endl;
        cout<<n<<" "<<p<<endl;
//        v.push_back(x);
    }
//    sort(v.begin(),v.end());
//    for(auto i=v.begin();i!=v.end();i++)
//        cout<<*i<<endl;


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

