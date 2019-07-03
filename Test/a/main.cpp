#include<bits/stdc++.h>
using namespace std;
char s[100][20];
float times[100];
int pos;
int n;
bool check_left(char c){
    if(c=='d'||c=='f')
        return true;
    else
        return false;
}
bool search(string str,int n){
    int flag=0;
    for(int i=0;i<n;i++){
        if(str.compare(s[i])){
            flag++;
            pos=i;
        }
    }
    if(flag==0)
        return false;
    else
        return true;
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
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }

        for(int i=0;i<n;i++){
            int l=strlen(s[i]);
            if(search(s[i],n)){
                times[i]=(times[pos]/2);
            }
            else{
                times[i]=0.2;
                for(int j=1;j<l;j++){
                        cout<<s[i][j];
                    if(check_left(s[i][j-1])!=check_left(s[i][j])){
                        times[i]+=0.2;
                    }
                else{
                    times[i]+=0.4;
                }
                }
                cout<<endl;
            }
        }
        for(int i=0;i<n;i++){
            cout<<times[i]<<"\n";
        }

    }


    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
