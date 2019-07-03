#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int i;
    int nt1,nt2;
    cin>>t;
    int days=0;
    while(t--){
        days=0;
        int n;
        cin>>n;
        int size;
        size=n*sizeof(int);
        int* a=(int*)calloc(n,sizeof(int));
        bool* s=(bool*)calloc(n,sizeof(bool));
        for(i=0;i<n;i++){
            cin>>*(a+i);
            *(s+i)=false;
        }


        *s=true;
        nt1=1;
        nt2=1;
        while(*(s+n-1)!=true){
            for(i=0;i<nt1;i++){
                for(int j=nt2;j<nt2+*(a+i);j++){
                    *(s+j)=true;
                }
                 nt2=nt2+*(a+i);
            }
            nt1=nt2;
            days++;
        }
    cout<<days<<endl;;
    }
}


