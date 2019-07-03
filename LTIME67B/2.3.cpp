#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    long long int t;
    cin>>t;
    while(t--){

        long long int n;
        cin>>n;
        long long int ndmw[n+1],ndiy=0,sdmw[n+1];       //ndmw: n of days month-wise; ndiy: n of days in year; sdmw: summation of days month-wise
        long long int days=0;
        sdmw[0]=0;
        ndmw[0]=0;
        for(long long int i=1;i<=n;i++){
            cin>>ndmw[i];
            ndiy+=ndmw[i];      //prefix sum of days in an year
            sdmw[i]=sdmw[i-1]+ndmw[i];      //prefix sum of days month-wise
        }
        long long int yb,mb,db,yc,mc,dc;
        cin>>yb>>mb>>db;
        cin>>yc>>mc>>dc;
        if(yb==yc && mb==mc && db==dc){
            cout<<"0"<<endl;
            continue;
        }
        long long int daystart = yb*ndiy + sdmw[mb-1] + db;     //days from starting till birth date
        long long int dayend = yc*ndiy + sdmw[mc-1] + dc;       //days from starting till current date
        long long int quo1 = yb/4;              //to adjust leap year cases between start and end years
        long long int quo2 = yc/4;
        quo2=((yb%4==0)?(quo2-1):quo2);         //if birth year is leap year then the extra day is counted twice from start so -1
        days = dayend - daystart + quo2 - quo1 +1;
        cout<<days<<endl;


    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

