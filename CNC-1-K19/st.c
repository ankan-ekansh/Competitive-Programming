#include<stdio.h>
#include<string.h>
int main(){
	#ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif

        char ch[5];
        fgets(ch,7,stdin);
        int l = strlen(ch);
        int i;
        for(i=0;i<l;i++){
        	printf("%c",ch[i]);
        }

    return 0;
}