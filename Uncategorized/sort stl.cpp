#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={1,9,3,2,6,5,4,8,7,0};
    sort(a,a+10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
