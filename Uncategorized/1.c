#include<stdio.h>
int main(){
	int n,rem;
	float k=0;
	scanf("%d",&n);
	rem=n%10;
	n=n-rem;
	k=(float)rem/10.0;
	printf("%d",(int)(n+k*10));
	return 0;
}
