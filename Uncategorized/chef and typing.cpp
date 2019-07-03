#include<bits/stdc++.h>
using namespace std;
char s[150][40];
float times[150];
float ti;
int pos;
int n;
bool check_left(char c){
    if(c=='d'||c=='f')
        return true;
    else
        return false;
}
bool search(char st[40],int num){
    int flag=0;
    for(int i=0;i<num;i++){
        if(!strcmp(st,s[i])){
            flag++;
            if(flag==1)
            pos=i;
        }
    }
    if(flag>=1)
        return true;
    else
        return false;
}
int main(){
/*#ifndef ONLINE_JUDGE
        freopen("i.txt", "rt", stdin);
        freopen("o.txt", "wt", stdout);
	#endif
	*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ti=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<n;i++){
            int l=strlen(s[i]);
            if(search(s[i],i)){
                times[i]=(times[pos]/2);
            }
            else{
                times[i]=0.2;
                for(int j=1;j<l;j++){
                    if(check_left(s[i][j-1])!=check_left(s[i][j])){
                        times[i]+=0.2;
                    }
                else{
                    times[i]+=0.4;
                }
                }
            }
        }
        for(int i=0;i<n;i++){
            ti+=times[i];
            /* cout<<times[i]<<endl;*/
        }
        cout<<ti*10<<endl;

    }


/*    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    */
    return 0;
}
