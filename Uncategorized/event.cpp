#include<bits/stdc++.h>
using namespace std;
#define sat "saturday"
#define sun "sunday"
#define mon "monday"
#define tue "tuesday"
#define wed "wednesday"
#define thu "thursday"
#define fri "friday"
int l,r;
char s[20];
char e[20];
char day[7][20] = {sat,sun,mon,tue,wed,thu,fri};
int no[] = {1,2,3,4,5,6,7};
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    int a=0;
    int b=0;
    int nd=0;
    while(t--){

        cin>>s;
        cin>>e;
        cin>>l;
        cin>>r;
//        cout<<s<<" ";
//        cout<<e<<"\n";
        for(int i=0;i<7;i++){
            if(!strcmp(s,day[i])){
                //cout<<day[i]<<"\n";
                a=no[i];
                break;
            }
        }
        for(int i=0;i<7;i++){
            if(!strcmp(e,day[i])){
                //cout<<day[i]<<"\n";
                b=no[i];
                break;
            }
        }
        nd = b-a+1;
        if(nd<1){
            nd=7+nd;
        }
/*        if(nd<=r && nd>=l){
            if((r-nd)/7 >= 1 ){
                cout<<"many\n";
            }
            else{
                cout<<nd<<"\n";
            }
        }
        else{
            cout<<"impossible\n";
        }
*/

        			int c=0,d=0;
			for(int i=l;i<=r;i++){
                if((i-nd)%7==0){
                    c++;
                    d=i;
                }
            }
			if(c==0){
                cout<<"impossible\n";
            }
			else if(c==1){
                cout<<d<<"\n";
            }
			else cout<<"many\n";





    }


    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

