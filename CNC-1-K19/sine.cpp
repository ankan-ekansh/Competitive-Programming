#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif

    float x,ans=0.0;
    scanf("%f",&x);
    x=(3.14159*x)/(float)180;
    int n=1000000;
    int i,f=1,c;
    for(i=1,c=3;i<=n && f<=1000000;i++,f=f*i){
    	if(i%2 !=0){
    		ans+=((float)pow(-1,++c)*(float)pow(x,i))/(float)f;
    	}
    }
    printf("sin(%f) is approximately %f\n",x,ans);
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


