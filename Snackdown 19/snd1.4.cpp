#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int i;
    int nt1,nt2;
    scanf("%d",&t);
    int days=0;
    while(t--){
        days=0;
        int n;
        scanf("%d",&n);
        int size;
        size=n*sizeof(int);
        int* a=(int*)calloc(n,sizeof(int));
        int* s=(int*)calloc(n,sizeof(int));
        for(i=0;i<n;i++){
            scanf("%d",(a+i));
            *(s+i)=0;
        }


        *s=1;
        nt1=1;
        nt2=1;
        for(i=0;i<nt1;i++){
            if(*(s+n-1)==1){
                break;
            }
            else{
                    nt2=nt2+(*(a+i));
                    if(nt2>n){
                        days++;
                        break;
                    }
                    else{

                            memset(s, 1, nt2*sizeof(int));
                    }
            }
            if(nt2>=n)
                break;
            if(i==(nt1-1)){

                nt1=nt2;
                days++;
                i=0;
            }



        }
    printf("%d\n",days);
    free(a);
    free(s);
    }
}


