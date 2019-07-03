#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
 
        int l;
        cin>>l;
        string s;
        cin>>s;
        bool flag = true;
        bool found = false;
        int lastpos = 0;
        for(int i=0;i<s.size();i++){
            //cout<<s[i]<<" ";
            //cout<<s[i]<<"\n";
            //cout<<s<<"\n";
            if(s[i] == 'H' && found == false){
                //cout<<"1st\n";
                found = true;
                lastpos = i;
            }
            else if(s[i] == 'T' && found == true){
                //cout<<"2nd\n";
                found = false;
                s.erase(lastpos,i-lastpos+1);
                i=i-(i-lastpos+1);
            }
            else if(s[i] == '.'){
                //cout<<"3rd\n";
                s.erase(i,1);
                i--;
            }
            else{
                //cout<<"4th\n";
                flag = false;
                found = true;
                break;
            }
        }
        //cout<<"\n";
        if(flag){
            if(found !=true){
                cout<<"Valid\n";
            }
            else{
                cout<<"Invalid\n";
            }
        }
        else if(flag == false && found == true){
            cout<<"Invalid\n";
        }
 
    }
    #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}