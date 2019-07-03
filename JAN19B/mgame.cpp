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

        long long int n,p,m;
        cin>>n>>p;
        long long int n1=0LL,n2=0LL,n3=0LL,n4=0LL;
//        m=(n)%((long long int)(n/2)+1);
        if(n%2==0){
            m=n/2 - 1;
        }
        else{
            m=n/2;
        }
        if(m==0){
            if(n==1){
                n1=p*p;
                n2=(p-n)*p;
                n3=(p-n)*(p-n);
                n4=(p-n)*(p-n)*(p-n);
                cout<<n1+n2+n3+n4<<endl;
                continue;
            }
            if(n==2){
                n1=p*p;
                n2=(p-n)*p;
                n3=(p-n)*(p-n);
                n4=(p-n)*(p-n)*(p-n);
//                if(p==2)
//                    cout<<
//                else
//                    cout<<(2*(n1+n2+n3))+1<<endl;
                cout<<2*(n1+n2+n3)+n4<<endl;
                continue;
            }

        }
/*        m=0LL;
        for(long long int i=1;i<=n;i++){
            if(n%i > m)
                m=n%i;
        }
*/
        if(n>=p){
            cout<<(p-m)*(p-m)<<endl;
        }
        if(n<p){
            n1=(p-m)*(p-m);
            n2=(p-n)*(p-m);
            n3=(p-n)*(p-n);
            cout<<n1+n2+n3<<endl;
        }


    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

