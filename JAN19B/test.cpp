#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int t;
cin>>t;
while(t--)
{int n,p,max=0,i,j,k,l;
cin>>n>>p;
int count[n];
int c=0;
memset (count,0,sizeof(count));
for(i=1;i<=p;i++){
    for(j=1;j<=p;j++){
        for(k=1;k<=p;k++){
            if((((n%i)%j)%k)%n > max){
                max=(((n%i)%j)%k)%n;
            }
        }
    }
}
for(i=1;i<=p;i++){
    for(j=1;j<=p;j++){
        for(k=1;k<=p;k++){
            if((((n%i)%j)%k)%n == max){
                c++;
                cout<<"<"<<i<<","<<j<<","<<k<<">"<<endl;
            }
        }
    }
}

cout<<c<<endl;
cout<<"MAX: "<<max<<endl;
}
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
return 0;
}
